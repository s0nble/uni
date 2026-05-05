import asyncio
import websockets
import tkinter as tk
import threading
import hashlib
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
import os

class ChatClient:
    def __init__(self):
        
        self.url = input("Enter server URL: ").strip()
        if self.url.startswith("https://"):
            self.url = self.url.replace("https://", "wss://")

        
        self.password = input("Enter shared password: ").strip()
        self.KEY = hashlib.sha256(self.password.encode()).digest()

        
        self.window = tk.Tk()
        self.window.title("Secure Chat")

        self.chat_box = tk.Text(self.window)
        self.chat_box.pack()

        self.entry = tk.Entry(self.window)
        self.entry.pack(fill="x")
        self.entry.bind("<Return>", self.send)

        
        self.loop = asyncio.new_event_loop()
        threading.Thread(target=self.start_loop, daemon=True).start()

    
    
    def encrypt(self, msg):
        aesgcm = AESGCM(self.KEY)
        nonce = os.urandom(12)
        ct = aesgcm.encrypt(nonce, msg.encode(), None)
        return (nonce + ct).hex()

    def decrypt(self, data):
        aesgcm = AESGCM(self.KEY)
        raw = bytes.fromhex(data)
        nonce = raw[:12]
        ct = raw[12:]
        return aesgcm.decrypt(nonce, ct, None).decode()

    
    def start_loop(self):
        asyncio.set_event_loop(self.loop)
        self.loop.run_until_complete(self.connect())

    
    async def connect(self):
        try:
            self.ws = await websockets.connect(self.url)

            
            await self.ws.send(self.password)

            self.chat_box.insert(tk.END, "[Connected]\n")

            while True:
                msg = await self.ws.recv()

                
                if msg == "AUTH_FAIL":
                    self.chat_box.insert(tk.END, "[Wrong Password]\n")
                    return

                
                try:
                    decrypted = self.decrypt(msg)
                    self.chat_box.insert(tk.END, f"Peer: {decrypted}\n")
                except:
                    self.chat_box.insert(tk.END, "[Decryption Failed]\n")

        except Exception as e:
            self.chat_box.insert(tk.END, f"[Error: {e}]\n")


    def send(self, event=None):
        msg = self.entry.get()
        if not msg:
            return

        encrypted = self.encrypt(msg)

        asyncio.run_coroutine_threadsafe(
            self.ws.send(encrypted), self.loop
        )

        self.chat_box.insert(tk.END, f"You: {msg}\n")
        self.entry.delete(0, tk.END)

    def run(self):
        self.window.mainloop()


if __name__ == "__main__":
    ChatClient().run()
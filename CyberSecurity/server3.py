import asyncio
import websockets
import hashlib
from cryptography.hazmat.primitives.ciphers.aead import AESGCM

PASSWORD = "123"

clients = {}

def make_key(password):
    return hashlib.sha256(password.encode()).digest()

def decrypt(data, key):
    aesgcm = AESGCM(key)
    raw = bytes.fromhex(data)
    nonce = raw[:12]
    ct = raw[12:]
    return aesgcm.decrypt(nonce, ct, None).decode()

async def handler(ws):
    print("[+] New connection")

    try:
        password = await ws.recv()

        if password != PASSWORD:
            await ws.send("AUTH_FAIL")
            await ws.close()
            return
        
        key = make_key(password)
        clients[ws] = key

        print("[+] Authenticated | Clients:", len(clients))
        async for message in ws:
            sender_key = clients[ws]

            try:
                text = decrypt(message, sender_key)
                print("Received:", text)
            except:
                print("Decryption failed")
                continue
            dead = []
            for client in clients:
                
                try:
                    await client.send(message)
                except:
                    dead.append(client)

            for d in dead:
                clients.pop(d, None)

    except Exception as e:
        print("Error:", e)

    finally:
        clients.pop(ws, None)
        print("[-] Client disconnected | Clients:", len(clients))

async def main():
    async with websockets.serve(handler, "0.0.0.0", 5000):
        print("[*] Server running on port 5000")
        await asyncio.Future()

asyncio.run(main())
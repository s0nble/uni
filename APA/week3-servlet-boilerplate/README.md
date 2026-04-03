# Week 3 — Java Servlets with Embedded Jetty (Ready-to-Run)

Pre-configured Java servlet project with embedded Jetty server.  
**No Tomcat installation, no server setup, no extra downloads needed.**

## How to Open

### Eclipse

1. File → Import → General → Existing Projects into Workspace
2. Select this folder → Finish
3. Right-click `Main.java` → Run As → Java Application
4. Open browser: `http://localhost:8080`

### IntelliJ IDEA

1. File → Open → select this folder
2. Wait for indexing to finish
3. Open `src/Main.java` → click ▶ next to `main()`
4. Open browser: `http://localhost:8080`

### VS Code

1. Open this folder in VS Code
2. Install "Extension Pack for Java" if prompted
3. Open `src/Main.java` → click **Run** above `main()`
4. Open browser: `http://localhost:8080`

### NetBeans

1. File → Open Project (or Import → Java Project with Existing Sources)
2. Set `src` as the source folder
3. Add all jars from `libs/` to project Libraries
4. Right-click `Main.java` → Run File
5. Open browser: `http://localhost:8080`

## Project Structure

```
week3-servlet-boilerplate/
├── libs/                    ← Jetty & Servlet jars (already included)
│   ├── jetty-server-*.jar
│   ├── jetty-servlet-*.jar
│   ├── jetty-util-*.jar
│   ├── jakarta.servlet-api-*.jar
│   └── ... (other Jetty dependencies)
├── src/
│   ├── Main.java           ← Run this to start the server
│   └── HelloServlet.java   ← Example servlet — your work goes here
├── webapp/
│   ├── WEB-INF/
│   │   └── web.xml         ← Servlet mappings
│   └── index.html          ← Landing page
├── .classpath              ← Eclipse config
├── .project                ← Eclipse config
├── .idea/                  ← IntelliJ config
└── .vscode/                ← VS Code config
```

## What Happens When You Run

1. **Jetty server starts** on port 8080
2. **Servlets are registered** from `web.xml`
3. Visit `http://localhost:8080` → see landing page
4. Visit `http://localhost:8080/hello` → see HelloServlet output
5. Visit `http://localhost:8080/hello?name=YourName` → personalized greeting

## URLs to Try

- `http://localhost:8080/` — Landing page
- `http://localhost:8080/hello` — HelloServlet (GET)
- `http://localhost:8080/hello?name=Mohamed` — With query parameter

## Sample Code Explained

### HelloServlet.java

```java
@WebServlet("/hello")
public class HelloServlet extends HttpServlet {
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) {
        // Handle GET requests
    }
}
```

### Main.java

- Creates embedded Jetty server
- Registers servlets from `WEB-INF/web.xml`
- Starts server on port 8080

## How to Add Your Own Servlet

1. Create new class extending `HttpServlet` in `src/`
2. Override `doGet()` and/or `doPost()`
3. Add servlet mapping in `webapp/WEB-INF/web.xml`
4. Restart the server (stop and run `Main.java` again)

## Stopping the Server

- In your IDE: click the red ⏹ (stop) button in the console
- Or press `Ctrl+C` in the terminal if running from command line

## Common Issues

**Port 8080 already in use?**

- Change the port in `Main.java`: `server.setPort(9090);`

**Changes not showing up?**

- Stop the server and run `Main.java` again

**Servlet not found (404)?**

- Check `web.xml` has the correct URL pattern
- Make sure servlet class name matches exactly

## Next Steps

- Add more servlets for different functionality
- Practice handling GET and POST requests
- Try reading request parameters
- Send different response types (HTML, JSON, etc.)
- Connect with Derby database from week 2

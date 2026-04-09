# Required JAR Files

This boilerplate needs the following JAR files in the `libs/` directory:

## Jetty 11.x (Jakarta EE 9+)

Download from: https://repo1.maven.org/maven2/org/eclipse/jetty/

Required files:

1. `jetty-server-11.0.15.jar`
2. `jetty-servlet-11.0.15.jar`
3. `jetty-util-11.0.15.jar`
4. `jetty-http-11.0.15.jar`
5. `jetty-io-11.0.15.jar`
6. `jetty-security-11.0.15.jar`

## Jakarta Servlet API

Download from: https://repo1.maven.org/maven2/jakarta/servlet/jakarta.servlet-api/

Required file:

- `jakarta.servlet-api-5.0.0.jar`

## SLF4J (Logging)

Download from: https://repo1.maven.org/maven2/org/slf4j/

Required files:

- `slf4j-api-2.0.7.jar`
- `slf4j-simple-2.0.7.jar`

## Quick Download Script

### macOS/Linux:

```bash
cd libs
curl -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-server/11.0.15/jetty-server-11.0.15.jar
curl -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-servlet/11.0.15/jetty-servlet-11.0.15.jar
curl -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-util/11.0.15/jetty-util-11.0.15.jar
curl -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-http/11.0.15/jetty-http-11.0.15.jar
curl -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-io/11.0.15/jetty-io-11.0.15.jar
curl -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-security/11.0.15/jetty-security-11.0.15.jar
curl -O https://repo1.maven.org/maven2/jakarta/servlet/jakarta.servlet-api/5.0.0/jakarta.servlet-api-5.0.0.jar
curl -O https://repo1.maven.org/maven2/org/slf4j/slf4j-api/2.0.7/slf4j-api-2.0.7.jar
curl -O https://repo1.maven.org/maven2/org/slf4j/slf4j-simple/2.0.7/slf4j-simple-2.0.7.jar
```

### Windows (PowerShell):

```powershell
cd libs
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-server/11.0.15/jetty-server-11.0.15.jar" -OutFile "jetty-server-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-servlet/11.0.15/jetty-servlet-11.0.15.jar" -OutFile "jetty-servlet-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-util/11.0.15/jetty-util-11.0.15.jar" -OutFile "jetty-util-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-http/11.0.15/jetty-http-11.0.15.jar" -OutFile "jetty-http-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-io/11.0.15/jetty-io-11.0.15.jar" -OutFile "jetty-io-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-security/11.0.15/jetty-security-11.0.15.jar" -OutFile "jetty-security-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/jakarta/servlet/jakarta.servlet-api/5.0.0/jakarta.servlet-api-5.0.0.jar" -OutFile "jakarta.servlet-api-5.0.0.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/slf4j/slf4j-api/2.0.7/slf4j-api-2.0.7.jar" -OutFile "slf4j-api-2.0.7.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/slf4j/slf4j-simple/2.0.7/slf4j-simple-2.0.7.jar" -OutFile "slf4j-simple-2.0.7.jar"
```

After downloading, you should have 9 JAR files in the `libs/` directory.

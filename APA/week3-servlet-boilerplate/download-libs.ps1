# PowerShell script to download all required JAR files for the servlet boilerplate

Write-Host "📦 Downloading Jetty and Servlet API JARs..." -ForegroundColor Cyan
Write-Host ""

Set-Location libs

# Jetty 11.0.15 JARs
Write-Host "Downloading Jetty JARs..." -ForegroundColor Yellow
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-server/11.0.15/jetty-server-11.0.15.jar" -OutFile "jetty-server-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-servlet/11.0.15/jetty-servlet-11.0.15.jar" -OutFile "jetty-servlet-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-util/11.0.15/jetty-util-11.0.15.jar" -OutFile "jetty-util-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-http/11.0.15/jetty-http-11.0.15.jar" -OutFile "jetty-http-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-io/11.0.15/jetty-io-11.0.15.jar" -OutFile "jetty-io-11.0.15.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-security/11.0.15/jetty-security-11.0.15.jar" -OutFile "jetty-security-11.0.15.jar"

# Jakarta Servlet API
Write-Host "Downloading Jakarta Servlet API..." -ForegroundColor Yellow
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/jakarta/servlet/jakarta.servlet-api/5.0.0/jakarta.servlet-api-5.0.0.jar" -OutFile "jakarta.servlet-api-5.0.0.jar"

# SLF4J for logging
Write-Host "Downloading SLF4J..." -ForegroundColor Yellow
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/slf4j/slf4j-api/2.0.7/slf4j-api-2.0.7.jar" -OutFile "slf4j-api-2.0.7.jar"
Invoke-WebRequest -Uri "https://repo1.maven.org/maven2/org/slf4j/slf4j-simple/2.0.7/slf4j-simple-2.0.7.jar" -OutFile "slf4j-simple-2.0.7.jar"

Write-Host ""
Write-Host "✅ All JARs downloaded successfully!" -ForegroundColor Green
Write-Host "You can now run Main.java in your IDE." -ForegroundColor Green

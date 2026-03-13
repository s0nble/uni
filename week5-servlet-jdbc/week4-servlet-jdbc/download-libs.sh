#!/bin/bash

# Script to download all required JAR files for the servlet boilerplate

echo "📦 Downloading Jetty and Servlet API JARs..."
echo ""

cd libs

# Jetty 11.0.15 JARs
echo "Downloading Jetty JARs..."
curl -# -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-server/11.0.15/jetty-server-11.0.15.jar
curl -# -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-servlet/11.0.15/jetty-servlet-11.0.15.jar
curl -# -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-util/11.0.15/jetty-util-11.0.15.jar
curl -# -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-http/11.0.15/jetty-http-11.0.15.jar
curl -# -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-io/11.0.15/jetty-io-11.0.15.jar
curl -# -O https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-security/11.0.15/jetty-security-11.0.15.jar

# Jakarta Servlet API
echo "Downloading Jakarta Servlet API..."
curl -# -O https://repo1.maven.org/maven2/jakarta/servlet/jakarta.servlet-api/5.0.0/jakarta.servlet-api-5.0.0.jar

# SLF4J for logging
echo "Downloading SLF4J..."
curl -# -O https://repo1.maven.org/maven2/org/slf4j/slf4j-api/2.0.7/slf4j-api-2.0.7.jar
curl -# -O https://repo1.maven.org/maven2/org/slf4j/slf4j-simple/2.0.7/slf4j-simple-2.0.7.jar

echo ""
echo "✅ All JARs downloaded successfully!"
echo "You can now run Main.java in your IDE."

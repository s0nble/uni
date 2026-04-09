import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;
import org.eclipse.jetty.servlet.DefaultServlet;

public class Main {

	public static void main(String[] args) throws Exception {
		// Create Jetty server on port 8080
		Server server = new Server(8080);

		// Create servlet context
		ServletContextHandler context = new ServletContextHandler(ServletContextHandler.SESSIONS);
		context.setContextPath("/");
		context.setResourceBase("webapp");
		server.setHandler(context);

		// Enable static file serving
		context.addServlet(new ServletHolder("default", DefaultServlet.class), "/");

		// Register servlets
		context.addServlet(new ServletHolder(new RegisterServlet()), "/register-service");
		context.addServlet(new ServletHolder(new UsersServlet()), "/display");

		System.out.println("Starting Jetty server on http://localhost:8080");
		System.out.println("Press Ctrl+C to stop the server");


		Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
		String conStr = "jdbc:derby:db/AAST;create=true";
		Connection conn = DriverManager.getConnection(conStr);

		Statement stmt = conn.createStatement();
		try {
			stmt.execute(
				"create table Users(id int, name varchar(25), email varchar(25), password varchar(25), primary key (id))");
		} catch (SQLException e) {
			System.out.println("Table already exists!");
		}
		conn.close();
		// PreparedStatement pstmt = conn.prepareStatement("insert into users values (?,?,?,?)");
		// pstmt.setInt(1, 1);
		// pstmt.setString(2, "mohamed");
		// pstmt.setString(3, "test@gmail.com");
		// pstmt.setString(4, "asdf1234");
		// pstmt.execute();

		// ResultSet result = stmt.executeQuery("select * from users");

		// while (result.next()) {
		// 	System.out.println(result.getString("email"));
		// }

		server.start();
		server.join();
		
	}
}

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;
import org.eclipse.jetty.servlet.DefaultServlet;

public class ServletMain {

	public static void main(String[] args) throws Exception {
		// Create Jetty server on port 8080
		Server server = new Server(8080);

		// Create servlet context
		ServletContextHandler context = new ServletContextHandler(ServletContextHandler.SESSIONS);
		context.setContextPath("/");
		context.setResourceBase("src/main/webapp");
		server.setHandler(context);

		// Enable static file serving
		context.addServlet(new ServletHolder("default", DefaultServlet.class), "/");

		// Register servlets
		context.addServlet(new ServletHolder(new DiscountServlet()), "/discount");

		// You can add more servlets here:
		// context.addServlet(new ServletHolder(new YourServlet()), "/yourpath");

		// Start the server
		System.out.println("Starting Jetty server on http://localhost:8080");
		System.out.println("Press Ctrl+C to stop the server");
		server.start();
		server.join();
	}
}

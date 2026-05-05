import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class UsersServlet extends HttpServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String conStr = "jdbc:derby:db/AAST;create=true";
        try {
            Connection conn = DriverManager.getConnection(conStr);
            Statement stmt = conn.createStatement();
            ResultSet result = stmt.executeQuery("select * from users");

            PrintWriter out = resp.getWriter();

            resp.setContentType("text/html");

            while(result.next()){
                int id = result.getInt("id");
                String name = result.getString("name");
                String email = result.getString("email");
                String password = result.getString("password");

                out.println("<p>ID: "+id+", Name: "+name+", Email: "+email+", Password: "+password+" </p>");
            }

            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

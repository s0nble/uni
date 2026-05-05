import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class RegisterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int id = Integer.parseInt(req.getParameter("id"));
        String name = req.getParameter("name");
        String email = req.getParameter("email");
        String password = req.getParameter("password");


		String conStr = "jdbc:derby:db/AAST;create=true";
        try {
            Connection conn = DriverManager.getConnection(conStr);
            
            PreparedStatement pstmt = conn.prepareStatement("insert into users values (?,?,?,?)");
            pstmt.setInt(1, id);
            pstmt.setString(2, name);
            pstmt.setString(3, email);
            pstmt.setString(4, password);

            pstmt.execute();

            PrintWriter out  = resp.getWriter();

            resp.setContentType("text/html");
            out.println("<h1>User created successfully!</h1>");

            conn.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

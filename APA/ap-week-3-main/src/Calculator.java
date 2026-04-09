import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class Calculator extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String xStr = req.getParameter("x");
        String yStr = req.getParameter("y");
        String choice = req.getParameter("choice");

        double x = Double.parseDouble(xStr);
        double y = Double.parseDouble(yStr);

        double result = 0;

        if(choice.equals("Add"))
            result = x+y;
        else 
            result = x - y;


        PrintWriter out = resp.getWriter();

        out.println("The result is: " +  result);
    }
}

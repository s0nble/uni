import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class BMICalculator extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String weightStr = req.getParameter("weight");
        String heightStr = req.getParameter("height");
        
        double weight = Double.parseDouble(weightStr);
        double height = Double.parseDouble(heightStr);

        double bmi = weight / (height * height);


        PrintWriter out = resp.getWriter();


        out.println("Your BMI is: " + bmi);
    }
}

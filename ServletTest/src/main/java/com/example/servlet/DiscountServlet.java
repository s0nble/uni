package com.example.servlet;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/discount")
public class DiscountServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String dPx = req.getParameter("discountPercent");
		String Prc = req.getParameter("Price");
		
		double discountPercent = Double.parseDouble(dPx);
		double Price = Double.parseDouble(Prc);
		double finalPrice=0;
		finalPrice = Price - ((Price * discountPercent)/100);
	
		PrintWriter pw = resp.getWriter();
		resp.setContentType("text/html");
		pw.println("Final Price is:" + finalPrice);
		
	}

}



// import jakarta.servlet.ServletException;
// import jakarta.servlet.annotation.WebServlet;
// import jakarta.servlet.http.HttpServlet;
// import jakarta.servlet.http.HttpServletRequest;
// import jakarta.servlet.http.HttpServletResponse;
// import java.io.IOException;
// import java.io.PrintWriter;

// /**
//  * Servlet implementation class ProcessData
//  */
// @WebServlet("/ProcessData")
// public class ProcessData extends HttpServlet {
// 	private static final long serialVersionUID = 1L;

// 	/**
// 	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
// 	 */
// 	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
// 		response.setContentType("text/html");
// 		PrintWriter out = response.getWriter();

// 		// Get input from form
// 		double hours = Double.parseDouble(request.getParameter("hour"));
// 		double rate = Double.parseDouble(request.getParameter("rate"));

// 		if(hours < 0 || rate < 7.5) {
// 			out.print("Invalid inputs");
// 			request.getRequestDispatcher("index.html").include(request, response);;    
// 		}

// 		else {
// 			// Calculate gross salary
// 			double grossSalary = hours * rate;

// 			// Determine tax rate
// 			double taxRate;
// 			if (grossSalary <= 4999) {
// 				taxRate = 0.10;
// 			} else if (grossSalary <= 30000) {
// 				taxRate = 0.20;
// 			} else {
// 				taxRate = 0.30;
// 			}

// 			// Calculate tax and net salary
// 			double tax = grossSalary * taxRate;
// 			double netSalary = grossSalary - tax;

// 			// Set values as request attributes
// 			request.setAttribute("gross", grossSalary);
// 			request.setAttribute("taxRate", taxRate * 100);
// 			request.setAttribute("tax", tax);
// 			request.setAttribute("net", netSalary);

// 			// Forward to another Servlet 
// 			request.getRequestDispatcher("Result").forward(request, response);;

// 		}
// 	}
// 	/**
// 	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
// 	 */
// 	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

// 	}

// }

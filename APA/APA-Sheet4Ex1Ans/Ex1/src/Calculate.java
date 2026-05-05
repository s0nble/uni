import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Calculate
 */
@WebServlet("/Calculate")
public class Calculate extends HttpServlet {
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String stx = request.getParameter("x");
		String sty = request.getParameter("y");
		
		int x = Integer.parseInt(stx);
		int y = Integer.parseInt(sty);
		
		int result=0;
		
		String choice = request.getParameter("choice");
	
		if(choice.equals("Add"))
			result = x+y;
		else
			result = x-y;
		
		response.setContentType("text/html");
		PrintWriter pw = response.getWriter();
		
		pw.print("<html>");
		pw.print("<head>");
		pw.print("<title> Welcome </title>");
		pw.print("</head>");
		pw.print("<body> Result "+result+"</body");
		pw.print("</html>");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}

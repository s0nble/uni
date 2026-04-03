package controller;

import java.io.IOException;

import org.thymeleaf.TemplateEngine;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.templatemode.TemplateMode;
import org.thymeleaf.templateresolver.WebApplicationTemplateResolver;
import org.thymeleaf.web.IWebExchange;
import org.thymeleaf.web.servlet.JakartaServletWebApplication;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import model.Student;

@WebServlet("/GradeCalc")
public class GradeCalcServlet extends HttpServlet {

    private static final long serialVersionUID = 1L;

    private TemplateEngine templateEngine;
    private JakartaServletWebApplication webApplication;

    @Override
    public void init() throws ServletException {

        this.webApplication =
                JakartaServletWebApplication.buildApplication(getServletContext());

        WebApplicationTemplateResolver resolver =
                new WebApplicationTemplateResolver(webApplication);

        resolver.setPrefix("/WEB-INF/templates/");
        resolver.setSuffix(".html");
        resolver.setTemplateMode(TemplateMode.HTML);
        resolver.setCharacterEncoding("UTF-8");

        templateEngine = new TemplateEngine();
        templateEngine.setTemplateResolver(resolver);
    }

    @Override
    protected void doGet(HttpServletRequest request,
                         HttpServletResponse response)
            throws ServletException, IOException {

        String name = request.getParameter("name");

        double mid = Double.parseDouble(request.getParameter("mid"));
        double fin = Double.parseDouble(request.getParameter("fin"));

        Student student = new Student(name, mid, fin);

        IWebExchange exchange =
                webApplication.buildExchange(request, response);

        WebContext ctx = new WebContext(exchange);

        // Error handling
        if (student.hasInvalidValues()) {

            ctx.setVariable("message",
                    "Grades cannot be negative!");

            templateEngine.process("error", ctx, response.getWriter());
            return;
        }

        ctx.setVariable("name", student.getName());
        ctx.setVariable("grade", student.calculateGrade());
        ctx.setVariable("status", student.getStatus());

        templateEngine.process("result", ctx, response.getWriter());
    }
}
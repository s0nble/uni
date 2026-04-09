import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Main {

	public static void main(String[] args) throws SQLException, ClassNotFoundException {
		DBManager.initDatabase();
		// User u = new User(3, "Mohamed", "test@gmail.com", "asd1234");
		// User u2 = new User(4, "Ahmed", "test2@gmail.com", "asd1234");
		// DBManager.insertUser(u);
		// DBManager.insertUser(u2);
		

		System.out.println(DBManager.getAllUsers());

		System.out.println("Login test: "+ DBManager.loginUser("test@gmail.com", "asd1234"));
	}

}

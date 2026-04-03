import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Main {

	public static void main(String[] args) throws SQLException, ClassNotFoundException {
		Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
		String conStr = "jdbc:derby:db/AAST;create=true";
		Connection conn = DriverManager.getConnection(conStr);

		Statement stmt = conn.createStatement();
		stmt.execute(
				"create table Users(id int, name varchar(25), email varchar(25), password varchar(25), primary key (id))");

		PreparedStatement pstmt = conn.prepareStatement("insert into users values (?,?,?,?)");
		pstmt.setInt(1, 1);
		pstmt.setString(2, "mohamed");
		pstmt.setString(3, "test@gmail.com");
		pstmt.setString(4, "asdf1234");
		pstmt.execute();

		ResultSet result = stmt.executeQuery("select * from users");

		while (result.next()) {
			System.out.println(result.getString("email"));
		}
	}

}

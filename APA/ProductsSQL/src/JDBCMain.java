import java.sql.*;

public class JDBCMain {

	static String conStr = "jdbc:derby:db/AAST;create=true";
	public static void main(String[] args) throws Exception {	
		try {
		Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
		 Connection conn = DriverManager.getConnection(conStr);
		 
		 createTable();
		 
		 Product p1 = new Product(101, "Laptop", "ELectronics", 15000);
		 Product p2 = new Product(102, "Headphones", "ELectronics", 1200);
		 Product p3 = new Product(103, "Office Chair", "Furniture", 3200);

		 InsertProduct(p1);
		 InsertProduct(p2);
		 InsertProduct(p3);
	
		 Retrieve();
		 
		 
		 conn.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}
		 
	
	}
	
	
	public static void createTable() throws SQLException{
		Connection conn = DriverManager.getConnection(conStr);
		Statement stmt = conn.createStatement();
		try{
		stmt.execute("create table products(product_id int, product_name varchar(50), category varchar(30), price int, primary key(product_id))");
		} 
		catch(SQLException e){
			e.printStackTrace();
		}
		
		conn.close();
		
	}
	
	public static void InsertProduct(Product p) throws SQLException {
		try {
			Connection conn = DriverManager.getConnection(conStr);
			PreparedStatement pstmt = conn.prepareStatement("INSERT into products values (?,?,?,?)");
			
			pstmt.setInt(1, p.product_id);
			pstmt.setString(2, p.product_name);
			pstmt.setString(3, p.category);
			pstmt.setInt(4, p.price);
			
			pstmt.execute();
			
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		
	}
	
	
	public static void Retrieve() throws SQLException{
		Connection conn = DriverManager.getConnection(conStr);
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery("SELECT * from products");
		
		while(rs.next()) {
			System.out.println(
					rs.getInt("product_id") + "|" + 
					rs.getString("product_name") + "|" + 
					rs.getString("category") + "|" + 
					rs.getInt("price")  
		);
		}
		
		conn.close();
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

import java.sql.*;

public class DB {


    Connection con;
    Statement st;


public DB() {
    //load driver
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        //establish connection
        con=DriverManager.getConnection("jdbc:mysql://localhost:3306/my_first_db", "root", "pypYHCzIm0mmV8");
        //create statement
        st= con.createStatement();
        //execute
        st.executeUpdate("create table Users (email varchar(25), password varchar(25), Fname varchar(10), Lname varchar(25), primary key (email))");
        //close connection
        con.close();

        System.out.println("table created");


    } catch (ClassNotFoundException | SQLException e) {
        throw new RuntimeException(e);
    }

}
}

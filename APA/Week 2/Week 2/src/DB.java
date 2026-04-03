import java.sql.*;
public class DB
{
    Connection con;
    Statement st;

    public DB()
    {
            //load driver
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Driver Loaded");
        //establish connection
        con=DriverManager.getConnection("jdbc:mysql://localhost:3306/CCIT","root","root12345");
            System.out.println("Connection Established");
        //create Statement
        st= con.createStatement();
        //execute SQL
        st.executeUpdate("create table Users (Email varchar(20),Password varchar(15)" +
                ", Fname varchar(10),Lname varchar(10),PRIMARY KEY (Email))");


        } catch (ClassNotFoundException | SQLException e) {
            throw new RuntimeException(e);
        }

        finally
        {
            try {
                con.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }

    }
    public static void main(String[] args)
    {
        DB db = new DB();
    }

}

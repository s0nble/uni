import java.sql.*;
import java.util.ArrayList;

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
       // st= con.createStatement();
        //execute SQL
       // st.executeUpdate("create table Users (Email varchar(20),Password varchar(15)" +
          //      ", Fname varchar(10),Lname varchar(10),PRIMARY KEY (Email))");


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

    public int add_users(User U)
    {
        int flag=0;   // indecator for insertion
        try {
            con=DriverManager.getConnection("jdbc:mysql://localhost:3306/CCIT","root","root12345");
      //      st= con.createStatement();
       //  flag=  st.executeUpdate("insert into Users values ('"+U.getEmail()+"','"+U.getPassword()+"','"+U.getFname()+"','"+U.getLname()+"')");

            PreparedStatement pst= con.prepareStatement("insert into Users values (?,?,?,?)");
            pst.setString(2,U.getPassword());
            pst.setString(1,U.getEmail());
            pst.setString(3,U.getFname());
            pst.setString(4,U.getLname());

            flag= pst.executeUpdate();

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        finally {
            try {
                con.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }

        return flag;
    }

    public ArrayList<User> print_all()
    {
        ArrayList<User> users = new ArrayList<>();
        try {
            con=DriverManager.getConnection("jdbc:mysql://localhost:3306/CCIT","root","root12345");
            st=con.createStatement();
            ResultSet rs= st.executeQuery("select * from Users");
            while (rs.next())
            {
                User u= new User(rs.getString(1),rs.getString(2), rs.getString(3),rs.getString(4));
                users.add(u);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        finally {
            try {
                con.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        return users;
    }



    public static void main(String[] args)
    {
        DB db = new DB();
        User u1= new User("aa.com","11233","ahmed","hesham");
        User u2= new User("ah1.com","11233","ahmed","hesham");
        int result=0;

       /*
         result= db.add_users(u2);


        if(result==1)
        {
            System.out.println("user inserted");
        }
        else
        {
            System.out.println("insertion error");
        }
*/
        ArrayList<User> users= db.print_all();
        System.out.println(users.toString());

    }

}

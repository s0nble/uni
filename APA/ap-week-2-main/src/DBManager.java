import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class DBManager {
    private static String connStr = "jdbc:derby:db/AAST;create=true";

    static void initDatabase() {
        try {
            Connection conn  = DriverManager.getConnection(connStr, "root", "1234");
            Statement stmt = conn.createStatement();

            stmt.execute("create table users "+
            "(id int, name varchar(25), email varchar(25), password varchar(25), primary key (id))");
            conn.close();
        } catch (SQLException e) {
            System.out.println("Table already exists!");
        }
    }


    public static void insertUser(User user) throws SQLException{
        Connection conn = DriverManager.getConnection(connStr);
        PreparedStatement pstmt = conn.prepareStatement("insert into users values (?,?,?,?)");

        pstmt.setInt(1, user.getId());
        pstmt.setString(2, user.getName());
        pstmt.setString(3, user.getEmail());
        pstmt.setString(4, user.getPassword());

        pstmt.execute();

        conn.close();
    }


    public static ArrayList<User> getAllUsers() throws SQLException{
        ArrayList<User> users = new ArrayList<>();


        Connection conn = DriverManager.getConnection(connStr);
        Statement stmt = conn.createStatement();

        ResultSet result =  stmt.executeQuery("select * from users");

        while(result.next()){
            int id  = result.getInt("id");
            String name = result.getString("name");
            String email = result.getString("email");
            String password = result.getString("password");

            User u = new User(id, name, email, password);

            users.add(u);
        }

        conn.close();

        return users;
    }


    public static User loginUser(String email, String password) throws SQLException {
        Connection conn = DriverManager.getConnection(connStr);
        PreparedStatement pstmt = conn.prepareStatement("select * from users where email = ? and password = ?");
        
        pstmt.setString(1, email);
        pstmt.setString(2, password);
        
        ResultSet result = pstmt.executeQuery();
        
        User user = null;
        if (result.next()) {
            int id = result.getInt("id");
            String name = result.getString("name");
            user = new User(id, name, email, password);
        }
        
        conn.close();
        return user;
    }


}

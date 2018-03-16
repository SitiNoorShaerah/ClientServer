import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class Server{
	public static void main(String[] args)
{
	try
	{
		System.out.println("Waiting for client...\n");
		ServerSocket ss = new ServerSocket(36772);
		Socket sock = ss.accept();
		System.out.println("Connection established...\n");
		BufferedReader in = new BufferedReader(new 
InputStreamReader(sock.getInputStream()));
		String str = in.readLine();
		PrintWriter out = new 
PrintWriter(sock.getOutputStream(), true);
		String as = new String("assalamualaikum");
		
		if(str.equalsIgnoreCase(as))
		{
			out.println("Waalaikumsalam\n");
		}
		else
		{
			out.println("Are you Muslim?\n");
		}
		
	}
	
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}

# ClientServer

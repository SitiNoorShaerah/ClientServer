import java.io.*;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.InetAddress;
import java.util.Date;
import java.net.UnknownHostException;

public class ServerTime1 {
	public static void main(String[] args) {
	try{
		System.out.println("Port is listening....");
		ServerSocket ss = new ServerSocket(7778);
		Socket sock = ss.accept();
		System.out.println("Connected");

		BufferedReader in = new
	BufferedReader(new InputStreamReader(sock.getInputStream()));
		PrintWriter out = new
	PrintWriter(sock.getOutputStream(), true);
	
	int g = Integer.parseInt(in.readLine());
	System.out.println(g);
	
	if (g<=11){
	out.println("Good Morning Human");
	}
	else if(g>=13&&g<=18){
	out.println("Good Evening People");
	}
	else if(g>=19){
	out.println("Good Night :)");
	}
	else{
	out.println("Good Afternoon");
	}
	}
	catch(Exception e){
	e.printStackTrace();
	}
	}
}

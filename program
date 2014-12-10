using System;
using System.Threading;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
namespace ledControl_4
{
public partial class Form1 : Form
{
public Thread myThread;
public Thread recThread;
public Socket sending_socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
public static IPAddress send_to_address = IPAddress.Parse("192.168.1.254");
public static IPEndPoint sending_end_point = new IPEndPoint(send_to_address, 8080);
public static bool myflag = false;
public Form1()
{
InitializeComponent();
myThread = new Thread(sending);
myThread.Start();
recThread = new Thread(recmes);
recThread.Start();
}
private void Form1_KeyUP(object sender, KeyEventArgs e)
{
if (e.KeyCode == Keys.L)
{
Globals.Lights = "x";
}
if (e.KeyCode == Keys.Up)
{
Globals.Forward = "x";
}
if (e.KeyCode == Keys.Down)
{
Globals.Backward = "x";
}
if (e.KeyCode == Keys.Left)
{
Globals.Left = "x";
}
if (e.KeyCode == Keys.Right)
{
Globals.Right = "x";
}
myflag = true;
if (!myThread.IsAlive)
{
myThread = new Thread(sending);
myThread.Start();
}
}
private void sending()
{
{
byte[] send_buffer = Encoding.ASCII.GetBytes(Globals.Forward + Globals.Backward + Globals.Left + Globals.Right + Globals.Speed);
sending_socket.SendTo(send_buffer, sending_end_point);
}
}
private void recmes()
{
const int listenPort = 8080;
UdpClient listener = new UdpClient(listenPort);
IPEndPoint groupEP = new IPEndPoint(IPAddress.Any, listenPort);
string received_data;
byte[] receive_byte_array;
bool done = false;
while (!done)
{
receive_byte_array = listener.Receive(ref groupEP);
received_data = Encoding.ASCII.GetString(receive_byte_array, 0, receive_byte_array.Length);
IP_Address.Text = received_data;
}
}
private void Form1_KeyDown(object sender, KeyEventArgs e)
{
if (myThread.IsAlive)
myThread.Abort();
myflag = false;
if (e.KeyCode == Keys.Up)
{
Globals.Forward = "F";
Globals.Backward = "x";
}
if (e.KeyCode == Keys.Down)
{
Globals.Forward = "x";
Globals.Backward = "B";
}
if (e.KeyCode == Keys.Left)
{
Globals.Left = "L";
Globals.Right = "x";
}
if (e.KeyCode == Keys.Right)
{
Globals.Right = "R";
Globals.Left = "x";
}
byte[] send_buffer = Encoding.ASCII.GetBytes(Globals.Forward + Globals.Backward + Globals.Left + Globals.Right+Globals.Speed);
sending_socket.SendTo(send_buffer, sending_end_point);
}
private void ON_Click(object sender, EventArgs e)
{
Globals.Lights = "O";
}

private void OFF_Click(object sender, EventArgs e)
{
Globals.Lights = "X";
}

private static void SendCommand(Socket s, string c)
{
Byte[] command = Encoding.ASCII.GetBytes(c);
try
{
s.Send(command, command.Length, 0);
}catch(Exception Ex)
{
Globals.oThread.Abort();
MessageBox.Show("Connection Aborted because it was already gone. I blame you.");
}
}
public static Socket ConnectSocket(string server, int port)
{
Socket s = null;
IPHostEntry hostEntry = null;
hostEntry = Dns.GetHostEntry(server);
foreach (IPAddress address in hostEntry.AddressList)
{
IPEndPoint ipe = new IPEndPoint(address, port);
Socket tempSocket =
new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Udp);
s = tempSocket;
}
return s;
}
public class Worker
{
public void Beta()
{
while (true)
{
}

}
};
public class Globals
{
public static Socket led_socket;
public static Thread oThread;
public static string Lights = "x";
public static string Temperature = "???";
public static string Forward = "x";
public static string Backward = "x";
public static string Left = "x";
public static string Right = "x";
public static string Speed = "000";
}

private void speed_TextChanged(object sender, EventArgs e)
{
if (speed.Text.Length == 0)
{
Globals.Speed = "000";
}
if (speed.Text.Length == 1)
{
Globals.Speed = "00"+speed.Text;
}
if (speed.Text.Length == 2)
{
Globals.Speed = "0" + speed.Text;
}
if (speed.Text.Length == 3)
{
Globals.Speed = speed.Text;
}
}
}
}

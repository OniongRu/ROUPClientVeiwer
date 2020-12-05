import java.io.*;
import java.nio.*;
import java.net.*;
import java.lang.*;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Set;
//сделать интеграционное тестирование
public class Server {
    //static String JTest="{\"userName\":\"Yuki\",\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"activeWindowProcessName\":\"java.exe\",\"programs\":[{\"name\":\"nvcontainer.exe\",\"ID\":2936,\"threadAmount\":42,\"cpuUsage\":0.0,\"ramUsage\":28},{\"name\":\"sihost.exe\",\"ID\":4908,\"threadAmount\":12,\"cpuUsage\":0.0,\"ramUsage\":32},{\"name\":\"svchost.exe\",\"ID\":872,\"threadAmount\":31,\"cpuUsage\":0.0,\"ramUsage\":57},{\"name\":\"taskhostw.exe\",\"ID\":3608,\"threadAmount\":8,\"cpuUsage\":0.0,\"ramUsage\":9},{\"name\":\"explorer.exe\",\"ID\":8672,\"threadAmount\":132,\"cpuUsage\":0.0,\"ramUsage\":152},{\"name\":\"avpui.exe\",\"ID\":15668,\"threadAmount\":17,\"cpuUsage\":0.0,\"ramUsage\":6},{\"name\":\"StartMenuExperienceHost.exe\",\"ID\":17608,\"threadAmount\":11,\"cpuUsage\":0.0,\"ramUsage\":37},{\"name\":\"RuntimeBroker.exe\",\"ID\":1628,\"threadAmount\":26,\"cpuUsage\":0.0,\"ramUsage\":88},{\"name\":\"SearchApp.exe\",\"ID\":16072,\"threadAmount\":42,\"cpuUsage\":0.0,\"ramUsage\":83},{\"name\":\"YourPhone.exe\",\"ID\":14896,\"threadAmount\":19,\"cpuUsage\":0.0,\"ramUsage\":12},{\"name\":\"NVIDIA Web Helper.exe\",\"ID\":10696,\"threadAmount\":94,\"cpuUsage\":0.0,\"ramUsage\":6},{\"name\":\"SecurityHealthSystray.exe\",\"ID\":16124,\"threadAmount\":1,\"cpuUsage\":0.0,\"ramUsage\":2},{\"name\":\"RtkNGUI64.exe\",\"ID\":12728,\"threadAmount\":6,\"cpuUsage\":0.0,\"ramUsage\":7},{\"name\":\"SeriousBit.NetBalancer.Tray.exe\",\"ID\":2280,\"threadAmount\":14,\"cpuUsage\":0.0,\"ramUsage\":15},{\"name\":\"punto.exe\",\"ID\":18344,\"threadAmount\":4,\"cpuUsage\":0.21834061135371177,\"ramUsage\":8},{\"name\":\"ps64ldr.exe\",\"ID\":6768,\"threadAmount\":1,\"cpuUsage\":0.0,\"ramUsage\":1},{\"name\":\"chrome.exe\",\"ID\":936,\"threadAmount\":545,\"cpuUsage\":0.0,\"ramUsage\":3557},{\"name\":\"WOMicClient.exe\",\"ID\":4212,\"threadAmount\":5,\"cpuUsage\":0.0,\"ramUsage\":7},{\"name\":\"Discord.exe\",\"ID\":6220,\"threadAmount\":172,\"cpuUsage\":4.638619201725998,\"ramUsage\":436},{\"name\":\"TextInputHost.exe\",\"ID\":17284,\"threadAmount\":14,\"cpuUsage\":0.0,\"ramUsage\":13},{\"name\":\"NVIDIA Share.exe\",\"ID\":8304,\"threadAmount\":75,\"cpuUsage\":0.10787486515641855,\"ramUsage\":61},{\"name\":\"UserOOBEBroker.exe\",\"ID\":11248,\"threadAmount\":1,\"cpuUsage\":0.0,\"ramUsage\":3},{\"name\":\"ShellExperienceHost.exe\",\"ID\":16892,\"threadAmount\":26,\"cpuUsage\":0.0,\"ramUsage\":59},{\"name\":\"WinStore.App.exe\",\"ID\":1672,\"threadAmount\":24,\"cpuUsage\":0.0,\"ramUsage\":3},{\"name\":\"ApplicationFrameHost.exe\",\"ID\":12864,\"threadAmount\":5,\"cpuUsage\":0.0,\"ramUsage\":22},{\"name\":\"Calculator.exe\",\"ID\":13592,\"threadAmount\":27,\"cpuUsage\":0.0,\"ramUsage\":3},{\"name\":\"Telegram.exe\",\"ID\":16940,\"threadAmount\":28,\"cpuUsage\":0.2157497303128371,\"ramUsage\":40},{\"name\":\"PaintStudio.View.exe\",\"ID\":1512,\"threadAmount\":50,\"cpuUsage\":0.0,\"ramUsage\":12},{\"name\":\"POWERPNT.EXE\",\"ID\":4708,\"threadAmount\":64,\"cpuUsage\":0.0,\"ramUsage\":122},{\"name\":\"Zoom.exe\",\"ID\":144,\"threadAmount\":119,\"cpuUsage\":0.0,\"ramUsage\":117},{\"name\":\"idea64.exe\",\"ID\":1640,\"threadAmount\":67,\"cpuUsage\":1.9417475728155338,\"ramUsage\":1020},{\"name\":\"conhost.exe\",\"ID\":7064,\"threadAmount\":14,\"cpuUsage\":0.0,\"ramUsage\":41},{\"name\":\"CompPkgSrv.exe\",\"ID\":19100,\"threadAmount\":1,\"cpuUsage\":0.0,\"ramUsage\":4},{\"name\":\"dllhost.exe\",\"ID\":1664,\"threadAmount\":2,\"cpuUsage\":0.0,\"ramUsage\":6},{\"name\":\"SystemSettingsBroker.exe\",\"ID\":4384,\"threadAmount\":1,\"cpuUsage\":0.0,\"ramUsage\":5},{\"name\":\"LockApp.exe\",\"ID\":5328,\"threadAmount\":18,\"cpuUsage\":0.0,\"ramUsage\":33},{\"name\":\"thunderbird.exe\",\"ID\":15716,\"threadAmount\":77,\"cpuUsage\":0.0,\"ramUsage\":184},{\"name\":\"WINWORD.EXE\",\"ID\":10876,\"threadAmount\":42,\"cpuUsage\":0.0,\"ramUsage\":144},{\"name\":\"java.exe\",\"ID\":8044,\"threadAmount\":165,\"cpuUsage\":0.970873786407767,\"ramUsage\":507}],\"collectInterval\":10000}";
    static String JTest="{\"Users\":[{\"name\":\"Goose\", \"ID\":2020, \"Programs\":[{\"name\":\"Discord\",\"ID\":100001,\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":5,\"activeWindowTime\":2,\"threadAmount\":2,\"cpuUsage\":1.941,\"ramUsage\":1231},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":2,\"activeWindowTime\":1,\"threadAmount\":2,\"cpuUsage\":4.912,\"ramUsage\":2131},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":7,\"activeWindowTime\":1,\"threadAmount\":2,\"cpuUsage\":8.271,\"ramUsage\":3131}]},{\"name\":\"Zoom\",\"ID\":100001,\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":5,\"activeWindowTime\":2,\"threadAmount\":2,\"cpuUsage\":1.941,\"ramUsage\":1231},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":2,\"activeWindowTime\":1,\"threadAmount\":2,\"cpuUsage\":4.912,\"ramUsage\":2131},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":7,\"activeWindowTime\":1,\"threadAmount\":2,\"cpuUsage\":8.271,\"ramUsage\":3131}]},{\"name\":\"DarkSouls\",\"ID\":100001,\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":5,\"activeWindowTime\":2,\"threadAmount\":2,\"cpuUsage\":1.941,\"ramUsage\":1231},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":2,\"activeWindowTime\":1,\"threadAmount\":2,\"cpuUsage\":4.912,\"ramUsage\":2131},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":7,\"activeWindowTime\":1,\"threadAmount\":2,\"cpuUsage\":8.271,\"ramUsage\":3131}]}]}]}";
    private static final int PORT = 5020;
    public static void main(String[] args) {
        try {
            System.out.println("♂Server start♂");
            Selector SelectorS = Selector.open();
            ServerSocketChannel ServerS = ServerSocketChannel.open();
            ServerS.bind(new InetSocketAddress(PORT));
            ServerS.configureBlocking(false);
            ServerS.register(SelectorS, SelectionKey.OP_ACCEPT);
            int i=0;
            while (true) {
                SelectorS.select();
                Set<SelectionKey> selectedKeys = SelectorS.selectedKeys();
                Iterator<SelectionKey> iter = selectedKeys.iterator();
                while(iter.hasNext())
                {

                    SelectionKey key = iter.next();
                    if(key.isAcceptable())
                    {
                        register(SelectorS, ServerS);
                        System.out.println("♂connect");
                    }
                    if(key.isReadable())
                    {
                        if(i==1)
                        {
                        showClientAnswer(key);
                        }
                        else
                        {
                            showClientAnswer2(key);
                            i++;
                        }
                    }
                    iter.remove();
                }
            }
        } catch (IOException e) {
            System.out.println("♂PogCham Server is down♂");
        }
    }

    private static void showClientAnswer(SelectionKey key) throws  IOException {
        SocketChannel client = (SocketChannel) key.channel();
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        client.read(buffer);
        String text = new String(buffer.array()).trim();
        if(text.length()>0)
            System.out.println(client+" | data: "+text);
        if(true)
        {
            ByteBuffer bufferWrite = ByteBuffer.allocate(30000);
            bufferWrite.put(JTest.getBytes());
            bufferWrite.flip();
            client.write(bufferWrite);
        }
    }
    private static void showClientAnswer2(SelectionKey key) throws  IOException {
        SocketChannel client = (SocketChannel) key.channel();
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        client.read(buffer);
        String text = new String(buffer.array()).trim();
        if(text.length()>0)
            System.out.println(client+" | data: "+text);

    }
    private static void register(Selector selector, ServerSocketChannel ServerS) throws IOException{
        SocketChannel client = ServerS.accept();
        client.configureBlocking(false);
        client.register(selector, SelectionKey.OP_READ);
    }
}

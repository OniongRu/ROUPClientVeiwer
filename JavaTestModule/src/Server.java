import java.io.*;
import java.nio.*;
import java.net.*;
import java.lang.*;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Set;
//сделать интеграционное тестирование
public class Server {
    static String JTest1="{\"OpType\":\"0\",\"Accept\":\"0\"}";
    static String JTest2="{\"OpType\":\"0\", \"Accept\":\"1\", \"Users\":[\"Goose\",\"JoJo\"], \"Programs\":[\"Skype\",\"Zoom\",\"DarkSouls\",\"Fifa\",\"Sekiro\"]}";
    static String JTest4="{\"OpType\":\"1\",\"Users\":[{\"name\":\"Goose\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Zoom\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"DarkSouls\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]}]}";
    static String JTest5="{\"OpType\":\"1\",\"Users\":[{\"name\":\"Goose\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Zoom\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"DarkSouls\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]},{\"name\":\"Yuki\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Wakanim\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Sekiro\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]}]}";
    static String JTest6="{\"OpType\":\"1\",\"Users\":[{\"name\":\"Goose\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Zoom\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"DarkSouls\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]},{\"name\":\"Yuki\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Wakanim\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Sekiro\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]},{\"name\":\"GoooseTest2\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Wakanim\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"DarkSouls\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]},{\"name\":\"Yuri\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Zoom\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"DarkSouls\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Sekiro\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]}]}";
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
                        showClientAnswer(key);
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
        int inf = client.read(buffer);


        System.out.println(inf);
        String text = new String(buffer.array(),"UTF-8").trim();
        System.out.println("| data: /"+text+"/");

        String Nikita = new String("<StartMsg>".getBytes(),"UTF-8");
        String meme2 = new String("NeedJson".getBytes(),"UTF-8");
        String[] words=text.split(Nikita);
        for (String word : words) {
            if(word.startsWith(meme2))
                text=word;
        }
        if(text.length()>0)
            System.out.println(client+" | data: /"+text+"/");



        String meme1 = new String("flag2".getBytes(),"UTF-8");
        String meme3 = new String("Login:".getBytes(),"UTF-8");
        if(text.startsWith(meme3)) {
            text=text.substring(6);
            if(text.equals(meme1))
            {
                System.out.println("Accept");
                ByteBuffer bufferWrite = ByteBuffer.allocate(30000);
                bufferWrite.put(JTest2.getBytes());
                bufferWrite.flip();
                client.write(bufferWrite);
                return;
            }
            System.out.println("NotAccept");
            ByteBuffer bufferWrite = ByteBuffer.allocate(30000);
            bufferWrite.put(JTest1.getBytes());
            System.out.println(JTest1.getBytes().length);
            bufferWrite.flip();
            client.write(bufferWrite);
            return;
        }

        System.out.println(text);
        if(text.startsWith(meme2))
        {
            System.out.println("GiveJson");
            ByteBuffer bufferWrite = ByteBuffer.allocate(JTest6.getBytes().length+1000);
            bufferWrite.put(JTest6.getBytes());
            System.out.println(JTest6.getBytes().length);
            bufferWrite.flip();
            client.write(bufferWrite);
            return;
        }

        /*String meme4 = new String("Test".getBytes(),"UTF-8");
        if(text.startsWith(meme4)) {
            text = text.substring(4);
            System.out.println(text);
        }*/
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

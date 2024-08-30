import java.io.*;

public class Main {
    public static void main(String [] args) {

        //FileWriter f1 = null;

//        try
//        {
//            f1 = new FileWriter("D:\\te.txt",true);
//            //f1.write("hello");
//            char[] c = new char[]{'2','3','4','5'};
//            f1.write(c);
////            f1.write('2');
////            f1.write("23456",2,3);
//            f1.write("\n");
//            f1.flush();
//            f1.close();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        try
//        {
//            f1.close();
//        }
//        catch (IOException e) {
//            e.printStackTrace();
//        }


        try {
            FileReader fr = new FileReader("D:\\te.txt");
            int ch;
            while((ch = fr.read())!= -1)
            {
                System.out.println((char)ch);
            }
            fr.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch(Exception e)
        {
            e.printStackTrace();
        }


    }
}

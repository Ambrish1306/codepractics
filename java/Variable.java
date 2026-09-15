import java.util.ArrayList;
import java.util.HashMap;
public class Variable {

     int a=20; 
     float b=2.5f;
     String c="Ambrish";
     int arr[] = {1,2,3,4,5};
     float abc;
     ArrayList<String> list = new ArrayList<String>();
     HashMap<String, Integer> hmap = new HashMap<String, Integer>();
  
    public static void main(String[] args) {
        Variable obj = new Variable();
        System.out.println("Integer value: " + obj.a);
        System.out.println("Float value: " + obj.b);
        System.out.println("String value: " + obj.c);
        System.out.print("Array values: ");
        for(int i=0;i < obj.arr.length; i++){
            System.out.print(obj.arr[i] + " ");
        }
        obj.list.add("Ambrish");
        obj.list.add("Kumar");
        obj.list.add("Java");
        obj.hmap.put("Ambrish",1);
        obj.hmap.put("programming", 2);

        System.out.println("HashMap values: " + obj.hmap.get("Ambrish"));
        System.out.println("Float value of abc: " + obj.abc);
        System.out.println("\nArrayList values: " + obj.list);
        System.out.println("Array values: " + obj.arr[0] );

    }
}
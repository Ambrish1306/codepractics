import java.util.HashMap;
public class HashMapExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hmap = new HashMap<String, Integer>();
        hmap.put("Ambrish", 1);
        hmap.put("programming", 2);
        System.out.println("HashMap values: " + hmap.get("Ambrish"));
    }                   
}

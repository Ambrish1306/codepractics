import java.util.concurrent.ConcurrentHashMap;
//when we want to use a HashMap in a multi-threaded environment, we can use ConcurrentHashMap. It is a thread-safe variant of HashMap that allows concurrent read and write operations without the need for explicit synchronization.

public class ConCurHashMap {
    public static void main(String[] args) {
        ConcurrentHashMap<String, Integer> cmap = new ConcurrentHashMap<>();
        cmap.put("Ambrish", 1);
        cmap.put("programming", 2);
        System.out.println("ConcurrentHashMap values: " + cmap.get("Ambrish"));
    }       
}

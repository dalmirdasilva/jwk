package jwk;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author dalmir
 */
public class Main {

    public static void main(String[] args) throws JWkFailException {
        Map<String, String> options = new HashMap<>();
        options.put("key", "value");
        new JWk().convert("http://localhost", "/tmp/sys.pdf", options);
    }
}

package jwk;

import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author dalmir
 */
public class Main {

    public static void main(String[] args) throws JWkFailException {
        Map<String, String> options = new HashMap<>();
        options.put("key", "value");

        JWk jwk = new JWk();

        for (int i = 0; i < 2; i++) {
            final int j = i;
            new Thread() {

                @Override
                public void run() {
                    try {
                        jwk.convert("http://localhost", "/tmp/sys_" + j + ".pdf", options);
                    } catch (JWkFailException ex) {
                        Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }.start();
        }
    }
}

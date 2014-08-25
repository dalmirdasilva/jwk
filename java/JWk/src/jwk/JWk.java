package jwk;

import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Convert HTML to PDF using WKHTMLTOX without launching
 *
 * @author dalmir
 */
public class JWk {

    static {
        Path LIBPATH = Paths.get(System.getProperty("user.dir"));
        System.load(LIBPATH + "/../../c/JWkLib/dist/libJWkLib.so");
    }

    public static void main(String[] args) {
        Map<String, String> options = new HashMap<>();
        options.put("key", "value");
        try {
            for (int i = 0; i < 1000; i++) {
                new JWk().sysConvert("http://localhost", "/tmp/sys.pdf"/*, options*/);
            }
        } catch (IOException ex) {
            Logger.getLogger(JWk.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private native void convert(String src, String dst/*, Map<String, String> options*/);

    private void sysConvert(String src, String dst) throws IOException {
        Runtime.getRuntime().exec("wkhtmltopdf " + src + " " + dst);
    }
}

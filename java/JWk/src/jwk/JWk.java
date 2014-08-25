package jwk;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Map;

/**
 * Convert HTML to PDF using WKHTMLTOX without launching
 *
 * @author dalmir
 */
public class JWk {

    private List<String> warnings;
    private List<String> errors;
    private List<String> infos;

    static {
        Path LIBPATH = Paths.get(System.getProperty("user.dir"));
        System.load(LIBPATH + "/../../c/JWkLib/dist/libJWkLib.so");
    }

    public void convert(String src, String dst, Map<String, String> options) throws JWkFailException {
        warnings = new ArrayList<>();
        errors = new ArrayList<>();
        infos = new ArrayList<>();
        if (!convertImp(src, dst, options, options.entrySet().toArray())) {
            throw new JWkFailException("Cannot convert.");
        }
    }

    public List<String> getWarnings() {
        return warnings;
    }

    public List<String> getErrors() {
        return errors;
    }

    public List<String> getInfos() {
        return infos;
    }

    private void addWarning(String warning) {
        warnings.add(warning);
    }

    private void addError(String error) {
        errors.add(error);
    }

    private void addInfo(String info) {
        infos.add(info);
    }

    private native boolean convertImp(String src, String dst, Map<String, String> options, Object[] optionsKeys) throws JWkFailException;
}

package jwk;

/**
 *
 * @author dalmir
 */
public class JWkFailException extends Exception {

    JWkFailException(String convertionErrors) {
        super(convertionErrors);
    }
    
}

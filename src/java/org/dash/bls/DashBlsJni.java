package org.dash.bls;

//https://www.baeldung.com/jni
 
public class DashBlsJni {
 
    static {
        System.loadLibrary("dashjbls");
    }
     
    public static void main(String[] args) {
        DashBlsJni blsJni = new DashBlsJni();
        //String message = blsJni.sayHelloToMe("Dash", false);
        //System.out.println("blsJni.sayHelloToMe(\"Dash\", false) = " + message);
        //long result = blsJni.sumIntegers(2, 3);
        //System.out.println("blsJni.sumIntegers(2, 3) = " + result);
        blsJni.callBls();
    }

    private native long sumIntegers(int first, int second);

    private native String sayHelloToMe(String name, boolean isFemale);
    
    private native void callBls();
}

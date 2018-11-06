package org.dash.bls;
 
public class DashBlsJni {
 
    static {
        System.loadLibrary("dashjbls");
    }
     
    public static void main(String[] args) {
        
        int[] seed = new int[] {
            0, 50, 6, 244, 24, 199, 1, 25, 52, 88, 192,
            19, 18, 12, 89, 6, 220, 18, 102, 58, 209,
            82, 12, 62, 89, 110, 182, 9, 44, 20, 254, 22};

        DashBlsJni blsJni = new DashBlsJni();
		blsJni.nativeSignMessage();
		
//        long fingerprint = blsJni.publicKeyFingerprint(seed);
//        System.out.println("Fingerprint (java):\t\t" + fingerprint);

        byte[] privateKey = blsJni.generatePrivateKey(seed);
//        byte[] publicKey = blsJni.generatePublicKey(privateKey);
//        for (byte item : privateKey) {
//            System.out.println("item:\t" + (item & 0xFF));
//        }

        int[] msg = new int[] {100, 2, 254, 88, 90, 45, 23};

        byte[] sign = blsJni.signMessage(privateKey, msg);
        System.out.print("java sign:  \t{");
        for (byte item : sign) {
            System.out.print((item & 0xFF) + ", ");
        }
        System.out.println("}");
    }

    private native long publicKeyFingerprint(int[] seed);
	
    private native void nativeSignMessage();

    private native byte[] generatePrivateKey(int[] seed);

    private native byte[] generatePublicKey(byte[] privateKey);

    private native byte[] signMessage(byte[] publicKey, int[] msg);
}

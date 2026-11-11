class RC4 {
    public static void main(String[] args) {
        String plaintext = "This is a secret message";
        String key = "secretkey";

        int s[] = new int[256];
        int k[] = new int[256];

        for (int i = 0; i < 256; i++) {
            s[i] = i;
            k[i] = key.charAt(i % key.length());
        }

        int j = 0, temp;

        for (int i = 0; i < 256; i++) {
            j = (j + s[i] + k[i]) % 256;

            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }

        int i = 0;
        j = 0;

        StringBuilder cipher = new StringBuilder();
        StringBuilder decrypt = new StringBuilder();

        for (int y = 0; y < plaintext.length(); y++) {
            i = (i + 1) % 256;
            j = (j + s[i]) % 256;

            temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            int z = s[(s[i] + s[j]) % 256];

            int c = plaintext.charAt(y) ^ z;
            cipher.append((char) c);

            decrypt.append((char) (c ^ z));
        }

        System.out.println("Plaintext: " + plaintext);
        System.out.println("Cipher Text: " + cipher);
        System.out.println("Decrypted Text: " + decrypt);
    }
}

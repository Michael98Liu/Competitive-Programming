import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static int INF = (int)1e9;
	public static void main(String[] argv)throws IOException {

		InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = in.nextInt(), k = in.nextInt(), m = in.nextInt();
        int[] powers = new int[n];
        for (int i=0; i<n; i++) powers[i] = in.nextInt();
        Arrays.sort(powers);
        long[] sums = new long[n];
        sums[0] = powers[n-1];
        for (int i=1; i<n; i++) sums[i] = sums[i-1] + powers[n-1-i];
        double max = (double)sums[n-1]/(double)n;
        for (int i=0; i<Math.min(m, n); i++) {
        	long added = Math.min((long)(n-i)*k, (long)m-i);
        	double avg = (double)(sums[n-1-i] + added)/(double)(n-i);
        	max = Math.max(avg, max);
        }
        System.out.printf("%.8f\n", max);
	}


	static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

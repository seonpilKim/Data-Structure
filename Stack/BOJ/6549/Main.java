package ksp;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {
	public static class pair {
		int first;
		int second;

		public pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}

	public static void main(String args[]) throws IOException {
		Stack<pair> s = new Stack<>();
		int n;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		while (true) {
			String[] input = br.readLine().split(" ");
			n = Integer.parseInt(input[0]);
			if (n == 0)
				break;

			long width, height;
			int rec;
			long area = 0;

			for (int i = 0; i < n; i++) {
				rec = Integer.parseInt(input[1 + i]);

				if (s.empty() || (!s.empty() && s.peek().first <= rec))
					s.push(new pair(rec, i));
				else if (!s.empty() && s.peek().first > rec) {
					while (!s.empty() && s.peek().first >= rec) {
						height = s.peek().first;
						s.pop();

						if (s.empty())
							width = i;
						else
							width = i - s.peek().second - 1;

						if (area < width * height)
							area = width * height;
					}

					s.push(new pair(rec, i));
				}
			}

			while (!s.empty()) {
				height = s.peek().first;
				s.pop();

				if (s.empty())
					width = n;
				else
					width = n - s.peek().second - 1;

				if (area < width * height)
					area = width * height;
			}

			bw.write(String.valueOf(area) + '\n');
		}

		bw.flush();
		br.close();
		bw.close();
	}
}

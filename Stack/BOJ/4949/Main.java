package ksp;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {
	public static void main(String args[]) throws IOException {
		Stack<Character> s = new Stack<>();
		String input = null;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		while (true) {
			boolean flag = true;
			input = br.readLine();
			
			if (input.charAt(0) == '.')
				break;

			for (int i = 0; i < input.length(); i++) {
				if (input.charAt(i) == '.')
					break;
				else if (input.charAt(i) == '(' || input.charAt(i) == '[')
					s.push(input.charAt(i));
				else if (input.charAt(i) == ')') {
					if (s.empty() || s.peek() != '(') {
						flag = false;
						break;
					}
					s.pop();
				} else if (input.charAt(i) == ']') {
					if (s.empty() || s.peek() != '[') {
						flag = false;
						break;
					}
					s.pop();
				}
			}

			if (!s.empty() || !flag) {
				bw.write("no\n");
				s.clear();
			} else
				bw.write("yes\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}

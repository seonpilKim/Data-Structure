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
		String str;
		int answer = 0;
		int val = 1;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		str = br.readLine();

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '(') {
				s.push(str.charAt(i));
				val *= 2;
			} else if (str.charAt(i) == '[') {
				s.push(str.charAt(i));
				val *= 3;
			} else if (str.charAt(i) == ')') {
				if (s.empty() || s.peek() != '(') {
					answer = 0;
					break;
				} else {
					if (str.charAt(i - 1) == '(')
						answer += val;
					val /= 2;
					s.pop();
				}
			} else if (str.charAt(i) == ']') {
				if (s.empty() || s.peek() != '[') {
					answer = 0;
					break;
				} else {
					if (str.charAt(i - 1) == '[')
						answer += val;
					val /= 3;
					s.pop();
				}
			}
		}

		if (!s.empty())
			answer = 0;
		
		bw.write(String.valueOf(answer));
		bw.flush();
		br.close();
		bw.close();
	}
}

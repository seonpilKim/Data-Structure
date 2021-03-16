## **[[2504] 괄호의 값](https://www.acmicpc.net/problem/2504)**
___
![](prob.PNG)![](prob2.PNG)
___
## **풀이**
괄호 문자열이 올바른지 판단과 동시에 괄호에 따라 value를 추가하여 출력하는 문제이다.<br>
아래와 같은 규칙으로 value 를 설정한다.
1. `여는 괄호의 경우 val 변수에 해당 값을 곱해`준다.
2. `닫는 괄호의 경우 val 변수에 해당 값을 나눠`준다.
3. `여는 괄호 다음에 바로 닫는 괄호가 오는 경우 answer 변수에 값을 더해`준다.<br>
> 풀고나서 보면 간단한 원리였지만, 이 원리를 발견하는 데 까지 시간이 너무 오래 걸렸었다.
___
### C++

```c++
for (int i = 0; i < str.size(); i++) {
    // 여는 괄호의 경우 val 변수에 해당 값을 곱해준다.
        if (str[i] == '(') {
            s.push(str[i]);
            val *= 2;
        }
        else if (str[i] == '[') {
            s.push(str[i]);
            val *= 3;
        }
    // 닫는 괄호의 경우 val 변수에 해당 값을 나눠준다.
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                answer = 0;
                break;
            }
            else {
                // 여는 괄호 다음에 바로 닫는 괄호가 오는 경우 answer 변수에 val 값을 더해준다.
                if (str[i - 1] == '(')
                    answer += val;
                val /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                answer = 0;
                break;
            }
            else {
                if (str[i - 1] == '[')
                    answer += val;
                val /= 3;
                s.pop();
            }
        }
    }
}
if (!s.empty()) answer = 0;
``` 
___
### Java
```java
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
		
        // 자바에서 BufferedWriter에 int형 값을 write하려면, 먼저 String 형으로 변환하여야 한다.
		bw.write(String.valueOf(answer));
```
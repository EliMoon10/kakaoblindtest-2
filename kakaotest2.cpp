#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int tokener(string dartresult) {
	int answer = 0;
	int arr[3] = { 0 };
	int cnt = -1;
	//Single(S), Double(D), Triple(T)영역
	// S = n^1, D = n^2, T = n^3
	//스타상(*) , 아차상(#)
	//# = 해당 점수는 마이너스된다. * = 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다
	//스타상(*)은 첫 번째 기회에서도 나올 수 있다. 이 경우 첫 번째 스타상(*)의 점수만 2배가 된다.
	//스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상(*) 점수는 4배가 된다.
	//스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다. 이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. 

	for (int i = 0; i < dartresult.size(); i++) {
		if (dartresult[i] >= '0' && dartresult[i] <= '9') {
			cnt++;
			if (dartresult[i] == '1' && dartresult[i + 1] == '0') {
				arr[cnt] = 10;
				i++;
			}
			else
			{
				arr[cnt] = (int)(dartresult[i] - '0');
			}
		}
		else if (dartresult[i] == 'D') {
			arr[cnt] *= arr[cnt];
		}
		else if (dartresult[i] == 'T') {
			arr[cnt] = arr[cnt] * arr[cnt] * arr[cnt];
		}
		else if (dartresult[i] == '*') {
			if (cnt != 0)
				arr[cnt - 1] *= 2;
			arr[cnt] *= 2;
		}
		else if (dartresult[i] == '#') {
			arr[cnt] *= -1;
		}
	}
	answer = arr[0] + arr[1] + arr[2];
	return answer;
}

int main()
{
	string strstr;
	int jj;

	for (int i = 0; i < 1; i++) {
		strstr = "1D2S#10S";
		jj = tokener(strstr);
		cout << jj;
	}
	return 0;
}

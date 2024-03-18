//น้มุ4673
#include <stdio.h>

#define MAX 10000

int arr[MAX] = { 0 };
int d(int n);

int main() {

	int temp;

	for (int i = 1; i <= MAX; i++) {
		temp = d(i);
		if (temp != i) {
			arr[temp] = 1;
		}
	}

	for (int i = 1; i <= MAX; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}


}

int d(int n) {

	int ans = n;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}

	return ans;
}
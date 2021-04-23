#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	vector<int> store(N);
	vector<int> customer(M);
	vector<string> answer;

	for (int i = 0; i < N; i++) {
		cin >> store[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> customer[i];
	}

	sort(store.begin(), store.end());
	sort(customer.begin(), customer.end());

	for (int i = 0; i < M; i++) {
		int start = 0;
		int fin = N - 1;
		bool check = false;

		while (start <= fin) {
			int mid = (start + fin) / 2;

			if (customer[i] == store[mid]) {
				answer.push_back("yes");
				check = true;
				break;
			}

			else if (customer[i] < store[mid]) {
				fin = mid - 1;
			}

			else if (customer[i] > store[mid]) {
				start = mid + 1;
			}
		}

		if (check == false) {
			answer.push_back("no");
		}
	}

	for (int i = 0; i < M; i++) {
		cout << answer[i] << " ";
	}
	
	return 0;
}
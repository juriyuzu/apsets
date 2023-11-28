#include <iostream>
#include <string>
using namespace std;

struct Fun {
	void diamond() {
		int x, y = 1;
		cout << "Radius: ";
		cin >> x;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < x - i - 1; j++) cout << " ";
			for (int j = 0; j < i * 2 + 1; j++) cout << "*";
			cout << endl;
		}
		for (int i = x - 2; i >= 0; i--) {
			for (int j = 0; j < x - i - 1; j++) cout << " ";
			for (int j = 0; j < i * 2 + 1; j++) cout << "*";
			cout << endl;
		}
	}
		
	void pascal() {
		int x;
		cout << "Height: ";
		cin >> x;
		int arr[2][x] = {{1}};
		for (int i = 0; i < x; i++) {
			for (int j = 0; j <= (x - i - 1) * 2 - 1; j++) cout << " ";
			for (int j = 0; j <= i; j++) {
				int n = (j == i && i != 0 ? 0 : arr[0][j]) + (j == 0 ? 0 : arr[0][j - 1]);
				cout << n << "   ";
				arr[1][j] = n;
			}
			for (int j = 0; j < x; j++) arr[0][j] = arr[1][j];
			cout << endl;
		}
	}
	
	void asterisk() {
		int x;
		cout << "Radius: ";
		cin >> x;
		x--;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < i; j++) cout << " ";
			for (int j = 0; j < 3; j++) {
				cout << "*";
				for (int k = 0; k < x - i - 1; k++) cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < x * 2 + 1; i++) cout << "*";
		cout << endl;
		for (int i = x - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) cout << " ";
			for (int j = 0; j < 3; j++) {
				cout << "*";
				for (int k = 0; k < x - i - 1; k++) cout << " ";
			}
			cout << endl;
		}
	}
	
	private:	
	void permutationFun(char arr[], int index[], string s, int size, int full) {
		if (size == full) {
			cout << s << endl;
			return;
		}
		for (int i = 0; i < full; i++) {
			bool f = false;
			for (int j = 0; j < size; j++) if (index[j] == i) f = true;
			if (f) continue;
			index[size] = i;
			permutationFun(arr, index, s + " " + arr[i], size + 1, full);
		}
	}
	
	public:
	void permutation() {
		int n;
		cout << "Size: ";
		cin >> n;
		char arr[n];
		int index[n];
		cout << "Array: ";
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			index[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			index[0] = i;
			permutationFun(arr, index, string("") + arr[i], 1, n);
		}
	}
	
	void barcode() {
		string lower = "abcdefghijklmnopqrstuvwxyz";
		string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string digit = "0123456789";
		
		int n;
		cout << "Size: ";
		cin >> n;
		char arr[n];
		cout << "Array: ";
		for (int i = 0; i < n; i++) cin >> arr[i];
		string s = "";
		for (char c : arr) {
			bool b = false;
			for (char cc : digit) {
				if (cc == c) {
					for (int i = 0; i < c - '0'; i++) s += "|";
					b = true;
					break;
				}
			}
			if (b) continue;
			for (char cc : upper) {
				if (cc == c) {
					s += "0";
					b = true;
					break;
				}
			}
			if (b) continue;
			for (int i = 0; i < 26; i++) if (lower[i] == c) s += to_string(i + 1);
		}
		for (int i = 0; i < 4; i++) cout << s << endl;
	}
	
	void thousands() {
		string s, s2 = "", s3 = "";
		cout << "Number: ";
		cin >> s;
		int a = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			s2 += s[i] + (a == 2 && i > 0 ? "," : string(""));
			a = (a + 1) % 3;
		}
		for (int i = s2.size() - 1; i >= 0; i--) cout << s2[i];
	}
	
	void spy() {
		int a, b;
		cout << "Height and Width: ";
		cin >> a >> b;
		int arr[a * b];
		cout << "Array:\n";
		for (int i = 0; i < a * b; i++) cin >> arr[i];
		for (int i = 0; i < a * b; i++) {
			bool f = true;
			for (int j = 0; j < a * b; j++) {
				if (arr[j] == arr[i] && j != i) {
					f = false;
					break;
				}
			}
			if (f) {
				cout << "SPY";
				return;
			}
		}
		cout << "NONE";
	}
	
	void anagram() {
		string a, b;
		cout << "Two Strings: ";
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++) {
			bool f = true;
			for (int j = 0; j < a.size(); j++) {
				if (a[i] == b[j]) {
					f = false;
					b[j] = 0;
					break;
				}
			}
			if (f) {
				cout << "False";
				return;
			}
		}
		cout << "True";
	}

	void binaryTreeFun(int arr[], int set[], int &min, int sum, int height, int level, int index, string &path, string stack) {
		if (level == height) {
			if (sum < min) {
				min = sum;
				path = stack;
				path += "]";
			}
			return;
		}
		for (int i = index; i <= index + 1 ; i++) binaryTreeFun(arr, set, min, sum + arr[set[level - 1] + i], height, level + 1, i, path, stack + to_string(arr[set[level - 1] + i]) + (level == height - 1 ? string("") : ", "));
	}
	
	void binaryTree() {
		int n;
		cout << "Height: ";
		cin >> n;
		int height = n;
		for (int i = 1; i < height; i++) n += i;
		int set[n] = {0};
		int ii = 2;
		for (int i = 1; i < height; i++) {
			set[i] = ii;
			ii += i + 2;
		}
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		int min = INT_MAX;
		string path = "[";
		binaryTreeFun(arr, set, min, arr[0], height, 1, 1, path, path + to_string(arr[0]) + (height == 1 ? string("") : ", "));
		cout << "Smallest sum: " << min
			 << "\nPath: " << path;
	}
	
	void treasureMapFun(char arr[], int h, int w, int sc, int ec, int pc[], int cd, int &d) {
		if (sc == ec) {	
			if (cd < d) d = cd;
			return;
		}
		int p = 0, parr[4] = {(sc % w == w - 1 ? -1 : sc + 1), (sc % w == 0 ? -1 : sc - 1), (sc >= w * (h - 1) ? -1 : sc + w), (sc < w ? -1 : sc - w)};
		for (int i = 0; i < 4; i++) {
			bool pcf = true;
			for (int j = 0; j < h	 * w; j++) if (pc[j] == parr[i]) pcf = false;
			if (parr[i] != -1 && (arr[parr[i]] == 'O' || arr[parr[i]] == 'E') && pcf) {
				pc[cd] = sc;
				treasureMapFun(arr, h, w, parr[i], ec, pc, cd + 1, d);
				pc[cd] = -1;
			}
		}
	}
	
	void treasureMap() {
		int h, w;
		cout << "Rows: ";
		cin >> h;
		cout << "Columns: ";
		cin >> w;
		char *arr = new char[h * w];
		for (int i = 0; i < h * w; i++) cin >> arr[i];
		bool sf = true, ef = true;
		int sc, ec, pc[h * w];
		for (int i = 0; i < h * w; i++) {
			pc[i] = -1;
			if (arr[i] == 'S') {
				sf = false;
				sc = i;
			}
			if (arr[i] == 'E') {
				ef = false;
				ec = i;
			}
		}
		if (sf || ef) {
			if (sf) cout << "MISSING PLAYER";
			if (ef) cout << "MISSING TREASURE";
			return;
		}
		int d = INT_MAX;
		treasureMapFun(arr, h, w, sc, ec, pc, 0, d);
		if (d == INT_MAX) cout << "BLOCKED";
		else cout << "STEPS: " << d;
	}
};

int main() {
	Fun fun;
	
//	cout << "## Diamond ##\n";
//	fun.diamond();
//	cout << "\n\n";
//	
//	cout << "## Pascal ##\n";
//	fun.pascal();
//	cout << "\n\n";
//	
//	cout << "## Asterisk ##\n";
//	fun.asterisk();
//	cout << "\n\n";	
//	
//	cout << "## Permutation ##\n";
//	fun.permutation();
//	cout << "\n\n";
//	
//	cout << "## Barcode ##\n";
//	fun.barcode();
//	cout << "\n\n";
//	
//	cout << "## Thousands ##\n";
//	fun.thousands();
//	cout << "\n\n\n";
//	
//	cout << "## Spy ##\n";
//	fun.spy();
//	cout << "\n\n\n";
//	
//	cout << "## Anagram ##\n";
//	fun.anagram();
//	cout << "\n\n\n";
//	
//	cout << "## Binary Tree ##\n";
//	fun.binaryTree();
//	cout << "\n\n";
	
	cout << "## Treasure Map ##\n";
	fun.treasureMap();
	cout << "\n\n";
	
	return 0;
}

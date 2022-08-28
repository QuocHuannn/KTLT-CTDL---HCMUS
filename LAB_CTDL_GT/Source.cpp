#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* sum(int* a, int* b)
{
	int sum = *a + *b;
	int* s = &sum;
	return s;
}

void inputArray(int*& a, int& n)
{
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int* findMax(int* arr, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int* findmax = &max;
	return findmax;
}

int* findLongestAscendingSubarray(int* a, int n, int& length_Max)
{
	length_Max = 1;
	int length = 1;
	int pos = 0;
	int posMax = 0;
	for (int i = 0; i < n; i++) {
		if (a[i + 1] < a[i]) {
			if (length > length_Max) {
				length_Max = length;
				posMax = pos - length_Max + 2;
			}
			length = 1;
		}
		else {
			pos = i;
			length++;
		}
	}
	int* sub = new int[length_Max];
	for (int b = 0; b < length_Max; b++) {
		sub[b] = a[posMax];
		posMax++;
	}
	return sub;
}

void swapArrays(int*& a, int*& b, int& na, int& nb)
{
	int* temp = new int[na];
	for (int i = 0; i < na; i++) {
		temp[i] = a[i];
	}
	a = new int[nb];
	for (int i = 0; i < nb; i++) {
		a[i] = b[i];
	}
	b = new int[na];
	for (int i = 0; i < na; i++) {
		b[i] = temp[i];
	}

	int c = na;
	na = nb;
	nb = c;
}

int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
	int* temp = new int[na + nb];
	for (int i = 0; i < na + nb ; i++) {
		if (i < na) {
			temp[i] = a[i];
		}
		else {
			temp[i] = b[i-na];
		}
	}
	return temp;
}

int* merge2Arrays(int* a, int* b, int na, int nb, int& nc)
{
	int* temp = concatenate2Arrays(a, b, na, nb);
	nc = na + nb;
	for (int i = 0; i < nc; i++) {
		for (int j = i + 1; j < nc; j++) {
			if (temp[i] > temp[j]) {
				swap(temp[i], temp[j]);
			}
		}
	}
	return temp;
}

void generateMatrix1(int** A, int& length, int& width) {
	A = new int* [length];
	for (int i = 0; i < length; i++) {
		A[i] = new int[width];
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			A[i][j] = rand() & 100;
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int** generateMatrix2(int* a, int* b, int na, int nb)
{
	int **c = new int* [na];
	for (int i = 0; i < na; i++) {
		c[i] = new int[nb];
	}
	for (int i = 0; i < na; i++) {
		for (int j = 0; j < nb; j++) {
			c[i][j] = a[i] * b[j];
		}
	}
	return c;
}

void print2dArray(int** a, int length, int width)
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int** transposeMatrix(int** a, int length, int width)
{
	int** matrix = new int* [length];
	for (int i = 0; i < length; i++) {
		matrix[i] = new int[width];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			matrix[i][j] = a[j][i];
		}
	}
	return matrix;
}

int** concatenate2MatricesH(int** a, int** b, int length, int width)
{
	int rong = length * 2;
	int** matrix = new int* [length];
	for (int i = 0; i < length; i++) {
		matrix[i] = new int[rong];
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < rong; j++) {
			if (j < width) {
				matrix[i][j] = a[i][j];
			}
			else {
				matrix[i][j] = b[i][j - width];
			}
		}
	}
	return matrix;
}

int** concatenate2MatricesV(int** a, int** b, int length, int width)
{
	int dai = length*2;
	int** matrix = new int* [dai];
	for (int i = 0; i < dai; i++) {
		matrix[i] = new int[width];
	}
	for (int i = 0; i < dai; i++) {
		for (int j = 0; j < width; j++) {
			if (i < length) {
				matrix[i][j] = a[i][j];
			}
			else {
				matrix[i][j] = b[i - length][j];
			}
		}
	}
	return matrix;
}

bool multiple2Matrices(int** a, int** b, int lengtha, int widtha, int lengthb, int widthb) {
	if (widtha != lengthb) {
		cout << "sai dieu kien!";
		return false;
	}
	else {

		int** matrix = new int* [lengtha];
		for (int i = 0; i < lengtha; i++) {
			matrix[i] = new int[widthb];
		}
		int k = 0;
		for (int i = 0; i < lengtha; i++) {
			for (int j = 0; j < widthb; j++) {
				matrix[i][j] = 0;
				for (int k = 0; k < widtha; k++) {
					matrix[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		for (int i = 0; i < lengtha; i++) {
			for (int j = 0; j < widthb; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return true;
	}
}

void swapRows(int** a, int length, int width)
{
	int chose = 0, change = 0;
	cout << "choose row: ";
	cin >> chose;
	cout << endl;
	cout << "choose row to be exchanged : ";
	cin >> change;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i == chose) {
				swap(a[i][j], a[change][j]);
			}
		}
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void swapColumns(int** a, int length, int width)
{
	int chose = 0, change = 0;
	cout << "choose column: ";
	cin >> chose;
	cout << endl;
	cout << "choose column to be exchanged : ";
	cin >> change;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (j == chose) {
				swap(a[i][j], a[i][change]);
			}
		}
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

int** findSubmatrix(int** a, int length, int width, int& length_, int& width_)
{
	int max_sum = 0;
	int index_i = 0, index_j = 0;
	for (int i = 0; i < length - length_ + 1; i++) {
		for (int j = 0; j < width - width_ + 1; j++) {
			int sum = 0;
			for (int k = i; k < i + length_; k++) {
				for (int l = j; l < j + width_; l++) {
					sum += a[k][l];
				}
			}
			if (sum > max_sum) {
				index_i = i;
				index_j = j;
				max_sum = sum;
			}
		}
	}
	int** sub = new int* [length_];

	for (int i = 0; i < length_; i++) {
		sub[i] = new int[width_];
	}
	for (int i = 0; i < length_; i++) {
		for (int j = 0; j < width_; j++) {
			sub[i][j] = a[index_i + i][index_j + j];
		}
	}
	return sub;
}

int* comon(int* a, int* b, int lena, int lenb) {
	int dem = 0;
	for (int i = 0; i < lena; i++) {
		for (int j = 0; j < lenb; j++) {
			if (a[i] % 2 != 0 && a[i] == b[j]) {
				dem++;
			}
		}
	}
	int* arr = new int[dem];
	int i = 0;
	for (int k = 0; k < lena; k++) {
		for (int j = 0; j < lenb; j++) {
			if (a[k] % 2 != 0 && a[k] == b[j]) {
				arr[i] = a[k];
				i++;
			}
		}
	}
	return arr;
}

int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}

int SentinelLinearSearch(int* a, int n, int key)
{
	if (a[n - 1] == key) {
		return a[n - 1];
	}
	else {
		a[n - 1] == key;
		int i = 0;
		while (a[i] != key) {
			i++;
		}
		if (i < n) {
			return i;
		}
		else {
			return -1;
		}
	}
}

int BinarySearch(int* a, int n, int key)
{
	int mid = 0;
	int l = 0;
	int r = n - 1;
	
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] < key) {
			l = mid + 1;
		}
		else if (a[mid] > key) {
			r = mid - 1;
		}
		else {
			return  mid;
		}
	}
	return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	if (left <= right) {
		int mid = (left + right) / 2;

		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] < key) {
			return RecursiveBinarySearch(a, mid + 1, right, key);
		}
		else {
			return RecursiveBinarySearch(a, left, mid - 1, key);
		}
	}
	return -1;
}

int main() {

}
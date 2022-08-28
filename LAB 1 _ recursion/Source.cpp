#include <iostream>
using namespace std;

int sumRe(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n + sumRe(n - 1);
	}
}

int factorialRe(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * factorialRe(n - 1);
	}
}

int x_mu_n(int x, int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return x * x_mu_n(x, n - 1);
	}
}

int countDegitsRe(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return 1 + countDegitsRe(n / 10);
	}
}

int verifyEvenRe(int n) {
	if (n % 2 == 1) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	else {
		return verifyEvenRe(n / 10);
	}
}

int reverse(int n) {
	int du = n % 10;
	int power = countDegitsRe(n);
	if (n == 0) {
		return 0;
	}
	else {
		return du * pow(10, power - 1) + reverse(n / 10);
	}
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int countCommonDiv(int a, int b, int c) {
	if (c == 1) {
		return 1;
	}
	if (a % c == 0 && b % c == 0) {
		return 1 + countCommonDiv(a, b, c - 1);
	}
	else {
		return countCommonDiv(a, b, c - 1);
	}
}

int fib(int n)
{
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main() {

}
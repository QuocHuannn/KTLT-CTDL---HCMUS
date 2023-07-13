#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(string file_name) {
	vector <Company> cpn;
	ifstream fin(file_name);
	string s;
	getline(fin, s);
	int i = 0;
	while (!fin.eof()) {
		cpn.push_back(Company());
		getline(fin, s);
		stringstream ss(s);
		getline(ss, cpn[i].name, '|');
		getline(ss, cpn[i].profit_tax, '|');
		getline(ss, cpn[i].address);
		i++;
	}
	return cpn;

}

string splitString(string s) {
	string temp = "";
	if (s.size() <= 20) {
		return s;
	}
	else {
		int count = 0;
		for (int i = s.size(); count <= 20; i--) {
			temp += s[i];
			count++;
		}
		reverse(temp.begin(), temp.end());
		return temp;
	}
}

long long hashCalculate(int i, long long m) {
	long long result = 31;
	for (int j = 1; j < i; j++) {
		result *= 31;
		result = result % m;
	}
	return result;
}

long long HashString(string company_name) {
	string s = splitString(company_name);
	long long m = pow(10, 9) + 9;
	long long hashKey = 0;
	for (int i = 0; i < s.length(); i++) {
		hashKey += s[i] * hashCalculate(i, m);
		hashKey = hashKey % m;
	}
	return hashKey;
}

Company* CreateHashTable(vector<Company> list_company) {
	int key = 0;
	Company* table = new Company[2000];
	for (int i = 0; i < 2000; i++) {
		table[i] = { "","","" };
	}
	int hashkey = 0;
	for (int i = 0; i < list_company.size(); i++) {
		hashkey = HashString(list_company[i].name);
		key = hashkey % 2000;
		if (table[key].name == "") {
			table[key] = { list_company[i].name, list_company[i].profit_tax, list_company[i].address };
		}
		else {
			int temp = key + 1;
			while (table[temp].name != "") {
				temp = (temp + 1) % 2000;
			}
			table[temp] = { list_company[i].name, list_company[i].profit_tax, list_company[i].address };
		}
	}
	return table;
}

void Insert(Company* hash_table, Company company) {
	int hashKey = HashString(company.name);
	int key = hashKey % 2000;
	if (hash_table[key].name == "") {
		hash_table[key] = company;
	}
	else {
		int temp = key + 1;
		while (hash_table[temp].name != "") {
			temp = (temp + 1) % 2000;
		}
		hash_table[temp] = company;
	}
}

Company* Search(Company* hash_table, string company_name) {
	int hashKey = HashString(company_name);
	int key = hashKey % 2000;
	Company* company_info = new Company;

	if (hash_table[key].name == company_name) {
		company_info->name = hash_table[key].name;
		company_info->profit_tax = hash_table[key].profit_tax;
		company_info->address = hash_table[key].address;
		return company_info;
	}
	else {
		while (hash_table[key].name != "") {
			if (hash_table[key].name == company_name) {
				company_info->name = hash_table[key].name;
				company_info->profit_tax = hash_table[key].profit_tax;
				company_info->address = hash_table[key].address;
				return company_info;
			}
			key++;
		}
		return NULL;
	}
}


int main() {
	vector<Company> list_C = ReadCompanyList("MST.txt");
	Company* table = CreateHashTable(list_C);

	

	Company inf = { "CTY VNU ", "20127172", " 227 Đ. Nguyen Van Cu, Phuong 4, Quan 5, TP.HCM" };
	Insert(table, inf);
	cout << HashString(inf.name) % 2000 << endl;
	for (int i = 0; i < 2000; i++) {
		if (table[i].name != "") {
			cout << i << " " << table[i].name << table[i].profit_tax << table[i].address << endl;
		}
	}

	//Company* se = Search(table, inf.name);
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Examinee
{
	string id, note, city;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};

Examinee readExaminee(string line_info) {
	Examinee stu;
	ifstream fin(line_info);
	string s, temp;
	getline(fin, s);
	getline(fin, s);
	stringstream ss(s);
	getline(ss, stu.id, ',');
	getline(ss, temp, ',');
	getline(ss, temp, ',');
	if (temp == "") {
		stu.math = 0;
	}
	else {
		stu.math = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.literature = 0;
	}
	else {
		stu.literature = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.physic = 0;
	}
	else {
		stu.physic = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.chemistry = 0;
	}
	else {
		stu.chemistry = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.biology = 0;
	}
	else {
		stu.biology = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.history = 0;
	}
	else {
		stu.history = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.geography = 0;
	}
	else {
		stu.geography = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.civic_education = 0;
	}
	else {
		stu.civic_education = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.natural_science = 0;
	}
	else {
		stu.natural_science = stof(temp);
	}
	getline(ss, temp, ',');
	if (temp == "") {
		stu.social_science = 0;
	}
	else {
		stu.social_science = stof(temp);
	}
	getline(ss, temp, ',');
	stu.note = temp;
	getline(ss, temp, ',');
	stu.city = temp;
	return stu;
}

vector<Examinee> readExamineeList(string file_name) {
	vector <Examinee> stu;
	ifstream fin(file_name);
	string s, temp;
	getline(fin, s);
	int i = 0;
	while (!fin.eof()) {
		getline(fin, s);
		stringstream ss(s);
		stu.push_back(Examinee());
		getline(ss, stu[i].id, ',');
		getline(ss, temp, ',');
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].math = 0;
		}
		else {
			stu[i].math = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].literature = 0;
		}
		else {
			stu[i].literature = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].physic = 0;
		}
		else {
			stu[i].physic = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].chemistry = 0;
		}
		else {
			stu[i].chemistry = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].biology = 0;
		}
		else {
			stu[i].biology = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].history = 0;
		}
		else {
			stu[i].history = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].geography = 0;
		}
		else {
			stu[i].geography = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].civic_education = 0;
		}
		else {
			stu[i].civic_education = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].natural_science = 0;
		}
		else {
			stu[i].natural_science = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].social_science = 0;
		}
		else {
			stu[i].social_science = stof(temp);
		}
		getline(ss, temp, ',');
		if (temp == "") {
			stu[i].foreign_language = 0;
		}
		else {
			stu[i].foreign_language = stof(temp);
		}
		getline(ss, temp, ',');
		stu[i].note = temp;
		getline(ss, temp, ',');
		stu[i].city = temp;
		i++;
	}
	return stu;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name) {
	float total_score = 0.0;
	examinee_list = readExamineeList("data.txt");
	ofstream fout(out_file_name);
	for (int i = 0; i < examinee_list.size(); i++) {
		examinee_list[i].natural_science = examinee_list[i].physic + examinee_list[i].chemistry + examinee_list[i].biology;
		examinee_list[i].social_science = examinee_list[i].history + examinee_list[i].geography + examinee_list[i].civic_education;
		total_score = examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].natural_science + examinee_list[i].social_science;
		fout << examinee_list[i].id << " " << total_score << " " << examinee_list[i].natural_science << " " << examinee_list[i].social_science << endl;
	}
}

int main() {
	vector<Examinee> stu;
	stu = readExamineeList("data.txt");

	

	for (int i = 0; i < stu.size(); i++) {
		cout << stu[i].id << " " << stu[i].math <<" " << stu[i].literature << " " << stu[i].physic << " "<<
			stu[i].chemistry << " " << stu[i].biology <<" "<< stu[i].history << " " << stu[i].geography <<" "<<
			stu[i].civic_education << " " << stu[i].natural_science <<" "<<
			stu[i].social_science << " " << stu[i].foreign_language << " " << stu[i].note << " " << stu[i].city << endl;
	}

	return 0;
}
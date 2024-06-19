#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstring>
void split(std::string str, int* ans) {
	char *token;
	const char tmp[2] = " ";
	int i = 0;
	token = strtok((char *)str.c_str(), tmp);
	while (token != NULL) {
		ans[i] = atoi(token);
		i++;
		token = strtok(NULL, tmp);
	}
}
int sp(std::string str) {
	char *token;
	const char tmp[2] = " ";
	token = strtok((char*)str.c_str(), tmp);
	for (int i = 0; i < 3; i++) {
		token = strtok(NULL, tmp);
	}
	return atoi(token);
}


int main(int argc, char* argv[]) {
	void split(std::string str, int* ans);
	int sp(std::string str);
	if(argc == 2){
		std::ifstream in(argv[1]);
		std::string q;
		int ans[4];
		int var[50] = { 0 };

		std::getline(in, q);
		double clause = sp(q);
		while (std::getline(in, q)) {
			split(q, ans);
			
			for (int i = 0; i < 3; i++) {
				if (ans[i] < 0) var[-ans[i] - 1] = 1;
				else var[ans[i] - 1] = 1;
			}
		}
		double varnum = 0;
		for (int i = 0; i < 50; i++)
			varnum += var[i];

		FILE* fp = fopen("phase.txt", "a+");
		fprintf(fp, "%.1f\n", (clause/varnum));
		}
	return 0;
}

#include<iostream>
#include<string>
#include<fstream>
#include<cstring>


int main() {
	double ans1[100] = { 0 };
	int num[100] = { 0 };
	std::ofstream out1("final1.txt");
	std::ofstream out2("final2.txt");
	std::ifstream inn("phase.txt");
	std::string p;
	const char tmp[2] = " ";
	double a, b;
	int d;
	while (std::getline(inn, p)) {
		a = atof(strtok((char*)p.c_str(), tmp));
		b = atof(strtok(NULL, tmp));
		d = (int)(atof(strtok(NULL, tmp))*10);
		ans1[d] += b, num[d] += 1;
		out2 << ((double)d) / 10 << " " << a << std::endl;
	}
	
	for (int i = 0; i < 100; i++) {
		if (num[i] != 0) {
			out1 << ((double)i) / 10 << " " << ans1[i] / num[i] << std::endl;
			
		}
	}
	out1.close();
	out2.close();
	return 0;
}

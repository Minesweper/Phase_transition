#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<ctime>

constexpr int file_num = 10000;		// CNF num (default: 10000)
constexpr int var_num = 50;		// variable num (default: 50)
constexpr int max_clause = 450;	// max clause num (modifiable)


int randint_range(int n, int m) {
	double base = ((double)rand()) / RAND_MAX;
	int res = n + (base * (double)(m - n + 1));
	return res;
}

int main() {
	int randint_range(int n, int m);
	srand(time(0));

	for (int i = 0; i < file_num; i++) {

		std::string now = "test/" + std::to_string(i + 1) + ".cnf";
		std::ofstream gefile(now, std::ios::app);

		if (gefile.is_open()) {
			int clause = randint_range(1, max_clause);
			gefile << "p cnf 50 " + std::to_string(clause) << std::endl;

			for (int j = 0; j < clause; j++) {
				int sym;

				int a1 = randint_range(1, var_num);
				std::string s1 = std::to_string(a1);
				sym = randint_range(0, 1);
				if (sym) s1 = "-" + s1;

				int a2 = a1;
				while (a2 == a1) {
					a2 = randint_range(1, var_num);
				}
				std::string s2 = std::to_string(a2);
				sym = randint_range(0, 1);
				if (sym) s2 = "-" + s2;

				int a3 = a2;
				while (a3 == a2 || a3 == a1) {
					a3 = randint_range(1, var_num);
				}
				std::string s3 = std::to_string(a3);
				sym = randint_range(0, 1);
				if (sym) s3 = "-" + s3;
				
				gefile << s1 + " " + s2 + " " + s3 + " 0" << std::endl;
			}
			gefile.close();
		}
		else {
			break;
		}
	}
	return 0;
}

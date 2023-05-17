#include"Produce.h"

//ด๚ธี
int main() {
	Produce a;
	a.print_board();
	//cout << endl;
	for (int i = 0;i < 5;i++) {
		a.generate_random_tile();
		a.print_board();
		cout << endl;
	}
}

//git test
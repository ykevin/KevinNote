
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout <<"Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grade: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << " enter all your homework grads,  follwed by end-of-file: ";

	vector<double> homework;
	double x;

	while(cin >> x)
		homework.push_back(x);
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if(size == 0) {
		cout << endl <<"you must enter your grades. " << " Please try again." << endl;
		return 1;
	}

	sort(homework.begin(), homework.end());

	vec_sz mid = size / 2;
	double median;
	median = (size % 2 == 0) ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

	streamsize prec = cout.precision();
	cout << "your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 *median << setprecision(prec) << endl;

	return 0;
}

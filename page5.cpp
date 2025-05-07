// a simple example of Eager and Lazy function call

#include <iostream>
#include <functional>

using namespace std;


// A low-level function which does a fundamental job (finding subString "Test" in str)
int f_find_substring(std::string s) {
	cout << "f_find_substring: I am called with argument: " << s << "\n";

	return s.find("Test");
}


// A high-level function which checks & processes a string by calling a low-level func 
void f_eager_evaluation(string s, int i)
{
	if (s.size() < 10)
		cout << "f_eager_evaluation: too short sentence";
	else
	{
		int pos_found{ i };
		cout << "f_eager_evaluation: The word (Test) found at " << pos_found;
	}
	cout << "\n\n";
}


// A high-level function which checks & processes a string by calling a low-level func 
void f_lazy_evaluation(string s, function<int(string)> f)
{
	if (s.size() < 10)
		cout << "f_lazy_evaluation: too short sentence";
	else
	{
		int pos_found{ f(s) };
		cout << "f_lazy_evaluation: The word (Test) found at " << pos_found;
	}
	cout << "\n\n";
}


// The main function
int main() {
	std::string s1{ "a Test in a longer sentence" }, s2{ "a Test" };

	std::function<int(std::string)> f_wrapper = f_find_substring;


	cout << "\n\n====== Eager Evaluation =============\n";
	f_eager_evaluation(s1, f_wrapper(s1));
	f_eager_evaluation(s2, f_wrapper(s2));


	cout << "\n\n====== Lazy Evaluation =============\n";
	f_lazy_evaluation(s1, f_wrapper);
	f_lazy_evaluation(s2, f_wrapper);
}

#include <iostream>
#include <list>
#include <string>
using namespace std;


// zadatak 3 funkcija void pomnozi
void pomnozi(list<double> &l, double multiplikator) {
	for(list<double>::iterator i = l.begin(); i != l.end(); ++i) {
		*i *= multiplikator;
	}
}

// zadatak 4 funkcija bool isSorted
bool isSorted(const list<char> &L) {
	for(list<char>::const_iterator i = L.begin(); i != L.end(); ++i) {
		if(*i > *next(i) && *next(i) != '0') {
			return false;
		}
	}
	return true;
}

int main(){
	// --------------- zadatak 1 ---------------
	list<string> l1;
	string s1;
	while(1) {
		getline(cin, s1);
		if(s1 == "Kraj" || s1 == "kraj")
			break;
		l1.push_back(s1);
	}
	cout << "Zadatak 1 ispis liste: " << endl;
	for(list<string>::iterator i = l1.begin(); i != l1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl << endl;
	// --------------- zadatak 2 ---------------
	list<int> l2;
	int n;
	while(1) {
		cin >> n;
		if(n == 0) break;
		if(n % 2 == 0) l2.push_back(n);
		else l2.push_front(n);
	}
	cout << "Zadatak 2 ispis liste:" << endl;
	for(list<int>::iterator i = l2.begin(); i != l2.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl << endl;
	// --------------- zadatak 3 ---------------
	list<double> l3 = {2, 3, 3};
	cout << "Zadatak 3 ispis liste prije funckije pomnozi:" << endl;
	for(list<double>::iterator i = l3.begin(); i != l3.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	pomnozi(l3, 2);
	cout << "Zadatak 3 ispis liste nakon funkcije pomnozi:" << endl;
	for(list<double>::iterator i = l3.begin(); i != l3.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl << endl;
	// --------------- zadatak 4 ---------------
	list<char> l4 = {'a', 'b', 'c', 'a'};
	cout << "Zadatak 4 ispis liste:" << endl;
	for(list<char>::iterator i = l4.begin(); i != l4.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	string sortirano = isSorted(l4) ? "Elementi su sortirani uzlazno" : "Elementi nisu sortirani uzlazno";
	cout << sortirano << endl << endl;
	// --------------- zadatak 5 ---------------
	list<string> l5 = {"NTP", "Jupi"};
	list<string> tempL;
	cout << "Zadatak 5 ispis liste:" << endl;
	for(list<string>::iterator i = l5.begin(); i != l5.end(); ++i) {
		string temp = *i;
		for(int j = 0; j < temp.size(); j++) {
			string temp2 = "";
			temp2 += temp[j];
			tempL.push_back(temp2);
		}
		tempL.push_back(*i);
	}
	l5.swap(tempL);
	for(list<string>::iterator i = l5.begin(); i != l5.end(); ++i) {
		cout << *i << " ";
	}
	system("PAUSE");
}

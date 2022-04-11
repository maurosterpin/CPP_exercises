#include <iostream>
#include <math.h> 
using namespace std;

// zadatak 1
class IP {
    public:
    int oktet[4];
    void print();
    char className();
};

void IP::print() {
    for(int i = 0; i < 4; i++) {
        cout << oktet[i] << (i == 3 ? "" : ".");
    }
    cout << endl;
};

char IP::className() {
    if(oktet[0] > 255) return '-';
    else if(oktet[0] >= 240) return 'E';
    else if(oktet[0] >= 224) return 'D';
    else if(oktet[0] >= 192) return 'C';
    else if(oktet[0] >= 128) return 'B';
    else if(oktet[0] >= 1) return 'A';
    else return '-';
};

// zadatak 2
class Datum {
    int dan, mjesec, godina;
    void ispis();
    public:
    void postavi(int, int, int);
    void razlika(Datum, Datum);
    void starost(Datum, Datum);
};

void Datum::ispis() {
    cout << (dan < 10 ? "0" : "") << dan << "." << (mjesec < 10 ? "0" : "") << mjesec << "." << godina << "." << endl;
}

void Datum::postavi(int a, int b, int c) {
    if(a > 0 && a < 31 && b > 0 && b < 13 && c > 0 && c < 2023) {
    dan = a;
    mjesec = b;
    godina = c;
    } else {
    dan = 1;
    mjesec = 1;
    godina = 2020;
    }
    ispis();
}

void Datum::razlika(Datum a, Datum b) {
    int d1, m2, g3;
    g3 = b.godina - a.godina;
    m2 = b.mjesec - a.mjesec;
    if(m2 < 0) {
        m2+=12;
        g3--;
    }
    d1 = b.dan - a.dan;
    if (d1 < 0) {
        d1+=30;
        if(m2 != 0) {
        m2--;
        }
        }
    cout << "Razlika izmedu datuma: Dan: " << d1 << " Mjesec: " << m2 << " Godina: " << g3 << endl;
    
}

void Datum::starost(Datum a, Datum b) {
    int dani = 0;
    int leapYearCounter = 0;
    for(int i = a.godina; i < b.godina; i++) {
        dani += 365;
        leapYearCounter++;
        if(leapYearCounter >= 4) {
            leapYearCounter = 0;
            dani++;
        }
    }
    for(int i = 1; i < b.mjesec; i++) {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
        dani += 31;
        } else if (i == 4 || i == 6 || i == 9 || i == 11){
        dani += 30;
        } else if(i == 2) {
        dani += 28;
        }
    }
    dani+=b.dan;
    for(int i = 1; i < a.mjesec; i++) {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
        dani -= 31;
        } else if (i == 4 || i == 6 || i == 9 || i == 11){
        dani -= 30;
        } else if(i == 2) {
        dani -= 28;
        }
    }
    dani-=a.dan;
    cout << "Vasa trenutna starost: " << dani << " dana" << endl;
}

// zadatak 3
class Kvadratna {
    double diskriminanta();
    public:
    double a, b, c, x1, x2;
    void calculate();
};

double Kvadratna::diskriminanta() {
    return (b*b-4*a*c);
}

void Kvadratna::calculate() {
    if(diskriminanta() < 0) {
        cout << "Nema rjesenja" << endl;
        return;
    }
    x1 = (b*(-1) + sqrt(diskriminanta()))/2*a;
    x2 = (b*(-1) - sqrt(diskriminanta()))/2*a;
    cout << "x1: " << x1 << " x2: " << x2 << endl;
}



int main() {
    int izbor;
  do{
    cout << "===========================" << endl;
	  cout << "1. Prvi zadatak" << endl;
	  cout << "2. Drugi zadatak" << endl;
	  cout << "3. Treci zadatak" << endl;
	  cout << "0. Izlaz" << endl << endl;
	  cout << "Izbor: ";
	  cin >> izbor;
	  switch (izbor) {
		  case 1:  {
        // zadatak 1
        IP novo;
        for(int i = 0; i < 4; i++) {
            cout << "Upisite " << i+1 << ". oktet: ";
            cin >> novo.oktet[i];
        }
        novo.print();
        cout << "Klasa IP adrese: " << novo.className() << endl;
        break;
          }
		  case 2: {
              // zadatak 2
              Datum novo;
              Datum novo2;
              int d, m, g;
              cout << "Upisite svoj datum rodjenja: " << endl;
              cout << "Dan: ";
              cin >> d;
              cout << "Mjesec: ";
              cin >> m;
              cout << "Godina: ";
              cin >> g;
              novo.postavi(d, m, g);
              cout << "Upisite danasnji datum: " << endl;
              cout << "Dan: ";
              cin >> d;
              cout << "Mjesec: ";
              cin >> m;
              cout << "Godina: ";
              cin >> g;
              novo2.postavi(d, m, g);
              novo.razlika(novo, novo2);
              novo.starost(novo, novo2);
            
      break;
      }
	  case 3: {
        // zadatak 3
        Kvadratna novo;
        cout << "Upisite a: ";
        cin >> novo.a;
        cout << "Upisite b: ";
        cin >> novo.b;
        cout << "Upisite c: ";
        cin >> novo.c;
        novo.calculate();
      break;
      }
    }

	} while (izbor != 0);

    return 0;
}

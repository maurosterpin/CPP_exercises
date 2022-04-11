// MD5:YrI6S5fHZ0EQr8cwza7J0A==// Verifikator 5.05// Program:NTP zadatak 6// Poèetno vrijeme: 12:27 (internetsko) Završno vrijeme: 14:57 Preostalo: 127 *// Opis zadatka:NTP zadatak 6// Autor:Mauro Sterpin// Poèetno vrijeme:8.4.2022. 12:27:50// Završno vrijeme:8.4.2022. 12:49:57// Identifikatori:Node,key,*prev,*next,main,float,val,const,Krug,*radius,radius,0.0,r,get,set,print,a,b,c,k1,k2,k3// IP:fe80::f96e:343c:ee94:7c02%5 ( 15 )// #:#include <iostream>,// Uspješnih/neuspješnih prevoðenja:14/11#include <iostream>
using namespace std;

// zadatak 1
class Node {
	public:
	float key;
	Node *prev;
	Node *next;
	Node() : key(0.0), prev(NULL), next(NULL) {};
	~Node() {
		delete prev;
		delete next;
	}
	Node(float val, Node *left, Node *right) : key(val), prev(left), next(right) {};
	Node(const Node& x) {
		key = x.key;
		prev = x.prev;
		next = x.next;
	};
};

// zadatak 2
class Krug {
	float *radius;
	public:
	Krug() : radius(new float(0.0)) {};
	Krug(float r) : radius(new float(r)) {};
	Krug(const Krug& k) : radius(k.radius) {};
	~Krug() {
		delete radius;
	};
	float get() { return *radius; };
	void set(float r) { delete radius; radius = new float(r); };
	void print() { cout << "Radius: " << *radius << endl; }	
};

// poèetak izvoðenja programa
int main(){
	// zadatak 1
	Node a;
	Node b(2.2, &a, NULL);
	a.next = &b;
	Node c(b);
	c.next = &a;
	c.prev = &b;
	b.next = &c;
	a.prev = &c;
	c.key = 3.5;
	cout << "key: " << a.next->key << ", prev: " << a.next->prev->key << ", next: " << a.next->next->key << endl;
	cout << "key: " << b.next->key << ", prev: " << b.next->prev->key << ", next: " << b.next->next->key << endl;
	cout << "key: " << c.next->key << ", prev: " << c.next->prev->key << ", next: " << c.next->next->key << endl;

	// zadatak 2
	Krug k1;
	Krug k2(15.0);
	Krug k3(k2);
	
	k1.set(13.2);
	cout << "Get: " << k1.get() << endl;
	k1.print();
	k2.print();
	k3.print();
		
	system("PAUSE");
}

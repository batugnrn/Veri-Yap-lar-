#ifndef stringKuyruk_hpp
#define stringKuyruk_hpp


#include <iostream>
#include "stringDugum.hpp"
using namespace std;



class stringKuyruk
{

public:

	stringDugum* on;
	stringDugum* arka;
	int uzunluk;

	stringKuyruk();

	~stringKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();

	string ilkElemaniGetir() const;

	string getir(int say);

	void kuyrukEkle(const string veri);

	void kuyrukCikar();
};




#endif
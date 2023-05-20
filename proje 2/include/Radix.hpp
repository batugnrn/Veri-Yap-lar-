#ifndef Radix_hpp
#define Radix_hpp

#include <iostream>
#include "intKuyruk.hpp"
using namespace std;


class Radix
{
private:
	intKuyruk** kuyruklar;
	int* sayilar;
	int  sayiAdedi;
public:
	Radix(int* sayilar, int adet);

	~Radix();

	int* sirala();


	int maxBasamakSayisiGetir();

	int basamakSayisiGetir(int sayi);

	void kuyrukUzunluklariGetir(int* uzunluklar);

};





#endif
#ifndef intYildizKuyruk_hpp
#define intYildizKuyruk_hpp


#include <istream>
#include <ostream> 
#include "intYildizDugum.hpp"
using namespace std;


class intYildizKuyruk
{
public:
	intYildizDugum* on;
	intYildizDugum* arka;
	int uzunluk;


	intYildizKuyruk();

	~intYildizKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();


	int* getir(int say);


	void kuyrukEkle(int* veri);


	void kuyrukCikar();

	void yazdir(int say);
};










#endif
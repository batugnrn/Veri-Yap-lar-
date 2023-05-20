#ifndef stringKuyrukYildizKuyruk_hpp
#define stringKuyrukYildizKuyruk_hpp

#include "stringKuyrukYildizDugum.hpp"
using namespace std;

class stringKuyrukYildizKuyruk
{
public:
	stringKuyrukYildizDugum* on;
	stringKuyrukYildizDugum* arka;
	int uzunluk;

	stringKuyrukYildizKuyruk();

	~stringKuyrukYildizKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();

	stringKuyruk* ilkElemaniGetir() const;

	stringKuyruk* getir(int say);


	void kuyrukEkle(stringKuyruk* veri);


	void kuyrukCikar();

};








#endif
#ifndef hucre_hpp
#define hucre_hpp


#include <iostream>
#include "intKuyruk.hpp"
#include "Radix.hpp"
using namespace std;


class hucre
{
public:

	void DNAdegistir(intKuyruk* k, int say);
	~hucre();
	intKuyruk* MutasyonluAgac();
	intKuyruk* k2 = new intKuyruk();


private:
	int* sirali;
	int orta = 0;
	intKuyruk* ortaKuyruk = new intKuyruk();
};






#endif
#ifndef Doku_hpp
#define Doku_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "Radix.hpp"
#include "intKuyruk.hpp"
#include "kuyrukKuyruk.hpp"
#include "intYildizKuyruk.hpp"
#include "intKuyrukYildizKuyruk.hpp"
using namespace std;

class Doku
{
private:
	ifstream fileread;
	string okunan;
	int sayac = 0;
	int orta = 0;
	int satirSayac = 0;

	intKuyrukYildizKuyruk* dokularKuyrugu = new intKuyrukYildizKuyruk();

public:
	~Doku();

	intKuyrukYildizKuyruk* dokuOlustur();

	intKuyrukYildizKuyruk* dokularKuyruguDondur();
};







#endif
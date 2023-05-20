#ifndef sistem_hpp
#define sistem_hpp


#include <iostream>
#include "stringKuyruk.hpp"
#include "stringKuyrukYildizKuyruk.hpp"

class sistem
{
private:
	stringKuyrukYildizKuyruk* sistemkuyruk = new stringKuyrukYildizKuyruk();
public:
	stringKuyrukYildizKuyruk* sistemOlustur(stringKuyruk* sistemKuyruk);

	int uzunluk();

	~sistem();



};







#endif
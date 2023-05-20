#ifndef kuyrukYildizDugum_hpp
#define kuyrukYildizDugum_hpp


#include <iostream>
#include "intYildizKuyruk.hpp"
using namespace std;


class kuyrukYildizDugum
{
public:

	intYildizKuyruk* veri;
	kuyrukYildizDugum* sonraki;

	kuyrukYildizDugum(intYildizKuyruk* veri);

};







#endif
#ifndef intKuyrukYildizDugum_hpp
#define intKuyrukYildizDugum_hpp


#include <iostream>
#include "intKuyruk.hpp"

class intKuyrukYildizDugum
{
public:
	intKuyruk* veri;
	intKuyrukYildizDugum* sonraki;

	intKuyrukYildizDugum(intKuyruk* veri);
};







#endif
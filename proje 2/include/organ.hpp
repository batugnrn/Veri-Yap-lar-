#ifndef organ_hpp
#define organ_hpp
#include <iomanip>
#include "stringKuyruk.hpp"
#include "intKuyruk.hpp"
#include "intYildizKuyruk.hpp"
#include "intKuyrukYildizKuyruk.hpp"
#include "AgacKuyruk.hpp"
#include "hucre.hpp"
using namespace std;


class organ
{
private:
	stringKuyruk* mutasyonluOrganKuyrugu = new stringKuyruk();
	stringKuyruk* organKuyrugu = new stringKuyruk();
	AgacKuyruk* agacKuyrugu = new AgacKuyruk();
public:
	~organ();
	stringKuyruk* organOlustur(intKuyrukYildizKuyruk* dokularKuyruk);
	stringKuyruk* mutasyon(intKuyrukYildizKuyruk* dokularKuyruk);
};





#endif
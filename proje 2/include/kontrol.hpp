#ifndef kontrol_hpp
#define kontrol_hpp
#include <iostream>
#include <iomanip>
#include "Doku.hpp"
#include "organ.hpp"
#include "sistem.hpp"
#include "organizma.hpp"

using namespace std;



class kontrol
{
private:
    Doku* dk = new Doku();
	organ* org = new organ();
	sistem* sys = new sistem();
	sistem* sys2 = new sistem();
	organizma* orgz = new organizma();
public:
    void normalOrganizmaYazdir();

	void mutasyonluOrganizmaYazdir();
};














#endif
/*****************************************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** VERİ YAPILARI DERSİ
** 2022-2023 GÜZ DÖNEMİ
**
**
** ÖDEV ..................: 1. ÖDEV
** ÖĞRENCİ ADI............: BAHRİ BATUHAN GÜNEREN
** ÖĞRENCİ NUMARASI.......: G201210059
** DERSİN ALINDIĞI GRUP...: 2.ÖĞRETİM C GRUBU
****************************************************************************************************/
#ifndef dosya_hpp
#define dosya_hpp
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class dosya
{
private:
    int sayi;
	int satirSayac = 0;           // satir sayisını tutuyor
	int satirElemanSayac = 0;
	string okunan;
	string str;
	size_t pos = -1;
	double ortalama = 0;
	double toplam = 0;
	int satirSayac1 = 0;
public:
    int satirSayisi();
    int satirElemanSayisi(int sira);
    int tekElemanGetir(int satir, int sayacc);
};









#endif
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
#ifndef yoneticiDugum_hpp
#define yoneticiDugum_hpp
#include "satirListe.hpp"

using namespace std;


class yoneticiDugum
{
private:
    
public:

    satirListe* veri;
	yoneticiDugum* on;
	yoneticiDugum* arka;

    yoneticiDugum(satirListe* veri);
    
};






#endif
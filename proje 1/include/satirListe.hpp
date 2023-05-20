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
#ifndef satirListe_hpp
#define satirListe_hpp
#include "satirDugum.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

class satirListe
{
private:
  
public:
    satirDugum* ilk; 


    satirListe();
    ~satirListe();
    void satirListeCikar();
    void satirListeCikar(int sira);
    satirDugum* satirDugumGetir(int sira);
    void satirListeEkle(int sayi);
    void satirListeYazdir(int sira);
    void satirListeSilmeYazdir(int sira, int hangisi);
    int satirDugumSayGetir();
    double ortalamaHesapla();

};









#endif
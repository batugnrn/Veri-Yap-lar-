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
#ifndef ekran_hpp
#define ekran_hpp
#include "yoneticiListe.hpp"
#include "yoneticiDugum.hpp"
#include <iostream>

using namespace std;


class ekran
{
private:
   
public:
    void cizgiCizdir(int adet);
    void yoneticiYaz(yoneticiListe* list, int sira);
    void satirYaz(int sira, yoneticiListe* list);
    void silincekSatirOkuYazdir(int sira, yoneticiListe* list, int hangisi);


};








#endif
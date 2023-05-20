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
#ifndef yoneticiListe_hpp
#define yoneticiListe_hpp
#include "yoneticiDugum.hpp"
using namespace std;



class yoneticiListe
{
private:

public:
    yoneticiDugum* ilk;


    yoneticiListe();
    ~yoneticiListe();
    void yoneticiEkle(satirListe* veri);
    void yoneticiEkle(satirListe* veri, int sira);
    yoneticiDugum* dugumGetir(int sira);
    void yoneticiCikar();
    void yoneticiCikar(int sira);
    int yoneticiDugumSayGetir();
    int yoneticiHangiDugum(yoneticiDugum* dugum);
    double yoneticiOrt(int sira);

};





#endif
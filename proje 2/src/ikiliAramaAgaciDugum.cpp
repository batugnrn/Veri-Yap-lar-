/*****************************************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** VERİ YAPILARI DERSİ
** 2022-2023 GÜZ DÖNEMİ
**
**
** ÖDEV ..................: 2. ÖDEV
** ÖĞRENCİ ADI............: BAHRİ BATUHAN GÜNEREN
** ÖĞRENCİ NUMARASI.......: G201210059
** MAİL ..................: bahri.guneren@ogr.sakarya.edu.tr
** DERSİN ALINDIĞI GRUP...: 2.ÖĞRETİM C GRUBU
**
**
** DOSYA ACIKLAMSI........: Ikili arama agaci icin gerkli dugum sinifi
****************************************************************************************************/
#include "ikiliAramaAgaciDugum.hpp"


ikiliAramaAgaciDugum::ikiliAramaAgaciDugum(int veri)
{
	this->veri = veri;
	sol = sag = 0;
}

ikiliAramaAgaciDugum::ikiliAramaAgaciDugum(int veri, intKuyruk* doku)
{
	this->doku = doku;
	this->veri = veri;
	sol = sag = 0;
}
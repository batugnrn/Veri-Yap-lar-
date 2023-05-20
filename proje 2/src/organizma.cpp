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
** DOSYA ACIKLAMSI........: Organizmanın olusturuldugu yer
****************************************************************************************************/
#include "organizma.hpp"


void organizma::organizmOlustur(stringKuyrukYildizKuyruk* veri)
{
	int a = veri->uzunluk;
	for (int i = 0; i < a; i++)     
	{
		for (int j = 0; j < 100; j++)
		{
			cout << veri->getir(i)->getir(j);           
		}
		cout << endl;
	}
}

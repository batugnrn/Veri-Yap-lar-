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
** DOSYA ACIKLAMSI........: Her 100 organda bir sistemin olustugu sinif
****************************************************************************************************/
#include "sistem.hpp"


stringKuyrukYildizKuyruk* sistem::sistemOlustur(stringKuyruk* organKuyruk)
{

	int a = organKuyruk->elemanSayisi() / 100;
	for (int i = 0; i < a; i++)
	{
		stringKuyruk* k = new stringKuyruk();
		for (int j = 0; j < 100; j++)
		{
			k->kuyrukEkle(organKuyruk->getir(j));
		}
		sistemkuyruk->kuyrukEkle(k);
		for (int p = 0; p < 100; p++)
		{
			organKuyruk->kuyrukCikar();
		}
	}
	return sistemkuyruk;

}

int sistem::uzunluk()
{
	int a = sistemkuyruk->uzunluk;    
	return a;
}


sistem::~sistem()
{
	delete sistemkuyruk;
}
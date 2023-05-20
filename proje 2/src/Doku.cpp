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
** DOSYA ACIKLAMSI........: Text dosyasından dokuların sıralanıp kuyruklara eklendigi dosya
****************************************************************************************************/
#include "Doku.hpp"


Doku::~Doku()
{
	delete dokularKuyrugu;
}

intKuyrukYildizKuyruk* Doku::dokuOlustur()
{
	fileread.open("Veri.txt", ios::in);
	while (getline(fileread, okunan))
	{
		satirSayac++;
		stringstream ss(okunan);
		intKuyruk k;

		while (ss)
		{
			int deger = 0;
			if (ss.eof())
			{
				break;
			}
			ss >> deger;
			k.kuyrukEkle(deger);
			sayac++;

		}
		int* dinamik = new int[sayac];

		for (int i = 0; i < sayac; i++)
		{
			dinamik[i] = k.getir(i);
		}

		Radix* r = new Radix(dinamik, sayac);

		int* sirali = r->sirala();
		delete[] dinamik;

		intKuyruk* kk = new intKuyruk();      ///text dosyasindaki her satiri bir kuyruga alama islemi

		for (int i = 0; i < sayac; i++) {
			kk->kuyrukEkle(sirali[i]);
		}
		
		dokularKuyrugu->kuyrukEkle(kk);   // her satirda olusa kuyrugu tutan kuyruga ekleme islemi
		
		delete r;

		sayac = 0;
	}

	fileread.close();
	return dokularKuyrugu;

}

intKuyrukYildizKuyruk* Doku::dokularKuyruguDondur()
{
	return dokularKuyrugu;
}

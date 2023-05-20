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
** DOSYA ACIKLAMSI........: Normal organizma mi yoksa mutasyonlu organizmayı olusturmayi kontrol eden kontrol sinifi
****************************************************************************************************/
#include "kontrol.hpp"



void kontrol::normalOrganizmaYazdir()
{
	cout<<endl<<endl;
	cout << setw(25) << "Text dosyasi okunup gerekli yapilar olusturuluyor. Lutfen bekleyin!!" << endl;
	orgz->organizmOlustur(sys->sistemOlustur(org->organOlustur(dk->dokuOlustur())));

	delete sys;
}


void kontrol::mutasyonluOrganizmaYazdir()
{
	system("cls");
	cout << setw(40) << "Mutasyonlu Organizma" << endl;
	orgz->organizmOlustur(sys2->sistemOlustur(org->mutasyon(dk->dokularKuyruguDondur())));


	delete org;
	delete dk;

	delete orgz;
	delete sys2;
}

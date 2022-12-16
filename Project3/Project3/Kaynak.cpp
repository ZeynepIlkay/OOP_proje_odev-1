#include <iostream>
#include <locale.h> //t�rk�e karakter kullanmak i�in ekledik.
#include "kisi.h"
#include "yonetici.h"
#include "kullanici.h"
#include <string>
#include <fstream>
 

using namespace std;

void uyeKayd�Formu();
int yoneticiGiris();
int musteriGiris();
void printOneri();
void OneriYaz();
void sifreDegistirme();


int main()
{
	setlocale(LC_ALL, "Turkish");
	

	cout << "1. sisteme giri�" << endl << "2. �ye kayd�" << endl<< "3.��k��" << endl;

	int number;
	cin >> number;
	switch (number) {
	case 1:
		cout << "1. y�netici giri�i" << endl << "2. m��teri giri�i" << endl << "3.Geri" << endl;
		int num;
		cin >> num;
		switch (num) {
			case 1:
			{
				int n = yoneticiGiris();
				switch (n) {
				case 0:
				{
					cout << "Kullan�c� ad� veya �ifre hatal�.Tekrar Deneyiniz!" << endl;
					yoneticiGiris();
					break;
				}
				case 1:
					cout << "1.�r�n giri�i" << endl << "2.Kurye ekle" << endl << "3.�ikayet ve �neri" << endl 
						<< "4.�ndirim kodu tan�mla" << endl << "5.Faturalar� g�r�nt�le" << endl;
					int num;
					cin >> num;
					switch (num){
					case 1:
						break;
					case 2:
						break;
					case 3:
						printOneri();
						break;
					case 4:
						break;
					case 5:
						break;

					default:
						break;
					}
					break;
				default:
					break;
				}

				break;
			}
			case 2:
			{
				int n=musteriGiris();
				switch(n){
				case 0:
				{
					cout << "Kullan�c� ad� veya �ifre hatal�.Tekrar Deneyiniz!" << endl;
					musteriGiris();
					break;
				}
				case 1:
					cout << "1.K�yafet kategorisi ve �r�n se�imi" << endl << "2.Sipari� Takip" << endl << "3.�ikayet/�neri" << endl
						<< "4.�ifre de�i�tir" << endl << "5.Geri d�n" << endl;
					int num;
					cin >> num;
					switch (num){
					case 1:
						break;
					case 2:
						break;
					case 3:
						OneriYaz();
						break;
					case 4:
						sifreDegistirme();
						break;
					case 5:
						break;
					default:
						break;
					}
				default:
					break;
				}
				break;
			}
			case 3:
				exit(1);
                break; //koddan ��k�� yap�l�yor ama bir �nceki men�ye d�nmesi gerek.
			
		}
		break;
	case 2:
		uyeKayd�Formu();
		break;
	
	case 3:
		exit(1);
		break;
	default:
		break;

	}

	
	
}
void uyeKayd�Formu()
{
	char* k_ad=new char[15];
	char* k_tno=new char[15];
	char* k_nickname=new char[15];
	char* k_mail = new char[15];
	char* k_adres = new char[15];
	char* sfr = new char[15];
	char* kpn = new char[15];
	char* dt = new char[15];

	

	cout << "�ye kayd� i�in bilgileri giriniz: "<<endl;
	cout << "ad-soyad: " << endl;  cin >> k_ad;
	cout << "telno: " << endl;  cin >> k_tno;                                     //cin.getline(k_tno, sizeof(k_tno));
	cout << "kullan�c� ad�: " << endl; cin >> k_nickname;
	cout << "email: " << endl; cin >> k_mail;
	cout << "adres: " << endl; cin >> k_adres;
	cout << "�ifre: " << endl; cin >> sfr;
	cout << "do�um tarihi(gg/aa/yyyy format�nda giriniz): " << endl; cin >>dt;

  kullanici nesne(k_ad, k_tno,k_nickname,k_mail,k_adres,sfr,"0", dt);
	
   

}
int yoneticiGiris()
{
	const int LINE = 20;
	const int SIZE = 7;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\suvey\\OneDrive\\Masa�st�\\kullan�c�lar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
	}
	
	string sifre="";
	string adSoyad = "";
	int bayrak1 = 0,bayrak2=0;

	cout << "Ad-Soyad :"; cin >> adSoyad; cout << endl;
	cout << "�ifre :"; cin >> sifre; 

	for (int i = 0; i < LINE; i++)
	{
		if (sifre == veri[i][2])
		{
			bayrak1 = 1;
		
		}
		if (adSoyad == veri[i][0])
		{
			bayrak2 = 1;
		}
		if (bayrak1 != bayrak2)
		{
			break;
		}
	}
	if (bayrak1 == 1 && bayrak2==1)
	{
		cout << "Ba�ar�l� Giri�" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int musteriGiris()
{
	const int LINE = 20;
	const int SIZE = 7;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\suvey\\OneDrive\\Masa�st�\\kullan�c�lar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
	}

	string name;
	string sifre;
	int bayrak1 = 0, bayrak2 = 0;

	cout << "Kullan�c� Ad� : ";  cin >> name; cout << endl;
	cout << "�ifre : ";  cin >> sifre;

	for (int i = 0; i < LINE; i++)
	{
		if (name == veri[i][2])
		{
			bayrak1 = 1;
		}
		if (sifre == veri[i][5])
		{
			bayrak2 = 1;
		}
		if (bayrak1 != bayrak2)
		{
			break;
		}

		
	}
	if (bayrak1 ==1 && bayrak2==1)
	{
		cout << "Ba�ar�l� Giri�"<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
	

}
void printOneri()
{
	ifstream dosyaOku("C:\\Users\\suvey\\OneDrive\\Masa�st�\\�neri.txt");


	string satir = "";

	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			cout << satir << endl;
		}

		dosyaOku.close();
	
	}
	

}
void OneriYaz()
{
	string oneri = "";
	cout << "�ikayet/�neri yaz�n�z:" <<endl;
	getline(cin, oneri); //buray� atl�yor??
	cout <<"yazd���n�z �neri:" << oneri;


	ofstream DosyaYazma("C:\\Users\\suvey\\OneDrive\\Masa�st�\\�neri.txt", ios::out | ios::app);
	DosyaYazma <<oneri ;
	DosyaYazma.close();

}

void sifreDegistirme()
{
	cout << "L�tfen �ifre de�i�ikli�i i�in eposta adresinizi do�rulay�n"<<endl;
	cout << "Eposta adresinini giriniz:"<<endl;
	string eposta = "";
	cin >> eposta;
	

	const int LINE = 20;
	const int SIZE = 7;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\suvey\\OneDrive\\Masa�st�\\kullan�c�lar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
	}

	int kontrol1 = 0;
	int line=0;

	for (int i = 0; i < LINE; i++)
	{
		if (eposta == veri[i][3])
		{
			line = i;
			kontrol1 = 1;
		}
	}
	if (kontrol1 != 1)
	{
		cout << "Epostan�z� kontrol ediniz!" << endl;
	}

	

	cout << "Yeni �ifrenizi giriniz: "<<endl;
	string yeniSifre = "";
	cin >> yeniSifre;
	
	veri[line][5] = yeniSifre;

}










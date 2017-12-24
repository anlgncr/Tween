#ifndef Tween_h
#define Tween_h
#include "arduino.h"

#define DOGRUSAL 0
#define YUMUSAK_GIRIS 1
#define YUMUSAK_CIKIS 2
#define YUMUSAK_GIRIS_SEKME 3
#define YUMUSAK_CIKIS_SEKME 4
#define YUMUSAK_GIRIS_GERI 5
#define YUMUSAK_CIKIS_GERI 6
#define YUMUSAK_GIRIS_ELASTIK 7 
#define YUMUSAK_CIKIS_ELASTIK 8
#define YUMUSAK_GIRIS_CIKIS 9
#define YUMUSAK_CIKIS_GIRIS 10
#define YUMUSAK_CIKIS_GIRIS_ELASTIK 11 
#define YUMUSAK_GIRIS_CIKIS_ELASTIK 12


class Tween{
	public:
		Tween();
		void baslat(int *, int, int, int, char fonk);
		void guncelle();
		bool bittiMi();
			
	private:
		void zamanGuncelle(int);
		typedef float (Tween::*gecisFonk)(float);
		gecisFonk gFonk;
		int gecenZaman;
		int toplamZaman;
		bool bitti;
		int sonDeger;
		int ilkDeger;
		int* degisken;
		int oncekiZaman = 0;
		int zaman = 0;
		
		float yumusakBirlesim(gecisFonk, gecisFonk, float);
		float yumusakCikisGirisElastik(float);
		float yumusakGirisCikisElastik(float);
		float yumusakGirisSekme(float);
		float yumusakCikisGiris(float);
		float yumusakGirisCikis(float);
		float yumusakCikisElastik(float oran);
		float yumusakCikisGeri(float);
		float yumusakGirisGeri(float);
		float yumusakGiris(float);
		float yumusakCikis(float);
		float yumusakGirisElastik(float);
		float yumusakCikisSekme(float);
		float dogrusal(float);
	
		const gecisFonk fonksiyonlar[13] = {
			&Tween::dogrusal
			,&Tween::yumusakGiris
			,&Tween::yumusakCikis
			,&Tween::yumusakGirisSekme
			,&Tween::yumusakCikisSekme
			,&Tween::yumusakGirisGeri
			,&Tween::yumusakCikisGeri
			,&Tween::yumusakGirisElastik
			,&Tween::yumusakCikisElastik
			,&Tween::yumusakGirisCikis
			,&Tween::yumusakCikisGiris
			,&Tween::yumusakGirisCikisElastik
			,&Tween::yumusakCikisGirisElastik
		};
};

#endif
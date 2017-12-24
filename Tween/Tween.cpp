#include "Tween.h"

Tween::Tween(){
	bitti = true;
}

void Tween::baslat(int * _degisken, int _ilkDeger, int _sonDeger, int _toplamZaman, char fonk){
	degisken = _degisken;
	ilkDeger = _ilkDeger;
	sonDeger = _sonDeger;
	toplamZaman = _toplamZaman;
	gecenZaman = 0;
	bitti = false;
	oncekiZaman = (int)millis();
	this->gFonk = fonksiyonlar[fonk];		
}

void Tween::guncelle(){
	zaman = (int)(millis() - oncekiZaman);
	zamanGuncelle(zaman);
    oncekiZaman = (int)millis();
}

void Tween::zamanGuncelle(int _zaman){
	if(bitti)
		return;
	
	gecenZaman += _zaman;
	
	if(gecenZaman <= 0)
		return;
	else if(gecenZaman > toplamZaman)
		gecenZaman = toplamZaman; 
  
	float oran = (float)gecenZaman / (float)toplamZaman;
	*degisken = ilkDeger + ((sonDeger - ilkDeger) * (this->*gFonk)(oran));
  
	if(gecenZaman == toplamZaman)
		bitti = true;
}

bool Tween::bittiMi(){
	return bitti;
}

float Tween::dogrusal(float oran){
	return oran;
}

float Tween::yumusakGiris(float oran){
  return oran * oran * oran;
}

float Tween::yumusakCikis(float oran){
  float tersOran = oran - 1;
  return tersOran * tersOran * tersOran +1; 
}

float Tween::yumusakGirisElastik(float oran){
	if(oran == 1 || oran ==0)
		return oran;
	else{
		float p = 0.3;
		float s = p/4.0;
		float tersOran = oran - 1;
		return -1.0 * pow(2.0, 10.0 * tersOran) * sin((tersOran-s)*(2.0* 3.14)/p);
	}
}

float Tween::yumusakCikisSekme(float oran){
	float s= 7.5625;
	float p= 2.75;
	float l;
	if (oran < (1.0/p)){
		l = s * pow(oran, 2);
	}
	else{
		if (oran < (2.0/p)){
			oran -= 1.5/p;
			l = s * pow(oran, 2) + 0.75;
		}
		else{
			if (oran < 2.5/p){
				oran -= 2.25/p;
				l = s * pow(oran, 2) + 0.9375;
			}
			else{
				oran -= 2.625/p;
				l =  s * pow(oran, 2) + 0.984375;
			}
		}
	}
	return l;
}

float Tween::yumusakGirisGeri(float oran){
	float s = 1.70158;
	return pow(oran, 2) * ((s + 1.0)*oran - s);
}
		
float Tween::yumusakCikisGeri(float oran){
	float tersOran = oran - 1.0;            
	float s = 1.70158;
	return pow(tersOran, 2) * ((s + 1.0)*tersOran + s) + 1.0;
}

float Tween::yumusakCikisElastik(float oran){
	if (oran == 0 || oran == 1) return oran;
	else{
		float p = 0.3;
		float s = p/4.0;                
		return pow(2.0, -10.0*oran) * sin((oran-s)*(2.0*3.14)/p) + 1;                
	}            
}      	

float Tween::yumusakGirisCikis(float oran){
	return yumusakBirlesim(&Tween::yumusakGiris, &Tween::yumusakCikis, oran);
} 

float Tween::yumusakCikisGiris(float oran){
	return yumusakBirlesim(&Tween::yumusakCikis, &Tween::yumusakGiris, oran);
} 

float Tween::yumusakGirisSekme(float oran){
	return 1.0 - yumusakCikisSekme(1.0 - oran);
}

float Tween::yumusakGirisCikisElastik(float oran){
	return yumusakBirlesim(&Tween::yumusakGirisElastik, &Tween::yumusakCikisElastik, oran);
}   

float Tween::yumusakCikisGirisElastik(float oran){
	return yumusakBirlesim(&Tween::yumusakCikisElastik, &Tween::yumusakGirisElastik, oran);
}

float Tween::yumusakBirlesim(gecisFonk baslangicFonk, gecisFonk bitisFonk, float oran){
	if (oran < 0.5) {
		return 0.5 * (this->*baslangicFonk)(oran * 2.0);
	}
	else {
		return 0.5 * (this->*bitisFonk)((oran - 0.5) * 2.0) + 0.5;
	}	
}





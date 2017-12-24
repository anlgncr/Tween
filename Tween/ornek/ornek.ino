/*Bu sketch Anıl tarafından 24.12.2017 tarihinde yazıldı.*/
#include "Tween.h"
#define TOPLAM_ZAMAN 1000 //ms

//Animasyon türleri için Tween.h dosyasına bakınız
Tween animasyon;

int degisken = 0;
void setup() {
  Serial.begin(9600); // Seri portu başlat
  //degisken adresi, baslangıç değeri, bitiş değeri, toplam zaman, animasyon türü
  animasyon.baslat(&degisken, degisken, degisken+100, TOPLAM_ZAMAN, YUMUSAK_GIRIS_CIKIS);  
}

void loop() {
  if(!animasyon.bittiMi()){ // animasyon bitmediyse güncellemeye devam et
    animasyon.guncelle(); // animasyonun çalışabilmesi için güncellennesi gerekiyor
    Serial.println(degisken); //Seri porta değişkenin değerini yaz
  }
}

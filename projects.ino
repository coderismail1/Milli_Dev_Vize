const int fanA1  = 6;  // L298N'in IN1 Girişi
const int fanA2  = 7; // L298N'in IN2 Girişi

int Relay1 = 8 ;
int led = 9 ;
int led2 = 10 ; 
int led3 = 11 ; 
int led4 = 12 ;

int state;  //Bluetooth verisi için değişken  
int vSpeed = 255; // Maximum  Alınacak  Hız Değeri
int i=0; // Döngü için atanan bir değer 


void setup() {
  //ÇIKIŞ  VE GİRİŞ PİNLERİNİ BELİRLEDİK
  pinMode(fanA1, OUTPUT);
  pinMode(fanA1, OUTPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);


}

void loop() {
 
  if (digitalRead(state)== LOW) {state='S';} //Bağlantımız koptuğunda devre Pasif duruma düşüp devremizi kapatması için komut verdik .

  if(Serial.available() > 0){     
      state = Serial.read();  // Gelen verileri state değişkenine atıyoruz .
  }

  // UYGULAMADAN AYARLANABİLEN 4 KADEMELİ  HIZ SEVİYESİNİ GİRİYORUZ:
  
  // 0 verisi aldığımızda Tüm sistemler Devre Dışı Sadece Kırmızı Led İle devrenin kapalı olduğunu anlıyoruz .
  if (state == '0'){  
    analogWrite(fanA1,0);
    analogWrite(fanA2,0);
    digitalWrite(Relay1 ,LOW);
    digitalWrite(led ,HIGH);
    digitalWrite(led2 ,LOW);
    digitalWrite(led3 ,LOW);
    digitalWrite(led4 ,LOW);
    
  }
 // 1 kademesinde ise fanımızı 1 kademeye ayarladağımız devire göre çalışıyor ve led2'miz devreye giriyor .
  if (state == '1'){
    analogWrite(fanA1,85);
    analogWrite(fanA2,0);
    digitalWrite(Relay1 ,LOW);
    digitalWrite(led ,LOW);
    digitalWrite(led2 ,HIGH);
    digitalWrite(led3 ,LOW);
    digitalWrite(led4 ,LOW);
  }
   // 2 kademesinde ise fanımızı 2. kademeye ayarladağımız devire göre çalışıyor ve led3'miz devreye giriyor .
  if (state == '2'){
    analogWrite(fanA1,115);
    analogWrite(fanA2,0);
    digitalWrite(Relay1 ,LOW);
    digitalWrite(led ,LOW);
    digitalWrite(led2 ,LOW);
    digitalWrite(led3 ,HIGH);
    digitalWrite(led4 ,LOW);

  }

   // 3 kademesinde ise fanımızı 3. kademeye ayarladağımız devire göre çalışıyor ve led4'miz devreye giriyor .
   
 if (state == '3'){
    analogWrite(fanA1,225);
    analogWrite(fanA2,0);
    digitalWrite(Relay1 ,LOW);
    digitalWrite(led ,LOW);
    digitalWrite(led2 ,LOW);
    digitalWrite(led3 ,LOW);
    digitalWrite(led4 ,HIGH);
  }

  // 4. kademesinde ise fanlarımızın yeterli soğuk havayı vermediğini anlıyoruz ve fanlarımız devre dışı bırakıp , Röle'mizden büyük fanımızı devreye aktif edip TÜM LEDLERİ uyarı olarak aktif ediyoruz .
   
   if (state == '4'){
    analogWrite(fanA1,0);
    analogWrite(fanA2,0);
    digitalWrite(Relay1 ,HIGH);
    digitalWrite(led ,HIGH);
    digitalWrite(led2 ,HIGH);
    digitalWrite(led3 ,HIGH);
    digitalWrite(led4 ,HIGH);
  }
  
}

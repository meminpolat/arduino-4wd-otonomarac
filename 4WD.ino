#include <SoftwareSerial.h>

// --- PİN AYARLARI ---
SoftwareSerial BT(11, 12);

#define ENA 9
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define ENB 3

#define TRIG_PIN A2
#define ECHO_PIN 2
#define SOL_SENSOR A3
#define SAG_SENSOR 8

// --- AYARLAR ---
int normalHiz = 255;
int donusHizi  = 255;   // 🔥 Daha sert dönüş
int engelSiniri = 15;
unsigned long beklemeSuresi = 4000;

// --- DEĞİŞKENLER ---
char gelenVeri;
bool otonomMod = true;
unsigned long sonKomutZamani = 0;

void setup() {
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SOL_SENSOR, INPUT);
  pinMode(SAG_SENSOR, INPUT);

  Serial.begin(9600);
  BT.begin(9600);

  randomSeed(analogRead(A0));
}

void loop() {

  if (BT.available()) {
    gelenVeri = BT.read();
    sonKomutZamani = millis();

    if (gelenVeri == 'F' || gelenVeri == 'B' || gelenVeri == 'L' || gelenVeri == 'R' || gelenVeri == 'S') {
      otonomMod = false;
      manuelKontrol(gelenVeri);
    } else if (gelenVeri == 'X' || gelenVeri == 'U') {
      otonomMod = true;
      dur();
    }
  }

  if (!otonomMod && millis() - sonKomutZamani > beklemeSuresi) {
    otonomMod = true;
  }

  if (otonomMod) {
    int mesafe = mesafeOlc();
    if (mesafe > 0 && mesafe < engelSiniri) {
      engeldenKac();
    } else {
      cizgiIzle();
    }
  }
}

// ---------- ENGELDEN KAÇ ----------
void engeldenKac() {
  dur(); delay(150);
  geri(); delay(250);

  int yon = random(0, 2);

  if (yon == 0) {
    solaDon(); delay(700);   // 🔥 Daha net dönüş
  } else {
    sagaDon(); delay(700);
  }

  // 🔥 15 cm ileri (ortalama)
  ileri();
  delay(350);
}

// ---------- ÇİZGİ İZLE ----------
void cizgiIzle() {
  int sol = digitalRead(SOL_SENSOR);
  int sag = digitalRead(SAG_SENSOR);

  if (sol == HIGH && sag == HIGH) {
    ileri();
  }
  else if (sol == HIGH && sag == LOW) {
    solaDon();
  }
  else if (sol == LOW && sag == HIGH) {
    sagaDon();
  }
  else {
    cizgiAra(); // 🔥 GECİKME YOK
  }
}

// ---------- HIZLI ÇİZGİ ARAMA ----------
void cizgiAra() {
  // Sağ tarafa KISA ama SERT bak
  sagaDon();
  delay(180);

  if (digitalRead(SOL_SENSOR) == HIGH || digitalRead(SAG_SENSOR) == HIGH) return;

  // Sol tarafa KISA ama SERT bak
  solaDon();
  delay(360);
}

// ---------- MANUEL ----------
void manuelKontrol(char komut) {
  switch (komut) {
    case 'F': ileri(); break;
    case 'B': geri(); break;
    case 'L': solaDon(); break;
    case 'R': sagaDon(); break;
    case 'S': dur(); break;
  }
}

// ---------- MESAFE ----------
int mesafeOlc() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long sure = pulseIn(ECHO_PIN, HIGH, 30000);
  if (sure == 0) return 0;
  return sure * 0.034 / 2;
}

// ---------- MOTOR ----------
void ileri() {
  analogWrite(ENA, normalHiz); analogWrite(ENB, normalHiz);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void geri() {
  analogWrite(ENA, normalHiz); analogWrite(ENB, normalHiz);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void sagaDon() {
  analogWrite(ENA, donusHizi); analogWrite(ENB, donusHizi);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void solaDon() {
  analogWrite(ENA, donusHizi); analogWrite(ENB, donusHizi);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void dur() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  analogWrite(ENA, 0); analogWrite(ENB, 0);
}

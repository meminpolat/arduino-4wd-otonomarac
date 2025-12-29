# 🤖 Arduino Uyumlu 4 Tekerlekli Akıllı Robot (4WD-BLE)

Bu proje, **Arduino Uno** tabanlı, **Bluetooth kontrollü**, **çizgi izleyebilen** ve **engelden kaçabilen** 4 tekerlekli akıllı bir robot araba sistemidir.  
Proje, robotik ve kodlama öğrenmek isteyen öğrenciler için **eğitici, düşük maliyetli ve çok modlu** bir platform sunar.

---

## 📌 Proje Sahibi
**Muhammed Emin Polat**  

---

## 🎯 Projenin Amacı

- Robotik ve gömülü sistemlere giriş yapmak  
- Sensör entegrasyonu ve gerçek zamanlı karar verme mekanizmalarını öğretmek  
- Tek platformda **manuel + otonom** kontrol modlarını birleştirmek  

---

## ⚙️ Temel Özellikler

- 🔹 **Bluetooth (HC-05) ile manuel kontrol**
- 🔹 **TCRT5000 sensörleri ile çizgi izleme**
- 🔹 **HC-SR04 ultrasonik sensör ile engelden kaçma**
- 🔹 **Otomatik / Manuel mod geçişi**
- 🔹 **4WD (4 motorlu) güçlü hareket sistemi**

---

## 🧠 Kontrol Modları

### 🔵 Bluetooth Manuel Kontrol
Mobil uygulama üzerinden gönderilen komutlar:
- `F` → İleri
- `B` → Geri
- `L` → Sola dön
- `R` → Sağa dön
- `S` → Dur

### 🟢 Otonom Mod
- **Çizgi izleme** (iki adet TCRT5000 sensörü)
- **Engel algılama ve kaçınma** (HC-SR04)
- Engel algılandığında:
  - Geri gider
  - Rastgele sağ/sol dönüş yapar
  - İleri devam eder

---

## 🔌 Kullanılan Donanımlar

| Bileşen | Açıklama |
|------|------|
| Arduino Uno R3 | Mikrodenetleyici |
| L298N | Motor sürücü |
| 4x DC Motor | 4WD hareket |
| HC-05 | Bluetooth modülü |
| HC-SR04 | Ultrasonik mesafe sensörü |
| TCRT5000 | Çizgi izleme sensörleri |
| 7.4V / 9V | Güç kaynağı |

---

## 🧩 Pin Bağlantıları

```
ENA  -> 9
IN1  -> 7
IN2  -> 6
IN3  -> 5
IN4  -> 4
ENB  -> 3

TRIG -> A2
ECHO -> 2

SOL Çizgi Sensörü -> A3
SAĞ Çizgi Sensörü -> 8

Bluetooth RX -> 11
Bluetooth TX -> 12
```

---

## 🛠️ Yazılım ve Algoritma

- **Arduino IDE (C/C++)**
- `if-else` karar yapıları
- Sensörlerden gelen verilerle **gerçek zamanlı kontrol**
- Gecikmesiz (delay-free) mod geçişi
- PID benzeri çizgi izleme mantığı

---

## 📂 Dosya Yapısı

```
📁 Arduino-4WD-Robot
 ├── robot_kodu.ino
 ├── README.md
```

---

## 🚀 Nasıl Çalıştırılır?

1. Arduino IDE’yi aç  
2. Kodu Arduino Uno’ya yükle  
3. Bluetooth uygulaması ile robota bağlan  
4. Manuel veya otonom modu kullan  

---

## 📈 Sonuç ve Gelecek Çalışmalar

✔ Bluetooth, çizgi izleme ve engelden kaçma başarıyla entegre edilmiştir  
✔ Robotik eğitiminde kullanılabilecek açık kaynaklı bir platform oluşturulmuştur  

🔮 Gelecek geliştirmeler:
- PID kontrol algoritmasının iyileştirilmesi
- Yapay zekâ destekli yön kararları
- Mobil uygulama geliştirme

---

## 🌍 Katkı ve Lisans

Bu proje **eğitim amaçlı ve açık kaynaklıdır**.  
Geliştirmeye ve katkıya açıktır.

---

📌 *STEM eğitimine katkı sağlamak amacıyla geliştirilmiştir.*

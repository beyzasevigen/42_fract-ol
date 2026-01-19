*This project has been created as part of the 42 curriculum by <bsevigen>.*

# Fract-ol

##  Açıklama (Description)

Fract-ol, karmaşık sayılar üzerinden oluşturulan fraktalları gerçek zamanlı olarak görüntülemeye ve etkileşimli şekilde incelemeye yarayan bir grafik programıdır.
Bu proje, 42 müfredatının bir parçasıdır ve özellikle şu konularda deneyim kazandırmayı amaçlar:

* MiniLibX ile grafiksel programlama
* Olay (event) yönetimi
* Render döngüsü mantığı
* Kompleks sayı düzlemi ile çalışma
* Fraktal formüllerinin uygulanması (escape-time algoritması)

Program, aşağıdaki iki fraktal türünün görüntülenmesine izin verir:

* **Mandelbrot Seti**
* **Julia Seti** (kullanıcı tanımlı parametrelerle)

Kullanıcı fare ve klavye yardımıyla fraktal üzerinde yakınlaşabilir, uzaklaşabilir ve dolaşabilir.

---

##  Talimatlar (Instructions)

###  Derleme

Proje dizininde **minilibx-linux** alt klasörü bulunmalıdır.
Daha sonra standart make komutu ile derleyebilirsiniz:

```sh
make
```

Başarılı derleme sonrası `fractol` isimli çalıştırılabilir dosya oluşur.

Temizleme komutları:

```sh
make clean      # .o dosyalarını siler
make fclean     # .o + fractol dosyasını siler
make re         # sıfırdan yeniden derler
```

---

###  Çalıştırma

Mandelbrot fraktalını çalıştırmak için:

```sh
./fractol mandelbrot
```

Julia setini çalıştırmak için iki parametre gereklidir (gerçek ve sanal kısım):

```sh
./fractol julia <re> <im>
```

Örnek:

```sh
./fractol julia -0.8 0.156
```

---

###  Kontroller

####  Fare

* **Scroll up** → Yakınlaştırma
* **Scroll down** → Uzaklaştırma

####  Klavye

* **ESC** → Programdan çıkış

---

##  Kaynaklar (Resources)

###  Belgeler ve Klasik Referanslar

* MiniLibX resmi dökümantasyonu
* Benoit Mandelbrot — *The Fractal Geometry of Nature*
* Wikipedia: Mandelbrot Set
* Wikipedia: Julia Set
* Escape-time algoritması üzerine matematiksel açıklamalar

---

###  Yapay Zekâ Kullanım Açıklaması

Bu projede yapay zekâ  **sadece aşağıdaki amaçlarla** kullanılmıştır:

* Kod yapısının gözden geçirilmesi
* Olası hatalar ve çökme sebeplerinin analiz edilmesi
* MiniLibX fonksiyonlarının açıklamalarının alınması
* Render sürecinde iyileştirme tavsiyeleri
* README.md dosyasının yazım desteği

---

##  Ek Notlar

* Global değişken kullanılmamaktadır.
* Kod Norminette standartlarına uygundur.
* Bellek yönetimi kontrol edilmiştir, bilinen bir leak yoktur.
* MiniLibX Linux sürümü ile çalışacak şekilde tasarlanmıştır.

---


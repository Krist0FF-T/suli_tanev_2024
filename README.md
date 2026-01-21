# Bevezetés
Ez a monorepo a 2024-25-ös tanévi (10. osztály) iskolai tananyaggal kapcsolatos munkáimat tartalmazza.

> [!NOTE]
> Feltöltés és bemutatás folyamatban...

# Fizika

## Rugószimulátor
<!-- TODO: forráskód (Python, PyGame) -->

Egy egyszerű, Euler-féle módszert alkalmazó rugószimulátor.

### Képek
<!-- TODO: szimulációk forráskódja -->

#### Különböző hosszúságú ingák lengése, lengésideje
<img width="1920" height="1080" alt="ingák lengésideje" src="https://github.com/user-attachments/assets/01830560-ed59-4a32-8ad7-cd43ba9bb9b5" />

#### Csatolt rezgés
<img width="1920" height="1080" alt="csatolt rezgés" src="https://github.com/user-attachments/assets/ab3ca60b-6851-4f28-a247-adfc716b1790" />

#### Egyéb

<img width="1920" height="1080" alt="oszlopok hajlása teher alatt" src="https://github.com/user-attachments/assets/f73379d3-4824-4830-9cd8-f009d9f460ca" />
<img width="1920" height="1080" alt="rúd hajlása" src="https://github.com/user-attachments/assets/9e3bac1b-7191-4101-805f-020ee45346dd" />


## Harmonikus rezgőmozgás animáció
<!-- TODO: statikus kép -> videó -->

[A Desmos grafikon](https://www.desmos.com/calculator/n7aijnefve)

<img width="1366" height="768" alt="harmonikus_rezgomozgas" src="https://github.com/user-attachments/assets/f05a6fc9-0d69-4a73-92d9-e5131bbb93eb" />

## Töltéses N-test szimuláció
[Forráskód](temp_fizika/fiz_szim.cpp) (C++ nyelven, az SFML multimédia könyvtár használatával)

![fiz_szim](https://github.com/user-attachments/assets/1d25ee20-fe27-41a7-9fd5-9040cb125b57)

<details>
<summary>Videók</summary>

https://github.com/user-attachments/assets/9c8cf477-03d7-4796-b6bb-0b3e20c8a4b7

https://github.com/user-attachments/assets/c0648e96-5014-4077-8eb2-e0fe35c8b88e

https://github.com/user-attachments/assets/7b2f5075-5254-4649-8959-c6deb0f0236d

</details>

## Kisebb vizualizációk

### Házi animáció
Egy kis animáció [Manim](https://github.com/ManimCommunity/manim/)-mal egy egyszerű házi feladat megoldásáról.

[Forráskód](temp_fizika/hazi_animacio.py) (Python)

https://github.com/user-attachments/assets/e1312346-0c4f-4664-9e6e-5ed8896fc496

### Elektromos mezők
<!-- TODO: forráskód (Python), magyarázat -->

Elektromos mezők ábrázolása HSV színtérrel (a színkerékhez hasonlóan).

<img width="1920" height="1080" alt="hsv elektromos tér" src="https://github.com/user-attachments/assets/6aaedbf0-38d9-48e5-9db8-749e31c13915" />

### Héjtétel
<!-- TODO: forráskód (Python) -->

Az egyik fizikaórán felmerült, a homogén gömbök esetén a középpontjuk közötti távolsággal kell számolni a gravitációs erőt, és nem láttam, hogy ha felbontjuk sok kisebb testre, akkor az erővektorok összege miért lenne azonos, mintha az egész test középpontjával számoltunk volna, így írtam egy kis programot, ami ezt ábrázolja, és kiszámolja. Utána megtaláltam a [héjtételt](https://hu.wikipedia.org/wiki/Gravit%C3%A1ci%C3%B3s_potenci%C3%A1l#G%C3%B6mbszimmetria) is, ami minden gömbileg szimmetrikus testre igazolja.

<img width="1920" height="1080" alt="hejtetel" src="https://github.com/user-attachments/assets/6189ad61-92e7-4132-b864-0c482ca6bd64" />

## Áramkörös feladatok megoldása bináris fa reprezentáció alkalmazásával
### a) Egyszerűbb
<!-- TODO: forráskód, példák -->

Ezen segédkönyvtár segítségével olyan áramkörös feladatokat lehet megoldani, amiben
- ismert az összes fogyasztó ellenállása
- legalább egy feszültség/áramerősség/teljesítmény ismert

Működése:
1. helyettesítő fogyasztók ellenállásainak kiszámolása
2. az ismert adat és megfelelő fogyasztó ellenállása alapján az összes feszültség kiszámolása
3. szükség esetén egyéb adatok kiszámolása az ismert ellenállások és kiszámolt feszültségek alapján

[aramkor_binaris_fa.pdf](https://github.com/user-attachments/files/24768709/aramkor_binaris_fa.pdf)

### b) Összetettebb
<!-- TODO: alap ötlet, eddigi forráskód (Python) -->

Ebben a változatban nem szükséges minden fogyasztó ellenállásának az ismerete.

(A fejlesztés szünetel.)

## Jövőbeli tervek:
- egy nagyobb és hatékonyabb N-test szimuláció (quadtree struktúra használatával)
- oktatóvideók készítése Manim-mal
    - (jóval előbb el kell kezdenem, hogy még releváns legyen)
    - (rengeteg idő elkészíteni)
- néhány eddig elkészített munkáim újraírásáról videók magyarázattal
    - (rugó szimulátor, feszültség- és áramerősség kiszámoló program)


# Matematika

## Egyenletábrázoló
<!-- TODO: forráskód, példák, LaTeX -->

### Működése
- minden pixelnél kiszámolja az egyenlet két oldalának $d$ különbségét $x$ és $y$ behelyettesítésével és ez alapján színezi be
- világosság (0..1) = $(1 + 10|d|)^{-2}$
    - így ha $d=0$, akkor 1 (100%), és ahogy $d$ nő, egyre sötétül
    - (általában ezt használtam, vagy ehhez hasonlót)
    - (több egyenlet ábrázolásánál kicsit bonyolultabb)

### Egy egyszerű példa
<img width="1920" height="1080" alt="eq_sin_cos" src="https://github.com/user-attachments/assets/785f7673-3fb5-4404-a307-e2a0e8a0b77a" />

- 🔴 $y = \sin(x)$
- 🔵 $y = \cos(x)$
- ⚪ $\sin(x \cdot \pi) = 0$ (függőleges)
- ⚪ $\sin(y \cdot \pi) = 0$ (vízszintes)

### Egyenletarc
<img width="3840" height="2160" alt="eq_face" src="https://github.com/user-attachments/assets/ed9a453d-895d-45d8-a1cd-2f5d3a898015" />

Ábrázolt egyenletek:
- 🔴 $|y - 0.6| = -\cos(x)$ ha $|x| < 6$
- 🔵 $\sqrt{(|x| - \pi)^2 + (y - 0.6)^2} = \sqrt{2}/2$
- 🟢 $r = 6$ vagy $r = r_h$
    - ahol $r = \sqrt{x^2 + y^2}$
    - $r_h = 6 - max(0, 3+|\sin(\alpha)sin(x \cdot \pi/2 + 0.3)|)$
        - ahol $\alpha = \arctan(y/x)$
- 🟡 $\sin(4x - 4y) = 0$ ha $r_h < r < 6$
- ⚪ $\sin(x \cdot \pi) = 0$ vagy $\sin(y \cdot \pi) = 0$

# Rajz

### Fraktál görbe animáció renderelő

- [Program újraírása](https://www.youtube.com/watch?v=Pmu5Lj8mTVE) (YouTube videó)
- [Forráskód](https://github.com/Krist0FF-T/fractal_renderer) (GitHub repo)

https://github.com/user-attachments/assets/05c421a9-01ce-4efd-bacb-211b7c4cfdfa

https://github.com/user-attachments/assets/9114f4af-e42e-4d7d-a517-3f493bf7c5d5


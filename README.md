# Bevezetés
Ez a monorepo a 2024-25-ös tanévi (10. osztály) iskolai tananyaggal kapcsolatos eddigi munkámat tartalmazza (nem teljes).

> [!NOTE]
> A projektek jelenlegi prezentációja ideiglenes. Feltöltés és részletes bemutatás folyamatban.

# Fizika (WIP)
## TODO (feltölteni, bemutatni):
- töltétes N-test szimuláció (régebbi gravitációs N-test szimulációm átírása)
- hőtani kísérletes videó
- elektromos mezők ábrázolása a saját módszeremmel
- héjtétel (erről én tudom mit csináltam) (majd belerakom)
- egy egyszerű animáció Manim-mal (kezdésnek)
- vegyes kapcsolású áramköröket kiszámoló program
    - a fogyasztóknál mérhető áramerősségeket és feszültségeket számolja ki
    - bináris fát használtam az áramkörök reprezentálására


## Harmonikus rezgőmozgás (Desmos)
- [A Desmos grafikon linkje](https://www.desmos.com/calculator/n7aijnefve)
- [Magyarázóvideó](temp_fizika/hazi_animacio.mp4)

![image](temp_fizika/harmonikus_rezgomozgas.png)

## Töltéses N-test szimuláció (C++)
- [videó 1](temp_fizika/egyszeru_szimulacio.mkv)
- [videó 2 (taszítás)](temp_fizika/taszitas.mkv)
- [videó 3 (javított)](temp_fizika/fiz_szim_javitott.mkv)

TODO: chat

![Demo](temp_fizika/fiz_szim.gif)

## Kisebb vizualizációk (Python)
TODO: chat

#### Házi animáció
Egy kis animáció [Manim](https://github.com/ManimCommunity/manim/)-mal az egyik egyszerű házifeladat megoldásáról.
[Forráskód](temp_fizika/hazi_animacio.py)
[Az animáció lassabban, jobb minőséggel](temp_fizika/hazi_animacio.mp4)
![Demo](temp_fizika/hazi_animacio.gif)

#### Elektromos tér
Elektromos tér ábrázolása HSV színtérrel (mint a színkerék).
![image](temp_fizika/hsv_elektromos_ter.png)

#### Héjtétel
Egyik órán felmerült, a homogén gömbök esetén a középpontjuk közötti távolsággal kell számolni a gravitációs erőt, és nem láttam, hogy ha felbontjuk sok kisebb testre, akkor az erővektorok összege miért lenne azonos, mintha a középpontjával számoltunk volna, így írtam egy kis programot, ami ezt ábrázolja, és kiszámolja. Utána megtaláltam a [héjtételt](https://hu.wikipedia.org/wiki/Gravit%C3%A1ci%C3%B3s_potenci%C3%A1l#G%C3%B6mbszimmetria), ami minden gömbileg szimmetrikus testre igazolja.

![image](temp_fizika/hejtetel.png)

## Áramkörös feladatok megoldása bináris fa reprezentáció alkalmazásával
[a mellékelt pdf](https://github.com/Krist0FF-T/suli_tanev_2024/blob/main/temp_fizika/aramkor_binaris_fa.pdf)
TODO: chat


## Jövőbeli tervek:
- egy nagyobb és hatékonyabb N-test szimuláció (quadtree struktúra használatával)
- oktatóvideók készítése Manim-mal
    - (jóval előbb el kell kezdenem, hogy még releváns legyen)
    - (rengeteg idő elkészíteni)
- a vegyes kapcsolást kiszámoló programról egy részletes dolgozat írása
    - (bár tényleg csak egy ~100 soros programól van szó, nem annyira bonyolult)
    - (inkább egy újraírós videó, amiben magyarázok is)


# Matematika
Kicsit ironikusan talán, de az idei matematika tananyaggal kapcsolatban eddig nem sokat csináltam - csak egy egyenletábrázolót. Ezen kívül esetleg másodfokú polinomok gyökeit kiszámomló programot lehetett volna, de Python-ban 1 sorban meg lehet (meg tudom) oldani (tehát programozási szempontból tényleg elég egyszerű)

## Egyenletábrázoló
### Működése
- minden pixelnél kiszámolja az egyenlet két oldalának értékét x és y behelyettesítésével és e 2 érték különbsége alapján színezi be
- világosság (0..1) = 1 / (1 + 10d) ^ 2
    - (ahol "d" a két oldal különbségének az abszolútértéke)
    - így ha d=0, akkor 1 (100%), és ahogy d nő, egyre sötétül
    - (általában ezt használtam, vagy ehhez hasonlót)
    - (több egyenlet ábrázolásánál kicsit bonyolultabb)

### Egy egyszerű példa
<img src="https://github.com/Krist0FF-T/ttk_talentum/blob/main/images/eq_sin_cos.png"/>

- piros: y = sin(x)
- kék: y = cos(x)
- négyzetrács:
    - sin(x * pi) = 0 (függőleges)
    - sin(y * pi) = 0 (vízszintes)


# Rajz (WIP)
TODO (feltölteni):
- fraktál görbe generálási animáció renderelő
- saját egyenletábrázolóval készített önarckép
- egy látens diffúziómodell segítségével készített házi feladat

Jövőbeli tervek:
- fraktál görbe .. mögötti matekot elmagyarázó videó
    - (vagy legalább egy részletes ábra)

### Fraktál görbe animáció
...

### Egyenletarc
<img src="https://github.com/Krist0FF-T/ttk_talentum/blob/main/images/eq_face.png"/>

- ábrázolt egyenletek:
    - piros (szem körvonal):
        - |y - ysz| = -cos(x)
        - ha |x| < 6 (hogy a fejen kívül ne ismétlődjön)
    - kék (pupilla):
        - dsz^2 = dsz * sqrt(2)/2
    - zöld (fej és haj körvonal):
        - do = rf
        - do = rh
    - sárga (haj besatírozása):
        - sin((x - y) * 4) = 0
        - ha rh < do < rf
    - (+ egy halvány négyzetrács a feljebb említett módszerrel)

- ahol:
    - ysz = 0.6 (szemek magassága)
    - dsz = sqrt((|x| - pi)^2 + (y - ysz)^2) (távolság a jobb/bal szem középpontjától)
    - do = sqrt(x^2 + y^2) (távolság az origótól)
    - rf = 6 (fej sugara)
    - rh = rf - max(0, (|sin(pi/2 * x + 0.3)| + rf/2) * sin(alfa))
        - ahol alfa = arctan(y/x)


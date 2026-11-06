# Studentų rezultatų apdorojimo programa

## V0.1 – pradinė programos versija

Šioje versijoje sukurta pradinė studentų rezultatų apdorojimo programa. Padaryta galimybė įvesti studentų duomenis rankiniu būdu arba generuoti juos atsitiktinai. Programa apskaičiuoja galutinius pažymius pagal namų darbų vidurkį arba medianą ir egzamino rezultatą. Taip pat galima išvesti studentų rezultatus į ekraną.

## V0.2 – darbas su failais ir duomenų generavimas

Šioje versijoje programa papildyta galimybe nuskaityti studentų duomenis iš failų bei automatiškai generuoti skirtingo dydžio duomenų rinkinius. Studentai suskirstomi į dvi grupes pagal galutinį pažymį: „vargšiukus“ (mažiau nei 5) ir „kietiakius“ (5 ir daugiau). Rezultatai įrašomi į atskirus failus. Taip pat pridėta studentų rūšiavimo pagal vardą, pavardę arba galutinį pažymį galimybė.

## Testavimų aprašymas

V0.1 ir V0.2 versijose pagrindinis dėmesys buvo skiriamas programos funkcionalumui. Buvo tikrinama, ar teisingai įvedami ir generuojami duomenys, apskaičiuojami galutiniai pažymiai, suskirstomi studentai į grupes bei nuskaitomi ir įrašomi failai. Taip pat tikrintas rūšiavimo veikimas. Šiose versijose pagrindinis tikslas buvo užtikrinti, kad visos pagrindinės programos funkcijos veiktų teisingai.

## V0.3 – konteinerių našumo palyginimas

Šioje versijoje nagrinėjamas dviejų C++ konteinerių – `vector` ir `list` – našumas apdorojant skirtingą studentų duomenų kiekį. Pagrindinis tikslas – išsiaiškinti, kaip keičiasi programos vykdymo laikas didėjant įrašų skaičiui ir kuris konteineris efektyvesnis šioje realizacijoje.

## Testavimo aplinka

| Komponentas | Specifikacija |
|---|---|
| Procesorius | Apple M4, 10 branduolių CPU |
| Operatyvioji atmintis | 16 GB RAM |
| Duomenų kaupiklis | 512 GB SSD |

## Testavimų aprašymas

Eksperimentams naudoti ankstesnėje V0.2 versijoje sugeneruoti duomenų failai, kuriuose yra 1 tūkst., 10 tūkst., 100 tūkst., 1 mln. ir 10 mln. studentų įrašų.

Kiekvienas duomenų failas apdorotas abiem konteineriais, o kiekvienas bandymas siekiant apskaičiuoti vidurkį kartotas tris kartus. Lentelėse pateikti vidutiniai vykdymo laikai sekundėmis.

Apdorojimo metu studentai buvo suskirstyti į grupes pagal galutinį pažymį, apskaičiuotą naudojant namų darbų vidurkį, ir surūšiuoti pagal vardą.

## Testavimo rezultatai

Lentelėje pateikti 3 bandymų vidurkiai sekundėmis.

| Įrašų skaičius | Konteineris | Nuskaitymas (s) | Skirstymas (s) | Rūšiavimas (s) | Įrašymas į `vargsiukai.txt` (s) | Įrašymas į `kietiakai.txt` (s) | Bendras laikas (s) |
|---:|:---:|---:|---:|---:|---:|---:|---:|
| 1 000 | vector | 0,008490 | 0,000632 | 0,001793 | 0,000732 | 0,002531 | 0,014178 |
| 1 000 | list | 0,008362 | 0,000521 | 0,000434 | 0,000868 | 0,002547 | 0,012732 |
| 10 000 | vector | 0,043869 | 0,003143 | 0,012058 | 0,001193 | 0,001498 | 0,061760 |
| 10 000 | list | 0,043414 | 0,003033 | 0,002960 | 0,001404 | 0,001592 | 0,052403 |
| 100 000 | vector | 0,357422 | 0,027280 | 0,142485 | 0,010801 | 0,014823 | 0,552811 |
| 100 000 | list | 0,361981 | 0,027685 | 0,032997 | 0,011539 | 0,015290 | 0,449492 |
| 1 000 000 | vector | 3,488050 | 0,282784 | 1,718430 | 0,105633 | 0,151188 | 5,746090 |
| 1 000 000 | list | 3,603840 | 0,286379 | 0,390393 | 0,112800 | 0,153596 | 4,547010 |
| 10 000 000 | vector | 38,175900 | 3,121160 | 20,576100 | 1,154500 | 1,608660 | 64,636200 |
| 10 000 000 | list | 38,470000 | 3,158000 | 4,674200 | 1,246330 | 1,710130 | 49,258700 |

**Duomenų nuskaitymas.** Abiejų konteinerių nuskaitymo laikas buvo panašus. 

**Studentų skirstymas.** Skirstymo laikai taip pat buvo labai panašūs. 

**Rūšiavimas.** Ryškiausias skirtumas pastebėtas rūšiuojant studentus. Pavyzdžiui, 10 milijonų įrašų atveju `vector` rūšiavimas truko apie 20,58 sekundės, o `list` – apie 4,67 sekundės. Tai buvo pagrindinis bendro vykdymo laiko skirtumo veiksnys.

**Rezultatų įrašymas.** Abiejų konteinerių įrašymo laikai buvo artimi.

## Testavimo nuotraukos

# Vector su 1000

<img width="1676" height="852" alt="image" src="https://github.com/user-attachments/assets/d72ba79e-1764-4a6e-bcea-cc7cecd410cd" />

# List su 1000

<img width="1622" height="846" alt="image" src="https://github.com/user-attachments/assets/7ac23cc8-eb1a-4b89-827f-51b7819e1820" />

# Vector su 10000

<img width="1626" height="868" alt="image" src="https://github.com/user-attachments/assets/0b4e2e93-5153-41a4-87be-dc1292072a98" />

# List su 10000

<img width="1634" height="850" alt="image" src="https://github.com/user-attachments/assets/312485e1-e12e-4e75-b933-f9cb8105e456" />

# Vector su 100000

<img width="1710" height="860" alt="image" src="https://github.com/user-attachments/assets/432b65b0-6004-43e0-91bb-d91ebfbc0c1e" />

# List su 100000

<img width="1698" height="864" alt="image" src="https://github.com/user-attachments/assets/3cd0e5f6-0a16-445e-b3c7-9fb1e605259c" />

# Vector su 1000000

<img width="1792" height="866" alt="image" src="https://github.com/user-attachments/assets/2076b7c8-c85b-4a29-b2d7-c8e971e61dd8" />

# List su 1000000

<img width="1652" height="858" alt="image" src="https://github.com/user-attachments/assets/79fbbf06-dd4b-44aa-8e6c-bbf4f43e8250" />

# Vector su 10000000

<img width="1840" height="854" alt="image" src="https://github.com/user-attachments/assets/bfd4462b-e6b5-4504-b822-510180e8ee35" />

# List su 10000000

<img width="1756" height="854" alt="image" src="https://github.com/user-attachments/assets/8acf2867-2880-458e-943f-4f2f827e0fff" />

## Galutinės išvados

- Visais tirtais duomenų kiekiais `list` bendras vykdymo laikas buvo mažesnis.
- Didėjant įrašų skaičiui, rūšiavimo našumo skirtumas tapo ypač reikšmingas.
- Nuskaitymo ir skirstymo operacijų laikai abiem atvejais buvo panašūs.
- Apdorojant 10 milijonų studentų, `list` visą procesą atliko maždaug 15,38 sekundės greičiau nei `vector`.
  

# V1.0 – trijų studentų skirstymo strategijų palyginimas

## Tyrimo tikslas

Šioje versijoje tiriama trijų studentų skirstymo strategijų veikimo sparta naudojant du C++ konteinerius – `vector` ir `list`.

Pagrindinis tikslas – palyginti, kaip skirtingi studentų skirstymo algoritmai veikia didėjant duomenų kiekiui ir kuris strategijos bei konteinerio derinys yra efektyviausias.

## Testavimo metodika

Testavimui naudoti studentų duomenų failai, kuriuose yra 1 tūkst., 10 tūkst., 100 tūkst., 1 mln. ir 10 mln. studentų įrašų.

Kiekvienas bandymas kartotas 3 kartus. Lentelėse pateikiamas vidutinis vykdymo laikas sekundėmis.

Studentai buvo skirstomi pagal galutinį pažymį, apskaičiuotą naudojant namų darbų vidurkį. Studentai, kurių galutinis rezultatas mažesnis nei 5, priskirti vargšiukų kategorijai, o likusieji – kietiakių kategorijai.

## Skirstymo strategijos

**1 strategija – du nauji konteineriai**

Sukuriami du nauji konteineriai. Pereinant per pradinį studentų konteinerį, studentai nukopijuojami į atitinkamą naują konteinerį. Pradinis konteineris lieka nepakeistas.

**2 strategija – perkėlimas ir ištrynimas**

Studentai, kurių galutinis rezultatas mažesnis nei 5, perkeliami į vargšiukų konteinerį ir pašalinami iš pradinio konteinerio.

**3 strategija – optimizuota antroji strategija**

Naudojami efektyvesni konteineriams pritaikyti metodai: `vector` atveju – `std::partition`, o `list` atveju – `splice`.

## Testavimo rezultatai

### `std::vector`

| Studentų skaičius | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---:|---:|---:|---:|
| 1 000 | 0.000551 | 0.023564 | 0.000196 |
| 10 000 | 0.003539 | 1.663933 | 0.001520 |
| 100 000 | 0.031769 | 194.691112 | 0.015567 |
| 1 000 000 | – | – | – |
| 10 000 000 | – | – | – |

Pastaba: `vector` bandymai su 1 mln. ir 10 mln. studentų neatlikti, nes antroji strategija jau su 100 tūkst. studentų užtruko apie 194,69 sekundės.

### `std::list`

| Studentų skaičius | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---:|---:|---:|---:|
| 1 000 | 0.000454 | 0.000176 | 0.000045 |
| 10 000 | 0.002478 | 0.000921 | 0.000227 |
| 100 000 | 0.022067 | 0.008573 | 0.001993 |
| 1 000 000 | 0.221428 | 0.085427 | 0.019791 |
| 10 000 000 | 2.762302 | 0.874625 | 0.221727 |

## Rezultatų analizė

**Pirmoji strategija.** Naudojant abu konteinerius, pirmosios strategijos vykdymo laikas didėja proporcingai duomenų kiekiui. Ši strategija kiekvieną studentą nukopijuoja į vieną iš dviejų naujų konteinerių.

**Antroji strategija.** Naudojant `vector`, ši strategija pasirodė labai lėta. Taip yra todėl, kad šalinant elementus iš `vector` vidurio reikia perkelti po jų esančius elementus. Didėjant studentų skaičiui, šis procesas tampa vis brangesnis. Naudojant `list`, elementų šalinimas yra efektyvesnis, todėl vykdymo laikas gerokai mažesnis.

**Trečioji strategija.** Visuose atliktuose bandymuose ši strategija buvo greičiausia. Tai rodo, kad tinkamai parinkti konteinerių metodai leidžia gerokai sumažinti skirstymo laiką.

## Testavimo nuotraukos

# Vector su 1000

<img width="902" height="698" alt="image" src="https://github.com/user-attachments/assets/354e58e6-b54e-4dcf-b629-2c796f1fc4bb" />

# List su 1000
<img width="1006" height="690" alt="image" src="https://github.com/user-attachments/assets/00ecb7db-b7c3-483b-ada8-3799583af208" />

# Vector su 10000

<img width="926" height="694" alt="image" src="https://github.com/user-attachments/assets/eed0c4dd-9ef1-42e0-900a-82ede9550618" />

# List su 10000

<img width="928" height="710" alt="image" src="https://github.com/user-attachments/assets/35a0e30b-595f-4d6e-b914-32cb2fa1ea0a" />

# Vector su 100000

<img width="996" height="690" alt="image" src="https://github.com/user-attachments/assets/8a1080fc-3a03-4317-9346-be016126d9ac" />

# List su 100000

<img width="992" height="698" alt="image" src="https://github.com/user-attachments/assets/dcda0fcd-ab8e-4dfa-a68c-dbd912a2df58" />

# List su 1000000

<img width="980" height="682" alt="image" src="https://github.com/user-attachments/assets/bd67318d-3c64-4ca6-9e57-a5750a9d1f9f" />

# List su 10000000

<img width="996" height="680" alt="image" src="https://github.com/user-attachments/assets/67fb3172-0124-48b0-94a2-76a6dc376cb2" />

## Galutinės išvados

- Trečioji strategija buvo greičiausia tiek naudojant `vector`, tiek naudojant `list`.
- Naudojant `vector`, antroji strategija buvo ypač neefektyvi dėl elementų šalinimo iš vidurio.
- Naudojant `list`, antroji strategija veikė gerokai greičiau nei su `vector`.
- Trečioji strategija pasiekė geriausius rezultatus net ir apdorojant 10 mln. studentų naudojant `list`.
- Tyrimas parodė, kad ne tik konteinerio pasirinkimas, bet ir jo elementų apdorojimo būdas turi didelę įtaką programos veikimo spartai.

**Bendra išvada:** iš trijų tirtų strategijų trečioji yra efektyviausia pagal atliktų bandymų rezultatus.

## Programos įdiegimas ir paleidimas, naudojant VS

### Reikalavimai
- Įdiegtas C++ kompiliatorius (pvz., GCC arba Clang).
- Įdiegtas CMake.

### Kompiliavimas

1. Atsisiųsti projekto repozitoriją.
2. Atidaryti terminalą projekto aplanke.
3. Sukurti kompiliavimo aplanką ir sukonfigūruoti projektą:

```bash
cmake -S . -B build
```

4. Sukompiliuoti programą:

```bash
cmake --build build
```

### Programos paleidimas

macOS arba Linux sistemose:

```bash
./build/programa
```

Windows sistemoje vykdomojo failo vieta priklauso nuo naudojamo generatoriaus ir kompiliavimo aplinkos.

## Programos kompiliavimas ir paleidimas per terminal

Programai kompiliuoti naudojamas CMake ir C++ kompiliatorius. Kompiliavimas atliekamas Release režimu, kuris leidžia optimizuoti programos veikimą.

Terminale, atsidarius projekto aplanką, vykdomos komandos:

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release

cmake --build build-release
```

Programa paleidžiama komanda:

```bash
./build-release/programa
```

Paleidus programą galima pasirinkti `vector` arba `list` konteinerį, duomenų įvedimo būdą ir studentų skirstymo strategiją. Taip pat galima atlikti automatinį strategijų greičio testavimą.

# Studentų rezultatų apdorojimo programa

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

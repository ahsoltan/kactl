# kactl

Inne
- Cachowanie testów (`GITHUB_TOKEN`) działa?

Do naprawienia w KACTL
- Zredagować ściągi, pewnie wywalić większość
- Naprawić spacing po spisie treści i w ściągach
- Zmergować algebrę na doublach i mintach przez szablony
- Generalnie prawie wszystko modulo powinno być na mintach

Przenieść z acmlib
- EulerWalk zmieniony
- Duval

Testy do przeniesienia
```
.
├── geometry
│   └── HullDiameter.test.cpp
├── graph
│   ├── EulerWalk1.test.cpp
│   ├── EulerWalk2.test.cpp
│   └── SCC.test.cpp
├── math
│   ├── FWHT.test.cpp
└── string
    ├── Duval.test.cpp
```

Do weryfikacji w KACTL
- [x] Contest
- [ ] Mathematics
- [x] Data structures
- [ ] Numerical
- [x] Number theory
- [ ] Combinatorial
- [ ] Graph
- [ ] Geometry
- [ ] Strings
- [x] Various

Struktury danych
- [x] gp_hash_table
- [x] ordered_set (T)
- [x] Line container
- [x] Sparse table
- [x] Lazy segtree (T)
- [ ] Persistent segtree
- [x] Treap (T)
- [x] Fenwick
- [x] Fenwick 2D (T)
- [ ] Drzewo lichao (z dodawaniem i maxowaniem)
- [ ] Persistent treap
- [ ] Wavelet tree
- [x] DSU z rollbackami (T)
- [x] Mo on array, on tree (T)
- [ ] Segment tree beats

Matma
- [x] Mint
- [ ] Silnie i odwrotności
- [ ] ModMul double
- [x] Barret (T)
- [x] Pierwiastek mod
- [ ] Ile ax + by <= s
- [x] Floor sum
- [x] Mod sum (T)
- [x] Sito z bitsetem
- [ ] Sumy prefiksowe funkcji multiplykatywnej
- [ ] Zliczanie/Suma liczb pierwszych
- [x] Miller rabin
- [x] Pollard rho
- [ ] Ułamek między a i b o najmniejszym mian.
- [x] Rozszerzony euklides (T)
- [x] CRT (T)
- [x] Min mod linear, first mod linear (T*)
- [ ] Ciąg debruijna
- [ ] Nim product
- [ ] Przecięcie matroidów
- [ ] Macierz (pow, mnożenie)
- [ ] Odwrotność macierzy (eliminacja - odwr oddzielnie) (rząd - wyznacznik)
- [ ] Sherman Morrison
- [ ] Operacje na wielomianach (inv, exp, pow, log, interp, eval, chirpz)
- [x] NTT
- [x] NTT Garner
- [ ] Berlekamp-Massey
- [ ] Simpson
- [ ] Adaptive simpson
- [ ] Simplex
- [x] Binsearch na ułamkach (T)
- [x] Logarytm dyskretny
- [x] Generator mod
- [ ] Sploty AND, OR, XOR
- [ ] Splot SUBSET
- [ ] Interpolacja Lagrange'a dla jednego punktu z 0...n
- [ ] Rozwiązywanie niekwadratowego SLAE
- [ ] Mobius i Phi
- [ ] Rozwiązania równania Pella
- [ ] Sumy potęgowe
- [ ] Generowanie trójek pitagorejskich
- [x] Przedziały równości dzielenia floor/ceil (T*)
- [ ] XOR basis
- [ ] Mnożniki lagrange'a
- [ ] Wielomian charakterystyczny (black box z berlekampem)
- [ ] Kod graya i odwrotność
- [ ] Schreier-Sims

Grafy
- [ ] DSU
- [ ] Ujemny cykl
- [ ] LCA skok
- [ ] LCA rmq z kompresją
- [ ] HLD
- [ ] Centroidy
- [ ] Cykl eulera
- [ ] SCC
- [x] 2-SAT (T*)
- [ ] Mosty, cutpointy
- [x] Maksymalne kliki (T)
- [x] Dinic (T)
- [x] Gomory-Hu (T)
- [x] MCMF (T)
- [x] Hungarian
- [x] General matching blossom
- [ ] General weighted matching
- [x] Hopcroft-Karp
- [ ] Chordal Graph Recognition
- [ ] Drzewo dominatorów
- [x] Kolorowanie krawędzi w D+1 (T)
- [x] DMST
- [ ] Link-cut tree z różnymi rzeczami
- [ ] Dynamic connectivity
- [ ] Twierdzenie Koniga
- [ ] Ściany grafu planarnego
- [ ] Test planarności grafu
- [x] Największa klika
- [ ] Trójkąty
- [ ] 5-kolorowanie grafu planarnego
- [ ] Max matching Tutte
- [ ] Incremental SCC
- [ ] Reroot DP
- [x] Twierdzenie BEST
- [x] Twierdzenie Kirchoffa
- [ ] Liczba/wielomian chromatyczna
- [ ] Kolorwanie krawędzi grafu dwudzielnego w D
- [ ] K-ta najkrótsza ścieżka
- [ ] Incremental bipartite matching
- [ ] SPFA smu

Geometria
- [ ] Zdecydować postępowanie co do templatów i doubli
- [x] Punkt (T)
- [x] Angle cmp
- [x] Segment dist, line dist (T)
- [x] Przecięcie prostych/odcinków (T)
- [x] Środek ciężkości wielokąta (T)
- [x] Test czy jest w środku wielokąta (T)
- [x] Otoczka wypukła
- [ ] Suma minkowskiego
- [x] Najdalsze punkty na otoczce (T)
- [x] Styczne do otoczki (T)
- [x] Przecięcie otoczki z prostą (T)
- [ ] Przecięcie półpłaszczyzn
- [ ] Online przecięcie półpłaszczyzn
- [x] Suma wielokątów (T)
- [ ] Okrąg
- [x] Przecięcie okrąg okrąg (T)
- [ ] Pole przecięcia okrąg okrąg
- [x] Przecięcie okręgu i prostej (T)
- [x] Wspólne styczne okręgów (T)
- [x] Okrąg opisany na trójkącie (T)
- [x] Min enclosing circle (T)
- [x] Najbliższa para punktów
- [x] Delaunay triangulation (T*)
- [x] Manhattan MST
- [x] Punkt 3D (T)
- [x] Otoczka 3D O(n^2) (T)
- [ ] Otoczka 3D O(n log n)
- [ ] Pole powierzchni
- [x] Objętość (T)
- [x] Test czy punkt w otoczce (T)
- [x] Obcięcie wielokąta prostą (T)
- [x] Pole wielokąta (T)
- [ ] Online otoczka wypukła
- [ ] Generowanie SVG wielokąta z punktów
- [ ] Diagram Voronoia
- [ ] Konwersja między postaciami prostych
- [ ] Test czy odcinek jest w środku wielokąta
- [ ] Zamiatanie cykliczne półprostą

Teksty
- [x] KMP (T)
- [x] Z
- [x] Manacher
- [ ] Duval
- [x] Haszowanie (T)
- [ ] Reverse Burrows-Wheeler
- [x] Aho (T)
- [x] Tablica sufiksowa
- [ ] Liniowa tablica sufiksowa
- [ ] Substringi cykliczne (Main-Lorentz)
- [ ] Drzewo palindromów
- [ ] Automat sufiksowy
- [x] Drzewo sufiksowe (T)
- [ ] Wildcard matching
- [ ] Znajdowanie przedziału wystąpień w tablicy sufiksowej
- [ ] Inty zamiast stringów?
- [ ] LCS miedzy wszystkimi substringami
- [ ] Monge (range LIS query)
- [ ] Szybkie modulo 2^61-1

Inne
- [ ] Circular LCS
- [ ] SMAWK
- [x] Fast IO (T)
- [ ] Python, decimal
- [x] Divide and conquer DP (T)
- [x] Knuth DP (T)
- [ ] Pragmy
- [ ] Subset sum dynamic bitset
- [ ] CHT
- [ ] Subset sum modulo m w O(m log m)
- [ ] Dobre ściągi, w szczególności UJ, UW1, stare UW, bardzo stare UW

Źródła
- https://github.com/ecnerwala/cp-book/
- https://github.com/dacin21/dacin21_codebook
- https://github.com/nealwu/competitive-programming
- https://github.com/the-tourist/algo
- https://github.com/bqi343/cp-notebook
- https://github.com/kth-competitive-programming/kactl
- https://github.com/cuber2460/acmlib07/
- https://mimuw.edu.pl/~ms360974/treningi/ACMLib.pdf
- https://github.com/tonowak/acmlib
- https://github.com/maspypy/library
- https://github.com/Stonefeang/librewoosh
- https://github.com/KacperTopolski/kactl

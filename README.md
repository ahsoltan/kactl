# kactl

Inne
- Cachowanie testów (`GITHUB_TOKEN`) działa?

Do naprawienia w KACTL
- Zredagować ściągi, pewnie wywalić większość
- Naprawić spacing po spisie treści i w ściągach
- Zmergować algebrę na doublach i mintach przez szablony
- Wywalić ull z number-theory
- Generalnie prawie wszystko modulo powinno być na mintach

Przenieść z acmlib
- EulerWalk zmieniony
- PrimitiveRoot
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
│   ├── PrimitiveRoot.test.cpp
└── string
    ├── Duval.test.cpp
```

Do weryfikacji w KACTL
- [x] Contest
- [ ] Mathematics
- [ ] Data structures
- [ ] Numerical
- [ ] Number theory
- [ ] Combinatorial
- [ ] Graph
- [ ] Geometry
- [ ] Strings
- [ ] Various

Struktury danych
- [ ] gp_hash_table
- [ ] ordered_set
- [ ] Line container
- [ ] Sparse table
- [ ] Lazy segtree
- [ ] Persistent segtree
- [ ] Treap
- [ ] Fenwick
- [ ] Fenwick 2D
- [ ] Drzewo lichao
- [ ] Persistent treap
- [ ] Wavelet tree

Matma
- [x] Mint
- [ ] Silnie i odwrotności
- [ ] ModMul double
- [ ] Barret
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
- [ ] Min mod linear, first mod linear
- [ ] Ciąg debruijna
- [ ] Nim product
- [ ] Przecięcie matroidów
- [ ] Macierz (pow, mnożenie)
- [ ] Odwrotność macierzy (eliminacja - odwr oddzielnie) (rząd - wyznacznik)
- [ ] Twierdzenie Kirchoffa
- [ ] Sherman Morrison
- [ ] Operacje na wielomianach
- [ ] NTT
- [ ] NTT Garner
- [ ] Berlekamp-Massey
- [ ] Simpson
- [ ] Adaptive simpson
- [ ] Simplex
- [ ] Binsearch na ułamkach
- [x] Logarytm dyskretny
- [ ] Generator mod
- [ ] Sploty AND, OR, XOR
- [ ] Splot SUBSET
- [ ] Interpolacja Lagrange'a dla jednego punktu z 0...n
- [ ] Rozwiązywanie niekwadratowego SLAE
- [ ] Mobius i Phi
- [ ] Rozwiązania równania Pella
- [ ] Sumy potęgowe
- [ ] Generowanie trójek pitagorejskich
- [ ] Przedziały równości dzielenia floor/ceil
- [ ] XOR basis
- [ ] Mnożniki lagrange'a

Grafy
- [ ] DSU
- [ ] Ujemny cykl
- [ ] LCA skok
- [ ] LCA rmq z kompresją
- [ ] HLD
- [ ] Centroidy
- [ ] Cykl eulera
- [ ] SCC
- [ ] 2-SAT 
- [ ] Mosty, cutpointy
- [ ] Maksymalne kliki
- [ ] Dinic
- [ ] Gomory-Hu
- [ ] MCMF
- [ ] Hungarian
- [ ] General matching blossom
- [ ] General weighted matching
- [ ] Hopcroft-Karp
- [ ] Chordal Graph Recognition
- [ ] Drzewo dominatorów
- [ ] Kolorowanie krawędzi w D+1
- [ ] DMST
- [ ] Link-cut tree
- [ ] DSU z rollbackami
- [ ] Dynamic connectivity
- [ ] Twierdzenie Koniga
- [ ] Ściany grafu planarnego
- [ ] Test planarności grafu
- [ ] Największa klika
- [ ] Trójkąty
- [ ] 5-kolorowanie grafu planarnego
- [ ] Max matching Tutte
- [ ] Online SCC
- [ ] Reroot DP
- [x] Twierdzenie BEST

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
- [x] Delaunay triangulation (T)
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
- [ ] Substringi cykliczne
- [ ] Drzewo palindromów
- [ ] Automat sufiksowy
- [x] Drzewo sufiksowe (T)
- [ ] Wildcard matching
- [ ] Znajdowanie przedziału wystąpień w tablicy sufiksowej
- [ ] Inty zamiast stringów

Inne
- [ ] Circular LCS
- [ ] SMAWK
- [ ] Fast IO
- [ ] Python, decimal
- [ ] Divide and conquer DP
- [ ] Knuth DP
- [ ] Pragmy
- [ ] Subset sum dynamic bitset
- [ ] CHT

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

# kactl
![verify](https://github.com/ahsoltan/kactl/actions/workflows/verify.yml/badge.svg)

Do zrobienia
- https://github.com/kth-competitive-programming/kactl/issues/63
- Cleanup weighted blossom?
- https://github.com/kth-competitive-programming/kactl/issues/137
- Zredagować ściągi, pewnie wywalić większość
- Naprawić spacing po spisie treści i w ściągach
- Generalnie prawie wszystko modulo powinno być na mintach
- Podzielić duże pliki/hasze przedziałów (fft, fftpoly)
- Cleanup fftpoly?
- Zrobić żeby cachowanie library-checker-problems było mądrzejsze

Do weryfikacji w KACTL
| Stan | Nazwa |
|:----:|-------|
| :heavy_check_mark: | Contest |
| :x: | Mathematics |
| :heavy_check_mark: | Data structures |
| :x: | Numerical |
| :heavy_check_mark: | Number theory |
| :x: | Combinatorial |
| :x: | Graph |
| :x: | Geometry |
| :x: | Strings |
| :heavy_check_mark: | Various |

Struktury danych
| Stan | Nazwa |
|:----:|-------|
| :heavy_check_mark: | gp_hash_table |
| :heavy_check_mark: | ordered_set |
| :heavy_check_mark: | Line container |
| :heavy_check_mark: | Sparse table |
| :warning: | Lazy segtree |
| :x: | Persistent segtree |
| :warning: | Treap |
| :heavy_check_mark: | Fenwick |
| :warning: | Fenwick 2D |
| :x: | Drzewo lichao (z dodawaniem i maxowaniem) |
| :x: | Persistent treap |
| :x: | Wavelet tree |
| :warning: | DSU z rollbackami |
| :warning: | Mo on array, on tree |
| :x: | Segment tree beats |

Matma
| Stan | Nazwa |
|:----:|-------|
| :heavy_check_mark: | Mint |
| :x: | Silnie i odwrotności |
| :x: | ModMul double |
| :warning: | Barret |
| :heavy_check_mark: | Pierwiastek mod |
| :heavy_check_mark: | Floor sum |
| :warning: | Mod sum |
| :heavy_check_mark: | Sito z bitsetem |
| :heavy_check_mark: | Sumy prefiksowe funkcji multiplykatywnej |
| :heavy_check_mark: | Miller rabin |
| :heavy_check_mark: | Pollard rho |
| :x: | Ułamek między a i b o najmniejszym mian. |
| :warning: | Rozszerzony euklides |
| :warning: | CRT |
| :warning: | Min mod linear, first mod linear |
| :warning: | Ciąg debruijna |
| :heavy_check_mark: | Nim product |
| :warning: | Przecięcie matroidów |
| :x: | Szybkie mnożenie (simd) i potęgowanie (frobenius) macierzy |
| :heavy_check_mark: | Macierz (wyznacznik, odwrotność) |
| :x: | Sherman Morrison |
| :heavy_check_mark: | [Operacje na wielomianach](https://github.com/kth-competitive-programming/kactl/pull/87) (inv, exp, pow, log, interp, eval, ~~chirpz~~) |
| :heavy_check_mark: | NTT |
| :heavy_check_mark: | NTT Garner |
| :heavy_check_mark: | Berlekamp-Massey |
| :warning: | Simpson |
| :warning: | Adaptive simpson |
| :warning: | Simplex |
| :warning: | Binsearch na ułamkach |
| :heavy_check_mark: | Logarytm dyskretny |
| :heavy_check_mark: | Generator mod |
| :heavy_check_mark: | Sploty AND, OR, XOR |
| :x: | Splot SUBSET |
| :x: | Interpolacja Lagrange'a dla jednego punktu z 0...n |
| :heavy_check_mark: | Rozwiązywanie niekwadratowego SLAE |
| :x: | Mobius i Phi |
| :x: | Rozwiązania równania Pella |
| :x: | Sumy potęgowe |
| :x: | Generowanie trójek pitagorejskich |
| :warning: | Przedziały równości dzielenia floor/ceil |
| :x: | XOR basis |
| :heavy_check_mark: | Mnożniki lagrange'a |
| :heavy_check_mark: | Wyznacznik macierzy (black box z berlekampem) |
| :x: | Kod graya i odwrotność |
| :x: | Schreier-Sims |
| :heavy_check_mark: | Twierdzenie pentagonalne eulera |
| :warning: | Ułamek |

Grafy
| Stan | Nazwa |
|:----:|-------|
| :heavy_check_mark: | DSU |
| :x: | Ujemny cykl |
| :x: | LCA skok |
| :x: | LCA rmq z kompresją |
| :x: | HLD |
| :heavy_check_mark: | Centroidy |
| :heavy_check_mark: | Cykl eulera |
| :heavy_check_mark: | SCC |
| :warning: | 2-SAT |
| :heavy_check_mark: | Dwuspójne |
| :warning: | Maksymalne kliki |
| :warning: | Dinic |
| :warning: | Gomory-Hu |
| :warning: | MCMF |
| :heavy_check_mark: | Hungarian |
| :heavy_check_mark: | General matching blossom |
| :heavy_check_mark: | General weighted matching |
| :heavy_check_mark: | Hopcroft-Karp |
| :x: | Chordal Graph Recognition |
| :heavy_check_mark: | Drzewo dominatorów |
| :warning: | Kolorowanie krawędzi w D+1 |
| :heavy_check_mark: | DMST |
| :warning: | Link-cut tree z różnymi rzeczami |
| :x: | Dynamic connectivity |
| :x: | Twierdzenie Koniga |
| :warning: | Ściany grafu planarnego |
| :x: | Test planarności grafu |
| :heavy_check_mark: | Największa klika |
| :x: | Trójkąty |
| :x: | 5-kolorowanie grafu planarnego |
| :x: | Max matching Tutte |
| :x: | Incremental SCC |
| :warning: | Reroot DP |
| :heavy_check_mark: | Twierdzenie BEST |
| :heavy_check_mark: | Twierdzenie Kirchoffa |
| :heavy_check_mark: | Liczba chromatyczna |
| :x: | Wielomian chromatyczny |
| :x: | Kolorwanie krawędzi grafu dwudzielnego w D |
| :heavy_check_mark: | K-ta najkrótsza ścieżka |
| :x: | Incremental bipartite matching |
| :x: | SPFA smu |

Geometria
| Stan | Nazwa |
|:----:|-------|
| :x: | Zdecydować postępowanie co do templatów i doubli |
| :warning: | Punkt |
| :heavy_check_mark: | Angle cmp |
| :warning: | Segment dist, line dist |
| :warning: | Przecięcie prostych/odcinków |
| :warning: | Środek ciężkości wielokąta |
| :warning: | Test czy jest w środku wielokąta |
| :heavy_check_mark: | Otoczka wypukła |
| :x: | Suma minkowskiego |
| :heavy_check_mark: | Najdalsze punkty na otoczce |
| :warning: | Styczne do otoczki |
| :warning: | Przecięcie otoczki z prostą |
| :warning: | Przecięcie półpłaszczyzn |
| :x: | Online przecięcie półpłaszczyzn |
| :warning: | Suma wielokątów |
| :x: | Okrąg |
| :warning: | Przecięcie okrąg okrąg |
| :x: | Pole przecięcia okrąg okrąg |
| :warning: | Przecięcie okręgu i prostej |
| :warning: | Wspólne styczne okręgów |
| :warning: | Okrąg opisany na trójkącie |
| :warning: | Min enclosing circle |
| :heavy_check_mark: | Najbliższa para punktów |
| :warning: | Delaunay triangulation |
| :heavy_check_mark: | Manhattan MST |
| :warning: | Punkt 3D |
| :warning: | Otoczka 3D O(n^2) |
| :x: | Otoczka 3D O(n log n) |
| :x: | Pole powierzchni |
| :warning: | Objętość |
| :warning: | Test czy punkt w otoczce |
| :warning: | Obcięcie wielokąta prostą |
| :warning: | Pole wielokąta |
| :x: | Online otoczka wypukła |
| :x: | Generowanie SVG wielokąta z punktów |
| :x: | Diagram Voronoia |
| :x: | Konwersja między postaciami prostych |
| :x: | Test czy odcinek jest w środku wielokąta |
| :x: | Zamiatanie cykliczne półprostą |
| :x: | Convex poly periodic min comp (zamienic z hull tangents, dodac min/max dot) (maspy) |
| :x: | Jakiś point location albo przynajmniej tutorial lol |
| :x: | Geo 3d (op na liniach, płaszczyznach, sferach itp) |

Teksty
| Stan | Nazwa |
|:----:|-------|
| :warning: | KMP |
| :heavy_check_mark: | Z |
| :heavy_check_mark: | Manacher |
| :heavy_check_mark: | Duval |
| :warning: | Haszowanie |
| :x: | Reverse Burrows-Wheeler |
| :warning: | Aho |
| :heavy_check_mark: | Tablica sufiksowa |
| :x: | Liniowa tablica sufiksowa |
| :heavy_check_mark: | Substringi cykliczne (Main-Lorentz) |
| :heavy_check_mark: | Drzewo palindromów |
| :x: | Automat sufiksowy |
| :warning: | Drzewo sufiksowe |
| :heavy_check_mark: | Wildcard matching |
| :x: | Znajdowanie przedziału wystąpień w tablicy sufiksowej |
| :x: | Inty zamiast stringów? |
| :x: | LCS miedzy wszystkimi substringami |
| :x: | Monge (range LIS query) |
| :warning: | Szybkie modulo 2^61-1 |

Inne
| Stan | Nazwa |
|:----:|-------|
| :x: | Circular LCS |
| :x: | SMAWK |
| :warning: | Fast IO |
| :x: | Python, decimal |
| :warning: | Divide and conquer DP |
| :warning: | Knuth DP |
| :warning: | Pragmy |
| :warning: | Subset sum dynamic bitset |
| :x: | CHT |
| :x: | Subset sum modulo m w O(m log m) |
| :x: | Dobre ściągi, w szczególności UJ, UW1, stare UW, bardzo stare UW |

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
- https://github.com/ecnerwala/icpc-book

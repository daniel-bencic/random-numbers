# Generating Random Numbers by Sampling

Ihre Aufgabe: Erzeugung von Zufallszahlen die der Verteilung des in der Vorlesung erwähnten Beispiels ["Eingehende Anrufe bei Fernsehabstimmungen"](https://de.wikibooks.org/wiki/Statistik:_Stetige_Zufallsvariablen) folgen.

Verwenden Sie die Programmiersprache Ihrer Wahl. Allerdings werden Sie keinen Zufallszahlengenerator für genau diese Verteilung finde. Implementieren Sie daher zur Erzeugung dieser Zufallszahlen folgende Algorithmen:

*[Verwerfungsmethode] (Accept Reject)(https://de.wikipedia.org/wiki/Verwerfungsmethode)
*[Inversionsmethode](https://de.wikipedia.org/wiki/Inversionsmethode)

Vergleichen Sie die beiden Algorithmen (z.B. Güte der Zufallszahlen, Schwierigkeit der Implementierung, Laufzeit, ...) und bewerten Sie, welcher der Algorithmen für Sie der "bessere" ist. 

# Dependencies
* Qt5Widgets
* Qt5Charts

# How To Run
1. `cd build`
2. `cmake ..`
3. `make`
4. run `random-numbers`

# Comments
Both sampling methods generate random numbers according to the probability density function.
The rejection method is an easy and straightforward attempt to generate random numbers but depending on the
pdf it can be very inefficient.
The inversion method is a 100% efficient method, however it depends on the calculation of the inverse function of the
cumulative density function. The implementation requires less work but may be more complicated than the rejection method
due to the calculation of the inverse cdf.

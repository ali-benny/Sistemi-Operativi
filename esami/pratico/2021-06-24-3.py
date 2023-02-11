# link testo https://csunibo.github.io/sistemi-operativi/prove/pratica/scritto-2021-06-24-testo.pdf

"""	Esercizio 3
Scrivere uno script o un programma python che corregga l'indentazione di tutti i file .c e .h presenti
nel sottoalbero della directory passata come parametro (la working directory se non vi sono
parametri).
Hint: il comando:
	ex -n '+norm!gg=G' +wq prog.c
corregge l'indentazione del programma sorgente C prog.c.
"""

import os
import sys

def main():
	
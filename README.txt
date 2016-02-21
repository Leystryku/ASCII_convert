Verwendung:
Man startet ASCII_convert.exe und wählt Modus 1 oder 2 aus.
Dann wird der string ( z.B. "Hallo Welt!" ) eingegeben.
Bei Dec to ASCII muss man beachten, das die einzelnen Nummern mit Leertasten
getrennt werden müssen ( z.B. 100 101 102 103 ).
Zeichen welche nicht in ASCII Code enthalten sind werden durch '?' ersetzt.
Die Kommandozeichen 0-31 ( Dez ) sowie 127 ( Dez ) werden visuell nicht dargestellt.

Info:
Das Programm wurde mit MSVC 12 kompiliert.
Ich habe es auf Windows 8.1 64 bit und Windows XP SP3 getestet,
um sicherzustellen das es auch auf älteren Maschinen läuft.

ASCII_convert.cpp supportet ASCII->Bin->Hex->Dec und Dec->Hex->Bin->ASCII.
In ASCII_convert_orig.cpp befindet sich mein originaler Konverter.
Er supportet kann mehr konvertieren als der andere ( ASCII zu Hex/Dec/Bin sowie Hex/Dec/Bin zu ASCII/Hex/Dec/Bin ).

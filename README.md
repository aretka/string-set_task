# Papildoma užduotis (naudojant asociatyvius konteinerius)

## Programos veikimas
  1. Programa kaip įvestį paima tekstą iš *"input.txt"* failo. Šį failą perskaito ir į "Words" asociatyvų konteinerį sudedami visi skirtingi žodžiai. 
  2. Kai perskaitomas žodis, yra patikrinama, ar tai yra URL, ar ne ir jeigu taip yra pridedamas URL prie "URLS" masyvo.
  3. Vėliau yra patikrinama ar žodis pasikartoja "Words" masyve, ar ne. Jeigu pasikartoja, prie "WordCount" vektoriaus yra pridedamas vienetas(iš pradžių randame, pagal "Words" masyvą, kurioje vietoje yra šis žodis ir pagal šį indeksą, toje pačioje vietoje ir "WordCount" masyve pridedame vienetą), jeigu ne, tai prie "WordCount" pridedamas 1 elementas, kurį prilyginame vienetui.
  4.  Galiausiai spausdindami elementus į *"output.txt"* failą. Programa spausdina tik tuos žodžius, kurie pasikartoja daugiau nei 1 kartą. Tada spausdinimo metu programa suranda kuriose eilutėse tam tikras žodis pasikartoja ir išspausdina tų eilučių indeksus.
  
  *"output.txt"* failas atrodo taip:</br>
  ![output](output.txt)

# Papildoma užduotis (naudojant asociatyvius konteinerius)

## Programos veikimas
  1. Programa kaip įvestį paima kažkokį tekstą iš *"input.txt"* failo. Šį failą perskaito ir į "Words" asociatyvų konteinerį sudedami visi skirtingi žodžiai. 
  2. Kai perskaitomas žodis, yra ptikrinama, ar tai yra URL ar ne.
  3. Vėliau yra patikrinama ar žodis pasikartoja "Words", ar ne. Jeigu pasikartoja, prie "WordCount" vektoriaus yra pridedamas vienetas(iš pradžių randame, pagal "Words" masyvą, kurioje vietoje yra šis žodis ir pagal šį indeksą, toje pačioje vietoje ir "WordCount" masyve pridedame vienetą), jeigu ne, tai prie "WordCount" pridedamas 1 elementas, kurį prilyginame vienetui.
  4.  Galiausiai spausdindami elementus į *"output.txt"* failą.

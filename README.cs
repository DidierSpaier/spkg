spkg - rychl� bal��kovac� mana�er pro Slackware Linux
-----------------------------------------------------

Popis
-----
Bal��kovac� mana�er je program pro spr�vu bal��k�. Spr�vou
se rozum� instalace, aktualizace, odstra�ov�n� a kontrola
bal��k�.

Bal��ek
-------
Obecn� je bal��ek mno�ina soubor� a informac� spole�n�ch t�mto 
soubor�m (metadat). P��kladem metadat m��e b�t skript, 
definuj�c� p��kazy, kter� se maj� prov�st po ur�it� akci, 
seznam z�vislost� na jin�ch bal��c�ch, atp.

Form�t bal��ku
--------------
Ka�d� bal��ek lze identifikovat pomoc� jednozna�n�ho
identifik�toru, kter� se skl�d� z:
  - n�zvu bal��ku
  - verze bal��ku
  - architektury pro kterou je bal��ek ur�en
  - ��sla sestaven� bal��ku
  - id autora

Pozn.: N�kdy se v k�du identifik�tor ozna�uje jako [dlouh�] n�zev 
bal��ku a n�zev bal��ku jako kr�tk� n�zev bal��ku. (name a shortname)

Identifik�tor m� form�t (�pi�at� z�vorky obsahuj� povinn� ��sti, hranat�
z�vorky nepovinn� ��sti):
  <n�zev>-<verze>-<architektura>-<sestaven�>[autor]

��dn� ��st identifik�toru, krom� n�zvu nem��e obsahovat poml�ku.

Bal��ek je gzipem komprimovan� tar archiv obsahuj�c� dva typy
soubor�:
  - soubory s metadaty:        install/slack-* install/doinst.sh
  - soubory bal��kovan�ch dat: zbyl� soubory

��dn� soubor v archivu nesm� m�t absolutn� cestu. (tj. cestu
za��naj�c� lom�tkem)

Soubory metadat by m�ly b�t um�st�ny co nejbl�e k za��tku archivu.

doinst.sh: Skript shellu, kter� se spou�t� po �sp�n� extrakci
soubor�. Skript se spu�t� v ko�enov�m adres��i bal��ku. Prov�d�n� 
p��kazy nesm�j� modifikovat soubory v rodi�ovsk�ch adres���ch
aktu�ln�ho adres��e. Z toho vypl�v�, �e autor skriptu nesm� 
p�edpokl�dat, �e bude skript spu�t�n v ko�enov�m adres��i (/).

slack-desc: Je soubor obsahuj�c� kr�tk� a dlouh� popis bal��ku. 
Prvn� platn� ��dek souboru mus� m�t form�t:
  <n�zev> (kr�tk� popis)

D�le soubor obsahuje maxim�ln� 10 takov�chto ��dk�:
  [dlouh� popis]

Platn� ��dek je ��dek za��naj�c� textem: "<n�zev>:"

P��klad platn�ho souboru slack-desc:

spkg: spkg (fast package manager)
spkg: spkg is The Fastest Package Managment Tool on the world.
spkg: Written by Ondrej Jirman <megous@megous.com>

spkg
----
Hlavn�m �kolem bal��kov�ho mana�eru je udr�ovat datab�zi nainstalovan�ch
bal��k� a k nim p��slu�ej�c�ch soubor�. 


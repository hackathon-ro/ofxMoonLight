# Nume proiect: ofxMoonLight 

# Descriere

ofxMoonLight este un mediu de programare in Lua (orientat catre Creative Coding) pentru Raspeberry Pi. 
Este util ca instrument de invatare a programarii (ofera feedback vizual rapid), dar si programatorilor din comunitatea OpenFrameworks care deja cunosc particularitatile
API-ului si doresc sa dezvolte rapid pe RasberryPi.

## Contine: 
- binding-uri pentru framework-ul OpenFrameworks, furnizate ca addon OF;
- script de instalare si configurare a pachetelor necesare pentru Raspbian;
- executabilul "ml", care permite rularea programelor scrise in Lua folosind API OpenFrameworks, si generarea template-urilor pentru proiecte noi.

## Avantajele solutiei:
- instalare simpla, eliminand necesitatea compilarii si configurarii manuale a OpenFrameworks;
- generare de templateuri pentru proiecte noi (creeaza structura de fisiere si directoare a proiectelor si functiile de implementat);
- pune la dispozitia programatorului biblioteca OpenFrameworks:
	-> apeleaza din Lua functiile native C++ din OpenFrameworks;
	-> performanta C++ pentru operatiile complexe de prelucrare multimedia;
	-> comunitatea existenta OpenFrameworks are la dispozitie API-ul deja cunoscut;
- Lua este cel mai rapid limbaj de scripting;
- Lua are o complexitate redusa de invatare, comparativ cu C++ sau Java;
- ofxMoonLight are avantajele unui limbaj interpretat (usurinta de invatare), eliminand in mare masura dezavantajul principal (viteza redusa de rulare comparativ cu un limbaj compilat);

# Categoria proiectului: Software 

# Echipa MoonPi: 
- Chioveanu Leonard
- Florescu Bogdan
- Vasile Adrian 

# Link GitHub: https://github.com/hackathon-ro/ofxMoonLight

# Instructiuni

### Instalare
<code> 
<code>wget https://github.com/hackathon-ro/ofxMoonLight/raw/master/prebuilt/downloadAndInstall.sh </code>
<code>chmod +x downloadAndInstall.sh</code>
<code>./downloadAndInstall.sh</code>


### Configurare
Adaugati linia urmatoare in ~/.bashrc:
<code> export PATH=/path/to/MoonLight/:$PATH </code>

### Rulare
<code>?>ml new PROJECT_NAME</code>
<code>?>ml /path/to/project_folder/</code>

### Structura proiectului
- /project_folder/main.lua (obligatorie) : incarca clasa principala a aplicatiei
- /project_folder/app/app.lua (obligatorie) : clasa principala a aplicatiei, contine toate functiile necesare implementarii
- /project_folder/app/class.lua (optionala) : simuleaza o clasa in lua; trebuie pastrata in situatia in care proiectul contine clase
- restul claselor vor fi create in /project_folder/app/
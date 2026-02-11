## Configuration matérielle

- Microcontrôleur : ATTiny85
- TX : PB4 (pin 3) → RX du XBee-USB
- GND ATTiny → GND du XBee-USB

## Outils nécessaires

 - avr-gcc
 - avrdude
 - gtkterm

Installation si nécessaire :

sudo apt install gcc-avr avr-libc avrdude gtkterm

## Compilation

Pour compiler et flasher le programme :

make flash

## Nettoyage

make clean

## Réception côté PC

Configurer le terminal série avec :
- Port : /dev/ttyACM0
- 300 bauds
- 8 bits
- pas de parité
- 1 bit de stop

Si accès refusé au port série, ajouter l'utilisateur au groupe dialout :

sudo usermod -aG dialout $USER

Puis se déconnecter et se reconnecter.

Le message "coucou" s’affiche chaque seconde.

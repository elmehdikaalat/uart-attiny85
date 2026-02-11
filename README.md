## Configuration matérielle

- Microcontrôleur : ATTiny85
- TX : PB4 (pin 3) → RX du XBee-USB
- GND ATTiny → GND du XBee-USB

## Compilation et programmation

Pour compiler et flasher le programme :

make flash

## Nettoyage

make clean

## Réception côté PC

Configurer le terminal série avec :
- 300 bauds
- 8 bits
- pas de parité
- 1 bit de stop

Le message "coucou" s’affiche chaque seconde.

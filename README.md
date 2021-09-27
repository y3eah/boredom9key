# boredom9key
9 key controller/macro keyboard with 30mm arcade buttons that I made, simply because I was bored!

Can play PIU/DDR/Pulsus/maimai if you want. Uses NICOHOOD's HID NKRO library so it can press 9 keyboard buttons at once.

4t plywood sandwhich with 3t acylic on the top!
It's built only for Aliexpress Chinese buttons, so other buttons wouldn't work due to height issues, unless you modify models to put more plywoods to make height higher.

List of parts that are required :

| Part | Qty |
| --- |:---:|
| M4 22mm screw | 4 |
| M4 Tee nut | 4 |
| Arduino Pro Micro | 1 |
| USB-B Block | 1 |
| Glues to put plywoods together | ? |
| 4T 145mm×145mm Plywood | 6 |
| 3T 145mm×145mm Acrylic | 1 |
| 30AWG wires (recommended) | ? |
| Aliexpress chinese buttons | 9 |

Link to 30mm LED Chinese buttons
: https://aliexpress.com/item/4001076611440.html

Link to USB-B Block
: https://aliexpress.com/item/4001279234342.html

Link to Arduino Pro Micro
: https://aliexpress.com/item/32887074671.html

Buttons are ordered like this : 

| 3 | 2 | 1 |  
| 6 | 5 | 4 |  
| 9 | 8 | 7 |

For the Button Keybinds : 

| q | w | e |  
| a | s | d |  
| z | x | c |

And for the pinout (Button Signal/LED) :

| A3/9 | A2/8 | A1/7 |  
| A0/6 | 15/5 | 14/4 |  
| 16/3 | 10/2 | 1/0 | 

30AWG is highly recommended because there aren't much spaces inside of controller.

This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
The code is based on SpeedyPotato's Pocket-sdvx : https://github.com/speedypotato/Pocket-SDVX

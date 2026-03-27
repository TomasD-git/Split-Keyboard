# Split-Keyboard

> A handwired split mechanical keyboard — essentially a modified 60% layout cut down the middle, powered by two ESP32 microcontrollers communicating wirelessly.

---

**How it works?**
The keyboard is split into two halfes, each wired to its own ESP32. Key presses are detected via a switch matrix using 1N4148 diodes to prevent ghosting. The two halfes communicate over wireless, and the firmware handles all HID (Bluetooth/USB) output. Switches sit in a custom PCB made from the Gerber files, and the case is 3D printed.

<details>
  <summary>Click me to see BOM</summary>

| Name | Purpose | Cost Per Item (USD) | Quantity | Total (USD) | Link | Distributor |
|------|---------|-------------------|---------|------------|------|------------|
| Keycaps | The keycaps sitting on top of the switches | ? | 1 set | ? | [Link](https://www.aliexpress.com/item/1005007360831985.html) | AliExpress |
| ESP32 N8R2 | Brain of each half | ? | 2 | ? | [Link](https://www.aliexpress.com/item/1005008750977454.html) | AliExpress |
| M2xL3xOD3 heat-set inserts | for securing the case without stripping | ? | 1 pack | ? | [Link](https://www.aliexpress.com/item/1005006071488810.html) | AliExpress |
| 5×3mm neodymium magnets | hold together both halfes | ? | 50 | ? | [Link](https://www.aliexpress.com/item/1005009327234616.html) | AliExpress |
| Cherry MX switches | The mechanical switches under each keycap | ? | 1 pack | ? | [Link](https://www.aliexpress.com/item/1005004285423123.html) | AliExpress |
| 1N4148WT SOD-523 diodes | One per switch — prevents ghosting in the key matrix | ? | 1 pack | ? | [Link](https://www.aliexpress.com/item/1005007160563285.html) | AliExpress |
| M2 screws | Holds the PCB and case together | ? | 1 pack | ? | [Link](https://www.aliexpress.com/item/1005005789516333.html) | AliExpress |
| PCB | Custom PCB made in KiCad | N/A | 1 | N/A | [Gerber files in repo](https://jlcpcb.com) | JLCPCB |
| 3U Spacebar (3D printed) | Custom wider spacebar for the split layout | — | 2 | — | Print myself | — |

</details>

<details>
  <summary>Layout</summary>

**Standard (unsplit) layout:**
```
["Esc","1","2","3","4","5","6","7","8","9","0","-","=",{w:2},"Backspace","PrtSc"],
[{w:1.5},"Tab","Q","W","E","R","T","Z","U","I","O","P","/",")",{w:1.5},"|",{a:6},"Left"],
[{a:4,w:1.75},"Caps Lock","A","S","D","F","G","H","J","K","L",{f:6},":",{f:5},"\"",{f:3,w:2.25},"Enter","Down"],
[{w:2.25},"Shift","y","x","c","v","b","n","m","<",">","?",{w:2.75},"Shift","Up"],
[{w:1.25},"Ctrl",{w:1.25},"Win",{w:1.25},"Alt",{w:2.75},"Space",{x:0.5,w:3},"Space",{w:1.25},"AltGr",{w:1.25},"Fn",{w:1.25},"Win",{w:1.25},"Ctrl","Right"]
```

**Split layout** (gap between columns 6 and 7):
```
["Esc","1","2","3","4","5","6",{x:1},"7","8","9","0","-","=",{w:2},"Backspace","PrtSc"],
[{w:1.5},"Tab","Q","W","E","R","T",{x:1},"Z","U","I","O","P","/",")",{w:1.5},"|",{a:6},"Left"],
[{a:4,w:1.75},"Caps Lock","A","S","D","F","G",{x:1},"H","J","K","L",{f:6},":",{f:5},"\"",{f:3,w:2.25},"Enter","Down"],
[{w:2.25},"Shift","y","x","c","v","b",{x:1},"n","m","<",">","?",{w:2.75},"Shift","Up"],
[{w:1.25},"Ctrl",{w:1.25},"Win",{w:1.25},"Alt",{w:2.75},"Space",{x:1.5,w:3},"Space",{w:1.25},"AltGr",{w:1.25},"Fn",{w:1.25},"Win",{w:1.25},"Ctrl","Right"]
```

You can visualise and edit these layouts at [keyboard-layout-editor.com](http://www.keyboard-layout-editor.com/).

</details>

<details>
  <summary>For Future</summary>

## Planned improvements:  

**Wrist rests** 
3D print custom wrist rests that magnetically attach to each half.  

**Proper firmware (ZMK / QMK / KMK)**  
Move from a hand-rolled firmware to ZMK (ideal for wireless ESP32 splits) for layers, combos, and community support.  

**Carrying case**  
A small 3D-printed travel case or pouch to store both halves and the cable.  

</details>

<details>
  <summary>License</summary>

### MIT License

**Copyright (c) [2026] [TomasD-git]**

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

</details>
  
    

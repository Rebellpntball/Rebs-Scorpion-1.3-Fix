# Rebs Scorpion 1.3 Fix

**Proper compatibility override** for the **BLACKOUTS / vg7_scorpion** motorcycle mod.

- DayZ **1.29** ready, safe for **1.30**
- Override only – does not edit the original mod

Original: VectorG7 / DrBlackouts / DeanosBeano  
Compatibility + colours: Rebs

---

## Features

### 1.29 physics sleep fix
Keeps simulation alive for exhaust / smoke while engine on or smoke active.

### Retro yellow headlights
`RebsScorpionFrontLight` / `RebsScorpionRearLight` (unique names, no clash).

### Handling pass
Lower inertia, lower drag, softer rear, tamer throttle – Fat Boy inspired, still a Scorpion.

### Procedural colour variants
Same method as your FDZ shemaghs: `#(argb,8,8,3)color(R,G,B,1,CO)`

| Class | Look |
|-------|------|
| `vg7_scorpion_Rebs_Princess` | **Royal Crown Purple** tank + original **pink** frame |
| `vg7_scorpion_Rebs_BlueBlood` | Full deep blue `(0.05,0.16,0.42)` |
| `vg7_scorpion_Rebs_CyberBlue` | Full cyber blue `(0.02,0.45,0.85)` |
| `vg7_scorpion_Rebs_ArmyGreen` | Full army green `(0.24,0.30,0.16)` |
| `vg7_scorpion_Rebs_AshGrunge` | Full ash/charcoal `(0.18,0.18,0.18)` |
| `vg7_scorpion_Rebs_RustGrunge` | Full rust brown `(0.36,0.14,0.05)` |

**Note:** Procedural colours are solid fills. You lose original tank art / logos / wear maps on those slots, but you get exact brand colours with zero extra textures.

Princess keeps original pink body `.paa` on the frame so it still has some detail.

---

## Install

```
… ; vg7_scorpion ; Rebs_Scorpion_1_3_Fix
```

Add the new classnames to types / economy if you want them to spawn.

---

## Credits

Original Scorpion – VectorG7, DrBlackouts, DeanosBeano  
Override / handling / procedural paints – Rebs

# Rebs Scorpion 1.3 Fix

**Proper compatibility override** for the **BLACKOUTS / vg7_scorpion** motorcycle mod.

- Works on **DayZ 1.29** (stable + Road to Badlands)
- Safe for **DayZ 1.30** Experimental / Badlands
- Does **not** edit the original mod – pure `modded class` + unique light types

Original authors: VectorG7, DrBlackouts, DeanosBeano  
Compatibility: Rebs

---

## What this fix does (correctly)

### 1.29 physics sleep
Inactive vehicles no longer tick `EOnPostSimulate`.  
This override calls `SetRequiredSimulation(true)` while the engine is on **or** the smoke screen is active so exhaust/smoke particles keep working.

### Headlights – retro 80s yellow
Uses **new** light classes (`RebsScorpionFrontLight` / `RebsScorpionRearLight`) so there is **no** multiple-declaration clash with the original `vg7ScorpionFrontLight`.  
Colour: warm halogen amber `RGB ≈ 1.0, 0.82–0.85, 0.45–0.50`.

### Actions
Uses **`modded class`** on the original action types (never re-declares them as `class`).  
Smoke-screen action: dynamic Enable/Disable text + requires engine on.

### Script scope
Only `modded class vg7_scorpion`.  
Colour variants that **extend** that script class in the original inherit the overrides.  
We do **not** invent `modded class vg7_scorpion_mermaid` etc. unless those script classes exist in the original (config inheritance alone is not enough).

---

## Installation

1. Keep the **original vg7_scorpion** mod installed.
2. Pack this folder (or clone the repo) as a normal DayZ mod.
3. Load order:

```
… ; vg7_scorpion ; Rebs_Scorpion_1_3_Fix
```

4. Optional on 1.30: add Scorpion class names to any 3PP vehicle whitelist.

No types.xml / economy changes.

---

## Why the first version was not a proper override

| Problem | Fix |
|--------|-----|
| `class vg7ScorpionFrontLight` redeclared → compile error vs original | Renamed to `RebsScorpionFrontLight` |
| `class ActionToggle…` redeclared → compile error | Switched to `modded class` |
| `modded class vg7_scorpion_mermaid` etc. when those script types may not exist | Removed; only mod the real base script class |
| requiredAddons includes `vg7_scorpion` | Kept (correct load order) |

---

## Credits

- Original Scorpion – VectorG7, DrBlackouts, DeanosBeano  
- Override / 1.29–1.30 compatibility – Rebs

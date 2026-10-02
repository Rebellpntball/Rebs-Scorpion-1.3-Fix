# Rebs Scorpion 1.3 Fix

**Proper compatibility override** for the **BLACKOUTS / vg7_scorpion** motorcycle mod.

- Works on **DayZ 1.29** (stable + Road to Badlands)
- Safe for **DayZ 1.30** Experimental / Badlands
- Does **not** edit the original mod – pure `modded class` + config overrides

Original authors: VectorG7, DrBlackouts, DeanosBeano  
Compatibility: Rebs

---

## What this fix does

### 1.29 physics sleep
`SetRequiredSimulation(true)` while engine on or smoke active so exhaust/smoke particles keep working.

### Retro 80s yellow headlights
Unique light classes (`RebsScorpionFrontLight` / `RebsScorpionRearLight`) – no name clash with original.

### Handling pass (Fat Boy inspired)
Config override on `vg7_scorpion` SimulationModule:

| Change | From → To | Feel |
|--------|-----------|------|
| Engine inertia | 0.85 → **0.45** | Snappier throttle |
| Drag | 0.56 → **0.40** | Less air wall |
| defaultThrust | 0.95 → **0.75** | Less twitchy |
| turboCoef | 4.0 → **3.6** | Softer boost spike |
| Rear suspension stiffness | ~35000 → **24000** | Less skatey rear |
| Downforce | none → **0.6** | More planted |

Still a Scorpion – not a full Fat Boy clone.

### New colour: `vg7_scorpion_Rebs_Princess`
**Procedural mix** of original textures only (no new .paa):

- **Tank:** Ace of Spades (`GasTank_Ace_CA`) – royal look
- **Frame / fender / forks / grips:** Pink (`Mainbody_Pink_CA` + pink materials)
- **Seat:** Ace body texture + standard seat material

Spawn name: `vg7_scorpion_Rebs_Princess`

There is **no purple tank** in the original pack. Closest “royal” tank is Ace. If you later add a purple `.paa`, we only need to point the tank slot at it.

---

## Installation

1. Keep the **original vg7_scorpion** mod installed.
2. Pack this folder / clone the repo as a normal DayZ mod.
3. Load order:

```
… ; vg7_scorpion ; Rebs_Scorpion_1_3_Fix
```

4. Optional on 1.30: whitelist Scorpion class names for 3PP if your server uses one.

No types.xml required for the fix itself. Add `vg7_scorpion_Rebs_Princess` to your economy / types if you want it to spawn or be craftable.

---

## Credits

- Original Scorpion – VectorG7, DrBlackouts, DeanosBeano  
- Override / 1.29–1.30 / handling / Princess mix – Rebs

# Rebs Scorpion 1.3 Fix

**Compatibility override** for the **BLACKOUTS / vg7_scorpion** motorcycle mod.

- Works on **DayZ 1.29** (stable + Road to Badlands)
- Safe for **DayZ 1.30** Experimental / Badlands
- Does **not** modify the original mod files – pure script + light override

Original authors: VectorG7, DrBlackouts, DeanosBeano  
Compatibility & lights: Rebs

---

## What this fix does

### 1.29 physics sleep
Inactive vehicles no longer receive `EOnPostSimulate`.  
The original exhaust + smoke-screen particles lived inside that callback.  
This override forces the body to stay simulated while the engine is running **or** the smoke screen is active, so the FX keep working.

### Headlights – retro 80s yellow
Replaces the front light with a warmer halogen / amber colour:

```
RGB ≈ 1.0 , 0.82–0.85 , 0.45–0.50
```

Classic late-70s / 80s motorcycle look instead of modern cold white.

### Matching rear light
Adds a proper warm reverse + classic red brake light so the bike looks consistent front-to-back.

### Actions cleaned up
- Smoke-screen action now correctly requires the engine to be running.
- Dynamic text (“Enable / Disable Smoke Screen”).
- Stand-up chopper action has a safe fallback if the original helper class is missing.

### Camera
Keeps the original 3rd-person distance / height offsets for every colour variant.

### OnDebugSpawn
Fixes the rust-variant handguard class names that did not exist in some builds of the original.

---

## Installation

1. Keep the **original vg7_scorpion** mod installed (Workshop or local).
2. Pack this folder as a normal DayZ mod (or use the provided structure).
3. Load order:

```
… ; vg7_scorpion ; Rebs_Scorpion_1_3_Fix
```

4. (Optional) If you use a 3PP vehicle whitelist on 1.30, add the Scorpion class names.

No types.xml / economy changes required – this is pure script + lights.

---

## Inputs

The original mod already registers:

- `UAToggleVG7SCORPIONSmokeScreen`
- `UAToggleVG7SCORPIONStandUpChopper`

If those keys are missing on your install, copy the original `inputs.xml` or re-bind them in the game options.

---

## Known limitations / notes

- The Scorpion remains a **4-wheel CarScript** vehicle. It will **not** lean like the official 1.30 Jana / Bitrak motorbikes. That is expected.
- Smoke screen only works while the engine is running (by design in this fix).
- If the original mod later receives an official 1.30 update, you can simply remove this override.

---

## File layout

```
Rebs_Scorpion_1_3_Fix/
├── config.cpp
├── README.md
└── Scripts/
    ├── 4_World/Rebs_Scorpion_1_3_Fix/
    │   ├── vg7_scorpion.c          ← main vehicle override + all colour variants
    │   ├── actions/
    │   │   ├── ActionInputVG7SCORPIONSmokeScreen.c
    │   │   ├── ActionInputVG7SCORPIONStandUpChopper.c
    │   │   ├── ActionToggleVG7SCORPIONSmokeScreen.c
    │   │   └── ActionToggleVG7SCORPIONStandUpChopper.c
    │   └── lights/
    │       ├── vg7ScorpionFrontLight.c   ← retro yellow
    │       └── vg7ScorpionRearLight.c
    └── 5_Mission/Rebs_Scorpion_1_3_Fix/
        └── camera.c
```

---

## Credits

- Original Scorpion mod – VectorG7, DrBlackouts, DeanosBeano
- 1.29 / 1.30 compatibility, yellow lights, action cleanup – Rebs

Feel free to fork / improve. Please keep the original authors credited.

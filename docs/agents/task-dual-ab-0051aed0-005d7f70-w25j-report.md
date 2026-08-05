# OWN-ONLY dual agent report — W25-J

**Date:** 2026-07-29  
**Agent:** W25-J OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051aed0`, `0x005d7f70`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ xrefs / function meta). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0051aed0` Object_PlayPickupSpecialFX | **accept-with-gaps** — **thiscall + ret 8; generic_pickup_* type/rarity map sealed; product method English open** |
| `aa_005d7f70` CVOGHBAICreatureBase_DoLogic | **accept-with-gaps** — **thiscall void; CreatureBase class High via DecideHeading vtbl; state machine + skill sets sealed; method English Probable** |

---

## `aa_0051aed0` — Object_PlayPickupSpecialFX

### Sealed facts

1. **Body:** `0x0051aed0`–`0x0051b1b9`.

2. **ABI:** **thiscall** (ECX=this → EBX); stack `char bPlayAudio`, `char bForceQuestFx`; **`ret 8`**.

3. **Domain:** Client pickup SpecialFX — script names `generic_pickup*` driven by clone type `+0x38`, force-quest flag / type 4, trick-material tag `def+0x3F4==0x10`, rarity `def+0x4B8`.

4. **Attach:** `NDSpecialFX_LoadFromScriptName(name,4,0)` → host activate `FUN_004b8dc0(1,0)` → object vtbl `+0xF8`; rare overlay before primary when present.

5. **Audio:** `Client_GetMissionCompleteAudioTable()+600` **and** `bPlayAudio` → `FUN_004b7e50`.

6. **Paint path:** when `def+0x3F4==8`, paint-id `this+0xC8` via `FUN_00519d20`, RGB × **≈1/255** (`DAT_00aaa7a8`), MatAmbient/Diffuse/Emissive + `FUN_0096f660`.

7. **Callers:** `CLoadNode__initSelection` `(1,0)`; `FUN_00585e00` distance/flag.

8. **Name:** `Object_PlayPickupSpecialFX` — domain **High** (strings); product C++ spelling **Open**. Ghidra: `FUN_0051aed0`.

### Gaps

1. Product class/method plate string.  
2. Exact English for vtbl `+0x1CC` / `+0x60` / `+0xF8`.  
3. Full def short taxonomy beyond branch labels.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| Function record | `docs/reconstruction/functions/aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_PlayPickupSpecialFX.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0051aed0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.annotated.md` |

---

## `aa_005d7f70` — CVOGHBAICreatureBase_DoLogic

### Sealed facts

1. **Body:** `0x005d7f70`–`0x005d8328`.

2. **ABI:** **thiscall** (ECX=this → ESI); bare **`ret`**; void.

3. **Class:** **CVOGHBAICreatureBase** — DATA vtbl slot `0x009db19c`; adjacent `0x009db194` = string-sealed `CVOGHBAICreatureBase_DecideHeading`.

4. **Role:** Creature combat tick twin of `CVOGHBAIDriver_DoLogic` (`0x005d7750`, plate string). Same `owner+0x26c` idle/engage/combat family; **no** FireWeapons tail; combat pursue = `DoCreaturePursue` (`FUN_005cf560`).

5. **Profile:** float key from def `+0x4DC` → `FUN_00540890`/`FUN_004cbd50` lower_bound; end-iterator → return.

6. **Skill sets:** idle 0 / engage 1 / combat 2 via `NPC_TryCastSkillFromSet`; slot 0 via `AI_CheckSlotTimerReady`.

7. **Constants:** `DAT_00aaa638` ≈1/65536; `_DAT_00aaa5dc` = 2^32.

8. **Name:** `CVOGHBAICreatureBase_DoLogic` — class **High**; method English **Probable** (no local plate). Ghidra: `FUN_005d7f70`.

### Gaps

1. In-body product plate for method name.  
2. Profile payload field English `[5]..[11]`.  
3. Shared path-helper product names (`FUN_005cedf0` family) — not sole ownership.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| Function record | `docs/reconstruction/functions/aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoLogic.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005d7f70.cpp` |
| Raw | `docs/reconstruction/raw/aa_005d7f70_FUN_005d7f70.md` |
| Annotated | `docs/reconstruction/raw/aa_005d7f70_FUN_005d7f70.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Pickup FX (`0x0051aed0`)

- Client-only cosmetics: do not gate server item grants on these scripts.
- Preserve product script spellings (including `generic_pickup_commidity`).
- Selection load path always requests audio-capable flag `(1,0)`.

### Creature DoLogic (`0x005d7f70`)

- Port as **virtual creature AI tick**, not driver.
- Keep profile-miss silent return and state byte `owner+0x26c` shared with Driver duals.
- Skill-set indices 0/1/2 must stay aligned with `NPC_TryCastSkillFromSet` banks.

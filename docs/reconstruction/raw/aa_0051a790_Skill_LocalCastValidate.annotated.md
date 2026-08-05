# Annotated low-level: Skill_LocalCastValidate (`aa_0051a790`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **VA** | `0x0051a790` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_0051a790_Skill_LocalCastValidate.md` (capture 2026-07-23) |
| **Related** | `Skill_FormatFailureMessage` (`0x0054fa20`), callers `Client_RequestCastSkill` / `Client_QuickBarActivateSkillSlot` |

This file is the **annotated** layer: widths, branch order, return codes, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = caster character/entity
// Decompiler mis-types skill as `char` and scrambles plate param names.
int __thiscall Skill_LocalCastValidate(
    CharacterEntity* this,   // ECX — local player / caster entity
    int skipBusyCheck,       // stack — nonzero skips busy/active-cast gate
    SkillRuntime* pSkill,    // stack — skill runtime (nullable for lightweight path)
    void* unusedOrTail);     // often 0 at known call sites
// returns eSkillResponses (u32/int; small integer codes)
```

| Name | Width | Origin | Role |
|---|---|---|---|
| `this` | 32-bit ptr | `ECX` | Caster entity (character) |
| `skipBusyCheck` | 32-bit / low byte used as bool | stack | When **0**, run busy gate; when nonzero, skip |
| `pSkill` | 32-bit ptr | stack | Skill runtime; null → early OK after light gates |
| return | 32-bit int | `EAX` | `eSkillResponses` |

**Call-site pattern (Confirmed):** both `Client_RequestCastSkill` and `Client_QuickBarActivateSkillSlot` pass:

```text
Skill_LocalCastValidate(character, 0, pSkillRuntime, 0)
```

i.e. busy check **enabled**, skill pointer in the third slot, fourth null.

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| Signature `(this, pCaster, bSkipBusyCheck, pSkill)` with `bSkipBusyCheck` as `char` | Third arg is **`SkillRuntime*`**; used with `+0x5fc`, `+0x614`, `+0x615`, `+0x628`, `+0x5e8`, `+8` | **High** |
| Plate names `pCaster` / `bSkipBusyCheck` swapped vs body | Body treats 2nd arg as bool skip-busy; 3rd as skill (`_bSkipBusyCheck` rename is inverted) | **High** |
| `(char)pCaster == '\0'` | Low-byte test of skip-busy flag (0 → do busy checks) | **High** |
| `return 4/5/6/7/10/0xb/0xc/...` | `eSkillResponses`; UX strings **Confirmed** via `Skill_FormatFailureMessage` raw switch (residual 2026-07-29) | **High** for 0,3–7,10–12 |
| `*(short*)(iVar2 + 300)` | Offset **0x12C** (decimal 300) — power/mana current on combat-pool object | **High** |
| `unaff_retaddr` into `Skill_LocalRangeTargetCheck` | Decompiler stack pollution; real 4th arg needs assembly/call-site check | **Open** |

---

## 3. Control flow (ordered gates G0–G9)

Early-exit order is load-bearing. Residual gate-ladder strengthen 2026-07-29.

```text
G0. if (this+0xb4 & 0x02) → return 5                    // status suppress
G1. if (vtbl+0x198()) {                                  // vehicle-like? Probable
      plant = vtbl+0x210(0)
      if plant==0 or plant+0x6b4 < 1 → return 3          // wrecked toast (plant gate)
    }
G2. if (!skipBusyCheck) {
      if (this+0xb4 & 0x08) and worldType(+0xa8)+0x38==0x14 → return 5
      if FUN_005169c0()->+0x10 != 0 → return 6           // busy (leave-FUN)
    }
G3. if (pSkill == NULL) → return 0                       // lightweight OK
G4. LookupActiveCastBinding(skill+0x5fc)
    if binding TFID ≠ invalid → return 0                 // occupied bind skips deep
    // free bind → deep skill checks:
G5. power: plant!=0 && plant+0x6b4 < 1 && plant+0x12C < pSkill+0x8 → return 4
      (NOTE: **if +0x6b4 >= 1, low power does NOT reject here**)
G6. casting flag pSkill+0x628 or category CD remaining ≠ 0 → return 7
G7. (no plant) && (FUN_00518c20()+8≠0) && (pSkill+0x615 & 2) → return 10  // prevent
G8. hide/related via vtbl+0x19c:
      formFlag @ related layout +0x29; skill+0x615 bit 0x40; skill+0x614 bit 0x4000
      → 0xC (12) can't-while-hidden / 0xB (11) must-be-hidden
      / else Skill_LocalRangeTargetCheck → that code (may be 0/0xf/13/14)
G9. return 0
```

| Code | FormatFailureMessage string | Confidence |
|---:|---|---|
| `0` | OK (no toast) | **High** |
| `3` | Cannot do that while wrecked! (body: plant/`+0x6b4`) | **High** string; gate gloss Probable |
| `4` | You don't have enough power! | **High** |
| `5` | You can't do that with your current status. | **High** |
| `6` | You're already actively using a skill! | **High** |
| `7` | This skill is not ready to use again yet! | **High** |
| `10` | You have an active skill that prevents you from doing that. | **High** |
| `11` | You must be hidden to use this. | **High** |
| `12` | You can't do this while hidden. | **High** |
| 13/14/15 | range / wrong target / accuracy — **not literals in this body** | downstream |

---

## 4. Side-effect order

1. **Reads only** on early reject paths (flags, vtable queries, busy helper).
2. When `pSkill != NULL`: **call** `Skill_LookupActiveCastBinding` (stack TFID out-param).
3. **call** `TFID_NotEquals` vs `g_abTfidInvalid_9CDF88`.
4. On deep path: optional `Skill_GetCategoryCooldownRemaining` (x87 `ST0` vs `g_flZero`).
5. Optional `Skill_LocalRangeTargetCheck` — final return may be range/target code.
6. **No stores** to skill or character observed in this function body.

**No network I/O** here; pure local pre-cast gate.

---

## 5. Field map (touched)

| Offset | Object | Type | Role |
|---|---|---|---|
| `this+0xb4` | character | u8 flags | bit1 → code 5; bit3 + world type → code 5 |
| `this+0xa8` → `+0x38` | world/map link | i32 type | `0x14` special reject with flag 8 |
| vtbl `+0x198` | character | bool method | vehicle/body presence **Probable** |
| vtbl `+0x210` | character | ptr method | combat pool / vehicle combat object |
| pool `+0x6b4` | combat pool | i32 | must be ≥ 1 when present |
| pool `+0x12C` (300) | combat pool | i16 | current power vs skill cost |
| vtbl `+0x19c` | character | ptr method | seat/mount object **Probable** |
| `pSkill+0x5fc` | skill | i32 | skill id (cast binding key) |
| `pSkill+0x8` | skill | i16 | power cost (compared to pool) |
| `pSkill+0x5e8` | skill | ptr | category cooldown map key |
| `pSkill+0x614` | skill | u32 flags | bit `0x4000` seat/cast mode |
| `pSkill+0x615` | skill | u8 flags | bits `0x02`, `0x40` |
| `pSkill+0x628` | skill | u8 | is-casting (`Skill_SetIsCastingFlag`) |

---

## 6. Call-site context

| Caller | VA | Notes |
|---|---|---|
| `Client_RequestCastSkill` | `0x00941590` | On nonzero → `Skill_FormatFailureMessage` + UI toast |
| `Client_QuickBarActivateSkillSlot` | `0x00921b50` | Cast packet only if return `0` |

---

## 7. Open questions

- Product field name for `plant+0x6b4` (UX “wrecked” is G1 toast only; not a sealed gate name).
- Skill flag product enum bits (`0x4000`, `0x40`, `0x02`).
- Full signature of `Skill_LocalRangeTargetCheck` (4th arg polluted).
- Whether vtbl `+0x198` / `+0x210` / `+0x19c` map 1:1 to known entity methods in TYPE_REGISTRY.
- Product rationale for occupied active-cast binding → allow 0.
- Runtime deny-code capture matrix.

**Sealed (residual 2026-07-29):** UX strings for codes 3/5/10/11/12 via FormatFailureMessage; ordered ladder G0–G9; leave-FUN helpers; TFID free-bind polarity.

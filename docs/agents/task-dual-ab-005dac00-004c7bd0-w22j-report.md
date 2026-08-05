# Dual A/B report — W22-J OWN `aa_005dac00` + `aa_004c7bd0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-J  
**Scope:** VAs `0x005dac00`, `0x004c7bd0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + `audit_globals_in_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005dac00` CVOGHBRecreateObject_RecreateOwner_Inferred | **accept-with-gaps** — HB this + dual RTTI + flag clear + zero impulse + soft type sealed; vfunc English open |
| `aa_004c7bd0` CVOGCreature_SlewFacingYaw_Inferred | **accept-with-gaps** — XZ slew + rate `(1-align)*ms*0.001*9.6` + 2π wrap + `+0x11c` write sealed; acos-arg/aim English open |

---

## VA `0x005dac00` — sealed facts

1. **Body:** `0x005dac00`–`0x005dae45` (582 B, inclusive plain `RET`).
2. **ABI:** `__thiscall`; ECX = `CVOGHBBase*` / `CVOGHBRecreateObject*`; void; plain `RET`.
3. **Owner:** `*(this+0x18)`; require non-null.
4. **Gates:** `dynamic_cast<CVOGPhysicsBase*>`; require `phys[2] != 0` body host; also cast `CVOGGraphicsBase*`.
5. **Soft flag:** `*(byte*)(layout+0x181) &= ~1`.
6. **Soft body type:** if `FUN_00418d10()==0` → `FUN_0053d970(0)` (sibling: flag0 → type 1).
7. **Impulse:** `CVOGPhysics_ApplyImpulseVector(&DAT_00bc5670)` + `FUN_0040d040` on **zero** BSS vector.
8. **Type filter:** if linked type `+0x38` ∉ `{0x12, 0x14}` → `FUN_00516a00(1)`.
9. **Tail:** `FUN_004cd540(phys_base, 1)`.
10. **Callers (2):** `CVOGHBRecreateObject_OnHeartBeat` @ `0x005dafba`; `FUN_004cd4e0` @ `0x004cd50c`.
11. **Name:** `CVOGHBRecreateObject_RecreateOwner_Inferred` (Ghidra `FUN_005dac00`). Former Reaction-spawn scaffold chain **misleading**.

### Gaps

- Product English for graphics/physics vfuncs, `FUN_004cd540`, `FUN_00516a00`.  
- Runtime recreate differential.  
- PDB / retail name.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005dac00_FUN_005dac00.md` |
| Annotated | `docs/reconstruction/raw/aa_005dac00_FUN_005dac00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBRecreateObject_RecreateOwner_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005dac00.cpp` |
| Function | `docs/reconstruction/functions/aa_005dac00_FUN_005dac00.md` |
| Function named | `docs/reconstruction/functions/aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005dac00.md` |

---

## VA `0x004c7bd0` — sealed facts

1. **Body:** `0x004c7bd0`–`0x004c7fc1` (1010 B, inclusive `RET 4`).
2. **ABI:** `__thiscall`; ECX = creature/object*; stack `int deltaMs`; **`RET 4`**; void.
3. **Gates:** `*(this+8) != 0`; `_finite(pose.x)`; horizontal dist `> 1.192e-7f`; align `< 0.999`.
4. **Algorithm:** unit XZ dir (Y forced 0) → `Math_AcosClamped` → basis extract → optional `2π−ang` → combine with yaw → sin/cos → alignment → rate step → wrap → store.
5. **Rate:** `(1 - align) * u32_as_float(deltaMs) * 0.001f * 9.6f` (`g_flMsToSeconds_Inferred` × `DAT_009cbab0`).
6. **Wrap:** `DAT_00aaa7dc ≈ 6.283185f` (`2π`).
7. **Write:** only `*(float*)(this+0x11c)`.
8. **Callers (3):** `CVOGCreature_SetupGraphics` @ `0x004c8e49`; `FUN_005d6b80` @ `0x005d6bf7`; `FUN_005d6c10` @ `0x005d6c21`.
9. **Name:** `CVOGCreature_SlewFacingYaw_Inferred` (Ghidra `FUN_004c7bd0`).

### Constants (`read_memory`)

| Symbol | VA | Value |
|---|---|---|
| `DAT_009cb8d4` | `0x009cb8d4` | `1.1920929e-7f` |
| `DAT_00aaa7dc` | `0x00aaa7dc` | `≈6.283185f` |
| `DAT_009cbab0` | `0x009cbab0` | `9.6f` |
| `DAT_009cbab8` | `0x009cbab8` | double `0.999` |
| `g_flMsToSeconds_Inferred` | `0x00a0f72c` | `≈0.001f` |
| `DAT_00aaa5dc` | `0x00aaa5dc` | `4294967296.0f` |
| `g_flOne` | `0x00a0f2a0` | `1.0f` |

### Gaps

- Exact float formal into `Math_AcosClamped` (decompiler elides).  
- Free-aim / camera-slot product English.  
- Runtime yaw differential; PDB name; HB pair product names.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c7bd0_FUN_004c7bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c7bd0_FUN_004c7bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_SlewFacingYaw_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c7bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_004c7bd0_FUN_004c7bd0.md` |
| Function named | `docs/reconstruction/functions/aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c7bd0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005dac00` | Recreate HB owner rebind — implement dual RTTI gates, soft flag clear, **zero** impulse, soft type request via sibling `0053d970(0)`, type 0x12/0x14 skip. Do not invent spawn-factory or non-zero kick. |
| `004c7bd0` | Creature facing yaw — XZ-only slew to `+0x11c` with rate `(1-align)*ms*0.001*9.6` and 2π wrap; do not snap, do not pitch, `RET 4` ABI. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / callers / globals audit).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold `Named_CalleeOf_*` names superseded by structural `_Inferred` names above.

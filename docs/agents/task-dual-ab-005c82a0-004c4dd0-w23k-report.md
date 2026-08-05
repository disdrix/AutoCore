# Dual A/B report — W23-K OWN `aa_005c82a0` + `aa_004c4dd0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-K  
**Scope:** VAs `0x005c82a0`, `0x004c4dd0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005c82a0` Object_EntityMidBase_Ctor | **accept-with-gaps** — ABI/CF/vtbl/fields/callers sealed; product class English open |
| `aa_004c4dd0` Combat_ComputeBaseCritChance_FromHost | **accept** — formula + ABI + constants + UI label sealed |

---

## VA `0x005c82a0` — sealed facts

1. **Body:** `0x005c82a0`–`0x005c83a1` (257 B; `RET 0x4`).
2. **ABI:** **ECX**=this*; stack `mostDerivedFlag`; **EAX**=this.
3. **Semantics:** Entity mid-base ctor shared by **CVOGCreature** and **Vehicle** (`0x00501970`).
4. **mostDerived:** vb cookies + `Object_SharedBase_Ctor` at **`this+0x110`**.
5. **Always:** parent `FUN_005d4830(0)`; vtbls `PTR_FUN_009da70c` / `PTR_FUN_009da6d0`; vb adjustor **`-0x10c`**; defaults `+0xD0..+0xF8` incl. **500** @ `+0xE4`.
6. **Callers (6):** Creature, Vehicle, `FUN_00588dc0`, GiveItemByCbid, `0051ea10`, `0051ef40`.
7. **Name:** `Object_EntityMidBase_Ctor` (Ghidra `FUN_005c82a0`).
8. **Decompile ≡ bytes** for CF.

### Gaps

- Product C++ class English (no RTTI this pass).  
- Field dictionary English (`+0xE4=500` meaning).  
- Parent `FUN_005d4830` layout residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005c82a0_Object_EntityMidBase_Ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005c82a0_Object_EntityMidBase_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005c82a0_FUN_005c82a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005c82a0_FUN_005c82a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EntityMidBase_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005c82a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005c82a0_FUN_005c82a0.md` |
| Function named | `docs/reconstruction/functions/aa_005c82a0_Object_EntityMidBase_Ctor.md` |
| Scratch | `docs/reconstruction/tmp/a_005c82a0.md` |

---

## VA `0x004c4dd0` — sealed facts

1. **Body:** `0x004c4dd0`–`0x004c4e1d` (77 B; no stack formals; **ST0** return).
2. **ABI:** **ECX**=host*; float **ST0**.
3. **Formula:** `(FUN_004c41c0(host) + vcall(+0x27c)) * 0.001f * 0.125f + 0.02f`.
4. **Constants:** `0x00a0f72c`=0.001, `0x00a110c0`=0.125, `0x00aaa7b8`=0.02 (`read_memory`).
5. **Callers (2):** `Combat_ComputeCritChance_Inferred` (bind path); `FUN_008f97c0` UI **"Base Critical Hit Chance"**.
6. **Name:** `Combat_ComputeBaseCritChance_FromHost` (Ghidra `FUN_004c4dd0`).
7. **Sibling no-bind:** `level*0.001*0.25+0.05` in parent — different scale/base.
8. **Decompile ≡ bytes** for CF/FPU order.

### Gaps

- Host product type from `vtbl+0x214`.  
- Full `FUN_004c41c0` / `+0x27c` English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c4dd0_FUN_004c4dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4dd0_FUN_004c4dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Combat_ComputeBaseCritChance_FromHost.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4dd0.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4dd0_FUN_004c4dd0.md` |
| Function named | `docs/reconstruction/functions/aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md` |
| Scratch | `docs/reconstruction/tmp/a_004c4dd0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005c82a0` | Creature/Vehicle mid-base layout: SharedBase embed **+0x110**, vb adjustor **-0x10c**, default **500** at **+0xE4**; keep mostDerived dual-base path. |
| `004c4dd0` | Bind-path base crit must use **0.125/0.02**, not no-bind **0.25/0.05**; inputs = perception score + level vcall. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.

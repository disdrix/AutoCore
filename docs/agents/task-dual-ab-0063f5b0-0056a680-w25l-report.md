# OWN-ONLY dual agent report — W25-L

**Date:** 2026-07-29  
**Agent:** W25-L OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0063f5b0`, `0x0056a680`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0063f5b0` EmptyBase_Ctor_ReturnThis_Inferred | **accept-with-gaps** — **12 B thiscall; call identity `FUN_005edf20`; return this; no field stores; product class open** |
| `aa_0056a680` Item_GetCycleTimeMs_Scaled_Inferred | **accept-with-gaps** — **thiscall cycle ms @ +0xD0; optional scale via related+0xB0 / vtbl+0x214 / +0x1E8; floor 500; DPS/tac-arc use sealed; product English open** |

---

## `aa_0063f5b0` — EmptyBase_Ctor_ReturnThis_Inferred

### Sealed facts

1. **Body:** `0x0063f5b0`–`0x0063f5bb` (Ghidra). Wrapper classification.

2. **ABI:** **thiscall** (ECX=this); bare **`ret`**; **EAX=this**.

3. **Callee:** `FUN_005edf20` @ `0x005edf20` body `8B C1 C3` — pure identity.

4. **Bytes:** `56 8B F1 E8 68 E9 FA FF 8B C6 5E C3`.

5. **Callers (8):** small POD/component ctors chain this first then write fields (`FUN_005d6720`, `FUN_0064dda0`, `FUN_005fe5c0`, …).

6. **Name:** `EmptyBase_Ctor_ReturnThis_Inferred` — role sealed **INFERRED**. Ghidra: `FUN_0063f5b0`.

### Gaps

1. Product C++ base class name.  
2. Historical purpose of identity call.  
3. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0063f5b0_EmptyBase_Ctor_ReturnThis_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0063f5b0_EmptyBase_Ctor_ReturnThis_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0063f5b0_EmptyBase_Ctor_ReturnThis_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EmptyBase_Ctor_ReturnThis_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0063f5b0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0063f5b0_FUN_0063f5b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0063f5b0_FUN_0063f5b0.annotated.md` |

---

## `aa_0056a680` — Item_GetCycleTimeMs_Scaled_Inferred

### Sealed facts

1. **Body:** `0x0056a680`–`0x0056a765` (~0xE5 B).

2. **ABI:** **thiscall**; stack **`char bSkipScale`**; **`ret 4`**; **EAX = int ms**.

3. **Base field:** `this+0xD0` (setter sibling `FUN_0056a1b0`, min 1).

4. **Scale path:** related `*(this + adj + 0xB0)` → `vtbl+0x214` → float `blob+0x1E8`; skip if == `g_flOne` (`0x00a0f2a0` = 1.0f).

5. **Round / floor:** bias `0x00aaa6d0` ≈ 0.5001f; if scaled trunc ≤ **500** return 500; else `FUN_0040dab0(product)`.

6. **Use:** TacArc timing; weapon UI **DPS** (`dmg / (ms * ms→sec)`); tooltips; HB ctor stores result.

7. **Name:** `Item_GetCycleTimeMs_Scaled_Inferred` (role High / product **Inferred**). Ghidra: `FUN_0056a680`.

### Gaps

1. Product type English for this / related / scale blob.  
2. Designer name for 500 ms constant.  
3. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_GetCycleTimeMs_Scaled_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0056a680.cpp` |
| Raw | `docs/reconstruction/raw/aa_0056a680_FUN_0056a680.md` |
| Annotated | `docs/reconstruction/raw/aa_0056a680_FUN_0056a680.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Empty base ctor (`0x0063f5b0`)

- Port as **return-this no-op base**; do not invent field zeroing in this unit.
- Child ctors own subsequent stores.

### Cycle time getter (`0x0056a680`)

- Server/client weapon DPS and fire cadence must use **integer ms** at `+0xD0` with optional owner scale and **500 ms floor on non-identity scale only**.
- Round with shared **±0.5001** bias (`FUN_0040dab0` semantics).
- `bSkipScale != 0` forces raw base (no scale, no 500 floor).

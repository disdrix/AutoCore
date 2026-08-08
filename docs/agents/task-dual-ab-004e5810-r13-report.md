# Dual A/B report — R13-026 OWN-ONLY (`0x004e5810`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-026**  
**Scope:** VA `0x004e5810` (`aa_004e5810`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent craft gate `0052eb90` re-dual, copy worker `004e53e0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-026**.  
**System:** inventory-transfer (partition assignment; unit role is object TFID-vector materialize at `+0xe7f8`).  
**Parent dual:** `0x0052eb90` Character_Craft_HasMatchingStationInRange_Inferred (R12-021).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e5810` Object_CopyTfidVectorAtE7f8_Inferred | **accept-with-gaps** — wrapper CF/ABI/RET4/`+0xe7f8`/callee sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission Named_CalleeOf / grid place / count-only / source-mutate / in-body resolve / cdecl / product-English claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004e5810` — sealed facts

1. **Body:** `0x004e5810`–`0x004e5833` exclusive (**35 B** / `0x23`); terminal **`C2 04 00`**; pad `CC`.
2. **ABI:** **`__thiscall`** ECX=`Object*`; stack `VectorU64Shell* out`; returns `out` in EAX; **`ret 4`**.
3. **Semantics:** thin **offset-binding wrapper**:
   - `src = this + 0xe7f8`
   - `FUN_004e53e0(out, src)` — MSVC-style `std::vector` copy-construct for **8-byte** elements (TFID pairs)
   - return `out`
4. **Layout (via callee + callers):** shell begin@+4, end@+8, capacity@+0xc; count `(end-begin)>>3`.
5. **Callees:** `FUN_004e53e0` only.
6. **Callers (2 funcs / 4 sites):**
   - `FUN_0052eb90` @ `0x0052ec12`, `0x0052ec6b` (parent craft station range gate)
   - `FUN_004dd940` @ `0x004ddb67`, `0x004ddbb7` (station subtype `0xD/0xE/0xF` walk)
7. **Xrefs:** 4 UNCONDITIONAL_CALL (same).
8. **Name:** `Object_CopyTfidVectorAtE7f8_Inferred` (Ghidra `FUN_004e5810`). Product demangle open → `_Inferred`.
9. **Classification:** wrapper (`analyze_function_complete`).
10. **Decompile ≡ raw CF**; assembly seals dest-this swap decompiler elides; full hex via `read_memory`.

### Gaps

- Product English for object member `+0xe7f8`.  
- Dual of copy worker `FUN_004e53e0` / pod copy `FUN_006a2be0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004e5810_FUN_004e5810.md` |
| Annotated | `docs/reconstruction/raw/aa_004e5810_FUN_004e5810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CopyTfidVectorAtE7f8_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e5810.cpp` |
| Function | `docs/reconstruction/functions/aa_004e5810_FUN_004e5810.md` |
| Function named | `docs/reconstruction/functions/aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Character_Craft_HasMatchingStationInRange_Inferred (0x0052eb90)  [parent dual R12-021]
  └─ Object_CopyTfidVectorAtE7f8_Inferred (0x004e5810)  [OWN R13-026]  ×2 (count + index)
       └─ FUN_004e53e0  vector copy-construct elem8  [residual]
            └─ FUN_006a2be0  pod copy / FUN_00418130 length_error  [residual]
  └─ ResolveObjectTarget via object+0xe4e8; SurfaceDistance3D; subtype flags

FUN_004dd940  station subtype TFID walk  [residual]
  └─ Object_CopyTfidVectorAtE7f8_Inferred (0x004e5810)  ×2
       └─ ResolveObjectTarget; subtype 0xD/0xE/0xF → FUN_004db740
```

Partition system **inventory-transfer** matches craft/station TFID consumers; the unit itself is a generic object-member vector materialize, not a grid place/find helper.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004e5810-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e5810` | Port as **object thiscall** that **copy-constructs** a temp TFID-pair vector from **`this+0xe7f8`** into caller shell; **returns shell**; **ret 4**. Elem stride **8**. |
| Pair with | dualed craft gate `0052eb90`; residual copy worker `004e53e0`; residual station walk `004dd940`. |
| Naming caution | **Not** mission-UI Named_CalleeOf. **Not** inventory grid place/find. **Not** TFID resolve/walk (callers). **Not** product-English without `_Inferred`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (TFID vector materialize @ object+0xe7f8)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004e5810`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (thiscall RET 4; dest-this before CALL).  
- Odd behavior preserved: spill `MOV [ESP+8],0` after ADD (dead store).  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

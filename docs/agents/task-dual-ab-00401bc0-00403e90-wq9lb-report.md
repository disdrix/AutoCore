# Dual A/B report — WQ9L-B OWN-ONLY (`0x00401bc0`, `0x00403e90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-B**  
**Scope:** VAs `0x00401bc0`, `0x00403e90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context` + `search_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 depth-8 residual dual seal — callees of dualed **StdTree_EraseAndRebalance_Isnil31** (`0x00408ed0`): **out_of_range ctor** + **Lrotate isnil31**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401bc0` Std_OutOfRange_CtorFromString | **accept** — CF/ABI/RET4/RTTI/ThrowInfo/shared erase throw path sealed |
| `aa_00403e90` StdTree_Lrotate_Isnil31_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil31/ECX-node/5 call sites sealed; product map open |

Path A (fidelity): `00401bc0` **accept**; `00403e90` **accept-with-gaps**.  
Path B (adversarial): skill-misname / length_error-merge / right-rotate / isnil29-2D-merge / ECX=tree / thiscall-throw claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401bc0` — sealed facts

1. **Body:** `0x00401bc0`–`0x00401c10` inclusive (**81 B** / `0x51`).
2. **ABI:** **ECX** = this; stack `const string*`; **EAX** = this; **`RET 4`**.
3. **Semantics:** `std::out_of_range` from-string ctor:
   - SEH frame (`LAB_009bc828` / FS:[0]).
   - Base `logic_error` via `FUN_00401aa0` (string @ `this+0x0c`, vtbl `009c7628`).
   - Install derived vtbl `PTR_FUN_009c7640`.
   - Does **not** throw; parents `_CxxThrowException(..., DAT_00acc34c)`.
4. **RTTI:** `.?AVout_of_range@std@@` @ `0x00af8b98`; CatchableType size **0x28**.
5. **Callees:** `FUN_00401aa0` only.
6. **Callers:** **25** UNCONDITIONAL_CALL; sample dualed erase isnil31 @ `0x00408f17` with `"invalid map/set<T> iterator"` @ `0x00a152f0`.
7. **Twin:** dualed `Std_LengthError_CtorFromString` `0x00401a40` (vtbl `009c7634`, ThrowInfo `acc388`).
8. **Name:** `Std_OutOfRange_CtorFromString` (Ghidra `FUN_00401bc0`). Product demangle sealed.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Full vtable method English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401bc0_Std_OutOfRange_CtorFromString.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00401bc0_Std_OutOfRange_CtorFromString.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401bc0_FUN_00401bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00401bc0_FUN_00401bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Std_OutOfRange_CtorFromString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401bc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00401bc0_FUN_00401bc0.md` |
| Function named | `docs/reconstruction/functions/aa_00401bc0_Std_OutOfRange_CtorFromString.md` |

---

## VA `0x00403e90` — sealed facts

1. **Body:** `0x00403e90`–`0x00403edb` inclusive (**76 B** / `0x4C`); pad `CC` before Rrotate twin `0x00403ee0`.
2. **ABI:** **ECX** = node X; stack map\*; void; **`RET 4`** ×3 exits.
3. **Semantics:** classic **left rotate** (isnil@**+0x31**):
   - `Y = X.right`; rewire Y.left parent if non-nil; reparent via root/left/right cases; `Y.left = X`.
   - No color stores; no callees (leaf).
4. **Callers (5):** erase isnil31 `FUN_00408ed0` @ `0x00409062` / `0x004090ab` / `0x00409107`; insert peer `FUN_00403250` @ `0x0040334a` / `0x00403396`.
5. **Xrefs:** 5 UNCONDITIONAL_CALL.
6. **Callees:** none.
7. **Name:** `StdTree_Lrotate_Isnil31_Inferred` (Ghidra `FUN_00403e90`). Product map open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product map/key English for isnil31 (0x38) family.  
- Rrotate twin `00403ee0` residual (WQ9L-C OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00403e90_FUN_00403e90.md` |
| Annotated | `docs/reconstruction/raw/aa_00403e90_FUN_00403e90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403e90.cpp` |
| Function | `docs/reconstruction/functions/aa_00403e90_FUN_00403e90.md` |
| Function named | `docs/reconstruction/functions/aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred  [dualed WQ9K-E]
  ├─ nil iterator:
  │     string("invalid map/set<T> iterator")
  │     FUN_00401bc0  Std_OutOfRange_CtorFromString  [OWN WQ9L-B]
  │     _CxxThrowException(..., DAT_00acc34c)
  ├─ FUN_00408590  IteratorIncrement isnil31  [dualed]
  ├─ FUN_00409160  Min isnil31  [dualed]
  ├─ FUN_004043e0  Max  [residual]
  ├─ FUN_00403e90  StdTree_Lrotate_Isnil31_Inferred  [OWN WQ9L-B]
  ├─ FUN_00403ee0  Rrotate isnil31  [residual WQ9L-C]
  └─ operator_delete

FUN_00403250  insert/rebalance isnil31 peer  [residual]
  └─ FUN_00403e90  (shared Lrot)  [OWN WQ9L-B]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401bc0-00403e90-wq9lb-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401bc0` | Port as **`std::out_of_range` from-string ctor**. **thiscall RET 4**. Pair with ThrowInfo `DAT_00acc34c` / message `"invalid map/set<T> iterator"`. Do **not** throw inside the ctor. Keep distinct from length_error ctor `00401a40`. |
| `00403e90` | Port as **left-rotate leaf** for isnil@**+0x31** nodes (size 0x38). **ECX=node**, stack=map, **RET 4**. No color mutation here. Keep distinct from Rrotate `00403ee0` and isnil29/isnil2D rotates. |
| Pair with | dualed erase isnil31 `00408ed0`; dualed length_error twin `00401a40`; residual Rrotate `00403ee0`; residual Max `004043e0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL exception + tree rotate — not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00401bc0`, `0x00403e90`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + RTTI strings. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; machine ABI corrections (thiscall RET 4; ECX=node for Lrot).  
- Odd behavior preserved: ctor does not throw; Lrot has no color writes; decompiler parent this/arg inversion corrected via assembly.  
- `_Inferred` where English unproven (`00403e90`); product demangle sealed for `00401bc0`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

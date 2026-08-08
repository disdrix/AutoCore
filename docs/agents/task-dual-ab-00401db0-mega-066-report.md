# Dual A/B report — MEGA-066 OWN-ONLY (`0x00401db0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-066**  
**Scope:** VA `0x00401db0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Mission null dialog nested → **isnil2D tree insert+rebalance**.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` row MEGA-066.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401db0` StdTree_InsertAndRebalance_Isnil2D_Inferred | **accept-with-gaps** — CF/ABI/RET0C/EDI-map/ECX-where/isnil2D/color2C/max-size/throw/2 call sites sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-dialog product / isnil29-merge / thiscall-ECX=map / insert-or-find-self claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401db0` — sealed facts

1. **Body:** `0x00401db0`–`0x00401f31` exclusive (**385 B** / `0x181`).
2. **ABI:** **EDI** = map shell*; **ECX** = where node*; stack `Node** out`, `char addLeft`, `value*`; void; **`RET 0x0C`** (`C2 0C 00`).
3. **Semantics:** MSVC `_Tree` **always-insert + RB rebalance** (isnil@**+0x2D**):
   - SEH frame (`LAB_009bc919` / FS:[0]).
   - Size gate: throw if `size > 0x7FFFFFD` via `"map/set<T> too long"` + `Std_LengthError_CtorFromString` (`FUN_00401a40`) + `_CxxThrowException(..., DAT_00acc388)`.
   - Buynode `FUN_00401f40` → `operator_new(0x30)` + `FUN_00401fe0` (string @+0x0C, color@+0x2C, isnil=0 @+0x2D).
   - Link empty / left / right + head extremum updates; size++.
   - RB while parent color red; L/R rotates; root blackened; `*out = n`.
4. **Layout:** node **0x30**; color@**+0x2C**; isnil@**+0x2D**; string key @**+0x0C**.
5. **Callees:** `FUN_00401f40`, `FUN_0044e010` (`StdTree_LeftRotate_Isnil2D_Inferred`), `FUN_0042a840` (`StdTree_Rrotate_Isnil2D_Inferred`), `FUN_00401a40`, string ctor, `_CxxThrowException`.
6. **Callers:** **1** function / **2** UNCONDITIONAL_CALL — `FUN_00401c50` @ `0x00401cb6`, `0x00401cfe` (string-key insert-or-find).
7. **Clone peer:** dualed `StdMap_StringKey_InsertNodeAndRebalance` `0x00430b60` (same ABI/threshold/rotates; different buynode).
8. **Name:** `StdTree_InsertAndRebalance_Isnil2D_Inferred` (Ghidra `FUN_00401db0`). Product demangle open → `_Inferred`. Retire `Named_CalleeOf_*Mission*null*dialog*`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Decompiler `unaff_EDI` / false thiscall-on-map corrected.

### Gaps

- Product/PDB English for this instantiation.  
- Mapped-value residual beyond string @+0x0C (peer u32 @+0x28).  
- Parent `00401c50` / buynode `00401f40` residual duals.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401db0_FUN_00401db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00401db0_FUN_00401db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401db0.cpp` |
| Function | `docs/reconstruction/functions/aa_00401db0_FUN_00401db0.md` |
| Function named | `docs/reconstruction/functions/aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00401c50  string-key insert-or-find (isnil@+0x2D walk; residual)
  ├─ std::operator< (basic_string @ node+0x0C)
  └─ FUN_00401db0  StdTree_InsertAndRebalance_Isnil2D_Inferred  [OWN MEGA-066]
        ├─ FUN_00401f40  buynode 0x30  [residual]
        │     └─ FUN_00401fe0  node ctor (string@+0x0C, color@+0x2C, isnil@+0x2D)
        ├─ FUN_0044e010  StdTree_LeftRotate_Isnil2D_Inferred  [dualed]
        ├─ FUN_0042a840  StdTree_Rrotate_Isnil2D_Inferred  [dualed]
        └─ FUN_00401a40  Std_LengthError_CtorFromString  [dualed]
              └─ _CxxThrowException(..., DAT_00acc388)

Clone peer (not OWN):
  0x00430b60  StdMap_StringKey_InsertNodeAndRebalance  [dualed W22-E]
    same EDI/ECX/RET0C/threshold/rotates; buynode FUN_0042a890
```

Partition parent hint: "null dialog chain" / "Mission null dialog nested" — **call-chain only**; no mission/dialog semantics in this body.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401db0-mega-066-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401db0` | Port as **always-insert + RB rebalance** for isnil@**+0x2D** nodes (size 0x30). **EDI=map**, **ECX=where**, stack out/addLeft/value, **RET 0x0C**. Max size **0x7FFFFFD**. Pair with dualed L/R rotates `0044e010`/`0042a840` and length_error `00401a40`. Do **not** treat as thiscall-on-map (unlike isnil29 insert `00406c40`). Keep distinct from clone `00430b60` and isnil29/isnil31 families. |
| Pair with | dualed rotates isnil2D; dualed length_error ctor; residual parent `00401c50`; residual buynode `00401f40`; dualed clone `00430b60`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL tree insert — not mission-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00401db0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (EDI=map, RET 0x0C, color@+0x2C).  
- Odd behavior preserved: custom EDI-map ABI (not thiscall-on-map); always-insert with no key compare; decompiler unaff_EDI corrected via assembly.  
- `_Inferred` where English unproven; retire Named_CalleeOf scaffolds. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

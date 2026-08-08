# Dual A/B report — R13-002 OWN-ONLY (`0x004cb2c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-002**  
**Scope:** VA `0x004cb2c0` (`aa_004cb2c0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent erase `00405650` re-dual, max peer `00421a60`, succ `004e12c0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-002**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `_Tree` min).  
**Parent dual:** `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cb2c0` StdTree_Min_Isnil21_Inferred | **accept** — min CF/ABI/isnil21/EAX-out sealed; product residual only |

Path A (fidelity): **accept**.  
Path B (adversarial): void-return / thiscall / EAX-in / wrong-isnil / max / skill-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004cb2c0` — sealed facts

1. **Body:** `0x004cb2c0`–`0x004cb2da` inclusive (**27 B** / `0x1b`); pad `CC`.
2. **ABI:** stack arg `node*` @ `[ESP+4]`; returns leftmost in **EAX**; bare **`RET`** (`C3`); caller cleans (`ADD ESP,4`). Not thiscall. Not EAX-in (unlike Min isnil31).
3. **Semantics:** MSVC-style **`_Tree_min` / leftmost non-nil** for **isnil@+0x21**:
   - Load left; if left isnil → return original node.
   - Else walk left while child non-nil; return last non-nil.
   - Leaf (no callees).
4. **Layout:** left@+0; isnil@**+0x21** (color@+0x20 per parent erase dual).
5. **Callees:** none.
6. **Callers (7):** all erase-family head-leftmost recompute plates:
   - `FUN_00405650` @ `0x0040571a` (parent dual R12-009)
   - `FUN_004e3e70` @ `0x004e3f5f`
   - `FUN_00511c00` @ `0x00511cec`
   - `FUN_0059d300` @ `0x0059d3ec`
   - `FUN_005a2ea0` @ `0x005a2f8f`
   - `FUN_005a4590` @ `0x005a467c`
   - `FUN_005ae6d0` @ `0x005ae7bf`
7. **Xrefs:** 7 UNCONDITIONAL_CALL (same). Uniform plate `PUSH EDI; CALL; ADD ESP,4; MOV [EBX],EAX`.
8. **Name:** `StdTree_Min_Isnil21_Inferred` (Ghidra `FUN_004cb2c0`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** Min isnil29 stack `0051b5d0`; Min isnil31 EAX `00409160`; Max residual `00421a60`.
10. **Decompile ≡ raw CF** for left walk; return sealed via `read_memory` + call-site EAX store (decomp void hazard).

### Gaps

- Product / MSVC demangle for map value_type / host English on 7 erase parents.  
- Dual of max peer `FUN_00421a60` (R13-001), other residual erase parents (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb2c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb2c0_FUN_004cb2c0.md` |
| Function named | `docs/reconstruction/functions/aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00405650  StdTree_EraseAndRebalance_Isnil21_Inferred  [R12-009 dualed — parent]
  └─ StdTree_Min_Isnil21_Inferred (0x004cb2c0)  [OWN R13-002]
  └─ FUN_00421a60  max  [R13-001 residual]
  └─ FUN_004e12c0  iterator++ isnil21  [R13-003 residual]
  └─ FUN_0050e9f0 / FUN_005a27f0  L/R rotate isnil21  [dualed earlier]

FUN_004e3e70 / FUN_00511c00 / FUN_0059d300 / FUN_005a2ea0 /
FUN_005a4590 / FUN_005ae6d0  peer erase plates  [residual]
  └─ StdTree_Min_Isnil21_Inferred (0x004cb2c0)

Family (do not merge):
  StdTree_Min_Isnil29 @ 0x0051b5d0  [dualed]
  StdTree_Min_Isnil31 @ 0x00409160  [dualed]
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (parent erase host proximity), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cb2c0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cb2c0` | Port as **shared StdTree min / leftmost** for **isnil@+0x21**. Stack arg `node*`; **EAX** out; bare RET; caller `ADD ESP,4`. Pair with isnil21 erase `00405650`, max residual `00421a60`. Do not merge with isnil29/31 Min or EAX-in Min isnil31. |
| Pair with | dualed erase parent `00405650`; dualed Min isnil29/31; residual max `00421a60`. |
| Naming caution | **Not** skill/ability-product-specific. **Not** max / iterator++ / erase. **Not** isnil29/31 Min despite shared plate shape. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL min — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004cb2c0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (stack arg + EAX return; decomp void hazard).  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

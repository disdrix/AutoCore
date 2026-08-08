# Dual A/B report — R13-003 OWN-ONLY (`0x004e12c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-003**  
**Scope:** VA `0x004e12c0` (`aa_004e12c0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent erase `00405650` re-dual, min `004cb2c0`, max `00421a60`, peer erase plates).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-003**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `_Tree_iterator::operator++`).  
**Parent dual:** `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009).  
**Dual start:** 2686.  
**Terminal:** **false** (no Runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e12c0` StdTree_IteratorIncrement_Isnil21_Inferred | **accept-with-gaps** — successor CF/ABI/isnil21/leaf sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): freelist / predecessor / wrong-isnil-family / EDX-ABI-merge / container-this / EAX-return / skill-product / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004e12c0` — sealed facts

1. **Body:** `0x004e12c0`–`0x004e130b` exclusive (**75 B** / `0x4B`); pad `CC`.
2. **ABI:** **ECX** = `node**` (iterator); void; plain **`RET`** (`C3` ×2). Entry `MOV EAX,[ECX]`; stores through `[ECX]`.
3. **Semantics:** MSVC-style **`_Tree_iterator::operator++`** (in-order successor) for **isnil@+0x21**:
   - Nil-at-current → no-op.
   - If right non-nil → leftmost of right subtree (walk left@+0).
   - Else climb parents@+4 while was right-child of parent.
4. **Layout:** left@+0, parent@+4, right@+8, isnil@**+0x21**; color@+0x20 unused in this unit (family from erase peers).
5. **Callees:** none (leaf).
6. **Callers (8):**  
   - `FUN_00405650` @ `0x004056b6` (parent erase isnil21)  
   - `FUN_00406560` @ `0x0040668e` (insert-hint isnil21)  
   - `FUN_004e3e70` @ `0x004e3efb`  
   - `FUN_00511c00` @ `0x00511c8b`  
   - `FUN_0059d300` @ `0x0059d38b`  
   - `FUN_005a2ea0` @ `0x005a2f2b`  
   - `FUN_005a4590` @ `0x005a461b`  
   - `FUN_005ae6d0` @ `0x005ae75b`  
   All sites: `LEA ECX,[stack_it]` then `CALL`.
7. **Xrefs:** 8 UNCONDITIONAL_CALL (same).
8. **Name:** `StdTree_IteratorIncrement_Isnil21_Inferred` (Ghidra `FUN_004e12c0`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** isnil19 `00457cc0`; isnil29 `004cb270`; isnil31 **EDX** `00408590`; isnil49 `00568200`; isnil131 **EDX** `00404000`; predecessor `004313d0`.
10. **Decompile ≡ raw CF ≡ bytes** for all isnil guards and both exits; sealed via `read_memory` + `disassemble_function`.

### Gaps

- Product / MSVC demangle for map value_type per caller.  
- Color bit unused here (family-only).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004e12c0_FUN_004e12c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e12c0_FUN_004e12c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e12c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004e12c0_FUN_004e12c0.md` |
| Function named | `docs/reconstruction/functions/aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00405650  StdTree_EraseAndRebalance_Isnil21_Inferred  [R12-009 dualed — parent]
  └─ StdTree_IteratorIncrement_Isnil21_Inferred (0x004e12c0)  [OWN R13-003]
       (leaf — no callees)

FUN_00406560  InsertHint isnil21  [prior dual residual context]
  └─ StdTree_IteratorIncrement_Isnil21_Inferred (0x004e12c0)

FUN_004e3e70 / FUN_00511c00 / FUN_0059d300 / FUN_005a2ea0 /
FUN_005a4590 / FUN_005ae6d0  erase isnil21 family plates
  └─ StdTree_IteratorIncrement_Isnil21_Inferred (0x004e12c0)

Sibling residuals under same parent (not this dual):
  FUN_004cb2c0  min  [R13-002]
  FUN_00421a60  max  [R13-001]
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (host erase caller proximity), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004e12c0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e12c0` | Port as **shared StdTree iterator++** for **isnil@+0x21**. **ECX** = `node**`; void; plain RET. Leaf. Pair with isnil21 erase `00405650`, Lrotate `0050e9f0`, Rrotate `005a27f0`. Do not merge with isnil19/29/31/49/131 peers or EDX-ABI twins. |
| Pair with | dualed parent erase `00405650`; residual min `004cb2c0` / max `00421a60`; dualed isnil21 rotate/insert family. |
| Naming caution | **Not** skill/ability-product-specific. **Not** predecessor. **Not** isnil31 EDX plate despite same 75 B shape. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL iterator++ — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004e12c0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (ECX iterator; plain RET).  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

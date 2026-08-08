# Dual A/B report — R13-001 OWN-ONLY (`0x00421a60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-001**  
**Scope:** VA `0x00421a60` (`aa_00421a60`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including twin min `004cb2c0`, parent erase `00405650` re-dual, peer Max families).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-001**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `_Tree` max).  
**Parent dual:** `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00421a60` StdTree_Max_Isnil21_Inferred | **accept-with-gaps** — CF/ABI/EAX-return/isnil21 sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-return / min-swap / isnil29-merge / isnil19-merge / thiscall / skill-unique / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00421a60` — sealed facts

1. **Body:** `0x00421a60`–`0x00421a7c` exclusive (**28 B** / `0x1C`); terminal `C3` @ `0x00421a7b`; pad `CC`.
2. **Bytes:** `8B442404 8B4808 80792100 750E 8D4900 8BC1 8B4808 80792100 74F5 C3`.
3. **ABI:** **`__cdecl`** stack `node*`; plain **`RET`**; **EAX = rightmost non-nil** (or input if right child is nil). Decompiler `void` **rejected**. Call sites: `ADD ESP,4` then `MOV [head+8],EAX`.
4. **Semantics:** MSVC-style **`_Tree_max` / rightmost** for **isnil@+0x21**:
   - `right = node+8`; if isnil → return start.
   - Else walk right while next is non-nil; return last non-nil.
5. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; node **0x28** family (with parent erase).
6. **Callees:** none (leaf).
7. **Callers (7):** `FUN_00405650`, `FUN_004e3e70`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a4590`, `FUN_005ae6d0` — all isnil21 erase rightmost recompute.
8. **Xrefs:** 7 UNCONDITIONAL_CALL (same).
9. **Name:** `StdTree_Max_Isnil21_Inferred` (Ghidra `FUN_00421a60`). Product demangle open → `_Inferred`.
10. **Family peers (do not merge):** isnil29 Max `00421b50`; isnil31 Max `004043e0`; Val12 Max `00418bf0`; twin min isnil21 `004cb2c0`.
11. **Decompile ≡ raw CF** for display; ABI sealed via `read_memory` + `disassemble_function` + call-site context.

### Gaps

- Product / MSVC demangle for map value_type / host English.  
- Dual of twin min `FUN_004cb2c0` (R13-002).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00421a60_StdTree_Max_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00421a60_StdTree_Max_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00421a60_FUN_00421a60.md` |
| Annotated | `docs/reconstruction/raw/aa_00421a60_FUN_00421a60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00421a60.cpp` |
| Function | `docs/reconstruction/functions/aa_00421a60_FUN_00421a60.md` |
| Function named | `docs/reconstruction/functions/aa_00421a60_StdTree_Max_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00405650  StdTree_EraseAndRebalance_Isnil21_Inferred  [R12-009 parent dual]
  └─ StdTree_Max_Isnil21_Inferred (0x00421a60)  [OWN R13-001]
  └─ FUN_004cb2c0  min isnil21  [residual R13-002]
  └─ FUN_004e12c0  succ isnil21  [residual R13-003]
  └─ FUN_0050e9f0 / FUN_005a27f0  L/R rotate isnil21  [prior duals]

Peer Max clones (different isnil offsets — do not merge):
  00421b50  StdTree_Max_Isnil29_Inferred
  004043e0  StdTree_Max_Isnil31
  00418bf0  StdTree_Max_Val12  (isnil@+0x19)
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (host caller proximity under parent erase), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00421a60-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00421a60` | Port as **shared StdTree max / rightmost** for **isnil@+0x21 / node 0x28**. **`__cdecl`** stack `node*`; **EAX** result; plain **ret**. Pair with min `004cb2c0` and isnil21 erase family (`00405650` et al.). Do not merge with isnil29/31/Val12 Max peers. |
| Pair with | dualed erase `00405650`; residual min `004cb2c0`; dualed L/R rotate `0050e9f0`/`005a27f0`. |
| Naming caution | **Not** skill/ability-product-specific. **Not** min. **Not** isnil29 Max despite identical plate. **Not** Runtime Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL max — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00421a60`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (cdecl EAX return; empty-right returns start).  
- Odd behavior preserved: decompiler void/while vs byte-faithful early return of start.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

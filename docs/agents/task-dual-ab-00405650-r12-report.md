# Dual A/B report — R12-009 OWN-ONLY (`0x00405650`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-009**  
**Scope:** VA `0x00405650` (`aa_00405650`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent rotate `005a27f0` re-dual, range parent `00407140`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-009**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `_Tree` erase).  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00405650` StdTree_EraseAndRebalance_Isnil21_Inferred | **accept-with-gaps** — erase CF/ABI/RET8/isnil21/epilogue sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): noreturn-as-full-body / isnil29-merge / isnil31-merge / stack-RET0xC / range-erase / freelist / value-dtor / Rrotate-only claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00405650` — sealed facts

1. **Body:** `0x00405650`–`0x004058e4` exclusive (**660 B** / `0x294`); pad `CC`. Ghidra lists end `0x004058b4` (false noreturn on `operator_delete`).
2. **ABI:** **`__thiscall`** ECX=`MapShell*`; stack `outIt**`, `node*`; **`ret 8`** (`C2 08 00` @ `0x004058e1`).
3. **Semantics:** MSVC-style **`_Tree` erase + RB rebalance** for **isnil@+0x21**:
   - SEH frame (`LAB_009bc919` / FS:[0]).
   - Nil iterator → `"invalid map/set<T> iterator"` @ `0x00a152f0` → `FUN_00401bc0` → `_CxxThrowException` / `DAT_00acc34c`.
   - Successor via `FUN_004e12c0` (iterator++ isnil21).
   - Unlink + head extremity fix (min `004cb2c0` / max `00421a60`); two-child swap path @ `0x0040574b`.
   - If erased black → recolor + Lrotate `0050e9f0` / Rrotate `005a27f0`.
   - `operator_delete(node)` (no value dtor); size--; `*outIt = succ`.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; node **0x28** (Val16); shell head@+4, size@+8.
5. **Callees:** `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `FUN_00401bc0`, basic_string ctor (IAT), `_CxxThrowException`, `operator_delete`.
6. **Callers (2):** `FUN_00407140` @ `0x004071df` (erase-range); `FUN_00932c80` @ `0x00933018` (host map @ `+0xed8`).
7. **Xrefs:** 2 UNCONDITIONAL_CALL (same).
8. **Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` (Ghidra `FUN_00405650`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** isnil29 thiscall `004cb740`; isnil29 RetC `00402850`; isnil31 `00408ed0`; StringKey isnil2d `004094c0`.
10. **Decompile ≡ raw CF** for throw/unlink/rebalance; epilogue sealed via `read_memory` + `disassemble_function` past false noreturn.

### Gaps

- Product / MSVC demangle for map value_type / host English (`FUN_00932c80` +0xed8).  
- Dual of range parent `FUN_00407140`, succ `FUN_004e12c0`, min/max.  
- Two-child splice plate bit-level fidelity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00405650_FUN_00405650.md` |
| Annotated | `docs/reconstruction/raw/aa_00405650_FUN_00405650.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00405650.cpp` |
| Function | `docs/reconstruction/functions/aa_00405650_FUN_00405650.md` |
| Function named | `docs/reconstruction/functions/aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00407140  erase-range parent (isnil21)  [residual]
  └─ StdTree_EraseAndRebalance_Isnil21_Inferred (0x00405650)  [OWN R12-009]
       ├─ FUN_004e12c0  iterator++ isnil21  [residual]
       ├─ FUN_004cb2c0  min  [residual]
       ├─ FUN_00421a60  max  [residual]
       ├─ FUN_0050e9f0  Lrotate isnil21  [R10 dualed]
       └─ FUN_005a27f0  Rrotate isnil21  [R11-007 dualed — parent dual]

FUN_00932c80  host object map @ +0xed8  [residual]
  └─ StdTree_EraseAndRebalance_Isnil21_Inferred (0x00405650)

FUN_00407200  StdTree_InsertAndRebalance_Isnil21_Inferred  [WQ9I-B dualed]
  └─ same L/R rotate pair (0050e9f0 / 005a27f0)
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (host caller proximity), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00405650-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00405650` | Port as **shared StdTree erase+rebalance** for **isnil@+0x21 / color@+0x20 / node 0x28**. **`__thiscall`** ECX=map; stack `outIt**`, `node*`; **ret 8**. No value dtor. Pair with isnil21 insert `00407200`, Lrotate `0050e9f0`, Rrotate `005a27f0`. Do not merge with isnil29/isnil2d/isnil31 erase or stack RET0xC peers. |
| Pair with | dualed Rrotate `005a27f0`; dualed Lrotate `0050e9f0`; dualed InsertAndRebalance `00407200`; residual range parent `00407140`; residual succ `004e12c0`. |
| Naming caution | **Not** skill/ability-product-specific. **Not** Rrotate. **Not** range erase. **Not** isnil29/31 erase despite shared MSVC plate shape. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL erase — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00405650`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (thiscall RET 8; epilogue past false noreturn).  
- Odd behavior preserved: decompiler unreachable mid-blocks for two-child path; assembly has them.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

# Dual A/B report — R12-030 OWN-ONLY (`0x005a2ea0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-030**  
**Scope:** VA `0x005a2ea0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including erase clones `00405650` / `004e3e70` / residual `0059d300`…).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `disassemble_function` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-030**.  
**System:** skills-abilities.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005a2ea0` StdTree_EraseAndRebalance_Isnil21_Inferred | **accept-with-gaps** — erase CF/ABI/RET8/size--/outIt/isnil21 sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Val12-merge / isnil29-merge / range-free / insert-merge / skill-only / decomp-complete / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005a2ea0` — sealed facts

1. **Body:** `0x005a2ea0`–`0x005a3155` inclusive (**694 B** / `0x2B6`); pad `CC` @ `0x005a3156`. Ghidra lists end `0x005a3126` (false noreturn truncate on delete).
2. **ABI:** **`__thiscall`** ECX=map; stack `Node** outIt`, `Node* node`; **`ret 8`** (`C2 08 00`).
3. **Semantics:** MSVC-style **`_Tree` erase + RB rebalance** for **isnil@+0x21**:
   - Throw `"invalid map/set<T> iterator"` if `node->isnil`.
   - Successor prep `FUN_004e12c0`; splice; fix root / min (`004cb2c0`) / max (`00421a60`).
   - If erased black (`color@+0x20 == 1`): RB with Lrotate `0050e9f0` / Rrotate `005a27f0`.
   - `operator_delete(node)`; if size>0 then `--size` @ map+8; `*outIt = successor`.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; node **0x28**; tree head@+4, size@+8.
5. **Callees:** `004e12c0`, `004cb2c0`, `00421a60`, `0050e9f0`, `005a27f0`, `operator_delete`, STL throw chain.
6. **Callers / xrefs (2 UNCONDITIONAL_CALL):**
   - `FUN_005a3860` @ `005a38ff` (EraseRange; `MOV ECX,EDI`; parent `ret 0xC`)
   - orphan @ `005a052b` (body ~`005a04d0`–`005a053d`; `MOV ECX,EDI`; parent `ret 4`; DATA `009d7f0c`)
7. **Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` (Ghidra `FUN_005a2ea0`). Product demangle open → `_Inferred`.
8. **Clones (not OWN):** dualed `00405650` (660 B), `004e3e70` (694 B reloc-near-identical); residual peers in R12 row (`0059d300`, `005a3500`, …).
9. **Decompile ≡ raw CF** for throw/splice/RB; epilogue sealed via `read_memory` (size-- / outIt / ret 8).

### Gaps

- Product / MSVC demangle for map value_type of callers.  
- Orphan enclosing-function recovery at `005a04d0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005a2ea0_FUN_005a2ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_005a2ea0_FUN_005a2ea0.annotated.md` |
| Clean (VA) | `docs/reconstruction/reconstructed-exact/FUN_005a2ea0.cpp` |
| Function | `docs/reconstruction/functions/aa_005a2ea0_FUN_005a2ea0.md` |
| Function named | `docs/reconstruction/functions/aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005a3860  EraseRange isnil21 shell                    [residual]
  └─ StdTree_EraseAndRebalance_Isnil21_Inferred (0x005a2ea0)  [OWN R12-030]
        ├─ FUN_004e12c0  nextnode isnil21
        ├─ FUN_004cb2c0  min isnil21
        ├─ FUN_00421a60  max isnil21
        ├─ FUN_0050e9f0  Lrotate isnil21                    [dualed]
        └─ FUN_005a27f0  Rrotate isnil21                    [parent R11-007]

Insert twin (same family, dualed earlier):
  FUN_00407200  StdTree_InsertAndRebalance_Isnil21_Inferred

Peer erase clones (other VAs — do not merge):
  00405650 (R12-009 dualed), 004e3e70 (R12-013 dualed), residual 0059d300 / 005a3500 / …
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005a2ea0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005a2ea0` | Port as **shared StdTree erase+rebalance** for **isnil@+0x21 / color@+0x20 / node 0x28**. **thiscall** ECX=map; stack `outIt**`, `node*`; **ret 8**. size-- after delete; write `*outIt`. Pair with L/R rotates `0050e9f0`/`005a27f0` and insert twin `00407200`. Do **not** merge with Val12 / isnil29 / other clone VAs. |
| Pair with | InsertAndRebalance isnil21; dualed L/R rotates isnil21; EraseRange parent `005a3860`; peer erase clones for CF reference only. |
| Naming caution | **Not** skill-specific product API. **Not** insert. **Not** range erase. **Not** Runtime Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (skills-abilities / STL helpers)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x005a2ea0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean VA source uses meaningful name + Ghidra alias.  
- Odd behavior preserved: decomp false-noreturn; unreachable two-child plate; size-- only if size>0.  
- `_Inferred` where product English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

# Dual A/B report — R13-016 OWN-ONLY (`0x00407140`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-016** (dual start **2686**)  
**Scope:** VA `0x00407140` (`aa_00407140`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including free residual `00406710`, tidy callers, host `004ffe60` re-dual, parent erase already dualed under R12-009).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-016**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `_Tree` range erase).  
**Parent dual:** `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00407140` StdTree_EraseRange_Isnil21_Inferred | **accept-with-gaps** — erase-range CF/ABI/RET0xC/isnil21/full-clear/partial loop sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): isnil29-merge / Map_EraseRange-merge / single-node-only / isnil offset swap / RET8-or-bare / skill-product-name / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00407140` — sealed facts

1. **Body:** `0x00407140`–`0x004071f4` exclusive (**180 B** / `0xB4`); pad `CC`.
2. **ABI:** **`__thiscall`** ECX=`MapShell*`; stack `outIt**`, `first*`, `last*`; **`ret 0xc`** (`C2 0C 00` both exits).
3. **Semantics:** MSVC-style **`_Tree::erase(first, last)`** for **isnil@+0x21**:
   - Full clear when `[first,last) == [head->left, head]`: free subtree `FUN_00406710(head->parent)`; reset head parent/left/right to head; `size=0`; `*outIt = head->left`.
   - Partial: inline isnil21 successor, then `FUN_00405650(map, &first, node)` per element; `*outIt = first` after loop.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; node **0x28** (Val16 trivial on erase path); shell head@+4, size@+8.
5. **Callees:** `FUN_00406710` (free residual); `FUN_00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009 dualed).
6. **Callers (3):** `FUN_00405290` @ `0x004052c3`; `FUN_00405620` @ `0x00405632`; `FUN_004ffe60` @ `0x00500162` (map @ `ESI-0x3B4`).
7. **Xrefs:** 3 UNCONDITIONAL_CALL (same).
8. **Name:** `StdTree_EraseRange_Isnil21_Inferred` (Ghidra `FUN_00407140`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** isnil29 range `004cbaa0`; isnil11 range `00441960`; Map_EraseRange / `_B`; single erase is parent `00405650` (not this unit).
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site `MOV ECX` + 3× PUSH.

### Gaps

- Product / MSVC demangle for map value_type / host English.  
- Dual of free residual `FUN_00406710` (left-recurse decomp residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407140_FUN_00407140.md` |
| Annotated | `docs/reconstruction/raw/aa_00407140_FUN_00407140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407140.cpp` |
| Function | `docs/reconstruction/functions/aa_00407140_FUN_00407140.md` |
| Function named | `docs/reconstruction/functions/aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00405290 / FUN_00405620  map-shell tidy  [residual]
  └─ StdTree_EraseRange_Isnil21_Inferred (0x00407140)  [OWN R13-016]
       ├─ FUN_00406710  free subtree isnil21  [residual]
       └─ StdTree_EraseAndRebalance_Isnil21_Inferred (0x00405650)  [R12-009 dualed — parent]
            ├─ FUN_004e12c0  iterator++ isnil21  [residual]
            ├─ FUN_0050e9f0  Lrotate isnil21  [dualed]
            └─ FUN_005a27f0  Rrotate isnil21  [dualed]

FUN_004ffe60  host object  [residual]
  map @ ESI - 0x3B4
  └─ StdTree_EraseRange_Isnil21_Inferred (0x00407140)  [OWN R13-016]

Peer (do not merge):
  StdTree_EraseRange_Isnil29_Inferred (0x004cbaa0)  [dualed] — free 004cb550 / erase 004cb740
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (host/caller proximity via skills residual partition), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00407140-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00407140` | Port as **shared StdTree erase-range** for **isnil@+0x21 / color@+0x20 / node 0x28**. **`__thiscall`** ECX=map; stack `outIt**`, `first*`, `last*`; **ret 0xc**. Full clear uses free `00406710`; partial loops erase `00405650`. Do not merge with isnil29 range `004cbaa0` or Map_EraseRange*. |
| Pair with | dualed single erase `00405650`; residual free `00406710`; dualed isnil21 insert/rotates. |
| Naming caution | **Not** skill/ability-product-specific. **Not** single erase. **Not** isnil29/isnil11 range despite shared 180 B plate shape. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL range erase — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00407140`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Raw body captured; re-verify **appended**.  
- Clean sources use meaningful `_Inferred` name; twin `FUN_00407140.cpp` retained.  
- Odd behavior preserved: free-subtree decomp may drop left recurse (residual on `00406710`, not this unit).  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

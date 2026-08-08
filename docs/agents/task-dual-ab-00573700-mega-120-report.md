# Dual A/B report — MEGA-120 OWN-ONLY (`0x00573700`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-120**  
**Scope:** VA `0x00573700` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual partition — inventory-transfer residual of InventoryGrid complete dtor / placement map.  
**Hint:** `InventoryGrid_DestroyItemList` (product-facing full-clear alias; structural name preferred).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573700` StdTree_EraseRange_Val12_InventoryGrid_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/Val12/peer-clone/InventoryGrid shell ownership sealed; product demangle + free residual + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): product-only DestroyItemList / ECX=grid / wrong isnil family / vtbl value destroy / 2-arg ABI claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00573700` — sealed facts

1. **Body:** `0x00573700`–`0x005737b3` inclusive (**180 B** / `0xB4`); pad `CC` before next unit.
2. **ABI:** **ECX** = map shell (`head@+4`, `size@+8`); stack `outIt*`, `first*`, `last*`; void via `*outIt`; **`RET 0x0C`** both exits.
3. **Semantics:** MSVC `_Tree` **range erase** `[first, last)` Val12 (isnil@**+0x19**):
   - Full: `first == head->left && last == head` → `FUN_005731c0(head->parent)`, reinit head, `size=0`, `*out=begin`.
   - Partial: successor (isnil@+0x19) + dualed `StdTree_Erase_Val12` `0x00573250` per node.
4. **Callees:** `FUN_005731c0` (free-subtree); `FUN_00573250` / `StdTree_Erase_Val12` (dualed W27-S).
5. **Callers (3 UNCONDITIONAL_CALL):**
   - `FUN_005725a0` @ `0x005725fe` — InventoryGrid complete dtor; `ECX = grid+0x5c`.
   - `FUN_00572ab0` @ `0x00572e71` — `InventoryGrid_AutoMergePartialStacks_Inferred` temp map.
   - `FUN_005738d0` @ `0x005738e2` — map-shell dtor (full erase + `operator_delete(head)`).
6. **Peer:** dualed `StdTree_EraseRange_Val12` @ `0x0040d700` — **byte-identical** 180 B skeleton; only CALL displacements differ.
7. **Name:** `StdTree_EraseRange_Val12_InventoryGrid_Inferred` (Ghidra `FUN_00573700`). Product demangle open → `_Inferred`. Partition hint is full-clear alias only.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/MSVC demangle for map `T` / key English.  
- Free-subtree residual `005731c0` (not dualled here).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00573700_FUN_00573700.md` |
| Annotated | `docs/reconstruction/raw/aa_00573700_FUN_00573700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Val12_InventoryGrid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573700.cpp` |
| Function | `docs/reconstruction/functions/aa_00573700_FUN_00573700.md` |
| Function named | `docs/reconstruction/functions/aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
InventoryGrid_ScalarDeletingDtor  0x00573910  [dualed WQ8R-E]
  └─ FUN_005725a0  InventoryGrid complete dtor  [residual parent MEGA-061]
       ├─ FUN_00570f70  nested CS-host dtor path
       ├─ operator_delete[] cells @ +0x28
       ├─ FUN_00573700  StdTree_EraseRange_Val12_InventoryGrid_Inferred  [OWN MEGA-120]
       │     ├─ FUN_005731c0  free-subtree Val12  [residual]
       │     └─ FUN_00573250  StdTree_Erase_Val12  [dualed W27-S]
       └─ operator_delete(head @ +0x60)

InventoryGrid_AutoMergePartialStacks_Inferred  0x00572ab0  [dualed]
  └─ FUN_00573700  (temp partial map full clear)  [OWN MEGA-120]

FUN_005738d0  map-shell dtor plate
  └─ FUN_00573700 + operator_delete(head)  [OWN MEGA-120]

Peer clone (not this VA):
  StdTree_EraseRange_Val12  0x0040d700  [dualed W32-C]
    free=0040d630  erase=004188e0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00573700-mega-120-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573700` | Port as **MSVC tree range erase** for Val12 maps. **ECX=map shell** (InventoryGrid at `grid+0x5c`), **not** grid `this`. Stack `(outIt, first, last)`, **RET 0xC**. |
| Full path | Free subtree root only — **no** value vtbl destroy in this body. Reset head self-links + `size=0`. |
| Partial path | Successor isnil@**+0x19** + dualed single erase `00573250` (`RET 8`). |
| Pair with | dualed erase `00573250`; residual free `005731c0`; residual complete dtor `005725a0`; dualed AutoMerge `00572ab0`; peer range `0040d700` (do not merge instances). |
| Alias caution | Partition hint `InventoryGrid_DestroyItemList` is a **full-clear use name** only — body is generic range erase. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00573700`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; scaffold twin retained.  
- Odd behavior preserved: decomp drops erase thiscall ECX and free left-walk; assembly is authority.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

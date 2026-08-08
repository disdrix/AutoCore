# Dual A/B report — R13-020 OWN-ONLY (`0x0040bc10`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-020**  
**Scope:** VA `0x0040bc10` (`aa_0040bc10`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent `0092b2a0`, free `0040c100`, erase `0040b440` re-dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-020**.  
**System:** inventory-transfer (partition assignment; unit role is generic MSVC `_Tree` range erase).  
**Parent dual:** `0x0092b2a0` (not dualled here).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040bc10` StdTree_EraseRange_Isnil19_Inferred | **accept-with-gaps** — CF/ABI EDI-map/RET0xC/isnil19 full+partial sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-only / single-erase / ECX-thiscall / merge-with-`0040d700` / wrong-isnil-family / inventory-product-method / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040bc10` — sealed facts

1. **Body:** `0x0040bc10`–`0x0040bcc2` exclusive (**178 B** / `0xB2`); pad `CC`.
2. **ABI:** register-this **EDI** = `MapShell*`; stack `outIt**`, `first`, `last`; **EAX** = `outIt*`; **`ret 0xC`** (`C2 0C 00` ×2 @ `0x0040bc5a` / `0x0040bcbf`).
3. **Semantics:** MSVC-style **`_Tree::erase(first, last)`** for **isnil@+0x19** (Val12):
   - Full clear: `first == head->left && last == head` → free root via residual `FUN_0040c100` (`PUSH parent; MOV ECX,EDI; CALL`); reset head left/parent/right to head; size=0; `*outIt=head->left`.
   - Partial: inline in-order successor (isnil@+0x19) then residual `FUN_0040b440(map, &outIt, cur)`.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x18**, isnil@**+0x19**; shell head@+4, size@+8.
5. **Callees:** `FUN_0040c100` (free-subtree residual; RET 4; isnil19), `FUN_0040b440` (erase+rebalance residual; R13-018).
6. **Callers (3 / 4 sites):** `FUN_0040b2d0` @ `0x0040b2fe`; `FUN_0040b410` @ `0x0040b420`; `FUN_0092b2a0` @ `0x0092b8fc` + `0x0092b947`.
7. **Xrefs:** 4 UNCONDITIONAL_CALL (same).
8. **Name:** `StdTree_EraseRange_Isnil19_Inferred` (Ghidra `FUN_0040bc10`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** ECX Val12 erase-range `0040d700` (free `0040d630` / erase `004188e0`); isnil11 `00441960`; isnil29 `004cbaa0`; isnil2d/131 string erase-range clones.
10. **Decompile ≡ raw CF** for full/partial; free callee decompile damaged by noreturn — sealed via `read_memory` of `0040c100`.

### Gaps

- Product / MSVC demangle for map value_type / host English (`FUN_0092b2a0` shells).  
- Dual of free `FUN_0040c100`, erase `FUN_0040b440`, tidy `0040b2d0`/`0040b410`, parent `0092b2a0`.  
- Free path value-dtor policy (`operator_delete` only in free body).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040bc10_FUN_0040bc10.md` |
| Annotated | `docs/reconstruction/raw/aa_0040bc10_FUN_0040bc10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil19_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040bc10.cpp` |
| Function | `docs/reconstruction/functions/aa_0040bc10_FUN_0040bc10.md` |
| Function named | `docs/reconstruction/functions/aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0092b2a0  inventory-transfer residual parent  [not dualled]
  └─ StdTree_EraseRange_Isnil19_Inferred (0x0040bc10)  [OWN R13-020]
       ├─ FUN_0040c100  free-subtree isnil19  [residual]
       └─ FUN_0040b440  erase+rebalance isnil19  [R13-018 residual]

FUN_0040b2d0 / FUN_0040b410  tidy full-clear wrappers  [residual]
  └─ StdTree_EraseRange_Isnil19_Inferred then operator_delete(head)

Peer (do not merge):
  StdTree_EraseRange_Val12 (0x0040d700)  [dualed W32-C]
    ├─ free 0040d630  [dualed]
    └─ erase 004188e0  [residual]
```

Partition system **inventory-transfer** explains why this VA was queued under that residual set (parent `0092b2a0` proximity), not an inventory-UI product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040bc10-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040bc10` | Port as **shared StdTree erase-range** for **isnil@+0x19 / color@+0x18 / Val12**. **EDI** = map; stack `outIt**`, `first`, `last`; **ret 0xC**. Full path free residual `0040c100`; partial erase residual `0040b440`. Do not merge with ECX Val12 peer `0040d700` or other isnil-family erase-range clones. |
| Pair with | residual free `0040c100`; residual erase `0040b440` (R13-018); residual tidy `0040b2d0`/`0040b410`; parent residual `0092b2a0`. |
| Naming caution | **Not** inventory grab/drop/UI product. **Not** ECX-thiscall Val12 `0040d700`. **Not** free-subtree-only or single-node erase. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (generic STL erase-range — not inventory UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0040bc10`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (EDI-map RET 0xC; free callee bytes past noreturn decompile).  
- Odd behavior preserved: decompiler free `0040c100` right-only + noreturn; assembly has right+left free plate.  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

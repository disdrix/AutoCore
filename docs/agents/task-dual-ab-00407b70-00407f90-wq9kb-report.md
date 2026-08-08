# Dual A/B report — WQ9K-B OWN-ONLY (`0x00407b70`, `0x00407f90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-B**  
**Scope:** VAs `0x00407b70`, `0x00407f90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` + `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-B**.  
**Work item:** WQ-009 depth-8 residual dual seal — **erase-range full-clear callers** of free-subtree **string families** (isnil131 + isnil2d DestroyStr0C).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00407b70` StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred | **accept-with-gaps** — CF/ABI/RET0x0c/ESI-this/full-clear free `00409920`+partial succ/erase sealed; product residual |
| `aa_00407f90` StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred | **accept-with-gaps** — CF/ABI/RET0x0c/EDI-this/isnil@+0x2d/full-clear free `00409970`+StringKey erase sealed; product residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): free-only / erase-only / ECX-thiscall / isnil29-or-15 merge / family cross-merge / RET4-or-8 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00407b70` — sealed facts

1. **Body:** `0x00407b70`–`0x00407bea` exclusive (**122 B** / `0x7A`); pad `CC`; next `0x00407bf0`.
2. **ABI:** **ESI = map\*** (register-this; **not** ECX `__thiscall`); stack `Node** out`, `Node* first`, `Node* last`; both exits **`RET 0x0c`**; returns `out` in EAX.
3. **Semantics:** MSVC-style **range erase** `[first, last)` for **isnil@+0x131** string family:
   - Full clear: `first == *head` (leftmost/begin) && `last == head` (end) → free-subtree dualed `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` (`0x00409920`, ECX=map, push `head->parent`); head parent/left/right = head; size@+8 = 0; `*out = *head`.
   - Partial: residual successor `FUN_00404000` (isnil@+0x131) then residual erase `FUN_00408ad0` (~string @+0x0c + rebalance); loop until first==last; `*out = first`.
4. **isnil / color:** family **+0x131** (via free/succ/erase callees; no isnil immediate in this body).
5. **Callees:** dualed free `0x00409920`; residual `0x00404000`; residual `0x00408ad0`.
6. **Callers (2):** `FUN_00405110` @ `0x0040513e`; `FUN_00405df0` @ `0x00405e00` (map tidy/dtor full-range clear → `operator_delete(head)`).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` (Ghidra `FUN_00407b70`). Product open → `_Inferred`.
9. **Decompile ≡ raw CF**; register-this + body size + RET sealed via `read_memory` / callers.

### Gaps

- Product / MSVC demangle for large string-bearing node.  
- Residual undualed: successor `00404000`, erase `00408ad0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407b70_FUN_00407b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00407b70_FUN_00407b70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407b70.cpp` |
| Function | `docs/reconstruction/functions/aa_00407b70_FUN_00407b70.md` |
| Function named | `docs/reconstruction/functions/aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` |

---

## VA `0x00407f90` — sealed facts

1. **Body:** `0x00407f90`–`0x00408042` exclusive (**178 B** / `0xB2`); pad `CC`; next SEH fn `0x00408050`.
2. **ABI:** **EDI = map\*** (register-this; **not** ECX `__thiscall`); stack `Node** out`, `Node* first`, `Node* last`; both exits **`RET 0x0c`**; returns `out` in EAX.
3. **Semantics:** MSVC-style **range erase** `[first, last)` for **isnil@+0x2d** string-key family:
   - Full clear: `first == *head && last == head` → free-subtree dualed `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` (`0x00409970`, ECX=map, push `head->parent`); head parent/left/right = head; size@+8 = 0; `*out = *head`.
   - Partial: **inlined** successor (isnil@+0x2d) then dualed `StdMap_StringKey_EraseAndRebalance_Inferred` (`0x004094c0`); loop until first==last; `*out = first`.
4. **isnil / color:** **+0x2d** / (color@+0x2c via erase peer); string@+0x0c.
5. **Callees:** dualed free `0x00409970`; dualed StringKey erase `0x004094c0`.
6. **Callers (2):** `FUN_00404ec0` @ `0x00404eee`; `FUN_004061f0` @ `0x00406200` (map tidy/dtor full-range clear → `operator_delete(head)`).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred` (Ghidra `FUN_00407f90`). Product open → `_Inferred`.
9. **Decompile ≡ raw CF**; isnil immediates + RET sealed via `read_memory`.

### Gaps

- Product / English host map type for compact string-key map.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407f90_FUN_00407f90.md` |
| Annotated | `docs/reconstruction/raw/aa_00407f90_FUN_00407f90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407f90.cpp` |
| Function | `docs/reconstruction/functions/aa_00407f90_FUN_00407f90.md` |
| Function named | `docs/reconstruction/functions/aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` |

---

## Chain context (evidence only)

```text
FUN_00407b70  StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred   [OWN WQ9K-B]
  ├─ full: FUN_00409920  FreeSubtree Isnil131 + DestroyStr0C   [dualed WQ9J-I]
  └─ partial:
        ├─ FUN_00404000  successor isnil131                    [residual]
        └─ FUN_00408ad0  erase+rebalance isnil131 + ~string    [residual]

FUN_00407f90  StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred    [OWN WQ9K-B]
  ├─ full: FUN_00409970  FreeSubtree Isnil2d + DestroyStr0C    [dualed WQ9J-I]
  └─ partial:
        ├─ inlined successor isnil@+0x2d
        └─ FUN_004094c0  StringKey EraseAndRebalance           [dualed WQ9J-F]

Compare isnil29 range peers (do not merge):
  FUN_00407d70  Map_EraseRange_C  free 00406c00 / erase Map_EraseNode_B
  FUN_0051c7c0 / FUN_0051d880  Map_EraseRange / Map_EraseRange_B
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00407b70-00407f90-wq9kb-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00407b70` | Port as **isnil131 string-family range erase**: full clear → free `00409920` + head/size reset; partial → succ `00404000` + erase `00408ad0`. **ESI = map\***, **RET 0x0c**. Do **not** merge with isnil2d peer or isnil29 `Map_EraseRange_C`. |
| `00407f90` | Port as **isnil2d string-key range erase**: full clear → free `00409970` + head/size reset; partial → inlined succ + StringKey erase `004094c0`. **EDI = map\***, **RET 0x0c**. Keep **distinct** from isnil131 twin. |
| Pair with | dualed frees `00409920`/`00409970`; dualed StringKey erase `004094c0`; residual isnil131 succ/erase `00404000`/`00408ad0`; isnil29 peer `00407d70`. |
| Naming caution | **OWN pair is two string free-subtree families** (isnil131 large vs isnil2d compact) — shared role (erase-range full-clear parent), **not** layout-compatible. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (or util/container system note — these are **tree** helpers)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00407b70`, `0x00407f90`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not blank Ghidra paste).  
- Odd behavior preserved: decompiler `unaff_ESI`/`unaff_EDI` for register-this; free callees false-noreturn on delete (callee dual).  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

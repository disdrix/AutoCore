# Dual A/B report — WQ9H-F OWN-ONLY (`0x00407d70`, `0x00406560`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-F**  
**Scope:** VAs `0x00407d70`, `0x00406560` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` + `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-F**.  
**Work item:** WQ-009 depth-5 residual dual seal — free-subtree full-clear caller + pair-key less peer of `00401480`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00407d70` Map_EraseRange_C | **accept-with-gaps** — CF/ABI/RET0x0c/isnil@+0x29/full-clear free+partial erase sealed; product residual |
| `aa_00406560` StdTree_InsertHint_Isnil21_Inferred | **accept-with-gaps** — CF/ABI/RET0x0c/isnil@+0x21/pair-key hint sealed; product residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): free-only / erase-only / isnil15-or-1d / RET8 / isnil29-for-hint / always-insert-only / less-leaf-as-shell claims **falsified**.

---

## VA `0x00407d70` — sealed facts

1. **Body:** `0x00407d70`–`0x00407e24` exclusive (**180 B** / `0xB4`); pad `CC`; next fn `00407e30`.
2. **ABI:** **`__thiscall`**; ECX = map*; stack `Node** out`, `Node* first`, `Node* last`; **RET 0x0c** both exits.
3. **Semantics:** MSVC-style **range erase** `[first, last)`:
   - Full clear: `first == *head` (leftmost/begin) && `last == head` (end) → free-subtree `FUN_00406c00(head->parent)`; head parent/left/right = head; size@+8 = 0; `*out = *head`.
   - Partial: inlined successor (isnil@+0x29) then dualed `Map_EraseNode_B` (`0x00409220`); loop until first==last; `*out = first`.
4. **isnil / color:** **+0x29** / (color unused here).
5. **Callees:** dualed `StdTree_FreeSubtree_Isnil29_Inferred` (`0x00406c00`); dualed `Map_EraseNode_B` (`0x00409220`).
6. **Callers (3):** `FUN_00405350`, `FUN_00406010`, `FUN_004d98f0` (map tidy/dtor full-range clear).
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Name:** `Map_EraseRange_C` (Ghidra `FUN_00407d70`). Third isnil29 twin of dualed `Map_EraseRange` / `Map_EraseRange_B`.
9. **Decompile ≡ raw CF**; body size + RET sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for map value_type.  
- Per-caller payload English beyond tidy/dtor full clear.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407d70_Map_EraseRange_C.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407d70_Map_EraseRange_C.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407d70_FUN_00407d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00407d70_FUN_00407d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseRange_C.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00407d70_FUN_00407d70.md` |
| Function named | `docs/reconstruction/functions/aa_00407d70_Map_EraseRange_C.md` |

---

## VA `0x00406560` — sealed facts

1. **Body:** `0x00406560`–`0x00406705` exclusive (**421 B** / `0x1A5`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map*; stack `Node** outIt`, `Node* hint`, `Val* value`; frame `SUB ESP,8`; exits **`ADD ESP,8; RET 0x0c`**.
3. **Semantics:** MSVC-style **insert(hint, value)** for **isnil@+0x21** family:
   - Empty → always-insert left of head (`FUN_00407200`, addLeft=1).
   - Hint == leftmost → if value < *begin (inlined hi-signed/lo-unsigned) → Insert(1, begin).
   - Hint == head (end) → if *rightmost < value (`FUN_00401480`) → Insert(0, rightmost).
   - value < hint → pred `FUN_005adff0`; if pred < value < hint → open-side Insert (bytes: pred/0 or hint/1).
   - hint < value → succ `FUN_004e12c0`; if hint < value < succ (or end) → Insert (bytes: hint/0 or succ/1).
   - Else insert-or-find `FUN_00407060`; `*out = pair.node`.
4. **isnil / color family:** attachment checks **isnil@+0x21**; always-insert callee uses **color@+0x20**.
5. **Key:** 2-dword pair @ value +0/+4 and node +0x10/+0x14; dualed less leaf `StdPairKey_Less_HiSignedLoUnsigned_Inferred` (`0x00401480`).
6. **Callers (1):** `FUN_004055c0` (operator[]-style; returns **node+0x18**).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertHint_Isnil21_Inferred` (Ghidra `FUN_00406560`). Pair-key peer of dualed `StdTree_InsertHint_Isnil29_Inferred` (`0x004cc220`). Product open → `_Inferred`.
9. **Decompile ≡ raw CF** with pred/succ **where** sealed by bytes (decomp slightly aliases).

### Gaps

- Product pair/value demangle.  
- Residual undualed: always-insert `00407200`, insert-or-find `00407060`, pred/succ isnil21.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406560_FUN_00406560.md` |
| Annotated | `docs/reconstruction/raw/aa_00406560_FUN_00406560.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertHint_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406560.cpp` |
| Function | `docs/reconstruction/functions/aa_00406560_FUN_00406560.md` |
| Function named | `docs/reconstruction/functions/aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00407d70-00406560-wq9hf-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00407d70` | Port as **isnil29 range erase** third clone: full clear → free-subtree `00406c00` + head/size reset; partial → successor + `Map_EraseNode_B`. **RET 0x0c**. Do not wire free to `0051bbc0` or erase to `0051cb40` without clone awareness. |
| `00406560` | Port as **isnil21 insert-with-hint** with **pair-key less** `00401480`. Empty/begin/end/neighbor → always-insert `00407200`; else insert-or-find `00407060`. **RET 0x0c**. Do **not** merge with isnil29 InsertHint `004cc220` or treat as the less leaf itself. |
| Pair with | dualed free `00406c00`, erase-node B `00409220`, pair less `00401480`, isnil29 InsertHint peer `004cc220`; residual always-insert/insert-or-find/pred/succ isnil21. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (range erase free-clear + insert-hint residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00407d70`, `0x00406560`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp where-alias after pred/succ on InsertHint; leftmost inlined less; free-subtree decomp false-noreturn on delete (callee dual).  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
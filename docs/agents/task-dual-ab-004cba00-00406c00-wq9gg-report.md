# Dual A/B report — WQ9G-G OWN-ONLY (`0x004cba00`, `0x00406c00`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-G**  
**Scope:** VAs `0x004cba00`, `0x00406c00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-G**.  
**Work item:** WQ-009 depth-4 residual dual seal (skill-hash neighborhood find shell + tree free-subtree near dualed insert `00406c40`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cba00` StdMap_Find_Tfid_Isnil29_Inferred | **accept-with-gaps** — find CF/ABI/RET8/lower_bound+eq/5 xrefs sealed; product map value_type open |
| `aa_00406c00` StdTree_FreeSubtree_Isnil29_Inferred | **accept-with-gaps** — free-subtree CF/ABI/RET4/isnil@+0x29/3 external callers sealed by bytes (decomp incomplete); product T residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): skill-hash-table merge, lower_bound-only, insert-or-find, Val12/isnil15 mix-ups, bare-cdecl, value-destroy, and scaffold product plates all **falsified/narrowed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004cba00` — sealed facts

1. **Body:** `0x004cba00`–`0x004cba51` inclusive (**82 B** / `0x52`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map (`head@+4`); stack `Node** outIt`, `const KeyU32I32* pKey`; **`RET 8`** both exits; writes `*outIt`.
3. **Semantics:** MSVC **`map::find`** over TFID-shaped key:
   - `lb = StdMap_LowerBound_Tfid_Isnil29` (`0x004cb4b0`).
   - Hit iff `lb != head` and `node.key <= *pKey` (hi@+0x14 signed, lo@+0x10 unsigned).
   - Else `*outIt = head` (end).
   - **No** insert/erase/payload read.
4. **Classification:** worker (find shell over dualed lower_bound).
5. **Xrefs (5 UNCONDITIONAL_CALL):** `0x004ea5d4`, `0x004ea8bc`, `0x004eab3d` (`FUN_004ea350`); `0x0080757b` (`FUN_00807550`); `0x005dd84d`.
6. **Callee:** only `StdMap_LowerBound_Tfid_Isnil29` (`0x004cb4b0`, W31-N).
7. **Name:** `StdMap_Find_Tfid_Isnil29_Inferred` (Ghidra `FUN_004cba00`). Closes W31-N residual “find shell”. Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 8 sealed by **bytes**.

### Gaps

- Product map / value_type @ node `+0x20`.  
- Parent English for `FUN_004ea350` / ghost-assign `FUN_00807550`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cba00_FUN_004cba00.md` |
| Annotated | `docs/reconstruction/raw/aa_004cba00_FUN_004cba00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_Find_Tfid_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cba00.cpp` |
| Function | `docs/reconstruction/functions/aa_004cba00_FUN_004cba00.md` |
| Function named | `docs/reconstruction/functions/aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md` |

---

## VA `0x00406c00` — sealed facts

1. **Body:** `0x00406c00`–`0x00406c34` inclusive (**53 B** / `0x35`); pad `CC`.
2. **ABI:** ECX = tree_base (threaded); stack `node*`; void; **`RET 4`**.
3. **Semantics (bytes authority — decompiler incomplete):**
   - If isnil@+0x29 ≠ 0: return.
   - Loop: recurse free **right**@+8; capture **left**@+0; `operator_delete(node)`; advance left until isnil.
   - **No** value destroy.
4. **Twin CF:** `Map_FreeSubtree_Isnil29` (`0x0051bbc0`) — same body except `operator_delete` rel32; **keep distinct names/VAs**.
5. **Classification:** worker.
6. **Xrefs (4):** self `0x00406c17`; `FUN_00407d70` @ `0x00407d8c` (full-clear); `FUN_0092f3b0` @ `0x0092f406`; `FUN_009463b0` @ `0x00946451` (Phy reinit).
7. **Callees:** self, `operator_delete`.
8. **Name:** `StdTree_FreeSubtree_Isnil29_Inferred` (Ghidra `FUN_00406c00`). Neighborhood of dualed insert `00406c40`. Scaffold mission-notify name **reject**.
9. **Decompile ⊊ bytes** for left-walk; **bytes sealed**.

### Gaps

- Product `value_type` for this instantiation vs twin `0051bbc0`.  
- Full dual of range parent `FUN_00407d70` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406c00_FUN_00406c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00406c00_FUN_00406c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406c00.cpp` |
| Function | `docs/reconstruction/functions/aa_00406c00_FUN_00406c00.md` |
| Function named | `docs/reconstruction/functions/aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
StdMap_LowerBound_Tfid_Isnil29 (0x004cb4b0)          [dualed W31-N]
  └─ StdMap_Find_Tfid_Isnil29_Inferred (0x004cba00) [OWN WQ9G-G]
        ├─ FUN_004ea350 (×3 sites)
        ├─ FUN_00807550 (map@+0x244, key TFID@+0x160)
        └─ 0x005dd84d → may CALL insert-or-find 0x004cc400

StdTree_InsertAndRebalance_Isnil29_Inferred (0x00406c40) [dualed WQ9E-G]
  (neighborhood)
FUN_00407d70 range erase (undualed)
  ├─ full-clear → StdTree_FreeSubtree_Isnil29_Inferred (0x00406c00) [OWN]
  └─ partial → Map_EraseNode_B (0x00409220) [dualed WQ9E-G]

Phy reinit FUN_009463b0 / FUN_0092f3b0
  └─ free root via 0x00406c00
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cba00` | Port as **pure find**: lower_bound + equality; **RET 8**; ECX=map. Do **not** treat as skill CNDHash lookup or as insert. Pair lower_bound `004cb4b0`. Callers read payload `@+0x20` after hit. |
| `00406c00` | Port as **free-subtree** isnil@**0x29**: right recurse + left walk + `operator_delete`. **Ignore** decomp noreturn. **RET 4**; ECX threaded. Do **not** merge symbol with `Map_FreeSubtree_Isnil29` `0051bbc0` (twin CF, different VA/callers). No value dtor here. |
| Pair with | lower_bound `004cb4b0`; insert `00406c40`; erase node B `00409220`; twin free `0051bbc0`; range parent `00407d70` when dualed |

---

## Process

- OWN VAs only (`0x004cba00`, `0x00406c00`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp false-noreturn + missing left-walk on free; find returns via `*outIt` (EAX left as out ptr).  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cba00-00406c00-wq9gg-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

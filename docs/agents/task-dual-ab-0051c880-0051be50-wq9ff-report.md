# Dual A/B report — WQ9F-F OWN-ONLY (`aa_0051c880`, `aa_0051be50`)

**Date:** 2026-08-04  
**Agent:** WQ9F-F OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051c880`, `0x0051be50`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-3 residual — single erase for isnil1d + free helper for isnil15 Map_EraseRange.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` — **WQ9F-F only**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051c880` Map_EraseNode_Isnil1d_Inferred | **accept-with-gaps** — single erase CF/ABI/isnil@+0x1d/color@+0x1c + post-delete size--/`*out`/`ret 8` sealed |
| `aa_0051be50` Map_FreeSubtree_Isnil15 | **accept-with-gaps** — free-subtree isnil@+0x15; byte left-walk sealed; sole external caller Map_EraseRange_Isnil15 |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; collapse into Map_EraseNode / StdMap free / skill-cast names **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x0051c880` Map_EraseNode_Isnil1d_Inferred

1. **Body:** `0x0051c880`–`0x0051cb36` exclusive (**694 B** / `0x2B6`); `ret` @ `0x0051cb33` (`C2 08 00`); `CC` pad; next `Map_EraseNode` @ `0x0051cb40`. Ghidra body end `0x0051cb06` incomplete — bytes supersede.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = map (`head@+4`, `size@+8`; saved `mov ebp,ecx`)  
   - stack `(void **pOutIt, node *pNode)`  
   - **`ret 8`** (`C2 08 00`)

3. **Identity:** MSVC map/set **single-node erase** for **isnil@+0x1d** / **color@+0x1c** family. Peer role of dualed `Map_EraseNode` (`0x0051cb40`, isnil@+0x29) — **not** the same family.

4. **isnil gate:** if `pNode->isnil@+0x1d` → throw `"invalid map/set<T> iterator"` @ `0x00a152f0`.

5. **Algorithm surface:**  
   - successor via `FUN_0051b690` (isnil@+0x1d)  
   - unlink + RB rebalance (rotates `FUN_00420130` / `FUN_00420180`; min `FUN_0051b670`; max `FUN_00421b90`)  
   - `operator_delete(pNode)` **falls through** (decomp false-noreturn)  
   - if `size > 0`: `size--`; `*pOutIt = successor`

6. **Callers:** sole static **`Map_EraseRange_Isnil1d_Inferred`** (`0x0051d700`) @ `0x0051d79f` (`xref_count=1`).

7. **Name:** `Map_EraseNode_Isnil1d_Inferred` — structural STL + isnil discriminator; pairs with dualed range erase.  
   **Reject:** identity with `Map_EraseNode` / `Map_EraseNode_B` / range-erase itself.

8. **Live decomp plate ≡ original raw CF;** epilogue sealed from bytes only.

### Gaps — `0051c880`

1. Product/PDB symbol; exact `map<K,V>` / value size.  
2. Full rotation-case algebra residual (CF sealed).  
3. Host English beyond range-erase caller chain.  
4. Runtime / bit-exact / differential open.

### Dual A/B — `0051c880`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` | **accept-with-gaps** |

### Files — `0051c880`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051c880_FUN_0051c880.md` |
| Annotated | `docs/reconstruction/raw/aa_0051c880_FUN_0051c880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseNode_Isnil1d_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051c880.cpp` |
| Function | `docs/reconstruction/functions/aa_0051c880_FUN_0051c880.md` |
| Function named | `docs/reconstruction/functions/aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` |

---

## Sealed facts — `0x0051be50` Map_FreeSubtree_Isnil15

1. **Body:** `0x0051be50`–`0x0051be85` exclusive (**53 B** / `0x35`); Ghidra inclusive end `0x0051be84`; `CC` pad after **`ret 4`**.

2. **ABI:** stack **`node*`**; preserves EBX/ESI/EDI; ECX threaded unused; **`ret 4`** (`C2 04 00`).

3. **Identity:** MSVC map/set **subtree free** for **isnil@+0x15** family (same header as dualed `Map_EraseRange_Isnil15`).

4. **Byte-correct algebra** (decomp plate incomplete — false-noreturn on `operator_delete` drops left walk):
   - if isnil → return  
   - loop: free(right @ +8); left = *node; `operator_delete(node)`; node = left; until isnil  

5. **Callers:** self (right recurse); sole external **`Map_EraseRange_Isnil15` / `FUN_0051d7c0`** full-clear @ `0x0051d7dc` (`head->parent` = root).

6. **Name:** `Map_FreeSubtree_Isnil15` — free discriminator for sealed `Map_EraseRange_Isnil15`. Twin CF: `StdMap_FreeSubtree_Isnil15_Inferred` @ `0x004ba770` (different VA/callers — do not alias).

7. **Live decomp plate ≡ original raw;** bytes supersede decomp for left-walk.

### Gaps — `0051be50`

1. Exact map instantiation / value type English (delete-only).  
2. Why separate clone vs `StdMap_FreeSubtree_Isnil15_Inferred` (`0x004ba770`).  
3. Runtime / bit-exact / differential open.

### Dual A/B — `0051be50`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051be50_Map_FreeSubtree_Isnil15.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051be50_Map_FreeSubtree_Isnil15.md` | **accept-with-gaps** |

### Files — `0051be50`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051be50_FUN_0051be50.md` |
| Annotated | `docs/reconstruction/raw/aa_0051be50_FUN_0051be50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051be50.cpp` |
| Function | `docs/reconstruction/functions/aa_0051be50_FUN_0051be50.md` |
| Function named | `docs/reconstruction/functions/aa_0051be50_Map_FreeSubtree_Isnil15.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051c880-0051be50-wq9ff-report.md` |

---

## Chain context (not dualled; evidence only)

```text
Map family (skill neighborhood / isnil discriminators)
  Map_EraseNode                 0x0051cb40  isnil@+0x29  [dualed W19-I]
  Map_EraseNode_B               0x00409220  isnil@+0x29  [dualed WQ9E-G]
  Map_EraseNode_Isnil1d_Inferred 0x0051c880 isnil@+0x1d  [OWN WQ9F-F]
  Map_EraseRange_Isnil1d_Inferred 0x0051d700 free 0051be10 erase 0051c880 [dualed WQ9E-I]
  Map_EraseRange_Isnil15        0x0051d7c0  free 0051be50 [dualed WQ9E-J]
  Map_FreeSubtree_Isnil15       0x0051be50  isnil@+0x15  [OWN WQ9F-F]
  Map_FreeSubtree_Isnil29       0x0051bbc0  isnil@+0x29  [dualed WQ9E-H]
  Map_FreeSubtree_B             0x0051be90  isnil@+0x29  [dualed WQ9E-I]
  StdMap_FreeSubtree_Isnil15_Inferred 0x004ba770 (twin CF; different callers)
  FUN_0051be10                  free isnil@+0x1d (WQ9F-E OWN — not this agent)
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051c880` | Port as map/set **erase iterator/node** for **isnil@+0x1d** / **color@+0x1c**. Preserve throw string, size--, `*out` successor, **`ret 8`**. Do **not** reuse isnil@+0x29 offsets or `Map_EraseNode` callees. Honor decomp false-noreturn trap on delete. |
| `0051be50` | Port **Map_EraseRange_Isnil15 full clear** as free-subtree of root (`head->parent`). Implement **byte-correct left-walk**; keep separate from `004ba770` / isnil29 frees. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); structural names without product English.  
- Odd behavior preserved (decomp truncation on free/erase epilogues).  
- **Terminal false.**

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

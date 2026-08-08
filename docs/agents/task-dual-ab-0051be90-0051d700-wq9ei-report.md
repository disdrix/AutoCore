# Dual A/B report — WQ9E-I OWN-ONLY (`aa_0051be90`, `aa_0051d700`)

**Date:** 2026-08-04  
**Agent:** WQ9E-I OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051be90`, `0x0051d700`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-2 residual dual seal (map/tree helpers near dualed Map_EraseRange / skill hash neighborhood).  
**Partition:** `WAVE_2026-08-04_wq009_depth2_partition_map.md` — **WQ9E-I only**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051be90` Map_FreeSubtree_B | **accept-with-gaps** — free-subtree isnil@+0x29; byte left-walk sealed; sole caller Map_EraseRange_B |
| `aa_0051d700` Map_EraseRange_Isnil1d_Inferred | **accept-with-gaps** — range erase CF/ABI/isnil@+0x1d sealed; free 0051be10 + erase 0051c880 |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; collapse into Map_EraseRange / MapFloatTfid free rejected; skill-cast names rejected.

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Sealed facts — `0x0051be90` Map_FreeSubtree_B

1. **Body:** `0x0051be90`–`0x0051bec5` exclusive (**53 B** / `0x35`); Ghidra inclusive end `0x0051bec4`; `CC` pad after **`ret 4`**.

2. **ABI:** stack **`node*`**; preserves EBX/ESI/EDI; ECX threaded unused; **`ret 4`** (`C2 04 00`).

3. **Identity:** MSVC map/set **subtree free** for large-node family **`isnil@+0x29`** (same header as `Map_EraseRange_B` / `Map_EraseNode`).

4. **Byte-correct algebra** (decomp plate incomplete — false-noreturn on `operator_delete` drops left walk):
   - if isnil → return  
   - loop: free(right @ +8); left = *node; `operator_delete(node)`; node = left; until isnil  

5. **Callers:** self (right recurse); sole external **`Map_EraseRange_B` / `FUN_0051d880`** full-clear @ `0x0051d89c` (`head->parent` = root).

6. **Name:** `Map_FreeSubtree_B` — free discriminator for sealed `Map_EraseRange_B` (vs `FUN_0051bbc0` used by `Map_EraseRange`). Twin CF: `MapFloatTfid_FreeSubtree_Isnil29_Inferred` @ `0x0058da00`.

7. **Live decomp plate ≡ original raw;** bytes supersede decomp for left-walk.

### Gaps — `0051be90`

1. Why second isnil@+0x29 free exists vs `FUN_0051bbc0` (value type / size).  
2. Twin free `FUN_0051bbc0` dual (WQ9E-H OWN — not this agent).  
3. Product/PDB map type English.  
4. Runtime / bit-exact / differential open.

---

## Sealed facts — `0x0051d700` Map_EraseRange_Isnil1d_Inferred

1. **Body:** `0x0051d700`–`0x0051d7b4` exclusive (**180 B** / `0xB4`); Ghidra inclusive end `0x0051d7b3`; `CC` pad; next sibling range-erase at `0x0051d7c0`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = map (`head@+4`, `size@+8`)  
   - stack `(void **out_it, node *first, node *last)`  
   - **`ret 0x0c`** (`C2 0C 00`) at full-clear and partial exits  

3. **Identity:** MSVC map/set **range erase** for node family **`isnil@+0x1d`** — same CF size/shape as `Map_EraseRange` but **not** the isnil@+0x29 family.

4. **Full-range fast path** when `first == *head && last == head`:  
   - `FUN_0051be10(head->parent)` free tree  
   - reset head parent/left/right to head; `size = 0`  
   - `*out_it = *head`  

5. **Partial path:** while `first != last`:  
   - inline tree successor (**isnil@+0x1d**)  
   - `FUN_0051c880(map, &first, first)` — single-node erase (throw string `invalid map/set<T> iterator`)  
   - advance to precomputed successor; `*out_it = first`  

6. **Callers:** map host complete dtor **`FUN_0051e120`** @ `0x0051e132` only (`xref_count=1`).

7. **Name:** `Map_EraseRange_Isnil1d_Inferred` — structural STL; isnil offset discriminates from `Map_EraseRange` / `_B`.

8. **Live ≡ raw CF** (2026-08-04 re-verify).

### Gaps — `0051d700`

1. Product/PDB symbol; exact `map<K,V>` / value size.  
2. Free-subtree `FUN_0051be10` and erase-node `FUN_0051c880` dual open (not OWN).  
3. Host class English for `FUN_0051e120`.  
4. Runtime / bit-exact / differential open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x0051be90` | `reviews/A_aa_0051be90_Map_FreeSubtree_B.md` | `reviews/B_aa_0051be90_Map_FreeSubtree_B.md` | **accept-with-gaps** |
| `0x0051d700` | `reviews/A_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md` | `reviews/B_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_0051be90` / `Map_FreeSubtree_B`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051be90_Map_FreeSubtree_B.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051be90_Map_FreeSubtree_B.md` |
| Function record | `docs/reconstruction/functions/aa_0051be90_Map_FreeSubtree_B.md` |
| Scaffold alias | `docs/reconstruction/functions/aa_0051be90_FUN_0051be90.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_B.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_0051be90.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051be90_FUN_0051be90.md` |
| Annotated | `docs/reconstruction/raw/aa_0051be90_FUN_0051be90.annotated.md` |

### `aa_0051d700` / `Map_EraseRange_Isnil1d_Inferred`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md` |
| Scaffold alias | `docs/reconstruction/functions/aa_0051d700_FUN_0051d700.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Map_EraseRange_Isnil1d_Inferred.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_0051d700.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051d700_FUN_0051d700.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d700_FUN_0051d700.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051be90-0051d700-wq9ei-report.md` |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0051d880` | `Map_EraseRange_B` — sole external caller of `Map_FreeSubtree_B` |
| `0x0051c7c0` | `Map_EraseRange` isnil@+0x29 (free via `FUN_0051bbc0`) |
| `0x0051bbc0` | free-subtree twin for Map_EraseRange (WQ9E-H OWN) |
| `0x0051be10` | free-subtree isnil@+0x1d (callee of this range erase) |
| `0x0051c880` | single-node erase isnil@+0x1d (callee) |
| `0x0051d7c0` | range erase isnil@+0x15 (WQ9E-J OWN) |
| `0x0051e120` | map host complete dtor calling `Map_EraseRange_Isnil1d_Inferred` |
| `0x0058da00` | `MapFloatTfid_FreeSubtree_Isnil29_Inferred` twin free CF |
| `0x004bacf0` | `StdMap_EraseRange_Inferred` isnil@+0x15 peer pattern |

---

## AutoCore impact

### `0051be90`

- Port **Map_EraseRange_B full clear** as free-subtree of root (`head->parent`), not a single `operator_delete`.  
- Implement **byte-correct left-walk** free; do not trust decompiler-only plate.  
- Keep **separate** from `FUN_0051bbc0` / MapFloatTfid free even though isnil offset matches.

### `0051d700`

- Port range erase for **isnil@+0x1d** maps: full clear via `FUN_0051be10` + head reset; partial via successor + `FUN_0051c880`.  
- **Do not** reuse isnil@+0x29 offsets from `Map_EraseRange` / `Map_EraseNode`.  
- ABI: **`thiscall` + `ret 0x0c`** — three stack args (out, first, last).  
- Parent merge should register isnil-discriminated name + matrix row (out of agent scope).

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md`  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

# Dual A/B report — WQ9D-H OWN-ONLY (`aa_0051c7c0`, `aa_0051d880`)

**Date:** 2026-08-04  
**Agent:** WQ9D-H OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051c7c0`, `0x0051d880`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities skill-bank helpers, partition WQ9D-H).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051c7c0` Map_EraseRange | **accept-with-gaps** — range erase CF/ABI/isnil@+0x29 sealed; K/V English open |
| `aa_0051d880` Map_EraseRange_B | **accept-with-gaps** — twin sealed; free-subtree discriminator Confirmed |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; chain-of-caller / skill-cast names rejected; twin collapse rejected.

---

## Sealed facts — `0x0051c7c0` Map_EraseRange

1. **Body:** `0x0051c7c0`–`0x0051c873` (**180 B** exclusive); `CC` pad; next at `0x0051c880`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = map (`head@+4`, `size@+8`)  
   - stack `(void **out_it, node *first, node *last)`  
   - **`ret 0x0c`** (`C2 0C 00`) at full-clear and partial exits  

3. **Identity:** MSVC map/set **range erase** for large-node family **`isnil@+0x29`** (same as dualed `Map_EraseNode` / `Map_ExactFindByIntKey`).

4. **Full-range fast path** when `first == *head && last == head`:  
   - `FUN_0051bbc0(head->parent)` free tree  
   - reset head parent/left/right to head; `size = 0`  
   - `*out_it = *head`  

5. **Partial path:** while `first != last`:  
   - inline tree successor (isnil@+0x29)  
   - `Map_EraseNode(map, &first, first)` — bytes restore `ECX = map` before call (decomp plate omits formal)  
   - advance to precomputed successor; `*out_it = first`  

6. **Callers:**  
   - `CVOGHBAIBase_GetTargetFromAggro` @ `0x00639170`, `0x006391d0`  
   - map host dtor `FUN_0051da30` @ `0x0051da42`  

7. **Name:** `Map_EraseRange` — structural STL (peer of `Map_EraseNode`).  
   **Reject:** `Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051c7c0`.

8. **Live ≡ raw CF** (2026-08-04 re-verify).

### Gaps — `0051c7c0`

1. Product/PDB symbol; exact `map<K,V>` / `set<K>`.  
2. Free-subtree `FUN_0051bbc0` not dual-owned.  
3. Per-caller payload English (aggro vs other).  
4. Runtime / bit-exact / differential open.

---

## Sealed facts — `0x0051d880` Map_EraseRange_B

1. **Body:** `0x0051d880`–`0x0051d933` (**180 B** exclusive); `CC` pad; next at `0x0051d940`.

2. **ABI:** same as `Map_EraseRange` — **`__thiscall`**, three stack args, **`ret 0x0c`**.

3. **Twin CF:** full clear vs partial successor + `Map_EraseNode`; **isnil@+0x29**.

4. **Discriminator:** full-clear free-subtree **`FUN_0051be90`** (not `FUN_0051bbc0`). Separate MSVC instantiation despite shared isnil offset.

5. **Callers:** map host dtor **`FUN_0051e180`** @ `0x0051e192` only (`xref_count=1`).

6. **Name:** `Map_EraseRange_B` — keep distinct from `Map_EraseRange`.

7. **Live ≡ raw CF** (2026-08-04 re-verify).

### Gaps — `0051d880`

1. Value-type / size reason for second instantiation.  
2. Free-subtree `FUN_0051be90` dual open.  
3. Host class English for `FUN_0051e180`.  
4. Runtime / bit-exact open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x0051c7c0` | `reviews/A_aa_0051c7c0_Map_EraseRange.md` | `reviews/B_aa_0051c7c0_Map_EraseRange.md` | **accept-with-gaps** |
| `0x0051d880` | `reviews/A_aa_0051d880_Map_EraseRange_B.md` | `reviews/B_aa_0051d880_Map_EraseRange_B.md` | **accept-with-gaps** |

---

## Files

### `aa_0051c7c0` / `Map_EraseRange`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051c7c0_Map_EraseRange.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051c7c0_Map_EraseRange.md` |
| Function record | `docs/reconstruction/functions/aa_0051c7c0_Map_EraseRange.md` |
| Scaffold alias | `docs/reconstruction/functions/aa_0051c7c0_FUN_0051c7c0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Map_EraseRange.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_0051c7c0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051c7c0_FUN_0051c7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051c7c0_FUN_0051c7c0.annotated.md` |

### `aa_0051d880` / `Map_EraseRange_B`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051d880_Map_EraseRange_B.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051d880_Map_EraseRange_B.md` |
| Function record | `docs/reconstruction/functions/aa_0051d880_Map_EraseRange_B.md` |
| Scaffold alias | `docs/reconstruction/functions/aa_0051d880_FUN_0051d880.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Map_EraseRange_B.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_0051d880.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051d880_FUN_0051d880.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d880_FUN_0051d880.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051c7c0-0051d880-wq9dh-report.md` |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0051cb40` | `Map_EraseNode` — single-node erase (callee of both) |
| `0x0051bbc0` | free-subtree for `Map_EraseRange` full clear |
| `0x0051be90` | free-subtree for `Map_EraseRange_B` full clear |
| `0x0051c150` | `Map_ExactFindByIntKey` (same isnil@+0x29 family) |
| `0x0051d700` | range erase sibling **isnil@+0x1d** |
| `0x0051d7c0` | range erase sibling **isnil@+0x15** |
| `0x004bacf0` | `StdMap_EraseRange_Inferred` (isnil@+0x15 peer pattern) |
| `0x0051da30` / `0x0051e180` | map host complete dtors calling owned units |
| `0x00638ec0` | `CVOGHBAIBase_GetTargetFromAggro` (caller of `Map_EraseRange`) |

---

## AutoCore impact

### `Map_EraseRange` / `Map_EraseRange_B`

- Client STL helpers. Ports use standard `map::erase(first, last)` / container clear — preserve full-range fast path and successor-before-erase loop.  
- Do **not** omit `ECX = map` on single-node erase (decomp trap).  
- Do **not** merge the two instantiations; free-subtree callees differ.  
- Not cast-request / LocalCastValidate logic — skill residual **container** helpers only (aggro map prune + map host teardown).  
- Distinct from smaller-node families (`isnil@+0x15` / `+0x1d`).

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

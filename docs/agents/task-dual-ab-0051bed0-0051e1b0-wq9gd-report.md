# Dual A/B report — WQ9G-D OWN-ONLY (`aa_0051bed0`, `aa_0051e1b0`)

**Date:** 2026-08-04  
**Agent:** WQ9G-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051bed0`, `0x0051e1b0`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-4 residual — free helper for Map_EraseRange_Isnil15_B + map tidy host of isnil15_B family.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` — **WQ9G-D only**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051bed0` Map_FreeSubtree_Isnil15_B | **accept-with-gaps** — free-subtree isnil@+0x15; byte left-walk sealed; sole external caller Map_EraseRange_Isnil15_B |
| `aa_0051e1b0` Map_Tidy_FreeHead_Isnil15_B | **accept-with-gaps** — tidy CF/ABI/nulls sealed by bytes (decomp incomplete); product map host open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; collapse into twin free/tidy / skill-cast names **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x0051bed0` Map_FreeSubtree_Isnil15_B

1. **Body:** `0x0051bed0`–`0x0051bf05` exclusive (**53 B** / `0x35`); Ghidra inclusive end `0x0051bf04`; `CC` pad after **`ret 4`**.

2. **ABI:** stack **`node*`**; preserves EBX/ESI/EDI; ECX threaded unused; **`ret 4`** (`C2 04 00`).

3. **Identity:** MSVC map/set **subtree free** for **isnil@+0x15** family (same header as dualed `Map_EraseRange_Isnil15_B`). Twin CF of dualed `Map_FreeSubtree_Isnil15` (`0x0051be50`) — different VA/callers.

4. **Byte-correct algebra** (decomp plate incomplete — false-noreturn on `operator_delete` drops left walk):
   - if isnil → return  
   - loop: free(right @ +8); left = *node; `operator_delete(node)`; node = left; until isnil  

5. **Callers:** self (right recurse @ `0x0051bee7`); sole external **`Map_EraseRange_Isnil15_B` / `FUN_0051d940`** full-clear @ `0x0051d95c` (`head->parent` = root).

6. **Name:** `Map_FreeSubtree_Isnil15_B` — free discriminator for sealed `Map_EraseRange_Isnil15_B`.  
   **Reject:** identity merge with `Map_FreeSubtree_Isnil15` / `StdMap_FreeSubtree_Isnil15_Inferred` / isnil29 frees.

7. **Live decomp plate ≡ original raw;** bytes supersede decomp for left-walk.

### Gaps — `0051bed0`

1. Exact map instantiation / value type English (delete-only).  
2. Why separate clone vs `Map_FreeSubtree_Isnil15` (`0x0051be50`).  
3. Runtime / bit-exact / differential open.

### Dual A/B — `0051bed0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md` | **accept-with-gaps** |

### Files — `0051bed0`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051bed0_FUN_0051bed0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bed0_FUN_0051bed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil15_B.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051bed0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051bed0_FUN_0051bed0.md` |
| Function named | `docs/reconstruction/functions/aa_0051bed0_Map_FreeSubtree_Isnil15_B.md` |

---

## Sealed facts — `0x0051e1b0` Map_Tidy_FreeHead_Isnil15_B

1. **Body:** `0x0051e1b0`–`0x0051e1dd` inclusive (**46 B** / `0x2E`); exclusive end `0x0051e1de`; `CC` pad after bare `ret`. Ghidra body end `0x0051e1cf` incomplete — **bytes supersede**.

2. **ABI:** **`__fastcall`/`__thiscall`-style** ECX = map*; void; **bare `RET`** (`C3`). head@+4, size@+8.

3. **Algorithm (bytes authority — decompiler incomplete):**  
   - Full-range erase: `Map_EraseRange_Isnil15_B(map, &out, *head, head)` @ `0x0051d940` (call site `0x0051e1c2`)  
   - `operator_delete(head)`  
   - Null head and size  
   - **Does not free map facade**

4. **Identity:** 46 B twin of dualed `Map_Tidy_FreeHead` (`0x0051da30`); erase callee is dualed `Map_EraseRange_Isnil15_B`. Discriminate vs `FUN_0051e150` (isnil15 tidy without `_B`), `Map_Tidy_FreeHead_B` (isnil29 `_B`), `Map_Tidy_FreeHead_Isnil1d_Inferred`.

5. **Caller:** atexit vector dtor `FUN_009c3980` = `_eh_vector_destructor_iterator_(&DAT_00b04288, 0xc, 3, FUN_0051e1b0)` — **3** map facades (stride `0xc`) at `0x00b04288`. DATA xref also `0x009c0b00`.

6. **Name:** `Map_Tidy_FreeHead_Isnil15_B` — structural High; pairs `Map_EraseRange_Isnil15_B`. Reject facade complete dtor; reject identity merge with other tidy peers.

7. **Decompile ⊊ bytes** for post-delete nulls; **bytes sealed**.

### Gaps — `0051e1b0`

1. Product `map<K,V>` / host class English for static array `0x00b04288`.  
2. Peer tidy `FUN_0051e150` not OWN.  
3. Runtime / bit-exact open.

### Dual A/B — `0051e1b0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md` | **accept-with-gaps** |

### Files — `0051e1b0`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051e1b0_FUN_0051e1b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051e1b0_FUN_0051e1b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_Isnil15_B.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051e1b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051e1b0_FUN_0051e1b0.md` |
| Function named | `docs/reconstruction/functions/aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051bed0-0051e1b0-wq9gd-report.md` |

---

## Chain context (not dualled; evidence only)

```text
Map family (skill neighborhood / isnil discriminators)
  Map_EraseRange_Isnil15        0x0051d7c0  free 0051be50        [dualed WQ9E-J]
  Map_FreeSubtree_Isnil15       0x0051be50  isnil@+0x15          [dualed WQ9F-F]
  Map_Tidy_FreeHead (peer)      0x0051e150  → Map_EraseRange_Isnil15  [not OWN]
  Map_EraseRange_Isnil15_B      0x0051d940  free 0051bed0        [dualed WQ9F-J]
  Map_FreeSubtree_Isnil15_B     0x0051bed0  isnil@+0x15          [OWN WQ9G-D]
  Map_Tidy_FreeHead_Isnil15_B   0x0051e1b0  → Map_EraseRange_Isnil15_B [OWN WQ9G-D]
       └─ atexit FUN_009c3980 vector-dtor DAT_00b04288[3] (stride 0xc)

  Map_Tidy_FreeHead             0x0051da30  → Map_EraseRange        [dualed]
  Map_Tidy_FreeHead_B           0x0051e180  → Map_EraseRange_B      [dualed WQ9F-H]
  Map_Tidy_FreeHead_Isnil1d_Inferred 0x0051e120 → EraseRange isnil1d [dualed WQ9F-G]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051bed0` | Port **Map_EraseRange_Isnil15_B full clear** as free-subtree of root (`head->parent`). Implement **byte-correct left-walk**; keep separate from `0051be50` / `004ba770` / isnil29 frees. |
| `0051e1b0` | Port as map tidy free-head: full erase via **EraseRange_Isnil15_B**, free sentinel, null head+size. Do **not** free facade. Bare RET. Trust bytes over Ghidra noreturn collapse after delete. Vector-dtor consumer: 3×12 B maps at `0x00b04288`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); structural names without product English.  
- Odd behavior preserved (decomp truncation on free/tidy epilogues).  
- **Terminal false.**

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

# Dual A/B report — WQ9E-J OWN-ONLY (`aa_0051d7c0`, `aa_0051da30`)

**Date:** 2026-08-04  
**Agent:** WQ9E-J OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051d7c0`, `0x0051da30`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-2 residual — map/tree helpers near dualed `Map_EraseRange` / `Map_EraseRange_B` skill neighborhood.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051d7c0` Map_EraseRange_Isnil15 | **accept-with-gaps** — range erase CF/ABI/isnil@+0x15 sealed; K/V English open |
| `aa_0051da30` Map_Tidy_FreeHead | **accept-with-gaps** — tidy CF/ABI/null epilogue sealed; host class English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; isnil29 merge / facade complete-dtor / chain-of-caller names **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x0051d7c0` Map_EraseRange_Isnil15

1. **Body:** `0x0051d7c0`–`0x0051d873` inclusive (**180 B** / `0xB4`); `CC` pad; next `Map_EraseRange_B` @ `0x0051d880`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = map (`head@+4`, `size@+8`)  
   - stack `(void **out_it, node *first, node *last)`  
   - **`ret 0x0c`** (`C2 0C 00`) at full-clear and partial exits  

3. **Identity:** MSVC map/set **range erase** for **isnil@+0x15** family (same offset family as dualed `StdMap_EraseRange_Inferred` @ `0x004bacf0`; **not** isnil@+0x29 `Map_EraseRange` / `Map_EraseRange_B`).

4. **Full-range fast path** when `first == *head && last == head`:  
   - `FUN_0051be50(head->parent)` free tree  
   - reset head parent/left/right to head; `size = 0`  
   - `*out_it = *head`  

5. **Partial path:** while `first != last`:  
   - inline tree successor (isnil@+0x15)  
   - `FUN_0051ce00(map, &first, first)` — bytes restore `ECX = map` before call (decomp plate omits formal)  
   - advance to precomputed successor; `*out_it = first`  

6. **STL seal via callee:** `FUN_0051ce00` throws `"invalid map/set<T> iterator"`.

7. **Callers:**  
   - map tidy peer `FUN_0051e150` @ `0x0051e162`  
   - large host dtor `FUN_0052f260` @ `0x0052f533` (full erase map @ `this-300`)  

8. **Name:** `Map_EraseRange_Isnil15` — structural STL + isnil discriminator.  
   **Reject:** identity with `Map_EraseRange` / `Map_EraseRange_B` / `StdMap_EraseRange_Inferred`.

9. **Live ≡ raw CF** (2026-08-04 re-verify).

### Gaps — `0051d7c0`

1. Product/PDB name; exact `map<K,V>` / `set<K>`.  
2. Free-subtree `FUN_0051be50` / erase `FUN_0051ce00` not dual-owned.  
3. Per-caller payload English.  
4. Runtime / bit-exact / differential open.

### Dual A/B — `0051d7c0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051d7c0_Map_EraseRange_Isnil15.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051d7c0_Map_EraseRange_Isnil15.md` | **accept-with-gaps** |

### Files — `0051d7c0`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051d7c0_FUN_0051d7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d7c0_FUN_0051d7c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseRange_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051d7c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051d7c0_FUN_0051d7c0.md` |
| Function named | `docs/reconstruction/functions/aa_0051d7c0_Map_EraseRange_Isnil15.md` |

---

## Sealed facts — `0x0051da30` Map_Tidy_FreeHead

1. **Body:** `0x0051da30`–`0x0051da5d` inclusive (**46 B** / `0x2E`); exclusive end `0x0051da5e`; `CC` pad.

2. **ABI:** **`ECX = map*`** (`56 8B F1`); bare **`ret`** (`C3`); void; no stack formals; no SEH in body.

3. **Algorithm (bytes authority):**  
   - full-range `Map_EraseRange(map, &out, *head, head)`  
   - `operator_delete(head)` sentinel  
   - **`head = 0; size = 0`** (decomp false-noreturn drops this)  

4. **Does not free map facade** — outer caller (`FUN_00518ec0`) may `operator_delete` the map object after return.

5. **Callee:** dualed **`Map_EraseRange`** (`0x0051c7c0`, isnil@+0x29).

6. **Callers:**  
   - `FUN_00518ec0` @ `0x00518fd3` (object map slot `+0x68`)  
   - SEH `Unwind@009a8e4c`  

7. **Name:** `Map_Tidy_FreeHead` — peer shape of dualed `StdTree_Tidy_FreeHead_Bare_Val12` (same 46 B tidy template).  
   **Reject:** scalar deleting dtor of facade; identity with erase-range itself.

8. **Live core CF ≡ raw**; **epilogue sealed from bytes only**.

### Gaps — `0051da30`

1. Product English for host class owning map at `+0x68`.  
2. Peer tidies `FUN_0051e150` / `FUN_0051e180` not OWN.  
3. Runtime / bit-exact open.

### Dual A/B — `0051da30`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051da30_Map_Tidy_FreeHead.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051da30_Map_Tidy_FreeHead.md` | **accept-with-gaps** |

### Files — `0051da30`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051da30_FUN_0051da30.md` |
| Annotated | `docs/reconstruction/raw/aa_0051da30_FUN_0051da30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051da30.cpp` |
| Function | `docs/reconstruction/functions/aa_0051da30_FUN_0051da30.md` |
| Function named | `docs/reconstruction/functions/aa_0051da30_Map_Tidy_FreeHead.md` |

---

## Chain context (not dualled; evidence only)

```text
Map family (skill neighborhood)
  Map_EraseRange          0x0051c7c0  isnil@+0x29  free 0051bbc0   [dualed WQ9D-H]
  Map_EraseRange_B        0x0051d880  isnil@+0x29  free 0051be90   [dualed WQ9D-H]
  Map_EraseRange_Isnil15  0x0051d7c0  isnil@+0x15  free 0051be50   [OWN WQ9E-J]
  Map_Tidy_FreeHead       0x0051da30  → Map_EraseRange + free head  [OWN WQ9E-J]
  FUN_0051e150            tidy peer → Map_EraseRange_Isnil15
  FUN_0051e180            tidy peer → Map_EraseRange_B
  StdMap_EraseRange_Inferred 0x004bacf0 isnil@+0x15 (different free/erase)
  StdTree_Tidy_FreeHead_Bare_Val12 0x0040d6d0  (46 B tidy template peer)
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051d7c0` | Port as `map`/`set` erase range or bit-exact tree with **isnil@+0x15**. Do **not** reuse isnil@+0x29 `Map_EraseRange` free/erase callees. Preserve full-range fast path + successor-before-erase; restore **ECX=map** on single-node erase. |
| `0051da30` | Map tidy only: full clear → free sentinel → null head/size. Do **not** treat as facade scalar deleting dtor. Honor decomp false-noreturn trap (always null after delete). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); structural names without product English.  
- Odd behavior preserved (decomp truncation on tidy; ECX restore on erase).  
- **Terminal false.**

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

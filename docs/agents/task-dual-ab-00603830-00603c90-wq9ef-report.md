# Dual A/B report — WQ9E-F OWN-ONLY (`0x00603830`, `0x00603c90`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9E-F**  
**Scope:** VAs `0x00603830`, `0x00603c90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-F**.  
**Work item:** WQ-009 depth-2 residual dual seal (tree erase/rebalance peer callers of dualed isnil29 helpers).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00603830` StdTree_EraseAndRebalance_Val28_Isnil29_Inferred | **accept** — erase CF/ABI/isnil/size--/ret8/throw/sole caller sealed |
| `aa_00603c90` StdTree_InsertAndRebalance_Val28_Isnil29_Inferred | **accept** — insert CF/ABI/max-size/ret10/buynode/rotates sealed |

Path A (fidelity): both **accept**.  
Path B (adversarial): no CF rejects; Ghidra noreturn-on-delete / body-end truncation closed via `read_memory`; Val12 isnil mix-up rejected.

---

## VA `0x00603830` — sealed facts

1. **Body:** `0x00603830`–`0x00603b03` exclusive (**723 B** / `0x2D3`); pad `CC`. Ghidra lists ~`0x00603acf` (false truncate on `operator_delete` noreturn).

2. **ABI:** **`__thiscall`**; ECX = map shell (`head@+4`, `size@+8`); stack `(Node** outIt, Node* node)`; **`RET 8`**.

3. **Semantics:** MSVC-style **tree erase + rebalance**:
   - If `node->isnil` (@**+0x29**) → throw `"invalid map/set<T> iterator"` (`0x00a152f0` / `DAT_00acc34c`).
   - `FUN_004cb270` advances out-iterator (successor).
   - Splice replacement; fix root / leftmost (`StdTree_Min_Isnil29` `FUN_0051b5d0`) / rightmost (`StdTree_Max_Isnil29_Inferred` `FUN_00421b50`).
   - If erased **black** (color @**+0x28**): RB fixup with `StdTree_Lrotate_Isnil29` / `StdTree_Rrotate_Isnil29_Inferred`.
   - Free mapped heap @**+0x14** if non-null; zero +0x14..+0x1C; `operator_delete(node)`.
   - If size>0 then **size--**; `*outIt` = successor.

4. **Node family:** Val28 payload @+0x0C; node size **0x2C** (buynode peer); isnil@+0x29.

5. **Classification:** worker (callees: iter++, min/max, L/R rotate, delete, throw).

6. **Callers:** **1** — `FUN_00604280` (erase-range) @ `0x0060431f`.

7. **Name:** `StdTree_EraseAndRebalance_Val28_Isnil29_Inferred` (Ghidra `FUN_00603830`). Product demangle open → `_Inferred`.

8. **Decompile ≡ raw CF**; epilogue sealed via `read_memory` (size-- / ret 8).

### Gaps — `00603830`

- Product / MSVC demangle for map typedef.  
- Full mapped-type English beyond heap free @+0x14.  
- Dual of caller `FUN_00604280` / `FUN_004cb270` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00603830_FUN_00603830.md` |
| Annotated | `docs/reconstruction/raw/aa_00603830_FUN_00603830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00603830.cpp` |
| Function | `docs/reconstruction/functions/aa_00603830_FUN_00603830.md` |
| Function named | `docs/reconstruction/functions/aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md` |

---

## VA `0x00603c90` — sealed facts

1. **Body:** `0x00603c90`–`0x00603e7a` exclusive (**490 B** / `0x1EA`); pad `CC`.

2. **ABI:** **`__thiscall`**; ECX = map shell; stack `(Node** outIt, char addLeft, Node* where, Val28* value)`; **`RET 0x10`**.

3. **Semantics:** MSVC-style **always-insert + rebalance**:
   - If `size > 0x9249247` → throw `"map/set<T> too long"` (`DAT_00acc388`).
   - Buynode `FUN_00603b10` (`operator_new(0x2C)` + `FUN_00603730`); **size++**.
   - Link empty / left (`addLeft!=0`) / right; update leftmost/rightmost.
   - While parent red: uncle recolor or L/R rotate (`FUN_004192a0` / `FUN_004192f0`).
   - Root black; `*outIt = new node`.

4. **Node family:** same Val28 / isnil@+0x29 / color@+0x28 / node **0x2C**.

5. **Classification:** worker (buynode + rotates + throw).

6. **Callers:** **1** — `FUN_00603f00` (int-key lower-bound + insert) @ `0x00603f4a`.

7. **Name:** `StdTree_InsertAndRebalance_Val28_Isnil29_Inferred` (Ghidra `FUN_00603c90`). Product demangle open → `_Inferred`.

8. **Decompile ≡ raw CF**; ret 0x10 sealed via `read_memory`.

### Gaps — `00603c90`

- Product demangle / map typedef English.  
- Multimap vs unique — caller always sets inserted=1 (open).  
- Dual of buynode/ctor/caller (not OWN).  
- Inline rotate arm equivalent to Lrotate — port detail.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00603c90_FUN_00603c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00603c90_FUN_00603c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00603c90.cpp` |
| Function | `docs/reconstruction/functions/aa_00603c90_FUN_00603c90.md` |
| Function named | `docs/reconstruction/functions/aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00603830-00603c90-wq9ef-report.md` |

---

## AutoCore impact

### `00603830` / `00603c90`

- Port as **shared MSVC `_Tree` erase/insert** for the **Isnil29 / Val28 / node 0x2C** family — not skill-cast managers.
- Keep **separate** from Val12 (`isnil@+0x19`, node `0x1C`, max `0x15555553`) and isnil15 clones.
- Pair with dualed helpers: `StdTree_Lrotate_Isnil29`, `StdTree_Rrotate_Isnil29_Inferred`, `StdTree_Min_Isnil29`, `StdTree_Max_Isnil29_Inferred`.
- Erase: preserve heap free @+0x14 and **size--** after node delete (decompiler may omit).
- Insert: max-size gate **`0x9249247`**; always-insert (caller owns uniqueness).
- Parent merge (not this agent): VERIFICATION_MATRIX / NAMING_REGISTRY / skills-abilities residual / WORK_QUEUE lockstep.

---

## Parent merge checklist (for integrator — not done here)

- [ ] `VERIFICATION_MATRIX.md` rows for both VAs  
- [ ] `NAMING_REGISTRY.md` entries + rename-history  
- [ ] `systems/skills-abilities.md` residual table  
- [ ] WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

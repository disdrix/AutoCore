# Dual A/B report — WQ9E-G OWN-ONLY (`0x00406c40`, `0x00409220`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9E-G**  
**Scope:** VAs `0x00406c40`, `0x00409220` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-G**.  
**Work item:** WQ-009 depth-2 residual dual seal (tree insert/erase callers of dualed Lrotate/Rrotate/Min/Max isnil29).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00406c40` StdTree_InsertAndRebalance_Isnil29_Inferred | **accept-with-gaps** — always-insert + RB CF/ABI/RET0x10/isnil@+0x29/rot callees sealed; product T residual |
| `aa_00409220` Map_EraseNode_B | **accept-with-gaps** — erase CF/ABI/RET8/post-delete size--/*out sealed; twin of Map_EraseNode; product residual |

Path A (fidelity): as above.  
Path B (adversarial): no CF rejects; decompiler noreturn/unreachable traps closed via bytes; Val12/isnil15/string-key mix-ups rejected; scaffold Named_CalleeOf rejected.

---

## VA `0x00406c40` — sealed facts

1. **Body:** `0x00406c40`–`0x00406dd5` exclusive (**405 B** / `0x195`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map*; stack `Node** out`, `char addLeft`, `Node* where`, `Val* value`; **RET 0x10**.
3. **Semantics:** MSVC-style **always-insert + RB rebalance**:
   - If `size > 0x0AAAAAA8` → throw `"map/set<T> too long"`.
   - Buynode `FUN_00407e30` → `operator_new(0x30)` + `FUN_004098d0` (links + 0x18 value @+0x10 + color red + isnil=0 @+0x29).
   - `size++`; link under where (empty / left / right + leftmost/rightmost).
   - While parent color@+0x28 red: uncle recolor or L/R rotate cases.
   - Root black; `*out = new node`.
4. **isnil / color:** **+0x29** / **+0x28**.
5. **Rotates:** dualed `StdTree_Lrotate_Isnil29` (`0x004192a0`), `StdTree_Rrotate_Isnil29_Inferred` (`0x004192f0`); ECX=map.
6. **Caller (1):** `FUN_00406040` insert-or-find (uint key @ node+0x10) — 2 call sites.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertAndRebalance_Isnil29_Inferred` (Ghidra `FUN_00406c40`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; max-size imm + RET sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for map value type (0x18 @+0x10).  
- Buynode / parent insert-or-find undualed residuals.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406c40_FUN_00406c40.md` |
| Annotated | `docs/reconstruction/raw/aa_00406c40_FUN_00406c40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406c40.cpp` |
| Function | `docs/reconstruction/functions/aa_00406c40_FUN_00406c40.md` |
| Function named | `docs/reconstruction/functions/aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |

---

## VA `0x00409220` — sealed facts

1. **Body (bytes):** `0x00409220`–`0x004094b4` exclusive (**660 B** / `0x294`); pad `CC`. Ghidra listed end `0x00409484` incomplete (cuts before size--/ret).
2. **ABI:** **`__thiscall`**; ECX = map*; stack `Node** outIt`, `Node* pNode`; **RET 8**.
3. **Semantics:** MSVC-style **single-node erase**:
   - isnil@+0x29 non-zero → throw `"invalid map/set<T> iterator"`.
   - Successor via `FUN_004cb270`; unlink + RB rebalance.
   - Leftmost/rightmost refresh: `StdTree_Min_Isnil29` / `StdTree_Max_Isnil29_Inferred`.
   - Black-node fixup uses dualed L/R rotates (ECX=map).
   - `operator_delete(node)` **falls through** (decomp false-noreturn).
   - If `size > 0` then `size--`; `*outIt = successor`.
4. **isnil / color:** **+0x29** / **+0x28**.
5. **Twin:** dualed `Map_EraseNode` @ `0x0051cb40` (same CF/callees/family; different throw construction).
6. **Callers (5):** `FUN_00407d70`, `FUN_005a0470`, `FUN_005a3750`, `FUN_00807550`, `FUN_008078b0`.
7. **Xrefs:** 6 UNCONDITIONAL_CALL.
8. **Name:** `Map_EraseNode_B` (Ghidra `FUN_00409220`). Structural twin naming (peer `Map_EraseRange_B`).
9. **Decompile ≡ raw CF** with post-delete commit sealed by `read_memory`.

### Gaps

- Product / PDB for this instantiation vs twin `0x0051cb40`.  
- Per-caller payload English.  
- Range parent `FUN_00407d70` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409220_Map_EraseNode_B.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409220_Map_EraseNode_B.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409220_FUN_00409220.md` |
| Annotated | `docs/reconstruction/raw/aa_00409220_FUN_00409220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseNode_B.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409220.cpp` |
| Function | `docs/reconstruction/functions/aa_00409220_FUN_00409220.md` |
| Function named | `docs/reconstruction/functions/aa_00409220_Map_EraseNode_B.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00406c40-00409220-wq9eg-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00406c40` | Port as **shared RB always-insert** for **isnil@+0x29** maps — not skill logic. Max size **`0x0AAAAAA8`**; node **0x30** / value **0x18** @+0x10; color@+0x28. Pair with Lrotate `004192a0` / Rrotate `004192f0`. Parent lower-bound is separate (`00406040`). |
| `00409220` | Port as **single-node erase** twin of `Map_EraseNode` (`0051cb40`). **RET 8**; post-delete **size--** + **`*outIt=succ`**. Do not trust decomp noreturn on delete. Pair Min `0051b5d0` / Max `00421b50` / successor `004cb270` / L-R rotates. |
| Pair with | dualed isnil29 rotates + Min/Max; twin erase `Map_EraseNode`; range wrappers when dualed. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (tree insert/erase residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00406c40`, `0x00409220`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp false-noreturn on erase delete; “unreachable” two-child blocks live; max-size 0x0AAAAAA8.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

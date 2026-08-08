# Dual A/B report — WQ9E-E OWN-ONLY (`0x004cb740`, `0x004cbb60`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9E-E**  
**Scope:** VAs `0x004cb740`, `0x004cbb60` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-E**.  
**Work item:** WQ-009 depth-2 residual dual seal (tree erase/rebalance callers of dualed StdTree min/max/rotates isnil@+0x29).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cb740` StdTree_EraseAndRebalance_Isnil29_Inferred | **accept-with-gaps** — CF/ABI/RET8/epilogue size--/*outIt/isnil@+0x29/3 callers sealed; product demangle open |
| `aa_004cbb60` StdTree_InsertAndRebalance_Isnil29_Inferred | **accept-with-gaps** — CF/ABI/RET10/buynode0x30/max-size/11 xrefs sealed; product demangle open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): decompiler noreturn-delete and Val12/isnil mix-ups falsified; scaffold aggro/VOG product names narrowed.

---

## VA `0x004cb740` — sealed facts

1. **Body:** `0x004cb740`–`0x004cb9f5` exclusive (**693 B** / `0x2B5`). Ghidra lists end `0x004cb9c6` (false noreturn on `operator_delete`). Final **`C2 08 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map shell*; stack `Node** outIt`, `Node* node`; **RET 8**.
3. **Semantics:** MSVC `_Tree` **single-node erase + RB rebalance** (isnil@+0x29):
   - nil → throw `"invalid map/set<T> iterator"` / `DAT_00acc34c`
   - `FUN_004cb270` successor prep
   - splice replacement; fix root / leftmost (`FUN_0051b5d0`) / rightmost (`FUN_00421b50`)
   - if erased black → recolor + `FUN_004192a0` L / `FUN_004192f0` R
   - `operator_delete`; if size>0 size--; `*outIt = succ`
4. **Layout:** left+0 parent+4 right+8; value ~+0x10 (6 dwords via insert buynode); color+0x28; isnil+0x29; node **0x30**.
5. **Classification:** worker (shared map erase helper).
6. **Callers (3):** `FUN_004c8610`, `FUN_004c8780`, `FUN_004cbaa0`.
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Twins / peers:** insert OWN `0x004cbb60`; Val12 erase `StdTree_EraseAndRebalance_Val12` @ `0x004e4130` (isnil@+0x19) — **do not merge**.
9. **Name:** `StdTree_EraseAndRebalance_Isnil29_Inferred` (Ghidra `FUN_004cb740`). Prior VOG_DEBUG_STOP callee **narrow**. Product demangle open → `_Inferred`.
10. **Decompile ≡ raw CF**; epilogue sealed by **bytes** (decomp drops size--/*outIt/ret).

### Gaps

- Product English / MSVC demangle for map value_type.  
- English name for successor `FUN_004cb270`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cb740_FUN_004cb740.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb740_FUN_004cb740.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb740.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb740_FUN_004cb740.md` |
| Function named | `docs/reconstruction/functions/aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md` |

---

## VA `0x004cbb60` — sealed facts

1. **Body:** `0x004cbb60`–`0x004cbd4b` exclusive (**491 B** / `0x1EB`); terminal **`C2 10 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map shell*; stack `Node** outIt`, `char addLeft`, `Node* where`, `Val24* value`; **RET 0x10**.
3. **Semantics:** MSVC `_Tree` **always-insert + RB rebalance** (isnil@+0x29):
   - if `size > 0xAAAAAA8` → `"map/set<T> too long"` / `DAT_00acc388`
   - `FUN_005a2de0(head, where, head, value, color=0)` — `operator_new(0x30)`; 6 dwords @ +0x10; color@+0x28; isnil=0@+0x29
   - `size++`; link empty / left / right; update extremities
   - while parent red: uncle recolor or L/R rotate (`004192a0`/`004192f0`; one L path inlined with isnil@+0x29)
   - root black; `*outIt = new`
4. **Classification:** worker (shared map insert helper).
5. **Callers (3 funcs / 11 xrefs):** `FUN_004cbe20` (2), `FUN_004cbee0` (2), `FUN_004cc220` (7).
6. **Twins / peers:** erase OWN `0x004cb740`; Val12 insert `StdTree_InsertAndRebalance_Val12` @ `0x005ae4e0` — **do not merge**.
7. **Name:** `StdTree_InsertAndRebalance_Isnil29_Inferred` (Ghidra `FUN_004cbb60`). Prior GetTargetFromAggro callee **narrow**. Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x10 sealed by **bytes**.

### Gaps

- Product English / MSVC demangle for map value_type.  
- Exact key/mapped field meanings of 6-dword payload.  
- Parent insert-or-find shells not dualed here.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbb60.cpp` |
| Function | `docs/reconstruction/functions/aa_004cbb60_FUN_004cbb60.md` |
| Function named | `docs/reconstruction/functions/aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cb740` | Port as **MSVC tree erase+rebalance** on isnil@**0x29** nodes: throw on nil; successor prep; splice; min/max extremity; black RB fixup with isnil29 L/R; delete; size--; `*outIt`. **Do not** trust decompiler noreturn on delete. **Do not** merge with Val12 erase (`isnil@+0x19`). |
| `004cbb60` | Port as **MSVC tree always-insert+rebalance** on same node family: max `0xAAAAAA8`; buynode 0x30 / 6-dword value; link; RB insert fixup; `*outIt`. Parent owns uniqueness. **Do not** merge with Val12 insert (`max 0x15555553`). |
| Pair with | isnil29 min `0051b5d0`, max `00421b50`, Lrotate `004192a0`, Rrotate `004192f0`; buynode `005a2de0`; successor `004cb270`; Val12 peers only as layout contrast |

---

## Process

- OWN VAs only (`0x004cb740`, `0x004cbb60`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp false-noreturn epilogue; inlined Lrotate on insert; addLeft==0 → right.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (or containers/shared tree table)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cb740-004cbb60-wq9ee-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

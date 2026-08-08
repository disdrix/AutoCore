# Dual A/B report — WQ9H-H OWN-ONLY (`0x00408590`, `0x00408640`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-H**  
**Scope:** VAs `0x00408590`, `0x00408640` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-H**.  
**Work item:** WQ-009 depth-5 residual dual seal (CNDHash/freelist **neighborhood** residual leaves — tree iterator isnil31 + vector InsertN elem **0x10**).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00408590` StdTree_IteratorIncrement_Isnil31 | **accept** — successor CF/ABI/EDX/isnil@+0x31/leaf sealed; product map type residual only |
| `aa_00408640` StdVector_InsertN_Elem0x10_Inferred | **accept-with-gaps** — insert-N CF/ABI/ECX·EDX/RET8/stride0x10/1.5× growth sealed; product POD + helpers residual |

Path A (fidelity): as above.  
Path B (adversarial): freelist / predecessor / wrong-isnil / thiscall-dword / Input_Poll domain misreads rejected; scaffold void traps closed via bytes.

---

## VA `0x00408590` — sealed facts

1. **Body:** `0x00408590`–`0x004085db` exclusive (**75 B** / `0x4B`); pad `CC` then freelist leaf `0x004085e0`.
2. **ABI:** **EDX** = `node**` (iterator); ECX unused phantom; void; plain **`RET` (`C3`)** ×2 exits.
3. **Semantics:** MSVC-style **tree iterator successor** (`operator++`):
   - if current is_nil(+0x31): no-op
   - else if right non-nil: `*it` = leftmost of right subtree
   - else climb parents while was right-child; `*it` = that ancestor (may be nil head)
4. **is_nil:** every guard **`+0x31`** (`80 xx 31 00`).
5. **Callees:** none (leaf).
6. **Callers (2):** `FUN_00408ed0` @ `0x00408f38`; `FUN_00944770` @ `0x00944956` — both `LEA EDX` then `CALL`.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_IteratorIncrement_Isnil31` (Ghidra `FUN_00408590`). Naming by isnil offset (family convention); product map English open.
9. **Twins (CF):** isnil `+0x19` `00457cc0`; `+0x29` `004cb270`; `+0x49` `00568200`.
10. **Decompile ≡ raw CF**; full body hex sealed via `read_memory`.
11. **Not** CNDHash freelist — residual **neighbor** of `FUN_004085e0` only.

### Gaps

- Product map key/value English type for isnil@+0x31 family.  
- Color bit unused here.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408590_StdTree_IteratorIncrement_Isnil31.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00408590_StdTree_IteratorIncrement_Isnil31.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408590_FUN_00408590.md` |
| Annotated | `docs/reconstruction/raw/aa_00408590_FUN_00408590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil31.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408590.cpp` |
| Function | `docs/reconstruction/functions/aa_00408590_FUN_00408590.md` |
| Function named | `docs/reconstruction/functions/aa_00408590_StdTree_IteratorIncrement_Isnil31.md` |

---

## VA `0x00408640` — sealed facts

1. **Body:** `0x00408640`–`0x0040887c` exclusive (**572 B** / `0x23C`).
2. **ABI:** **ECX** = count; **EDX** = vector* (+4 begin, +8 end, +0xC capEnd); stack `where`, `const T* value` (4 dwords); **`RET 8`** (`C2 08 00`).
3. **Semantics:** MSVC-style **vector insert-n** for **0x10**-byte elements:
   - capacity/size via `>>4`; growth 1.5× (`cap+(cap>>1)`) else exact `size+count`
   - max elems `0x0FFFFFFF`; overflow → `FUN_00418130`
   - realloc: `operator_new` → copy prefix (`00409b60`) → construct-N (`00407000`) → copy suffix → `operator_delete` → write triad
   - in-place: two sub-paths by distance-to-end vs count + fill helpers
4. **Stride:** **0x10** (caller site also `ADD …,0x10`).
5. **Callees:** `00418130`, `operator_new`/`delete`, `00409b60`, `00407000`, `0040a670`, `0045f050`, `00465bc0` (helpers undualed residual).
6. **Caller (1):** `FUN_00930360` @ `0x009305c5` (`MOV ECX,1`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_InsertN_Elem0x10_Inferred` (Ghidra `FUN_00408640`). Product demangle open → `_Inferred`.
9. **Twins (role):** dword InsertN `004073a0`; InsertN 0x28 residual `00408050`.
10. **Decompile ≡ raw CF**; RET + stride sealed via `read_memory`. Decompiler noreturn-on-delete is false.

### Gaps

- Product / POD English type (16-byte layout).  
- Relocate/fill callees undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408640_FUN_00408640.md` |
| Annotated | `docs/reconstruction/raw/aa_00408640_FUN_00408640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408640.cpp` |
| Function | `docs/reconstruction/functions/aa_00408640_FUN_00408640.md` |
| Function named | `docs/reconstruction/functions/aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00408590-00408640-wq9hh-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00408590` | Port as **shared tree iterator ++** for **isnil@+0x31** family. **EDX**=`node**`; void; plain ret. Do **not** fold into freelist `004085e0` or other isnil twins. |
| `00408640` | Port as **vector insert-n** for **elem stride 0x10**. **ECX**=count, **EDX**=vec*, stack where+value, **ret 8**. 1.5× growth. Pair with dword InsertN twin pattern; not domain Input_Poll logic. |
| Pair with | Tree iterator isnil family (`00457cc0`/`004cb270`/`00568200`); vector InsertN dword (`004073a0`); undualed fill helpers when dualed. |
| Naming caution | **Not** CNDHash freelist despite VA neighborhood of `0x004085e0`. **Not** InsertN 0x28 / dword thiscall without ABI remap. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (or util/container system note — these are **tree/vector** helpers, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00408590`, `0x00408640`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not blank Ghidra paste).  
- Odd behavior preserved: decompiler ECX phantom on iterator; `operator_delete` false noreturn on insert realloc.  
- `_Inferred` where English unproven (InsertN); Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

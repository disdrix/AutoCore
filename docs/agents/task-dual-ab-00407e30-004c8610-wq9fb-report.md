# Dual A/B report — WQ9F-B OWN-ONLY (`0x00407e30`, `0x004c8610`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9F-B**  
**Scope:** VAs `0x00407e30`, `0x004c8610` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-B**.  
**Work item:** WQ-009 depth-3 residual dual seal (buynode for insert `00406c40` + erase caller of `StdTree_EraseAndRebalance_Isnil29`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00407e30` StdTree_Buynode_Val24_Isnil29_Inferred | **accept-with-gaps** — stdcall RET0x14 / new(0x30) / ctor Val24 isnil29 / sole insert caller sealed; product demangle open |
| `aa_004c8610` Object_AggroMap_DecayOrPurge_Inferred | **accept-with-gaps** — thiscall RET4 / 0.85f decay / keep-or-erase / dualed erase callee / TFID clear-target sealed; product English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): Val12/thiscall-map/always-erase/GetTargetFromAggro mix-ups **rejected**; chain-of-caller scaffold names **narrowed**.

---

## VA `0x00407e30` — sealed facts

1. **Body:** `0x00407e30`–`0x00407eb4` exclusive (**132 B** / `0x84`); terminal **`C2 14 00`**; pad follows.
2. **ABI:** **`__stdcall`**; stack `left, parent, right, value*, color`; **RET 0x14**; EAX = node* \| null.
3. **Semantics:** MSVC-style **tree buynode**:
   - SEH frame (`LAB_009bc6e1`).
   - `operator_new(0x30)`.
   - On success: `FUN_004098d0` thiscall — links + **6 dwords** value @+0x10 + color@+0x28 + **isnil=0** @+0x29.
   - On OOM: return null (no construct).
4. **Caller (1):** `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x00406c40`) @ `0x00406cad` with `(head, where, head, value, color=0)`.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Twin contrast:** `FUN_005a2de0` same layout, **inlined** ctor, **no** SEH (insert `004cbb60` path) — **do not merge**.
7. **Name:** `StdTree_Buynode_Val24_Isnil29_Inferred` (Ghidra `FUN_00407e30`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x14 sealed via `read_memory` / disasm.

### Gaps

- Product / MSVC demangle for map value_type.  
- Ctor helper `FUN_004098d0` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407e30_FUN_00407e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00407e30_FUN_00407e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val24_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407e30.cpp` |
| Function | `docs/reconstruction/functions/aa_00407e30_FUN_00407e30.md` |
| Function named | `docs/reconstruction/functions/aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` |

---

## VA `0x004c8610` — sealed facts

1. **Body:** `0x004c8610`–`0x004c8779` exclusive (**361 B** / `0x169`); terminal **`C2 04 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = object*; stack `char forcePurge`; void; **RET 4**.
3. **Semantics:** Object map @ **+0x154** (head @ **+0x158**) inorder walk:
   - `score@+0x20 = (int)((float)score * 0.85f)` — `DAT_00aaa680` bytes `9A 99 59 3F`.
   - If `forcePurge==0` **and** scaled ≠ old → **keep**; advance isnil29 successor.
   - Else → if TFID key @+0x10 matches host MI identity @ primary+0x44/48/4c → **vtbl+0x258** clear-target with `DAT_009cb8c0..cc`; successor; **`StdTree_EraseAndRebalance_Isnil29_Inferred`** on map shell.
4. **Callee:** dualed erase `0x004cb740` (WQ9E-E).
5. **Caller (1):** `FUN_00638ac0` @ `0x00638af1` with **forcePurge=0** (AI timer `0x5dc`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Peer evidence:** `FUN_004c8780` same map + `Object_ResolveFromTFID((TFID_16*)(node+0x10))` — seals key as TFID / aggro list.
8. **Name:** `Object_AggroMap_DecayOrPurge_Inferred` (Ghidra `FUN_004c8610`). Product method English open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET 4 + float sealed by bytes.

### Gaps

- Product / PDB method + host class English.  
- forcePurge!=0 live callers (none in this image).  
- Peer `004c8780` / clear-target slot undualed (WQ9F-C owns `004c8780`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004c8610_FUN_004c8610.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8610_FUN_004c8610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_AggroMap_DecayOrPurge_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c8610.cpp` |
| Function | `docs/reconstruction/functions/aa_004c8610_FUN_004c8610.md` |
| Function named | `docs/reconstruction/functions/aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00407e30` | Port as **shared Val24/isnil29 buynode**: `new(0x30)` + construct links/value/color/isnil0; **stdcall RET 0x14**; null on OOM. Pair only with insert `00406c40` family — **not** Val12 buynodes, **not** no-SEH twin `005a2de0`. |
| `004c8610` | Port as **aggro map decay tick**: score `*= 0.85f` then keep non-zero or erase via isnil29 erase; map shell **object+0x154**. forcePurge=0 is the live AI path. Clear selection when erasing host TFID entry. |
| Pair with | insert `00406c40`; erase `004cb740`; peer purge/resolve `004c8780` (other OWN); AI caller `00638ac0` |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (or containers / aggro residual table)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00407e30`, `0x004c8610`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw for `00407e30` preserved; re-verify **appended**; clean plates rewritten with meaningful names.  
- Odd behavior preserved: SEH on buynode; forcePurge branch with no live nonzero caller; decomp uses `param_2` as erase outIt storage.  
- `_Inferred` where English unproven; Terminal **false**.

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00407e30-004c8610-wq9fb-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

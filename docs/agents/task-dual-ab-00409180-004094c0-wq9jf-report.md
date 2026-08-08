# Dual A/B report — WQ9J-F OWN-ONLY (`0x00409180`, `0x004094c0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9J-F**  
**Scope:** VAs `0x00409180`, `0x004094c0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-F**.  
**Work item:** WQ-009 depth-7 residual dual seal (00409xxx neighborhood residual leaves — **tree head isnil31 size 0x38** + **StringKey erase isnil2d**).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409180` StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred | **accept-with-gaps** — alloc/ABI/color@+0x30/isnil@+0x31/sole head-caller sealed; product Val36 open |
| `aa_004094c0` StdMap_StringKey_EraseAndRebalance_Inferred | **accept-with-gaps** — erase CF/ABI ret0xC/isnil@+0x2D/string key/size-- sealed; product map English + helper duals residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash, Client-ctor scaffold, isnil29/31 merge, void/noreturn-delete, range-as-unit, ECX-thiscall misread **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409180` — sealed facts

1. **Body:** `0x00409180`–`0x00409209` exclusive (**137 B** / `0x89`).
2. **ABI:** no stack formals; **EAX = node\***; plain **`RET` (`C3`)**. Decompiler `void` is **false**.
3. **Semantics:** MSVC-style **empty tree head buynode**:
   - SEH (`LAB_009bc670`) + `operator_new(0x38)`.
   - left/parent/right = 0.
   - **color@+0x30 = 1**; **isnil@+0x31 = 0**.
4. **Caller (1):** `FUN_00405f20` @ `0x00405f3a` — install as `_Myhead`; isnil=1; L/P/R = self; size = 0.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` (Ghidra `FUN_00409180`). Reject scaffold `Named_CalleeOf_*Client_Constructor*`.
7. **Twins (do not merge):** isnil29 head `0x00408a30` (0x30); isnil21 empty `0x004088f0` (0x28); isnil31 iterator++ `0x00408590`.
8. **Decompile ≡ raw CF**; color/isnil/RET sealed via `read_memory`.

### Gaps

- Product map `value_type` (Val36 @ +0x0C).  
- Ctor wrapper `FUN_00405f20` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409180_FUN_00409180.md` |
| Annotated | `docs/reconstruction/raw/aa_00409180_FUN_00409180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409180.cpp` |
| Function | `docs/reconstruction/functions/aa_00409180_FUN_00409180.md` |
| Function named | `docs/reconstruction/functions/aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md` |

---

## VA `0x004094c0` — sealed facts

1. **Body:** `0x004094c0`–`0x0040977d` exclusive (**701 B** / `0x2BD`). Ghidra lists end `0x00409749` (false noreturn on delete).
2. **ABI:** **3 stack args** (map*, outIt**, node*); **`RET 0x0C`** (`C2 0C 00`).
3. **Semantics:** MSVC-style **StringKey tree erase + RB rebalance**:
   - isnil → `"invalid map/set<T> iterator"` / `DAT_00acc34c`
   - successor `FUN_0042ac40`; unlink; fix head extremities (min `0044e180` / max `0042ac20`)
   - if erased black: recolor + Lrot `0044e010` / Rrot `0042a840`
   - `~basic_string(node+0xC)` → `operator_delete` → size-- → `*outIt` → ret 0xC
4. **Layout:** color@**+0x2C**, isnil@**+0x2D**, string@**+0x0C**, node **0x30** (peer insert `0x00430b60`).
5. **Caller (1):** `FUN_00407f90` @ `0x0040802e` (erase-range loop).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `StdMap_StringKey_EraseAndRebalance_Inferred` (Ghidra `FUN_004094c0`).
8. **Twins (do not merge):** isnil29 erase `0x004cb740`; isnil31 head OWN peer `0x00409180`; insert peer `0x00430b60`.
9. **Decompile ≡ raw CF** for throw/unlink/rebalance; **epilogue sealed via bytes** (decompiler drops size--/*outIt/ret).

### Gaps

- Product / English host map type.  
- Erase-range parent + rotate/min/max helpers undualed.  
- Two-child splice plate (decomp unreachable warnings).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004094c0_FUN_004094c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004094c0_FUN_004094c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_EraseAndRebalance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004094c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004094c0_FUN_004094c0.md` |
| Function named | `docs/reconstruction/functions/aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409180-004094c0-wq9jf-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409180` | Port as **shared tree head buy** for **isnil@+0x31 / node 0x38**. No stack args; **EAX=node\***; bare ret. Do **not** fold into isnil29 head `00408a30` or StringKey erase. |
| `004094c0` | Port as **StringKey map erase+rebalance** for **isnil@+0x2D / color@+0x2C / string@+0x0C**. **3 stack args**, **ret 0xC**. Pair with insert peer `00430b60`; use isnil2d rotates (`0044e010`/`0042a840`), not isnil29 pair. |
| Pair with | isnil31 iterator `00408590`; StringKey insert `00430b60`; undualed erase-range `00407f90` when dualed. |
| Naming caution | **OWN pair is two families** (isnil31 head shell vs isnil2d StringKey erase) — shared only by residual VA neighborhood, not layout. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (or util/container system note — these are **tree** helpers, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409180`, `0x004094c0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not blank Ghidra paste).  
- Odd behavior preserved: decompiler void on head buy; false noreturn on erase delete; decomp "unreachable" mid blocks on two-child splice.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

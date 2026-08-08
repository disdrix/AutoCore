# Dual A/B report — WQ9J-G OWN-ONLY (`0x00409780`, `0x00409820`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-G**  
**Scope:** VAs `0x00409780`, `0x00409820` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs + call-site bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-G**.  
**Work item:** WQ-009 depth-7 residual dual seal (00409xxx residual neighborhood — tree **BuyHead isnil2D** + **predecessor isnil29 EDX**).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409780` StdTree_BuyHeadNode_Isnil2D_Inferred | **accept-with-gaps** — cdecl RET0 / new(0x30) / color@+0x2c isnil@+0x2d / sole head-install caller sealed; product Val32 open |
| `aa_00409820` StdTree_Predecessor_Isnil29_Edx_Inferred | **accept-with-gaps** — EDX Node** / isnil@+0x29 / three-arm pred / leaf sealed; product map type residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash, successor, isnil29-head merge, ECX-only ABI, same-family co-location, and scaffold chain-of-caller plates **rejected/narrowed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409780` — sealed facts

1. **Body:** `0x00409780`–`0x00409809` inclusive (**138 B** / `0x8A`); bare **`RET` (`C3`)**.
2. **ABI:** no stack formals; **EAX = node***; bare RET. Decompiler `void` is **wrong**.
3. **Semantics:** MSVC-style **empty tree head shell**:
   - SEH (`LAB_009bc660`) + `operator_new(0x30)`.
   - left/parent/right = 0 (MSVC field-address null checks).
   - **color@+0x2c = 1**; **isnil@+0x2d = 0**.
4. **Classification:** worker (`operator_new`).
5. **Xrefs (1 UNCONDITIONAL_CALL):** `FUN_00406190` @ `0x004061aa`.
6. **Caller pattern:** install as `_Myhead`; isnil=1; L/P/R = self; size = 0.
7. **Twins (do not merge):** isnil29 BuyHead `FUN_00408a30` (color@+0x28 isnil@+0x29); isnil21 empty `FUN_004088f0` (size 0x28).
8. **Name:** `StdTree_BuyHeadNode_Isnil2D_Inferred` (Ghidra `FUN_00409780`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET + layout sealed via `read_memory` (`88 58 2c` / `88 50 2d`).

### Gaps

- Product / English field map for Val32 region (+0x0C..+0x2B).  
- Tree ctor `FUN_00406190` undualed.  
- OOM field-check odd if `new` returns null without throw.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409780_FUN_00409780.md` |
| Annotated | `docs/reconstruction/raw/aa_00409780_FUN_00409780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409780.cpp` |
| Function | `docs/reconstruction/functions/aa_00409780_FUN_00409780.md` |
| Function named | `docs/reconstruction/functions/aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md` |

---

## VA `0x00409820` — sealed facts

1. **Body:** `0x00409820`–`0x00409870` inclusive (**81 B** / `0x51`); pad `CC` then residual peer `0x00409880` (WQ9J-H).
2. **ABI:** **EDX** = `Node**` (iterator); ECX unused phantom; void; plain **`RET` (`C3`)** ×3 exits.
3. **Semantics:** MSVC-style **tree iterator predecessor** (`operator--` / `_Dec`):
   - if current is_nil(+0x29): `*it` = right (header → max)
   - else if left non-nil: `*it` = rightmost of left subtree
   - else climb parents while was **left**-child; `*it` = that ancestor
4. **is_nil:** every guard **`+0x29`** (`80 xx 29 00`).
5. **Callees:** none (leaf).
6. **Callers (1):** `FUN_00405bd0` @ `0x00405c33` — `LEA EDX,[ESP+0x0C]` then `CALL`.
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Predecessor_Isnil29_Edx_Inferred` (Ghidra `FUN_00409820`). Scaffold Named_CalleeOf_Error_Receiv **reject**. Product open → `_Inferred`.
9. **Twin:** ECX ABI `StdTree_Predecessor_Isnil29_Inferred` (`0x004cb4f0`) — same CF/isnil, different register.
10. **Decompile ≡ raw CF**; EDX/isnil sealed via `read_memory` + call-site bytes.

### Gaps

- Product map key/value English (caller uses 2-dword hi/lo keys).  
- Why EDX clone exists beside ECX twin `0x004cb4f0`.  
- Insert-or-find parent `FUN_00405bd0` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409820_FUN_00409820.md` |
| Annotated | `docs/reconstruction/raw/aa_00409820_FUN_00409820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Predecessor_Isnil29_Edx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409820.cpp` |
| Function | `docs/reconstruction/functions/aa_00409820_FUN_00409820.md` |
| Function named | `docs/reconstruction/functions/aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00406190  (tree ctor / head install)
  └─ StdTree_BuyHeadNode_Isnil2D_Inferred (0x00409780) [OWN WQ9J-G]
        → head isnil=1 @+0x2d; circular L/P/R; size=0

FUN_00405bd0  (insert-or-find / hi-lo key walk)
  └─ StdTree_Predecessor_Isnil29_Edx_Inferred (0x00409820) [OWN]
        → LEA EDX; three-arm pred; isnil@+0x29

Peers (not OWN this partition):
  StdTree_BuyHeadNode_Isnil29_Inferred (0x00408a30)     [WQ9H-J]
  StdTree_Predecessor_Isnil29_Inferred (0x004cb4f0)     [WQ9G-B, ECX]
  StdTree_IteratorIncrement_Isnil31 (0x00408590)        [WQ9H-H successor]
  WQ9J-H: 0x00409880 / 0x004098d0                       [adjacent residual]
```

**Naming caution:** co-located VAs are **not** the same node family — BuyHead is isnil@**+0x2d**; predecessor is isnil@**+0x29**.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409780` | Port as **empty tree head factory** isnil@**+0x2d** size **0x30**: new + zero links + color=1 isnil=0; **EAX** return. Callers set isnil=1 + self-link. **Not** freelist; **not** isnil29 BuyHead `00408a30`. |
| `00409820` | Port as **leaf predecessor** isnil@**+0x29** with **EDX** iterator: header→right / left-max / climb-left-child. Twin of ECX `004cb4f0`. **Not** successor. |
| Pair with | Ctor `00406190`; insert-or-find `00405bd0`; ECX pred `004cb4f0`; isnil29 head `00408a30` when wiring maps. |

---

## Process

- OWN VAs only (`0x00409780`, `0x00409820`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + call-site bytes. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank-line paste).  
- Odd behavior preserved: decompiler void return on BuyHead; MSVC field-address null checks; ECX phantom on EDX pred.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (util/container / tree helpers)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409780-00409820-wq9jg-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

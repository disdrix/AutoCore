# Dual A/B report — WQ9J-E OWN-ONLY (`0x00416f00`, `0x00409160`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-E**  
**Scope:** VAs `0x00416f00`, `0x00409160` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-E**.  
**Work item:** WQ-009 depth-7 residual dual seal (00416xxx + 00409xxx residual neighborhood).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416f00` Class_00a733ec_ScalarDeletingDtor_Inferred | **accept-with-gaps** — scalar CF/ABI/vtbl[0]/inline free-cb/flags&1/RET4 sealed; product class English open |
| `aa_00409160` StdTree_Min_Isnil31 | **accept** — min CF/ABI/EAX/isnil@+0x31/leaf sealed; product map type residual only |

Path A (fidelity): as above.  
Path B (adversarial): noreturn-delete / array-dtor / thiscall-on-min / return-isnil / wrong-isnil / UNI_BUTTONS-as-class rejects closed via bytes; product demangle open on scalar → `_Inferred`.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00416f00` — sealed facts

1. **Body:** `0x00416f00`–`0x00416f2e` inclusive (**47 B** / `0x2F`); pad `CC` after **`RET 4`**.
2. **ABI:** **`__thiscall`** — **ECX** = this; stack **flags**; **`RET 4`** (`C2 04 00`); returns **this\*** in EAX. Entry `56 8B F1`.
3. **Semantics:** MSVC **scalar-deleting destructor** for vtbl family **`PTR_FUN_00a733ec`**:
   - Always `*this = 0x00a733ec`.
   - If `this+0x10` free callback ≠ null: cdecl call with `this+0x04` context (`ADD ESP,4`).
   - If `(flags & 1)`: `operator_delete(this)` (**returns** — decompiler noreturn WARNING is **false**).
   - Return this.
4. **Complete teardown is inline** — no separate complete-dtor callee (unlike `004160b0` → `0097a8a0` pattern).
5. **Layout:** object size **0x14** (factories): +0 vtbl, +4 context, +8/+0xc zeros, +0x10 free cb.
6. **Callees:** indirect free @ +0x10; `operator_delete` @ `0x00489822`.
7. **Callers:** none by CALL; **DATA** only — `PTR_FUN_00a733ec[0]` @ `0x00a733ec` = `0x00416f00`.
8. **Xrefs:** 1 DATA (function); vtbl also DATA-written by factories `00416830` / `004168c0`.
9. **Name:** `Class_00a733ec_ScalarDeletingDtor_Inferred` (Ghidra `FUN_00416f00`). Product English open → `_Inferred`. Adjacent UTF-16 `"UNI_BUTTONS"` **not** sealed as class name.
10. **Decompile ≡ raw CF spine**; RET4 + non-noreturn delete sealed via `read_memory`.

### Gaps

- Product / RTTI demangle for class behind `PTR_FUN_00a733ec`.  
- Free-callback `LAB_00573240` + factories undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416f00_FUN_00416f00.md` |
| Annotated | `docs/reconstruction/raw/aa_00416f00_FUN_00416f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a733ec_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416f00.cpp` |
| Function | `docs/reconstruction/functions/aa_00416f00_FUN_00416f00.md` |
| Function named | `docs/reconstruction/functions/aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md` |

---

## VA `0x00409160` — sealed facts

1. **Body:** `0x00409160`–`0x00409172` inclusive (**19 B** / `0x13`); pad `CC`.
2. **ABI:** **EAX** = subtree root `node*`; returns leftmost non-nil in **EAX**; plain **`RET`** (`C3`). Not thiscall.
3. **Semantics:** MSVC-style **tree min / leftmost** (`_Tree_min`):
   - `left = node->left`; if `left->isnil(+0x31)`: return `node`.
   - Else walk `node = left` while `node->left` non-nil; return last real node.
4. **is_nil:** every guard **`+0x31`** (`80 79 31 00`).
5. **Callees:** none (leaf).
6. **Caller (1):** `FUN_00408ed0` @ `0x00408f9d` — `MOV EAX,EDI; CALL; MOV [EBX],EAX` when erased node was head leftmost.
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Min_Isnil31` (Ghidra `FUN_00409160`). Naming by isnil offset (family convention).
9. **Twins (CF):** `StdTree_Min_Isnil29` @ `0x0051b5d0` (stack-arg ABI); peer `StdTree_IteratorIncrement_Isnil31` @ `0x00408590`.
10. **Decompile ≡ walk-left CF**; decomp **void/in_EAX** wrong for return — sealed via call-site EAX store + listing.

### Gaps

- Product map key/value English for isnil@+0x31 family.  
- Color bit unused here.  
- Erase parent `FUN_00408ed0` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409160_StdTree_Min_Isnil31.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00409160_StdTree_Min_Isnil31.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409160_FUN_00409160.md` |
| Annotated | `docs/reconstruction/raw/aa_00409160_FUN_00409160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil31.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409160.cpp` |
| Function | `docs/reconstruction/functions/aa_00409160_FUN_00409160.md` |
| Function named | `docs/reconstruction/functions/aa_00409160_StdTree_Min_Isnil31.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_00a733ec
  [0] = Class_00a733ec_ScalarDeletingDtor_Inferred (0x00416f00)  [OWN WQ9J-E]
FUN_00416830  factory new(0x14) + callback LAB_00573240         [residual]
FUN_004168c0  factory new(0x14) + null callback                 [residual]

FUN_00408ed0  map erase / rebalance isnil@+0x31                 [residual]
  ├─ StdTree_IteratorIncrement_Isnil31 (0x00408590)             [WQ9H-H dualed]
  ├─ StdTree_Min_Isnil31 (0x00409160)                           [OWN WQ9J-E]
  └─ FUN_004043e0  (rightmost / max helper for head->right)     [residual]

StdTree_Min_Isnil29 (0x0051b5d0)  stack-arg twin                [prior dual]
```

Partition co-owns these by residual neighborhood; machine CF is **scalar deleting dtor (callback holder)** + **STL tree min** — unrelated systems beyond partition assignment.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416f00-00409160-wq9je-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416f00` | Port as **scalar deleting only** with **inline** teardown: write vtbl `00a733ec`, optional cdecl free(`+0x10`)(`+0x04`), free host iff `flags&1`, return this, **RET 4**. Object size **0x14**. Do not invent a separate complete-dtor call. |
| `00409160` | Port as **shared tree min** isnil@**+0x31** — **EAX** node in/out, bare ret, leaf. Used by erase `00408ed0` for head leftmost. Twin stack-arg min is `0051b5d0` (isnil@+0x29) — **do not merge ABIs**. |
| Pair with | Factories `00416830`/`004168c0`; erase `00408ed0`; iterator++ `00408590`; Min isnil29 `0051b5d0`. |
| Naming caution | **Not** UNI_BUTTONS class (string adjacency only). **Not** void min (EAX return). **Not** thiscall min. Scalar is **not** the complete-dtor-call pattern of `004160b0`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container/STL residual for Min; util/UI residual for scalar callback holder — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00416f00`, `0x00409160`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp noreturn on scalar delete; decomp void on Min.  
- `_Inferred` where English unproven (scalar); Min role sealed without `_Inferred` (family convention). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

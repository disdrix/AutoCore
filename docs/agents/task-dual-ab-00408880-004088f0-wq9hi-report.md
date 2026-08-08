# Dual A/B report — WQ9H-I OWN-ONLY (`0x00408880`, `0x004088f0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-I**  
**Scope:** VAs `0x00408880`, `0x004088f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-I**.  
**Work item:** WQ-009 depth-5 residual dual seal (CNDHash/freelist neighborhood residual leaves — sealed as **POD 0x138 construct** + **tree empty buynode isnil21**).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00408880` PodCopyConstruct_Elem0x138_Inferred | **accept-with-gaps** — thiscall RET4 / width 0x138 / leaf POD / 2 callers sealed; product event fields open |
| `aa_004088f0` StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred | **accept-with-gaps** — cdecl RET0 / new(0x28) / color@+0x20 isnil@+0x21 / 4 head-init callers sealed; product Val20 open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash identity, isnil29 Val24 merge, void-return, tree-as-vector, and scaffold chain-of-caller plates **rejected/narrowed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00408880` — sealed facts

1. **Body:** `0x00408880`–`0x004088ef` inclusive / exclusive end `0x004088f0` (**112 B** / `0x70`).
2. **ABI:** **`__thiscall`**; ECX = dest; stack `const void* src`; void; **`RET 4`**.
3. **Semantics:** MSVC-style **POD copy-construct** of **0x138** bytes:
   - 14 unrolled dword stores (0x00–0x37).
   - `mov ecx, 0x40; rep movsd` from +0x38 (0x100 bytes).
   - Total **0x138**.
4. **Classification:** leaf (no callees).
5. **Xrefs (2 UNCONDITIONAL_CALL):** `0x004076d0` in `LogicUiEventQueue_InsertN` (`FUN_004076a0`); `0x0040a70e` in `FUN_0040a6e0`.
6. **Name:** `PodCopyConstruct_Elem0x138_Inferred` (Ghidra `FUN_00408880`). Product demangle open → `_Inferred`.
7. **Decompile ≡ raw CF**; RET 4 + width sealed via `read_memory`.

### Gaps

- Product / English field map for 0x138 Logic-UI event record.  
- Placement wrapper `FUN_0040a6e0` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408880_FUN_00408880.md` |
| Annotated | `docs/reconstruction/raw/aa_00408880_FUN_00408880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodCopyConstruct_Elem0x138_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408880.cpp` |
| Function | `docs/reconstruction/functions/aa_00408880_FUN_00408880.md` |
| Function named | `docs/reconstruction/functions/aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` |

---

## VA `0x004088f0` — sealed facts

1. **Body:** `0x004088f0`–`0x00408979` inclusive / exclusive end `0x0040897a` (**138 B** / `0x8A`).
2. **ABI:** **cdecl**; no stack formals; **EAX = node\***; **`RET 0`** (`C3`). Decompiler `void` is **wrong**.
3. **Semantics:** MSVC-style **empty tree buynode**:
   - SEH (`LAB_009bc6c0`) + `operator_new(0x28)`.
   - left/parent/right = 0.
   - **color@+0x20 = 1**; **isnil@+0x21 = 0**.
4. **Classification:** worker.
5. **Xrefs (4 UNCONDITIONAL_CALL):** `FUN_00405560` @ `0x0040557d`; `FUN_00405d00` @ `0x00405d1a`; `FUN_00406100` @ `0x0040611a`; `FUN_00501970` @ `0x00501c4e`.
6. **Caller pattern (all):** install as `_Myhead`; isnil=1; L/P/R = self; size = 0.
7. **Twins (do not merge):** empty-head `FUN_00408a30` (size 0x30 / isnil@+0x29); value buynode `FUN_00408990` (WQ9H-J).
8. **Name:** `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` (Ghidra `FUN_004088f0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF** for stores; return type corrected via callers + epilogue bytes.

### Gaps

- Product map `value_type` (Val20 @ +0x0C).  
- WQ9H-J peers `00408990` / `00408a30` undualed here.  
- Head-init parents undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004088f0_FUN_004088f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004088f0_FUN_004088f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004088f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004088f0_FUN_004088f0.md` |
| Function named | `docs/reconstruction/functions/aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
LogicUiEventQueue_InsertN (0x004076a0)                 [dualed W23-B]
  └─ PodCopyConstruct_Elem0x138_Inferred (0x00408880) [OWN WQ9H-I]
FUN_0040a6e0 placement
  └─ PodCopyConstruct_Elem0x138_Inferred (0x00408880) [OWN]

Tree/map head ctors FUN_00405560 / FUN_00405d00 / FUN_00406100 / FUN_00501970
  └─ StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred (0x004088f0) [OWN]
        → head isnil=1; circular L/P/R; size=0

Peers (WQ9H-J, not OWN):
  FUN_00408990  full value buynode size 0x28 + FUN_004099b0
  FUN_00408a30  empty buynode size 0x30 isnil@+0x29

Contrast (other waves):
  StdTree_Buynode_Val24_Isnil29_Inferred (0x00407e30)  [WQ9F-B]
  CNDHash_FreelistPop_Node0x28                        [different family]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00408880` | Port as **`memcpy(dest, src, 0x138)`** thiscall leaf; **RET 4**. Pair with LogicUi insert-N. **Not** tree/hash. |
| `004088f0` | Port as **empty tree node factory** isnil@**+0x21** size **0x28**: new + zero links + color=1 isnil=0; **EAX** return; cdecl. Head ctors set isnil=1. **Not** freelist pop; **not** isnil29 Val24 buynode. |
| Pair with | InsertN `004076a0`; value buynode `00408990` / empty isnil29 `00408a30` when dualed; char-key map isnil21 family. |
| Naming caution | Neighborhood of CNDHash/freelist residuals is **co-location only** — these two VAs are POD construct + tree empty buy. |

---

## Process

- OWN VAs only (`0x00408880`, `0x004088f0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decompiler void return on buynode; always-true null checks on `node+1`/`node+2`; unrolled+rep-movsd vs single memcpy equivalence.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (util/container / tree helpers — not skill CNDHash domain for these two)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00408880-004088f0-wq9hi-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

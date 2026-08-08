# Dual A/B report — WQ9L-C OWN-ONLY (`0x00403ee0`, `0x004043e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-C**  
**Scope:** VAs `0x00403ee0`, `0x004043e0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-C**.  
**Work item:** WQ-009 depth-9 residual dual seal — **erase-and-rebalance isnil31 callees** (Rrotate + Max).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00403ee0` StdTree_Rrotate_Isnil31_Inferred | **accept** — CF/ABI/RET4/ECX-node/isnil@+0x31/leaf sealed; product residual |
| `aa_004043e0` StdTree_Max_Isnil31 | **accept** — CF/ABI/EAX in-out/RET0/isnil@+0x31/leaf sealed; product residual |

Path A (fidelity): both **accept**.  
Path B (adversarial): L-rotate-as-R / ECX-tree-isnil29 / isnil2D-merge / void-return-max / thiscall-on-max claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00403ee0` — sealed facts

1. **Body:** `0x00403ee0`–`0x00403f2f` inclusive (**80 B** / `0x50`); next prologue `0x00403f30`.
2. **ABI:** **ECX** = pivot node `x*`; stack tree/map*; void; three exits **`RET 4`**. Decompiler shows thiscall without cleanup.
3. **Semantics:** classical **right rotate** about `x`:
   - `y = x->left`; `x->left = y->right`; if `!y->right->isnil(+0x31)` then `y->right->parent = x`.
   - Reparent y; reattach at root / right-child / left-child of parent; `y->right = x`; `x->parent = y`.
   - No recolor (callers write color@+0x30).
4. **Bytes:** `8B018B500889118B5008807A31007503894A048B51048950048B5424048B52043B4A04750C894204894808894104C20400…` (full in raw append).
5. **Callees:** none (leaf).
6. **Callers (5):** erase `FUN_00408ed0` @ `00409091`/`004090c2`/`0040911f`; insert peer `FUN_00403250` @ `00403366`/`0040337a`.
7. **Xrefs:** 5 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Rrotate_Isnil31_Inferred` (Ghidra `FUN_00403ee0`). Product open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + call-site context + `read_memory`.

### Gaps

- Product / MSVC demangle for isnil31 node 0x38 family.  
- Twin L-rotate `00403e90` residual dual (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00403ee0_FUN_00403ee0.md` |
| Annotated | `docs/reconstruction/raw/aa_00403ee0_FUN_00403ee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403ee0.cpp` |
| Function | `docs/reconstruction/functions/aa_00403ee0_FUN_00403ee0.md` |
| Function named | `docs/reconstruction/functions/aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md` |

---

## VA `0x004043e0` — sealed facts

1. **Body:** `0x004043e0`–`0x004043fb` inclusive (**28 B** / `0x1c`); pad `CC`.
2. **ABI:** **EAX** = node* in; returns rightmost non-nil in **EAX**; plain **`RET`**. Decompiler shows void / `in_EAX` phantom.
3. **Semantics:** MSVC `_Tree_max` / **rightmost** walk:
   - Load `node->right`; if isnil@+0x31 early-return original node.
   - Else walk right while child non-nil; return last non-nil.
   - 7-byte `LEA ESP,[ESP]` alignment NOP before loop body.
4. **Callers (1):** erase `FUN_00408ed0` @ `0x00408fbf` — `MOV EAX,EDI; CALL; MOV [EBX+8],EAX` (`head->right = max`).
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** none (leaf).
7. **Name:** `StdTree_Max_Isnil31` (Ghidra `FUN_004043e0`). Mirrors dualed min `StdTree_Min_Isnil31`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + call-site + `read_memory`.

### Gaps

- Product map English (shared isnil31 helper).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004043e0_StdTree_Max_Isnil31.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004043e0_StdTree_Max_Isnil31.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004043e0_FUN_004043e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004043e0_FUN_004043e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil31.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004043e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004043e0_FUN_004043e0.md` |
| Function named | `docs/reconstruction/functions/aa_004043e0_StdTree_Max_Isnil31.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred  [dualed]
  ├─ FUN_00408590  Iterator++ isnil31                     [dualed]
  ├─ FUN_00409160  StdTree_Min_Isnil31                    [dualed]
  ├─ FUN_004043e0  StdTree_Max_Isnil31                    [OWN WQ9L-C]
  ├─ FUN_00403e90  Lrotate isnil31                        [residual]
  ├─ FUN_00403ee0  StdTree_Rrotate_Isnil31_Inferred       [OWN WQ9L-C]
  └─ operator_delete

FUN_00403250  insert/rebalance peer (residual)
  └─ FUN_00403ee0  (shared Rrotate)                       [OWN WQ9L-C]

Compare (do not merge):
  isnil2D Rrot 0042a840 / Lrot 0044e010
  isnil29 Rrot 004192f0 / Max 00421b50 (stack ABI)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00403ee0-004043e0-wq9lc-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00403ee0` | Port as **isnil31 right-rotate**: **ECX = node**, stack map, **RET 4**. Pair with L-rot `00403e90`. Do **not** invert ABI to isnil29 (ECX=tree). Keep distinct from isnil2D `0042a840`. |
| `004043e0` | Port as **isnil31 max/rightmost**: **EAX in/out**, bare **RET**. Pair with min `00409160`. Call site writes `head->right`. Not thiscall; not stack-arg like Max isnil29. |
| Pair with | dualed erase `00408ed0`; dualed min `00409160`; residual L-rot `00403e90`; residual insert peer `00403250`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (STL tree Rrot + Max isnil31 — not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00403ee0`, `0x004043e0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; machine ABI corrections (RET 4 Rrot; EAX Max return).  
- Odd behavior preserved: 7-byte NOP in Max loop align.  
- `_Inferred` where English unproven (Rrot); Max mirrors Min without `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

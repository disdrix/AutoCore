# Dual A/B report — WQ9K-J OWN-ONLY (`0x0042a840`, `0x0040a590`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-J**  
**Scope:** VAs `0x0042a840`, `0x0040a590` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-J**.  
**Work item:** WQ-009 depth-8 residual dual seal (tree R-rotate isnil2D + range-copy twin Elem12).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0042a840` StdTree_Rrotate_Isnil2D_Inferred | **accept** — leaf CF/ABI/isnil@+0x2D/RET4/ECX=node sealed; product residual only |
| `aa_0040a590` StdVector_UninitializedCopy_Elem12_Inferred | **accept-with-gaps** — range CF/ABI/stride0x0C/PodCopy leaf/return dest sealed; product + parent residual |

Path A (fidelity): rotate **accept**; range **accept-with-gaps**.  
Path B (adversarial): left-rotate-merge / isnil29-merge / ECX=tree-on-rotate / thiscall-on-range / stride 0x0C↔0x28 merge / ConstructN-as-range all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0042a840` — sealed facts

1. **Body:** `0x0042a840`–`0x0042a88f` inclusive (**80 B** / `0x50`); three `RET 4` exits.
2. **ABI:** **ECX** = node `x*`; stack tree/map*; void; **`RET 4`**. **Not** ECX=tree (isnil29 invert).
3. **Semantics:** Standard **right rotate**: `y = x->left`; reparent; hang `x` as `y->right`.
4. **isnil:** guard at **`+0x2D`** on `y->right` (`80 7A 2D 00`).
5. **Layout:** left@+0, parent@+4, right@+8; tree head@+4; root = head->parent.
6. **Recolor:** none (no color@+0x2C writes) — pure structural leaf.
7. **Callees:** none (leaf).
8. **Callers (4):** `FUN_00401db0`, `FUN_0042a930`, `FUN_00430b60` (StringKey insert), `FUN_004094c0` (StringKey erase).
9. **Xrefs:** 10 UNCONDITIONAL_CALL.
10. **Name:** `StdTree_Rrotate_Isnil2D_Inferred` (Ghidra `FUN_0042a840`). Product demangle open → `_Inferred`.
11. **Peer L-rotate:** `FUN_0044e010` (same isnil@+0x2D + ECX=node ABI; residual).
12. **Decompile ≡ raw CF**; ABI sealed via `read_memory` + call-site context.

### Gaps

- Product / MSVC demangle.  
- Full dual of peer L-rotate `0044e010` (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0042a840_FUN_0042a840.md` |
| Annotated | `docs/reconstruction/raw/aa_0042a840_FUN_0042a840.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0042a840.cpp` |
| Function | `docs/reconstruction/functions/aa_0042a840_FUN_0042a840.md` |
| Function named | `docs/reconstruction/functions/aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` |

---

## VA `0x0040a590` — sealed facts

1. **Body:** `0x0040a590`–`0x0040a5f4` inclusive (**101 B** / `0x65`).
2. **ABI:** **ECX** = `src_end`; stack `src_begin`, `dest`; **EAX** = advanced dest; plain **`ret`** (`C3`). Free helper (not vector thiscall despite decomp label).
3. **Semantics:** MSVC-style **uninitialized_copy** for **elem 0x0C**:
   - Loop while `src_begin != src_end`.
   - Each step: `PodCopy_Elem12(dest, src)` via dualed `FUN_00409f50` (EAX=dest, ECX=src).
   - Advance both cursors **+0x0C**; return final dest.
4. **SEH:** frame with `LAB_009bd0a0`; try level 0 → −1 on exit.
5. **Callees:** `FUN_00409f50` only.
6. **Callers:** `FUN_004082f0` InsertN Elem12 (2 sites @ `0x004084ea`, `0x0040854e`); trampoline `FUN_00409b40` @ `0x00409b50`.
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_UninitializedCopy_Elem12_Inferred` (Ghidra `FUN_0040a590`). Product demangle open → `_Inferred`.
9. **Twins (CF):** PodCopy leaf `00409f50` (WQ9J-A dualed); range twin 0x28 `0040a520` (WQ9J-A dualed) — keep distinct.
10. **Decompile ≡ raw CF**; empty `FUN_00409f50()` and false thiscall overridden by bytes + call-site context.

### Gaps

- Product / MSVC demangle for 0x0C POD element type.  
- Full dual of trampoline `00409b40` and parent InsertN `004082f0` (roles sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040a590_FUN_0040a590.md` |
| Annotated | `docs/reconstruction/raw/aa_0040a590_FUN_0040a590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem12_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040a590.cpp` |
| Function | `docs/reconstruction/functions/aa_0040a590_FUN_0040a590.md` |
| Function named | `docs/reconstruction/functions/aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00430b60  StdMap_StringKey_InsertNodeAndRebalance  [dualed W22-E]
FUN_004094c0  StdMap_StringKey_EraseAndRebalance_Inferred  [dualed WQ9J-F]
  └─ StdTree_Rrotate_Isnil2D_Inferred (0x0042a840)   [OWN WQ9K-J]
  └─ L-rotate peer FUN_0044e010                        [residual]
  (isnil29 pair 004192a0/004192f0 is different family — ECX=tree)

FUN_004082f0  InsertN Elem12                            [residual]
  └─ StdVector_UninitializedCopy_Elem12_Inferred (0x0040a590)  [OWN WQ9K-J]
       └─ StdVector_PodCopyElement_Elem12_Inferred (0x00409f50)  [WQ9J-A dualed]
FUN_00409b40  thin trampoline → 0040a590                [residual]

// Twin (already dualed WQ9J-A):
FUN_0040a520  StdVector_UninitializedCopy_Elem0x28_Inferred
  └─ PodCopy 0x28 (0x00409f30)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0042a840-0040a590-wq9kj-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0042a840` | Port as **shared tree right-rotate** for **isnil@+0x2D**. **ECX=node**, stack tree, **RET 4**. Pair with L-rotate `0044e010`; StringKey insert `00430b60` / erase `004094c0`. |
| `0040a590` | Port as **shared vector uninitialized_copy** for **elem stride 0x0C**. **ECX**=end, stack begin+dest, **EAX**=dest_end, plain ret. Pair with PodCopy `00409f50`, InsertN `004082f0`. |
| Pair with | isnil2D L-rotate residual; Elem12 PodCopy/ConstructN/InsertN; Elem0x28 range twin (already dualed). |
| Naming caution | **OWN pair is two families** (tree R-rotate isnil2D vs vector Elem12 range) — shared only by partition residual list, not layout. **R-rotate isnil2D is not isnil29** — **ECX roles inverted**. **UninitCopy Elem12 is not UninitCopy 0x28** — stride + leaf ABI differ (ECX vs EDX src). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container / util — **tree rotate** + **vector POD**, not skill domain gameplay)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0042a840`, `0x0040a590`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly context + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Raw bodies preserved; WQ9K-J re-verify sections appended.  

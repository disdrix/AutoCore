# Dual A/B report — WQ9I-C OWN-ONLY (`0x00407060`, `0x004099b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-C**  
**Scope:** VAs `0x00407060`, `0x004099b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-C**.  
**Work item:** WQ-009 depth-6 residual dual seal — isnil21 **insert-or-find** (InsertHint fallback) + **buynode node ctor** Val16/isnil21.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00407060` StdMap_InsertOrFind_PairKey_Isnil21_Inferred | **accept-with-gaps** — CF/ABI/RET8/isnil21/pair-key sealed; insert worker + product residual |
| `aa_004099b0` StdTree_NodeCtor_Val16_Isnil21_Inferred | **accept-with-gaps** — CF/ABI/RET0x14/Val16/isnil21 layout sealed; product value open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): int-key-merge / isnil29-merge / always-insert-only / hit-rewrite / full-buynode-inside-ctor / freelist / RET0x0c claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00407060` — sealed facts

1. **Body:** `0x00407060`–`0x00407133` exclusive (**211 B** / `0xD3`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map*; stack `InsertPair* out`, `ValPair* value`; **RET 0x8** all exits.
3. **Semantics:** MSVC-style **insert-or-find** for **isnil@+0x21** + **pair key**:
   - Walk root while `!isnil`; go right when `node <= key` (hi **signed** primary @+0x14, lo **unsigned** secondary @+0x10); track `addLeft`.
   - Left-walk + where == leftmost → always-insert `FUN_00407200(..., 1, ...)`.
   - Left-walk + not begin → predecessor `FUN_005adff0`.
   - If `hint < key` → insert `FUN_00407200(..., addLeft, ...)`; `out.inserted=1`.
   - Else equal: `out.it=hint`, `out.inserted=0` (**no value rewrite**).
4. **isnil / color family:** checks **isnil@+0x21**; insert callee owns color@+0x20.
5. **Key:** 2-dword pair; same order as dualed less `0x00401480` and isnil29 peer `0x004cbee0`.
6. **Callees:** undualed insert `FUN_00407200` (WQ9I-B OWN); pred `FUN_005adff0`.
7. **Callers (1):** dualed `StdTree_InsertHint_Isnil21_Inferred` (`0x00406560`) @ `0x004066ee`.
8. **Xrefs:** 1 UNCONDITIONAL_CALL.
9. **Name:** `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (Ghidra `FUN_00407060`). Product open → `_Inferred`.
10. **Decompile ≡ raw CF**; body/RET sealed via `read_memory` + disasm (decomp reuses `param_3` as cursor — machine keeps value in EBP).

### Gaps

- Product pair/value demangle.  
- Residual undualed: always-insert `00407200` (WQ9I-B), pred `005adff0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407060_FUN_00407060.md` |
| Annotated | `docs/reconstruction/raw/aa_00407060_FUN_00407060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407060.cpp` |
| Function | `docs/reconstruction/functions/aa_00407060_FUN_00407060.md` |
| Function named | `docs/reconstruction/functions/aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` |

---

## VA `0x004099b0` — sealed facts

1. **Body:** `0x004099b0`–`0x004099f3` exclusive (**67 B** / `0x43`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = node*; stack left, parent, right, value4*, color; **RET 0x14**; **EAX = this**.
3. **Semantics:** MSVC-style **node construct** for Val16/isnil21 family:
   - left/parent/right @ +0/+4/+8.
   - **Val16** four dwords @ +0x10..+0x1c.
   - **color** @ +0x20; **isnil=0** @ +0x21.
   - **+0x0c** not written.
4. **Callers (1):** dualed `StdTree_Buynode_Val16_Isnil21_Inferred` (`0x00408990`) @ `0x004089e8` after `operator_new(0x28)`.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** none (leaf).
7. **Name:** `StdTree_NodeCtor_Val16_Isnil21_Inferred` (Ghidra `FUN_004099b0`). Reject freelist/head-shell/Val24 merge.
8. **Decompile ≡ raw CF**; layout/RET sealed via `read_memory` + disasm. Decompiler `void` return is false for EAX=this.

### Gaps

- Product value_type English for 4 dwords.  
- Runtime / bit-exact (low risk leaf).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004099b0_FUN_004099b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004099b0_FUN_004099b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val16_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004099b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004099b0_FUN_004099b0.md` |
| Function named | `docs/reconstruction/functions/aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00406560  StdTree_InsertHint_Isnil21_Inferred   [dualed WQ9H-F]
  └─ FUN_00407060  StdMap_InsertOrFind_PairKey_Isnil21_Inferred  [OWN WQ9I-C]
        ├─ FUN_00407200  always-insert/rebalance isnil21         [WQ9I-B OWN]
        │     └─ FUN_00408990  StdTree_Buynode_Val16_Isnil21     [dualed WQ9H-J]
        │           └─ FUN_004099b0  NodeCtor Val16/isnil21      [OWN WQ9I-C]
        └─ FUN_005adff0  predecessor isnil21                     [residual]

Compare leaf peer: FUN_00401480  StdPairKey_Less...              [dualed]
isnil29 pair peer: FUN_004cbee0  InsertOrFind PairKey Isnil29    [dualed]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00407060-004099b0-wq9ic-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00407060` | Port as **isnil21 pair-key insert-or-find**. **RET 0x8** thiscall. Hi signed / lo unsigned; equal **no rewrite**. Pair with InsertHint `00406560`, insert `00407200` when dualed. Do **not** merge with isnil29 pair `004cbee0` or int-key `004cbe20`. |
| `004099b0` | Port as **node ctor** for **Val16 / isnil@+0x21 / size 0x28**. **thiscall RET 0x14**; EAX=this. Pair with buynode `00408990`. Do not claim alloc inside this VA; do not merge with head shell `00408a30`. |
| Pair with | dualed InsertHint `00406560`, buynode `00408990`, pair less `00401480`, isnil29 InsertOrFind peer `004cbee0`; residual insert `00407200`, pred `005adff0`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (container/STL residual — general StdTree/map, not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00407060`, `0x004099b0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste); null-contaminated scaffold `FUN_00407060.cpp` replaced.  
- Odd behavior preserved: decomp `param_3` cursor aliasing; decompiler void on node ctor (machine EAX=this); +0x0c gap.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

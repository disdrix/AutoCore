# Dual A/B report — WQ9K-D OWN-ONLY (`0x00406190`, `0x00405bd0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-D**  
**Scope:** VAs `0x00406190`, `0x00405bd0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-D**.  
**Work item:** WQ-009 depth-8 residual dual seal (isnil2D empty tree construct + isnil29 pair-key insert-or-find register ABI).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00406190` StdTree_ConstructEmpty_Isnil2D_Inferred | **accept-with-gaps** — stdcall RET0x4 / buyhead isnil2D / isnil1@+0x2d / self-link / size0 sealed; product map English open |
| `aa_00405bd0` StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred | **accept-with-gaps** — EBX/EAX/ESI bare RET / isnil29 pair hi-signed lo-unsigned / pred dual / insert worker residual; product pair English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash, isnil29/31 empty merge, thiscall twin merge (`004cbee0`), packet-error scaffold, Client/TFID product method names **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00406190` — sealed facts

1. **Body:** `0x00406190`–`0x004061e9` inclusive (**90 B** / `0x5A`); terminal **`C2 04 00`** after `ADD ESP,0xC`.
2. **ABI:** **`__stdcall`**; 1 stack arg (shell*); void-side effects + **EAX = shell***; **RET 0x4**.
3. **Semantics:** MSVC-style **empty tree construct**:
   - SEH (`LAB_009bd1a8`).
   - Call dualed `StdTree_BuyHeadNode_Isnil2D_Inferred` (`0x00409780`).
   - `_Myhead` @ shell+4 ← head; **isnil@+0x2d = 1**; L/P/R self-link; `_Mysize` @ shell+8 = 0.
4. **Caller (1):** `FUN_00404e40` @ `0x00404e76` — `FUN_00406190(param_1 + 3)` → subobject @ **+0x0C**.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `StdTree_ConstructEmpty_Isnil2D_Inferred` (Ghidra `FUN_00406190`). Reject isnil31 twin merge with `0x00405f20`.
7. **Family:** isnil@**+0x2d** / node **0x30** (via buyhead dual WQ9J-G).
8. **Decompile ≡ raw CF**; RET 0x4 + isnil store sealed by bytes.

### Gaps

- Product / English key-value type for host+0x0C map/set.  
- Shell+0 allocator/comp identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406190_FUN_00406190.md` |
| Annotated | `docs/reconstruction/raw/aa_00406190_FUN_00406190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406190.cpp` |
| Function | `docs/reconstruction/functions/aa_00406190_FUN_00406190.md` |
| Function named | `docs/reconstruction/functions/aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md` |

---

## VA `0x00405bd0` — sealed facts

1. **Body:** `0x00405bd0`–`0x00405c7e` inclusive (**175 B** / `0xAF`); terminal bare **`C3`** ×2.
2. **ABI:** **register** — **EBX**=map*, **EAX**=value* (pair lo@0 hi@4), **ESI**=out `{it*, inserted}`*; **EAX** returns out*; bare RET (no stack cleanup).
3. **Semantics:** MSVC-style **unique insert-or-find**:
   - Lower-bound walk on **isnil@+0x29**; go right iff node ≤ key (hi signed @+0x14, lo unsigned @+0x10).
   - If goLeft: leftmost → insert addLeft=1; else dualed pred `StdTree_Predecessor_Isnil29_Edx_Inferred` (`0x00409820`).
   - Equal: out.it=where, inserted=0.
   - Else insert via undualed `FUN_004069f0` (EDI=map, ECX=where): inserted=1.
4. **Caller:** `FUN_0092ff00` @ `0x0092ffbc` and `0x00930001` (TFID object-resolve host; packs coidLo/Hi + flags + tick into value blob).
5. **Xrefs:** 2 UNCONDITIONAL_CALL (same parent).
6. **Twin contrast:** `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (`0x004cbee0`) same role/family, **thiscall RET 8** — **do not merge**.
7. **Name:** `StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred` (Ghidra `FUN_00405bd0`). Reject packet-error scaffold plate.
8. **Decompile ≡ raw CF**; register ABI recovered from disasm (decomp `unaff_*`).

### Gaps

- Product / English pair+mapped type (TFID host evidence only).  
- Insert worker `FUN_004069f0` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00405bd0_FUN_00405bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00405bd0_FUN_00405bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00405bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00405bd0_FUN_00405bd0.md` |
| Function named | `docs/reconstruction/functions/aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00404e40  (host object ctor; vtable install)
  └─ StdTree_ConstructEmpty_Isnil2D_Inferred (0x00406190)  [OWN WQ9K-D]
        └─ StdTree_BuyHeadNode_Isnil2D_Inferred (0x00409780)  [dualed WQ9J-G]

Contrast twin empty construct (already dualed):
  StdTree_ConstructEmpty_Isnil31_Inferred (0x00405f20)  [WQ9K-C]
    └─ StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred (0x00409180)  [WQ9J-F]

FUN_0092ff00  (TFID resolve / miss path)
  └─ StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred (0x00405bd0)  [OWN WQ9K-D]
        ├─ StdTree_Predecessor_Isnil29_Edx_Inferred (0x00409820)  [dualed WQ9J-G]
        └─ FUN_004069f0  (insert+rebalance; undualed; pairs with EAX buynode path)

Contrast twin insert-or-find (already dualed):
  StdMap_InsertOrFind_PairKey_Isnil29_Inferred (0x004cbee0)  [WQ9F-D thiscall RET8]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00406190` | Port as **empty isnil2D tree construct**: call buyhead 0x30, install head isnil=1 @+0x2d + self-link, size=0; **stdcall RET 0x4**. Host may embed at +0x0C — do **not** name as host product method. |
| `00405bd0` | Port as **unique pair-key insert-or-find** with **EBX/EAX/ESI** register ABI; isnil@+0x29; hi signed / lo unsigned; pair with undualed insert `004069f0` when dualed. **Not** thiscall twin `004cbee0`. |
| Pair with | buyhead `00409780`; pred `00409820`; undualed insert `004069f0`; contrast empty isnil31 `00405f20`. |
| Naming caution | OWN pair is **two roles/families** (isnil2D empty shell vs isnil29 pair insert) — co-owned by residual partition, not shared layout. |

---

## Process

- OWN VAs only (`0x00406190`, `0x00405bd0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank paste).  
- Odd behavior preserved: decompiler `void`/unaff formals on insert-or-find; host TFID packing without product demangle.  
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
| This report | `docs/agents/task-dual-ab-00406190-00405bd0-wq9kd-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

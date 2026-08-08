# Dual A/B report — WQ9K-C OWN-ONLY (`0x00404180`, `0x00405f20`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9K-C**  
**Scope:** VAs `0x00404180`, `0x00405f20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-C**.  
**Work item:** WQ-009 depth-8 residual dual seal (buynode wrapper for EAX-ctor path + isnil31 empty tree construct / head install).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404180` StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred | **accept-with-gaps** — stdcall RET0x14 / new(0x30) / EAX-ctor Val24 isnil29 / sole insert caller sealed; product demangle open |
| `aa_00405f20` StdTree_ConstructEmpty_Isnil31_Inferred | **accept-with-gaps** — stdcall RET0x4 / buyhead install / isnil1@+0x31 / self-link / size0 sealed; product map English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash, thiscall-map, isnil29/31 merge, Client-product scaffold names, buynode twin merge **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404180` — sealed facts

1. **Body:** `0x00404180`–`0x00404202` exclusive (**130 B** / `0x82`); terminal **`C2 14 00`**.
2. **ABI:** **`__stdcall`**; stack `left, parent, right, value*, color`; **RET 0x14**; EAX = node* | null.
3. **Semantics:** MSVC-style **tree buynode**:
   - SEH (`LAB_009bc701`) + `operator_new(0x30)`.
   - On success: dualed `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` (`0x00409880`) — EAX=node, ECX=value*, EDX=left; stack parent/right/color; Val24 @+0x10; color@+0x28; **isnil=0** @+0x29.
   - On OOM: return null (no construct).
4. **Caller (1):** `FUN_004069f0` @ `0x00406a56` with `(head, where, head, value, color=0)` — insert + rebalance (`"map/set<T> too long"`).
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Twin contrast:** `StdTree_Buynode_Val24_Isnil29_Inferred` (`0x00407e30`) same layout/SEH/RET0x14, **thiscall** ctor `0x004098d0` — **do not merge**.
7. **Name:** `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred` (Ghidra `FUN_00404180`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF** for alloc/null/return; **register ABI to ctor sealed via disasm** (decomp incomplete).

### Gaps

- Product / MSVC demangle for map value_type.  
- Parent insert `FUN_004069f0` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00404180_FUN_00404180.md` |
| Annotated | `docs/reconstruction/raw/aa_00404180_FUN_00404180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404180.cpp` |
| Function | `docs/reconstruction/functions/aa_00404180_FUN_00404180.md` |
| Function named | `docs/reconstruction/functions/aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` |

---

## VA `0x00405f20` — sealed facts

1. **Body:** `0x00405f20`–`0x00405f7a` exclusive (**90 B** / `0x5A`); terminal **`C2 04 00`** after `ADD ESP,0xC`.
2. **ABI:** **`__stdcall`**; 1 stack arg (shell*); void-side effects + **EAX = shell***; **RET 0x4**.
3. **Semantics:** MSVC-style **empty tree construct**:
   - SEH (`LAB_009bdb18`).
   - Call dualed `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` (`0x00409180`).
   - `_Myhead` @ shell+4 ← head; **isnil@+0x31 = 1**; L/P/R self-link; `_Mysize` @ shell+8 = 0.
4. **Caller (1):** `FUN_009495c0` (Client ctor; `"Client Constructor"`) @ `0x00949d37` — `FUN_00405f20(param_1 + 0x3c5)` → subobject @ **+0xF14**.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `StdTree_ConstructEmpty_Isnil31_Inferred` (Ghidra `FUN_00405f20`). Reject scaffold `Named_CalleeOf_Named_Client_Constructor_*`.
7. **Family:** isnil@**+0x31** / node **0x38** (via buyhead dual WQ9J-F).
8. **Decompile ≡ raw CF**; RET 0x4 + isnil store sealed by bytes.

### Gaps

- Product / English key-value type for Client+0xF14 map/set.  
- Shell+0 allocator/comp identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00405f20_FUN_00405f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00405f20_FUN_00405f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00405f20.cpp` |
| Function | `docs/reconstruction/functions/aa_00405f20_FUN_00405f20.md` |
| Function named | `docs/reconstruction/functions/aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004069f0  (insert/rebalance; "map/set<T> too long"; isnil@+0x28 color walks)
  └─ StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred (0x00404180)  [OWN WQ9K-C]
        └─ StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred (0x00409880)  [dualed WQ9J-H]

Contrast twin path (already dualed):
  StdTree_InsertAndRebalance_Isnil29_Inferred (0x00406c40)  [WQ9E-G]
    └─ StdTree_Buynode_Val24_Isnil29_Inferred (0x00407e30)  [WQ9F-B]
          └─ StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred (0x004098d0)  [WQ9J-H]

FUN_009495c0  (Client constructor)
  └─ StdTree_ConstructEmpty_Isnil31_Inferred (0x00405f20)  [OWN WQ9K-C]
        └─ StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred (0x00409180)  [dualed WQ9J-F]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00404180` | Port as **shared Val24/isnil29 buynode** via **EAX-this** ctor: `new(0x30)` + construct; **stdcall RET 0x14**; null on OOM. Pair with insert `004069f0` when dualed. **Not** thiscall twin `00407e30`; **not** freelist. |
| `00405f20` | Port as **empty isnil31 tree construct**: call buyhead 0x38, install head isnil=1 + self-link, size=0; **stdcall RET 0x4**. Host may be Client subobject — do **not** name as Client product method. |
| Pair with | EAX ctor `00409880`; thiscall buynode twin `00407e30`; buyhead `00409180`; undualed insert `004069f0`. |
| Naming caution | OWN pair is **two families** (isnil29 data buynode vs isnil31 empty shell) — co-owned by residual partition, not shared layout. |

---

## Process

- OWN VAs only (`0x00404180`, `0x00405f20`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank paste).  
- Odd behavior preserved: decompiler incomplete ctor arg list on buynode; Client-hosting of empty shell without product demangle.  
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
| This report | `docs/agents/task-dual-ab-00404180-00405f20-wq9kc-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

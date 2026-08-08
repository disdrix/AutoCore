# Dual A/B report — WQ9I-B OWN-ONLY (`0x00409f30`, `0x00407200`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-B**  
**Scope:** VAs `0x00409f30`, `0x00407200` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-B**.  
**Work item:** WQ-009 depth-6 residual dual seal (POD copy 10 dwords for ConstructN 0x28 + always-insert isnil21).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409f30` StdVector_PodCopyElement_0x28_Inferred | **accept-with-gaps** — leaf CF/ABI/10-dword/0x28/null-dst sealed; product residual |
| `aa_00407200` StdTree_InsertAndRebalance_Isnil21_Inferred | **accept-with-gaps** — always-insert CF/ABI/RET0x10/isnil21/buynode sealed; product + rotate dual residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): thiscall-on-PodCopy / InsertHint-merge / isnil29-merge / freelist / wrong RET / wrong max-size all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409f30` — sealed facts

1. **Body:** `0x00409f30`–`0x00409f43` inclusive (**20 B** / `0x14`); pad `CC`.
2. **ABI:** **EAX** = dest `T*`; **EDX** = src `const T*`; plain **`ret`** (`C3`). No stack args.
3. **Semantics:** Null-dst no-op; else **`REP MOVSD`** with **ECX=10** → **40 B / 0x28** POD copy.
4. **Bytes:** `57 8B F8 85 FF 74 0B 56 B9 0A 00 00 00 8B F2 F3 A5 5E 5F C3`.
5. **Callees:** none (leaf).
6. **Callers (2):** `FUN_00409d40` ConstructN 0x28 @ `0x00409d78`; `FUN_0040a520` range-copy 0x28 @ `0x0040a558` (both advance +0x28 after call).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_PodCopyElement_0x28_Inferred` (Ghidra `FUN_00409f30`). Product demangle open → `_Inferred`.
9. **Twins (CF):** ConstructN parent `00409d40` (WQ9H-B dualed); peer PodCopy leaves 0x38/0x98/0x138 families.
10. **Decompile ≡ raw CF**; register ABI sealed via `read_memory` + call-site context (decomp phantom `param_1` overridden).

### Gaps

- Product / MSVC demangle for 0x28 POD element type.  
- Full dual of range worker `FUN_0040a520` (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409f30_FUN_00409f30.md` |
| Annotated | `docs/reconstruction/raw/aa_00409f30_FUN_00409f30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PodCopyElement_0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409f30.cpp` |
| Function | `docs/reconstruction/functions/aa_00409f30_FUN_00409f30.md` |
| Function named | `docs/reconstruction/functions/aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` |

---

## VA `0x00407200` — sealed facts

1. **Body:** `0x00407200`–`0x00407395` inclusive (**406 B** / `0x196`); pad `CC`.
2. **ABI:** **`__thiscall`** ECX=map; stack `Node** out`, `char addLeft`, `Node* where`, `const void* value`; **`ret 0x10`**.
3. **Semantics:** MSVC-style **always-insert + RB rebalance** for **isnil@+0x21**:
   - Size gate: `size ≥ 0xFFFFFFE` → `"map/set<T> too long"` / length_error / throw.
   - Buynode dualed `FUN_00408990` `(head, where, head, value*, color=0)`.
   - `size++`; link empty / left / right + extremum update.
   - While parent color red: uncle recolor or Lrotate `0050e9f0` / Rrotate `005a27f0`.
   - Root black @+0x20; `*out = node`.
4. **Layout:** node **0x28**; color@**+0x20**; isnil@**+0x21**; Val16 @+0x10 (from buynode dual).
5. **Callees:** `00408990` buynode (dualed); `0050e9f0` L; `005a27f0` R; length_error path.
6. **Callers (2):** dualed InsertHint `FUN_00406560` (7 sites); residual InsertOrFind `FUN_00407060` (2 sites).
7. **Xrefs:** 9 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertAndRebalance_Isnil21_Inferred` (Ghidra `FUN_00407200`). Product demangle open → `_Inferred`.
9. **Twins (CF):** isnil29 always-insert `00406c40` (WQ9E-G); InsertHint parent `00406560` (WQ9H-F); buynode `00408990` (WQ9H-J).
10. **Decompile ≡ raw CF**; RET + thiscall + size imm + color@+0x20 sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for value_type / map instantiation.  
- Full dual of rotates `0050e9f0` / `005a27f0` (roles sealed).  
- Full dual of InsertOrFind `00407060` (WQ9I-C OWN, not this agent).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407200_FUN_00407200.md` |
| Annotated | `docs/reconstruction/raw/aa_00407200_FUN_00407200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407200.cpp` |
| Function | `docs/reconstruction/functions/aa_00407200_FUN_00407200.md` |
| Function named | `docs/reconstruction/functions/aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00409d40  StdVector_ConstructN_Elem0x28_Inferred  [WQ9H-B dualed]
  └─ StdVector_PodCopyElement_0x28_Inferred (0x00409f30)   [OWN WQ9I-B]
FUN_0040a520  (range-copy step +0x28)
  └─ StdVector_PodCopyElement_0x28_Inferred (0x00409f30)   [OWN WQ9I-B]

FUN_00406560  StdTree_InsertHint_Isnil21_Inferred  [WQ9H-F dualed]
  └─ StdTree_InsertAndRebalance_Isnil21_Inferred (0x00407200)  [OWN WQ9I-B]
        └─ StdTree_Buynode_Val16_Isnil21_Inferred (0x00408990) [WQ9H-J dualed]
        └─ FUN_0050e9f0 / FUN_005a27f0  (L/R rotate color@+0x20)  [residual]
FUN_00407060  InsertOrFind isnil21  [WQ9I-C residual]
  └─ StdTree_InsertAndRebalance_Isnil21_Inferred (0x00407200)  [OWN WQ9I-B]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409f30-00407200-wq9ib-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409f30` | Port as **shared POD element copy** for **stride 0x28** — EAX=dest, EDX=src, plain ret. Null-dst no-op; 10 dwords. Pair with ConstructN `00409d40` / Ufill `00406e50` / push_back `00406220`. |
| `00407200` | Port as **StdTree always-insert + RB rebalance** for **isnil@+0x21 / Val16 / node 0x28**. **thiscall** ECX=map; **ret 0x10**. Max size `≥ 0xFFFFFFE` throws. Pair with buynode `00408990`, InsertHint `00406560`, InsertOrFind `00407060`. Do not merge with isnil29 always-insert `00406c40`. |
| Pair with | ConstructN/Ufill/push_back 0x28 family; InsertHint isnil21; isnil29 always-insert peer; rotates when dualed. |
| Naming caution | **PodCopy is not ConstructN** (that is `00409d40`). **Always-insert is not InsertHint** (that is `00406560`) and **not** InsertOrFind (`00407060`). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container / util — **vector POD** + **StdTree isnil21**, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409f30`, `0x00407200`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Raw bodies captured fresh with re-verify sections.  

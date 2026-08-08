# Dual A/B report — WQ9K-E OWN-ONLY (`0x00408ed0`, `0x00833d50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-E**  
**Scope:** VAs `0x00408ed0`, `0x00833d50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-E**.  
**Work item:** WQ-009 depth-8 residual dual seal (erase caller of tree min isnil31 + CWndVehicle nested dtor helper EDI=this).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00408ed0` StdTree_EraseAndRebalance_Isnil31_Inferred | **accept-with-gaps** — stack RET0xC / isnil@+0x31 color@+0x30 / single-node erase + RB rebalance / size-- sealed; product map English open |
| `aa_00833d50` CWndVehicle_DerivedTeardown_EDI | **accept-with-gaps** — EDI=this / +0x50C clear / nested +0x2A8 re-notify / +0x508 scalar-delete + SetWheelset sealed; nested product English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist, isnil29/isnil2d erase merge, thiscall RET8, complete/scalar merge, ECX thiscall for helper, tree-as-UI merge **rejected/narrowed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00408ed0` — sealed facts

1. **Body:** `0x00408ed0`–`0x0040915f` inclusive / exclusive end `0x00409160` (**656 B** / `0x290`). Ghidra end `0x00409130` truncated by false noreturn on delete.
2. **ABI:** Three **stack** args (map*, outIt**, node*); void product; **`RET 0x0C`**.
3. **Semantics:** MSVC-style **`_Tree` erase(const_iterator)** for **isnil@+0x31 / color@+0x30 / node 0x38**:
   - Throw `"invalid map/set<T> iterator"` on nil.
   - Successor via `StdTree_IteratorIncrement_Isnil31` (`FUN_00408590`).
   - Unlink + fix head extremities (min `FUN_00409160`, max `FUN_004043e0`).
   - RB rebalance if erased black (Lrot `FUN_00403e90`, Rrot `FUN_00403ee0`).
   - `operator_delete` only (**no** value/`basic_string` dtor).
   - `size--` when size>0; write `*outIt`.
4. **Classification:** worker.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `FUN_00407cb0` @ `0x00407d4e` (erase-range loop).
6. **Twins (do not merge):** isnil29 erase `0x004cb740`; StringKey isnil2d erase `0x004094c0`; min leaf `0x00409160` (callee, not this unit).
7. **Name:** `StdTree_EraseAndRebalance_Isnil31_Inferred` (Ghidra `FUN_00408ed0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF** for throw/unlink/rebalance; epilogue sealed via `read_memory`.

### Gaps

- Product / English map type and value payload fields.  
- Parent erase-range `FUN_00407cb0` and rotate/max helpers undualed here.  
- Two-child successor-swap plate (decomp unreachable warnings).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408ed0_FUN_00408ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00408ed0_FUN_00408ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408ed0.cpp` |
| Function | `docs/reconstruction/functions/aa_00408ed0_FUN_00408ed0.md` |
| Function named | `docs/reconstruction/functions/aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md` |

---

## VA `0x00833d50` — sealed facts

1. **Body:** `0x00833d50`–`0x00833df6` inclusive / exclusive end `0x00833df7` (**167 B** / `0xA7`).
2. **ABI:** **EDI = this** (CWndVehicle*); no stack formals; void; bare **`RET`** (`C3`).
3. **Semantics:** **CWndVehicle derived teardown helper**:
   - `*(this+0x50C) = 0`.
   - If nested `@+0x2A8`: flag `+0x48=1`, copy `+0x40→+0x44`, `FUN_0076c4d0(nested+0x10)`, binder `{PTR_LAB_00a9f4d8, nested}`, iface vcalls `+0x20` / `+0x10(0)`.
   - If vehicle host `@+0x508`: optional child `@host+0x258` scalar-delete; `Vehicle_SetWheelset(0)` @ `0x004fea90`; scalar-delete host; null `+0x508`.
   - Does **not** free `this`; does **not** call base UI dtor.
4. **Classification:** worker.
5. **Xrefs (6):** `FUN_00834520` @ `0x0083458d` (complete); `FUN_00833e30`; `FUN_0083ac90`; `FUN_0084b210`; `FUN_0088d980` (Drive_Loading_Vehicles).
6. **Odd behavior (preserve):** complete dtor already notifies nested `@+0x2A8`; this helper **re-notifies** the same nested when non-null.
7. **Name:** `CWndVehicle_DerivedTeardown_EDI` (Ghidra `FUN_00833d50`). Host class sealed via complete/scalar RTTI chain.
8. **Decompile ≡ raw CF**; EDI ABI sealed via entry bytes + complete call site.

### Gaps

- Nested `@+0x2A8` product type English.  
- Vehicle host `@+0x508` exact class beyond wheelset usage.  
- Other callers undualed here.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00833d50_FUN_00833d50.md` |
| Annotated | `docs/reconstruction/raw/aa_00833d50_FUN_00833d50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndVehicle_DerivedTeardown_EDI.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00833d50.cpp` |
| Function | `docs/reconstruction/functions/aa_00833d50_FUN_00833d50.md` |
| Function named | `docs/reconstruction/functions/aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00407cb0  erase-range isnil31 (EDI=map)
  └─ StdTree_EraseAndRebalance_Isnil31_Inferred (0x00408ed0)  [OWN WQ9K-E]
       ├─ StdTree_IteratorIncrement_Isnil31 (0x00408590)      [WQ9H-H]
       ├─ StdTree_Min_Isnil31 (0x00409160)                    [WQ9J-E]
       ├─ FUN_004043e0 max
       └─ FUN_00403e90 / FUN_00403ee0 L/R rotates

CWndVehicle_ScalarDeletingDtor (0x004160d0)                   [WQ9I-F]
  └─ CWndVehicle_CompleteDtor (0x00834520)                    [WQ9J-B]
       ├─ nested notify @+0x2A8
       ├─ CWndVehicle_DerivedTeardown_EDI (0x00833d50)        [OWN WQ9K-E]
       └─ FUN_0078ca80 base CNDUIWndBuffered complete         [WQ9K-F]

Peers (do not merge):
  isnil29 erase 0x004cb740
  StringKey isnil2d erase 0x004094c0
  CWndVehicle complete / scalar (parents, not this helper)
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00408ed0` | Port as **single-node tree erase** isnil@**+0x31** color@**+0x30** node **0x38**: throw / succ / unlink / rebalance / delete / size-- / *outIt; **RET 0xC**. **No** string dtor. Pair with erase-range `00407cb0` and isnil31 min/iter. **Not** isnil29 or StringKey erase. |
| `00833d50` | Port as **CWndVehicle derived teardown** with **EDI=this** (or rewrite call sites): clear +0x50C; nested notify; scalar-delete +0x508 (+ SetWheelset(0)); **not** free this; **not** base dtor. Preserve double-notify with complete. |
| Pair with | min `00409160`; iter++ `00408590`; complete `00834520`; base `0078ca80` when dualed. |
| Naming caution | **OWN pair is two families** (isnil31 erase vs CWndVehicle UI teardown) — shared only by residual VA partition, not layout. |

---

## Process

- OWN VAs only (`0x00408ed0`, `0x00833d50`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank paste).  
- Odd behavior preserved: decompiler noreturn-on-delete truncating epilogue; unreachable mid-splice warnings; double nested notify on complete path; EDI-not-ECX helper ABI.  
- `_Inferred` where English unproven (erase); host product sealed for teardown. Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (util/container tree helpers + UI CWndVehicle)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00408ed0-00833d50-wq9ke-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

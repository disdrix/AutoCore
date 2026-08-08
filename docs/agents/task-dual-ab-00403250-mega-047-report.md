# Dual A/B report — MEGA-047 OWN-ONLY (`0x00403250`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-047**  
**Scope:** VA `0x00403250` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-047 residual dual seal — insert/rebalance peer of dualed **StdTree_Lrotate_Isnil31** (`0x00403e90`); nested under NotifyActiveMissionChanged chain.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00403250` StdTree_InsertAndRebalance_Isnil31_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/EDI=map/ECX=where/color@+0x30/isnil@+0x31/node0x38/always-insert sealed; product map open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-product / isnil29-merge / thiscall-map-RET10 / insert-or-find / erase-mislabel claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00403250` — sealed facts

1. **Body:** `0x00403250`–`0x004033d1` inclusive (**386 B** / `0x182`); pad `CC`.
2. **ABI:** **EDI** = map shell*; **ECX** = where node*; stack `(Node** out, char addLeft, Val* value)`; **EAX** = out; **`RET 0xC`**.
3. **Semantics:** MSVC `_Tree` always-insert + RB rebalance (isnil@**+0x31** family):
   - SEH frame (`LAB_009bc919` / FS:[0]).
   - Size gate: throw `"map/set<T> too long"` if `size >= 0x7fffffe` via `FUN_00401a40` + `_CxxThrowException(DAT_00acc388)`.
   - Buynode `FUN_00403f30` → `operator_new(0x38)` + `FUN_00404360` (value **0x20** @+0x10, color red @+0x30, isnil=0 @+0x31).
   - Link empty / left / right + Lmost/Rmost/root; RB while parent red; Lrot dualed `00403e90` / Rrot `00403ee0`; root black.
   - Does **not** compare keys (parent `FUN_00402b30` owns find).
4. **Layout:** node **0x38**; color@**+0x30**; isnil@**+0x31**; value **0x20** @+0x10.
5. **Callees:** `FUN_00403f30`, `FUN_00403e90`, `FUN_00403ee0`, `FUN_00401a40`, basic_string ctor, `_CxxThrowException`.
6. **Callers:** **1** function / **2** UNCONDITIONAL_CALL — `FUN_00402b30` @ `0x00402b88`, `0x00402bc0`.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertAndRebalance_Isnil31_Inferred` (Ghidra `FUN_00403250`). Product map open → `_Inferred`. Retire `Named_CalleeOf_*NotifyActiveMissionChanged`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + call-site context + `read_memory` epilogue.

### Gaps

- Product / English host map type (0x38 isnil31 family under mission chain).  
- Value payload English (0x20; key = first u32 at parent).  
- Residual duals: Rrotate `00403ee0`, buynode `00403f30`, parent `00402b30`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00403250_FUN_00403250.md` |
| Annotated | `docs/reconstruction/raw/aa_00403250_FUN_00403250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403250.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00403250.cpp` |
| Function | `docs/reconstruction/functions/aa_00403250_FUN_00403250.md` |
| Function named | `docs/reconstruction/functions/aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_NotifyActiveMissionChanged  [chain root — not dualled here]
  └─ … → FUN_00402b30  insert-or-find isnil31  [MEGA-040 residual]
           ├─ key walk isnil@+0x31; compare node+0x10 vs *EBX
           └─ FUN_00403250  StdTree_InsertAndRebalance_Isnil31_Inferred  [OWN MEGA-047]
                ├─ FUN_00403f30  buynode 0x38  [MEGA-048 residual]
                │    └─ FUN_00404360  node ctor (val0x20, color@+0x30, isnil@+0x31)
                ├─ FUN_00403e90  StdTree_Lrotate_Isnil31_Inferred  [dualed WQ9L-B]
                ├─ FUN_00403ee0  Rrotate isnil31  [residual]
                └─ FUN_00401a40  Std_LengthError_CtorFromString  [dualed]
                     + _CxxThrowException(DAT_00acc388)

FUN_00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred  [dualed]
  └─ shared Lrot 00403e90 / Rrot 00403ee0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00403250-mega-047-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00403250` | Port as **always-insert + RB rebalance** for isnil@**+0x31** nodes (size **0x38**, color@**+0x30**, value **0x20**). **EDI=map**, **ECX=where**, stack out/addLeft/value, **RET 0xC**. Do **not** use pure thiscall-map RET 0x10 form of isnil29 peer. |
| Distinct from | isnil29 insert `00406c40` (RET 0x10 / color@+0x28); isnil21 insert `00407200`; erase isnil31 `00408ed0`. |
| Pair with | dualed Lrot isnil31 `00403e90`; dualed length_error `00401a40`; residual Rrot `00403ee0`; residual buynode `00403f30`; residual parent `00402b30`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- system map missions-progression / STL helpers
- retire Named_CalleeOf plate in any inventory

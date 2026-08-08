# Dual A/B report — MEGA-048 OWN-ONLY (`0x00403f30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-048**  
**Scope:** VA `0x00403f30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** HTTP `127.0.0.1:8089` — `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-048**.  
**Work item:** Mega residual dual seal — nested under dualed `Client_NotifyActiveMissionChanged`; structural isnil31 tree buynode.  
**Hint retired:** `Named_CalleeOf_*NotifyActiveMission*` chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00403f30` StdTree_Buynode_Val32_Isnil31_Inferred | **accept-with-gaps** — stdcall RET0x14 / new(0x38) / ctor Val32 isnil31 / sole insert caller sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-product / isnil29-Val24-merge / BuyHead-merge / thiscall-map / freelist claims **falsified**; chain-of-caller scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00403f30` — sealed facts

1. **Body:** `0x00403f30`–`0x00403fb2` exclusive (**130 B** / `0x82`); terminal **`C2 14 00`**; SEH cleanup + `CC` pad follow.
2. **ABI:** **`__stdcall`**; stack `left, parent, right, value*, color`; **RET 0x14**; EAX = node* \| null. **Not** thiscall.
3. **Semantics:** MSVC-style **tree buynode**:
   - SEH frame (`LAB_009bc781`).
   - `operator_new(0x38)`.
   - On success: `FUN_00404360` — EAX=node, ECX=left, EDX=parent, stack right/value/color — links + **8 dwords** value @+0x10 + color@+0x30 + **isnil=0** @+0x31.
   - On OOM: return null (no construct).
4. **Caller (1):** residual insert/rebalance `FUN_00403250` @ `0x004032b6` with `(head, where, head, value, color=0)`.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** `operator_new` @ `0x00489892`; `FUN_00404360` @ `0x00404360`.
7. **Family:** dualed isnil31 Lrot `00403e90`, Rrot `00403ee0`, erase `00408ed0`, BuyHead `00409180`. Contrast isnil29 Val24 buynode `00407e30` — **do not merge**.
8. **Name:** `StdTree_Buynode_Val32_Isnil31_Inferred` (Ghidra `FUN_00403f30`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET 0x14 + ctor full arg list sealed via `disassemble_function` + `read_memory` (decompiler elides ECX/EDX/EAX on ctor call — documented gap, not CF conflict).

### Gaps

- Product / MSVC demangle for map value_type (8-dword English).  
- Ctor helper `FUN_00404360` undualed (not OWN).  
- Insert parent `FUN_00403250` residual (MEGA-047 OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00403f30_FUN_00403f30.md` |
| Annotated | `docs/reconstruction/raw/aa_00403f30_FUN_00403f30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val32_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403f30.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_NotifyActiv_00403f30.cpp` |
| Function | `docs/reconstruction/functions/aa_00403f30_FUN_00403f30.md` |
| Function named | `docs/reconstruction/functions/aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_NotifyActiveMissionChanged  [dualed]
  └─ … residual insert path …
       FUN_00403250  insert/rebalance isnil31  [residual MEGA-047]
         ├─ FUN_00403f30  StdTree_Buynode_Val32_Isnil31_Inferred  [OWN MEGA-048]
         │     ├─ operator_new(0x38)
         │     └─ FUN_00404360  node construct Val32+isnil31  [residual]
         ├─ FUN_00403e90  StdTree_Lrotate_Isnil31_Inferred  [dualed]
         └─ FUN_00403ee0  StdTree_Rrotate_Isnil31_Inferred  [dualed]

FUN_00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred  [dualed]
  └─ shares Lrot/Rrot family (not this buynode)

FUN_00409180  StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred  [dualed]
  └─ same size/isnil family; head shell only — do not merge
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00403f30-mega-048-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00403f30` | Port as **`_Tree` buynode** for isnil@**+0x31** nodes (size **0x38**, **Val32** @+0x10). **stdcall RET 0x14**. Args: left, parent, right, value*, color. Null-safe. Pair with ctor that forces isnil=0 @+0x31. |
| Distinct from | isnil29 Val24 buynode `00407e30` (size 0x30); BuyHead `00409180` (no value); freelist paths. |
| Pair with | residual insert `00403250`; dualed Lrot `00403e90` / Rrot `00403ee0` / erase `00408ed0`; residual ctor `00404360`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `StdTree_Buynode_Val32_Isnil31_Inferred` @ `0x00403f30` / `aa_00403f30`.
- Verdict: **accept-with-gaps**; Terminal **false**.

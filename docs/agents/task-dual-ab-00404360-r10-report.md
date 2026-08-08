# Dual A/B report — R10-021 OWN-ONLY (`0x00404360`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-021**  
**Scope:** VA `0x00404360` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual rewrite.  
**Ghidra:** MCP — `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-021**.  
**Parent dual:** `0x00403f30` `StdTree_Buynode_Val32_Isnil31_Inferred` (MEGA-048).  
**Work item:** Residual dual seal — node ctor under dualed Val32 isnil31 buynode.  
**Hint retired:** `Named_CalleeOf_*` multi-hop Client/NotifyActiveMission chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404360` StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred | **accept-with-gaps** — leaf EAX-this ctor / Val32 / isnil@+0x31 / RET 0xC / sole buynode caller sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-product / buynode-merge / isnil29-Val24-merge / thiscall-node / freelist claims **falsified**; chain-of-caller scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404360` — sealed facts

1. **Body:** `0x00404360`–`0x0040438C` exclusive (**44 B** / `0x2C`); terminal **`C2 0C 00`**; `CC` pad follows.
2. **ABI:** **`__usercall`**; node@**EAX**, left@**ECX**, parent@**EDX**, stack `right, value*, color`; **RET 0xC**. Not thiscall; not pure stdcall.
3. **Semantics:** MSVC-style **tree node construct** (no alloc):
   - left/parent/right → +0/+4/+8
   - **8 dwords** value @+0x10 (`REP MOVSD` ECX=8) — **Val32**
   - color@+0x30; **isnil=0** @+0x31
   - +0x0C untouched
4. **Caller (1):** dualed buynode `FUN_00403f30` / `StdTree_Buynode_Val32_Isnil31_Inferred` @ `0x00403f86` with EAX=new(0x38) node.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** none (leaf).
7. **Family:** isnil31 Lrot `00403e90`, Rrot `00403ee0`, erase `00408ed0`, BuyHead `00409180`; parent buynode `00403f30`. Contrast isnil29 Val24 NodeCtor `00409880`/`004098d0` — **do not merge**.
8. **Name:** `StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred` (Ghidra `FUN_00404360`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET 0xC + store map sealed via `read_memory` (decompiler shows phantom `in_EAX` / incomplete `__fastcall` — documented ABI presentation gap, not CF conflict).

### Gaps

- Product / MSVC demangle for map value_type (8-dword English).  
- Runtime / bit-exact / differential.  
- Insert parent `FUN_00403250` residual (MEGA-047; not OWN).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00404360_FUN_00404360.md` |
| Annotated | `docs/reconstruction/raw/aa_00404360_FUN_00404360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404360.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404360.cpp` |
| Function | `docs/reconstruction/functions/aa_00404360_FUN_00404360.md` |
| Function named | `docs/reconstruction/functions/aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_NotifyActiveMissionChanged  [dualed]
  └─ … residual insert path …
       FUN_00403250  insert/rebalance isnil31  [residual MEGA-047]
         └─ FUN_00403f30  StdTree_Buynode_Val32_Isnil31_Inferred  [dualed MEGA-048]
               ├─ operator_new(0x38)
               └─ FUN_00404360  StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred  [OWN R10-021]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00404360-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00404360` | Port as **`_Tree` node construct** for isnil@**+0x31** nodes (**Val32** @+0x10). **usercall RET 0xC**. Args: node@eax, left@ecx, parent@edx, right, value*, color. Forces isnil=0. |
| Distinct from | parent buynode `00403f30` (owns alloc); Val24 isnil29 NodeCtor `00409880`/`004098d0`; freelist paths. |
| Pair with | dualed buynode `00403f30`; residual insert `00403250`; dualed Lrot `00403e90` / Rrot `00403ee0` / erase `00408ed0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred` @ `0x00404360` / `aa_00404360`.
- Verdict: **accept-with-gaps**; Terminal **false**.

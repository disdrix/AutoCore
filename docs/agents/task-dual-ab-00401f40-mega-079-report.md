# Dual A/B report — MEGA-079 OWN-ONLY (`0x00401f40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-079**  
**Scope:** VA `0x00401f40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-079**.  
**Work item:** Mega residual dual seal — Mission null dialog nested; structural isnil2D tree buynode (string+byte).  
**Hint retired:** `Named_CalleeOf_*Mis_00401f40` chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401f40` StdTree_Buynode_StringByte_Isnil2D_Inferred | **accept-with-gaps** — stdcall RET0x14 / new(0x30) / string+byte isnil2D ctor / sole insert caller sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-product / isnil29-Val24-merge / isnil31-Val32-merge / BuyHead-merge / thiscall-map / freelist / set-without-byte claims **falsified**; chain-of-caller scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401f40` — sealed facts

1. **Body:** `0x00401f40`–`0x00401fbf` exclusive (**127 B** / `0x7F`); terminal **`C2 14 00`**.
2. **ABI:** **`__stdcall`**; stack `left, parent, right, value*, color`; **RET 0x14**; EAX = node* \| null. **Not** thiscall.
3. **Semantics:** MSVC-style **tree buynode**:
   - SEH frame (`LAB_009bc811`).
   - `operator_new(0x30)`.
   - On success: `FUN_00401fe0` — ECX=parent, EDX=right, EDI=value*, stack node/left/color — links + **string@+0x0c** + **byte@+0x28** + color@+0x2c + **isnil=0** @+0x2d.
   - On OOM: return null (no construct).
4. **Caller (1):** residual insert/rebalance `FUN_00401db0` @ `0x00401e16` with `(head, where, head, value, color=0)`.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** `operator_new` @ `0x00489892`; `FUN_00401fe0` @ `0x00401fe0` (→ value `FUN_00402040`).
7. **Family:** dualed isnil2D Lrot `0044e010`, Rrot `0042a840`, BuyHead `00409780`, ConstructEmpty `00406190`. Contrast isnil29 Val24 `00404180`/`00407e30` and isnil31 Val32 `00403f30` — **do not merge**.
8. **Name:** `StdTree_Buynode_StringByte_Isnil2D_Inferred` (Ghidra `FUN_00401f40`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET 0x14 + full 5-arg list sealed via `disassemble_function` + `read_memory` (decompiler arity elision documented, not CF conflict).

### Gaps

- Product / MSVC demangle for host map (`string→byte`-shaped) under null-dialog chain.  
- Ctor `FUN_00401fe0` / value `FUN_00402040` / insert `FUN_00401db0` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401f40_FUN_00401f40.md` |
| Annotated | `docs/reconstruction/raw/aa_00401f40_FUN_00401f40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_StringByte_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401f40.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00401f40.cpp` |
| Function | `docs/reconstruction/functions/aa_00401f40_FUN_00401f40.md` |
| Function named | `docs/reconstruction/functions/aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00980160  [caller of insert-or-find; residual]
  └─ FUN_00401c50  string-key insert-or-find (isnil@+0x2d)
       └─ FUN_00401db0  insert + rebalance  ["map/set<T> too long"]
            ├─ FUN_00401f40  StdTree_Buynode_StringByte_Isnil2D_Inferred  [OWN MEGA-079]
            │     ├─ operator_new(0x30)
            │     └─ FUN_00401fe0  node construct string+byte+isnil2D  [residual]
            │           └─ FUN_00402040  value: string copy + byte  [residual]
            ├─ FUN_0044e010  StdTree_LeftRotate_Isnil2D_Inferred  [dualed]
            └─ FUN_0042a840  Rrotate isnil2D  [dualed]

StdTree_BuyHeadNode_Isnil2D_Inferred (0x00409780)  [dualed]
  └─ same size/isnil family; head shell only — do not merge

StdTree_ConstructEmpty_Isnil2D_Inferred (0x00406190)  [dualed]
  └─ empty shell — do not merge
```

Partition hint "Mission null dialog nested" names the **host chain**, not this leaf's product role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401f40-mega-079-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401f40` | Port as **`_Tree` buynode** for isnil@**+0x2d** nodes (size **0x30**, **string+byte** @+0x0c/+0x28). **stdcall RET 0x14**. Args: left, parent, right, value*, color. Null-safe. Pair with ctor that forces isnil=0 @+0x2d. |
| Distinct from | isnil29 Val24 buynode `00404180`/`00407e30`; isnil31 Val32 `00403f30`; BuyHead `00409780` (no value). |
| Pair with | residual insert `00401db0`; residual insert-or-find `00401c50`; dualed isnil2D rotates `0044e010`/`0042a840`; residual ctor `00401fe0` / value `00402040`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `StdTree_Buynode_StringByte_Isnil2D_Inferred` @ `0x00401f40` / `aa_00401f40`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00401f40`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + callee/parent decompiles. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (stdcall RET 0x14; 5 args; decompiler arity fixed).
- Odd behavior preserved: OOM returns null without ctor; isnil forced 0 regardless of color; value byte is 1-wide not demangled.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

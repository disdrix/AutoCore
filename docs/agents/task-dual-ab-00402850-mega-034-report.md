# Dual A/B report — MEGA-034 OWN-ONLY (`0x00402850`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-034**  
**Scope:** VA `0x00402850` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-034 residual dual seal — nested callee of **Client_Input_OnKeyDown_MatchAction** (input-drive-control partition); STL tree erase isnil29 stack ABI.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402850` StdTree_EraseAndRebalance_Isnil29_RetC_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/isnil29/size--/throw plate sealed; product map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): OnKeyDown-as-role / thiscall-merge / isnil31-merge / Val28-dtor / noreturn-on-delete / range-as-body claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402850` — sealed facts

1. **Body:** `0x00402850`–`0x00402ae0` exclusive (**656 B** / `0x290`); Ghidra end `0x00402ab0` truncated by false noreturn on `operator_delete`.
2. **ABI:** Three **stack** args: map*, outIt**, node*; **`RET 0x0C`** (`C2 0C 00` @ `0x00402add`). Not ECX-thiscall primary.
3. **Semantics:** MSVC `std::_Tree` erase + RB rebalance (isnil@**+0x29**, color@**+0x28**):
   - SEH frame (`LAB_009bc919` / FS:[0]).
   - Nil → `"invalid map/set<T> iterator"` @ `0x00a152f0` → `FUN_00401bc0` → `_CxxThrowException(..., DAT_00acc34c)`.
   - Successor via `FUN_004040a0` (isnil29 iterator++).
   - Unlink + head extremity fix (min `FUN_004031e0`, max `FUN_004031c0`); two-child successor-swap path @ `0x00402949` (decomp may mark unreachable).
   - If erased black → recolor + Lrot `FUN_00407a60` / Rrot `FUN_00403200`.
   - Bare `operator_delete`; if size>0 then size--; `*outIt = succ`.
4. **Callees:** `FUN_004040a0`, `FUN_004031e0`, `FUN_004031c0`, `FUN_00407a60`, `FUN_00403200`, `FUN_00401bc0`, `basic_string` ctor, `_CxxThrowException`, `operator_delete`.
5. **Callers (5 named + 1 bare):** `FUN_004079a0` @ `0x00407a3e`; `FUN_00407bf0` @ `0x00407c8e`; `Client_Input_OnKeyDown_MatchAction` @ `0x00911260` (map `0x00d1b564`); `FUN_00942e20` @ `0x00943060`; `FUN_00944d50` @ `0x00944e83`; xref `0x00957e8c`.
6. **Name:** `StdTree_EraseAndRebalance_Isnil29_RetC_Inferred` (Ghidra `FUN_00402850`). **RetC** = stack 3-arg / `ret 0xC` family (≠ thiscall isnil29 `004cb740`). Scaffold `Named_CalleeOf_*` **retired**.
7. **Decompile ≡ raw CF** for throw/unlink/rebalance; ABI/epilogue sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product/PDB demangle for host map / value payload English.  
- Dual of range parents + rotate/min helpers (OWN elsewhere).  
- Two-child splice plate full fidelity (decomp unreachable).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402850_FUN_00402850.md` |
| Annotated | `docs/reconstruction/raw/aa_00402850_FUN_00402850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402850.cpp` |
| Function | `docs/reconstruction/functions/aa_00402850_FUN_00402850.md` |
| Function named | `docs/reconstruction/functions/aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_Input_OnKeyDown_MatchAction  [0x00911030]
  └─ FUN_00402850  StdTree_EraseAndRebalance_Isnil29_RetC_Inferred  [OWN MEGA-034]
        map imm 0x00d1b564

FUN_004079a0 / FUN_00407bf0  erase-range parents  [residual]
  └─ FUN_00402850  (loop body)

FUN_00402850
  ├─ nil: string + FUN_00401bc0 Std_OutOfRange_CtorFromString  [dualed]
  │       + _CxxThrowException(DAT_00acc34c)
  ├─ FUN_004040a0  iterator++ isnil29  [residual]
  ├─ FUN_004031e0  min isnil29  [residual]
  ├─ FUN_004031c0  max isnil29  [residual]
  ├─ FUN_00407a60  Lrotate isnil29  [residual]
  ├─ FUN_00403200  Rrotate isnil29  [residual]
  └─ operator_delete

Do not merge:
  004cb740  StdTree_EraseAndRebalance_Isnil29_Inferred  (thiscall RET8)
  00603830  StdTree_EraseAndRebalance_Val28_Isnil29_Inferred
  00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred  (isnil31 / different rotates)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402850-mega-034-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402850` | Port as **single-node `_Tree` erase + RB rebalance** for isnil@**+0x29** / color@**+0x28**. **Three stack args**, **`RET 0x0C`**. Pair with isnil29 iterator++ `004040a0`, min `004031e0`, max `004031c0`, L/R `00407a60`/`00403200`. Throw plate shared with dualed `00401bc0` / `"invalid map/set<T> iterator"`. Do **not** use thiscall RET8 or isnil31 rotates. No value dtor. |
| Pair with | dualed out_of_range `00401bc0`; dualed isnil31 stack twin `00408ed0` (ABI shape only); residual range parents `004079a0`/`00407bf0`; residual rotate/min helpers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL tree erase — input-drive-control caller only, not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00402850`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name with `_Inferred` + **RetC** ABI qualifier; machine ABI corrections (stack RET 0xC; epilogue past false noreturn).  
- Odd behavior preserved: decomp unreachable two-child path; noreturn-on-delete truncation; OnKeyDown is caller not role.  
- Scaffold `Named_CalleeOf_*` retired. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

# Dual A/B report — MEGA-013 OWN-ONLY (`0x0052b350`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-013**  
**Scope:** VA `0x0052b350` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `analyze_control_flow` + callee/parent decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual partition — reward inventory list insert under CompleteObjective parent `0x004d08c0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052b350` CVOGCharacter_RewardInventoryList_PushBack_Inferred | **accept-with-gaps** — CF/ABI/RET4/list push_back/+0xcc4 sealed; product field English residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-list ECX-merge / push_front / tree-vector / cdecl / `const T*` ABI claims **falsified**; product English gap **retained**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0052b350` — sealed facts

1. **Body:** `0x0052b350`–`0x0052b388` inclusive (**57 B** / `0x39`); pad `CC` after.
2. **ABI:** **ECX** = owner (character*); stack **dword value by value**; void; **`RET 4`**.
3. **Semantics:** MSVC `std::list` **push_back** on embedded list at **this+0xcc4**:
   - `head = *(this+0xcc8)`; `list = this+0xcc4`
   - `node = BuyNode(head, head->_Prev, &value)` via dualed `StdList_BuyNode_Dword_Seh` `0x00418700` (node **0xC**)
   - `Incsize(list, 1)` via `FUN_00404840` (may throw `"list<T> too long"` / length_error)
   - `head->_Prev = node`; `old_prev->_Next = node`
4. **Callees:** `FUN_00418700`, `FUN_00404840`.
5. **Callers:** **1** UNCONDITIONAL_CALL — `FUN_004d08c0` @ `0x004d0980` (CompleteObjective 4-slot reward loop: resolve item, flag `+0x17c|=4`, TFID copy, `PUSH ESI; CALL`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `CVOGCharacter_RewardInventoryList_PushBack_Inferred` (Ghidra `FUN_0052b350`). Product field English open → `_Inferred`. Retire `Named_CalleeOf_Named_CalleeOf_CVOGReaction_CompleteObjective_0052b350`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context (decompiler `__fastcall`/void corrected).
9. **Distinct from** dualed free helper `StdList_PushBack_Dword_Inferred` `0x00402d10` (ECX=list*; stack=`const T*`).

### Gaps

- Product English for list member at `+0xcc4` (reward inventory inferred from parent/partition).  
- Exact payload type English beyond item/object* from `FUN_004cf120`.  
- Parent `FUN_004d08c0` residual dual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052b350_FUN_0052b350.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b350_FUN_0052b350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_RewardInventoryList_PushBack_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052b350.cpp` |
| Function | `docs/reconstruction/functions/aa_0052b350_FUN_0052b350.md` |
| Function named | `docs/reconstruction/functions/aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGReaction_CompleteObjective  (parent chain; residual)
  └─ FUN_004d08c0  Named_CalleeOf_CVOGReaction_CompleteObjective  [residual]
       │  4× reward slots: FUN_004cf120 → flag|TFID →
       └─ FUN_0052b350  CVOGCharacter_RewardInventoryList_PushBack_Inferred  [OWN MEGA-013]
            ├─ FUN_00418700  StdList_BuyNode_Dword_Seh  [dualed MEGA-081]
            └─ FUN_00404840  list Incsize / "list<T> too long"  [shared residual]

Related free twin (different ABI):
  FUN_00402d10  StdList_PushBack_Dword_Inferred  [dualed MEGA-126]  // ECX=list*
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0052b350-mega-013-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052b350` | Port as **character-bound `std::list` push_back** at **owner+0xcc4**. **thiscall RET 4**; stack **dword by value**. Node **0xC** via BuyNode `0x00418700`; size++ via `0x00404840` (overflow throw). |
| Do **not** merge with | free `StdList_PushBack_Dword_Inferred` `0x00402d10` (ECX=list*, `const T*`). |
| Pair with | dualed BuyNode `0x00418700`; residual parent `0x004d08c0` CompleteObjective reward loop; nearby `CVOGCharacter_IsMission*` methods. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` missions-progression residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0052b350`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + callee family. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; machine ABI corrections (thiscall RET 4; by-value dword; owner ECX).  
- Odd behavior preserved: decompiler loses RET 4 / by-value shape; Incsize may throw out-of-line; sole caller.  
- Retire `Named_CalleeOf_*` scaffold. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

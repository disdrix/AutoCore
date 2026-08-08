# Dual A/B report — MEGA-059 OWN-ONLY (`0x004025e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-059**  
**Scope:** VA `0x004025e0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Named_CalleeOf `CVOGReaction_TransferMap` leaf → MSVC list push_back Val0x28.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004025e0` StdList_PushBack_Val0x28_Inferred | **accept-with-gaps** — CF/ABI/RET4/list layout/node0x30/val0x28/sole caller sealed; product T English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cookie/epilogue / map-tree / CsSList / push-front / dword-node / reaction-product-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004025e0` — sealed facts

1. **Body:** `0x004025e0`–`0x00402611` inclusive last byte (**50 B** / `0x32`); pad `CC` before `Client_EnqueueCombatFloater_INFERRED` `0x00402620`.
2. **ABI:** **ECX** = list*; stack `const T*`; void; **`RET 4`**.
3. **Semantics:** MSVC **`std::list::push_back`** for **T size 0x28**:
   - `head = list->_Myhead` (+4)
   - `node = FUN_00403560(head, head->_Prev, val)` — `operator_new(0x30)` + `FUN_00404390` (Next/Prev + 10 dword value)
   - `FUN_00403600(1)` — `_Incsize`; max **`0x6666666`** (`0xFFFFFFFF/0x28`); `"list<T> too long"` @ `0x00a1581c`; ThrowInfo `DAT_00acc388`
   - `head->_Prev = node`; `node->_Prev->_Next = node`
4. **Callees:** `FUN_00403560`, `FUN_00403600` only.
5. **Callers:** **1** UNCONDITIONAL_CALL — `CVOGReaction_TransferMap` @ `0x004d3893` with `ECX = reaction+0xe778`, stack local T.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `StdList_PushBack_Val0x28_Inferred` (Ghidra `FUN_004025e0`). Product T English open → `_Inferred`. Retire `Named_CalleeOf_CVOGReaction_TransferMap_*`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + parent call-site context.

### Gaps

- Product English for T (0x28 transfer payload) and list member at `CVOGReaction+0xe778`.  
- Residual duals for buynode/incsize leaves (context only).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004025e0_StdList_PushBack_Val0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004025e0_StdList_PushBack_Val0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004025e0_FUN_004025e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004025e0_FUN_004025e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushBack_Val0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004025e0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGReaction_TransferMap_004025e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004025e0_FUN_004025e0.md` |
| Function named | `docs/reconstruction/functions/aa_004025e0_StdList_PushBack_Val0x28_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGReaction_TransferMap  0x004d37f0  [prior dual; missions-progression]
  ├─ gates: flag+0x7e, param object, vtbl+0x210 resolve, !+0x4f4
  ├─ FUN_004d2ac0  transfer attempt
  ├─ set resolved+0x4f4 = 1
  ├─ build local T (0x28) from resolved fields + args
  └─ FUN_004025e0  StdList_PushBack_Val0x28_Inferred  [OWN MEGA-059]
        ECX = reaction+0xe778
        ├─ FUN_00403560  Buynode0x30  [residual]
        │     └─ FUN_00404390  node ctor Next/Prev/val×10  [residual]
        └─ FUN_00403600  Incsize max 0x6666666  [residual]
              └─ "list<T> too long" / FUN_00401a40 / _CxxThrowException
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004025e0-mega-059-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004025e0` | Port as **`std::list::push_back`** for **T size 0x28** (node **0x30**). **thiscall RET 4**. Pair with Incsize max **`0x6666666`** and buynode `operator_new(0x30)`. |
| Host | Sole known: `CVOGReaction` list at **`+0xe778`** from `CVOGReaction_TransferMap`. Do **not** name the helper as a reaction method. |
| Keep distinct from | dword `StdList_PushPayloadNode`; CsSList append `004024d0`; map/tree inserts; cookie/epilogue stubs. |
| Pair with | residual buynode `00403560` / ctor `00404390` / Incsize `00403600`; dualed TransferMap parent. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL list — not skill-specific; seed missions-progression)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004025e0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 4; ECX=list; T=0x28).  
- Odd behavior preserved: buynode call sets ECX=list though `00403560` does not read ECX (stdcall-ish RET 0xC member shape).  
- `_Inferred` where product T English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

# Dual A/B report — MEGA-081 OWN-ONLY (`0x00418700`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-081**  
**Scope:** VA `0x00418700` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `disassemble_function` + `analyze_function_complete` + callers/xrefs + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-081 residual dual seal — Reward/list partition hint → sealed as **shared list `_Buynode` SEH twin**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00418700` StdList_BuyNode_Dword_Seh | **accept** — CF/ABI/RET0xC/EAX/SEH/61 xrefs/twin sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): DebugListMissionsStatus-only / reward-only / tree-Buynode / thiscall / true-void / freelist claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00418700` — sealed facts

1. **Body:** `0x00418700`–`0x00418779` inclusive (**122 B** / `0x7A`); last insn `RET 0xC` (`C2 0C 00`).
2. **ABI:** stack `link0`, `link1`, `uint32_t* pValue`; **EAX** = node*; **`RET 0xC`** (`__stdcall`). Not thiscall.
3. **Semantics:** MSVC `list::_Buynode` for dword payload:
   - SEH frame (`LAB_009bc331` / FS:[0]).
   - `operator_new(0xC)`; null → return 0.
   - Else `node[0]=link0; node[1]=link1; node[2]=*pValue`.
   - Does **not** Incsize or relink (callers do).
4. **Callees:** `operator_new` @ `0x00489892` only (normal path).
5. **Callers / xrefs:** **61** UNCONDITIONAL_CALL; insert wrappers + multi-domain product code.
6. **Twin:** dualed `StdList_BuyNode_Dword` `0x006759b0` (same fill CF, **no** SEH, 39 B).
7. **Name:** `StdList_BuyNode_Dword_Seh` (Ghidra `FUN_00418700`). Retire `Named_CalleeOf_Client_DebugListMissionsStatus_00418700`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site EAX capture. Decompiler `void` corrected.

### Gaps

- Product `list<T>` English beyond dword-sized payload.  
- Full EH state-table narrative for `LAB_009bc331`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00418700_StdList_BuyNode_Dword_Seh.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00418700_StdList_BuyNode_Dword_Seh.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00418700_FUN_00418700.md` |
| Annotated | `docs/reconstruction/raw/aa_00418700_FUN_00418700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_BuyNode_Dword_Seh.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00418700.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_DebugListMissionsStatus_00418700.cpp` |
| Function | `docs/reconstruction/functions/aa_00418700_FUN_00418700.md` |
| Function named | `docs/reconstruction/functions/aa_00418700_StdList_BuyNode_Dword_Seh.md` |

---

## Chain context (not dualled; evidence only)

```text
insert wrappers (e.g. FUN_00402d10 / FUN_004040f0 / FUN_00517db0)
  ├─ FUN_00418700  StdList_BuyNode_Dword_Seh  [OWN MEGA-081]
  ├─ FUN_00404840  Incsize "list<T> too long"  [context]
  └─ head[+4]=node; *node[+4]=node

twin leaf (no SEH):
  StdList_BuyNode_Dword @ 0x006759b0  [dualed W20-M]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00418700-mega-081-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00418700` | Port as **`std::list` `_Buynode`** for **dword** nodes (size **0xC**). **`__stdcall` RET 0xC**; return **EAX**. SEH around `new` is CRT-shaped; success CF matches twin `006759b0`. Do **not** Incsize/relink inside this leaf. Keep distinct from tree Buynode / isnil families. |
| Pair with | dualed twin `StdList_BuyNode_Dword` `006759b0`; Incsize `00404840`; insert wrappers residual. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL list helper — multi-domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00418700`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (stdcall RET 0xC; EAX return vs decompiler void).  
- Scaffold `Named_CalleeOf_*` retired. Twin relationship to `006759b0` documented.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

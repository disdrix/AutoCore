# Dual A/B report — MEGA-040 OWN-ONLY (`0x00402b30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-040**  
**Scope:** VA `0x00402b30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual partition — Named_CalleeOf `NotifyActiveMissionChanged` seed → seal as isnil31 uint-key insert-or-find.  
**Hint system:** missions-progression (host map only).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402b30` StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred | **accept-with-gaps** — CF/ABI/RET4/EAX+EBX/isnil31/uint key/equal no-rewrite/3 callers sealed; product map English + insert/pred duals open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-product / thiscall / signed-key / isnil29-merge / equal-rewrite / RET0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402b30` — sealed facts

1. **Body:** `0x00402b30`–`0x00402be6` inclusive (**183 B** / `0xB7`); pad `CC` @ `0x00402be7`.
2. **ABI:** **EAX** = map shell; **EBX** = value* (key = `*(uint32*)EBX`); stack out `{Node* it, u8 inserted@+4}`; **EAX** returns out; **`RET 4`** ×3 exits.
3. **Semantics:** classic MSVC **insert-or-find**:
   - Walk from root (`head->parent`) while `!isnil@+0x31`.
   - Unsigned compare key vs `node+0x10` (`SETC` / `JNC`).
   - Miss → `FUN_00403250` insert+RB (addLeft=1 at begin, else goLeft flag).
   - goLeft && not begin → predecessor `FUN_00404290` then re-check.
   - Hit → `{existing, inserted=0}`; **no mapped rewrite**.
4. **Node family:** isnil@**+0x31**, color@**+0x30**, key@**+0x10**, size **0x38** (peer BuyHead/Lrot/erase isnil31).
5. **Callees:** `FUN_00403250` (insert+RB, unOWN); `FUN_00404290` (predecessor, unOWN).
6. **Callers (3 UNCONDITIONAL_CALL):**
   - `Client_NotifyActiveMissionChanged` `FUN_00944770` @ `0x00944802`, `0x009448bd` — map **`client+0xf14`**.
   - `FUN_00933310` @ `0x00933363` — thin wrapper.
7. **Name:** `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` (Ghidra `FUN_00402b30`). Product map open → `_Inferred`.
8. **Rejected:** `Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30` (xref-seed scaffold).
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / English host map type at client+`0xf14`.  
- Dual of insert `00403250` / pred `00404290` (unOWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402b30_FUN_00402b30.md` |
| Annotated | `docs/reconstruction/raw/aa_00402b30_FUN_00402b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402b30.cpp` |
| Function | `docs/reconstruction/functions/aa_00402b30_FUN_00402b30.md` |
| Function named | `docs/reconstruction/functions/aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md` |
| Scaffold (retired product plate; superseded) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30.cpp` |

---

## Chain context (not dualled; evidence only)

```text
Client_NotifyActiveMissionChanged  FUN_00944770  [parent; not OWN]
  ├─ map @ client+0xf14
  ├─ FUN_00402b30  StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred  [OWN MEGA-040]
  │     ├─ FUN_00403250  insert+RB isnil31  [residual unOWN]
  │     │     ├─ FUN_00403e90  StdTree_Lrotate_Isnil31_Inferred  [dualed]
  │     │     └─ FUN_00403ee0  StdTree_Rrotate_Isnil31_Inferred  [dualed]
  │     └─ FUN_00404290  predecessor isnil31  [residual unOWN]
  ├─ FUN_00408590  IteratorIncrement isnil31  [dualed elsewhere]
  └─ FUN_00406bc0  erase subtree helper  [residual]

FUN_00933310  thin wrapper → FUN_00402b30  [OWN target only]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402b30-mega-040-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402b30` | Port as **uint32-key insert-or-find** for isnil@**+0x31** nodes (size 0x38). **EAX=map, EBX=value*, stack out, RET 4**. Equal key → no mapped rewrite. Keep distinct from isnil15 EaxEbx `00458510` and isnil29 thiscall InsertOrFind peers. |
| Host | Mission client map @ **+0xf14** used by `NotifyActiveMissionChanged` — product entry type still open. |
| Pair with | residual insert `00403250`; residual pred `00404290`; dualed L/R rotate isnil31; dualed erase isnil31 `00408ed0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/missions-progression.md` residual tables (STL helper hosted by mission UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  
- Retire/supersede `Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30` plate in any indexes  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00402b30`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (EAX map / EBX value / RET 4 / unsigned).  
- Odd behavior preserved: equal key does not rewrite mapped; decompiler phantom regs corrected via assembly.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

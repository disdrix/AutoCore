# Dual A/B report — MEGA-042 OWN-ONLY (`0x00405920`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-042**  
**Scope:** VA `0x00405920` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `batch_decompile` (callers) + `analyze_control_flow`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition MEGA-042 / inventory-transfer residual under SendInventoryAddItem nested plate (body is generic CsSList remove).  
**Hint consumed:** `SendInventoryAddItem nested` → **parent seed only**; not this VA's product English.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00405920` CsSList_RemoveFirstByPredicate_Inferred | **accept-with-gaps** — CF/ABI/RET8/dual-CS/layout/first-match/family sealed; product class English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-only / remove-all / Append-merge / Contains-merge / wrong ECX / RET4 / bare delete claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00405920` — sealed facts

1. **Body:** `0x00405920`–`0x004059b9` inclusive (**154 B** / `0x9A`); pad `CC` after `RET 8`.
2. **ABI:** **ECX** = list\*; stack `pred*`, `cookie`; void; **`RET 8`**.
3. **Semantics:** dual-CS walk; `pred(payload, cookie)`; on first true → unlink (head/prev/tail), clear payload, `vtbl[0](1)` scalar dtor, `InterlockedDecrement(list+0xC)`; leave both CS. At most one remove.
4. **Layout:** head `+4`, tail `+8`, count `+0xC`, CS `+0x10` / `+0x28`; node vtbl/`payload`/`next` — **same family** as dualed Append `004024d0` and Contains `004e15a0`.
5. **CS policy:** always outer then inner (Contains twin; **not** Append's count≤3 gate).
6. **Callees:** EnterCriticalSection ×2, LeaveCriticalSection ×2, InterlockedDecrement, node vtbl[0].
7. **Callers (2 / 3 sites):**
   - `FUN_004d4790` (Object_QueueDelete path) @ `0x004d4855` — after Contains true; list `[…+0xe648]`; pred `0x4cd580`
   - `FUN_00944d50` @ `0x00944d8f`, `0x00944e1e` — list `[…+0xe5fc]`; pred `0x92d8e0`
8. **Xrefs:** 3 `UNCONDITIONAL_CALL`.
9. **Predicate stubs:** both sites use pointer-equality (`MOV/CMP/SETE/RET 8`) — not inventory string logic.
10. **Name:** `CsSList_RemoveFirstByPredicate_Inferred` (Ghidra `FUN_00405920`).  
    Retired: `Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920`.
11. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product C++ class / node vtbl English (`009cb340` family).  
- Which host list is inventory-transfer vs delete-queue vs world-manager.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00405920_CsSList_RemoveFirstByPredicate_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00405920_CsSList_RemoveFirstByPredicate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00405920_FUN_00405920.md` |
| Annotated | `docs/reconstruction/raw/aa_00405920_FUN_00405920.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CsSList_RemoveFirstByPredicate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00405920.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920.cpp` |
| Function | `docs/reconstruction/functions/aa_00405920_FUN_00405920.md` |
| Function named | `docs/reconstruction/functions/aa_00405920_CsSList_RemoveFirstByPredicate_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004d4790  Object_QueueDelete path  [not OWN]
  ├─ FUN_004e15a0  CsSList_ContainsPayload_Inferred  [dualed]
  ├─ FUN_00405920  CsSList_RemoveFirstByPredicate_Inferred  [OWN MEGA-042]
  │     pred LAB_004cd580  (ptr-eq)
  └─ FUN_004024d0  CsSList_AppendPayload_Inferred  [dualed; sibling enqueue]

FUN_00944d50  object teardown  [not OWN]
  └─ FUN_00405920  ×2  (object + related cookie)  [OWN MEGA-042]
        pred LAB_0092d8e0  (ptr-eq)

CsSList family:
  004024d0  AppendPayload     [dualed]
  004e15a0  ContainsPayload   [dualed]
  00405920  RemoveFirstByPred [OWN MEGA-042]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00405920-mega-042-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00405920` | Port as **dual-CS list remove-first-if(pred, cookie)**. **ECX=list**, stack pred+cookie, **RET 8**. Always both locks. Free node via **scalar deleting dtor** (`vtbl[0](1)`), not bare free. Keep distinct from Append (`004024d0`) and Contains (`004e15a0`). Do **not** name as SendInventoryAddItem. |
| Pair with | dualed Append `004024d0`; dualed Contains `004e15a0`; consumers Object_QueueDelete `004d4790`, teardown `00944d50`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (CsSList family / inventory-transfer plate reclassify)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00405920`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + pred stub bytes. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin `FUN_00405920.cpp` kept; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: first-match only; always dual-CS; InterlockedDecrement after dtor; pred RET 8.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

# Dual A/B report — MEGA-116 OWN-ONLY (`0x0048a060`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-116**  
**Scope:** VA `0x0048a060` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including sort core `0x00489f20` / MEGA-115).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `disassemble_function` + `get_function_by_address` + call-site context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-116**.  
**Work item:** residual dual seal — **sort soft-cast hits (count>1)** under dualed `Client_InteractWorldClickHub` (`0x00925820`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0048a060` SoftCastHitList_SortIfCountGt1_Inferred | **accept-with-gaps** — CF/ABI/RET/count>1 gate/sole hub caller/sort dispatch sealed; product English + sort-key label open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-fastcall / always-sort / inline-qsort / multi-caller / skill-inventory-sort / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0048a060` — sealed facts

1. **Body:** `0x0048a060`–`0x0048a082` inclusive (**35 B** / `0x23`); next `FUN_0048a083`.
2. **ABI:** **ECX** = soft-cast hit-list this; void; bare **`RET`** (`C3`). Decompiler `__fastcall(uint)` is ECX-as-int view.
3. **Semantics:** sort **gate** only:
   - `count = *(int*)(this+0x14)`; if `count <= 1` return.
   - Else `FUN_00489f20(*(void**)(this+0x10), 0, count-1, this & 0xFFFFFF00)` (`cdecl`, `ADD ESP,0x10`).
   - Local cookie = `PUSH ECX` then zero low byte (`this & ~0xFF`); sort re-pushes cookie on recurse only (no compare use).
4. **Hit layout (structural):** base `+0x10`, count `+0x14`; elem **0x30**; sort key **float @ +0x14** (in callee); object slot **+0x20** (hub walk).
5. **Callees:** `FUN_00489f20` only (MEGA-115 OWN residual).
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL — `Client_InteractWorldClickHub` / `FUN_00925820` @ `0x00925c3e` after `FUN_0040c410` + `FUN_0055e1e0`.
7. **Name:** `SoftCastHitList_SortIfCountGt1_Inferred` (Ghidra `FUN_0048a060`). Product map open → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire.
8. **Decompile ≡ raw scaffold CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site `LEA ECX`.

### Gaps

- Product English for hit-list class and float key (distance vs other).  
- Sort implementation dual is MEGA-115 (`0x00489f20`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0048a060_FUN_0048a060.md` |
| Annotated | `docs/reconstruction/raw/aa_0048a060_FUN_0048a060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_SortIfCountGt1_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048a060.cpp` |
| Function | `docs/reconstruction/functions/aa_0048a060_FUN_0048a060.md` |
| Function named | `docs/reconstruction/functions/aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ FUN_0040c410     init/clear soft-cast hit container
  ├─ FUN_0055e1e0     soft-cast fill wrapper
  │    └─ FUN_006ca890  hit-list core  [residual / MEGA-062 family]
  ├─ FUN_0048a060     SoftCastHitList_SortIfCountGt1_Inferred  [OWN MEGA-116]
  │    └─ FUN_00489f20  qsort 0x30 / float key +0x14  [MEGA-115 OWN]
  └─ walk hits
       └─ FUN_0040afb0  resolve object* from hit  [MEGA-028 residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0048a060-mega-116-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0048a060` | Port as **hit-list sort gate**: `if (count > 1) Qsort(base, 0, count-1)`. **thiscall**, bare **RET**. Fields: base `@+0x10`, count `@+0x14`. |
| Do **not** | Inline the 0x30-stride quicksort here; keep at `00489f20`. Do not sort when count ≤ 1. |
| Optional | Retail emits unused cookie `this & ~0xFF` as 4th arg — omit in managed unless native bit-exact required. |
| Pair with | dualed hub `00925820`; residual sort `00489f20`; residual resolve `0040afb0`; fill `0055e1e0` / `006ca890`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` interaction-activation residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0048a060`); no Launcher; no parent ledger edits; no other VAs dualed.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (thiscall ECX; bare RET; count>1 gate).  
- Odd behavior preserved: masked this cookie 4th arg; no-op on count ≤ 1.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

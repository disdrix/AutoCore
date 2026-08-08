# Dual A/B report — MEGA-011 OWN-ONLY (`0x004bae00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-011**  
**Scope:** VA `0x004bae00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-011 residual dual seal — pick-list / SelectBestPick enumerator residual (`aa_004bae00`).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bae00` Host_DualCNDHash_TraverseNextObject_Inferred | **accept-with-gaps** — CF/ABI/RET8/dual-list offsets/lock sandwich/SelectBestPick host binding sealed; product host English + `004bc530` dual open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): LoadMapFile scaffold / CS-list merge / multi-step held lock / inverted flag polarity / bare-RET / Client-this / node*-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004bae00` — sealed facts

1. **Body:** `0x004bae00`–`0x004bae63` inclusive (**100 B** / `0x64`).
2. **ABI:** **ECX** = dual-list host; stack `char listSelect`, `int* cursor`; **EAX** = object* or NULL; **`RET 8`** ×3 exits.
3. **Semantics:** single-step dual-CNDHash object enumerator:
   - `listSelect == 0` → gate `host+0xd`, hash `host+0x8`.
   - `listSelect != 0` → gate `host+0xc`, hash `host+0x4`.
   - `CNDHash_TraversalLock_Set` (`0x00402c40`) → `FUN_004bc530` TraverseToNext (payload `node+0xc`) → clear `hash+0x1d`.
   - Fail (enable clear / null hash) → EAX=0 without lock.
4. **Callees:** `FUN_00402c40` (dualed MEGA-110 lock set); `FUN_004bc530` (TraverseToNext residual MEGA-029; string `"HashError:TraverseToNext, not locked for traversal"` @ `0x00a27c9c`).
5. **Callers:** **13** functions / **28** UNCONDITIONAL_CALL. Sample dualed SelectBestPick `0x00490070` @ `0x0049010b`/`0x0049048f` with ECX=`[Client+0xBC]`, flag **0 then 1**.
6. **Name:** `Host_DualCNDHash_TraverseNextObject_Inferred` (Ghidra `FUN_004bae00`). Product host English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00` **retired**.
7. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Decompiler elides callee ECX restores — assembly corrects.

### Gaps

- Product RTTI / English for dual-list host class.  
- Product labels for list A vs B (flag 0/1).  
- Dual seal of `FUN_004bc530` (MEGA-029 OWN residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004bae00_FUN_004bae00.md` |
| Annotated | `docs/reconstruction/raw/aa_004bae00_FUN_004bae00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_DualCNDHash_TraverseNextObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bae00.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00.cpp` |
| Function | `docs/reconstruction/functions/aa_004bae00_FUN_004bae00.md` |
| Function named | `docs/reconstruction/functions/aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_Interact_SelectBestPickTarget  FUN_00490070  [dualed]
  └─ Host_DualCNDHash_TraverseNextObject_Inferred  004bae00  [OWN MEGA-011]
       ├─ CNDHash_TraversalLock_Set_Inferred  00402c40  [dualed MEGA-110]
       └─ FUN_004bc530  TraverseToNext payload@+0xc  [residual MEGA-029]

Client_FlushWorldObjectState_Inferred  00943b80  [dualed]
  └─ 004bae00 ×2 (flag toggle) → ObjectList_ExportTfidsToMap

MEGA-029 residual: FUN_004bc530  (walk payload node+0xc)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004bae00-mega-011-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bae00` | Port as **dual-CNDHash host single-step object enumerator**. **thiscall RET 8**. ECX=host with lists at `+4/+8` and enables at `+c/+d`. Flag **0 → list B (+8)**; flag **≠0 → list A (+4)**. Sandwich: lock set → TraverseToNext → clear `hash+0x1d`. Return object* from `node+0xc`. |
| SelectBestPick | Bind enumerator host to **`Client+0xBC`**; two passes flag 0 then 1. Closes prior “enumerator host Tentative” gap. |
| Pair with | dualed lock `00402c40`; residual walk `004bc530`; dualed SelectBestPick `00490070`. Distinct from CS `List_TraversalLock/Unlock` (`+0x28`). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (interaction-activation pick enumerator)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004bae00`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (RET 8; callee ECX restores).  
- Odd behavior preserved: lock is set then cleared every step (not multi-step hold); fail paths skip lock; flag 0 maps to **list B** (`+8`), not list A.  
- `_Inferred` where product host English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

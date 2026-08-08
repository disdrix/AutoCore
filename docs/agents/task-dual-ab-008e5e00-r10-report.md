# Dual A/B report — R10-015 OWN-ONLY (`0x008e5e00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-015**  
**Scope:** VA `0x008e5e00` (`aa_008e5e00`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual rewrite.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-015**.  
**Work item:** Residual dual seal — inventory-transfer craft host material list refresh (`Client_UI_CraftHost_RefreshMaterialList`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008e5e00` Client_UI_CraftHost_RefreshMaterialList_Inferred | **accept-with-gaps** — CF/ABI/EDI-host/RET0/TFID sentinel/`[M]`/`[L]`/callers/rebind sealed; bit-19 product English + residual helpers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ECX-thiscall / stack-args / mission-only scaffold / decompiler invalid test / always-scan claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008e5e00` — sealed facts

1. **Body:** `0x008e5e00`–`0x008e6386` inclusive (**1415 B** / `0x587`); pad `CC` then sibling host code (caller site `0x008e63f5`).
2. **ABI:** host in **EDI** on entry; **no stack args**; void; plain **`RET`** (`C3`). Not ECX-thiscall.
3. **Semantics:** refresh craft host material list:
   - Early-out if `host+0x754 == 0`.
   - Snapshot list vtbl+`0x490` / +`0x49c` / +`0x44c` (TFID pair).
   - Invalid selection: **`(lo & hi) == -1`** (asm; decompiler wrong) → if `host+0x7cc` set, use bound object TFID `+0x160/+0x164`.
   - Clear list vtbl+`0x458`.
   - **Cargo:** `char+0x250`→`+0x2b0` grid walk under CS; items with `+0x17c` bit 19 set → plain name + list add.
   - **Locker:** `char+0xcbc` when `DAT_00d1b644+0xf5`; prefix **`[L]`** (`DAT_00a3af64`).
   - **Equip:** `FUN_00522000` count; table `char+0x5a0`; `CVOGReaction_ResolveObjectTarget(1,lo,hi)`; prefix **`[M]`** (`DAT_00a3af60`).
   - Restore vtbl+`0x448`(sel); zero `list+0x568`; vtbl+`0x498`(snapB).
   - If selection TFID changed → dualed **`FUN_008e5ce0(host,lo,hi)`** stdcall.
   - If +`0x490` changed → `FUN_007fbd30` (asm EAX=list, ESI=`host+0x758`).
4. **Classification:** worker.
5. **Xrefs:** 2 UNCONDITIONAL_CALL — `0093a9d3`, `008e63f5`.
6. **Callers:** `Client_RefreshOpenMissionUiWindows`; sibling craft-host op at `0x008e63f5`.
7. **Callees:** map walk helpers, string helpers, `FUN_008e4430`, `FUN_00522000`, `CVOGReaction_ResolveObjectTarget`, `sprintf`, `FUN_008e5ce0`, `FUN_007fbd30`, `DeleteCriticalSection`, vtbls.
8. **Name:** `Client_UI_CraftHost_RefreshMaterialList_Inferred` (Ghidra `FUN_008e5e00`). Product host class open → `_Inferred`.
9. **Retired scaffold:** `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e5e00`.
10. **Decompile ≡ raw CF**; ABI/TFID sentinel sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product demangle for craft host / list widget.  
- `+0x17c` bit 19 product English (parent dual “Broken” filter-out vs this filter-in).  
- Residual helper English (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008e5e00_FUN_008e5e00.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5e00_FUN_008e5e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_RefreshMaterialList_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e5e00.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e5e00.cpp` |
| Function | `docs/reconstruction/functions/aa_008e5e00_FUN_008e5e00.md` |
| Function named | `docs/reconstruction/functions/aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_RefreshOpenMissionUiWindows  FUN_0093a940
  └─ FUN_008e5e00  refresh material list   [OWN R10-015]

sibling craft-host op  (site 0x008e63f5)
  └─ FUN_008e5e00  same

FUN_008e5e00
  ├─ cargo / locker / equip inventory fill
  └─ on selection change:
       Client_UI_CraftHost_BindObjectByTfid_Inferred  FUN_008e5ce0  [dualed WQ8R-H]
         └─ UI_CraftHost_BindResolvedObject_Inferred  FUN_008e5990  [dualed MEGA-032]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008e5e00-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008e5e00` | Port as **craft-host material list refresh**. **EDI host**, no stack args, plain RET. Clear `host+0x754` list; refill from cargo (plain), locker (`[L]`), equip (`[M]`); filter items with `+0x17c` bit 19 set; restore selection; if TFID changed call dualed bind-by-TFID `008e5ce0`. Do **not** treat as mission-only helper (scaffold retired). Keep distinct from TFID resolve / object bind units. |
| Pair with | dualed `Client_UI_CraftHost_BindObjectByTfid_Inferred` `008e5ce0`; dualed `UI_CraftHost_BindResolvedObject_Inferred` `008e5990`; residual `FUN_008e4430`, `FUN_00522000`, `FUN_007fbd30`, map iterators. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` inventory-transfer residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

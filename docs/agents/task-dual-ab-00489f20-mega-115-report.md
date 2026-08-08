# Dual A/B report — MEGA-115 OWN-ONLY (`0x00489f20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-115**  
**Scope:** VA `0x00489f20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including gate `0x0048a060` / MEGA-116).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees + `disassemble_function` + `get_function_signature` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-115**.  
**Work item:** residual dual seal — **hit-list sort implementation** under dualed `SoftCastHitList_SortIfCountGt1_Inferred` (`0x0048a060`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00489f20` SoftCastHitList_QuickSortRange_KeyFloat14_Inferred | **accept-with-gaps** — CF/ABI/cdecl/RET/Hoare qsort/stride 0x30/key float+0x14/partial swap/sole external caller sealed; product key English + sticky-field semantics open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / full-0x30-memcpy / descending / key-at-0-or-20 / STL-sort / multi-caller / cookie-in-compare / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00489f20` — sealed facts

1. **Body:** `0x00489f20`–`0x0048a05d` inclusive (**318 B** / `0x13E`); pad `CC CC` before gate `FUN_0048a060` @ `0x0048a060`.
2. **ABI:** **cdecl** — stack `base, lo, hi, cookie`; void; bare **`RET`** (`C3`); caller **`ADD ESP,0x10`** at recurse (`0x0048a045`) and parent (`0x0048a07e`). Frame: `AND ESP,0xFFFFFFF0; SUB ESP,0x64`.
3. **Semantics:** Hoare-partition **quicksort** ascending on **float @ elem+0x14**:
   - Mid pivot `((lo+hi)>>1)`.
   - Left scan while `key < pivot`; right while `pivot < key` (`FCOMP` / `TEST AH,0x5` / `JP`).
   - Partial swap when `i != j`: fields **`+0x00,+0x04,+0x08,+0x0C,+0x10,+0x14,+0x20`** only (not `+0x18,+0x1C,+0x24..+0x2C`).
   - Recurse left if `lo < j`; set `lo = i` and continue for right (tail).
   - **cookie** unused in compare/swap (parent seeds `this & 0xFFFFFF00`).
4. **Element layout (structural):** stride **0x30**; key float **+0x14**; hub object-related slot **+0x20** (swapped).
5. **Callees:** self only.
6. **Callers / xrefs:** **2** UNCONDITIONAL_CALL — self @ `0x0048a040`; external **`FUN_0048a060`** @ `0x0048a079` (dualed MEGA-116 `SoftCastHitList_SortIfCountGt1_Inferred`).
7. **Name:** `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` (Ghidra `FUN_00489f20`). Product key English open → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire.
8. **Decompile ≡ raw scaffold CF**; ABI/stride/key/swap sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for float key (distance vs other score).  
- Semantics of sticky (unswapped) dwords at +0x18..+0x1C / +0x24..+0x2C.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00489f20_FUN_00489f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00489f20_FUN_00489f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00489f20.cpp` |
| Function | `docs/reconstruction/functions/aa_00489f20_FUN_00489f20.md` |
| Function named | `docs/reconstruction/functions/aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ FUN_0040c410     init/clear soft-cast hit container
  ├─ FUN_0055e1e0     soft-cast fill wrapper
  │    └─ FUN_006ca890  hit-list core  [residual / MEGA-062 family]
  ├─ FUN_0048a060     SoftCastHitList_SortIfCountGt1_Inferred  [dualed MEGA-116]
  │    └─ FUN_00489f20  SoftCastHitList_QuickSortRange_KeyFloat14_Inferred  [OWN MEGA-115]
  └─ walk hits
       └─ FUN_0040afb0  resolve object* from hit  [MEGA-028 residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00489f20-mega-115-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00489f20` | Port as **cdecl Hoare quicksort** over soft-cast hits: stride **0x30**, ascending float key **@+0x14**, mid pivot, **partial** 7-field swap. Bare **RET**; caller cleans **16** bytes. Cookie arg ignored. |
| Keep distinct from | gate wrapper `SoftCastHitList_SortIfCountGt1` `0048a060` (count>1 trampoline only). |
| Pair with | dualed gate MEGA-116; hub `00925820`; residual fill `006ca890` / resolve `0040afb0`. |
| Fidelity hazard | Do **not** full-memcpy 0x30 elements — sticky fields at +0x18..+0x1C / +0x24..+0x2C must survive swap. |

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

- OWN VA only (`0x00489f20`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (cdecl bare RET; partial swap; unused cookie).  
- Odd behavior preserved: partial swap; dead cookie; equal keys do not advance scans; right partition iterative.  
- `_Inferred` where product key English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

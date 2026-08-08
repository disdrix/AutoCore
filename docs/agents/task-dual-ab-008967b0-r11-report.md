# Dual A/B report — R11-034 OWN-ONLY (`0x008967b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-034**  
**Scope:** VA `0x008967b0` (`aa_008967b0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-034**.  
**Work item:** Residual dual seal — undualed skills UI callee of dualed `LookupClassDisplayName_Inferred` (`0x0051f940`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008967b0` UI_SkillPanel_UpdateSharedColumnClassHints_Inferred | **accept-with-gaps** — EDI-this / table / product strings / sprintf-3 / dual widgets sealed; product method + vtbl+0x308 English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ECX-thiscall / stdcall / merge-with-0051f940 / inventory-or-HB / 2-arg-sprintf / 4-arg-lookup claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008967b0` — sealed facts

1. **Body:** `0x008967b0`–`0x00896986` inclusive (**471 B** / `0x1D7`); pad `CC` after plain `RET`.
2. **ABI:** **EDI-this** (panel*); **no stack args**; frame `SUB ESP,0x164`; plain **`RET`** (`C3`). Caller `0x00897a87`: `MOV EDI,EBP` then `CALL`.
3. **Semantics:** if `DAT_00d1b6d8 != 0` and `*(panel+0x51c)==1`, for non-null widgets at `+0x744` / `+0x748`:
   - Resolve local char blob via host chain; read **class@+0x531**, **race@+0x532**.
   - Index 12-pair share table: `i = class + race*4`; column A uses `pair[0]`, B uses `pair[1]`.
   - `LookupClassDisplayName_Inferred(sharedClass, race)` → ring-localize with `"class"` + prefix.
   - `sprintf(buf, "%s %s %s.", prefix, name, "class")` →  
     `"This column of skills is shared by the <Name> class."`
   - Virtual call `widget->vtbl[+0x308](buf)`.
4. **Share table:** even i → `(1,3)`; odd i → `(0,2)`; i=10 → `(3,1)`; i=11 → `(2,0)`.
5. **Callees:** `007a69d0` (locale), `007a6de0` (ring), `0051f940` (lookup), `sprintf` IAT.
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL @ `0x00897a89` (host not defined as Ghidra function).
7. **Name:** `UI_SkillPanel_UpdateSharedColumnClassHints_Inferred` (Ghidra `FUN_008967b0`). Prior string-plate `Skill_This_column_of_skills_is_shared_by_the*` retired as product claim.
8. **Decompile ≡ raw CF**; ABI/sprintf arity sealed via `disassemble_function` + `read_memory` (decompiler undercount on sprintf / trailing lookup args is not a CF conflict).

### Gaps

- Product/PDB panel method English.  
- `vtbl+0x308` and `+0x51c` mode English.  
- Caller host function recovery.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_008967b0_FUN_008967b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008967b0_FUN_008967b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008967b0.cpp` |
| Function | `docs/reconstruction/functions/aa_008967b0_FUN_008967b0.md` |
| Function named | `docs/reconstruction/functions/aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
LookupClassDisplayName_Inferred (0x0051f940)  [dualed WQ-009 / parent]
  └─ called by FUN_008967b0  [OWN R11-034]
        sole site 0x00897a89  (skill 2d window setup; MOV EDI,EBP)
          nearby XML: i_d_s_2d_wnd_frame_level_*.xml

Peer class/race consumers (not OWN):
  Character_GetClassDisplayName_Inferred
  Character_FormatClassAndLevelDisplay_Inferred
  FUN_00846820 (R11-028 sibling partition; different body — ingredients/reqs UI)
```

Partition system **skills-abilities** matches product string + skill-panel UI role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008967b0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008967b0` | Port as **UI refresh of two shared skill-column labels**. Input: panel mode + local class/race. Output: two widget strings via sealed pair table + class display names. Do **not** reimplement class-name table here (use shared `LookupClassDisplayName`). |
| Pair with | dualed `0051f940`; locale ring `007a69d0`/`007a6de0`; panel bind `UI_SkillPanel_BindAvailableButtons` (`0x00824140`) for broader skill UI. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry when the merge agent runs.
- Record first dual seal for `aa_008967b0` as `UI_SkillPanel_UpdateSharedColumnClassHints_Inferred`.
- Optionally promote string-plate scaffolds to point at the dual canonical name.

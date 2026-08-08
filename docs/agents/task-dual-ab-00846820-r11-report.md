# Dual A/B report — R11-028 OWN-ONLY (`0x00846820`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-028**  
**Scope:** VA `0x00846820` (`aa_00846820`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + call graph + xrefs + `audit_globals_in_function` + callee `batch_decompile`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual dual seal — undualed UI craft-requirements formatter; parent dual hint `0x0051f940` (class display name).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00846820` UI_AppendCraftRequirements_Inferred | **accept-with-gaps** — ABI/stages/strings/colors/field map sealed; callers + product symbol + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Combat-primary / ECX-thiscall-item / identical-to-00845360 / server-authority claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00846820` — sealed facts

1. **Body:** `0x00846820`–`0x00847232` inclusive (**4115 B** / `0x1013`); pad `CC` before `FUN_00847240` @ `0x00847240`.
2. **ABI:** stack **ItemOrCraft***; UI text in **ESI**; int line count; **plain RET** after SEH `add esp,0x1a8`.
3. **Semantics:** craft/recipe requirements UI block:
   - Gate: `DAT_00d1b6d8` local player.
   - **INGREDIENTS** from def slots `+0x498..+0x4a8` (count `FUN_00599dd0`).
   - **ENHANCEMENT INGREDIENTS** via item vfuncs `+0x60`/`+0x5c` → `FUN_005097b0` recipe rows.
   - **Discipline** `def+0x4ac`/`+0x4b0`.
   - **Required Faction/Class/Combat/Perception/Tech/Theory/Level** with red fail color `0xffff2020`.
4. **Callees:** ingredient count, recipe row, class/race name, four stat getters, discipline helpers, localize, sprintf, heap.
5. **Callers:** **none recovered** in live Ghidra (open gap).
6. **Xrefs:** empty to entry; product strings also referenced from `UI_BuildItemTooltipStats` inline path (not a call).
7. **Name:** `UI_AppendCraftRequirements_Inferred` (Ghidra `FUN_00846820`). Reject `Named_Required_Combat_00846820`.
8. **Decompile ≡ raw CF** for product stages; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Static caller inventory.  
- Product C++ method / UI text class.  
- Runtime / bit-exact / differential.  
- Full line-faithful clean body (stage reconstruction + raw; not bit-identical C).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00846820_UI_AppendCraftRequirements_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00846820_UI_AppendCraftRequirements_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00846820_FUN_00846820.md` |
| Annotated | `docs/reconstruction/raw/aa_00846820_FUN_00846820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00846820.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/UI_AppendCraftRequirements_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00846820_FUN_00846820.md` |
| Function named | `docs/reconstruction/functions/aa_00846820_UI_AppendCraftRequirements_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
skills-abilities craft UI formatters:
  00845360  UI_AppendItemRequirements          [dualed W23-J]  item "Requires:"
  00846820  UI_AppendCraftRequirements_Inferred [OWN R11-028] ingredients + Required*
            ├─ FUN_00599dd0  ingredient slot count
            ├─ FUN_005097b0  GetTypelessRecipe / enhancement rows
            ├─ FUN_0051f940  class display (parent partition hint)
            └─ 004c4070/41c0/3ff0/4140  Combat/Perception/Tech/Theory

Sibling string reuse (inline, not call):
  00847ad0  UI_BuildItemTooltipStats also refs INGREDIENTS strings
```

Partition system **skills-abilities** matches craft/recipe presentation; parent dual `0x0051f940` explains class-line depth only.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00846820-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00846820` | Port as **client craft requirements presentation**. Native: **ESI = UIText***, **stack item***, plain ret, line count. Do **not** treat as server gate. Do **not** merge with item `UI_AppendItemRequirements` (different field map). Keep distinct from rejected Combat-only alias. |
| Pair with | dualed `00845360` (item Requires); dualed `0051f940` (class names); dualed stat getters. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry when the merge agent runs.
- Record first dual seal for `aa_00846820` as `UI_AppendCraftRequirements_Inferred` / **accept-with-gaps**.

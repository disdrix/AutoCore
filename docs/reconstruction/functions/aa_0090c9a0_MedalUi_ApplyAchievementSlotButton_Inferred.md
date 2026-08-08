# Function record: MedalUi_ApplyAchievementSlotButton_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c9a0` |
| **Canonical name** | `MedalUi_ApplyAchievementSlotButton_Inferred` |
| **Ghidra name** | `FUN_0090c9a0` |
| **Address** | `0x0090c9a0`–`0x0090cbbb` inclusive (**540 B** / `0x21C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / Medal UI |
| **Partition** | MEGA-095 OWN-ONLY dual (parent context `0x0090cbc0`) |
| **Completion status** | **Dual sealed** 2026-08-05 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open — Terminal **false** |

## Naming

| Name | Status |
|---|---|
| `MedalUi_ApplyAchievementSlotButton_Inferred` | **Active** dual seal |
| `FUN_0090c9a0` | Ghidra machine name |
| `UI_a_btn_achievement` | Plate alias (XML stem) |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c9a0` | **Retired** |

`_Inferred`: product English for host panel / widget class unproven; behavioral role sealed.

## Purpose

Medal UI **apply/toggle** for one grid slot:

1. Construct achievement button widget (`operator_new(0x488)` + `FUN_007b5dd0`).
2. Install into host slot pointer table `@+0x540[slot]`.
3. Load `i_d_a_2d_btn_achievement.xml`.
4. Place in **3×N** grid from `slotIndex` (`/3`, `%3`) with scale constants.
5. Bind medal texture: C-string at `medalDef+0x10` + `".dds"`.
6. Stamp control id `slotIndex + 0x9c43`.
7. If `earnedFlag==0`, apply unowned dim/lock visual (`vtbl+0x164(2)` → `+0x154(0,mode)`).

## Signature (sealed)

```c
// Retail register+stack form:
//   ESI = UiHost* host
//   EBX = int slotIndex
//   [ESP+4] = MedalDef* medalDef
//   [ESP+8] = uint32_t earnedFlag
//   RET 8
void MedalUi_ApplyAchievementSlotButton_Inferred(
    MedalDef* medalDef,
    uint32_t earnedFlag);
```

## Call graph

```text
FUN_0090cbc0  (Medal UI panel fill — partition parent)
  ├─ MedalDef_LookupById (FUN_0051a0e0)
  └─ FUN_0090c9a0 / MedalUi_ApplyAchievementSlotButton_Inferred  [OWN MEGA-095]
        ├─ operator_new(0x488)
        ├─ FUN_007b5dd0          // widget ctor
        └─ host/widget vfuncs    // attach, load XML, size, pos, tex, id, dim
```

| Site | Flag | Path |
|---|---|---|
| `0x0090ccea` | 1 | Owned medal vector `@char+0x574..578` |
| `0x0090cdb4` | 0 | Hash-traverse remainder `@char+0x540` |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ MEGA-095 re-verify) | `docs/reconstruction/raw/aa_0090c9a0_FUN_0090c9a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c9a0_FUN_0090c9a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUi_ApplyAchievementSlotButton_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090c9a0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0090c9a0_FUN_0090c9a0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090c9a0-mega-095-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Body range / RET 8 / ESI+EBX ABI | **High** |
| CF: new→ctor→XML→grid→dds→id→dim | **High** |
| Sole caller `FUN_0090cbc0` (2 sites) | **High** |
| Medal/achievement UI role | **High** (string + MedalDef parent) |
| Product class English | **Open** |
| Vtable method English | **Open** |
| Runtime / bit-exact | **Open** |

## Dual verdict

**accept-with-gaps** (A + B). Terminal **false**.

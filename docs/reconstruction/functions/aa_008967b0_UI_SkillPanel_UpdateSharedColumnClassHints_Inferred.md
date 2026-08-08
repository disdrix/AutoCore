# Function record: UI_SkillPanel_UpdateSharedColumnClassHints_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008967b0` |
| **Canonical name** | `UI_SkillPanel_UpdateSharedColumnClassHints_Inferred` |
| **Ghidra name** | `FUN_008967b0` |
| **Address** | `0x008967b0`–`0x00896986` inclusive (**471 B** / `0x1D7`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Dual** | R11-034 OWN-ONLY 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Parent** | `0x0051f940` `LookupClassDisplayName_Inferred` |

## Purpose

Refresh the two **shared skill-column** UI widgets on a skill panel with a localized class-share hint derived from the local character's class/race and a hard-coded 12-pair share table.

## Signature

```c
// __usercall-style EDI-this: EDI = panel*
// no stack args; plain RET; frame 0x164
void UI_SkillPanel_UpdateSharedColumnClassHints_Inferred(void);
```

## Key offsets (panel)

| Offset | Role |
|---:|---|
| `+0x51c` | mode gate (must be `1`) |
| `+0x744` | shared-column widget A* |
| `+0x748` | shared-column widget B* |

## Key offsets (character blob)

| Offset | Role |
|---:|---|
| `+0x531` | classId (uint8) |
| `+0x532` | raceId (uint8) |

## Share table

Index `i = classId + raceId*4`. Pair `{A,B}` at `table[i*2]`, `table[i*2+1]`.  
Even i (0..8): `(1,3)`; odd i (1..9): `(0,2)`; i=10: `(3,1)`; i=11: `(2,0)`.

## Product string result

```text
This column of skills is shared by the <LookupClassDisplayName(shared, race)> class.
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008967b0_FUN_008967b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008967b0_FUN_008967b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008967b0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` |
| Ghidra record | `docs/reconstruction/functions/aa_008967b0_FUN_008967b0.md` |
| Report | `docs/agents/task-dual-ab-008967b0-r11-report.md` |

## Gaps

- Product/PDB method name
- `vtbl+0x308` English
- `+0x51c` mode English
- Caller host function recovery
- Runtime / bit-exact / differential

## Port note

Port as **UI label refresh**, not as class-name lookup (that is `0051f940`). Managed code: given local class/race, map through the sealed pair table, format the product sentence, assign to two column widgets when mode==1.

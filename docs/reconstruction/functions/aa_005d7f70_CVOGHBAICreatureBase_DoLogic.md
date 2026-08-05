# Function record: CVOGHBAICreatureBase_DoLogic

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7f70` |
| **Canonical name** | `CVOGHBAICreatureBase_DoLogic` |
| **Ghidra name** | `FUN_005d7f70` |
| **Address** | `0x005d7f70` |
| **Body range** | `0x005d7f70`–`0x005d8328` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / HBAI / creature |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; ABI + class + CF sealed; method English Probable; profile fields open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md`, `reviews/B_aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| **Last reviewed** | `2026-07-29` (W25-J) |

## Alias

- `FUN_005d7f70` (Ghidra)

## Purpose

Main **ground-creature** HBAI combat tick: profile lower_bound, then state machine on **owner+0x26c** (idle/engage/combat) with skill sets 0/1/2, slot timer, leash helpers, HP/RNG gates, and `DoCreaturePursue`. Twin of `CVOGHBAIDriver_DoLogic` without FireWeapons.

## Signature

```c
// Machine: __thiscall, ECX=this, bare ret; void
// Ghidra: void __fastcall FUN_005d7f70(int *param_1)
void __thiscall CVOGHBAICreatureBase_DoLogic(void *this);
```

## Object / vtbl

| Item | Value | Conf |
|---|---|---|
| Class | `CVOGHBAICreatureBase` | **High** (vtbl sibling DecideHeading string) |
| Vtbl slot | `0x009db19c` → this | **High** |
| Sibling slot | `0x009db194` = DecideHeading `0x005d0840` | **High** |
| Owner pointer | `this+0x64` (`this[0x19]`) | **High** |
| Combat state | `owner+0x26c` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d7f70_FUN_005d7f70.md`
- Annotated: `docs/reconstruction/raw/aa_005d7f70_FUN_005d7f70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoLogic.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005d7f70.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0051aed0-005d7f70-w25j-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | Virtual only (DATA `0x009db19c`) |
| **Callees** | profile map helpers; `NPC_TryCastSkillFromSet`; `AI_CheckSlotTimerReady`; `CVOGReaction_RandomUnitScalar`; path helpers `FUN_005cedf0/005cc980/005cebd0/005cc450/005ccbd0`; `FUN_005cf560` DoCreaturePursue; `FUN_00638cd0`; vtbl `+0x1C/+0x2C/+0x4C` |

## Confidence

| Claim | Level |
|---|---|
| thiscall void + state machine | **High** |
| Class CVOGHBAICreatureBase | **High** |
| Method English DoLogic | **Probable** |
| Profile field English | **Partial / Open** |
| Runtime / bit-exact | Open |

## Related

- `aa_005d7750` CVOGHBAIDriver_DoLogic (vehicle twin)
- `aa_005d1280` NPC_TryCastSkillFromSet
- `aa_005cced0` AI_CheckSlotTimerReady
- `aa_005cf560` CVOGHBAICreatureBase_DoCreaturePursue
- `aa_005d0840` CVOGHBAICreatureBase_DecideHeading

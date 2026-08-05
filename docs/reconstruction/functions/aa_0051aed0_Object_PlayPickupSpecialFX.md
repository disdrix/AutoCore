# Function record: Object_PlayPickupSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aed0` |
| **Canonical name** | `Object_PlayPickupSpecialFX` |
| **Ghidra name** | `FUN_0051aed0` |
| **Address** | `0x0051aed0` |
| **Body range** | `0x0051aed0`–`0x0051b1b9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / special-fx / item-pickup |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; ABI + script map sealed; product method English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0051aed0_Object_PlayPickupSpecialFX.md`, `reviews/B_aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| **Last reviewed** | `2026-07-29` (W25-J) |

## Alias

- `FUN_0051aed0` (Ghidra)
- Prior parent-seed: `Named_CalleeOf_…_CVOGCreature_Setup_0051aed0`

## Purpose

Load/attach client **pickup SpecialFX** scripts from clone-base item type + rarity; optional mission-audio host play; optional paint material recolor when def type-tag `+0x3F4==8`.

## Signature

```c
// Machine: __thiscall, ECX=this, ret 8; void
// Ghidra: void __thiscall FUN_0051aed0(int *param_1, char param_2, char param_3)
void __thiscall Object_PlayPickupSpecialFX(void *this, char bPlayAudio, char bForceQuestFx);
```

## Key constants

| Item | Value | Conf |
|---|---|---|
| `DAT_00aaa7a8` | ≈1/255 (`81 80 80 3b`) | **High** |
| Load flags | `NDSpecialFX_LoadFromScriptName(name, 4, 0)` | **High** |
| Type field | `clone+0x38` | **High** |
| Rarity short | `def+0x4B8` | **High** |
| Type-tag short | `def+0x3F4` | **High** (branch labels) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.md`
- Annotated: `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_PlayPickupSpecialFX.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051aed0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0051aed0-005d7f70-w25j-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `CLoadNode__initSelection` @ `0x005c69aa` `(1,0)`; `FUN_00585e00` @ `0x00585fe1` |
| **Callees** | `NDSpecialFX_LoadFromScriptName`, `FUN_004b8dc0`, vtbl `+0xF8/+0x60/+0x1CC`, `Client_GetMissionCompleteAudioTable`, `FUN_004b7e50`, `FUN_00519d20`, `FUN_009700f0`, `FUN_0096f660` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 8 + void | **High** |
| Script name / type / rarity map | **High** |
| Domain name Object_PlayPickupSpecialFX | **High** |
| Product C++ spelling | **Open** |
| Runtime / bit-exact | Open |

## Related

- `aa_004a61b0` NDSpecialFX_LoadFromScriptName
- `aa_004b8dc0` host activate cascade
- `aa_00519d20` VehiclePaintColor_LookupById_Inferred
- `aa_005c6960` CLoadNode__initSelection

# Function record: Character_Craft_HasMatchingStationInRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052eb90` |
| **Canonical name** | `Character_Craft_HasMatchingStationInRange_Inferred` |
| **Ghidra name** | `FUN_0052eb90` |
| **Address** | `0x0052eb90`–`0x0052ed73` exclusive (**483 B** / `0x1E3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer — craft / reverse-engineer station proximity gate |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/callers/constants sealed; product demangle + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md`, `reviews/B_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` (2026-08-05 R12-021) |
| **Last reviewed** | `2026-08-05` |
| **Runtime Confirmed** | **Never claimed** |

## Alias

- `FUN_0052eb90` (Ghidra / scaffold)
- `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_0052eb90` (**retired**)

## Purpose

**Bool gate** on the local character: for a selected craft object, evaluate whether a DisciplineDef-required station subtype is present within **50.0** surface-to-surface distance. Result is stored at craft host **`+0x7e2`** and used to enable craft success UI / tooltip coloring.

## Signature

```c
// Machine: __thiscall, ECX=character*, stack object*, AL bool, RET 4
uint8_t __thiscall Character_Craft_HasMatchingStationInRange_Inferred(
    void *character, void *craftObject);
```

## Algorithm

```
if charObj@MI+0xa8 == 0 or craftObject == 0: return false
if character+0x6b4 > 0: return true                  // free / RE-open bypass
if !DisciplineDefMap_TryCopyPayloadById(def+0x4ac, buf0x1FC): return true
flags = buf[+0x1F0], [+0x1F4], [+0x1F8]             // subtypes 0xD/0xE/0xF
for each TFID in charObj+0xe7f8 vector:
  obj = ResolveObjectTarget(charObj+0xe4e8, tfid)
  if obj has pose (vtbl+0x1c8) and SurfaceDistance3D <= 50.0:
    subtype = obj.def+0x3f4
    if subtype matches a non-zero flag: return true
return false
```

## Offsets / constants

| Item | Role | Conf |
|---|---|---|
| `character+0x6b4` | free/open bypass when `> 0` | **High** (role); English open |
| MI `+0xa8` | character object with lists | **High** |
| object `+0xe7f8` | TFID vector | **High** |
| object `+0xe4e8` | resolve context | **High** |
| craftObject `def+0x4ac` | DisciplineDef id key | **High** |
| nearby `def+0x3f4` | station subtype short | **High** |
| payload `+0x1F0/+0x1F4/+0x1F8` | flags for 0xD/0xE/0xF | **High** |
| `DAT_00a0f524` | **50.0f** range | **High** |
| craft host `+0x7e2` | consumer gate byte | **High** |
| craft host `+0x7cc` | selected object arg | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052eb90_FUN_0052eb90.md`
- Annotated: `docs/reconstruction/raw/aa_0052eb90_FUN_0052eb90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_Craft_HasMatchingStationInRange_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0052eb90.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0052eb90_FUN_0052eb90.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0052eb90-r12-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x008e6b50` | `UI_CraftHost_CreateChildWidgets_Inferred` → `+0x7e2` |
| Caller | `0x008e55e0` | craft host refresh enable flag |
| Caller | `0x008e63cc` | craft host tick → `+0x7e2` |
| Caller | `0x00847ad0` | `UI_BuildItemTooltipStats` greyscale |
| Callee | `0x0052b040` | `DisciplineDefMap_TryCopyPayloadById_Inferred` |
| Callee | `0x004e5810` | TFID vector materialize |
| Callee | `0x004bae70` | `CVOGReaction_ResolveObjectTarget` |
| Callee | `0x0053e510` | `Object_SurfaceDistance3D_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + thiscall RET 4 | **High** |
| 50.0f distance + subtype flag match | **High** |
| Craft UI gate consumer | **High** |
| Product method / subtype English | **Open** |
| Runtime / bit-exact | Open |

## Related

- Parent: `aa_008e6b50` UI_CraftHost_CreateChildWidgets_Inferred
- Discipline map: `aa_0052b040` DisciplineDefMap_TryCopyPayloadById_Inferred
- Distance: `aa_0053e510` Object_SurfaceDistance3D_Inferred
- RE free flag family: `character+0x6b4` (also RE required-level zero path)

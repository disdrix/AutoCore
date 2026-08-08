# Function record: UI_AppendCraftRequirements_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00846820` |
| **Canonical Ghidra name** | `FUN_00846820` |
| **Role name** | `UI_AppendCraftRequirements_Inferred` |
| **Address** | `0x00846820` |
| **Body** | `00846820`–`00847232` (**4115 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | skills-abilities |
| **Dual** | R11-028 **accept-with-gaps** (A+B) |
| **Terminal** | false |

## Naming

| Name | Status |
|---|---|
| `UI_AppendCraftRequirements_Inferred` | **Accepted role name** (product multi-section craft requirements UI) |
| `FUN_00846820` | Ghidra twin (keep) |
| `Named_Required_Combat_00846820` | **Rejected** |

## Contract

```text
int UI_AppendCraftRequirements_Inferred(ItemOrCraft *item /*stack*/, UIText *text /*ESI*/);
// returns line count; 0 if no local player
// sections: INGREDIENTS, ENHANCEMENT INGREDIENTS, Discipline,
//           Required Faction/Class/Combat/Perception/Tech/Theory/Level
```

## Related dualed units

| VA | Role |
|---|---|
| `0x00845360` | `UI_AppendItemRequirements` (item Requires; no ingredients) |
| `0x0051f940` | `LookupClassDisplayName_Inferred` (class line) |
| `0x004c4070` / `4140` / `41c0` / `3ff0` | Combat / Theory / Perception / Tech getters |

## Artifacts

Same set as `aa_00846820_FUN_00846820.md` (raw / annotated / clean / A+B / report).

## Port note (AutoCore)

Client presentation only. Server craft validation must not depend on this formatter. Compare data fields (ingredient ids, def req shorts, level sum cap 80) with authoritative tables; reuse dualed stat getters only for parity tests.

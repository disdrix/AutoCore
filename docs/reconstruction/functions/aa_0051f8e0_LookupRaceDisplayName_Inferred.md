# Function record: LookupRaceDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f8e0` |
| **Canonical Ghidra name** | `FUN_0051f8e0` |
| **Role name** | `LookupRaceDisplayName_Inferred` |
| **Address** | `0x0051f8e0` |
| **Body** | `0051f8e0`–`0051f90b` exclusive (**43 B** / `0x2B`) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | skills-abilities |
| **Dual** | R12-017 **accept-with-gaps** (A+B) |
| **Terminal** | false |

## Naming

| Name | Status |
|---|---|
| `LookupRaceDisplayName_Inferred` | **Accepted role name** |
| `FUN_0051f8e0` | Ghidra twin (keep) |
| `Named_CalleeOf_Named_Combat_0051f8e0` | **Rejected** |

## Contract

```text
const char * LookupRaceDisplayName_Inferred(int raceId);
// cdecl; plain RET; static rodata return
// 0=Human, 1=Mutant, 2=Biomek, else=Unknown
```

## Related dualed units

| VA | Role |
|---|---|
| `0x0051f940` | `LookupClassDisplayName_Inferred` |
| `0x00521800` | `Character_GetRaceDisplayName_Inferred` |
| `0x00846820` | `UI_AppendCraftRequirements_Inferred` (partition parent) |
| `0x00845360` | `UI_AppendItemRequirements` |

## Artifacts

Same set as `aa_0051f8e0_FUN_0051f8e0.md` (raw / annotated / clean / A+B / report).

## Port note (AutoCore)

Client presentation only. Server craft/item race validation must not depend on this formatter. Compare race ids with authoritative tables; reuse dualed character race getter only for parity tests of the English map.

# Function record: LookupRaceShortCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f910` |
| **Canonical Ghidra name** | `FUN_0051f910` |
| **Role name** | `LookupRaceShortCode_Inferred` |
| **Address** | `0x0051f910` |
| **Body** | `0051f910`–`0051f93b` exclusive (**43 B** / `0x2B`) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | skills-abilities |
| **Dual** | R13-032 **accept-with-gaps** (A+B) |
| **Terminal** | false |
| **Partition parent** | `0x0051f8e0` `LookupRaceDisplayName_Inferred` |

## Naming

| Name | Status |
|---|---|
| `LookupRaceShortCode_Inferred` | **Accepted role name** |
| `FUN_0051f910` | Ghidra twin (keep) |
| `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0051f910` | **Rejected** |

## Contract

```text
const char * LookupRaceShortCode_Inferred(int raceId);
// cdecl; plain RET; static rodata return
// 0=HUM, 1=MUT, 2=BIO, else=Unknown
```

## Related dualed units

| VA | Role |
|---|---|
| `0x0051f8e0` | `LookupRaceDisplayName_Inferred` (English twin; partition parent) |
| `0x0051f940` | `LookupClassDisplayName_Inferred` |
| `0x0051f550` | `BuildRaceClassSuffix_Inferred` (`_h/_m/_b` path tokens) |
| `0x00521800` | `Character_GetRaceDisplayName_Inferred` |
| `0x0051fa10` | class short codes (residual; caller peer) |
| `0x00871150` | sole caller UI formatter (residual) |

## Artifacts

Same set as `aa_0051f910_FUN_0051f910.md` (raw / annotated / clean / A+B / report).

## Port note (AutoCore)

Client presentation only. Port as pure **`raceId → const char*`** short table. Do not free return. Do not merge with English twin, class short peer, or path-suffix builder. Server race validation must not depend on this formatter.

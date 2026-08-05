# Function record: StringTable_FindOrIntern_u16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a1770` |
| **Canonical name** | `StringTable_FindOrIntern_u16_Inferred` |
| **Ghidra name** | `FUN_004a1770` |
| **Address** | `0x004a1770`–`0x004a18a8` exclusive (**312 B** / `0x138`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | global string intern table |
| **Wave** | W34-I OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md`, `reviews/B_aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` |

## Purpose

Find-or-intern a C-string into the global `vector<basic_string>` at `0x00b03608`, returning a compact `u16` index. Empty-table path seeds index 0 as `"Empty"`. Observed consumers: environment `cloudName` / `skyName` fields via `FUN_004a18b0`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `StringVec_PushBack` | `0x004301f0` | intern push (W33-D) |
| `FUN_004a18b0` | `0x004a18b0` | sole caller (env parse; unowned) |

## Signature

```c
unsigned StringTable_FindOrIntern_u16_Inferred(const char* name /*cdecl*/);
```

## Artifacts

See `aa_004a1770_FUN_004a1770.md` for full paths and confidence table.

# Function record: Fs_ReadPathListFileToStringVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009841d0` |
| **Canonical name** | `Fs_ReadPathListFileToStringVec_Inferred` |
| **Ghidra name** | `FUN_009841d0` |
| **Address** | `0x009841d0`–`0x00984335` exclusive (**357 B** / `0x165`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / path-list text reader |
| **Wave** | W34-I OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md`, `reviews/B_aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` |

## Purpose

Read a newline-delimited path list file into a `vector<basic_string>` out parameter via stack `stoFileOSFile`. Open-fail yields empty out. Sole static use is the `@list` arm of `Fs_ExpandPathSpecToStringVec_Inferred`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `Fs_ExpandPathSpecToStringVec_Inferred` | `0x00984340` | sole caller (W33-E) |
| `StringVec_PushBack` | `0x004301f0` | push each line (W33-D) |
| `StringVec_Tidy` | `0x00431ae0` | collector cleanup (W33-D) |
| `FUN_007669d0` / `FUN_00766ee0` | stoFile cluster | open / readline (unowned) |

## Signature

```c
void* Fs_ReadPathListFileToStringVec_Inferred(void* out_string_vec,
                                              const char* path /*cdecl*/);
```

## Artifacts

See `aa_009841d0_FUN_009841d0.md` for full paths and confidence table.

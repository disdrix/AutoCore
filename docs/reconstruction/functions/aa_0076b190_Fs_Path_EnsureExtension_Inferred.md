# Function record: Fs_Path_EnsureExtension_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b190` |
| **Canonical name** | `Fs_Path_EnsureExtension_Inferred` |
| **Ghidra name** | `FUN_0076b190` |
| **Address** | `0x0076b190`–`0x0076b208` exclusive (**120 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | fs / path helpers |
| **Wave** | W33-P |
| **Completion status** | **Dual-sealed** accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Ensure a path has an extension: split → if ext empty copy ESI → makepath to out. Used by AssPackManager CompactPackFile with ESI=`"glm"`.

## Signature

```c
void Fs_Path_EnsureExtension_Inferred(
    const char* path, char* out /* ESI=defaultExt */);
```

## Artifacts

See `aa_0076b190_FUN_0076b190.md` for full artifact table.

## Naming

**Inferred** from split/ensure/make CF + `"glm"` call sites. No PDB plate.

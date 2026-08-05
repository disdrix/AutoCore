# Function record: AssPackManager_AddOrReplaceFileInPack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984910` |
| **Canonical name** | `AssPackManager_AddOrReplaceFileInPack_Inferred` |
| **Ghidra name** | `FUN_00984910` |
| **Address** | `0x00984910`–`0x00984c65` (**854 B** / `0x356`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir assets / assPackManager |
| **Wave** | W33-Q OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Classification** | worker |

## Purpose

Add a filesystem file into an open pack (or skip if unchanged when not forced): optional CS, lookup existing, compare mtime/size/type, replace-prep, open-read, compress/meta, insert node; plate logs Not replacing / Unable to open / Added file.

## Signature (sealed)

```c
// ECX = const char* srcPath
// stack0 = AssPackHost* host
// stack1 = int typeId
// stack2 = char forceReplace
// stack3 = uint32_t arg4
// stack4 = uint32_t replaceCookie → FUN_009847c0
// RET 0x14; int 1 skip / >=0 add / -1 fail
int AssPackManager_AddOrReplaceFileInPack_Inferred(
    const char* srcPath /*ECX*/,
    AssPackHost* host /*stack0*/,
    int typeId /*stack1*/,
    char forceReplace /*stack2*/,
    uint32_t arg4 /*stack3*/,
    uint32_t replaceCookie /*stack4*/);
```

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssPackManager_ExtractPackEntryToFile_Inferred` | `0x00984d30` | compact extract pair (this wave) |
| `AssPackManager_CompactPackFile_Inferred` | `0x00985010` | caller (W32-E) |
| `FUN_00984c70` | `0x00984c70` | dir bulk-add caller (W33-E OWN) |
| `Fs_DirRecurseCollectLeafPaths_Inferred` | `0x009839b0` | feeds `00984c70` (W32-D) |
| Replace prep `FUN_009847c0` | nested | not OWN |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00984910_FUN_00984910.md`
- Annotated: `docs/reconstruction/raw/aa_00984910_FUN_00984910.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPackManager_AddOrReplaceFileInPack_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00984910.cpp`
- Legacy: `docs/reconstruction/reconstructed-exact/Named_assPackManager_00984910.cpp`
- Function FUN: `docs/reconstruction/functions/aa_00984910_FUN_00984910.md`
- A: `docs/reconstruction/reviews/A_aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow skip / replace / add | **High** |
| ABI ECX path + 5 stack + RET 0x14 | **High** |
| CS +0x38 / gate +0x50 | **High** |
| typeId @ entry+0x14 / size+0x08 | **High** |
| Compress/insert nested product | **Med** |
| arg4 product meaning | **Low/Open** |
| Runtime / bit-exact | **Open** |

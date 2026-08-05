# Function record: AssPackManager_ExtractPackEntryToFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984d30` |
| **Canonical name** | `AssPackManager_ExtractPackEntryToFile_Inferred` |
| **Ghidra name** | `FUN_00984d30` |
| **Address** | `0x00984d30`–`0x00984ed4` (**421 B** / `0x1A5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir assets / assPackManager |
| **Wave** | W33-Q OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Classification** | worker |

## Purpose

Extract one named pack entry’s payload to a filesystem path under optional host critical section: lookup entry, stream-read packed bytes, open-write destination (mode 6), log not-found from `assPackManager.cpp`.

## Signature (sealed)

```c
// ECX = const char* outPath (nullable)
// stack0 = AssPackHost* host
// stack1 = const char* entryName
// stack2 = spill (caller pushes empty; fail reuses slot as fmt buf)
// RET 0x0C; int 0 / -1
int AssPackManager_ExtractPackEntryToFile_Inferred(
    const char* outPath /*ECX*/,
    AssPackHost* host /*stack0*/,
    const char* entryName /*stack1*/,
    uint32_t spill /*stack2*/);
```

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssPackManager_CompactPackFile_Inferred` | `0x00985010` | sole caller (W32-E) |
| `AssPackManager_AddOrReplaceFileInPack_Inferred` | `0x00984910` | compact pair (this wave) |
| `AssPackManager_OpenPackFile_Inferred` | `0x00984ee0` | sibling open (W31-H) |
| Lookup `FUN_009835f0` / stream `FUN_00983d40` | nested | not OWN |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00984d30_FUN_00984d30.md`
- Annotated: `docs/reconstruction/raw/aa_00984d30_FUN_00984d30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPackManager_ExtractPackEntryToFile_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00984d30.cpp`
- Legacy: `docs/reconstruction/reconstructed-exact/Named_assPackManager_00984d30.cpp`
- Function FUN: `docs/reconstruction/functions/aa_00984d30_FUN_00984d30.md`
- A: `docs/reconstruction/reviews/A_aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| ABI ECX/outPath + host stack + RET 0x0C | **High** |
| CS +0x38 / gate +0x50 | **High** |
| Path fallback entry+0x10 / empty | **High** |
| Nested stream/read product English | **Med** |
| stack[2] product role | **Low/Open** |
| Runtime / bit-exact | **Open** |

# Function record: Character_FormatLevelRaceClassLine_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092e710` |
| **Canonical name** | `Character_FormatLevelRaceClassLine_Inferred` |
| **Ghidra name** | `FUN_0092e710` |
| **Address** | `0x0092e710` |
| **Body** | `0x0092e710`–`0x0092e8a7` inclusive (**408 B** / `0x198`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / character display UI |
| **Dual** | A/B **accept-with-gaps** (R10-016, 2026-08-05) |
| **Parent dual (partition)** | `0x00521800` `Character_GetRaceDisplayName_Inferred` |
| **Terminal** | false |

## Purpose

Build the character-sheet header line:

```text
Level <level> <RaceDisplayName> <ClassDisplayName>
```

into a caller-owned buffer and return its length.

## Signature (port-facing)

```c
// Retail: character* on stack (cdecl); outBuf in EBX; returns strlen.
int Character_FormatLevelRaceClassLine_Inferred(void* character, char* outBuf);
```

## Implementation notes

1. Null-check both `character` and `outBuf` → return 0.
2. Ring-copy `"Level "` (`0x00a2d280`) and append.
3. Call nested vtbl `+0x27c` for level int; `_itoa(..., 10)`; append digits.
4. Append `DAT_00a2a000` space; race via `Character_GetRaceDisplayName_Inferred` (ECX-this); ring re-buffer; append.
5. Append space; class via `Character_GetClassDisplayName_Inferred`; ring re-buffer; append.
6. Return `strlen(outBuf)`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0092e710_FUN_0092e710.md` |
| Annotated | `docs/reconstruction/raw/aa_0092e710_FUN_0092e710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_FormatLevelRaceClassLine_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092e710.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0092e710_FUN_0092e710.md` |
| Report | `docs/agents/task-dual-ab-0092e710-r10-report.md` |

## Retired names

- `Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_0092e710`

# Function record: AssManager_InitPrecompileAndResolvers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b75b0` |
| **Canonical name** | `AssManager_InitPrecompileAndResolvers_Inferred` |
| **Ghidra name** | `FUN_007b75b0` |
| **Address** | `0x007b75b0`–`0x007b7b6d` (**~1469 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assManager / NDAssetManager |
| **Wave** | W30-D OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |

## Purpose

Ensure precompile effect directory, publish path on assManager host, optionally construct/register resolvers A/B into `host+0x58`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `GuardedVector_PushBackLocked` | `0x0043c4f0` | resolver A insert (this wave) |
| `GuardedVector_PushBack` | `0x0043c830` | resolver B insert body (W29-B) |
| `AssManager_RemoveResolver_Inferred` | `0x00423e00` | remove from same +0x58 list (W29-C) |
| `AssManager_ReleaseOwnedResolvers_Inferred` | `0x007b65d0` | teardown of self+0x08/+0x0c (W29-D) |

## Artifacts

See `aa_007b75b0_FUN_007b75b0.md` for full paths and confidence table.

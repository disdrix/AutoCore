# Function record: AssManager_ResolverA_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423be0` |
| **Canonical name** | `AssManager_ResolverA_Ctor_Inferred` |
| **Ghidra name** | `FUN_00423be0` |
| **Address** | `0x00423be0`–`0x00423c35` (**86 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assManager / resolver A |
| **Wave** | W31-G OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md`, `reviews/B_aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` |

## Purpose

Placement constructor for AssManager **resolver A** (0x4c object, vtbl `00a95acc`).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssManager_InitPrecompileAndResolvers_Inferred` | `0x007b75b0` | sole caller (W30-D) |
| `GuardedVector_PushBackLocked` | `0x0043c4f0` | register A on host+0x58 |
| `AssManager_ReleaseOwnedResolvers_Inferred` | `0x007b65d0` | teardown self+0x08 |
| `AssResolverCore_Ctor_Inferred` | `0x00983940` | sibling resolver-B core (this wave) |

## Signature

```c
AssResolverA* AssManager_ResolverA_Ctor_Inferred(AssResolverA* self /*stack; RET 4*/);
```

## Artifacts

See `aa_00423be0_FUN_00423be0.md` for full paths and confidence table.

# Function record: AssResolverCore_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00983940` |
| **Canonical name** | `AssResolverCore_Ctor_Inferred` |
| **Ghidra name** | `FUN_00983940` |
| **Address** | `0x00983940`–`0x009839af` (**112 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assManager resolver-B core + effect probe host |
| **Wave** | W31-G OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00983940_AssResolverCore_Ctor_Inferred.md`, `reviews/B_aa_00983940_AssResolverCore_Ctor_Inferred.md` |

## Purpose

Placement constructor for resolver-B core / effect-probe host (CS + ready + global clear). AssManager wraps with outer vtbl `PTR_FUN_00aa1f1c` at mem+0 and calls this on mem+8.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssManager_InitPrecompileAndResolvers_Inferred` | `0x007b75b0` | primary caller for resolver B (W30-D) |
| `AssManager_ResolverA_Ctor_Inferred` | `0x00423be0` | sibling resolver A ctor (this wave) |
| `AssManager_ReleaseOwnedResolvers_Inferred` | `0x007b65d0` | teardown self+0x0c |
| `FUN_00984ee0` | `0x00984ee0` | post-ctor probe batch (W31-H residual) |

## Signature

```c
AssResolverCore* AssResolverCore_Ctor_Inferred(AssResolverCore* self /*stack; RET 4*/);
```

## Artifacts

See `aa_00983940_FUN_00983940.md` for full paths and confidence table.

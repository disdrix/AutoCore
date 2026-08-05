# Function record: AssResolverA_NestedHash_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423cf0` |
| **Canonical name** | `AssResolverA_NestedHash_Ctor_Inferred` |
| **Ghidra name** | `FUN_00423cf0` |
| **Address** | `0x00423cf0`–`0x00423d51` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assManager / resolver A nested member |
| **Wave** | W32-D OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md`, `reviews/B_aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` |

## Purpose

Placement constructor for the nested hash/map member of AssManager **resolver A** (outer alloc `0x4c`, member at `+0x08`, span `0x28`).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssManager_ResolverA_Ctor_Inferred` | `0x00423be0` | sole caller (W31-G) |
| `AssManager_InitPrecompileAndResolvers_Inferred` | `0x007b75b0` | grandparent init |
| `FUN_00469db0` | `0x00469db0` | twin nested ctor (AssResolverCore / W32-E) |
| `AssResolverCore_Ctor_Inferred` | `0x00983940` | sibling outer that uses twin |

## Signature

```c
AssResolverA_NestedHash* AssResolverA_NestedHash_Ctor_Inferred(AssResolverA_NestedHash* self /*stack; RET 4*/);
```

## Artifacts

See `aa_00423cf0_FUN_00423cf0.md` for full paths and confidence table.

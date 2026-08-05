# Function record: NestedHashBag_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a0d0` |
| **Canonical name** | `NestedHashBag_Ctor_Inferred` |
| **Ghidra name** | `FUN_0044a0d0` |
| **Address** | `0x0044a0d0`–`0x0044a131` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / nested hash-bag (Ass-style twin) |
| **Wave** | W34-D OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0044a0d0_NestedHashBag_Ctor_Inferred.md`, `reviews/B_aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` |

## Purpose

Placement constructor for nested hash/map bag member: circular sentinel, 9-bucket pointer table filled with that sentinel, size 0, flags 1/1. Same CF as AssResolver nested bag twins; sole parent `FUN_0074d750` nests at outer `+0x0c`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssResolverA_NestedHash_Ctor_Inferred` | `0x00423cf0` | twin CF (W32-D) |
| `AssResolverCore_HeadBag_Ctor_Inferred` | `0x00469db0` | twin CF (W32-E) |
| `CircularSentinel_Alloc0x28_Inferred` | `0x00423d60` | callee (W33-B) |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | callee (W33-B) |
| `Mem_FillDwordN_FromSrc_EaxEcxEdx` | `0x00436ef0` | nested fill (this dual) |
| `FUN_0074d750` | `0x0074d750` | sole caller (unowned) |

## Signature

```c
NestedHashBag* NestedHashBag_Ctor_Inferred(NestedHashBag* self /*stack; RET 4*/);
```

## Artifacts

See `aa_0044a0d0_FUN_0044a0d0.md` for full paths and confidence table.

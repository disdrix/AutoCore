# Function record: NestedHash_Ctor_Sentinel0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00463bd0` |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x30_Inferred` |
| **Ghidra name** | `FUN_00463bd0` |
| **Address** | `0x00463bd0`–`0x00463c31` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared nested hash/map shell |
| **Wave** | W34-F OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md`, `reviews/B_aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` |

## Purpose

Placement constructor for a nested hash/map shell (span **0x28**): sentinel node **0x30**, empty list size, 9-bucket pointer table filled with sentinel, structural flags = 1.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssResolverA_NestedHash_Ctor_Inferred` | `0x00423cf0` | family twin (sentinel 0x28; W32-D) |
| `FUN_00469db0` | `0x00469db0` | family twin (sentinel 0x28; AssResolverCore nested) |
| `NestedHash_Ctor_Sentinel0xC_Inferred` | `0x0043fdf0` | sibling this dual (sentinel 0x0C) |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | bucket table init (W33-B) |
| `FUN_005b43b0` | `0x005b43b0` | 0x30 circular sentinel factory (unowned) |
| `FUN_0075f7f0` | `0x0075f7f0` | sole caller host |

## Signature

```c
NestedHash_Sentinel0x30* NestedHash_Ctor_Sentinel0x30_Inferred(NestedHash_Sentinel0x30* self /*stack; RET 4*/);
```

## Artifacts

See `aa_00463bd0_FUN_00463bd0.md` for full paths and confidence table.

# Function record: NestedHash_Ctor_Sentinel0xC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fdf0` |
| **Canonical name** | `NestedHash_Ctor_Sentinel0xC_Inferred` |
| **Ghidra name** | `FUN_0043fdf0` |
| **Address** | `0x0043fdf0`–`0x0043fe51` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared nested hash/map shell |
| **Wave** | W34-F OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md`, `reviews/B_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md` |

## Purpose

Placement constructor for a nested hash/map shell (span **0x28**): sentinel node **0x0C**, empty list size, 9-bucket pointer table filled with sentinel, structural flags = 1.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssResolverA_NestedHash_Ctor_Inferred` | `0x00423cf0` | family twin (sentinel 0x28; W32-D) |
| `FUN_00469db0` | `0x00469db0` | family twin (sentinel 0x28; same SEH plate) |
| `NestedHash_Ctor_Sentinel0x30_Inferred` | `0x00463bd0` | sibling this dual (sentinel 0x30) |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | bucket table init (W33-B) |
| `StdList_AllocSentinel_0xC_Inferred` | `0x004933f0` | sentinel factory (W32-P) |
| `FUN_0074e380` / `FUN_0096eec0` / `FUN_00996bc0` | various | three hosts |

## Signature

```c
NestedHash_Sentinel0xC* NestedHash_Ctor_Sentinel0xC_Inferred(NestedHash_Sentinel0xC* self /*stack; RET 4*/);
```

## Artifacts

See `aa_0043fdf0_FUN_0043fdf0.md` for full paths and confidence table.

# Function record: NestedHash_Ctor_Sentinel0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bdf0` |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x14_Inferred` |
| **Ghidra name** | `FUN_0043bdf0` |
| **Address** | `0x0043bdf0`–`0x0043be51` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / nested hash bag (NDResourceCache head + embeds) |
| **Wave** | W34-E OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md`, `reviews/B_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` |

## Purpose

Placement constructor for NestedHash with **0x14** circular sentinel nodes and a **9-bucket** pointer table (fill = sentinel). Used as NDResourceCache head (`FUN_0075d470` / `DAT_00d1f050`) and as nested member in `FUN_0074d750`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `NestedHash_Ctor_Sentinel0x10_Inferred` | `0x00457ac0` | W34-E twin (node 0x10) |
| `AssResolverA_NestedHash_Ctor_Inferred` | `0x00423cf0` | same CF, node 0x28 (W32-D) |
| `AssResolverCore_HeadBag_Ctor_Inferred` | `0x00469db0` | same CF, node 0x28 (W32-E) |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | bucket init (W33-B) |
| `CircularSentinel_Alloc0x28_Inferred` | `0x00423d60` | larger node factory family |

## Signature

```c
NestedHash_Sentinel0x14* NestedHash_Ctor_Sentinel0x14_Inferred(NestedHash_Sentinel0x14* self /*stack; RET 4*/);
```

## Artifacts

See `aa_0043bdf0_FUN_0043bdf0.md` for full paths and confidence table.

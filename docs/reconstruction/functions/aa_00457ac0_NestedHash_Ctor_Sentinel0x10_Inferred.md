# Function record: NestedHash_Ctor_Sentinel0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457ac0` |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x10_Inferred` |
| **Ghidra name** | `FUN_00457ac0` |
| **Address** | `0x00457ac0`–`0x00457b21` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / nested hash bag (statics + gfx + heap hosts) |
| **Wave** | W34-E OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md`, `reviews/B_aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` |

## Purpose

Placement constructor for NestedHash with **0x10** circular sentinel nodes and a **9-bucket** pointer table. Multi-caller: once-flag statics, heap bag hosts, and stack-local use on gfxDeviceIB path.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `NestedHash_Ctor_Sentinel0x14_Inferred` | `0x0043bdf0` | W34-E twin (node 0x14) |
| `AssResolverA_NestedHash_Ctor_Inferred` | `0x00423cf0` | same CF, node 0x28 |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | bucket init (W33-B) |

## Signature

```c
NestedHash_Sentinel0x10* NestedHash_Ctor_Sentinel0x10_Inferred(NestedHash_Sentinel0x10* self /*stack; RET 4*/);
```

## Artifacts

See `aa_00457ac0_FUN_00457ac0.md` for full paths and confidence table.

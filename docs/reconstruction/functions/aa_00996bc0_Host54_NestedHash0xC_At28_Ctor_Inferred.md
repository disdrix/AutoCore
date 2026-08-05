# Function record: Host54_NestedHash0xC_At28_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996bc0` |
| **Canonical name** | `Host54_NestedHash0xC_At28_Ctor_Inferred` |
| **Ghidra name** | `FUN_00996bc0` |
| **Address** | `0x00996bc0`–`0x00996c1e` (**94 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash0xC host with prefix fields |
| **Wave** | W35-S OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md`, `reviews/B_aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` |

## Purpose

Placement constructor for a **0x54**-byte host embedding NestedHash0xC at **+0x28** after a zeroed prefix (default capacity **8**).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `NestedHash_Ctor_Sentinel0xC_Inferred` | `0x0043fdf0` | nested shell at +0x28 (W34-F) |
| `Host34_NestedHash0xC_Singleton_Ctor_Inferred` | `0x0096eec0` | sibling this dual (hash at +0, span 0x34) |
| `FUN_00989cf0` | `0x00989cf0` | sole outer host (CS at +0x68) |

## Signature

```c
Host54_NestedHash0xC_At28* Host54_NestedHash0xC_At28_Ctor_Inferred(Host54_NestedHash0xC_At28* self /*stack; RET 4*/);
```

## Artifacts

See `aa_00996bc0_FUN_00996bc0.md` for full paths and confidence table.

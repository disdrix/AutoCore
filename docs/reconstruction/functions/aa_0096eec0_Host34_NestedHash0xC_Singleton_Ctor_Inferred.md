# Function record: Host34_NestedHash0xC_Singleton_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096eec0` |
| **Canonical name** | `Host34_NestedHash0xC_Singleton_Ctor_Inferred` |
| **Ghidra name** | `FUN_0096eec0` |
| **Address** | `0x0096eec0`–`0x0096ef6a` (**170 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash0xC host + singleton + type-token once-init |
| **Wave** | W35-S OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md`, `reviews/B_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` |

## Purpose

Placement constructor for a **0x34**-byte NestedHash0xC host with global singleton publish and one-shot type-token / handler registration against the NDResourceCache map.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `NestedHash_Ctor_Sentinel0xC_Inferred` | `0x0043fdf0` | nested shell at +0 (W34-F) |
| `Host54_NestedHash0xC_At28_Ctor_Inferred` | `0x00996bc0` | sibling this dual (hash at +0x28, span 0x54) |
| `NestedHash_Ctor_Sentinel0x30_Inferred` | `0x00463bd0` | peer host path in same `FUN_0075f7f0` (`param_2[0x1d6]`) |
| `FUN_0043bd40` | `0x0043bd40` | unowned map find/insert |
| `DAT_00d1f050` | global | NDResourceCache* |

## Signature

```c
Host34_NestedHash0xC* Host34_NestedHash0xC_Singleton_Ctor_Inferred(Host34_NestedHash0xC* self /*stack; RET 4*/);
```

## Artifacts

See `aa_0096eec0_FUN_0096eec0.md` for full paths and confidence table.

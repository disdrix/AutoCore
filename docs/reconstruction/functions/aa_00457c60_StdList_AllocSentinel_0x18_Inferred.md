# Function record: StdList_AllocSentinel_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457c60` |
| **Canonical name** | `StdList_AllocSentinel_0x18_Inferred` |
| **Ghidra name** | `FUN_00457c60` |
| **Address** | `0x00457c60`–`0x00457c7a` exclusive (**26 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `std::list`-style sentinel factory |
| **Status** | Dual A/B sealed W30-E 2026-07-29 — **accept** |

## Purpose

Factory for a **0x18**-byte circular empty-list sentinel (`next=prev=self`). Used by complete ctors and list initializers that pair head + size dword.

## Signature

```c
void* StdList_AllocSentinel_0x18_Inferred(void);  // EAX = node*
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x0040fb90` StdList_AllocEmptySentinel_Inferred | Sibling factory, node **0x0C** |
| `0x00496f70` Class_009c7a1c_Ctor | Caller — list @ `+0x0C` |
| `0x00575440` Object_009d33c4_Ctor | Caller — list @ `+0x1DC` |
| `0x00497360` StdList_Destroy_FreeHead | Destroy twin family (size field elsewhere) |

## Artifacts

See `aa_00457c60_FUN_00457c60.md`.

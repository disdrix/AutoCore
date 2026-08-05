# Function record: StdList_AllocSentinel_0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b43b0` |
| **Canonical name** | `StdList_AllocSentinel_0x30_Inferred` |
| **Ghidra name** | `FUN_005b43b0` |
| **Address** | `0x005b43b0`–`0x005b43c9` inclusive (**26 B** / `0x1A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `std::list`-style sentinel factory |
| **Status** | Dual A/B sealed W35-G 2026-07-29 — **accept-with-gaps** |

## Purpose

Factory for a **0x30**-byte circular empty-list sentinel (`next=prev=self`). Non-SEH. Same 26-byte skeleton as 0xC and 0x18 factories. Callers pair head + size dword = 0. Differentiator for NestedHash_Sentinel0x30 hosts vs Ass NestedHash (sentinel **0x28**).

## Signature

```c
void* StdList_AllocSentinel_0x30_Inferred(void);  // EAX = node*
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x004933f0` StdList_AllocSentinel_0xC_Inferred | Sibling factory, node **0x0C** |
| `0x00457c60` StdList_AllocSentinel_0x18_Inferred | Sibling factory, node **0x18** |
| `0x0040fb90` StdList_AllocEmptySentinel_Inferred | SEH twin family, node **0x0C** |
| `0x00423d60` CircularSentinel_Alloc0x28_Inferred | Ass NestedHash sentinel **0x28** |
| `0x00463bd0` NestedHash_Ctor_Sentinel0x30_Inferred | Caller |
| `0x004438c0` NestedHashBag_Ctor_Sentinel0x30_Inferred | Caller |
| `0x005b3f60` Obj_DefaultCtor… | Caller — list @ +0x10 |

## Artifacts

See `aa_005b43b0_FUN_005b43b0.md`.

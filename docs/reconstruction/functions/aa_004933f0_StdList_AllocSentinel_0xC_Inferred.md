# Function record: StdList_AllocSentinel_0xC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004933f0` |
| **Canonical name** | `StdList_AllocSentinel_0xC_Inferred` |
| **Ghidra name** | `FUN_004933f0` |
| **Address** | `0x004933f0`–`0x00493409` inclusive (**26 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `std::list`-style sentinel factory |
| **Status** | Dual A/B sealed W32-P 2026-07-29 — **accept-with-gaps** |

## Purpose

Factory for a **0xC**-byte circular empty-list sentinel (`next=prev=self`). Non-SEH twin of `StdList_AllocEmptySentinel_Inferred` (`0x0040fb90`). Used widely by complete ctors that pair head + size dword.

## Signature

```c
void* StdList_AllocSentinel_0xC_Inferred(void);  // EAX = node*
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x0040fb90` StdList_AllocEmptySentinel_Inferred | Same 0xC self-link **with SEH** |
| `0x00457c60` StdList_AllocSentinel_0x18_Inferred | Sibling factory, node **0x18** |
| `0x00492dd0` PalantirEnv_Ctor_Inferred | Caller — two heads |
| `0x004ba310` NDSpecialFX_Ctor | Caller — six heads |

## Artifacts

See `aa_004933f0_FUN_004933f0.md`.

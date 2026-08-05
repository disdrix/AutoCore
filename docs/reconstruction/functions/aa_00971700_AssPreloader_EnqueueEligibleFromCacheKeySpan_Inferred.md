# Function record: AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971700` |
| **Canonical name** | `AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred` |
| **Ghidra name** | `FUN_00971700` |
| **Address** | `0x00971700`–`0x00971795` (**150 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Dual** | W33-M 2026-07-29 — A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Copy cache-context key span into a local ring and enqueue eligible keys into AssPreloader pending (no dependency expansion).

## Signature

```c
uint32_t AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred(void* host /*ECX*/);
// bare RET; returns 0
```

## Related sealed units

| VA | Name | Relation |
|---|---|---|
| `00971640` | `AssPreloader_EnqueueEligibleFromRing_Inferred` | Nested enqueue |
| `0044e1c0` | `GuardedVector_InsertRange` | Nested span insert (sole known caller) |
| `009717a0` | single-key + expand path | Sibling (not OWN) |
| `00971820` | `AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred` | Sibling expand path |

## Artifacts

- Raw / annotated / clean / twin / FUN_ record / A+B reviews (see dual report).

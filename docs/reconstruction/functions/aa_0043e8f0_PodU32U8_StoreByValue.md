# Function record: PodU32U8_StoreByValue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e8f0` |
| **Canonical name** | `PodU32U8_StoreByValue` (**Inferred**) |
| **Ghidra name** | `FUN_0043e8f0` |
| **Address** | `0x0043e8f0`–`0x0043e902` (**19 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | POD store adapter (by-value → split store) |
| **Dual** | W33-M 2026-07-29 — A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Materialize a 5-byte U32U8 POD into `dest` from two stack **values** (not pointers) by adapting to sealed `PodU32U8_StoreSplit`.

## Signature

```c
void* PodU32U8_StoreByValue(void* dest /*ESI*/,
                            uint32_t u32_val /*stack*/,
                            uint32_t u8_val /*stack*/);
// bare RET; returns dest; callers ADD ESP,8
```

## Related sealed units

| VA | Name | Relation |
|---|---|---|
| `0043ea50` | `PodU32U8_StoreSplit` | Nested leaf (split pointers) |
| `0043ecf0` | `PodU32U8_CopyIfNonNull` | Contiguous null-safe twin family |
| `0043e7f0` | `GuardedVector_PushBackLocked_Stride2_U32U8` | Typical consumer after materialize |

## Artifacts

- Raw / annotated / clean / twin / FUN_ record / A+B reviews (see dual report).

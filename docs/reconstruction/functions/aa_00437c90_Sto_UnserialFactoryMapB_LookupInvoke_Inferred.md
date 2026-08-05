# Function record: Sto_UnserialFactoryMapB_LookupInvoke_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437c90` |
| **Canonical name** | `Sto_UnserialFactoryMapB_LookupInvoke_Inferred` |
| **Address** | `0x00437c90`–`0x00437cce` (**63 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2/storage |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Review date** | `2026-07-29` (W36-C) |

## Alias

- Ghidra: `FUN_00437c90`
- Scaffold (reject): `Named_CalleeOf_*_gfxBody_*`

## Purpose

Sto abstract-unserialization **map B lookup/invoke**: peek tag from chunk reader, NestedHash find on MapB, call creator at `node+0xC` or return 0. Complements insert twin `0x00444a40`.

## Signature (sealed)

```c
// entry EAX = stoChunkReader*
void* Sto_UnserialFactoryMapB_LookupInvoke_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00437c90_FUN_00437c90.md`
- Annotated: `docs/reconstruction/raw/aa_00437c90_FUN_00437c90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_LookupInvoke_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00437c90.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md`, `B_aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | PeekChunkTag, MapB GetInstance, NestedHash find |
| Callers | `FUN_00765740` |
| Map | B only |

## Confidence

| Claim | Level |
|---|---|
| Lookup/invoke CF | **High** |
| Creator ABI | **Medium / gap** |

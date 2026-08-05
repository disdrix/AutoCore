# Function record: Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437b00` |
| **Canonical name** | `Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred` |
| **Address** | `0x00437b00`–`0x00437b57` (**88 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2/storage |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Review date** | `2026-07-29` (W36-A) |

## Alias

- Ghidra: `FUN_00437b00`
- Scaffold (reject as product role): `Named_CalleeOf_Named_gfxBody_00437b00`

## Purpose

**Lookup + create + unserialize** for the next peeked chunk tag against factory map A. Writes created object to caller out-slot; drives object unserialize vfunc with the active `stoChunkReader`.

## Signature (sealed)

```c
// cdecl; EDI = stoChunkReader*
uint32_t Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred(void **out);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00437b00_FUN_00437b00.md`
- Annotated: `docs/reconstruction/raw/aa_00437b00_FUN_00437b00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00437b00.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md`, `B_aa_00437b00_…`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | PeekChunkTag, MapA GetInstance, NestedHash lookup, creator, vfunc |
| Callers | `FUN_00765740` (4 sites) |
| Pair | Insert `FUN_004449b0` |

## Confidence

| Claim | Level |
|---|---|
| Peek/lookup/create/unserialize CF | **High** |
| Sto factory map A role | **High** |
| Concrete object class English | **Inferred** |

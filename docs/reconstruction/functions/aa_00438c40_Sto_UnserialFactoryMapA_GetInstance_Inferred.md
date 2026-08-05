# Function record: Sto_UnserialFactoryMapA_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438c40` |
| **Canonical name** | `Sto_UnserialFactoryMapA_GetInstance_Inferred` |
| **Address** | `0x00438c40`–`0x00438c99` (**90 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2/storage |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Review date** | `2026-07-29` (W35-D) |

## Alias

- Ghidra: `FUN_00438c40`
- Scaffold (reject): `Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438c40`

## Purpose

Meyers **GetInstance** for NestedHash creator-tag **map A** at `DAT_00d1fd18`. Cold path: once-flag `DAT_00d1fd40` bit0 → `NestedHash_Ctor_Sentinel0x10_Inferred` + atexit no-op. Always returns bag pointer.

Primary evidence: exclusive callers with plate `..\arda2/storage/stoAbstractUnserializationFactory.h` and "Inserting duplicate creator tag to factory".

## Signature (sealed)

```c
// cdecl void → NestedHash_Sentinel0x10*
NestedHash_Sentinel0x10* Sto_UnserialFactoryMapA_GetInstance_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00438c40_FUN_00438c40.md`
- Annotated: `docs/reconstruction/raw/aa_00438c40_FUN_00438c40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapA_GetInstance_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00438c40.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md`, `B_aa_00438c40_…`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | `FUN_00457ac0`, `_atexit` |
| Callers | `FUN_004449b0`, `FUN_00437b00` |
| Twin | MapB `0x00438ca0` |
| Ctor family | W34-E NestedHash node 0x10 |

## Confidence

| Claim | Level |
|---|---|
| Getter CF / ABI / static addresses | **High** |
| NestedHash 0x10 bag type | **High** |
| Sto unserialization factory map role | **High** (callers) |
| Tag-domain English "A" product name | **Inferred** |

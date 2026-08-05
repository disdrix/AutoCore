# Function record: Sto_AbstractUnserializationFactory_InsertCreator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004449b0` |
| **Canonical name** | `Sto_AbstractUnserializationFactory_InsertCreator_Inferred` |
| **Address** | `0x004449b0`–`0x00444a35` (**134 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2/storage |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Review date** | `2026-07-29` (W36-A) |

## Alias

- Ghidra: `FUN_004449b0`
- Registry plate: `Sto_AbstractUnserializationFactory`
- Scaffold (reject): `Named_CalleeOf_Named_CalleeOf_Named_Palantir_004449b0`

## Purpose

**Insert / rebind creator** for a FourCC tag in sto abstract unserialization factory **map A**. Duplicate tags log a warning then overwrite `node+0xc`. Creator arrives in **EBX**; tag on stack.

Primary evidence: embedded header + "Inserting duplicate creator tag to factory"; exclusive use of MapA getter; three FourCC registration wrappers.

## Signature (sealed)

```c
// cdecl; EBX = creator fn*
void Sto_AbstractUnserializationFactory_InsertCreator_Inferred(uint32_t tag);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004449b0_FUN_004449b0.md`
- Annotated: `docs/reconstruction/raw/aa_004449b0_FUN_004449b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Sto_AbstractUnserializationFactory_InsertCreator_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004449b0.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md`, `B_aa_004449b0_…`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | `FUN_00438c40`, `FUN_0046c1b0`, `FUN_0046bf90`, `vog_LogMessage` |
| Callers | `FUN_004448b0`, `FUN_004448d0`, `FUN_004448f0` |
| Pair | lookup/create `FUN_00437b00` |

## Confidence

| Claim | Level |
|---|---|
| Insert/bind CF + ABI | **High** |
| Sto factory map A role | **High** |
| Tag-domain product English | **Inferred** |

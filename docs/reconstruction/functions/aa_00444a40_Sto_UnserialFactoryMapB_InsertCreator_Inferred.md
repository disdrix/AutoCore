# Function record: Sto_UnserialFactoryMapB_InsertCreator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444a40` |
| **Canonical name** | `Sto_UnserialFactoryMapB_InsertCreator_Inferred` |
| **Address** | `0x00444a40`–`0x00444ac5` (**134 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2/storage |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Review date** | `2026-07-29` (W36-C) |

## Alias

- Ghidra: `FUN_00444a40`
- Plate/registry: `Sto_AbstractUnserializationFactory_00444a40`
- Scaffold (reject): `Named_CalleeOf_*_Palantir_*`

## Purpose

Sto abstract-unserialization **map B insert**: bind EBX creator under stack FourCC tag into NestedHash bag `DAT_00d1fcec` via GetInstance `FUN_00438ca0`. Duplicate log on existing key; still rebinds `node+0xC`.

## Signature (sealed)

```c
// cdecl; EBX = creator_fn*
void Sto_UnserialFactoryMapB_InsertCreator_Inferred(uint32_t tag);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00444a40_FUN_00444a40.md`
- Annotated: `docs/reconstruction/raw/aa_00444a40_FUN_00444a40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_InsertCreator_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00444a40.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md`, `B_aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | MapB GetInstance, NestedHash find/insert, vog_LogMessage |
| Callers | `FUN_00444910` DSDL, `FUN_00444930` AADL |
| Map | B only (`FUN_00438ca0`) — not MapA |

## Confidence

| Claim | Level |
|---|---|
| Insert/bind CF + strings | **High** |
| Map B exclusivity | **High** |
| Product plate beyond header | **Inferred** |

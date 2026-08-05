# Function record: Sto_UnserialFactoryMapB_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438ca0` |
| **Canonical name** | `Sto_UnserialFactoryMapB_GetInstance_Inferred` |
| **Address** | `0x00438ca0`–`0x00438cf9` (**90 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2/storage |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Review date** | `2026-07-29` (W35-D) |

## Alias

- Ghidra: `FUN_00438ca0`
- Scaffold (reject): `Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438ca0`

## Purpose

Meyers **GetInstance** for NestedHash creator-tag **map B** at `DAT_00d1fcec`. Cold path: once-flag `DAT_00d1fd14` bit0 → same NestedHash 0x10 ctor as MapA + atexit no-op. Always returns bag pointer.

Twin of MapA; exclusive callers are Sto factory sibling insert/lookup (`FUN_00444a40` / `FUN_00437c90`).

## Signature (sealed)

```c
// cdecl void → NestedHash_Sentinel0x10*
NestedHash_Sentinel0x10* Sto_UnserialFactoryMapB_GetInstance_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00438ca0_FUN_00438ca0.md`
- Annotated: `docs/reconstruction/raw/aa_00438ca0_FUN_00438ca0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_GetInstance_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00438ca0.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md`, `B_aa_00438ca0_…`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | `FUN_00457ac0`, `_atexit` |
| Callers | `FUN_00444a40`, `FUN_00437c90` |
| Twin | MapA `0x00438c40` |
| BSS neighbor | bag C `DAT_00d1fcc0` (`FUN_0044fee0`, W35-E) |

## Confidence

| Claim | Level |
|---|---|
| Getter CF / ABI / static addresses | **High** |
| Twin of MapA | **High** |
| Sto unserialization factory map role | **High** (callers) |
| Tag-domain English "B" product name | **Inferred** |

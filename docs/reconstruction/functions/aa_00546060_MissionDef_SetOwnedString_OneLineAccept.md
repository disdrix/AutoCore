# Function record: MissionDef_SetOwnedString_OneLineAccept

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546060` |
| **Canonical name** | `MissionDef_SetOwnedString_OneLineAccept` |
| **Address** | `0x00546060` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual A/B accept** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Owned C-string replace at mission def **`+0x154`** for XML tag **`OneLineAccept`** (EnsureXml hydrate).

## Signature

```c
void __thiscall MissionDef_SetOwnedString_OneLineAccept(MissionDef* this, char* src);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00546060_FUN_00546060.md`
- Annotated: `docs/reconstruction/raw/aa_00546060_FUN_00546060.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00546060.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00546060_MissionDef_SetOwnedString_OneLineAccept.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00546060_MissionDef_SetOwnedString_OneLineAccept.md`

## Confidence

| Claim | Level |
|---|---|
| Offset `+0x154` + free/alloc/copy | **High** |
| Tag OneLineAccept | **High** (parent EnsureXml) |

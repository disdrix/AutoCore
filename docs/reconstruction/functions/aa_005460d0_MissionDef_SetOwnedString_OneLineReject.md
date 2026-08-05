# Function record: MissionDef_SetOwnedString_OneLineReject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005460d0` |
| **Canonical name** | `MissionDef_SetOwnedString_OneLineReject` |
| **Address** | `0x005460d0` |
| **Module** | `autoassault.exe` |
| **System** | `missions-progression` |
| **Completion status** | **Dual A/B accept** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Owned C-string replace at **`+0x158`** for XML **`OneLineReject`**.

## Signature

```c
void __thiscall MissionDef_SetOwnedString_OneLineReject(MissionDef* this, char* src);
```

## Artifacts

- Raw: `raw/aa_005460d0_FUN_005460d0.md`
- Clean: `reconstructed-exact/FUN_005460d0.cpp`
- Dual A/B: `reviews/A_aa_005460d0_*`, `reviews/B_aa_005460d0_*`

## Confidence

| Claim | Level |
|---|---|
| Offset `+0x158` | **High** |
| Tag OneLineReject | **High** |

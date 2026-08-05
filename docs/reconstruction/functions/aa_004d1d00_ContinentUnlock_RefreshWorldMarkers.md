# Function record: ContinentUnlock_RefreshWorldMarkers

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d1d00` |
| **Canonical name** | `ContinentUnlock_RefreshWorldMarkers` |
| **Address** | `0x004d1d00` |
| **Module** | `autoassault.exe` |
| **System** | `missions-progression` / exploration |
| **Completion status** | **Dual A/B accept-with-gaps** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Client world side-effect after continent unlock/relock: despawn/spawn marker props from table `[+0xe798,+0xe79c)` stride `0x40`, gated on primary entity `+0xe8a0`.

## Signature

```c
void __fastcall ContinentUnlock_RefreshWorldMarkers(ClientWorld* world);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d1d00_FUN_004d1d00.md`
- Annotated: `docs/reconstruction/raw/aa_004d1d00_FUN_004d1d00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004d1d00.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004d1d00_ContinentUnlock_RefreshWorldMarkers.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004d1d00_ContinentUnlock_RefreshWorldMarkers.md`

## Callers

- `CVOGReaction_UnlockContinentObject` `0x00531c80`
- `CVOGReaction_RelockContinentObject` `0x0052a1b0`
- `FUN_004d9f00`

## Confidence

| Claim | Level |
|---|---|
| Visual marker refresh role | **High** |
| Not hash insert authority | **High** |
| Spawn CBID globals product values | **Open** (static −1) |

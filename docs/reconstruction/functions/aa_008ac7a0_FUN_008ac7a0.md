# Function record: FUN_008ac7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac7a0` |
| **Canonical name** | `FUN_008ac7a0` |
| **Inferred name** | `Client_MaybeShowMultiActiveMissionTip_Inferred` |
| **Address** | `0x008ac7a0`–`0x008ac884` (228 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual sealed 2026-08-04 (WQ7R-A)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (`terminal_coverage=false`) |

## Purpose

Walk active-mission hash at singleton `+0x540` under traversal lock; if ≥2 payloads satisfy `short@+0xf8==0 && int@+0xfc!=-1`, call `Client_MaybeShowFirstTimeTip(0x20)`. Sole caller: accept path of `Client_MissionDialogHandleButton`.

## Signature

```c
void FUN_008ac7a0(void); // plain ret; no formals
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.md`
- Annotated: `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_MaybeShowMultiActiveMissionTip_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008ac7a0.cpp`
- Named record: `docs/reconstruction/functions/aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md`
- Dual A/B: `reviews/A_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md`, `reviews/B_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md`

## Callers / callees

| Direction | Target |
|-----------|--------|
| Caller | `Client_MissionDialogHandleButton` (`0x008aec20`) |
| Callee | `FUN_007a4480`, `Client_MaybeShowFirstTimeTip` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / count predicate / tip threshold | High (Confirmed vs decompile+bytes) |
| Active mission hash at `+0x540` | High (missions system map + strings) |
| Product tip / field English | Tentative / Open → `_Inferred` |

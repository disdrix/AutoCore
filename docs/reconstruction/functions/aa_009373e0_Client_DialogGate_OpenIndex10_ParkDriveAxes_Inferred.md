# Function record: Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009373e0` |
| **Canonical name** | `Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred` |
| **Ghidra name** | `FUN_009373e0` |
| **Address** | `0x009373e0`–`0x00937462` (**131 B** / `0x83`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Partition** | MEGA-024 (`WAVE_2026-08-05_mega_residual_partition_map.md`) |
| **Completion status** | **Dual sealed** (OWN-ONLY MEGA-024) |
| **Name confidence** | **Inferred** — behavior sealed; product method / dialog-10 English open |
| **Bit-for-bit / runtime / diff** | Open — Terminal **false** |

## Purpose

When the client dialog-host gate matches, open dialog table index **10**, update mission-dialog caption host (`client+0x1058`) from the stack stamp, and park the local vehicle axes (longitudinal 0, steer 0, handbrake 1).

## Signature

```c
// Retail register/stack model
void Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred(
    /* EDI */ Client* client,
    /* stack */ int npcOrClear);
// RET 4
```

## Body summary

1. Gate: `[EDI+0xf40] != 0` and `**[EDI+0xf40] == *[EDI+0xf38]`.
2. `Client_OpenDialogByIndex(EDI, 10, 0, 0)`.
3. `MissionDialog_SetNpcObjectAndNameCaption([EDI+0x1058], stamp)`.
4. If `[EDI+0xe98]` and `+0x250` vehicle: thr0, steer0, HB1 (HB via tail JMP).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009373e0_FUN_009373e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009373e0_FUN_009373e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.cpp` |
| Twin FUN_ | `docs/reconstruction/reconstructed-exact/FUN_009373e0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_009373e0_FUN_009373e0.md` |
| Report | `docs/agents/task-dual-ab-009373e0-mega-024-report.md` |

## Related (not dualled here)

| VA | Relation |
|---|---|
| `0x007fef20` | dualed `Client_OpenDialogByIndex` |
| `0x008aa4b0` | dualed caption helper (MEGA-058) |
| `0x004f5650` / `0x004f5620` / `0x004f3620` | dualed vehicle axis setters |
| `0x0092f090` | pure thr0/steer0/HB1 park (no open) — MEGA-021 residual |
| `0x00952b20` | sole caller stub |

## Dual verdict

**accept-with-gaps** (A + B). Terminal **false**.

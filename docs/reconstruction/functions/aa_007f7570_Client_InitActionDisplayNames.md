# Function record: Client_InitActionDisplayNames

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f7570` |
| **Canonical name** | `Client_InitActionDisplayNames` |
| **Address** | `0x007f7570` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Human-refined partial** — force_decompile recovered body; sectioned name groups; dual review not required this pass |
| **Bit-for-bit / runtime / diff** | Open |
| **Last refined** | 2026-07-23 (force_decompile + human-refine) |

## Purpose

Fill human-readable action/keybind display names into ActionMap fixed-stride (`0x34`) slots. Pure string copies — no DIK writes.

## Signature

```c
void Client_InitActionDisplayNames(void)
// ActionMap* arrives in EAX (decomp in_EAX → pActionMap)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007f7570_Client_InitActionDisplayNames.md` (append force_decompile recovery)
- Annotated: `docs/reconstruction/raw/aa_007f7570_Client_InitActionDisplayNames.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_InitActionDisplayNames.cpp`

## Drive-axis display names (ActionMap base)

| Offset | String |
|-------:|--------|
| `+0x27d` | Accelerate |
| `+0x2b1` | Reverse |
| `+0x2e5` | Steer Left |
| `+0x319` | Steer Right |
| `+0x34d` | Steer Left Soft |
| `+0x381` | Steer Right Soft |
| `+0x3b5` | Brake |

## Confidence

| Claim | Level |
|---|---|
| Control flow / string stores from force_decompile | High |
| Drive name offsets | High |
| Link of names → held DAT_* | Medium (system map / plate) |

# Function record: CVOGHBPendingUseObject_Stop_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b410` |
| **Canonical name** | `CVOGHBPendingUseObject_Stop_Inferred` (**Probable**) |
| **Ghidra name** | `FUN_0060b410` |
| **Address** | `0x0060b410`–`0x0060b438` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / missions-progression |
| **Completion status** | **Full dual seal** (W26-T 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Stop the pending-use-object HB aux at `char+0xca0`: optional cancel of character pending resolve, then hard EndOrDestroy.

## Signature

```c
void __thiscall CVOGHBPendingUseObject_Stop_Inferred(
    CVOGHBPendingUseObject* self, char flag_cancel_pending);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0060b410_FUN_0060b410.md`
- Annotated: `docs/reconstruction/raw/aa_0060b410_FUN_0060b410.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBPendingUseObject_Stop_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0060b410.cpp`
- Ghidra record: `docs/reconstruction/functions/aa_0060b410_FUN_0060b410.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md`, `B_aa_0060b410_…`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **High** |
| Product English | **Tentative** (`_Inferred`) |

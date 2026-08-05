# Function record: GfxDevice_Reset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075eff0` |
| **Canonical name** | `GfxDevice_Reset` |
| **Ghidra name** | `FUN_0075eff0` |
| **Address** | `0x0075eff0`–`0x0075f55f` exclusive (**1391 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics |
| **Completion status** | **Dual A/B complete (W37-N)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Product device Reset body in `gfxDevice.cpp`. Called from `Palantir::ResetDevice` with EAX=`Palantir+8` and stack device / present args from Palantir fields.

## Signature

```c
int __stdcall GfxDevice_Reset(void* device, uint32_t arg_b0, uint8_t flag5);
// + live-in EAX present seed
```

## Artifacts

See `aa_0075eff0_FUN_0075eff0.md`.

## Confidence

| Claim | Level |
|---|---|
| Product name + ABI + 0/−1 | **High** |
| Factory fail plate | **High** |
| Unowned helper contracts | **Open** |

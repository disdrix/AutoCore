# Function record: Palantir_ResetDevice

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754480` |
| **Canonical name** | `Palantir_ResetDevice` |
| **Ghidra name** | `FUN_00754480` |
| **Address** | `0x00754480`–`0x007544E0` exclusive (**96 B** / `0x60`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir host device reset |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W35-K 2026-07-29) — stage order/ABI/product sealed; nested device dual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `Palantir_ResetDevice` (**product**)
- Ghidra: `FUN_00754480`
- Vtbl family: `PTR_FUN_00a9f76c[1]` (peer complete dtor W34-K `aa_00754320`)
- Product path: `C:\vog\1_code\palantir\palantir\framework\Palantir.cpp:0x184`

## Purpose

Product `Palantir::ResetDevice`: attempt device reset through nested `FUN_0075eff0`; failure path logs, sets retry flag at `this+6`, sleeps 1000 ms, returns -1; success clears flag, calls `(*(this+0x2C))->vtbl[+8](this+8)`, returns 0.

## Signature (sealed)

```c
// ECX=this; bare RET; EAX = 0 success / -1 failure
int Palantir_ResetDevice(Palantir* self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00754480_FUN_00754480.md` (+ W35-K append)
- Annotated: `docs/reconstruction/raw/aa_00754480_FUN_00754480.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Palantir_ResetDevice.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00754480.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_00754480_FUN_00754480.md`
- Review A/B: `reviews/A_aa_00754480_Palantir_ResetDevice.md`, `reviews/B_aa_00754480_Palantir_ResetDevice.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_007a3c80` (direct @ `0x007a3c84`); virtual via vtbl[1] | `FUN_0075eff0`, `vog_LogMessage`, IAT `Sleep` |

## Confidence

| Claim | Level |
|---|---|
| Product method name | **High** |
| ABI ECX/this + 0/-1 | **High** |
| Retry flag + Sleep(1000) | **High** |
| Nested device implementation | **Low** |

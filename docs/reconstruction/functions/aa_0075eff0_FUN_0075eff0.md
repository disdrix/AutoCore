# Function record: FUN_0075eff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075eff0` |
| **Canonical name** | `GfxDevice_Reset` |
| **Ghidra name** | `FUN_0075eff0` |
| **Address** | `0x0075eff0`–`0x0075f55f` exclusive (**1391 B** / `0x56F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics (`gfxDevice.cpp`) |
| **Completion status** | **Dual A/B complete (W37-N)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Product `gfxDevice` **Device Reset()** implementation: shutdown GPU resources, `IDirect3DDevice9::Reset`, rebuild factories/caps, return 0/−1. Nested core of `Palantir::ResetDevice` (W35-K).

## Signature (bytes + sole caller)

```c
// EAX = present seed (Palantir+8); stdcall 3 stack args; RET 12; EAX = 0 | -1
int __stdcall GfxDevice_Reset(void* device, uint32_t arg_b0, uint8_t flag5 /* + EAX formal */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075eff0_FUN_0075eff0.md`
- Annotated: `docs/reconstruction/raw/aa_0075eff0_FUN_0075eff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxDevice_Reset.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0075eff0.cpp`
- Named record: `docs/reconstruction/functions/aa_0075eff0_GfxDevice_Reset.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0075eff0_GfxDevice_Reset.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0075eff0_GfxDevice_Reset.md`

## Callers / callees

| Callers | Callees (high-signal) |
|---|---|
| `FUN_00754480` Palantir_ResetDevice @ `0x00754498` (sole) | `FUN_0075e710`, factory Reset helpers, `vog_LogMessage`, `FUN_0076c130`, D3D vcalls on `*device`, accounting helpers |

## Confidence

| Claim | Level |
|---|---|
| Product Reset identity (path + strings) | **High** |
| EAX + 3 stack + RET 12 + 0/−1 | **High** |
| IDirect3DDevice9::Reset / TCL role | **High** (HRESULT + strings) |
| Full field English for GfxDevice | **Partial** |
| Runtime / bit-exact | **Open** |

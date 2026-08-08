# Function record: CNDUIWindow_ClearOwnedObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a8580` |
| **Canonical name** | `CNDUIWindow_ClearOwnedObject_Inferred` |
| **Ghidra** | `FUN_007a8580` |
| **Address** | `0x007a8580`–`0x007a85df` (**96 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIWindow / UI owned-object clear |
| **Completion status** | **Dual sealed** WQ9L-E 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Clear the owned/hosted object pointer at `CNDUIWindow+0x298`. Virtual method at primary vtbl `PTR_FUN_00a960ac` slot **+0x44**. Set pair is `FUN_007a85e0` (slot **+0x40**).

## Signature

```c
void __fastcall CNDUIWindow_ClearOwnedObject_Inferred(void* self /* ECX */);
```

## Layout touchpoints

| Off | Role |
|---|---|
| `+0x298` | owned object pointer (always nulled) |
| `+0x2B4` | child/iface — scalar dtor flags=0 |
| `+0xBC` | ownership flag — if set, scalar-delete owned (flags=1) |

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_007a8580_FUN_007a8580.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_ClearOwnedObject_Inferred.cpp`
- Dual A/B under `docs/reconstruction/reviews/`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets / vtbl slot | **High** |
| Name English | **Inferred** (structural; product class CNDUIWindow via owner RTTI) |

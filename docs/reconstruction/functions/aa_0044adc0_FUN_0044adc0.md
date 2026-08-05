# Function record: FUN_0044adc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044adc0` |
| **Canonical name** | `Phy_CPConnectionPair_ReleaseClear` |
| **Ghidra name** | `FUN_0044adc0` |
| **Address** | `0x0044adc0`–`0x0044ae50` (145 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics-cpconnection |
| **Completion status** | **Dual sealed W22-S** — raw append + annotated + clean A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Human: `Phy_CPConnectionPair_ReleaseClear`
- Prior auto: `Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_0044adc0`

## Purpose

Release dual smart-pointer slots (`+4`, `+0xC`) and clear owner-outs (`+0`, `+8`) of a CP-connection bind pair. `ret 4` stdcall. Does not free the pair heap block.

## Signature (byte-sealed)

```c
void __stdcall Phy_CPConnectionPair_ReleaseClear(CPConnectionPair *pair);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044adc0_FUN_0044adc0.md`
- Annotated: `docs/reconstruction/raw/aa_0044adc0_FUN_0044adc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Phy_CPConnectionPair_ReleaseClear.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0044adc0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md`
- Review B: `docs/reconstruction/reviews/B_aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (7) | `ClientSpecialEvent_TeleportIn_ctor`, `ClientSpecialEvent_Respawn_Update`, `FUN_0096d550`, `FUN_0096d5c0`, `FUN_0096dc80`, `FUN_009784f0`, `FUN_00855ff0` |
| Callees | `FUN_00437150` ×2 |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ref protocol / offsets | **High** |
| ABI stdcall `ret 4` | **High** |
| Pair layout vs `0x0044af00` bind helper | **High** |
| Product C++ type name | **Probable** (inferred from `phyCPConnection.h` sibling) |
| `vtbl+8` English = Release | **Probable** |

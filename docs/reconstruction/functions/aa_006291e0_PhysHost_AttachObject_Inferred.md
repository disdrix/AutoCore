# Function record: PhysHost_AttachObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006291e0` |
| **Canonical name** | `PhysHost_AttachObject_Inferred` |
| **Ghidra** | `FUN_006291e0` |
| **Address** | `0x006291e0`–`0x00629231` exclusive (**81** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / phys host |
| **Completion status** | **Dual sealed** W30-I 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Host-side attach leaf used by `WorldObj_AttachRegisterHost_Inferred`: register world object on host list, stamp backlink/index, fire nested→host vcall notify pair.

## Signature

```c
void __thiscall PhysHost_AttachObject_Inferred(void* host, void* worldObj);
// RET 4
```

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_006291e0_FUN_006291e0.md`
- Clean: `docs/reconstruction/reconstructed-exact/PhysHost_AttachObject_Inferred.cpp`
- Dual A/B under `docs/reconstruction/reviews/A|B_aa_006291e0_PhysHost_AttachObject_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Name English | **Inferred** (PhysHost family + W29-T Host_Attach role) |

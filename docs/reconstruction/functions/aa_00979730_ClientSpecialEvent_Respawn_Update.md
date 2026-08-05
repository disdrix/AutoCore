# Function record: ClientSpecialEvent_Respawn_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979730` |
| **Canonical name** | `ClientSpecialEvent_Respawn_Update` |
| **Address** | `0x00979730` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client special-event / respawn presentation |
| **Completion status** | **Dual-reviewed** — three-rep present; A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (static decompile + `read_memory` only) |

## Purpose

Virtual per-frame **Update** for the client **Respawn** special-event (INC airlift). Accumulates `dt`, advances phase `0..7` (spawn `cptest.geo`, lift-follow, teleport to dest, camera restore, complete). Return **1** = finished; **0** = continue. Not a packet handler.

## Signature (prologue-sealed)

```c
// __thiscall ECX=this; stack float dt
undefined4 __thiscall ClientSpecialEvent_Respawn_Update(int this, float dt);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00979730_ClientSpecialEvent_Respawn_Update.md`
- Annotated: `docs/reconstruction/raw/aa_00979730_ClientSpecialEvent_Respawn_Update.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ClientSpecialEvent_Respawn_Update.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00979730_ClientSpecialEvent_Respawn_Update.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00979730_ClientSpecialEvent_Respawn_Update.md`

## Callers / callees

| Direction | Note |
|---|---|
| Caller | Vtable only — DATA xref `0x00a76720` |
| Key callees | `FUN_00979310`, `FUN_004bb010`, `CVOGReaction_TeleportTarget`, `FUN_005816a0`, `FUN_00979290`, `FUN_0090dd50`, `FUN_00417e40`, ship ctor/`cptest.geo`, `FUN_0040d4b0` |

## Key sealed facts

| Fact | Value |
|---|---|
| Phase field | `this+0x6d` (0..7) |
| Elapsed / phaseTime | `+0x60` / `+0x64` |
| Lift-follow flag | `+0x6c` |
| Cancel flag | `+0x08` → `FUN_00979310` |
| Timing Δ | 4.0, ≈3.433, ≈0.566, 1.0, 2.0; blend 0.1 |
| Complete | phase 6→7 return 1; or phase 2 with `+0x38==0` return 1 |

## Confidence

| Claim | Level |
|---|---|
| Control flow / phase machine | **High** |
| Timing constants (`read_memory`) | **High** |
| Layout offsets used in unit | **High** |
| Helper product names (`FUN_005816a0` modes, attach glue) | **Medium / Tentative** |
| Runtime parity | Open |

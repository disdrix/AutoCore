# Function record: FUN_005d9af0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9af0` |
| **Canonical name** | `Drive_CollisionListener_PlayCollisionEffect` |
| **Ghidra name** | `FUN_005d9af0` |
| **Address** | `0x005d9af0`–`0x005d9e94` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | drive / collision / client FX |
| **Completion status** | **Dual-sealed W23-G** — raw append + annotated + clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

`CollisionListener::PlayCollisionEffect` — apply collision special FX to a game object: resolve clonebase FX, optional lazy FxMaster create on listener+4, load event variant, sample GO frames, set three float3 params, play.

## Signature (byte-sealed)

```c
// __thiscall RET 0x14
void Drive_CollisionListener_PlayCollisionEffect(
    int this_listener, float *vec3_a, uint32_t arg1, uint32_t arg2,
    int *gameObject, int8_t allowCreate);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d9af0_FUN_005d9af0.md`
- Annotated: `docs/reconstruction/raw/aa_005d9af0_FUN_005d9af0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_PlayCollisionEffect.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d9af0.cpp`
- Named plate: `docs/reconstruction/functions/aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md`
- Reviews: `A_` / `B_aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (2) | `FUN_005da0a0` Contact, `FUN_005d9ea0` |
| Callees | `FUN_0076cf00/cef0`, `operator_new`, `FUN_004a1620`, `FUN_004a6390`, `FUN_004a16d0`, `FUN_004eb3b0`, `FUN_004b7550`×3, `FUN_004b7e50`, GO vtbl+0x1c8 / +0xf8 |

## Confidence

| Claim | Level |
|---|---|
| Name / profiler string | **High** |
| RET 0x14 + thiscall | **High** |
| Null go early-out | **High** |
| Lazy FxMaster @ +4 | **High** |
| clonebase @ go+0xA8 / gate +0x88 | **High** |
| stack1/stack2 English | Medium residual |
| Full float algebra bit-exact | Medium residual |
| Runtime | Open |

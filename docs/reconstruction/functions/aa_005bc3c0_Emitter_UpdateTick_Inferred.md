# Function record: Emitter_UpdateTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc3c0` |
| **Canonical name** | `Emitter_UpdateTick_Inferred` |
| **Ghidra name** | `FUN_005bc3c0` |
| **Address** | `0x005bc3c0`–`0x005bdce6` exclusive (**6438** B / `0x1926`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::fx / emitter |
| **Completion status** | **Sealed** — dual A/B W28-I 2026-07-29; **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** |

## Naming evidence

| Source | Value |
|---|---|
| Sole caller | `NDSpecialFX_HostTick_Inferred` — list `+0x1E0` payload tick |
| String | `"Emitter found at 0,0,0: %d %I64d"` |
| Child | sole caller of `Emitter_SpawnOnIntervalTick_Inferred` |
| Keep polarity | return 0 remove / 1 keep → SlotListTick |
| Product mangled on this VA | **No** |

**Decision:** promote **`Emitter_UpdateTick_Inferred`** (role sealed; product English residual → `_Inferred`).  
Reject scaffold chain name `Named_CalleeOf_…_Client_Input_PollB` as product claim.

## Signature

```c
// __thiscall; ECX = emitter*; stack float* dt, int host_field_2c, int camera_or_world;
// RET 0x0C; return 0=remove, 1=keep
uint32_t Emitter_UpdateTick_Inferred(int *emitter, float *dt, int host_field_2c, int camera_or_world);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.md`
- Annotated: `docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Emitter_UpdateTick_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005bc3c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005bc3c0_Emitter_UpdateTick_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005bc3c0_Emitter_UpdateTick_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005bc3c0_FUN_005bc3c0.md`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 0x0C | **Confirmed** (`read_memory`) |
| Keep 0/1 polarity vs HostTick | **Confirmed** (caller decompile) |
| Interval spawn child linkage | **Confirmed** (W26-I + live) |
| Full pose-branch bit-exact port | **Medium** (staged clean; raw authority) |
| Product English | **Inferred** |
| Runtime | **Open** |

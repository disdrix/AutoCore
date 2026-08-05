# Review A (reconstruction fidelity): `aa_0053eec0` VehicleNet_ApplyNetworkPose_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053eec0` |
| **VA** | `0x0053eec0` |
| **Canonical name** | `VehicleNet_ApplyNetworkPose_Inferred` (was `FUN_0053eec0`) |
| **Ghidra symbol** | `FUN_0053eec0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053eec0_VehicleNet_ApplyNetworkPose_Inferred.md` |
| **System** | `input-drive-control` / vehicle ghost pose apply |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — soft/hard CF + constants sealed; integrate arg-order residual |

---

## 1. Purpose

Client **network pose + velocity apply** for CVOG entities with a physics shell (primary: vehicle ghost path from `Vehicle_setDrivingInputs`).

Two major paths:

### Soft path (phys present, valid mass, **not fully ready**)

`notFullyReady = (phys+0x40==0) || (phys+0x08==0)`

1. Stamp `entity+0x14 = g_dwClientTickMs`, `entity+0x10 byte = 1`.
2. Ensure soft buffer at `entity+0x28` (`FUN_0053e020`).
3. `buf.pos = netPos`.
4. `buf.linVel = (‖netVel‖ ≥ 0.01) ? netVel : zero` (`DAT_00a0f718`).
5. `buf.rot = netRot` **iff** `FUN_00568100` unit-quat gate.
6. `buf.ω = netAngVel` always.
7. If `‖netPos − livePos‖ > 15` (`DAT_009d000c`): entity vtbl+0x40; `setPos`; `ApplyImpulseVector(vel)`; `setRot`; `setAngVel`.
8. If `integrateDt == 0` return; else `FUN_0053eb90(0, integrateDt)`.

### Hard path (no soft)

If `‖netPos‖ > ~1.19e-7`: write **visual** pos/rot only (`entity` visual chain +0x84 / +0x94). **No** lin/ang vel push.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0053eec0` |
| Raw | `raw/aa_0053eec0_FUN_0053eec0.md` |
| Verified | `physics/verified/fn_0053eec0_networkApply.md` |
| Constants | `read_memory` 15.0 / ε / 0.01 / 0.5 / 0.001 |
| Callers | `Vehicle_setDrivingInputs` `0x504c70`, `FUN_005057c0`, `FUN_004c6360` |

---

## 3. Signature

```c
void __thiscall ApplyNetworkPose(
  Entity* this,
  float* pos, float* rot, float* linVel, float* angVel,
  float integrateDt);
```

### Soft-ready dual field

Same as `Object_SetPhysBodyTypeIfNotReady`: `phys+0x40` and `phys+0x08`.

### Live pos for 15u test

```
if (entity+0x08 == 0) live = visual pos chain
else live = chassis body +0xb0
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Soft vs hard split | **High** |
| Teleport 15u / vel floor 0.01 | **High** |
| Soft buffer field map | **High** |
| Hard path pose-only | **High** |
| Integrate stack order at this site | **Medium** residual |

**Verdict:** **accept-with-gaps**

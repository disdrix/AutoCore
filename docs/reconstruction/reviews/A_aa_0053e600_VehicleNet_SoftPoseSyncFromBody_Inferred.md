# Review A (reconstruction fidelity): `aa_0053e600` VehicleNet_SoftPoseSyncFromBody_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e600` |
| **VA** | `0x0053e600` |
| **Canonical name** | `VehicleNet_SoftPoseSyncFromBody_Inferred` (was `FUN_0053e600`) |
| **Ghidra symbol** | `FUN_0053e600` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of soft-pose graph / ApplyNetworkPose family) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053e600_VehicleNet_SoftPoseSyncFromBody_Inferred.md` |
| **System** | input-drive-control / vehicle ghost soft-pose |
| **Callees** | `FUN_0053fc10`, `FUN_0053e020`, `SetPosition 0x0040d2a0`, `ApplyImpulseVector 0x0040d260` |
| **Caller** | `FUN_004fb370` (vehicle tick / phys path with large this-adjust) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Seed or resync soft pose buffer from live rigid body**, and optionally hard-correct body when soft lags.

Framing: decompiler shows `__fastcall` with **negative this offsets** (`param_1 + -0x48`, `-0x30`, `-0x2c`) — MSVC **this-adjust** (multi-inherit / interior pointer). Mapping consistent with soft buffer pointer slot at adjusted `this-0x2c` ≡ entity soft slot used by ApplyNetworkPose (`entity+0x28` family). Exact base identity residual.

CF:

```
if physHost (this-0x48) == 0: clear seeded flag (this-0x30)=0; return
if FUN_0053fc10() == 0: clear seeded; return

if seeded_flag == 0:
  seeded_flag = 1
  ensure softBuf (this-0x2c) via FUN_0053e020
  softBuf.pos  = body+0xb0..0xbc
  softBuf+0x20 = body+0x40..0x4c   // lin vel
  softBuf+0x30 = body+0x50..0x5c   // ang vel
  return

// already seeded: measure ‖body.pos - soft.pos‖
if dist > DAT_00a0f694 (30.0f, read_memory):
  SetPosition(softBuf.pos)                 // 0040d2a0
  ApplyImpulseVector(softBuf+0x20)         // push soft lin vel into body
  return

// close enough: refresh soft from body pos + lin vel only (no ang on this path)
softBuf.pos = body+0xb0
softBuf+0x20 = body+0x40
```

**Not** ApplyNetworkPose (network → entity). This is **body ↔ soft buffer** maintenance on the local sim tick path.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0053e600` (full body) |
| Callers | `get_function_callers` → `FUN_004fb370` |
| Constant | `read_memory` `0x00a0f694` → **30.0f** |
| Soft alloc | `FUN_0053e020` dual present |
| Phys helpers | `A_aa_0040d2a0_*`, `A_aa_0040d260_*` dual present |
| Raw / clean | `raw/aa_0053e600_*`, `FUN_0053e600.cpp` |

---

## 3. Signature

```c
// ECX = adjusted entity/physics view (negative offsets)
void __fastcall SoftPoseSyncFromBody(AdjustedEntity *this);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| First-time seed copies pos+lin+ang from body | **High** |
| Re-sync threshold **30.0** world units | **High** |
| Far path: setPos soft + impulse soft lin | **High** |
| Near path: refresh soft pos+lin from body | **High** |
| Gate via `FUN_0053fc10` | **High CF** / English **Open** |
| Exact this-adjust base (entity+Δ) | **Medium** residual |
| Network wire IO | **None** (falsified) |

**Verdict:** **accept-with-gaps**

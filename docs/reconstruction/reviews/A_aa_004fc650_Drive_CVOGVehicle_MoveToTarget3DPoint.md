# Review A (reconstruction fidelity): `aa_004fc650` Drive_CVOGVehicle_MoveToTarget3DPoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fc650` |
| **VA** | `0x004fc650` |
| **Canonical name** | `Drive_CVOGVehicle_MoveToTarget3DPoint` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fc650_Drive_CVOGVehicle_MoveToTarget3DPoint.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |
| **UF-007 (this pass)** | **Sealed High (static)** — three-load chain + mask semantics ≡ `SetSteerInput` |

---

## 1. Purpose

AI/path drive helper: given target 3D point + acceptance radius, compute heading/range error and write thr/steer/handbrake axes on vehicle entity. Entry requires physics body `this+0x8` and `this+0x101==0`. Pose from body `+0x3c+0xb0` (or wobj fallback). Proportional steer path when world-obj `+0xb4` bits allow → store entity `+0x618`; else hard `VehicleEntity_SetSteerInput(±1)`. Longitudinal bulk store `+0x614`; sharp handbrake `+0x61c` when speed high + large heading error. Ends with `PushDriveAxesToController`; arrival zeros thr via SetLongitudinal. Core NPC/AI MoveTo / path-follow axis writer (pairs MapPath_AdvanceAndSteer).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fc650_FUN_004fc650.md` |
| Annotated | `docs/reconstruction/raw/aa_004fc650_FUN_004fc650.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CVOGVehicle_MoveToTarget3DPoint_004fc650.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fc650_FUN_004fc650.md` |
| Prior verified | `docs/reconstruction/physics/verified/fn_004fc650_driveController.md` |
| Dual residual peer | `VehicleEntity_SetSteerInput` @ `0x004f5620` (live MCP decompile this pass) |
| Evidence | Ghidra MCP `batch_decompile` `0x004fc650,0x004f5620` (2026-07-29) |

---

## 3. Dual residual — UF-007 wobj gate vs SetSteerInput

### 3.1 Three-load pointer chain (parenthesization)

**Live decompile — identical C tree in both functions:**

```c
// VehicleEntity_SetSteerInput @ 0x004f5620
iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

// Drive_CVOGVehicle_MoveToTarget3DPoint proportional path @ 0x004fc650
iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
```

Reading order (same both):

| Step | Expression | Role |
|---|---|---|
| 1 | `p0 = *(this + 4)` | linked block |
| 2 | `p1 = *(p0 + 4)` | second hop |
| 3 | `wobj = *(p1 + this + 0xb0)` | entity-relative slot |

**Verdict:** **no parenthesization difference**. Older loose notes of the form `*(*(this+4)+4 + this + 0xb0)` (one-level after `p0`) are **not** what the decompiler emits for MoveToTarget; retail form is the **same three-load chain** as SetSteerInput.

### 3.2 Flag allow predicate (mask form vs expanded bits)

| Site | Allow write when |
|---|---|
| SetSteerInput | `(wobj == 0) \|\| ((*(u8*)(wobj+0xb4) & 199) == 0)` — `199 == 0xC7` |
| MoveToTarget proportional | `(wobj == 0) \|\| ( (b&2)==0 && (b&4)==0 && (b&1)==0 && (b&0x80)==0 && (b&0x40)==0 )` |

Expanded bits: `0x01 | 0x02 | 0x04 | 0x40 | 0x80` = **`0xC7`**.

Boolean equivalence (for any `b`):

```
(b & 0xC7) == 0
  ⇔  (b&1)==0 ∧ (b&2)==0 ∧ (b&4)==0 ∧ (b&0x40)==0 ∧ (b&0x80)==0
```

MoveToTarget decompiler parenthesizes as nested `&&` of zero-tests; SetSteerInput uses a single masked compare. **Semantic gate ≡**; form-only residual.

### 3.3 Store target

| Site | On allow |
|---|---|
| SetSteerInput | `*(float/u32*)(this+0x618) = param` |
| MoveToTarget proportional | `*(float*)(this+0x618) = fVar7` (clamped proportional steer) |

### 3.4 Path coverage (not a parenthesization issue)

| Path | Gate application |
|---|---|
| MoveToTarget **proportional** (`\|lateral\| >= 0.01`) | **Inline** expanded `0xC7` gate, then direct `+0x618` |
| MoveToTarget **deadband** | Calls `VehicleEntity_SetSteerInput` → **callee** applies same three-load + `0xC7` |
| MoveToTarget **throttle** `+0x614` | Direct store (no inline gate); arrival uses `SetLongitudinalInput` (gated) |
| MoveToTarget **sharp** `+0x61c` | Direct byte store (no `0xC7` gate) |

> Older drive-controller-spec claim that deadband “is not subject to this gate” is **false for end effect**: deadband goes through SetSteerInput, which re-applies the same gate (see `fn_004f5620_setSteerInput.md` correction note).

### 3.5 UF-007 status (this dual)

| Claim | Status | Confidence |
|---|---|---|
| Three-load chain differs from SetSteerInput | **Falsified** | High |
| Mask bits differ from `0xC7` | **Falsified** (expanded ≡ mask) | High |
| Proportional inline vs setter form | Documented form-only residual | High |
| Type of `wobj` / per-bit meanings | Still open (UF-001 / UF-002) | — |

**UF-007 parenthesization residual: sealed High (static).** Cross-ref: CX-002 resolved with UF-007.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Entry: body `+0x8` and `+0x101==0` | High | Live decompile |
| Heading/lateral from target vs pose | High | ABS/SQRT + basis extractors |
| Proportional steer → `+0x618` under wobj gate | High | Inline bits ≡ 0xC7 |
| Hard spin via SetSteerInput | High | Deadband path |
| Thr store `+0x614` | High | Direct on drive path |
| HB `+0x61c` sharp-turn path | High | Speed × heading |
| PushDriveAxesToController exit | High | Both drive + arrival |
| String `CVOGVehicle::MoveToTarget3DPoint` | High | Profiler tag |
| **UF-007 three-load ≡ SetSteerInput** | **High** | Dual residual this pass |
| **UF-007 mask bits ≡ 0xC7** | **High** | 1\|2\|4\|0x40\|0x80 |
| Exact param_2 / param_3 names (radius vs cruise) | Medium | Prior verified plate; not re-proved here |
| Full float golden / bit-exact gains | Medium | Constants in prior verified; no emulate this pass |
| `wobj` type identity | Low–Med | UF-001 |
| Suppress-bit meanings | Low–Med | UF-002 |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Body gate → delta → steer/thr/HB → push | Yes |
| Proportional inline gate three-load + expanded bits | Yes (live ≡ raw) |
| No invented client input poll | Yes |
| Deadband → SetSteerInput | Yes |

---

## 6. Gaps / open (post UF-007 seal)

1. Exact acceptance of param_2 / param_3 (radius vs cruise gain) — prior plate Medium; not re-proved this residual pass.
2. `wobj` type / class (UF-001) and per-bit meanings of `0xC7` (UF-002).
3. Runtime / differential / bit-exact vs loaded image.
4. Direct thr `+0x614` lacks the setter gate on the main drive path (by design in binary; port parity choice).

**Verdict:** **accept-with-gaps** — CF + UF-007 gate residual sealed; unit not complete.

# Review A (reconstruction fidelity): `aa_004f5650` VehicleEntity_SetLongitudinalInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5650` |
| **VA** | `0x004f5650` |
| **Canonical name** | `VehicleEntity_SetLongitudinalInput` |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f5650_VehicleEntity_SetLongitudinalInput.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Gated write of raw longitudinal-axis float at **this+0x614**. Allows write when final linked object pointer is **null**, or when flag byte at **+0xb4** has **none** of bits **0xC7** set (write-suppress mask). Intermediate `p0`/`p1` loads are **unchecked** (null intermediate faults); only final **wobj** null is an allow path. No clamps, ramps, callees, or controller push — callers supply sign/magnitude.

**Sibling:** `VehicleEntity_SetSteerInput` (`aa_004f5620`) — **byte-identical** body except store `+0x618`. Primary local caller `Client_Input_DriveControlTick`: Accelerate → **−1.0**, Reverse → **+1.0**, release → 0; tick also requires `vehicle+0x101==0` before calling.

---

## 2. Inspected artifacts (this pass)

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` | Unchanged (authoritative); live ≡ raw |
| Annotated | `docs/reconstruction/raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.annotated.md` | Residual notes eligible |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetLongitudinalInput.cpp` | CF ≡ raw (no edit required) |
| Function record | `docs/reconstruction/functions/aa_004f5650_*.md` | **Updated** (callers/size/consumers/bypass) |
| Live decompile | Ghidra MCP `0x004f5650` | **≡ raw** |
| Live sibling decompile | Ghidra MCP `0x004f5620` | Mirror gate; store `+0x618` |
| Live body bytes | `read_memory` @ `0x004f5650` / `0x004f5620` | Twin images; only store disp differs |
| Live body span | `get_function_by_address` | `0x004f5650`–`0x004f567a` (0x2a bytes) |
| Live xrefs | `get_function_callers` / `get_function_xrefs` | 9 funcs / 16 call sites |
| Consumers | Push `0x004fbc10`, throttleRamp note | thr → `ctrl+0x20`; not applyAction |
| Bypass writers | SetDriveAxes / setDrivingInputs / MoveToTarget | Ungated direct `+0x614` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store at `entity+0x614` | **High** | Live `movss [ecx+0x614]`; raw + clean |
| Gate: wobj null OR flags&0xC7==0 | **High** | Machine `test …,0xC7` + null jz |
| Null-safety: only final wobj checked | **High** | No intermediate null tests in image |
| No clamp/ramp/push/callee in body | **High** | Pure gate+store+ret4 |
| Sibling byte-identity except store disp | **High** | Parallel read_memory seal |
| Body size 0x2a / end exclusive `0x004f567a` | **High** | Ghidra body range |
| Caller owns signs (Accel −1 / Rev +1) | **High** | DriveControlTick / system map; body passthrough |
| Push is primary thr consumer | **High** | Verified push + throttleRamp |
| Bypass writers skip 0xC7 | **High** | Live SetDriveAxes / setDrivingInputs |
| Per-bit meaning of 0xC7 | **Medium** | Unresolved (shared with SetSteer) |
| Non-input caller English names | **Probable** | Addresses sealed; labels open |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Walk link → if allowed store thr at +0x614 | **Yes** (live decompile) |
| Suppress mask `199` ≡ `0xC7` | **Yes** (immediate in image) |
| No invent steer / HB / push | **Yes** |
| CF changed for sign convention | **No** (document-only) |
| Sibling CF match except store target | **Yes** (byte-level) |

---

## 5. Sign convention cross-check (document only; CF unchanged)

Against `systems/input-drive-control.md` and DriveControlTick plate:

| Action | System map | Caller constants | Body CF |
|---|---|---|---|
| Accelerate held | **−1.0f** | `0xbf800000` / `DAT_00d1bc26` | Passthrough |
| Reverse held | **+1.0f** | `0x3f800000` / `DAT_00d1bc5a` | Passthrough |
| Release / neither | typically 0 | clear/damp path | Passthrough |

**Result:** Clean plate and dual package match system map (**Accelerate negative**). No clean-body CF change required or applied.

---

## 6. Dual residual seals (2026-07-29)

1. **Live ≡ raw** for gate + `+0x614` store.
2. **Sibling machine twin** of SetSteerInput (only `0x614` vs `0x618` displacement).
3. **Body span sealed** `0x004f5650`–`0x004f567a`.
4. **Caller inventory sealed** (16 sites / 9 functions).
5. **Consumer:** Push copies thr to `ctrl+0x20`; applyAction does **not** ramp thr.
6. **Bypass writers:** SetDriveAxes, setDrivingInputs, MoveToTarget proportional thr — **ungated** direct stores (MoveToTarget also *calls* this setter on arrival).

---

## 7. Gaps / open

1. Resolve 0xC7 bit semantics / producers ("lock" unproven).
2. Runtime / differential / bit-exact still open (matrix policy).
3. Full English names for AI/UI callers.
4. Exhaustive direct `+0x614` store scan beyond sealed bypass trio (optional).

**Verdict:** **accept-with-gaps** — dual residual **gate + sibling byte-delta + callers + consumers + bypass** sealed; package **not complete** (runtime/diff).

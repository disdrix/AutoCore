# Review A (reconstruction fidelity): `aa_004f3620` VehicleEntity_SetHandbrake

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3620` |
| **VA** | `0x004f3620` |
| **Canonical name** | `VehicleEntity_SetHandbrake` |
| **Review date** | `2026-07-29` (dual residual **strengthen**) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f3620_VehicleEntity_SetHandbrake.md` |
| **Scratch** | `reviews/a_004f3620.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **ungated** store: `*(u8*)(this+0x61c) = handbrakeOn`. **No** `0xC7` suppress gate (unlike `SetSteerInput` / `SetLongitudinalInput`). Body is store+`ret 4` only.

**Machine proof (`read_memory`):**

```text
0x004f3620:  8a 44 24 04          mov al, [esp+4]
0x004f3624:  88 81 1c 06 00 00    mov [ecx+0x61c], al
0x004f362a:  c2 04 00             ret 4
```

Body **13** bytes: `0x004f3620`–`0x004f362c` inclusive (prior span `~0x004f3626` corrected).

**Semantics (same byte, two uses):**

* **Player:** `Client_Input_DriveControlTick` — Brake held (`DAT_00d1bd5e`) / bounce → `1` @ `0x009235b9`; five clear sites → `0`.
* **NPC sharp:** `MoveToTarget3DPoint` writes `+0x61c` **directly** (not via this setter) when `speed > DAT_00aaa7a4` **and** `|headingErr| > DAT_00a0f710`; arrival arm forces `1`.
* **Consumers:** `PushDriveAxesToController` copies to `ctrl+0x24`; `calcWheelTorque` rear drive torque × **`DAT_00a0f298` = 0.5f** when non-zero. **Not** Havok service-brake torque.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004f3620_*.md` | Unchanged (authoritative pseudocode) |
| Annotated | `docs/reconstruction/raw/aa_004f3620_*.annotated.md` | Machine bytes + span |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetHandbrake.cpp` | Plate: span, 18 call sites |
| Function record | `docs/reconstruction/functions/aa_004f3620_*.md` | Full xref table + bytes |
| Live decompile | Ghidra MCP `0x004f3620` | **≡ raw** |
| Live bytes | `read_memory` len 16 @ entry | **≡ store+ret4** |
| Live xrefs | `get_xrefs_to` / `get_function_callers` | **10** fn / **18** sites |
| Consumers | Push `0x004fbc10`, calcWheelTorque `0x00598040`, `DAT_00a0f298` | Re-decompile + float bytes |
| Bypass | MoveToTarget `0x004fc650`, SetDriveAxes `0x004fbec0` | Live decompile |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store only at `+0x61c` | **High** | Bytes + decompile; no other writes |
| Body span 13 B / end `0x004f362c` | **High** | `read_memory` |
| No `0xC7` gate | **High** | No pointer chain; siblings gated |
| DriveControlTick primary local caller | **High** | Six call sites (5×0, 1×1) |
| MoveToTarget is **direct writer**, not caller | **High** | Live decompile; xrefs omit it |
| PushDriveAxes `+0x61c` → `ctrl+0x24` | **High** | Live decompile |
| Hard-stop `+0x109` forces ctrl HB without reading `+0x61c` | **High** | Push early-return |
| calcWheelTorque rear ×0.5 on non-zero | **High** | `DAT_00a0f298` = `3f000000` |
| Non-input callers (AI / UI stop packs) | **High** (calls) / **Probable** (English names) | 18 sites sealed |
| Handbrake ≡ sharp-assist same byte | **High** | Two writers, one consumer contract |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| single u8 store; ret 4 | Yes |
| No invent gate | Yes |
| No invent clamp / multi-byte | Yes |
| Offset `0x61c` encoded as little-endian dword | Yes (`1c 06 00 00`) |

---

## 5. Gaps / open

1. Runtime / live differential under Brake hold (matrix policy).
2. Bit-exact / full-image instruction diff beyond this 13-byte body (body itself sealed).
3. Original PDB symbol; full English names for every non-input caller.
4. Whether any writer stores values other than 0/1 (consumers are ≠0 tests).
5. Optional: exhaustive binary scan for every direct `+0x61c` store beyond MoveToTarget / SetDriveAxes.

**Verdict:** **accept-with-gaps** — dual residual **machine body + consumers + bypass writers + 18-site callers + ungated CF** sealed; package **not complete** (runtime / package-level diff).

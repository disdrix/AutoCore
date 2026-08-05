# Review A (reconstruction fidelity): `aa_004f5620` VehicleEntity_SetSteerInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5620` |
| **VA** | `0x004f5620` |
| **Canonical name** | `VehicleEntity_SetSteerInput` |
| **Review date** | `2026-07-29` (dual residual refresh) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f5620_VehicleEntity_SetSteerInput.md` |
| **Scratch** | `reviews/a_004f5620.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Gated write of raw steer-axis float at **`this+0x618`**. Resolves linked gate object via three-step pointer chain; writes only if object is null or flag byte at **`wobj+0xb4`** has none of bits **`0xC7`** set. Same gate as `SetLongitudinalInput` (`+0x614`). No clamps, ramps, controller push, or other stores.

Body is ~`0x2b` bytes (instruction-sealed). Callers supply axis sign/magnitude (DriveControlTick hard/soft; MoveToTarget deadband; stop packs).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004f5620_*.md` | Unchanged (authoritative); live ≡ raw |
| Annotated | `docs/reconstruction/raw/aa_004f5620_*.annotated.md` | Prior widths/CF |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetSteerInput.cpp` | ≡ CF |
| Function record | `docs/reconstruction/functions/aa_004f5620_*.md` | Updated |
| Live decompile | Ghidra MCP `0x004f5620` | **≡ raw** |
| Live `read_memory` | `0x004f5620` / sibling `0x004f5650` | Mask imm + store offs sealed |
| Live xrefs | Callers of `0x004f5620` | Six callers |
| MoveToTarget | Decompile `0x004fc650` | Chain + bit identity + deadband callee |
| Bypass writers | `0x004fbec0`, `0x00504c70` | Ungated `+0x618` stores |
| Consumers | applyAction / Push / steer feed | Prior verified + recheck |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store only at `entity+0x618` | **High** | `movss [ecx+0x618]`; no other writes |
| Gate chain `*(*(*(this+4)+4)+this+0xb0)` | **High** | Decompile + instruction sequence |
| Mask immediate **`0xC7`** (byte `test`) | **High** | `f6 80 b4 00 00 00 c7` — not decompiler-only |
| Null `wobj` allows write | **High** | `test eax; jz STORE` |
| Closed gate retains prior | **High** | `jnz RET` skips store |
| Sibling longitudinal identical gate | **High** | Byte-identical body except store `+0x614` |
| MoveToTarget proportional = same chain/bits | **High** | Live decompile; bits ≡ `0xC7` |
| Deadband calls this setter (still gated) | **High** | Callee applies gate |
| No controller push here | **High** | No callees; Push omits steer |
| applyAction consumes `+0x618` as stage-1 target | **High** | Verified steer feed |
| Callers inventory (6) | **High** (calls) / **Probable** (English names) | Live xrefs |
| Bypass: SetDriveAxes / setDrivingInputs ungated | **High** | Live decompile |
| `wobj` type name / layout | **Probable** | Behavior sealed; class open |
| `0xC7` per-bit producers / meanings | **Tentative** | Mask proven; UF open — **not invented** |
| Soft/hard L/R magnitudes on this body | **N/A** | Caller-owned; not in body |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| `p0 = *(this+4); p1 = *(p0+4); wobj = *(p1+this+0xb0)` | Yes |
| Allow if null **or** `(u8 flags & 0xC7)==0` | Yes |
| Store f32 at `+0x618` only when open | Yes |
| No invent thr / HB / clamp / push | Yes |
| `ret 4` thiscall stack arg | Yes |

---

## 5. Gaps / open

1. Runtime / CE force of `wobj+0xb4` bits (matrix policy) — not dual residual CF.
2. Bit-exact image diff beyond this `read_memory` window (optional).
3. `wobj` type identity and flag producers (**UF open — do not invent**).
4. Soft L/R polarity ownership belongs to DriveControlTick plates, not this unit.
5. Optional exhaustive scan of every direct `+0x618` store beyond sealed bypass table.

**Verdict:** **accept-with-gaps** — dual residual **gate chain + mask immediate + sibling parity + MoveToTarget chain identity + callers + bypass writers + consumers** sealed; package **not complete** (runtime / UF bit story).

# Reconstruction review: `aa_004f5620` VehicleEntity_SetSteerInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5620` |
| **VA** | `0x004f5620` |
| **Canonical name** | `VehicleEntity_SetSteerInput` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.md` | Authoritative Ghidra decompile; body ~`0x004f5620`–`0x004f564a`; thiscall; gate `iVar1==0 \|\| (byte & 199)==0`; store `this+0x618` |
| Annotated low-level | `docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.annotated.md` | Widths; mask `199→0xC7`; pointer-chain expansion; short-circuit; no side effects; Probable wobj / lock semantics |
| Exact C++ | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetSteerInput.cpp` | Port-shaped reconstruction of gate + single float store |
| Function record | `docs/reconstruction/functions/aa_004f5620_VehicleEntity_SetSteerInput.md` | Summary, confidence table, open questions, “Not fully complete” |
| Prior verified physics note | `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md` | Earlier sealed decompile of same VA + sibling `0x004f5650`; same gate/store claims |

**Primary claims under review (clean must match low-level):**

1. Three-step pointer chain: `*(*( *(this+4)+4 ) + this + 0xb0)` → `wobj`
2. Gate open iff `wobj == NULL` **OR** `(*(uint8_t*)(wobj+0xb4) & 0xC7) == 0`
3. Gate open → single 4-byte store at `this+0x618` (steer f32 / bit pattern)
4. Gate closed → no write; prior value retained
5. No calls, clamps, ramps, flag mutation, or other stores

**Not re-authored:** No edits to reconstructed-exact, function records, raw, or annotated layers.

**Optional live re-decompile:** Not performed in this review session (Ghidra MCP not invoked here). Static evidence is the raw capture dated 2026-07-23 plus the prior verified note’s identical pseudocode.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw capture § “Raw pseudocode” | Ground truth for CF, gate, store |
| Decompiler mask decimal `199` | Raw + verified note | Confirm `0xC7` and bit set `0x01\|0x02\|0x04\|0x40\|0x80` |
| Byte load of flags | Raw: `*(byte *)(iVar1 + 0xb4)` | Confirm u8 AND, not dword |
| Pointer associativity | Raw tool notes + annotated §3 | Confirm entity-relative final address `p1 + this + 0xb0` |
| Side-effect bounds | Raw tool notes; annotated §5; verified §2 | No extra stores/calls/FP math |
| Sibling parity (context only) | Verified note / function record | Same gate at `0x004f5650` writing `+0x614` — not required for this unit’s body seal |
| Clean implementation | `VehicleEntity_SetSteerInput.cpp` | Line-by-line map to annotated/raw |

No runtime / CE / live gate exercise. No instruction-byte measurement of body end.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Raw | Annotated | Clean C++ |
|---|---|---|---|
| Load chain | 3 dword loads | Same expanded steps | `p0` / `p1` / `wobj` with offsets `0x4`, `0x4`, `0xb0` |
| Branch shape | `if (null \|\| (flags&mask)==0) store` | Same (also shown as inverted early-return form) | Same allow-path `if` |
| Closed gate | Fall through / no store | Retain `+0x618` | Comment + no else write |
| Return | `return` | Yes | Implicit end |

Equivalent boolean polarity to the verified note’s “suppress if non-null **and** bits set” form. No extra branches in clean.

### 3.2 Gate: clean ≡ annotated ≡ raw

| Element | Raw | Clean | Match |
|---|---|---|---|
| Null allow | `iVar1 == 0` | `wobj == nullptr` | **Yes** |
| Mask | decimal `199` | `kSteerLongitudinalLockMask = 0xC7u` | **Yes** (`199 == 0xC7`) |
| Flag access | `*(byte *)(iVar1 + 0xb4)` | `*(wobj + kOffWobjFlags)` on `uint8_t*` | **Yes** (u8 load) |
| Compare | `(… & 199) == 0` | `(… & mask) == 0` | **Yes** |
| Short-circuit | C `\|\|` | C++ `\|\|` | **Yes** — flag byte not read when `wobj` null |

Bit expansion `0x01|0x02|0x04|0x40|0x80` is documented consistently; clean does not invent per-bit names.

### 3.3 Store: clean ≡ annotated ≡ raw

| Element | Raw | Clean | Match |
|---|---|---|---|
| Target | `param_1 + 0x618` | `base + kOffSteerInput` (`0x618`) | **Yes** |
| Width | 4 bytes (`undefined4`) | `float` assignment (4-byte f32) | **Yes** (semantic type per annotated) |
| Value | `param_2` bit pattern | `steerInput` | **Yes** — no cast that alters bits under normal IEEE-754 float pass-through |
| Only store | Sole write in body | Sole write in body | **Yes** |

### 3.4 Absences (negative claims)

Confirmed absent in raw **and** clean:

- Clamps / min / max / abs / deadzone
- Function calls
- Writes to `+0x614`, `+0x61c`, controller, or `wobj` flags
- FP arithmetic (only memory MOV of axis value)

### 3.5 Signature typing (annotated layer)

Raw `int` / `undefined4` → annotated/clean `VehicleEntity*` / `float` is a **documented decompiler correction**, not a behavioral invent. Acceptable for reconstructed-exact.

### 3.6 Function record honesty

Record correctly marks overall gate+store **High**, lock-bit / wobj identity **Probable**, runtime **Open**, and completion **Not fully complete**. That status is consistent with the evidence; it does not oversell the reconstruction.

---

## 4. Discrepancies or improvements needed

None that break gate/store fidelity. Minor notes only:

| Item | Severity | Notes |
|---|---|---|
| Intermediate nulls `p0`/`p1` | None (faithfulness) | Raw also does not null-check intermediate links; clean correctly mirrors that (crash-parity if chain is broken). |
| `float` vs raw `undefined4` store | Cosmetic / platform | On x86 IEEE-754, assigning `float` matches retail bit-pattern store for caller-supplied f32. Hyper-exact bit-blit could use `uint32_t` + `memcpy`/store; **not required** given annotated f32 seal. |
| Semantic naming in comments | Doc only | “lock object”, “wheel-control” appear as narrative; code treats opaque `uint8_t*`. Function record already labels wobj identity **Probable** — keep comments from implying Confirmed class type. |
| Body end `~0x004f564a` | Meta | Approximate across all layers; not re-measured. Does not affect algorithm reconstruction. |
| Sibling not in this `.cpp` | Out of scope | Longitudinal twin is separate unit; clean correctly only writes `+0x618`. |
| No instruction-level / binary size seal | Gap (see §5) | Static decompile parity only. |

**No revision required** for control flow, mask, offsets, or store target.

---

## 5. What remains uncertain

These are **environment / semantic** gaps, not clean-vs-raw mismatches:

1. **`wobj` type identity** — object at entity-relative slot remains Probable (wheel-control / subsystem), not Confirmed.
2. **Per-bit meanings** of `0xC7` on `wobj+0xb4` — which retail systems set/clear each bit.
3. **Producers / clearers** of the lock flags — not in this unit’s body.
4. **Runtime verification** — no live confirm that known lock states suppress `+0x618` writes.
5. **Binary body bounds** — end address approximate; no re-measure / instruction dump in this artifact set.
6. **Bypass writers of `+0x618`** — inventory of sites that store steer without this setter (e.g. proportional path notes) is incomplete; out of body scope but relevant for full port parity.
7. **Live re-decompile this session** — not re-fetched from Ghidra; review trusts the filed raw capture + verified note agreement.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:**

- Clean C++ reproduces raw/annotated control flow, pointer chain, short-circuit gate, mask `0xC7`, byte flag load, and sole store to `this+0x618` without inventing clamps, ramps, or extra side effects.
- Annotated corrections (`float`, `0xC7`, widths) are applied consistently and labeled.
- Function record confidence and open questions match the actual seal level of the body.

**Gaps (do not block acceptance of the setter reconstruction):**

- No runtime / CE confirmation of gate under real lock conditions.
- Lock-bit producers and `wobj` class name unsealed.
- Body size / instruction-level seal not re-done.
- Optional live Ghidra re-decompile not performed by this reviewer (static dual-source decompile agreement used instead: raw 2026-07-23 + prior verified note).

**Not reject:** No material fidelity error between clean and low-level.

**Not needs-revision:** No required change to `VehicleEntity_SetSteerInput.cpp` for faithfulness.

---

## 7. Reviewer role statement

This review judges **faithfulness of the reconstructed-exact C++ to the low-level evidence** (raw decompile + annotated widths/control flow), cross-checked against the prior verified physics note and the function record’s claims. It does **not** re-author the reconstruction, validate full retail lock semantics, or certify a live-game port beyond the gated store itself.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Clean gate matches raw (`null \|\| (u8&0xC7)==0`) | **Pass** |
| Clean store `+0x618` only | **Pass** |
| No invented clamps / calls / extra stores | **Pass** |
| Annotated types consistent with clean | **Pass** |
| Function record does not overclaim completion | **Pass** |
| Runtime / lock-bit story complete | **Open** (documented gap) |
| Verdict | **accept-with-gaps** |

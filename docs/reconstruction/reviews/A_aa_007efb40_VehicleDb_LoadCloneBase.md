# Review A (reconstruction fidelity): `aa_007efb40` VehicleDb_LoadCloneBase

| Field | Value |
|---|---|
| **Stable ID** | `aa_007efb40` |
| **VA** | `0x007efb40` |
| **Canonical name** | `VehicleDb_LoadCloneBase` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007efb40_VehicleDb_LoadCloneBase.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Clonebase vehicle-spec DB loader at **0x7efb40**. **Ghidra decompilation failed** — clean is a stub (`Error: Decompilation failed`); dual review rests on xrefs / bind sites / setup consumers, not a recovered body. Documented bind column names include **`sinVehicleFlags`** (UTF-16 `0xa92f24`, store path → **VehSpec+0x5f0** i16/byte), `rlSuspension*`, `rlBrakesMaxTorque*`, `rlSteering*`, aero columns, COM recordset path near `0x7f3020`. Feeds `Vehicle_Build*Descriptor` / framework assembly. Not a runtime tick function.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007efb40_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007efb40_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleDb_LoadCloneBase.cpp` |
| Function record | `docs/reconstruction/functions/aa_007efb40_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `VA is vehicle clonebase DB load entry` | High | Xrefs + name binds |
| `sinVehicleFlags → VehSpec+0x5f0` | High | fn_vehicleFlags_bits |
| `Feeds setup builders (steer/brake/susp/aero)` | High | setup-field-mapping |
| `Full recovered body / CF` | Low | Decomp failed |
| `Complete column→offset table from this VA alone` | Low | Needs asm/bind walk |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| No invent full decompiled body | Yes — stub preserved |
| Bind-site claims externalized to verified notes | Yes |

---

## 5. Gaps / open

1. Re-decompile or asm-walk 0x7efb40–0x7f3xxx bind block.
2. Publish complete column list with store offsets.
3. Do not treat stub clean as behavior-complete.

**Verdict:** accept-with-gaps

# Review A (reconstruction fidelity): `aa_0060a820` Net_UnpackGhostUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060a820` |
| **VA** | `0x0060a820` |
| **Canonical name** | `Net_UnpackGhostUpdate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060a820_Net_UnpackGhostUpdate.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client ghost **delta/update unpack** for networked objects (plate `unpacking update from net … ghost`). Signature `__thiscall(this, bitstream/ctx, flags)`. Reads via `BitStream_readFlag` / `readBits` / `readInt`; dispatches object-field patches including combat/state paths through callees `FUN_005172d0`, `FUN_005208e0`, `FUN_00521440`/`FUN_00521480`, and target resolve `CVOGReaction_ResolveObjectTarget`. Sibling of `Net_UnpackGhostUpdate_005b17b0` (base GhostObject path) and `VehicleNet_UnpackGhostVehicle` (vehicle-specialized). ~398-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060a820_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0060a820_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_UnpackGhostUpdate.cpp` |
| Function record | `docs/reconstruction/functions/aa_0060a820_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Ghost delta unpack via BitStream read family | High | Clean body |
| Calls CVOGReaction_ResolveObjectTarget on some paths | High | Callee list |
| Not the vehicle-only UnpackGhostVehicle | High | Distinct VA vs 005f7720 |
| Full per-mask field map sealed | Medium | Large body; residual FUN_* |
| Exact ghost mask → field table | Medium | Needs mask ledger cross-ref |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| readFlag/Bits/Int → branch patches → resolve helpers | Yes |
| Does not invent pack-side writes | Yes |

---

## 5. Gaps / open

1. Seal combat/position mask bit → offset table vs GHOST_* constants.
2. Diff vs VehicleNet_UnpackGhostVehicle ownership of hardpoints.
3. Bit-exact vs retail deferred.

**Verdict:** **accept-with-gaps**

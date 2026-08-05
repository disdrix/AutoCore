# Review A (reconstruction fidelity): `aa_004de550` CVOGReaction_SpawnObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de550` |
| **VA** | `0x004de550` |
| **Canonical name** | `CVOGReaction_SpawnObject` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004de550_CVOGReaction_SpawnObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **world object spawn** for reaction context `this`:

1. Resolve via `FUN_004e23d0(objectId, instanceId)`; take result+0xc object ptr; null → 0.
2. If vtable `+0x214` alive-check fails: log path, clear bit0 at +0x17d; optional bit12 spawn-flag early return 1; position/velocity short path.
3. Else set bit1 at +0x17d; call vtable `+0x2a4` with `this+0xe4e8` spawn params.
4. If clone type != 0x36 (repair station): init helpers, vtable +0x244/+0x240/+0xfc, state 3, +0x45=-1, vehicle ref cleanup.
5. Type 0x36: alternate vtable +0x1ec path.
6. Return 1 on success paths.

Plate algorithm comments in raw match decompile structure (some bit labels Probable).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004de550_CVOGReaction_SpawnObject.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_SpawnObject.cpp` |
| System map | `docs/reconstruction/systems/missions-progression.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(ctx, objectId, instanceId) → 0/1` | **High** | Raw |
| Resolve FUN_004e23d0 → +0xc | **High** | First steps |
| Alive check vtable +0x214 | **High** | Branch |
| Spawn params at ctx+0xe4e8 | **High** | Pass to +0x2a4 |
| Type 0x36 special path | **High** | Explicit |
| +0x17d flag bits | **Probable** | Bit roles inferred |
| Vehicle ref vtables | **Tentative** | Unnamed slots |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null resolve → 0 | **Yes** |
| Alive vs spawn body | **Yes** |
| Type != 0x36 init chain | **Yes** |
| Return 1 success | **Yes** |

---

## 5. Gaps

1. FUN_004e23d0 / FUN_004dbef0 / FUN_00518370 semantics.
2. Exact meaning of +0x17d bitfield.
3. Whether server spawn is authoritative and this is client apply only.
4. Runtime spawn reaction capture.

**Verdict:** accept-with-gaps.

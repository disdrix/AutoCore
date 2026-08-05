# Review A (reconstruction fidelity): `aa_0060a230` Net_PackInitialCharacterUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060a230` |
| **VA** | `0x0060a230` |
| **Canonical name** | `Net_PackInitialCharacterUpdate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060a230_Net_PackInitialCharacterUpdate.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Server/client **initial character ghost pack** (plate `Packing initial update for character %I64` / `Can't save ghost data for character!`). `__thiscall` builds first-scope bitstream via `BitStream_writeBits` / `writeFlag` / `writeInt` (~28 writeBits sites). Large create-shaped payload (~197 non-empty decompiler lines). Pairs with unpack siblings; not the per-tick delta path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060a230_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0060a230_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_PackInitialCharacterUpdate.cpp` |
| Function record | `docs/reconstruction/functions/aa_0060a230_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Initial character pack (create-shaped) | High | Plate strings + body |
| Heavy BitStream_writeBits/Flag/Int use | High | Callee counts |
| Error string if ghost data unsaveable | High | Embedded string |
| Full field layout sealed | Medium | Large residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| writeBits/Flag/Int cascade → return | Yes |
| Not delta-only mask pack | Yes |

---

## 5. Gaps / open

1. Document initial vs delta split vs Net_UnpackGhostUpdate.
2. Seal character field order against CreateFromPacket.

**Verdict:** **accept-with-gaps**

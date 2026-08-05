# Review A (reconstruction fidelity): `aa_007dfd10` Named_tCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dfd10` |
| **VA** | `0x007dfd10` |
| **Canonical name** | `Named_tCharacter` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007dfd10_Named_tCharacter.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB table loader **`tCharacter`**. Bulk character definition table via DBReader (same family as tCloneBase/tDamage). Supplies character templates for create/load. Gate `DAT_00d1793c` empty path. Not net ghost pack.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007dfd10_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007dfd10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_tCharacter.cpp` |
| Function record | `docs/reconstruction/functions/aa_007dfd10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tCharacter table loader | High | Name + pattern |
| Shared DBReader helpers | High | Callees |
| Full column map | Medium | 410-line residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → columns → map insert → close | Yes |

---

## 5. Gaps / open

1. Publish character column ledger.

**Verdict:** **accept-with-gaps**

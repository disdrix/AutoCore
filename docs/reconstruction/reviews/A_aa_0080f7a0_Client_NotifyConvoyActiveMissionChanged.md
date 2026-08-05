# Review A (reconstruction fidelity): `aa_0080f7a0` Client_NotifyConvoyActiveMissionChanged

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080f7a0` |
| **VA** | `0x0080f7a0` |
| **Canonical name** | `Client_NotifyConvoyActiveMissionChanged` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080f7a0_Client_NotifyConvoyActiveMissionChanged.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_NotifyConvoyActiveMissionChanged.cpp` |
| Raw | `docs/reconstruction/raw/aa_0080f7a0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Alternate path for convoy-leader active-mission change notification. Toast strings: 'has changed your active mission to' / 'Your Convoy Leader'. Sibling of Client_NotifyActiveMissionChanged.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Convoy leader mission change toast | High | Strings |
| Does not set active mission itself (notify path) | High | Plate alternate-path |
| Pairs NotifyActiveMissionChanged family | High | Prior duals |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Format leader/mission toast → show | Yes |

---

## 4. Gaps

1. When this path vs NotifyActiveMissionChanged is chosen.
2. Whether any mission hash write occurs here.

**Verdict:** **accept-with-gaps**

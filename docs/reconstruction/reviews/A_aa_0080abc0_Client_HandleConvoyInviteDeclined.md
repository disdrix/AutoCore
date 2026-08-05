# Review A (reconstruction fidelity): `aa_0080abc0` Client_HandleConvoyInviteDeclined

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080abc0` |
| **VA** | `0x0080abc0` |
| **Canonical name** | `Client_HandleConvoyInviteDeclined` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080abc0_Client_HandleConvoyInviteDeclined.md` |
| **System tag** | `auth-login` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_HandleConvoyInviteDeclined.cpp` |
| Raw | `docs/reconstruction/raw/aa_0080abc0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Convoy invitation failure handler. Maps decline reason codes to localized strings (self-invite, full convoy, already in convoy, enemy, pending, busy, non-leader) and shows chat toasts. Reason enum often at packet+0x14.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Reason→string switch/map | High | Body + strings |
| Chat toast display only | High | FUN_007fdfb0 family |
| Does not alter convoy roster | High | No roster mutators |
| Reason at packet+0x14 (plate) | Probable | Plate notes |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Map reason code → toast string → show | Yes |

---

## 4. Gaps

1. Full reason enum values sealed vs wire.
2. Opcode binding for handler dispatch.

**Verdict:** **accept-with-gaps**

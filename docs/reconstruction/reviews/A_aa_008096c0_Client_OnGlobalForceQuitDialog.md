# Review A (reconstruction fidelity): `aa_008096c0` Client_OnGlobalForceQuitDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_008096c0` |
| **VA** | `0x008096c0` |
| **Canonical name** | `Client_OnGlobalForceQuitDialog` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008096c0_Client_OnGlobalForceQuitDialog.md` |
| **System tag** | `auth` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnGlobalForceQuitDialog.cpp` |
| Raw | `docs/reconstruction/raw/aa_008096c0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Global disconnect / force-quit dialog: multiple logins, GM kick/ban. Accept returns to login screen. Strings: forced to quit due to multiple logins.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multiple-logins force-quit string | High | String |
| Accept → login screen | High | Plate |
| GM kick/ban messaging family | High | Plate |
| Dialog UX not reconnect logic | High | Body role |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show force-quit dialog → on accept go login | Yes |

---

## 4. Gaps

1. Full reason variants table.
2. Opcode/dispatch binding for global force quit.

**Verdict:** **accept-with-gaps**

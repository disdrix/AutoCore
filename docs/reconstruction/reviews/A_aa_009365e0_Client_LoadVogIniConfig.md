# Review A (reconstruction fidelity): `aa_009365e0` Client_LoadVogIniConfig

| Field | Value |
|---|---|
| **Stable ID** | `aa_009365e0` |
| **VA** | `0x009365e0` |
| **Canonical name** | `Client_LoadVogIniConfig` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009365e0_Client_LoadVogIniConfig.md` |
| **System tag** | `auth` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_LoadVogIniConfig.cpp` |
| Raw | `docs/reconstruction/raw/aa_009365e0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Parse VOG.ini: USERNAME/PASSWORD/AUTHSERVERIP/AUTHSERVERID/display mode and related boot settings. fopen("VOG.ini") path.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| fopen VOG.ini | High | String |
| AUTHSERVERIP / AUTHSERVERID keys | High | Strings |
| USERNAME/PASSWORD keys | High | Plate |
| Display mode settings | High | Plate |
| Boot config only | High | No sector game logic |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Open INI → parse keys → fill client config | Yes |

---

## 4. Gaps

1. Full key list and defaults.
2. Password storage/obfuscation details.

**Verdict:** **accept-with-gaps**

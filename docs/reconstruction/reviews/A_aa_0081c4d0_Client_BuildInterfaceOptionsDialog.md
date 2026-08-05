# Review A (reconstruction fidelity): `aa_0081c4d0` Client_BuildInterfaceOptionsDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0081c4d0` |
| **VA** | `0x0081c4d0` |
| **Canonical name** | `Client_BuildInterfaceOptionsDialog` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0081c4d0_Client_BuildInterfaceOptionsDialog.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_BuildInterfaceOptionsDialog.cpp` |
| Raw | `docs/reconstruction/raw/aa_0081c4d0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Build interface-options dialog tree (i_o_ui_2d_*.xml): quickbar drag-requires-shift, auto-set new mission active, graphics/UI toggles. Large CreateChildWidgets pattern; client settings UI only.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| XML set i_o_ui_2d_* title/icon/close | High | String literals |
| Includes Quickbar Drag Requires Shift | High | String evidence |
| Includes Auto-set New Mission Active | High | String evidence |
| No server packet send in builder | High | UI construct only |
| Large ~500-line widget tree | High | Body size |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Repeated child-widget create + XML load CF preserved | Yes |
| No invented modernizations | Yes |

---

## 4. Gaps

1. Per-toggle bind offsets to graphics INI keys not fully sealed.
2. Exact save path for options bits open.

**Verdict:** **accept-with-gaps**

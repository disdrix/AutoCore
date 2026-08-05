# Review A (reconstruction fidelity): `aa_0093a940` Client_RefreshOpenMissionUiWindows

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a940` |
| **VA** | `0x0093a940` |
| **Canonical name** | `Client_RefreshOpenMissionUiWindows` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093a940_Client_RefreshOpenMissionUiWindows.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_RefreshOpenMissionUiWindows.cpp` |
| Raw | `docs/reconstruction/raw/aa_0093a940_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Bulk refresh/hide of open mission-related HUD panels after mission state change. For each panel pointer (client+0x1030, +0x1074, +0x1094, +0x1068, nested +0x1040/+0x1034 children): if non-null && vtbl+0x3d8 visible → call panel-specific refresh (FUN_00888de0, vtbl+0x448, FUN_008c0d10, FUN_008e55e0, …). Called from CompleteObjective path and RecvCompleteDynamicObjective. Re-entrancy sensitive with MSXML.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Walks fixed client panel slots 0x1030/74/94/68… | High | Body |
| Visibility probe vtbl+0x3d8 | High | Pattern |
| Per-panel refresh callees | High | Calls |
| Triggered after objective complete paths | High | Plate |
| May re-enter XML UI load | Medium | Plate warning |
| No mission grant logic | High | UI only |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| For each slot: null check → visible? → refresh | Yes |

---

## 4. Gaps

1. Identity of each panel type at offsets.
2. Full list of refresh FUN_* endpoints.
3. MSXML re-entrancy crash conditions.

**Verdict:** **accept-with-gaps**

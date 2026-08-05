# Review A (reconstruction fidelity): `aa_009306a0` Client_RefreshMissionDialogChrome

| Field | Value |
|---|---|
| **Stable ID** | `aa_009306a0` |
| **VA** | `0x009306a0` |
| **Canonical name** | `Client_RefreshMissionDialogChrome` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009306a0_Client_RefreshMissionDialogChrome.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_RefreshMissionDialogChrome.cpp` |
| Raw | `docs/reconstruction/raw/aa_009306a0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** If dialog chrome at game+0x10b0 is open (vtbl+0x3d8 visible), call FUN_008a05a0 to refresh it. Tiny UI helper used after mission state changes.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Chrome root game+0x10b0 | High | Body |
| Visible probe vtbl+0x3d8 | High | Body |
| Refresh via FUN_008a05a0 | High | Body |
| No-op if missing/hidden | High | Body |
| UI only | High | No mission complete |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if chrome && visible: FUN_008a05a0() | Yes |

---

## 4. Gaps

1. FUN_008a05a0 exact refresh duties.
2. Relationship to +0x107c mission dialog root.

**Verdict:** **accept**

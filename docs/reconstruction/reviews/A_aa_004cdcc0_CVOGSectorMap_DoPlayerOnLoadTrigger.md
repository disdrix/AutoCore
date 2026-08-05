# Review A (reconstruction fidelity): `aa_004cdcc0` CVOGSectorMap_DoPlayerOnLoadTrigger

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdcc0` |
| **VA** | `0x004cdcc0` |
| **Canonical name** | `CVOGSectorMap_DoPlayerOnLoadTrigger` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004cdcc0_CVOGSectorMap_DoPlayerOnLoadTrigger.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fire m_coidPerPlayerLoadTrigger: resolve TFID @ sector **+0xE7E0/+0xE7E4** via FUN_004bb1c0; if found, dual-base vtbl **+0x114** activate/fire.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cdcc0_CVOGSectorMap_DoPlayerOnLoadTrigger.md` |
| Annotated | `docs/reconstruction/raw/aa_004cdcc0_CVOGSectorMap_DoPlayerOnLoadTrigger.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_DoPlayerOnLoadTrigger.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cdcc0_CVOGSectorMap_DoPlayerOnLoadTrigger.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `TFID pair at +0xE7E0 / +0xE7E4` | **High** | Loads |
| `Lookup FUN_004bb1c0; null → return` | **High** | No fire if missing |
| `Fire vtbl+0x114 on dual-base inner object` | **High** | Indirect call |
| `No once-flag (unlike creator)` | **High** | Contrast sibling |
| `Caller AddCharacter always` | **High** | Sibling plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Lookup + conditional fire | **Yes** |
| No invented once-gate | **Yes** |

---

## 5. Gaps / open

1. FUN_004bb1c0 exact (global vs sector object table).
2. What reaction graph +0x114 runs.
3. Server mission list mapping for per-player load.

**Verdict:** **accept-with-gaps**

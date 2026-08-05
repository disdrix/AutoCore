# Review A (reconstruction fidelity): `aa_004cdd20` CVOGSectorMap_DoCreatorLoadTrigger

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdd20` |
| **VA** | `0x004cdd20` |
| **Canonical name** | `CVOGSectorMap_DoCreatorLoadTrigger` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004cdd20_CVOGSectorMap_DoCreatorLoadTrigger.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Once-per-map fire of m_coidCreatorLoadTrigger: if sector **+0x74** already set return; else set +0x74=1, stamp **+0x6C**=GetTickCount(), resolve TFID **+0xE7E8/+0xE7EC**, fire vtbl+0x114.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cdd20_CVOGSectorMap_DoCreatorLoadTrigger.md` |
| Annotated | `docs/reconstruction/raw/aa_004cdd20_CVOGSectorMap_DoCreatorLoadTrigger.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_DoCreatorLoadTrigger.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cdd20_CVOGSectorMap_DoCreatorLoadTrigger.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Once flag +0x74 early-out` | **High** | Prevents re-fire |
| `Stamp +0x6C = GetTickCount on first fire` | **High** | Store |
| `TFID +0xE7E8 / +0xE7EC` | **High** | Distinct from player trigger |
| `Same fire vfunc +0x114 pattern as player` | **High** | Shared activation |
| `Caller AddCharacter when count condition` | **High** | Not every add |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Once gate + stamp | **Yes** |
| Lookup + fire | **Yes** |

---

## 5. Gaps / open

1. Stamp +0x6C consumers.
2. Creator vs player mission content split in assets.
3. Server instance-start hook parity.

**Verdict:** **accept-with-gaps**

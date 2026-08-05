# Review A (reconstruction fidelity): `aa_00509680` CVOGLootGenerator_GetTypeFromIDPrefix_00509680

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509680` |
| **VA** | `0x00509680` |
| **Canonical name** | `CVOGLootGenerator_GetTypeFromIDPrefix_00509680` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00509680_CVOGLootGenerator_GetTypeFromIDPrefix_00509680.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Loot prefix sibling returning **byte at entry+0x10** (not pointer). Same map/types/lookups. Miss → type 0 then switch default returns **0**. Distinct from string siblings (+0x11/+0x44) and +0x70 struct sibling. Useful as compact type/flag read after prefix resolve.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00509680_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00509680_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetTypeFromIDPrefix_00509680.cpp` |
| Function record | `docs/reconstruction/functions/aa_00509680_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Returns *(u8*)(entry+0x10) | High | Body |
| Default returns 0 | High | Body |
| Shared DAT_00b041dc map | High | Body |
| Not the primary GetType dword API alone | Medium | Family overlap |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| lower_bound → switch → load byte +0x10 or 0 | Yes |

---

## 5. Gaps / open

1. Confirm +0x10 byte vs +0x10 type dword on map node (different structs).

**Verdict:** **accept-with-gaps**

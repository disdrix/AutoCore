# Review A (reconstruction fidelity): `aa_004dcb80` CVOGSectorMap_SaveToFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dcb80` |
| **VA** | `0x004dcb80` |
| **Canonical name** | `CVOGSectorMap_SaveToFile` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004dcb80_CVOGSectorMap_SaveToFile.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sector map **save-to-file** (`CVOGSectorMap::SaveToFile`). Large ~959-line writer with heavy `fwrite`/`ftell` (40+ fwrite sites). Validates object positions (`weird location` log) and writes map binary (`garbagefile` debug string). Editor/tooling path more than live sector sim — still a named manager with real CF for map persistence RE.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004dcb80_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004dcb80_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_SaveToFile.cpp` |
| Function record | `docs/reconstruction/functions/aa_004dcb80_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| SaveToFile plate string | High | Embedded |
| Heavy fwrite map serialization | High | Callee counts |
| Weird location validation log | High | String |
| Full map binary format sealed | Medium | Large residual |
| Live server path vs editor | Medium | Call-site open |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open file → walk objects → fwrite fields → close | Yes |

---

## 5. Gaps / open

1. Document map file header/version.
2. Diff vs CVOGSectorMap_LoadMapFile dual if present.

**Verdict:** **accept-with-gaps**

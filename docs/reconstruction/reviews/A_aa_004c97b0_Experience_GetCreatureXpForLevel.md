# Review A (reconstruction fidelity): `aa_004c97b0` Experience_GetCreatureXpForLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c97b0` |
| **VA** | `0x004c97b0` |
| **Canonical name** | `Experience_GetCreatureXpForLevel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c97b0_Experience_GetCreatureXpForLevel.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Lookup **creature kill-base XP** for a creature level key from `tCreatureExperienceLevel`. `__cdecl(nCreatureLevel) → uint`. Lazy-inits via `Experience_EnsureCreatureXpTableLoaded_INFERRED` when `g_nCreatureXpTableReady==0` (checked before **and** after lower_bound). Map lower_bound on `DAT_00b04270`; returns node `+0x10` (`intExperience`) or **0** if missing/end. Used by `Experience_LevelDiffBaseXp` and kill XP path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c97b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004c97b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_GetCreatureXpForLevel.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c97b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Lazy table ensure + lower_bound by level | High | Clean body + XP.md |
| XP at map entry +0x10 | High | Plate + docs/XP.md |
| Missing → 0 (not 0x7FFFFFFF) | High | Clean return |
| Double ready-flag check (before/after) | High | Decompiler CF |
| Map root DAT_00b04270 sealed identity | Medium | Global name INFERRED |
| extraout_EAX / unaff_EDI residuals | Medium | Decompiler artifacts |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| ready==0 → Ensure; lower_bound; +0x10 or 0 | Yes |
| Does not apply grey/hard level-diff | Yes |

---

## 5. Gaps / open

1. Seal full tCreatureExperienceLevel payload (126 rows) for worked kill examples.
2. Confirm ready-flag write site (loader, not this helper).
3. Bit-exact vs retail deferred.

**Verdict:** **accept-with-gaps**

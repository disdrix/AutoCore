# Review A (reconstruction fidelity): `aa_0059df20` Mission_ComputeObjectiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059df20` |
| **VA** | `0x0059df20` |
| **Canonical name** | `Mission_ComputeObjectiveCredits` |
| **Review date** | `2026-07-23`; residual refresh `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure mission-complete **credit delta** calculator (`__fastcall` objective in ECX). Sibling of `Mission_ComputeObjectiveXp`. Formula: `base = (float)tQuestBaseCredits[mission.wTargetLevel@+0x11c].intBaseCredits`; `frac = tQuestCreditsLookup[obj.wCreditsIndex@+0x13e].rlLevelCredits`; return `(int)FISTP_chop(ceil(fCreditScaler@obj+0x148 * frac * base))`. Lazy-loads both maps; lower_bound miss / end sentinel → **0**. **Does not** null-check `obj+0x14c` mission def (unlike XP calc). Caller CompleteObjective FINAL path **adds** result into char currency `+0x720` (64-bit carry `+0x724`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| Annotated | `docs/reconstruction/raw/aa_0059df20_Mission_ComputeObjectiveCredits.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_ComputeObjectiveCredits.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| Residual scratch | `docs/reconstruction/reviews/a_0059df20.md` |
| Ensure base | `0x00512870` EnsureQuestBaseCreditsLoaded |
| Ensure lookup | `0x00512830` EnsureQuestCreditsLookupLoaded |
| Map lower_bound | `0x0050f940` Map_LowerBoundFindByIntKey |
| Ghidra re-decompile + image bytes at `0x0059dfca` | 2026-07-29 residual wave |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Pure delta return; no currency write` | High | Body |
| `TargetLevel mission+0x11c → base map` | High | Key |
| `CreditsIndex obj+0x13e → frac map` | High | Key |
| `CreditScaler obj+0x148` | High | Multiply |
| `ceil then FISTP RC=chop (Ghidra ROUND)` | **High** | image `OR AH,0x0C` after ceil |
| `Map miss → 0` | High | End sentinel |
| `No null-check mission def` | High | Differs from XP |
| `FINAL-only grant caller (CompleteObjective)` | High | UI toast also **reads** for display |
| `Ensure* @ 0x00512870 / 0x00512830` | **High** | residual sealed |
| `Node key+0x0C value+0x10 flag+0x15` | **High** | Map_LowerBoundFindByIntKey |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Ensure-load → lower_bound base → frac → ceil/FISTP | Yes |
| No invented currency store | Yes |

---

## 5. Gaps / open (after residual)

1. Full WAD row bit-exact dump (schema sealed; samples match plate).
2. Runtime / live complete compare; image diff.
3. AutoCore clamps negative scaler to 0 (client can return negative) — port policy.

**Verdict:** **accept-with-gaps** — dual residual Ensure*, map layout, ROUND/FISTP, null reachability sealed; only verification/runtime + full table dump remain.

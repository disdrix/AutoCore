# Review A (reconstruction fidelity): `aa_0060e9e0` CVOGObjectiveRequirement_Patrol_GetSomething

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e9e0` |
| **VA** | `0x0060e9e0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetSomething` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Trivial getter: returns dword at **req+0x28** (ContinentCBID / primary field also written by GetTarget to *out). __fastcall in decompiler (likely this in ECX).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060e9e0_CVOGObjectiveRequirement_Patrol_GetSomething.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_GetSomething.cpp` |
| GetTarget | `writes *out = *(req+0x28)` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Load +0x28 return | **High** | single instruction body |
| Same field as ContinentCBID in GetFlags/GetTarget | **High** | cross-unit |
| Canonical name still placeholder GetSomething | **High** | needs rename |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Load/return | **Yes** |

---

## 5. Gaps

1. Prefer name Patrol_GetContinentCBID or GetPrimaryField once callers sealed.

**Verdict:** accept-with-gaps.

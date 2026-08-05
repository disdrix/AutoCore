# Review A (reconstruction fidelity): `aa_0060e260` CVOGObjectiveRequirement_Patrol_GetFlags

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e260` |
| **VA** | `0x0060e260` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetFlags` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Despite the name, body is an **XML serialize dump** to FILE*: writes `<Requirement type="patrol">` with AutoComplete/Distance, AutoFail/Distance, ContinentCBID, GenericTargetCOID list (+0x30 pairs, count +0xd0), and Laps. Not a bitflag getter.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_GetFlags.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| fprintf XML schema strings | **High** | literal tags |
| AutoComplete byte +0x10; dist float +0x14 | **High** | raw |
| AutoFail byte +0x18; dist float +0x1c | **High** | raw |
| ContinentCBID dword +0x28 | **High** | raw |
| Targets at +0x30 step 8; count +0xd0 | **High** | loop |
| Laps fprintf present | **Probable** | format string; some arg recovery weak |
| Name GetFlags is misnomer vs SerializeXml | **High** | behavior is dump |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Header/fields loop/footer | **Yes** |

---

## 5. Gaps

1. Laps field source offset (fprintf arg missing in decomp).
2. Whether production uses this dump or mission-tool only.

**Verdict:** accept-with-gaps.

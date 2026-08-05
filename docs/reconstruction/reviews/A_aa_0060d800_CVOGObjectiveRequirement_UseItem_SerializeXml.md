# Review A (reconstruction fidelity): `aa_0060d800` CVOGObjectiveRequirement_UseItem_SerializeXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d800` |
| **VA** | `0x0060d800` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_SerializeXml` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060d800_CVOGObjectiveRequirement_UseItem_SerializeXml.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

COM/XML **property walk** loading UseItem fields by wide-string key: PrimaryCOID/CBID/Destroy/InWorld/UseText/GiveAtStart/MultipleUse/Explode/CompletedItem, Secondary*, Progress*, Complete*, RepeatCount→+0x50, ContinentID→+0x54. Heavy unaff_* register noise; field assignment map from string compares is high confidence.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060d800_CVOGObjectiveRequirement_UseItem_SerializeXml.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_UseItem_SerializeXml.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tag→offset map (listed strings) | **High** | wcsicmp chain |
| PrimaryCOID 64-bit-ish +0x10/+0x14; 0 → -1 | **High** | raw |
| RepeatCount +0x50; ContinentID +0x54 | **High** | raw |
| Bool tags via _wtol==1 | **High** | raw |
| Text fields via helper FUN_0060d2e0/340/3a0/400 | **Probable** | helpers |
| Default PrimaryUseText if +0x20==0 | **Probable** | tail |
| unaff_EBP/ESI/EBX iteration ABI | **Tentative** | decompiler |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Child property loop + tag dispatch | **Yes** |
| Default text tail | **Yes** |

---

## 5. Gaps

1. Full COM interface types.
2. Validate every offset against server ObjectiveRequirementUseItem.
3. unaff register recovery.

**Verdict:** accept-with-gaps.

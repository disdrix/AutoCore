# Review A (reconstruction fidelity): `aa_005afd40` CVOGVariable_EvaluateComputed

| Field | Value |
|---|---|
| **Stable ID** | `aa_005afd40` |
| **VA** | `0x005afd40` |
| **Canonical name** | `CVOGVariable_EvaluateComputed` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005afd40_CVOGVariable_EvaluateComputed.md` |
| **System tag** | `map-variables` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGVariable_EvaluateComputed.cpp` |
| Raw | `docs/reconstruction/raw/aa_005afd40_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Evaluate map logic variable by Type at var+0x40 and Value at var+0x4c into *param_3. Early specials: type 5 → int from context+0x34+0xf8; type 8 → RNG ushort * Value * DAT_00aaa638 via RandomUnitScalar singleton. Switch types include 1–4,6,7,9 completed mission, 0xb active mission (char+0x540 hash), 0xc active objective (+0x548), 0xd–0x13 further mission/distance forms. Returns 1 on success, 0 if param_4 null (with case fallthrough). Client/map condition engine; server has LogicVariableStore twin.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Type byte var+0x40; Value var+0x4c | High | Plate + body |
| Type 5 early: *(ctx+0x34)+0xf8 | High | Body |
| Type 8: RandomUnitScalar table * Value * scale | High | Body |
| Type 9 completed mission Value | High | Plate + case |
| Type 0xb hash char+0x540 active mission | High | CNDHash_LookupByKey |
| Type 0xc hash char+0x548 active objective | High | Body |
| param_4 null → return 0 | High | switchD_caseD_5 path |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Type5/8 early-outs then big switch | Yes |
| Mission/objective hash lookups | Yes |

---

## 4. Gaps

1. Full sealed semantics for types 1–4,6,7,0xd–0x13.
2. DAT_00aaa638 scale exact float.
3. OP conditions LeftId/RightId path (plate note).

**Verdict:** **accept-with-gaps**

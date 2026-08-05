# Review A (reconstruction fidelity): `aa_005ca720` CreateSimpleObject_SerializeVariant2

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ca720` |
| **VA** | `0x005ca720` |
| **Canonical name** | `CreateSimpleObject_SerializeVariant2` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005ca720_CreateSimpleObject_SerializeVariant2.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Second **CreateSimpleObject** serializer (**opcode 0x2012**, same **0xD8** layout) with a **different multi-inherit this-base** (`-0x10c` family vs primary `-0xbc`). Used first by `CVOGCharacter_SerializeCreatePacket` and related character/object create paths. Same null→0, COID **-1** defaults, IsIdentified force **1**, flag **|0x10**, `FUN_00512670`, name strcpy to `+0xae`. Prefixes/gadgets zeroed pattern present in clean mid-body.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ca720_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005ca720_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CreateSimpleObject_SerializeVariant2.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ca720_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode 0x2012 same layout family | High | Clean |
| Distinct this-base vs Serialize (-0x10c) | High | Offset deltas |
| Caller: character serialize create | High | Callee graph / plate |
| IsIdentified forced 1 | High | Clean |
| Full field bit-exact sealed | Medium | Large body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| null→0; 0x2012; parallel pack with shifted this offsets | Yes |
| Not a different opcode family | Yes |

---

## 5. Gaps / open

1. Document which object types use Variant2 vs primary.
2. Cross-check character create pack calls Variant2 first.

**Verdict:** **accept-with-gaps**

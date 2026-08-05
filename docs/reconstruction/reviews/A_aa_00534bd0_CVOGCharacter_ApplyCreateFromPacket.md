# Review A (reconstruction fidelity): `aa_00534bd0` CVOGCharacter_ApplyCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534bd0` |
| **VA** | `0x00534bd0` |
| **Canonical name** | `CVOGCharacter_ApplyCreateFromPacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00534bd0_CVOGCharacter_ApplyCreateFromPacket.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Large apply of CreateCharacter / CreateCharacterExtended packet onto character: base `FUN_005cbcb0` then extensive field stamps; when extended (`param_4 != 0`) reads FirstTimeFlags from packet **0x8EC..0x8F8** into char first-time region (plate: secondary-relative → primary **char+0xD30**). Extended HP at **0x8D6** is int16.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00534bd0_CVOGCharacter_ApplyCreateFromPacket.md` |
| Annotated | `docs/reconstruction/raw/aa_00534bd0_CVOGCharacter_ApplyCreateFromPacket.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_ApplyCreateFromPacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_00534bd0_CVOGCharacter_ApplyCreateFromPacket.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Entry FUN_005cbcb0(base apply)` | **High** | Body start |
| `Extended gate param_4` | **High** | Plate + body |
| `FirstTimeFlags @ 0x8EC family when extended` | **High** | Plate AutoCore offset |
| `Extended HP int16 @ 0x8D6` | **Probable** | Plate note |
| `Huge residual field map still FUN_*/offsets` | **Tentative** | Large scaffold |
| `Clean is very large scaffold` | **High** | 745 lines |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Base helper then extended branches | **Yes (structure)** |
| Field-by-field completeness | **Open — too large to seal in this review** |

---

## 5. Gaps / open

1. Full field dictionary not re-derived line-by-line here.
2. Many nested helpers.
3. Cross-check with Client_RecvCreateCharacter producer.

**Verdict:** **accept-with-gaps**

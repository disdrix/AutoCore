# Review B (skeptical / adversarial): `aa_0060a230` Net_PackInitialCharacterUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060a230` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060a230_Net_PackInitialCharacterUpdate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This is per-tick delta pack only | Falsified — 'initial update' plate |
| 2 | Unpacks client create | Falsified — write path |
| 3 | Vehicle hardpoint equip pack | Falsified — character-focused |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Initial vs delta identity | High | Wrong first scope |
| write order | High | Client parse fail |
| Field completeness | Medium | Missing create fields |

---

## 3. Cross-check against raw

```
PackInitialCharacterUpdate(obj, stream):
  writeBits/Flag/Int create payload; fail log if unsaveable.
Clean CF ≡ raw; layout residual.
```

---

## 4. Surviving contract for AutoCore

```
First-scope character ghost serializer.
  AutoCore Character create/ghost pack must match write order.
```

---

## 5. Open questions

1. Cross-check with CVOGCharacter_SerializeCreatePacket.
2. Capture live initial ghost size vs clean estimate.

**Verdict:** **accept-with-gaps**

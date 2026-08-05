# Review B (skeptical / adversarial): `aa_00534bd0` CVOGCharacter_ApplyCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00534bd0_CVOGCharacter_ApplyCreateFromPacket.md` |
| **Verdict** | **accept-with-gaps** on high-level CF; **needs-more-evidence** for full schema seal |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Review seals every offset | **Falsified — large residual** |
| 2 | Base and extended identical | **Falsified — param_4 extended fields** |
| 3 | HP always int32 | **Falsified as plate — extended 0x8D6 int16** |
| 4 | Finished exact | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Extended FirstTimeFlags 0x8EC | High | Flags desync |
| param_4 extended gate | High | Missing extended fields |
| Full field map | Tentative — needs dedicated pass | Serializer wrong |

---

## 3. Cross-check against raw

```
FUN_005cbcb0(...); /* many stores */
if extended: FirstTimeFlags from 0x8EC.. into char+0xD30 family; other extended fields
Clean is behavior-preserving scaffold of decomp — treat as CF map not sealed schema.
```

---

## 4. Surviving contract for AutoCore

```
On Create/CreateExtended apply:
  run base apply helper then extended-only fields when flagged
  FirstTimeFlags packet offset 0x8EC; HP extended int16 at 0x8D6
  Prefer dedicated field-table RE before production serializer
Cross-link RecvCreateCharacter + SendUpdateFirstTimeFlags.
```

---

## 5. Open questions

1. Complete offset table vs AutoCore CreateCharacterExtendedPacket.
2. Runtime login apply capture.
3. FUN_005cbcb0 dual review.

**Verdict:** **accept-with-gaps** on high-level CF; **needs-more-evidence** for full schema seal

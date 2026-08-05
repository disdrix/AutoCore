# Review B (skeptical / adversarial): `aa_0092c6d0` Client_SendUpdateFirstTimeFlags

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092c6d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0092c6d0_Client_SendUpdateFirstTimeFlags.md` |
| **Verdict** | **accept-with-gaps** on CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sends without local stamp | **Falsified — copies to char+0xD30 first** |
| 2 | Variable-length flag blob | **Falsified — fixed 4 dwords** |
| 3 | Uses sector DAT connection only | **Weak — uses client+0xc78** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x20B1 + 0x14 | High | Wrong C2S |
| char+0xD30 mirror | High | Desync first-time UI |
| Null gates | High | Spurious/missed send |

---

## 3. Cross-check against raw

```
if char && flags:
  copy 4 dwords to char+0xD30; pkt={0x20b1, f0..f3}; send 0x14
Clean matches AutoCore UpdateFirstTimeFlagsRequest note.
```

---

## 4. Surviving contract for AutoCore

```
On first-time flag update:
  mirror 4×u32 to character +0xD30 then C2S 0x20B1 size 0x14
Keep offsets aligned with CreateCharacterExtended FirstTimeFlags @ 0x8EC family.
```

---

## 5. Open questions

1. Flag bit dictionary.
2. Server handler seal.

**Verdict:** **accept-with-gaps** on CF

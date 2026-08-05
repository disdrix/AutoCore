# Review B (skeptical / adversarial): `Client_SetFirstTimeTipBit` @ `0x0040ff80`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ff80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0040ff80_Client_SetFirstTimeTipBit.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sends packet | Falsified — local OR only |
| 2 | Uses id>>3 byte index | Falsified — dword index id>>5 |
| 3 | Clears bit | Falsified — OR set only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0xD30 OR bitfield | High | Wrong tip memory |
| id<0x80 gate | High | Out-of-range write |

---

## 3. Cross-check against raw

```
if tipId < 0x80: *(char+0xD30 + 4*(id>>5)) |= 1<<(id&0x1f).
```

---

## 4. Surviving contract for AutoCore

```
SetFirstTimeTipBit(tipId, character):
  local bit set only; caller may SendUpdateFirstTimeFlags
  128 tips max (4x u32)
```

---

## 5. Open questions

1. Confirm 4-dword FirstFlags1..4 layout.

**Verdict:** **accept**

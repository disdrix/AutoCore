# Review B (skeptical / adversarial): `Client_MaybeShowFirstTimeTip` @ `0x00801760`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00801760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00801760_Client_MaybeShowFirstTimeTip.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always shows dialog | Falsified — bit set and hide-all skip UI |
| 2 | Bits stored only server-side | Falsified — local char+0xD30 OR then C2S update |
| 3 | Tip id unlimited | Falsified — SetFirstTimeTipBit only id<0x80 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0xD30 bitfield | High | Repeat tips / never tip |
| Hide-all bit31 path | High | Spam dialogs |
| SendUpdateFirstTimeFlags | High | Lost persistence |
| Dialog ctor details | Tentative | UI crash |

---

## 3. Cross-check against raw

```
if bit set: return; if hide-all: set bit + send flags; else show CDlgFirstTime.
```

---

## 4. Surviving contract for AutoCore

```
MaybeShowFirstTimeTip(client, tipId):
  if bit(char+0xD30, tipId): return
  if hideTips(bit31): SetBit; SendUpdateFirstTimeFlags; return
  else show CDlgFirstTime(tipId)
  persist FirstFlags1..4 on account
```

---

## 5. Open questions

1. Map tip ids to content strings.
2. Confirm account.FirstFlags packing matches +0xD30.

**Verdict:** **accept-with-gaps**

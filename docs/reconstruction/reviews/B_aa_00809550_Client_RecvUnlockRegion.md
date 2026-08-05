# Review B (skeptical / adversarial): `aa_00809550` Client_RecvUnlockRegion

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00809550_Client_RecvUnlockRegion.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | First unlock applies ExploredBits | **Falsified** — UnlockContinentObject only; bits ignored |
| 2 | Areas are 0-based in API | **Falsified** — SetAreaExploredBit uses `i+1` (1..32) |
| 3 | Bits equal → still rewrite | **Falsified** — only when `entry+8 != packet bits` |
| 4 | UnlockFlag byte width exact | **Probable** — compared as char at +8 |
| 5 | Handler is only discovery path | **Falsified** — LocalDiscoveryTick also sets bits client-side |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bootstrap vs bit-apply split | High | Lost exploration map |
| Area id 1..32 | High | Off-by-one fog map |
| Relock polarity | High | Map permanently stuck |
| Packet framing in clean | Tentative | Wrong field reads in port |

---

## 3. Cross-check against raw

Plate comments match CF. Comment placement in raw is slightly scrambled (bootstrap comment sits inside bit loop) — **behavior** still matches plate summary. Clean copies raw including that comment quirk.

---

## 4. Surviving contract for AutoCore

```
RecvUnlockRegion(0x205B):
  char = client.local(+0xe98); if !char: return
  if !unlockFlag(+8): RelockContinentObject(continentId); return
  entry = char.hash(+0x534).lookup(continentId)
  if !entry: UnlockContinentObject(char, continentId)  // ignore bits
  else if entry.bits != pkt.bits:
    for i in 0..31:
      if bit i differs: SetAreaExploredBit(char, continentId, i+1, on)
Login: send twice (bootstrap empty then bits) recommended.
```

---

## 5. Open questions

1. Clean up decompiler packet/register ABI.
2. Interaction with LocalDiscoveryTick client-side bits vs server authority.
3. CreateCharacterExtended bootstrap parity.
4. Relock use cases.

**Verdict:** Bootstrap/bit-split contract is the critical sealed fact.

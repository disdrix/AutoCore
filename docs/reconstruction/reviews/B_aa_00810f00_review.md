# Review B (skeptical / adversarial): `Client_RecvCharacterLevel` @ `0x00810f00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810f00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00810f00_review.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | CharacterLevel is an XP grant | **Falsified** — absolute snapshot; Apply sets totals |
| 2 | Formal pPacket drives field reads | **Weak** — body uses EAX framing (`pPacketInEax`) |
| 3 | Always refreshes local UI | **Falsified** — TFID must match local player |
| 4 | Login should send GiveXP of full total | **Falsified by XP.md** — would re-apply; use 0x2017 only |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode 0x2017 absolute snapshot role | High | Broken login restore |
| TFID triple layout +8/+0xc/+0x10 | High | Apply wrong entity |
| Full packet field map | Medium (in Apply callee) | Partial UI desync |
| EAX vs formal packet ABI | Medium | Wrong integration test harness |

---

## 3. Surviving contract for AutoCore

```
S2C 0x2017 CharacterLevel:
  resolve object by (coidLo, coidHi, bGlobal)
  apply absolute Level, Experience, Currency, point pools
  if local TFID match: refresh level UI + mission windows
Login restore: send CharacterLevel, NOT full-total GiveXP.
```

---

## 4. Open questions

1. Exact ApplyCharacterLevelPacket field order vs AutoCore `CharacterLevelPacket.cs`.
2. Whether non-local CharacterLevel (other players) is used in retail traffic.

**Verdict:** Correct hub for absolute progress sync; do not treat as grant path.

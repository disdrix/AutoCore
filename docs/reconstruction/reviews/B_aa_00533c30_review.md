# Review B (skeptical / adversarial): `aa_00533c30` CVOGReaction_AddExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Verdict** | **needs-more-evidence** on package-level claims; body CF **solid** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Single kernel for all XP | **Mostly true on client** — packet + mission + kill call it; server must mirror |
| 2 | Spree index comes from spree byte | **Falsified previously** — table index from entity `+0xe818`, not `+0x738` |
| 3 | `WeaponAllowsKillXpBonus` is weapon check | **Falsified** — see `aa_004ce340` body (mode flags only) |
| 4 | Packet path uses KillPath | **Falsified** — `Client_AwardKillExperience` uses `PacketOrNonKill` |
| 5 | Soft cap always applies | **Falsified** — skipped when `specialMode(+0x6b4) >= 1` |
| 6 | Level loops always run | **Falsified** — require entity flag `+0x7e` |

---

## 2. Surviving algorithm

```
if KillPath: update spree window; maybe scale amount by (table[i]+1)
scaled = (int)(amount * personalGain)
if atMax && !specialMode: clamp scaled
if scaled==0: return false
totalXp += scaled
if flag_7e: level up/down loops
return true
```

---

## 3. Open questions

1. What sets `+0xe818` (table index)?
2. Is `+0x7e` strictly “local player / authority”?
3. Negative XP sources in retail?

**Verdict:** Use clean for port of apply rules; do not trust marketing names around weapon/spree index without the `+0xe818` path.

# Review B (skeptical / adversarial): `aa_0080ae70` Client_AwardKillExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ae70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on packet framing absolute layout |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Handles kill XP only | **Falsified** — plate + body: all S2C GiveXP; `PacketOrNonKill` |
| 2 | Uses formal `pGiveXp` parameter | **Weak** — body reads `unaff_ESI` framing; formal may be dead/ overlapping |
| 3 | LevelHint drives character level | **Overstated** — writes spree/hint byte `+0x738` + timestamp, does **not** set `+0x6c8` level here |
| 4 | Floater always shown | **Falsified** — requires `char+0x250 != 0` |
| 5 | Name `sbyte` from early emit | **Historical scaffolding bug** — raw/clean renamed; ignore |

---

## 2. Surviving contract for AutoCore

```
S2C GiveXP 0x205F:
  amount: int32
  levelHint: sbyte (-1 none)
Client:
  AddExperience(local, amount, isKillPath=0)
  if levelHint != -1: stamp +0x738/+0x734
  maybe XP floater if vehicle context
```

Server should send final integer amount (spree already baked if desired). Do not expect client kill formula to re-run on packet path.

---

## 3. Open questions

1. Exact BitStream / packet body offsets vs ESI framing in dispatch.
2. Whether levelHint is ever non-`-1` in retail traffic.
3. Interaction when GiveXP amount is 0 but hint set.

**Verdict:** Safe to implement server→client GiveXP mirroring non-kill apply; rename function in new code to `Client_RecvGiveXp` when modernizing.

# Review B (skeptical / adversarial): `aa_004c8b60` CVOGCreature_SetupGraphics

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8b60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c8b60_CVOGCreature_SetupGraphics.md` |
| **Verdict** | **accept-with-gaps** on height CF; **needs-more-evidence** on full graphics tail |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always subtracts flying height | **Falsified — type 0x12 and bit4 clear only** |
| 2 | Adds flying height here | **Falsified — subtracts (pairs with create add)** |
| 3 | Finished graphics port | **Overstated — large tail** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Y flying-height polarity | High | Float spawn / buried NPC |
| Type/flag gate | High | Wrong ground snap |
| Placement helper | Tentative | Bad transform |

---

## 3. Cross-check against raw

```
if kind==0x12 && bit4 clear: param_Y -= rlFlyingHeight;
FUN_005d4d70(...); set graphics flags; NPC name / mesh tail.
Clean preserves height adjust; tail FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
SetupGraphics(creature, ... Y ...):
  for creature templates (0x12) without flag bit4: Y -= rlFlyingHeight before place
  (inverse of CreateCreature height add — keep paired)
  then graphics/phys setup helpers
Critical for NPC_SPAWN_HEIGHT correctness.
```

---

## 5. Open questions

1. Seal rlFlyingHeight offset path template+0x4d4.
2. Document bit4 flag name from assets.
3. Cross-check CreateCreature add path.

**Verdict:** **accept-with-gaps** on height CF; **needs-more-evidence** on full graphics tail

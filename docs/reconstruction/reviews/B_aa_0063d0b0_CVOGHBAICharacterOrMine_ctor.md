# Review B (skeptical / adversarial): `aa_0063d0b0` CVOGHBAICharacterOrMine_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063d0b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0063d0b0_CVOGHBAICharacterOrMine_ctor.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on mid field names |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same size as Creature 0x100 | **Falsified — 0x110** |
| 2 | Only zeros no float seeds | **Falsified — four g_flOne at 0x38..** |
| 3 | Driver does not use this mid | **Falsified — Driver_ctor chains it** |
| 4 | Finished field map | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size 0x110 + mid vtbl | High | Driver/Character crash |
| Float quartet seed | High | Bad default ranges |
| Zero span coverage | High | Stale mid state |
| Slot semantics | Tentative | Wrong sim fields |

---

## 3. Cross-check against raw

```
Base_ctor; *this=CharMineVtbl; [0x38..0x3b]=1.0f; zero [0x30..0x37]+[0x3c..0x43]; [4]=DAT_00aaa668.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
CharacterOrMine_ctor:
  shared mid parent size 0x110 for AICode 1/4 and Driver
  seeds four floats to 1.0; clears large mid zero block
  Character may still redirect to CreatureBase at factory (not here)
  seal layout before porting Driver-only fields
```

---

## 5. Open questions

1. Name DAT_00aaa668.
2. Map [0x30..] to DoLogic/ReturnToNormalLocation this[] uses.
3. Publish mid layout in types registry.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on mid field names

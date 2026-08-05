# Review B (skeptical / adversarial): `Client_RefreshLocalCharacterLevelUi` @ `0x0092f4d0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f4d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0092f4d0_Client_RefreshLocalCharacterLevelUi.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets currency/XP | Falsified — UI fields only |
| 2 | Applies for remote players | Falsified — local char path |
| 3 | Uses money fields | Falsified — plate excludes money |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI refresh after CharacterLevel | High | Stale level HUD |
| clonebase +0x531/+0x532 | High | Wrong rank display |
| Local TFID gate at caller | High | Wrong if called always |

---

## 3. Cross-check against raw

```
RefreshLocalCharacterLevelUi(game):
  char=game+0xe98; if null return;
  game+0xeec = clonebase+0x531;
  game+0xee4 = vtbl+0x27c();
  game+0xee8 = clonebase+0x532;
```

---

## 4. Surviving contract for AutoCore

```
RefreshLocalCharacterLevelUi:
  HUD level/rank only after local CharacterLevel;
  pairs LookupObjectByTfid + ApplyCharacterLevelPacket.
```

---

## 5. Open questions

1. Name clonebase fields +0x531/+0x532.

**Verdict:** **accept-with-gaps**

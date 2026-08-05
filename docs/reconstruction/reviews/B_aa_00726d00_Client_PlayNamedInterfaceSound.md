# Review B (skeptical / adversarial): `Client_PlayNamedInterfaceSound` @ `0x00726d00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00726d00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00726d00_Client_PlayNamedInterfaceSound.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Blocks until sound ends | Weak — async playback likely |
| 2 | Grants mission complete | Falsified — audio only |
| 3 | No concurrency control | Falsified — CS present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Named interface cues | High | Silent mission complete |
| CS around slot table | High | Audio race crash |

---

## 3. Cross-check against raw

```
PlayNamedInterfaceSound(this, name/params...):
  CS; lookup cue; manage slots; start; leave CS.
```

---

## 4. Surviving contract for AutoCore

```
PlayNamedInterfaceSound:
  client UI/mission stingers; pairs mission_complete_* table.
```

---

## 5. Open questions

1. Document param_1..param_9 meanings.

**Verdict:** **accept-with-gaps**

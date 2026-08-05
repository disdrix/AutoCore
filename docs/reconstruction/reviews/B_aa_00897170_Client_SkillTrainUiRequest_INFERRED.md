# Review B (skeptical / adversarial): `Client_SkillTrainUiRequest_INFERRED` @ `0x00897170`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00897170` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00897170_Client_SkillTrainUiRequest_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Trains without server | Falsified — sends SkillIncrement 0x2059 |
| 2 | Always fills QB | Falsified — empty slot only / first-rank path |
| 3 | Uses 0x2030 cast opcode | Falsified — 0x2059/0x2062 train/QB |
| 4 | Max rank unlimited | Falsified — max +0x5f4 and hard <0x32 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x2059 SkillIncrement | High | Train not applied |
| 0x2062 QB update on first train | High | Missing auto hotbar |
| Empty slot criteria FFFFFFFF/-1 | High | Overwrite occupied slot |
| Rank fields +0x5f6/+0x5f4 | High | Overtrain / stuck |

---

## 3. Cross-check against raw

```
SkillTrainUiRequest(ui, skillId):
  if unavailable/SP/level/max: toast; return
  if first-rank active: find empty QB slot → SetQuickBarSkill → send 0x2062
  send SkillIncrement 0x2059
  maybe first-time tip.
```

---

## 4. Surviving contract for AutoCore

```
SkillTrainUiRequest:
  client train UI → C2S **0x2059** (+ optional **0x2062** QB);
  server validates train; empty QB = COID FFFFFFFF & skill -1.
```

---

## 5. Open questions

1. Seal full prereq checks from body.
2. Confirm 0x2059 payload layout vs server.

**Verdict:** **accept-with-gaps**

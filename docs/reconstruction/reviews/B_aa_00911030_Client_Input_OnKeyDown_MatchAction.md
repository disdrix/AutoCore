# Review B (skeptical / adversarial): `Client_Input_OnKeyDown_MatchAction` @ `0x00911030`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00911030_Client_Input_OnKeyDown_MatchAction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Polls held every frame here | Falsified — key-down path; PollBoundActions consumes edges |
| 2 | Drive thr/steer set here | Falsified — DriveControlTick held path |
| 3 | Shift is DIK 0x36 RSHIFT only | Falsified — any VK shift → 0x2a |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Edge+held set on match | High | Dead keys |
| 0x34 stride table | High | Wrong bind |
| ESC UI cancel | High | Stuck dialog |
| Override helper | Tentative | Hardcoded binds miss |

---

## 3. Cross-check against raw

```
if ESC&allow: cancel UI; else shift-mod + scan table;
on match held/edge + notify. Clean sections match raw.
```

---

## 4. Surviving contract for AutoCore

```
OnKeyDown_MatchAction(client, key, lParam):
  ESC → UI cancel if allowed
  else match DIK[+shift] in ActionMap table
  set held/edge bytes; notify
  pairs PollBoundActions edge consumers
```

---

## 5. Open questions

1. Seal table symbol names and count.
2. Name FUN_0093a5c0.

**Verdict:** **accept-with-gaps**

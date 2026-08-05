# Review B (skeptical / adversarial): `Client_NotifyActiveMissionChanged` @ `0x00944770`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00944770_Client_NotifyActiveMissionChanged.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets character active mission +0x540 | Falsified — notify/toast only |
| 2 | Always fires for solo play | Attack — convoy leader strings dominate |
| 3 | No debug strings | Falsified — KQDI/DQDI present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Toast-only side effect | High | Missed player feedback |
| Type==3 filter | Medium | Wrong entity toast |
| Trigger packet | Tentative | Never shows |

---

## 3. Cross-check against raw

```
Walk context list; for matching convoy-related entries build
'Your Convoy Leader has changed your active mission to …'; emit.
State change is elsewhere.
```

---

## 4. Surviving contract for AutoCore

```
NotifyActiveMissionChanged:
  UI chat when leader swaps active mission
  does not write mission hashes
  pair with active-mission set on packet handler
```

---

## 5. Open questions

1. Find caller / packet opcode.
2. Seal chat emit helper.

**Verdict:** **accept-with-gaps**

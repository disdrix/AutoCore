# Review B (skeptical / adversarial): `Client_UpdateObjectiveDisplayHud` @ `0x008066f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008066f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008066f0_Client_UpdateObjectiveDisplayHud.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Grants XP | Falsified — display only |
| 2 | Single fixed layout no mode byte | Falsified — +0xd1c switch |
| 3 | Server HUD sync packet | Falsified — local refresh |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode +0xd1c | High | Wrong HUD page |
| Level/XP string path | High | Blank level |
| Other modes | Tentative | Stale objective text |

---

## 3. Cross-check against raw

```
switch(+0xd1c); case1 level/xp/money labels; other cases open.
UI refresh only.
```

---

## 4. Surviving contract for AutoCore

```
UpdateObjectiveDisplayHud(hudRoot):
  mode = +0xd1c
  refresh level/money/objective labels from local char
  call after level/mission packets
```

---

## 5. Open questions

1. Document all +0xd1c modes.
2. Link from RecvCharacterLevel / mission updates.

**Verdict:** **accept-with-gaps**

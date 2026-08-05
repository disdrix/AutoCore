# Review B (skeptical / adversarial): `Client_GetMissionCompleteAudioTable` @ `0x00723820`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00723820_Client_GetMissionCompleteAudioTable.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Grants mission complete rewards | Falsified — audio table init |
| 2 | Always re-inits | Falsified — once flag |
| 3 | Server-side | Falsified — client audio |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Once-init singleton table | High | Double-init crash |
| DAT_00d20210 host | High | Wrong cue table |
| mission_complete_3/5 names | Medium | Missing stingers |

---

## 3. Cross-check against raw

```
GetMissionCompleteAudioTable():
  once: FUN_00723510(&DAT_00d20210); atexit;
  return table.
```

---

## 4. Surviving contract for AutoCore

```
GetMissionCompleteAudioTable:
  client mission-complete audio table singleton;
  pairs PlayNamedInterfaceSound / CompleteObjective stingers.
```

---

## 5. Open questions

1. List all mission_complete_* cue names.

**Verdict:** **accept**

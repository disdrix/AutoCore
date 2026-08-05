# Review B (skeptical / adversarial): `Client_DebugDumpEntityCombatStats` @ `0x00955eb0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00955eb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00955eb0_Client_DebugDumpEntityCombatStats.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Production combat solver | Falsified — debug dump |
| 2 | Mutates AI state | Falsified — read+sprintf |
| 3 | Required for server XP | Falsified — client debug |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Debug-only tool | High | None for live servers |
| Reads live AI/skill fields | Medium | Wrong RE if used as truth |

---

## 3. Cross-check against raw

```
DebugDumpEntityCombatStats(entity):
  sprintf AI/skill/armor/resists/pos → print;
  no state change.
```

---

## 4. Surviving contract for AutoCore

```
DebugDumpEntityCombatStats:
  client debug only; do not port as combat rules.
```

---

## 5. Open questions

1. Wire to slash command registry entry.

**Verdict:** **accept**

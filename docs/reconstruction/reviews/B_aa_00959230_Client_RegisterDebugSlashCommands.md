# Review B (skeptical / adversarial): `Client_RegisterDebugSlashCommands` @ `0x00959230`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00959230` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00959230_Client_RegisterDebugSlashCommands.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Production player commands | Falsified — debug slash |
| 2 | Server slash admin | Falsified — client register |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Debug command surface | High | None for ship |
| castskill/quickbar debug hooks | Medium | RE tooling only |

---

## 3. Cross-check against raw

```
RegisterDebugSlashCommands: register debugmissions/castskill/quickbar/...
```

---

## 4. Surviving contract for AutoCore

```
RegisterDebugSlashCommands: client debug only; do not port as GM API.
```

---

## 5. Open questions

1. Enumerate complete command table.

**Verdict:** **accept**

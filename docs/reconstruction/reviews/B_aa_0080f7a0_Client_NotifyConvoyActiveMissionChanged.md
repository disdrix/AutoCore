# Review B (skeptical / adversarial): `Client_NotifyConvoyActiveMissionChanged` @ `0x0080f7a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080f7a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080f7a0_Client_NotifyConvoyActiveMissionChanged.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Leader-only local set without server | Weak — notify/toast focused |
| 2 | Same as non-convoy notify | Falsified — convoy-specific strings |
| 3 | No UX | Falsified — explicit toast |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Convoy toast only vs state write | High | Desync if assumed writer |
| Sibling notify selection | Medium | Duplicate/missing toast |

---

## 3. Cross-check against raw

```
NotifyConvoyActiveMissionChanged:
  toast convoy leader changed active mission;
  verify if state write is elsewhere.
```

---

## 4. Surviving contract for AutoCore

```
NotifyConvoyActiveMissionChanged:
  client convoy UX; active mission authority is server + other setters.
```

---

## 5. Open questions

1. Diff vs Client_NotifyActiveMissionChanged CF.

**Verdict:** **accept-with-gaps**

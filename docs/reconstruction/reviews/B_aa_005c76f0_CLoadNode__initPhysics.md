# Review B (skeptical / adversarial): `aa_005c76f0` CLoadNode__initPhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c76f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c76f0_CLoadNode__initPhysics.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always blocks forever | Falsified — return 3 wait |
| 2 | Only vehicles | Falsified — multi-type gate |
| 3 | Skips type 0xE special path | Falsified — dedicated branch |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0xE path | High | Player phys wrong |
| Wait code 3 | High | Load hang / skip |
| +0x52 flag | Medium | Downstream stage miss |

---

## 3. Cross-check against raw

```
_initPhysics: wait +0x14c; clear +0x67; phys resolve;
  type0xE special vs generic; maybe +0x52; return 0|3.
```

---

## 4. Surviving contract for AutoCore

```
Load-node physics stage for client object bring-up.
```

---

## 5. Open questions

1. Trace one vehicle spawn through CLoad stages.

**Verdict:** **accept-with-gaps**

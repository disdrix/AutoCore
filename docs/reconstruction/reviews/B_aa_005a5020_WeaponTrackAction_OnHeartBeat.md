# Review B (skeptical / adversarial): `aa_005a5020` WeaponTrackAction_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a5020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005a5020_WeaponTrackAction_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies heat each beat | Falsified — no heat path |
| 2 | Never reschedules | Falsified — always writes out period |
| 3 | Requires +0x24 for period write | Falsified — always writes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x24 gate | High | Missed track updates |
| Period global | Medium | Wrong HB rate |

---

## 3. Cross-check against raw

```
OnHeartBeat: maybe FUN_004f8430; *out=DAT_00b05064. Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
HB weapon track tick; keep distinct from fire cost path.
```

---

## 5. Open questions

1. Who sets +0x24 on track action.

**Verdict:** **accept-with-gaps**

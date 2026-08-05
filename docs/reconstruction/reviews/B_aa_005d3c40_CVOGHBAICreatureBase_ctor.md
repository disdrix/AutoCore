# Review B (skeptical / adversarial): `aa_005d3c40` CVOGHBAICreatureBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3c40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d3c40_CVOGHBAICreatureBase_ctor.md` |
| **Verdict** | **accept** on CF (simple ctor); slot names open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Does not chain base | **Falsified — calls Base_ctor** |
| 2 | Same vtbl as Driver | **Falsified — distinct CreatureBase vtbl** |
| 3 | Size 0x110 | **Falsified — 0x100** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CreatureBase vtbl | High | Wrong virtuals / OnHeartBeat |
| Extended zero | Tentative | Stale timers |

---

## 3. Cross-check against raw

```
Base_ctor; *this=CreatureBaseVtbl; zero [0x30..0x3f]; return this.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
CreatureBase_ctor:
  AICode 2 default foot AI; size 0x100
  OnHeartBeat is primary tick (not Driver_DoLogic)
  27 retail profiles use this class
```

---

## 5. Open questions

1. Map [0x30..] to OnHeartBeat fields this+0x24/0x28 etc.

**Verdict:** **accept** on CF (simple ctor); slot names open

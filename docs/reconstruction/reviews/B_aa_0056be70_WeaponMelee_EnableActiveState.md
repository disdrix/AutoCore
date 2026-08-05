# Review B (skeptical / adversarial): `aa_0056be70` WeaponMelee_EnableActiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056be70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056be70_WeaponMelee_EnableActiveState.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always allocates HB | **Falsified** — requires clonebase host `+0xe4ec` list |
| 2 | Re-enables when already active | **Falsified** — early out if `+0xc5 != 0` |
| 3 | Same as disable unit | **Falsified** — polarity + HB path |
| 4 | Period is 0x1000 ms product English | **Open** — literal 1000 sealed; unit open |
| 5 | 0x3e4ccccd is 0.2 | **High seal** as IEEE float; product role open |

---

## 2. Surviving contract

```
fastcall(melee):
  if already active: return
  enable vfunc104(1); set flags
  maybe enqueue CVOGHBBase(period=1000) and Start
  maybe secondary vfunc with 0.2f
```

Melee equip dual call after skills cast **survives**.

---

## 3. Open

HB factory product; runtime; `+0x78` sentinel meaning.

**Verdict:** Enable path sealed. **accept-with-gaps.**

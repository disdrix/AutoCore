# Review B (skeptical / adversarial): `aa_00569d50` WeaponMelee_DisableActiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569d50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00569d50_WeaponMelee_DisableActiveState.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Clears vehicle melee slot `+0x264` | **Falsified** — no vehicle store; parent does that |
| 2 | Always runs teardown | **Falsified** — gated on `+0xc5` |
| 3 | Same as Enable (`0056be70`) | **Falsified** — polarity inverted; enable allocates HB |
| 4 | Called with explicit vehicle arg | **Falsified** — `__fastcall` this only (decompiler may elide ECX) |
| 5 | Product name sealed | **Fail** — inferred |

---

## 2. Surviving contract

```
fastcall(melee):
  if melee.activeFlag_0xc5:
    clear flag
    gfx.vfunc104(0)
    delete melee.actionHost_0xc0 if any
    null 0xc0
```

Melee equip dual **must** keep this before prior-item unbind.

---

## 3. Open

`+0xc0` concrete type; runtime.

**Verdict:** Disable path sealed against enable dual. **accept-with-gaps.**

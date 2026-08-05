# Review B (skeptical / adversarial): `aa_00764030` CVOGGraphicsBody_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00764030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00764030_CVOGGraphicsBody_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Melee-only factory | **Falsified** — TacArc / creature / respawn callers |
| 2 | Function loads mesh by path | **Falsified** — zero-init only; load is `00989e00` + vfunc after |
| 3 | Size is 0x24 | **Falsified** — equip path `new(0x14c)`; 0x24 is HB path |
| 4 | Product class name proven | **Fail** — vtable symbol open |
| 5 | Not a ctor | **Falsified** — returns this; sets vtable |

---

## 2. Surviving contract

```
fastcall(this) -> this:
  base_init; vtable = LAB_00a9da8c
  zero fields; scale = 1.0f; self-links
  return this
```

Melee equip dual **new(0x14c)+this** pattern cannot be attacked away.

---

## 3. Open

RTTI name; full layout; runtime.

**Verdict:** Ctor sealed. **accept-with-gaps.**

# Review B (skeptical / adversarial): `aa_00989e00` ResourceCache_LookupByName

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00989e00_ResourceCache_LookupByName.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Equip-only helper | **Falsified** — TacArc/creature/FX callers |
| 2 | Always EnterCriticalSection | **Falsified** — gated on `this+0x80` |
| 3 | Empty name returns null | **Falsified** — writes `DAT_00d1eac0` |
| 4 | Constructs mesh geometry | **Falsified** — handle lookup only |
| 5 | Product class name sealed | **Fail** — inferred |

---

## 2. Surviving contract

```
thiscall(cache, out*, name):
  if !name || !*name: *out = g_default; return
  resolve via fast path or CS-protected map
  *out = handle
```

Melee equip dual path **snprintf → this → vfunc load** survives.

---

## 3. Open

Handle type; default object identity; runtime.

**Verdict:** Lookup sealed. **accept-with-gaps.**

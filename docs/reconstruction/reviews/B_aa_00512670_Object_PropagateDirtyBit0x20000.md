# Review B (skeptical / adversarial): `aa_00512670` Object_PropagateDirtyBit0x20000

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512670_Object_PropagateDirtyBit0x20000.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function attaches / clears equip mesh | **Falsified** — only OR + parent walk |
| 2 | Bit is `0x2000` or `0x200` | **Falsified** — immediate `0x20000` |
| 3 | Walks children not parents | **Open polarity** — `+0xac` is parent/container in inventory duals; not child list |
| 4 | Stops after first parent | **Falsified** — while until null |
| 5 | Vehicle-only | **Falsified** — Item_SetBroken / inventory grid callers |
| 6 | Product bit name known | **Fail** — sealed value only |

---

## 2. Surviving contract

```
fastcall(object):
  object.flags_0x17c |= 0x20000
  for p = object.parent_0xac; p; p = p.parent_0xac:
    p.flags_0x17c |= 0x20000
```

Equip helpers that call this **before** slot mutate cannot be attacked as “no dirty.”

---

## 3. Open

| Topic | Why |
|---|---|
| Bit product dictionary | Immediate only |
| Runtime mask consumers | Deferred |

**Verdict:** CF trivial and sealed. **accept-with-gaps.**

# Review B (skeptical / adversarial): `aa_004fbb50` Vehicle_ClearItemGfxBindings

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbb50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fbb50_Vehicle_ClearItemGfxBindings.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Destroys item | **Falsified** — list predicate remove + flag vcall only |
| 2 | Always double-removes list | **Falsified** — second pass gated on char resolve + `+0x250` |
| 3 | Vehicle this is unused beyond host load | **Partial** — only COM host path; no vehicle slot stores here |
| 4 | `+0x40(1)` means “equipped true” | **Unsealed English** — call sealed |
| 5 | Only used on unequip | **Falsified** — heavy use on **equip** replace paths |
| 6 | Predicate is identity free | **Open** — `LAB_004f5400` not dualed here |

---

## 2. Surviving contract

```
if vehicle.charHost && item:
  DoubleList_RemoveIf(predicate_004f5400, item.list@+0x160, 0)
  if char = host.vtbl+0x1dc(); char && char.vehicle@+0x250:
    DoubleList_RemoveIf(... again ...)
  item.vtbl+0x40(1)
```

---

## 3. Open

Predicate body; product name; runtime.

**Verdict:** CF sealed against equip duals. **accept-with-gaps.**

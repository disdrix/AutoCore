# Review B (skeptical / adversarial): `aa_0053d790` CVOGReaction_TeleportTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053d790` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0053d790_CVOGReaction_TeleportTarget.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Loads a new map | **Falsified** |
| 2 | Always writes pose at +0x84 | **Falsified** |
| 3 | Ignores validation | **Falsified** |
| 4 | Server physics teleport | **Overstated** |
| 5 | Clean reorders branches | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pose apply CF | High | Wrong position |
| Validation gate | Probable | Bad teleports accepted |
| Offset labels | Tentative | Wrong entity fields |

---

## 3. Cross-check against raw

```
vcall this+0x40
if !target(+8): copy 4 dwords to pose+0x84
else:
  validate; maybe FUN_005070d0
  maybe vcall target+0x3c +0x40(data)
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
TeleportTarget(ctx, pose4)
  apply local teleport pose to reaction target or self pose cache
  distinct from TransferMap
```

---

## 5. Open questions

1. Link to mission teleporter reactions.
2. Coordinate space (world vs sector).
3. Interaction with vehicle seat.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.

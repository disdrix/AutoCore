# Review B (skeptical / adversarial): `aa_00863430` Client_SendInventoryDrop_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00863430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00863430_Client_SendInventoryDrop_Hardpoint.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Name “Drop_Hardpoint” proves opcode 0x2036 type=2 | **Not body-sealed** — equip chain may use distinct framing |
| 2 | Paint path is only paint | **Overstated risk** — type 0x0E gate is real; other reject reasons exist |
| 3 | Clean exact finished | **Scaffold** — dual body + stub |
| 4 | Always sends on pass | **Weak** without full body walk of all return edges |

---

## 2. Surviving contract

```
require host + cursor item
gate FUN_00862860 / space helpers
special-case paint/town restrictions with toast
else build+send hardpoint drop/equip packet
```

---

## 3. Open questions

Opcode/size; parity with UI DropToGrid; server TryEquip link; runtime.

**Verdict:** Gate/toast map usable; wire layout not sealed.

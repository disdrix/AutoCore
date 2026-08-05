# Review A (reconstruction fidelity): `aa_00538c80` CNDHash_Remove_009cefd4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538c80` |
| **VA** | `0x00538c80` |
| **Canonical name** | `CNDHash_Remove_009cefd4` (remove twin; vtbl `PTR_FUN_009cefd4` + dead delete stub) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00538c80_CNDHash_Remove_009cefd4.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash remove** with:

- Full shared remove CF (lock warn, `004e2ca0` bucket unlink, list unlink, freelist, E_FAIL miss).
- Vtbl `PTR_FUN_009cefd4` (matches insert twin `CNDHash_Insert` `0x0053c560` node family).
- Residual `if (node->value) operator_delete` **after** value already cleared → **dead**.

Caller: `CVOGReaction_RelockContinentObject` `0x0052a1b0`.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw | **Confirmed** |
| Dead delete after clear | **Confirmed** |
| Vtbl ties to insert `0053c560` | **High** |

---

## 3. Recovered CF

Same as `0x00538000` with vtbl `009cefd4`.

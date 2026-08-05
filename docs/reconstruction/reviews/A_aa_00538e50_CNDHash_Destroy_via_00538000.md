# Review A (reconstruction fidelity): `aa_00538e50` CNDHash_Destroy_via_00538000

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538e50` |
| **VA** | `0x00538e50` |
| **Canonical name** | `CNDHash_Destroy` (owning; remove body `FUN_00538000` / vtbl `009cefec`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00538e50_CNDHash_Destroy_via_00538000.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, remove `0x00538000` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Twin of `0x00538e00`:

1. Lock log `HashError:Destroy…`; continue.
2. `FUN_00538000(key, &keySlot)` remove (vtbl `009cefec` family).
3. On success (`hr >= 0`) → `operator_delete` of out value.

Callers: `CVOGReaction_CompleteObjective` `0x00533f90`; pairs with remove dual `aa_00538000`.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw | **Confirmed** |
| Same ownership model as `00538e00` | **Confirmed** |
| Remove specialization only via callee vtbl | **High** |

---

## 3. Recovered CF

```c
// void __thiscall CNDHash_Destroy(hash*, uint key)
if (hash->lock) log Destroy-locked;
void *val = …;
hr = Remove_00538000(hash, key, &val);
if (hr >= 0) operator_delete(val);
```

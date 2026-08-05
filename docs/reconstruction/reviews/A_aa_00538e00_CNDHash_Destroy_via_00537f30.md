# Review A (reconstruction fidelity): `aa_00538e00` CNDHash_Destroy_via_00537f30

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538e00` |
| **VA** | `0x00538e00` |
| **Canonical name** | `CNDHash_Destroy` (owning remove+delete; remove body `FUN_00537f30`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00538e00_CNDHash_Destroy_via_00537f30.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, remove callee |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Owning destroy by key** — `__thiscall Destroy(hash*, uint key)`:

1. If lock `+0x1d` → log `"HashError:Destroy, already locked for traversal"` + `VOG_DEBUG_STOP`; continue.
2. Call remove twin `FUN_00537f30(key, &keySlot)` — **reuses stack key slot as outValue**.
3. If remove HRESULT `>= 0` (success 0; miss `0x80004005` is negative) → `operator_delete(outValue)`.
4. Ghidra falsely marks `operator_delete` as noreturn — **it returns**; destroy returns void after.

Callee `00537f30` is remove+dead-delete-stub (vtbl `009cefe4` family). True ownership free is **here**, not in remove.

Caller: `CVOGReaction_CompleteObjective` `0x00533f90`.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw | **Confirmed** |
| Key slot reused as out | **Confirmed** |
| Free only on success | **Confirmed** (signed `iVar1 >= 0`) |
| Double lock log possible (destroy + remove) | **High** |
| `operator_delete` noreturn warning wrong | **Confirmed** |

---

## 3. Recovered CF

```c
// void __thiscall CNDHash_Destroy(hash*, uint key)
if (hash->lock) log Destroy-locked;
void *val = (void*)(uintptr_t)key; // stack slot
hr = Remove_00537f30(hash, key, &val); // overwrites val with payload*
if (hr >= 0) operator_delete(val);
```

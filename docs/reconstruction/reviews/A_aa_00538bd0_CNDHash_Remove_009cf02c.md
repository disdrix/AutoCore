# Review A (reconstruction fidelity): `aa_00538bd0` CNDHash_Remove_009cf02c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538bd0` |
| **VA** | `0x00538bd0` |
| **Canonical name** | `CNDHash_Remove_009cf02c` (CNDHash remove twin; node vtbl `PTR_FUN_009cf02c`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00538bd0_CNDHash_Remove_009cf02c.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile`, `force_decompile`, `FUN_004e2ca0`, callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Same **remove** CF as sealed `0x00538b20` / family:

1. Optional out zero.
2. Lock `+0x1d` → log `HashError:remove…`; continue.
3. `FUN_004e2ca0(key)` bucket find+unlink.
4. Miss → `0x80004005`; hit → out value, clear, list unlink, freelist push @ `+0x20`, count--, return 0.
5. **No** `operator_delete` in body (payload ownership to out/caller).
6. Node vtbl stamp `PTR_FUN_009cf02c` before freelist overwrite.

Sealed caller: `CVOGReaction_CompleteObjective` `0x00533f90`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live A/B | batch + force decompile — **identical** |
| Raw | `raw/aa_00538bd0_FUN_00538bd0.md` |
| Caller | CompleteObjective |

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw | **Confirmed** |
| Non-owning remove (no delete) | **Confirmed** |
| Vtbl `009cf02c` | **Confirmed** |
| Matches insert twin `0x0053c460` node family | **High** |

---

## 4. Recovered CF

```c
// int __thiscall CNDHash_Remove(hash*, uint key, void **outOpt)
// identical to 0x00538b20 except vtbl = PTR_FUN_009cf02c
```

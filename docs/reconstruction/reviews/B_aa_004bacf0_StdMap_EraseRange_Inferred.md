# Review B (skeptical / adversarial): `aa_004bacf0` StdMap_EraseRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bacf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bacf0_StdMap_EraseRange_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Intrusive list remove-by-payload | Uses RB successor + `004baa30` map erase | **Falsified** as list |
| 2 | Only full clear (no partial) | Partial loop when not full-range | **Falsified** — both paths |
| 3 | Not STL | `004baa30` throws `"invalid map/set<T> iterator"` | **Survives** as map/set |
| 4 | Frees NDSpecialFX host | Only nodes; host is caller-owned | **Falsified** as host free |
| 5 | Same as `004b85d0` | Different structures (map facade vs list heads) | **Distinct** |

---

## 2. Live ≡ raw

Live decompile matches raw `aa_004bacf0`. Callee `004baa30` live body contains the standard invalid-iterator throw string and rebalance helpers (`FUN_004e22d0`, `FUN_006753b0`) — seals STL erase.

---

## 3. Surviving contract

```
// thiscall map{ head*@+4, size@+8 }
// if first==*head && last==head: destroy tree; size=0; *out=*head
// else: while first!=last: succ=successor(first); erase(first); first=succ
// *out = first
```

**Gaps kept:** K/V types; `004badb0` owner.

**Verdict:** **accept-with-gaps**.

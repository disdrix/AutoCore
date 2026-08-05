# Review B (skeptical / adversarial): `aa_004d7e30` Client_Combat_ApplySingleHitMaybeDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d7e30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d7e30_Client_Combat_ApplySingleHitMaybeDefer_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same function as multi-target `004da2e0` | No entry loop; count forced 1; different callers | **Falsified** merge |
| 2 | Always enqueues deferred record | Skipped when `host+0x7e==0` and `param_8==0` | **Survives** as gated |
| 3 | Hits filtered/dead targets | Requires `vtbl+0x198()==0` | **Survives** gate |
| 4 | Only applies floaters | Calls full `004d78e0` (pools/shield) | **Falsified** floater-only |
| 5 | Deferred blob size multiplies by hit count | Always `operator_new__(0x20)` once | **Survives** single-entry |

---

## 2. Live ≡ raw

Live matches raw: gate → `004d78e0` → optional 0x28 pack → `004e1600`. Callers are weapon/combat sites, not the multi-target batch callers of `004da2e0`.

---

## 3. Surviving contract

```
// this = host (+0x7E)
// if !target || target.vtbl[0x198](): return 0
// status = ApplyHit_004d78e0(...)
// if !host[+0x7E] && !param_8: return status
// pack 0x28 { transform, count=1, 0x20 blob } → Enqueue_004e1600
// return status
```

**Gaps kept:** product names; full hit-meta schema.

**Verdict:** **accept-with-gaps**.

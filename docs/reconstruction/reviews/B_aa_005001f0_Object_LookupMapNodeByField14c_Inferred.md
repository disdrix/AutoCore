# Review B (skeptical / adversarial): `aa_005001f0` Object_LookupMapNodeByField14c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005001f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005001f0_Object_LookupMapNodeByField14c_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Computes loot float itself | Only lookup; float at ret+0x178 by caller | **Falsified** as formula |
| 2 | Void no useful return | OnDeath assigns EAX | **Falsified** void contract |
| 3 | Key at +0x150 | Body uses **+0x14c** | **Falsified** +0x150 |
| 4 | Domain = kill XP only | Kill precheck + objective callers | **Falsified** sole domain |
| 5 | Always inserts | `0040b330` may return existing | **Survives** find-or-insert |

---

## 2. Live ≡ raw

Two-instruction semantic body (load + call). Wrapper sealed; map dual residual.

---

## 3. Surviving contract

```
// ECX=obj* → EAX = MapLookup(obj->key@+0x14c) value*
```

**Verdict:** **accept-with-gaps**.

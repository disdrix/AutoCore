# Review B (skeptical / adversarial): `aa_004bb070` Object_ResolveTfIdGetIdentity_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bb070_Object_ResolveTfIdGetIdentity_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identical to `Object_ResolveFromTFID` (`004bb950`) | Calls `ResolveObjectTarget` then **extra** `vtbl+0x1d8` | **Falsified** merge |
| 2 | Applies damage / floaters | No combat callees in body | **Falsified** as apply |
| 3 | Always returns raw resolved object | Returns virtual result, not `piVar1` | **Survives** as identity get |
| 4 | Combat-only | Mission dialog + other callers | **Falsified** combat-only |
| 5 | Type-0x12-only | Type check is at **callers**, not here | **Survives** as general helper |

---

## 2. Live ≡ raw

Live matches raw three-line body. Callers include both `004da2e0` and `004d7e30` (live `get_function_callers`).

---

## 3. Surviving contract

```
// blob → ResolveObjectTarget(blob+2 byte, blob[0], blob[1])
// if null → 0 else → obj->vtbl[0x1d8]()
```

**Gaps kept:** product name of `+0x1d8`; blob vs TFID_16 formal.

**Verdict:** **accept-with-gaps**.

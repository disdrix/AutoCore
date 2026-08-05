# Review B (skeptical / adversarial): `aa_0042b250` LinkedListHead_Ctor_00a9b1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b250` |
| **VA** | `0x0042b250` |
| **Canonical name** | `LinkedListHead_Ctor_00a9b1dc_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b250_LinkedListHead_Ctor_00a9b1dc_Inferred.md` |
| **Live tools** | batch decompile; Damage/TNL callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full BitStream bind (sets +0x0c..+0x38) | Only 3 dwords touched | **Falsified** BindFromBuffer identity |
| 2 | Vtbl is `009d7b94` / `009d7b00` | Live `00a9b1dc` | **Falsified** |
| 3 | Allocates buffer | No calls | **Falsified** |
| 4 | Clean adds fields | Matches 3 stores | **Falsified** divergence |
| 5 | Same body as clear twin `0042b270` | Twin walks chain | **Falsified** merge |

---

## 2. Surviving contract

```
Ctor(this):
  this.vtbl = 00a9b1dc
  this[+4] = 0
  this[+8] = 0
```

**Verdict:** **accept-with-gaps.** Accept A.

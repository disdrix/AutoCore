# Review B (skeptical / adversarial): `aa_0041a810` Locale_MbcsToWideThenInvoke_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a810` |
| **VA** | `0x0041a810` |
| **Canonical name** | `Locale_MbcsToWideThenInvoke_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041a810_Locale_MbcsToWideThenInvoke_Inferred.md` |
| **Live tools** | batch decompile; Win32 MB2WC |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always converts to wide | Null EBX skips MB2WC | **Falsified** always-convert |
| 2 | Always calls `0041de50` | Gated on `00422d10() >= 0` | **Falsified** |
| 3 | Uses fixed CP_ACP only | Code page from function pointer | **Falsified** constant-CP |
| 4 | Heap-allocates wide buffer | Stack alloca / chkstk | **Falsified** |
| 5 | Clean fully resolves stack formals | Spacebase warning remains | **Attack fails** (gap accepted) |

---

## 2. Surviving contract

```
If str null: maybe 00422d10 → 0041de50(p3,p4)
Else: MB2WC(str) → 00422d10(wide?) → on success 0041de50(p3,p4,p6,p7)
Formal map residual; API chain High.
```

**Verdict:** **accept-with-gaps.** Accept A on role CF; formals residual.

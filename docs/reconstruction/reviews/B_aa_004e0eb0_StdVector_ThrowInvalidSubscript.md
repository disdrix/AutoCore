# Review B (skeptical / adversarial): `aa_004e0eb0` StdVector_ThrowInvalidSubscript

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e0eb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e0eb0_StdVector_ThrowInvalidSubscript.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Silent no-op / return error code | `_CxxThrowException` noreturn | **Falsified** as soft fail |
| 2 | Combat-specific error | Generic STL message; multi-domain callers | **Falsified** combat-only |
| 3 | Same as insert-N `004e39d0` | No buffer math; pure throw | **Falsified** merge |
| 4 | Message is different string | Live literal exact match | **Survives** |

---

## 2. Live ≡ raw

Live matches raw SEH + string + throw. Callers include `FUN_004da2e0`.

---

## 3. Surviving contract

```
// noreturn throw with "invalid vector<T> subscript"
```

**Gaps kept:** precise exception RTTI id only.

**Verdict:** **accept**.

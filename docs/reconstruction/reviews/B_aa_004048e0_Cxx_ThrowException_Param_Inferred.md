# Review B (skeptical / adversarial): `aa_004048e0` Cxx_ThrowException_Param_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004048e0` |
| **VA** | `0x004048e0` |
| **Canonical name** | `Cxx_ThrowException_Param_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004048e0_Cxx_ThrowException_Param_Inferred.md` |
| **Live tools** | Ghidra decompile + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function returns / logs then continues | Decompiler “does not return”; no `ret` | **Attack fails** — pure throw |
| 2 | Hardcodes E_OUTOFMEMORY | Body never embeds `0x8007000E` | **Falsified** constant-HR claim; HR is **caller-supplied** |
| 3 | Is `_com_issue_error` | Different VA; that unit is `0x00717f00` | **Falsified** |
| 4 | Game-owned skill logic | Shared CRT throw leaf | **Falsified** as skill-specific |
| 5 | ThrowInfo proves `_com_error` type | Only pointer sealed | **Unproven** exact C++ type |

---

## 2. Surviving contract

```
Cxx_ThrowException_Param(param_1):
  never returns
  _CxxThrowException(&stack_copy(param_1), &DAT_00acc3fc)
```

Skill/DB loaders call this after failed `SysAllocString` / hard COM failures. Porting skill defs does **not** require reimplementing this throw — map to server-side error return instead.

**Verdict:** **accept-with-gaps**

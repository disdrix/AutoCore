# Review B (skeptical / adversarial): `aa_00419ed0` Com_CallVtbl90_OutIface_OptionalRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ed0` |
| **VA** | `0x00419ed0` |
| **Canonical name** | `Com_CallVtbl90_OutIface_OptionalRelease_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00419ed0_Com_CallVtbl90_OutIface_OptionalRelease_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Call is `IUnknown::QueryInterface` | Bytes `call [ecx+0x90]` | **Falsified** QI claim |
| 2 | `param_2` is `IID*` | Used as object whose **first dword** is method arg; then released as BSTR holder | **Falsified** pure-IID claim |
| 3 | Always releases param_2 | Only if non-null | **Falsified** always-release |
| 4 | Mission-only | Shared across DB loaders | **Falsified** exclusivity |
| 5 | Method is skill-specific | Same helper for many tables | **Falsified** |

---

## 2. Surviving contract

```
hr = (*this->vtbl)[+0x90](this, param2?*param2:0, &out)
if hr<0: _com_issue_errorex(hr, this, &IID_00a86128)
*param_1 = out
if param2: ReleaseHolder(param2)
return param_1
```

Port: replace with native “open table by xpath/name” without COM vtbl.

**Verdict:** **accept-with-gaps**

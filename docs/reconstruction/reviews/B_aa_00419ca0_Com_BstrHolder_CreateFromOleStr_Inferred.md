# Review B (skeptical / adversarial): `aa_00419ca0` Com_BstrHolder_CreateFromOleStr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ca0` |
| **VA** | `0x00419ca0` |
| **Canonical name** | `Com_BstrHolder_CreateFromOleStr_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00419ca0_Com_BstrHolder_CreateFromOleStr_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Mission-only helper | Prior alias `Mission_bActiveObjectiveOverride` | **Falsified** exclusivity — multi-DB caller set |
| 2 | Pure `SysAllocString` | Also `operator_new` + refcount object | **Falsified** as bare BSTR alloc |
| 3 | Returns BSTR directly | Returns `param_1` with `*param_1 = holder*` | **Falsified** BSTR-return claim |
| 4 | Null EDI always errors | `SysAllocString(null)` + only errors if alloc fails **and** EDI non-null; separate null-holder check | **Nuanced** — empty source may yield null BSTR without first `_com_issue_error` path |
| 5 | Name `_bstr_t` is CRT-exact | No Ghidra library symbol on this VA | **Unproven** product name — `_Inferred` required |

---

## 2. Surviving contract

```
out = new Holder{ bstr=SysAllocString(edi), extra=0, ref=1 }
*param_1 = out; fail → _com_issue_error(E_OUTOFMEMORY)
return param_1
```

Do **not** treat as mission objective logic. For AutoCore skill table load, replace with native string + no COM holder.

**Verdict:** **accept-with-gaps**

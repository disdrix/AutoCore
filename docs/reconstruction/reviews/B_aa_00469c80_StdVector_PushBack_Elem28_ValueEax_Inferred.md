# Review B (skeptical / adversarial): `aa_00469c80` StdVector_PushBack_Elem28_ValueEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469c80` |
| **VA** | `0x00469c80` |
| **Canonical name** | `StdVector_PushBack_Elem28_ValueEax_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-C) |
| **Counterpart** | `reviews/A_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Same ABI as RC `StdVector_PushBack_RcElem28` (`00460f90`)? | **No** — RC uses **EAX=vec, ECX=value**; this unit **ECX=vec, EAX=value** |
| Decompiler `in_EAX` is phantom garbage? | **No** — `mov ebx,eax` at entry; value forwarded to fill-n EBX and insert-one stack |
| Decompiler `FUN_0046a260(param_1)` means stack vec formal? | **No** — bytes: **ECX=1, EAX=end, EBX=value**; extra push cleaned; W36-M register ABI |
| This is insert-n / resize public API? | **No** — only count=1 fill or insert-one-at-end |
| thiscall (ECX=this only, value on stack)? | **No** — value never loaded from stack in body; comes from EAX |
| assPackManager product name from scaffold? | **Reject** — container helper only; no plate/RTTI on VA |
| Returns iterator / end pointer? | **No** — both paths bare `C3` without result setup; void |

---

## Residual risks

1. Product demangle / concrete POD T.
2. Why prologue pushes vec then reloads for ignored fill-n stack arg (harmless).
3. No runtime proof of caller value lifetime.

---

## Minimal sealed model

```
StdVector_PushBack_Elem28_ValueEax(vec@ECX, value@EAX):
  size = empty? 0 : (end-begin)/0x1c
  if begin && size < capacity:
    FillN_CountEcx(1, end, value); end += 0x1c; ret
  InsertOne_Rebind(vec@EDI, &outIt, end, value); ret
```

---

## Verdict

Do not unify with RC push_back register ABI. **accept-with-gaps**.

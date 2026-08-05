# Review B (skeptical / adversarial): `aa_00469e20` StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469e20` |
| **VA** | `0x00469e20` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-Q) |
| **Counterpart** | `reviews/A_aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Multi-insert / insert-n public API? | **No** — hardcodes `push 1`; thin wrapper |
| ECX is vec (thiscall like `0040dbf0`)? | **No** — **EDI** holds vec; ECX only used in divide temps |
| Value is in EAX only (parent decompiler `in_EAX`)? | **No** for this unit — body loads **value*** from **stack2** (`mov edx,[esp+0x18]`); parent must pass third stack formal |
| Index after insert (stale begin)? | **No** — index computed **before** call; rebind uses **new** begin |
| Empty-size branch forces index=0 wrongly when where≠begin? | Only when size==0; correct for empty vector insert |
| Same as RC `004612d0`? | Same CF/ABI shell; engine is POD ValueEdx InsertN not RC InsertN |
| Same as W34-Q InsertN itself? | **No** — this is insert-one + rebind only |
| assPackManager scaffold name? | **Reject** — container helper only |

---

## Residual risks

1. Product demangle / T identity.  
2. Parent push_back spare-cap path formal residual (not owned).  
3. No runtime.

---

## Minimal sealed model

```
StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(vec@EDI, outIt, where, value*):
  index = empty ? 0 : (where-begin)/0x1c
  InsertN_Elem28_ValueEdx(value*@EDX, vec, where, 1)
  *outIt = begin' + index*0x1c
  return outIt; ret 0xC
```

---

## Verdict

Do not unify ABI with thiscall dword insert-one or RC insert-one engine. **accept-with-gaps**.

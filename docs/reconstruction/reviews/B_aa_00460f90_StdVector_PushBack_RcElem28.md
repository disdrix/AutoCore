# Review B (skeptical / adversarial): `aa_00460f90` StdVector_PushBack_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00460f90` |
| **VA** | `0x00460f90` |
| **Canonical name** | `StdVector_PushBack_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-O) |
| **Counterpart** | `reviews/A_aa_00460f90_StdVector_PushBack_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this insert-n / resize not push_back? | **No** — always count=1 at end; no arbitrary `where` formal |
| Is value by-value 0x1c on stack? | **No** — ECX pointer only; fill-n / insert-one take value* |
| Is thiscall ECX=vec? | **No** — EAX=vec (`mov edi,eax`); ECX=value*; caller @`00966449` LEA value into ECX, ADD vec into EAX |
| Does slow path need returned iterator? | **No** — outIt local discarded; push_back returns void |
| Same as dword push_back `004406e0`? | Cousin shape only; stride/ABI/lifetime differ (RC 0x1c vs dword) |
| Scaffold gfxDevice name product? | **Reject** — structural `StdVector_PushBack_RcElem28` only |
| Body size wrong? | Exclusive end **`0x00461011`**, **129 B** — bytes win |

---

## Residual risks

1. Product T English (mesh/UI residual parent only).  
2. No runtime.  
3. Insert-one third formal / RET C sealed elsewhere; this unit only routes to it.

---

## Minimal sealed model

```
StdVector_PushBack_RcElem28(vec@EAX, value@ECX):
  size = begin ? (end-begin)/0x1c : 0
  if begin && size < capacity:
    StdUninitFillN_RcElem28(value, 1, end)
    end += 0x1c
  else:
    StdVector_InsertOne_RebindIt_RcElem28(vec, &tmp, end, value)
  ret 0
```

---

## Verdict

Push_back router fully byte-sealed over W35-O fill-n and W35-Q insert-one. Do not port as POD push or thiscall dword twin. **accept-with-gaps**.

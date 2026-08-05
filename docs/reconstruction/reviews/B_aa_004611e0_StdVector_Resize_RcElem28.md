# Review B (skeptical / adversarial): `aa_004611e0` StdVector_Resize_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004611e0` |
| **VA** | `0x004611e0` |
| **Canonical name** | `StdVector_Resize_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-Q) |
| **Counterpart** | `reviews/A_aa_004611e0_StdVector_Resize_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this insert-n itself? | **No** — thin resize shell; grows via `004617a0`, shrinks via `00461720` |
| Is ECX the vector (thiscall)? | **No** — ECX is new_size (`mov ebx,ecx`); **EDI** is vec |
| Is RET 0x1C seven pointer args? | **No** — single by-value T of size **0x1c** (MSVC non-trivial param) |
| Is epilogue Release a free dangling pointer? | **No** — field is T+0x10 resource; matches RC family of InsertN |
| POD resize / memmove? | **No** — uses RC insert-n + RC erase; resource dtor |
| Same as LogicUiEventQueue_Resize? | Pattern twin only — different stride (0x138) and POD lifetime |
| gfxDevice product plate from scaffold? | **Reject** — sole caller is mesh-weight UI residual, not device |

---

## Residual risks

1. Product T name / exact MSVC demangle.  
2. `FUN_00461720` destroy-range formal map not dual-sealed here.  
3. Caller `FUN_00965ab0` stack construction of by-value T residual.  
4. No runtime.

---

## Minimal sealed model

```
StdVector_Resize_RcElem28(vec@EDI, n@ECX, value@stack[0x1c]):
  size = (end-begin)/0x1c or 0
  if size < n: InsertN_RcElem28(&value, vec, end, n-size)
  elif begin && n < size: erase [begin+n*0x1c, end)
  Release(value.resource); ret 0x1C
```

---

## Verdict

Do not treat as thiscall ECX=vec or as POD resize. **accept-with-gaps**.

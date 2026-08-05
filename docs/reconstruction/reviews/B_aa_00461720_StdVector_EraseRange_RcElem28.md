# Review B (skeptical / adversarial): `aa_00461720` StdVector_EraseRange_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461720` |
| **VA** | `0x00461720` |
| **Canonical name** | `StdVector_EraseRange_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-N) |
| **Counterpart** | `reviews/A_aa_00461720_StdVector_EraseRange_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this destroy-range only (`00461780`)? | **No** — also move-assigns tail via `00461e60` and publishes `end`; destroy is leftover only |
| Is this insert-n / resize itself? | **No** — sole parent is resize shrink; body never grows |
| POD memmove erase? | **No** — RC move helper AddRef/Release `@+0x10`; destroy leaf Release |
| RET 0 / register formals like destroy-range? | **No** — **`C2 10 00`** four stack formals |
| first/last swapped? | **No** — equal check EAX/EDX; call order `(last,end,first)` with EAX=first dest matches MSVC erase |
| Clears capacity / frees buffer? | **No** — only writes `end@+8`; parent owns buffer free |
| gfxDevice product plate from scaffold? | **Reject** — structural erase helper; product residual only via resize→overlay chain |

---

## Residual risks

1. Product T name / exact MSVC demangle.  
2. Full formal map of `FUN_00461e60` (decompiler drops third stack formal; caller pushes 3 + EAX).  
3. No runtime.

---

## Minimal sealed model

```
StdVector_EraseRange_RcElem28(vec, outIt, first, last)  // ret 0x10
  if first == last: *outIt = first; return outIt
  new_end = MoveAssignRange_Rc28(dest=first, [last, end))
  destroy [new_end, end) via Release@+0x10 stride 0x1c
  end = new_end; *outIt = first; return outIt
```

---

## Verdict

Do not treat as destroy-only, POD erase, or register-ABI sibling. **accept-with-gaps**.

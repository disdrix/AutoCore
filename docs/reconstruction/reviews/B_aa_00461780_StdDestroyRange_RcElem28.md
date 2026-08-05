# Review B (skeptical / adversarial): `aa_00461780` StdDestroyRange_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461780` |
| **VA** | `0x00461780` |
| **Canonical name** | `StdDestroyRange_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-O) |
| **Counterpart** | `reviews/A_aa_00461780_StdDestroyRange_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this POD no-op / empty dtor range? | **No** — always calls `FUN_00460d70` which Releases `@+0x10` |
| Is EDI a phantom / decompiler artifact? | **No** — call sites `mov edi, [vec+8]` / load end before call; `CMP ESI,EDI` in body |
| Stack formals / thiscall? | **No** — pure register (EAX/EDI), `RET 0`, no `C2` |
| Same as string destroy-range? | Structural cousin only; this T is RC shared* not basic_string |
| operator delete included? | **No** — parent deletes after this returns; body only destroys |
| Scaffold gfxDevice name product? | **Reject** — structural destroy-range name only |
| Ghidra end `00461796` size wrong? | Inclusive end; exclusive **`00461797`**, size **23** — **bytes win** |

---

## Residual risks

1. Product T name.  
2. `FUN_00460d70` plate residual (refcount / vtbl+8).  
3. No runtime.

---

## Minimal sealed model

```
StdDestroyRange_RcElem28(begin@EAX, end@EDI):
  for cur in [begin, end) step 0x1c:
    FUN_00460d70(cur)   // Release shared@+0x10
  ret 0
```

---

## Verdict

Thin, fully byte-sealed destroy walker. Do not treat as free/delete or POD skip. **accept-with-gaps**.

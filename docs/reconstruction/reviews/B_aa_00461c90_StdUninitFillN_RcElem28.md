# Review B (skeptical / adversarial): `aa_00461c90` StdUninitFillN_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461c90` |
| **VA** | `0x00461c90` |
| **Canonical name** | `StdUninitFillN_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-O) |
| **Counterpart** | `reviews/A_aa_00461c90_StdUninitFillN_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this POD memmove / memcpy fill? | **No** — AddRef path on `@+0x10`; SEH; not trivial |
| Same ABI as BasicString fill-n (`RET C` / thiscall)? | **No** — ECX=value EDX=count stack dest **RET 0** |
| Same as Pod28 fill helpers? | **No** — resource lifetime; not 7-lane MOVSS trivial |
| Is dest ECX / thiscall vector? | **No** — ECX is value source (`8B F9`); dest from stack |
| Ghidra classification “leaf” means no side effects? | **No** — indirect vtbl call + EH; leaf only means no direct FUN_* callees |
| Scaffold `Named_CalleeOf_*gfxDevice*` product? | **Reject** — structural fill-n name only |
| Decompiler complete body? | **No** — EH unwind Release path present in bytes, thin in decompile; **bytes win** |
| Two stack args required? | Callers push extra unused dword; body only reads `[ebp+8]` |

---

## Residual risks

1. Product T name / gfx domain plate.  
2. AddRef gate (refcount becomes 1 → vtbl+4) is non-classic COM — must not invent IUnknown.  
3. Optional unused stack formal residual (allocator ghost?).  
4. No runtime.

---

## Minimal sealed model

```
StdUninitFillN_RcElem28(value@ECX, count@EDX, dest@stack):
  for i in 0..count-1:
    if dest:
      copy fields; AddRef(value.shared@+0x10); store into dest
    dest += 0x1c
  // EH unwind: Release constructed [start, cur)
  ret 0
```

---

## Verdict

Do not unify with POD fill, BasicString fill-n, or raw memmove. **accept-with-gaps**.

# Review B (skeptical / adversarial): `aa_004612d0` StdVector_InsertOne_RebindIt_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004612d0` |
| **VA** | `0x004612d0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-Q) |
| **Counterpart** | `reviews/A_aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Multi-insert / insert-n public API? | **No** — hardcodes `push 1`; thin wrapper |
| ECX is vec (thiscall like `0040dbf0`)? | **No** — **EDI** holds vec; ECX only loaded as value* into InsertN |
| Index after insert (use stale begin)? | **No** — index computed **before** call; rebind uses **new** begin |
| Empty-size branch forces index=0 wrongly when where!=begin? | Only when size==0; correct for empty vector insert |
| POD memmove insert? | **No** — routes to RC InsertN with AddRef/Release |
| Same as dword `StdVector_InsertOne_RebindIt_Thiscall`? | Same CF pattern, different ABI (EDI vs ECX) and stride 0x1c vs 4 |
| gfxDevice scaffold name? | **Reject** — container helper only |

---

## Residual risks

1. Product demangle / T identity.  
2. Push_back parent spare-cap path formal residual.  
3. No runtime.

---

## Minimal sealed model

```
StdVector_InsertOne_RebindIt_RcElem28(vec@EDI, outIt, where, value*):
  index = empty ? 0 : (where-begin)/0x1c
  InsertN_RcElem28(value*, vec, where, 1)
  *outIt = begin' + index*0x1c
  return outIt; ret 0xC
```

---

## Verdict

Do not unify ABI with thiscall dword insert-one. **accept-with-gaps**.

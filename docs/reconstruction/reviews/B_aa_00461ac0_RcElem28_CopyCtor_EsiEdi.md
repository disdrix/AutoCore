# Review B (skeptical / adversarial): `aa_00461ac0` RcElem28_CopyCtor_EsiEdi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461ac0` |
| **VA** | `0x00461ac0` |
| **Canonical name** | `RcElem28_CopyCtor_EsiEdi` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-N) |
| **Counterpart** | `reviews/A_aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this POD memmove / no lifetime? | **No** — resource `@+0x10` AddRef path; null-checked |
| Is ESI/EDI decompiler phantom? | **No** — sole parent sets ESI/EDI before call; loads/stores match |
| Is this `basic_string` copy? | **No** — no SSO/char buffer; layout is 4 dwords + shared + 3 bytes + dword |
| Is vtbl+4 a dtor? | **No** — runs on **increment to 1**, not decrement; Release is vtbl+8 on parent path |
| Assign vs construct? | Placement construct into EDI; no prior dest Release (uninit dest assumed) |
| Ghidra end `00461b10` | Off-by-one exclusive; bytes exclusive **`00461b11`**, size **81** |

---

## Residual risks

1. Product T name / domain plate.  
2. AddRef-on-transition-to-1 is non-classic COM — port must match observed gate.  
3. No runtime.

---

## Minimal sealed model

```
RcElem28_CopyCtor_EsiEdi(ESI=src, EDI=dst):
  dst[0..3] = src[0..3]
  if src.resource:
    ++resource.refcount
    if resource.refcount == 1: resource.vtbl[+4]()
  dst.resource = src.resource
  dst[+0x14..+0x16] = src[…]
  dst[+0x18] = src[+0x18]
  return dst
```

---

## Verdict

Do not treat as POD copy or string. Register ABI + AddRef sealed. **accept-with-gaps**.

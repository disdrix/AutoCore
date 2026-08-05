# Review B (skeptical / adversarial): `aa_004620b0` StdVector_UninitializedCopy_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004620b0` |
| **VA** | `0x004620b0` |
| **Canonical name** | `StdVector_UninitializedCopy_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-N) |
| **Counterpart** | `reviews/A_aa_004620b0_StdVector_UninitializedCopy_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this POD `memmove` / `memcpy` range? | **No** — per-element AddRef; SEH |
| Is Ghidra `__thiscall` correct? | **No for epilogue** — plain `C3`, caller cleans 8; ECX is first formal only |
| Same as BasicString uninit-copy? | **No** — different element layout; no string IAT |
| Same as copy-ctor leaf only? | Leaf is single-element register ABI; this is ranged + EH |
| Is null-dest path dead? | Reachable in CF; writes skipped, pointer advanced — seal as observed |
| operator path noreturn on EH? | EH rethrow exists in bytes; happy path returns normally |
| Ghidra end `00462193` | Off-by-one; exclusive **`00462194`**, size **228** |

---

## Residual risks

1. Product class name.  
2. EH Release loop exactness vs clean (happy path sealed).  
3. No runtime.

---

## Minimal sealed model

```
StdVector_UninitializedCopy_RcElem28(src@ECX, src_end, dest):
  SEH enter
  while src != src_end:
    if dest: construct *dest from *src (AddRef resource@+0x10)
    dest += 0x1c; src += 0x1c
  SEH leave; return dest
  // EH: Release constructed [saved_dest, dest); rethrow
```

---

## Verdict

Do not port as POD memmove or as thiscall `RET 8`. **accept-with-gaps**.

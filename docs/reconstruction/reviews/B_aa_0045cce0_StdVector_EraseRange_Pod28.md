# Review B (skeptical / adversarial): `aa_0045cce0` StdVector_EraseRange_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cce0` |
| **VA** | `0x0045cce0` |
| **Canonical name** | `StdVector_EraseRange_Pod28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-L) |
| **Counterpart** | `reviews/A_aa_0045cce0_StdVector_EraseRange_Pod28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this string erase / basic_string? | **No** — pure 7-dword POD move; no IAT, no dtor, RET 10 not string ABI |
| Is this insert / copy_backward? | **No** — forward shift from last toward end onto first; end shrinks |
| Is stride 0x20 / other? | **No** — `ADD 0x1C` + ECX=7 sealed |
| Is this destroy-range only (no shift)? | **No** — when last≠end, elements are copied; no dtor calls |
| Single-iterator erase only? | **No** — first+last range form; resize uses first=new_end, last=end |
| Could out_it be unused? | **No** — always `*out_it=first`; return out_it (MSVC erase pattern) |
| anmTrackMaster scaffold name | **Reject** — structural Pod28 erase; multi-parent |

---

## Residual risks

1. Product typename / domain (scaffold anm residual is not a plate).  
2. Sibling InsertN at `0045cd30` not this VA — do not merge.  
3. Parent `00466df0` open under other owner.

---

## Minimal sealed model

```
StdVector_EraseRange_Pod28(vec, out_it, first, last):
  if first != last:
    end = vec->end
    dest = first
    while last != end:
      copy 7 dwords last → dest
      last += 0x1c; dest += 0x1c
    vec->end = dest
  *out_it = first
  return out_it   // ret 0x10
```

---

## Verdict

Structural POD erase-range leaf sealed. Do not invent string/RC semantics. **accept-with-gaps**.

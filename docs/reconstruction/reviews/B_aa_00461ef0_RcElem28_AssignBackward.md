# Review B (skeptical / adversarial): `aa_00461ef0` RcElem28_AssignBackward

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461ef0` |
| **VA** | `0x00461ef0` |
| **Canonical name** | `RcElem28_AssignBackward` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-P) |
| **Counterpart** | `reviews/A_aa_00461ef0_RcElem28_AssignBackward.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Forward assign / fill? | **No** — both cursors step **backward** by 0x1c |
| Uninit-copy (`FUN_004620b0`)? | **No** — Releases dest resource (live assign) |
| Three stack formals? | **No** — body has **2** stack args; third is **EAX** dest_end |
| Returns void? | **No** — `mov eax,esi` before RET; decompiler returns `in_EAX` |
| BasicString copy_backward twin? | Same *shape* as `0x00431790` but inline RC, not `operator=` |

---

## Residual risks

1. Product T name.  
2. Parent mid-path bound math not re-sealed here (OWN-ONLY).  
3. No runtime.

---

## Minimal sealed model

```
RcElem28_AssignBackward(dest_end@EAX, first, last):
  if first==last: return dest_end
  do:
    last -= 1 elem; dest_end -= 1 elem
    assign *dest_end = *last  // RC
  while last != first
  return dest_end
```

---

## Verdict

Do not treat as fill, uninit-copy, or 3-stack cdecl without EAX. **accept-with-gaps**.

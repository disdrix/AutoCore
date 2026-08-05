# Review B (skeptical / adversarial): `aa_00461e60` RcElem28_AssignRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461e60` |
| **VA** | `0x00461e60` |
| **Canonical name** | `RcElem28_AssignRange` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-Y) |
| **Counterpart** | `reviews/A_aa_00461e60_RcElem28_AssignRange.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this uninit-copy (`FUN_004620b0` family)? | **No** — Releases existing dest resource before store |
| Is this destroy-range (`FUN_00460d70` / `00461780`)? | **No** — copies into dest; destroy is parent loop after return |
| Is this fill-from-one-value (`00461b80`)? | **No** — both cursors advance; range-to-range |
| Is this assign-backward (`00461ef0`)? | **No** — forward walk; lives immediately before backward sibling |
| Is this POD memmove? | **No** — AddRef/Release on `@+0x10` |
| Decompiler 2-arg vs parent 3-push? | **Bytes**: leaf reads EAX+2 stack; third push dead; parent still `ADD ESP,0xC` |
| Ghidra `void` signature? | Ignore; return dest* sealed by `8B C6` + parent `MOV EDI,EAX` |
| Overlap / erase safety? | Parent uses this only as `[last,end) → first` non-overlapping tail for erase; overlap not claimed sealed for general use |

---

## Residual risks

1. Product T name / domain plate.  
2. AddRef-when-becomes-1 is non-COM-classic — port must match retail.  
3. No runtime / bit-exact.

---

## Minimal sealed model

```
RcElem28_AssignRange(dest@EAX, src_first@stack0, src_last@stack1) -> dest':
  if src_first == src_last: return dest
  for s,d in zip([src_first,src_last), dest...):
    copy POD; AddRef(s.res); Release(d.res); d.res = s.res
  return d'
```

---

## Verdict

Do not unify with uninit-copy, destroy, fill, or backward. **accept-with-gaps**.

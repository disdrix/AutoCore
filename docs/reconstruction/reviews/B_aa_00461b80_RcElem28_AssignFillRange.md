# Review B (skeptical / adversarial): `aa_00461b80` RcElem28_AssignFillRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461b80` |
| **VA** | `0x00461b80` |
| **Canonical name** | `RcElem28_AssignFillRange` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-P) |
| **Counterpart** | `reviews/A_aa_00461b80_RcElem28_AssignFillRange.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this uninit fill (`FUN_00461c90`)? | **No** — Releases existing dest resource; used after live slots exist |
| Is EDI advanced (range-to-range)? | **No** — EDI fixed; pure fill from one value |
| Is this POD memmove? | **No** — AddRef/Release on `@+0x10` |
| Is this `basic_string` assign? | **No** — no string IAT; layout matches RcElem28 |
| Ghidra `void` / no params? | Decompiler incomplete; **bytes** seal EAX/EDI/stack |
| Self-assign resource leak? | If dest==source and same resource: AddRef then Release nets zero when distinct objects share resource; if same element (`cur==value`) AddRef then Release on same pointer is net-zero after ++/-- — still unusual but matches retail |

---

## Residual risks

1. Product T name / domain plate.  
2. AddRef-when-becomes-1 gate is non-COM-classic — port must match.  
3. No runtime.

---

## Minimal sealed model

```
RcElem28_AssignFillRange(dest_first@EAX, value@EDI, dest_last@stack):
  for cur in [dest_first, dest_last) step 0x1c:
    copy POD lanes; AddRef(value.res); Release(cur.res); cur.res = value.res
  ret
```

---

## Verdict

Do not unify with uninit-fill or POD relocate. **accept-with-gaps**.

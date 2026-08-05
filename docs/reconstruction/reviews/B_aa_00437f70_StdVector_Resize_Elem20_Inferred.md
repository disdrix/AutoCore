# Review B (skeptical / adversarial): `aa_00437f70` StdVector_Resize_Elem20_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437f70` |
| **VA** | `0x00437f70` |
| **Canonical name** | `StdVector_Resize_Elem20_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W38-F) |
| **Counterpart** | `reviews/A_aa_00437f70_StdVector_Resize_Elem20_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this the same body as Elem56 resize? | **No** — stride **0x14**, magic `0x66666667`, **RET 0x14**, different callees |
| Is ABI identical to `00437e40` (EDI=vec)? | **No** — **ESI=vec**, **ECX=new_size** (EDI holds new_size working copy) |
| Is value a pointer? | **No** — `RET 0x14` implies 20 B by-value blob |
| Is this `reserve` only? | **No** — shrink erase + grow insert at end |
| Is stride not 0x14? | **No** — ÷20 magic + ×0x14 new_end + RET 0x14 |
| Does epilogue prove T is vector-of-0x38? | **Reject** — `FUN_00437f20` decompile looks like Elem56 vector destroy; **do not** seal as stack-T dtor product type without more evidence |
| Decompiler complete? | **No** — misses ESI vec + stack value; **bytes win** |
| Sole caller implies gfxBody product name? | **Reject** — callee-of scaffold only; structural name required |
| Ghidra body end `0043803f` | Inclusive last byte of `C2 14 00`; exclusive **`00438040`**, size **208** |

---

## Residual risks

1. Product typename for 0x14 T open.  
2. InsertN/erase helpers dual-unowned.  
3. Epilogue `FUN_00437f20` residual (possible EH glue / mis-typed neighbor).  
4. No runtime trace.

---

## Minimal sealed model

```
StdVector_Resize_Elem20_Inferred(vec@ESI, new_size@ECX, value@stack[0x14]):
  size = begin? (end−begin)/0x14 : 0
  if size < new_size:
    FUN_004388b0(vec, where=end, count=new_size−size, &value)
  else if begin && new_size < size:
    FUN_00438850(vec, it*, begin+new_size*0x14, end)
  // epilogue FUN_00437f20 residual
  ret 0x14
```

---

## Verdict

Structural resize sealed against sibling Elem56 ABI and POD/BasicString families; epilogue helper not over-claimed. **accept-with-gaps**.

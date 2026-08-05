# Review B (skeptical / adversarial): `aa_0045c4b0` StdVector_Resize_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045c4b0` |
| **VA** | `0x0045c4b0` |
| **Canonical name** | `StdVector_Resize_Pod28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W35-M) |
| **Counterpart** | `reviews/A_aa_0045c4b0_StdVector_Resize_Pod28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this InsertN itself? | **No** — body is thin resize; grow calls sealed `0045cd30` |
| Is ABI ECX=vec like BasicString? | **No** — **EBX=vec**, **ECX=new_size**, **RET 0x1C** |
| Is value a pointer on stack? | **No** — `RET 0x1C` + `LEA` into stack blob; value is **by value** |
| Is this `reserve` / capacity only? | **No** — shrink erases elements; grow inserts at end with fill value |
| Is stride not 0x1c? | **No** — magic `0x92492493` and `new_size*0x1c` lea form sealed |
| Does decompiler show full InsertN formals? | Incomplete — **bytes win**: ECX=count, EDX=vec, stack where+value* into W34-P ABI |
| Equal-size path mutates? | **No** — fall-through to RET when `new_size >= size` after grow branch skipped |
| Ghidra body end `0045c551` | Inclusive last byte of `C2 1C 00`; exclusive **`0045c552`**, size **162** |

---

## Residual risks

1. Product typename / domain residual (anmTrackMaster scaffold **not** sealed).  
2. `FUN_0045cce0` erase semantics dual-unowned — CF sealed from decompile, not dual-reviewed.  
3. Sole parent `FUN_00459750` register/stack setup not dual-owned.  
4. No runtime trace.

---

## Minimal sealed model

```
StdVector_Resize_Pod28(vec@EBX, new_size@ECX, value@stack[0x1c]):
  size = begin? (end−begin)/0x1c : 0
  if size < new_size:
    InsertN_Pod28(new_size−size, vec, where=end, &value)
    ret 0x1c
  if begin && new_size < size:
    erase(vec, begin+new_size*0x1c, end)   // FUN_0045cce0
  ret 0x1c
```

---

## Verdict

Structural resize sealed against InsertN parent and POD family; do not merge with BasicString resize/insert ABIs. **accept-with-gaps**.

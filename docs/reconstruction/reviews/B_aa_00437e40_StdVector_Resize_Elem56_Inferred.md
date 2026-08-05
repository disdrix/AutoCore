# Review B (skeptical / adversarial): `aa_00437e40` StdVector_Resize_Elem56_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437e40` |
| **VA** | `0x00437e40` |
| **Canonical name** | `StdVector_Resize_Elem56_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W38-F) |
| **Counterpart** | `reviews/A_aa_00437e40_StdVector_Resize_Elem56_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this InsertN itself? | **No** — thin resize; grow calls `FUN_00438520` |
| Is ABI ECX=vec like BasicString / thiscall? | **No** — **EDI=vec**, **ECX=new_size**, **RET 0x38** |
| Is value a pointer on stack? | **No** — `RET 0x38` + epilogue dtor on stack blob; value **by value** |
| Is this `reserve` / capacity only? | **No** — shrink erases range; grow inserts at end with fill |
| Is stride not 0x38? | **No** — magic ÷56 + `lea` ×56 + RET 0x38 + dtor of two 0x1c strings |
| Is T POD / CombatFloater 0x38 clone? | **No as POD** — stack dtor runs two `~basic_string`; may share size with other 0x38 types but layout evidence is dual-string |
| Decompiler `__fastcall(uint)` complete? | **No** — misses EDI vec + stack value; **bytes win** |
| Is `FUN_00437da0` vector dtor? | **No** — destroys two strings on ECX object (element / stack T) |
| Equal-size path mutates? | **No** — fall-through after failed grow/shrink predicates |
| Ghidra body end `00437f1d` | Inclusive last byte of `C2 38 00`; exclusive **`00437f1e`**, size **222** |

---

## Residual risks

1. Product typename residual (scaffold gfxBody **not** sealed as product plate).  
2. `FUN_00438520` / `FUN_00438430` dual-unowned — formals from call site only.  
3. Parents beyond thin wrapper `FUN_00437ad0` not dual-owned.  
4. No runtime trace.

---

## Minimal sealed model

```
StdVector_Resize_Elem56_Inferred(vec@EDI, new_size@ECX, value@stack[0x38]):
  size = begin? (end−begin)/0x38 : 0
  if size < new_size:
    FUN_00438520(vec, where=end, count=new_size−size, &value)
  else if begin && new_size < size:
    FUN_00438430(vec, it*, begin+new_size*0x38, end)
  FUN_00437da0(&value)   // two basic_string
  ret 0x38
```

---

## Verdict

Structural resize sealed; dual-string T layout from dtor; do not merge with POD Pod28/BasicString thiscall ABIs or bare CombatFloater product names. **accept-with-gaps**.

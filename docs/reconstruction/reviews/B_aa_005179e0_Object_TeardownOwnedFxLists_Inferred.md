# Review B (skeptical / adversarial): `aa_005179e0` Object_TeardownOwnedFxLists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005179e0` |
| **VA** | `0x005179e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-H) |
| **Counterpart** | `reviews/A_aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `FUN_00516930(0)` means ECX=0 / null this | Entry keeps ECX=this; push 0 is stack formal; callee **`ret 4`** | **this + stack 0** |
| 2 | Decompiler epilogue: null path zeros then returns; non-null only deletes | Bytes always zero triad after optional delete | **Always zero** |
| 3 | StopFinalize / TeardownCore this = outer self | `mov ecx,ebp` before each call | **fx\*** |
| 4 | `operator_delete` never returns (decomp WARNING) | False noreturn; control continues | **Returns** |
| 5 | Only direct CODE callers | 4 DATA vtable installs | **Also virtual** |
| 6 | Product name in binary | None | **`_Inferred`** |
| 7 | Frees every vector entry | Gate skips `+9!=0` or StopFinalize==0 | **Selective free** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free gate + StopFinalize polarity | **Confirmed** | leak / double-free |
| Always-zero triad | **Confirmed** | dtor double-free / stale iters |
| Secondary list first | **Confirmed** | wrong destroy order |
| Product English | Tentative | cosmetic |
| Nested `00516930`/`00517250` full dual | Partial | out of OWN |
| Runtime | Open | |

---

## 3. Surviving contract

```
void Object_TeardownOwnedFxLists_Inferred(void *self) // thiscall
{
  FUN_00516930(self, 0);
  if (sticky = *(self+0x130)) FUN_00517250(self, sticky);
  *(self+0x130) = 0;
  for (fx* in [*(self+0x124), *(self+0x128)))
    if (fx->b9==0 && StopFinalize(fx)) { TeardownCore(fx); delete fx; }
  if (begin = *(self+0x124)) delete begin;
  *(self+0x124)=*(self+0x128)=*(self+0x12c)=0;
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names | No |
| R2 | Full dual of nested list helpers | No for this VA |
| R3 | Runtime multi-entry golden | No for static seal |
| R4 | Exact capacity semantics of `+0x12c` | No (always cleared) |

---

## 5. Concrete checks performed

1. Re-decompile `0x005179e0` — CF matches 2026-07-23 raw.  
2. `read_memory` entry + full walk + epilogue — free gate, always-zero, plain ret.  
3. `read_memory` `FUN_00516930` end — **`C2 04 00`**.  
4. Callers/xrefs — CODE×2 + DATA×4.  
5. Cross-check W27-D StopFinalize free polarity and W26-K tail chain.

---

## 6. Falsifications locked in

- **Reject** treating `FUN_00516930(0)` as null-this call.  
- **Reject** trusting decompiler missing post-delete zeroing.  
- **Reject** assuming unconditional free of every vector entry.  
- **Reject** inventing product symbols without strings/PDB.

**Verdict:** **accept**

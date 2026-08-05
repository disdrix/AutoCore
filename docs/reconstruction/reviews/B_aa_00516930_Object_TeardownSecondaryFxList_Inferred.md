# Review B (skeptical / adversarial): `aa_00516930` Object_TeardownSecondaryFxList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516930` |
| **VA** | `0x00516930` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-N) |
| **Counterpart** | `reviews/A_aa_00516930_Object_TeardownSecondaryFxList_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `__fastcall` single-arg signature | Epilogue **`C2 04 00`**; callers `push 0` / `push 1` | **thiscall + stack formal** |
| 2 | Stack formal is a live mode flag | Body never loads `[esp+…]` / stack arg | **Unread; cleaned only** |
| 3 | Null begin path alone zeros triad; free path never returns | Bytes: free then fall into same `mov [+0x138],0` triad | **Always zero** |
| 4 | `operator_delete` is noreturn (decomp WARNING) | False; control continues | **Returns** |
| 5 | DeactivateClear / TeardownCore this = outer self | `mov ecx,ebx` with `ebx=*it` | **fx\*** |
| 6 | Same free gate as primary (`fx+9`) | No `cmp [fx+9]` in body | **No +9 gate** |
| 7 | Product name in binary | None | **`_Inferred`** |
| 8 | `FUN_00516930(1)` means ECX=1 | `00518370`: keep ECX=this; push 1 is stack | **this + stack 1** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-zero secondary triad | **Confirmed** | dtor double-free / stale iters |
| DeactivateClear before free | **Confirmed** | live FX leak / orphan children |
| Flag bit2 clear | **Confirmed** | mission FX re-entry wrong |
| Unread stack formal | **Confirmed** | wrong ABI port |
| Product English | Tentative | cosmetic |
| Runtime multi-entry golden | Open | |

---

## 3. Surviving contract

```
void Object_TeardownSecondaryFxList_Inferred(void *self, int unused) // thiscall, ret 4
{
  for (fx* in [*(self+0x138), *(self+0x13c)))
    { DeactivateClear(fx); if (fx) { TeardownCore(fx); delete fx; } }
  *(self+0x184) &= ~4;
  if (begin = *(self+0x138)) delete begin;
  *(self+0x138)=*(self+0x13c)=*(self+0x140)=0;
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names | No |
| R2 | Why callers push 0 vs 1 | No (unread) |
| R3 | Null-entry DeactivateClear(ECX=0) safety | No for static CF seal |
| R4 | Runtime golden | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00516930` — CF matches 2026-07-23 raw outer loop.  
2. `read_memory` full body — walk, flag clear, free, **always** triad zero, **`ret 4`**.  
3. Caller sites: `005179e0` push 0; `00518370` push 1 then `or [+0x184],4`.  
4. Relative call targets sealed to `004b7150` / `004b99c0`.  
5. Cross-check W28-H parent residual and W23-H DeactivateClear dual.

---

## 6. Falsifications locked in

- **Reject** trusting decompiler single-arg / missing `ret 4`.  
- **Reject** trusting decompiler missing post-delete triad zeroing.  
- **Reject** treating caller `FUN_00516930(1)` as null/one this pointer.  
- **Reject** inventing a live stack mode without a body load.  
- **Reject** inventing product symbols without strings/PDB.

**Verdict:** **accept**

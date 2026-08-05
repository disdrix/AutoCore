# Review B (skeptical / adversarial): `aa_00584330` Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00584330` |
| **VA** | `0x00584330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W26-K) |
| **Counterpart** | `reviews/A_aa_00584330_Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__fastcall` with only ECX param is free-function style | Entry `push esi; mov esi,ecx` | **thiscall** |
| 2 | Returns via `FUN_005179e0(); return` | Epilogue `lea ecx,…; pop esi; jmp 005179e0` | **Tail jmp** |
| 3 | Same pack as dual-slot wild `(0,e,1,-1)` | Pushes filter char **0** not 1 | **Distinct pack** |
| 4 | Decompiler shows correct ECX for `004b7030` | Missing `mov ecx,[edi]` | **Byte fix required** |
| 5 | Teardown only when effect non-null | Teardown is **after** the if; always runs | **Always tail** |
| 6 | Product name in body | None | **`_Inferred`** |
| 7 | Dual-slot unit is identical | `004c8110` has two slots + filter 1 + different offsets | **Sibling, not alias** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Effect gate + pack constants | **Confirmed** | wrong e300 vs e270 path |
| Table owner `-0x90` | **Confirmed** | fan-out wrong object |
| Host vector + `*it` this | **Confirmed** | apply on wrong host |
| Always tail teardown | **Confirmed** | skip cleanup on null effect |
| Product English | Tentative | cosmetic |
| `005179e0` full semantics | Partial | out of OWN |
| Runtime | Open | |

---

## 3. Surviving contract

```
void Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred(void *self) // thiscall, tail
{
  int effect = *(int *)((char*)self - 0x88);
  if (effect) {
    ForEachHostPtrTablePair(self-0x90, 0, effect, 0, -1);
    for (host* in vb_vector(self-0x8c, 0xac, 0xb0))
      ForEachOwnedBit7(*it, 0, effect, 0, -1);
  }
  goto FUN_005179e0(vbase_adjust(self, -0x8c));
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names | No |
| R2 | Full dual of `005179e0` | No for this VA |
| R3 | Whether any caller depends on EAX after chain | No (tail; void role) |
| R4 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00584330` — CF matches 2026-07-23 raw.  
2. `read_memory` full body — push constants, lea ECX, `mov ecx,[edi]`, rel32 call/jmp.  
3. `get_function_by_address` body end `005843af`.  
4. Cross-check W25-D `004c8110` B-note: "filter char 0 (distinct)" — **confirmed**.  
5. Peek `005179e0` decompile — vector teardown at +0x124/+0x128/+0x130 (context only).

---

## 6. Falsifications locked in

- **Reject** treating unit as normal `ret` epilogue.  
- **Reject** equating pack with dual-slot wild `(0,e,1,-1)`.  
- **Reject** trusting decompiler-omitted host ECX.  
- **Reject** claiming teardown is conditional on effect non-null.  
- **Reject** inventing product symbol without strings/PDB.

**Verdict:** **accept**

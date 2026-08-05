# Review B (skeptical / adversarial): `aa_0058e270` NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e270` |
| **VA** | `0x0058e270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W26-K) |
| **Counterpart** | `reviews/A_aa_0058e270_NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name + 0096d* residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Void with no stack cleanup info | Epilogue `ret 0x0C` | **3 stack dwords cleaned** |
| 2 | `param_4` full int compare to -1 | Entry `cmp al,0xFF` + `movsx` path | **Low-byte wild / signed-byte match** |
| 3 | `0096d550(child+0x914)` is only stack arg / cdecl | Before call: `mov ecx, effect_stop` | **thiscall(this=effect_stop)** |
| 4 | `0096d460` / `0096dc80` this = child | `mov ecx, effect_start` (EDI) | **this = effect_start** |
| 5 | Same as `0058e300` | e300 gates `+0x25c < 0`, no slot formal | **Sibling, not alias** |
| 6 | Many callers (exhaust family) | xrefs: **1** site in `004b7030` | **Exclusive callee** |
| 7 | `want_start`/`want_stop` are bools | Non-zero values loaded into ECX as objects | **Pointers + truthiness** |
| 8 | Product name present | Scaffold alias only | **`_Inferred`**; retire exhaust-only alias |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot gate + wild | **Confirmed** | wrong children toggled |
| Stop/start order | **Confirmed** | wrong lifecycle |
| Active flag bit0 | **Confirmed** | state desync |
| effect_* as particle this | **Confirmed** | crash / wrong attach |
| 0096d* internal semantics | Medium | out of OWN |
| Product English | Tentative | cosmetic |
| Runtime | Open | |

---

## 3. Surviving contract

```
// thiscall ret 0x0C
void NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred(
    void *child, void *effect_start, void *effect_stop, int slot_filter)
{
  uint8_t sf = (uint8_t)slot_filter;
  int slot = *(int*)((char*)child + 0x25c);
  if ((sf == 0xFF || slot == (int)(int8_t)sf) && slot != -1) {
    if (effect_stop)
      FUN_0096d550(effect_stop, *(uint32_t*)((char*)child + 0x914));
    if (effect_start) {
      if (FUN_0096d460(effect_start, *(uint32_t*)((char*)child + 0x258)) == 0) {
        FUN_0096dc80(effect_start,
            *(uint32_t*)((char*)child + 0x258),
            *(uint32_t*)((char*)child + 0x914),
            *(uint32_t*)((char*)child + 0x254));
        *(uint8_t*)((char*)child + 0x90f) |= 1;
        return;
      }
    }
    *(uint8_t*)((char*)child + 0x90f) &= ~1;
  }
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names | No |
| R2 | Full dual of 0096d* | No for this VA |
| R3 | Slot_filter high 24 bits | No — bytes ignore |
| R4 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x0058e270` — CF matches 2026-07-23 raw.  
2. `read_memory` full body through both `ret 0x0C` paths + pad `CC`.  
3. `get_function_by_address` end `0058e2f1`.  
4. `analyze_function_complete` — 1 xref from `004b7067`.  
5. Sibling `0058e300` entry bytes — `cmp [esi+0x25c],0; jge skip` then same ECX=stack-arg pattern.  
6. Cross-check W24-D `004b7030` branch `use_slot_filter!=0 → e270`.

---

## 6. Falsifications locked in

- **Reject** treating `effect_start`/`effect_stop` as pure booleans only.  
- **Reject** claiming multiple direct callers.  
- **Reject** equating unit with `0058e300`.  
- **Reject** decompiler-only `0096d550` signature without ECX=effect_stop.  
- **Reject** exhaust-specific product name as canonical.

**Verdict:** **accept**

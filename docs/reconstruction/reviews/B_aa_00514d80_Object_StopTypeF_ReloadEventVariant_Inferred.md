# Review B (skeptical / adversarial): `aa_00514d80` Object_StopTypeF_ReloadEventVariant_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514d80` |
| **VA** | `0x00514d80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-H) |
| **Counterpart** | `reviews/A_aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompile `FUN_004ba0a0()` uses outer this | `mov ecx,[edi]` = entry | **fx this** |
| 2 | `FUN_004eb3b0()` uses outer this | ECX = `*(esi+0xA8)` | **linked host** |
| 3 | `FUN_004a16d0(0xf,1,-1)` free function with stack-only | ECX = catalog `*(linked+0x88)` | **thiscall catalog** |
| 4 | Same as full teardown `005179e0` (free all) | Stop only; no delete; then reload | **Distinct** |
| 5 | Impl takes / cleans stack arg | Impl `C3`; thunk `ret 4` | **Thunk owns formal** |
| 6 | Type 0xF is character/text | Immediate `0x0F`; LoadEvent event id family | **Event type code** |
| 7 | Product name in body | None | **`_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type gate + StopFinalize-only | **Confirmed** | wrong free/reload |
| LoadEvent pack constants | **Confirmed** | wrong variant |
| Ensure target `+0xA8` | **Confirmed** | catalog on wrong host |
| Virtual apply slot `+0xF8` | **Confirmed** | wrong vfunc |
| Product English | Tentative | cosmetic |
| `vtbl+0xF8` / Ensure duals | Partial | out of OWN |
| Runtime | Open | |

---

## 3. Surviving contract

```
void Object_StopTypeF_ReloadEventVariant_Inferred(void *self) // thiscall
{
  for (fx* in [*(self+0x124), *(self+0x128)))
    if (*(int*)(fx+0x28)==0xF) StopFinalize(fx);
  linked = *(self+0xA8);
  Ensure(linked);
  if (*(linked+0x88)) {
    Ensure(linked);
    fx = LoadEventVariant(*(linked+0x88), 0xF, 1, -1);
    if (fx) self->vtbl[0xF8/4](fx, 1, 0);
  }
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product event / method English | No |
| R2 | Dual of Ensure / vfunc target | No for this VA |
| R3 | Ignored stack formal meaning on public ABI | No (impl ignores) |
| R4 | Runtime golden | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00514d80` — CF matches 2026-07-23 raw.  
2. `read_memory` full body — type cmp, ECX setups, push pack, vtbl call, plain ret.  
3. `read_memory` `FUN_00581500` — vb-adjust + call + **`ret 4`**.  
4. Cross-check W27-D StopFinalize type-0xF caller note; sealed LoadEventVariant dual.  
5. Confirm shared `+0x124/+0x128` with `005179e0`.

---

## 6. Falsifications locked in

- **Reject** equating this unit with full vector free teardown (`005179e0`).  
- **Reject** decompiler-omitted ECX for StopFinalize / Ensure / LoadEvent.  
- **Reject** claiming impl itself is `ret 4`.  
- **Reject** inventing product names without evidence.

**Verdict:** **accept**

# Review B (skeptical / adversarial): `aa_00583f10` NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00583f10` |
| **VA** | `0x00583f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product symbol residual only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** the owned-list walker at `+0x204` | No `+0x204` load; walks ptr tables then calls `004b7030` | **Falsified** if conflated with `004b7030` |
| 2 | stdcall free function | Entry `mov esi,ecx`; epilogue `ret 0x10` | **thiscall** |
| 3 | Decompiler call form complete | Bytes `mov ecx,[edi]` before each call | **Decompiler incomplete** — host is callee this |
| 4 | Single table only | Two ranges: `0x128/0x12c` and `0x13c/0x140` | **Two tables** |
| 5 | Mutates tables / frees hosts | Body only iterates + dispatches | **No mutator** |
| 6 | Scaffold creature-setup alias is product name | Alias is caller-chain only; multi-caller including dual-slot apply | **Reject** as sole name |
| 7 | Product string in body | None | **`_Inferred` required** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `ret 0x10` | **Confirmed** | stack imbalance |
| Dual host* vectors | **Confirmed** | miss half of fan-out |
| Callee this = *it | **Confirmed** | wrong ECX on apply |
| Arg passthrough | **Confirmed** | wrong slot policy |
| Distinct from `004b7030` | **Confirmed** | double-count coverage |
| Product method name | Tentative | cosmetic |
| Runtime / bit-exact | Open | |

---

## 3. Surviving contract

```
// thiscall RET 0x10
void NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(void *owner, int a, int b, char use_slot, int slot)
{
  base = owner + *(*(owner+4)+4);
  for (it = begin(base+0x128); it != end(base+0x12c); it += 4)
    NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(*it, a, b, use_slot, slot);
  for (it = begin(base+0x13c); it != end(base+0x140); it += 4)
    NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(*it, a, b, use_slot, slot);
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ name | No |
| R2 | Table A vs B English | No |
| R3 | EAX return use | No for static seal |
| R4 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00583f10` — matches scaffold CF.
2. `read_memory` full body — dual loops + `ret 0x10`.
3. Rel32 → `004b7030` twice **Confirmed**.
4. Callers via `get_function_callers` / `get_xrefs_to` — multi-parent fan-out.
5. Cross-check W24-D seal of `004b7030` arg contract.

---

## 6. Falsifications locked in

- **Reject** treating this as the `+0x204` owned-child walker.
- **Reject** decompiler-only call form without host ECX.
- **Reject** creature-setup chain alias as product method name.
- **Reject** single-table model.

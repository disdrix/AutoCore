# Review B (skeptical / adversarial): `aa_004b7030` NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7030` |
| **VA** | `0x004b7030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product symbol + bit7 English residual only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is **only** vehicle-exhaust apply | Callers include `005829d0`, `00583f10`, `004c8110`, not just exhaust snprintf path | **Falsified** — generic owned-bit7 apply |
| 2 | stdcall free function | Entry uses ECX host; epilogue `C2 10 00` with thiscall pops | **Falsified** — **thiscall** |
| 3 | Decompiler call form complete (no this on e270/e300) | Bytes `mov ecx,[esi+8]` immediately before flag test and calls | **Decompiler incomplete** — child is callee this |
| 4 | Creates / destroys children | Body only walks + dispatches; no alloc/free/unlink | **Falsified if spawn/teardown claimed** |
| 5 | Bit7 means destroy-pending (bit0) | Test is `0x80` not `0x01`; deactivate dual uses bit0 for destroy | **Distinct bit** |
| 6 | `param_4` is the child slot index | `param_4` is 1-byte gate; slot is `param_5` into e270 | **Falsified if conflated** |
| 7 | Product name recovered from body string | No string xrefs in body | **False** — `_Inferred` required |
| 8 | Scaffold exhaust-only alias sufficient | Multi-caller + layout peer to NDSpecialFX | **Reject** as sole name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `ret 0x10` | **Confirmed** | stack imbalance |
| List walk + bit7 gate | **Confirmed** | miss/apply wrong children |
| Callee this = child | **Confirmed** | wrong ECX on apply |
| e300 vs e270 branch | **Confirmed** | wrong slot policy |
| NDSpecialFX host typing | **High** | mis-port to unrelated list |
| Bit7 English | Open | doc only |
| e270/e300 full product semantics | Partial | wrong start/stop side effects |
| Product method name | Tentative | cosmetic |
| Runtime / bit-exact | Open | |

---

## 3. Surviving contract

```
// thiscall RET 0x10
void NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
    void *host,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter)
{
  for (node = first(host+0x204); node != sentinel; node = *node) {
    child = node->payload; // [node+8]
    if ((child->flags_90e & 0x80) == 0) continue;
    if (use_slot_filter == 0)
      FUN_0058e300(child, want_start, want_stop);
    else
      FUN_0058e270(child, want_start, want_stop, slot_filter);
  }
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ name | No |
| R2 | Bit7 English (phys / FX / shared) | No for CF seal |
| R3 | Full dual of e270/e300 | No for this VA (dispatch sealed) |
| R4 | Whether every caller passes same host type | Mild — shared list offsets |
| R5 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x004b7030` — matches scaffold raw CF.
2. `read_memory` entry: `push ecx; mov eax,[ecx+0x204]; …`.
3. `read_memory` mid-body: `mov ecx,[esi+8]; test [ecx+0x90e],0x80; cmp slot_char; push args; call e270/e300`.
4. `read_memory` epilogue: `pop edi/ebp/ebx/esi/ecx; ret 0x10`.
5. Callers via `get_function_callers` / `get_xrefs_to` — five parents, not exhaust-only.
6. Callee decompiles: e270 slot gate on `+0x25c`; e300 requires `+0x25c < 0`; both touch `+0x90f` bit0 and particle helpers.
7. Peer `004b7150` dual confirms `+0x204` own-list + `+0x90e` flag family.

---

## 6. Falsifications locked in

- **Reject** `Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030` as primary role name.
- **Reject** treating decompiler two/three-arg e300/e270 calls as complete without child ECX.
- **Reject** conflating bit7 gate with destroy-pending bit0.
- **Reject** classifying this VA as spawn or deactivate/clear (that is `004b7150`).

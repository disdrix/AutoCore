# Review A (reconstruction fidelity): `aa_0082f9a0` UI_InteractionMenu_AddFriendsToggle

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f9a0` |
| **VA** | `0x0082f9a0`–`0x0082fa59` exclusive |
| **Body size** | **185 B** (`0xB9`) |
| **Canonical name** | `UI_InteractionMenu_AddFriendsToggle` |
| **Ghidra name** | `FUN_0082f9a0` |
| **Prior alias** | `UI_int_btn_generic_0082f9a0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082f9a0_UI_InteractionMenu_AddFriendsToggle.md` |
| **System** | interaction menu / social UI |
| **Agent** | MEGA-075 OWN-ONLY dual |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_callers`, `get_function_xrefs`, `get_assembly_context`, `get_function_signature`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/strings/IDs/slots/callers sealed; product host class + `+0x6B4` English open |

---

## 1. Purpose

**Interaction-menu friends button pack.** For a menu host (EDI) and target object (EAX), create either **Add to Friends** (`0x11177`) or **Remove from Friends** (`0x1117a`) using plate `i_m_int_2d_btn_generic.xml`, store the button on the host, membership gated by friends-list name lookup `FUN_00573a30(DAT_00d1da2c, name)`.

```c
// EAX = target; EDI = menu host; ret 0
void UI_InteractionMenu_AddFriendsToggle(Object* target, MenuHost* menu);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x0082f9a0` |
| Full listing | `disassemble_function` @ `0x0082f9a0` (57 insns, 11 BB) |
| Body bytes | `read_memory` 192 B @ `0x0082f9a0` — ends `5E C3`, pad `CC` |
| Callers | `get_function_callers` → `FUN_0082fe20` only |
| Xrefs | `get_function_xrefs` → `0x0082fee3`, `0x0082feff` UNCONDITIONAL_CALL |
| Parent CF | `disassemble_function` / decompile `FUN_0082fe20` |
| Call-site regs | `get_assembly_context` — `MOV EAX,EBP` / `MOV EDI,ESI` |
| Strings | `read_memory` @ `0x00a721ac` / `0xa72144` / `0xa72134` |
| Sibling dual | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`aa_0082fb30`) |
| Parent dual | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`aa_0082fe20`) |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 185 B / pad `CC` | **Confirmed** | disasm end `0x0082fa58` + memory |
| EAX = target (`+0x6B4` cmp) | **Confirmed** | entry `83 B8 B4 06 00 00 01` |
| EDI = menu host | **Confirmed** | stores + parent `MOV EDI,ESI` |
| `ret 0` (`C3`) | **Confirmed** | both epilogues `POP ESI; RET` |
| Gate target/local `+0x6B4` | **Confirmed** | disasm + decomp |
| Friends lookup via `DAT_00d1da2c` + `FUN_00573a30` | **Confirmed** | `E8` + thiscall ECX=list |
| Remove vs Add exclusive branch | **Confirmed** | early return after Remove |
| Button ids `0x1117a` / `0x11177` | **Confirmed** | push immediates |
| Labels Add/Remove Friends | **Confirmed** | string xrefs + memory |
| XML plate generic | **Confirmed** | `0x00a721ac` |
| Slots `+0x564` / `+0x558` | **Confirmed** | `mov [edi+0x564/0x558],esi` |
| Parent ×2 call sites | **Confirmed** | xrefs + parent listing |
| Product menu class name | **Inferred** | no RTTI on VA |
| `+0x6B4` English | **Open** | numeric gate only |
| `DAT_00d1da2c` product type | **Inferred** | structural friends list |

---

## 4. Control flow

```
if not (target+0x6B4 < 1 || local+0x6B4 >= 1): return
if DAT_00d1da2c != 0:
  name = target.adjustor_vtbl+0x160()
  if FUN_00573a30(DAT_00d1da2c, name) != 0:
    btn = menu.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x1117a, -1)
    if btn: btn.vtbl+0x1d8("Remove from Friends", 1, 1)
    menu+0x564 = btn
    return
btn = menu.vtbl+0x444(..., 0x11177, -1)
if btn: btn.vtbl+0x1d8("Add to Friends", 1, 1)
menu+0x558 = btn
```

---

## 5. Decompile ≡ raw

Live MEGA-075 decompile matches frozen raw body from 2026-07-23 (same CF, strings, callees, unaff_EDI/in_EAX shape). ABI recovered beyond decompiler via `disassemble_function` + parent context.

---

## 6. Gaps (acceptable)

1. Product class / MSVC name for menu host and friends-list object.
2. English for `+0x6B4`.
3. Dual of `FUN_00573a30` / name-getter vtbl (not OWN).
4. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under role name sealed by product UI English strings.

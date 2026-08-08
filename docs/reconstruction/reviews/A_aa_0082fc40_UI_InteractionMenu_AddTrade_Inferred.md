# Review A (reconstruction fidelity): `aa_0082fc40` UI_InteractionMenu_AddTrade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fc40` |
| **VA** | `0x0082fc40`–`0x0082fd4a` exclusive |
| **Body size** | **266 B** (`0x10A`) |
| **Canonical name** | `UI_InteractionMenu_AddTrade_Inferred` |
| **Ghidra name** | `FUN_0082fc40` |
| **Prior alias** | `UI_int_btn_generic_0082fc40` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md` |
| **System** | interaction menu / Trade UI |
| **Agent** | MEGA-077 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/strings/IDs/slot/range sealed; product host class + `+0x6B4` English open |

---

## 1. Purpose

**Interaction-menu Trade button pack.** For a menu host (ESI) and target object (EBX), create a **Trade** button (`0x11175`) using plate `i_m_int_2d_btn_generic.xml`, store it on the host at `+0x550`, and disable when squared world-distance to local player (`DAT_00d1b6d8`) exceeds **1600.0f** (range **40**).

```c
// ESI = menu host; EBX = target; ret 0
void UI_InteractionMenu_AddTrade_Inferred(MenuHost* menu, Object* target);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x0082fc40` |
| Full disassembly | `disassemble_function` (entry through `RET`) |
| Entry / exit / float | `read_memory` @ `0x0082fc40`, `0x0082fd40`, `0x00aaa674`, strings |
| Callers / xrefs | `get_function_callers` / `get_function_xrefs` → `FUN_0082fe20` ×2 |
| Call-site context | `get_assembly_context` @ `0x0082fed7`, `0x0082ff0b` |
| Parent CF | decompile `FUN_0082fe20` (pack order including Trade) |
| Sibling dual | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`aa_0082fb30`) |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + size 266 B | **Confirmed** | disasm end `RET` @ `0x0082fd49`; pad `CC` |
| EBX = target (`+0x6B4` cmp) | **Confirmed** | entry `CMP [EBX+0x6B4],1`; parent `MOV EBX,EBP` |
| ESI = menu host | **Confirmed** | `MOV ECX,ESI` before create; store `[ESI+0x550]` |
| `ret 0` (`C3`) | **Confirmed** | epilogue |
| Label `"Trade"` + id `0x11175` | **Confirmed** | immediates + `read_memory` strings |
| XML plate generic | **Confirmed** | `0x00a721ac` |
| Slot `+0x550` | **Confirmed** | `MOV [ESI+0x550],EDI` |
| Dist² threshold 1600.0f | **Confirmed** | `DAT_00aaa674` = `00 00 C8 44` |
| Disable via `vtbl+0xD4(0)` when too far | **Confirmed** | `COMISS` / `JBE` / call |
| Position via `vtbl+0x1A0` | **Confirmed** | both target and local |
| Product menu class name | **Inferred** | no RTTI on VA |
| `+0x6B4` English | **Open** | numeric gate only |

---

## 4. Control flow

```
if not (target+0x6B4 < 1 || local+0x6B4 > 0): return
btn = menu.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x11175, -1)
if btn: btn.vtbl+0x1D8("Trade", 1, 1)
menu+0x550 = btn
tpos = target.SharedBase.vtbl+0x1A0()
lpos = local.SharedBase.vtbl+0x1A0()
if btn && |tpos-lpos|² > 1600.0f:
  btn.vtbl+0xD4(0)
return
```

---

## 5. Gaps (acceptable)

1. Product class / MSVC name for menu host.
2. English for `+0x6B4`.
3. Product demangle of SharedBase position getter (`vtbl+0x1A0`).
4. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

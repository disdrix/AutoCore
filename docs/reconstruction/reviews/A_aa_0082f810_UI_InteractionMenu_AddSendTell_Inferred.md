# Review A (reconstruction fidelity): `aa_0082f810` UI_InteractionMenu_AddSendTell_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f810` |
| **VA** | `0x0082f810`–`0x0082f849` inclusive |
| **Body size** | **58 B** (`0x3A`) |
| **Canonical name** | `UI_InteractionMenu_AddSendTell_Inferred` |
| **Ghidra name** | `FUN_0082f810` |
| **Prior alias** | `UI_int_btn_generic` / `FUN_0082f810` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md` |
| **System** | interaction menu / tell UI (skills-abilities partition) |
| **Agent** | MEGA-073 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/strings/id/slot/callers/ABI sealed; product host class English open |

---

## 1. Purpose

**Interaction-menu "Send a Tell" button leaf.** For a menu host (EDI), create one generic button from plate `i_m_int_2d_btn_generic.xml` with id **`0x11176`**, set caption **"Send a Tell"**, and store the pointer at **host+0x554**.

```c
// EDI = menu host; ret 0
void UI_InteractionMenu_AddSendTell_Inferred(MenuHost* menu);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x0082f810` |
| Full analysis | `analyze_function_complete` (xrefs/callers/disasm/locals) |
| Full body asm | `disassemble_function` (20 insns) |
| Entry / body bytes | `read_memory` 58 B @ `0x0082f810` |
| Strings | `read_memory` @ `0x00a721ac` / `0x00a72158` |
| Callers / xrefs | `get_function_callers` + `get_xrefs_to` → `FUN_0082fe20` ×2 |
| Parent CF | `decompile_function` + `disassemble_function` `FUN_0082fe20` (`MOV EDI,ESI` before both CALLs) |
| Peer dual | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`aa_0082fb30`) |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`, dual of other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + size 58 B | **Confirmed** | last insn `RET` @ `0x0082f849`; pad `CC` |
| EDI = menu host | **Confirmed** | entry `MOV EAX,[EDI]`; parent `MOV EDI,ESI` |
| `ret 0` (`C3`) | **Confirmed** | epilogue `5E C3` |
| Create via host `vtbl+0x444` | **Confirmed** | `CALL [EAX+0x444]` after `MOV ECX,EDI` |
| Button id `0x11176` | **Confirmed** | `PUSH 0x11176` |
| Plate XML string | **Confirmed** | push `0xa721ac` + bytes |
| Caption "Send a Tell" | **Confirmed** | push `0xa72158` + bytes |
| Label via btn `vtbl+0x1D8` | **Confirmed** | `CALL [EDX+0x1D8]` when ESI≠0 |
| Slot store `+0x554` | **Confirmed** | `MOV [EDI+0x554],ESI` |
| Always store (incl. null) | **Confirmed** | store after JZ join |
| No disable path | **Confirmed** | no `vtbl+0xD4` / no other CALLs |
| Sole parent `FUN_0082fe20` ×2 | **Confirmed** | 2 UNCONDITIONAL_CALL xrefs |
| Product menu class name | **Inferred** | no RTTI on VA; family name from parent dual |
| Create/label formal English | **Tentative** | shape sealed; product method names open |

---

## 4. Control flow

```
btn = menu.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x11176, -1)  // ECX=menu
if btn != 0:
  btn.vtbl+0x1D8("Send a Tell", 1, 1)                                // ECX=btn
menu+0x554 = btn
return
```

Matches live decompile and full assembly 1:1. No branches other than null-check on create result.

---

## 5. Parent placement (evidence only; parent already dualed)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred
  … resolve target; if not self …
  if menu.vtbl+0x478() == 0:
    … FUN_0082f8d0; FUN_0082f9a0; FUN_0082f810; …   // EDI=ESI
  else:
    … FUN_0082fc40; FUN_0082f810; FUN_0082f9a0; …   // EDI=ESI
```

Both call sites install **EDI = menu host (ESI)** before `CALL 0x0082f810`.

---

## 6. Gaps (acceptable)

1. Product class / MSVC name for menu host.
2. Product English for vtbl methods at `+0x444` / `+0x1D8` and args `(0,-1)` / `(1,1)`.
3. Downstream command path for button id `0x11176` (not this leaf).
4. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

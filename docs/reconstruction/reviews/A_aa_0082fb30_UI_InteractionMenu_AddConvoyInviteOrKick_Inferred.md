# Review A (reconstruction fidelity): `aa_0082fb30` UI_InteractionMenu_AddConvoyInviteOrKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fb30` |
| **VA** | `0x0082fb30`–`0x0082fc31` exclusive |
| **Body size** | **257 B** (`0x101`) |
| **Canonical name** | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` |
| **Ghidra name** | `FUN_0082fb30` |
| **Prior alias** | `UI_int_btn_generic_0082fb30` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| **System** | interaction menu / convoy UI |
| **Agent** | WQ9D-I OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/strings/IDs/slots/callers sealed; product host class + `+0x6B4` English open |

---

## 1. Purpose

**Interaction-menu convoy button pack.** For a menu host (ESI) and target object (EDX), create either **Invite To Convoy** (`0x11171`) or **Kick From Convoy** (`0x11172`) using plate `i_m_int_2d_btn_generic.xml`, store the button on the host, and disable when local player is not the convoy leader (`FUN_00574880() != DAT_00d1b6d8`).

```c
// ESI = menu host; EDX = target; ret 0
void UI_InteractionMenu_AddConvoyInviteOrKick_Inferred(MenuHost* menu, Object* target);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` @ `0x0082fb30` |
| Entry / exit bytes | `read_memory` @ `0x0082fb30` / `0x0082fc20` |
| Callers | `FUN_0082fe20` ×2 sites |
| Parent CF | decompile `FUN_0082fe20` (button-build sequences) |
| Crew dual | `VehicleCrew_ContainsMember_Inferred` (`aa_005749d0`) |
| Slot peer | `ConvoyRoster_GetMemberBySlot_Inferred` (`aa_00574760`) vs `FUN_00574880` |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + size 257 B | **Confirmed** | function meta + pad `CC` |
| EDX = target (`+0x6B4` cmp) | **Confirmed** | entry bytes `83 BA B4 06…` |
| ESI = menu host | **High** | `unaff_ESI` stores + parent preserves ESI |
| `ret 0` (`C3`) | **Confirmed** | epilogue |
| Invite vs Kick branch on crew | **Confirmed** | `+0xCB0` + `FUN_005749d0` |
| Button ids `0x11171` / `0x11172` | **Confirmed** | immediates |
| Labels Invite/Kick strings | **Confirmed** | decompile |
| XML plate generic | **Confirmed** | string |
| Slots `+0x540` / `+0x544` | **Confirmed** | `ESI[0x150]` / `[0x151]` |
| Disable via `vtbl+0xD4(0)` when not leader | **Confirmed** | CF |
| Product menu class name | **Inferred** | no RTTI on VA |
| `+0x6B4` English | **Open** | numeric gate only |

---

## 4. Control flow

```
if not (target+0x6B4 < 1 || local+0x6B4 > 0): return
crewHost = *(local+0xCB0)
if crewHost==0 || !ContainsMember(crewHost, target):
  btn = menu.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x11171, -1)
  if btn: btn.vtbl+0x1D8("Invite To Convoy", 1, 1)
  menu+0x540 = btn
  if btn && crewHost && FUN_00574880()!=local: btn.vtbl+0xD4(0)
else:
  btn = menu.vtbl+0x444(..., 0x11172, -1)
  if btn: btn.vtbl+0x1D8("Kick From Convoy", 1, 1)
  menu+0x544 = btn
  if btn && FUN_00574880()!=local: btn.vtbl+0xD4(0); return
```

---

## 5. Gaps (acceptable)

1. Product class / MSVC name for menu host.
2. English for `+0x6B4`.
3. Dual of `FUN_00574880` / parent `FUN_0082fe20` (not OWN).
4. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

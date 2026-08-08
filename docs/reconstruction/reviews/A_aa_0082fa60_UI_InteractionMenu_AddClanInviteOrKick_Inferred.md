# Review A (reconstruction fidelity): `aa_0082fa60` UI_InteractionMenu_AddClanInviteOrKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fa60` |
| **VA** | `0x0082fa60`–`0x0082fb2b` exclusive |
| **Body size** | **203 B** (`0xCB`) |
| **Canonical name** | `UI_InteractionMenu_AddClanInviteOrKick_Inferred` |
| **Ghidra name** | `FUN_0082fa60` |
| **Prior alias** | `UI_int_btn_generic_0082fa60` (**retired**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md` |
| **System** | skills-abilities / interaction-menu clan UI |
| **Agent** | MEGA-076 OWN-ONLY dual |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `get_assembly_context`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/strings/IDs/slots/callers sealed; product host class + field English open |

---

## 1. Purpose

**Interaction-menu clan button pack.** For a menu host (**EBX**) and target object (**EAX**), create either **Invite To Clan** (`0x11173`) or **Kick From Clan** (`0x11174`) using plate `i_m_int_2d_btn_generic.xml`, after clan-table lookups on `DAT_00d1da30`, and store the button on the host (`+0x548` / `+0x54C`).

```c
// EAX = target; EBX = menu host; ret 0
void UI_InteractionMenu_AddClanInviteOrKick_Inferred(Object* target, MenuHost* menu);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x0082fa60` |
| Full asm listing | `disassemble_function` @ `0x0082fa60` |
| Body span | `get_function_by_address` `0082fa60`–`0082fb2a` + pad `CC` |
| Entry / string bytes | `read_memory` @ `0x0082fa60`, `0x0082fad0`, `0x00a72164`, `0x00a72174`, `0x00a721ac` |
| Callers / xrefs | `get_function_callers` / `get_function_xrefs` → `FUN_0082fe20` ×2 |
| Parent call sites | `get_assembly_context` @ `0x0082fed0`, `0x0082ff14` |
| Parent dual | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`aa_0082fe20`) |
| Convoy sibling dual | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`aa_0082fb30`) |
| Callee raw | `FUN_004c22a0`, `FUN_0082f7d0` |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + size 203 B | **Confirmed** | function meta + pad `CC` before `0082fb30` |
| EAX = target (`MOV ESI,EAX`; `+0x6B4` cmp) | **Confirmed** | entry bytes + parent `MOV EAX,EBP` |
| EBX = menu host | **Confirmed** | `MOV ECX,EBX` before helper; stores `[EBX+0x548/54C]`; parent `MOV EBX,ESI` |
| `ret 0` (`C3`) | **Confirmed** | both epilogues |
| Gate `+0x6B4` + `DAT_00d1da30` | **Confirmed** | asm + decompile |
| Clan lookup via `FUN_004c22a0` ×2 | **Confirmed** | ECX=`DAT_00d1da30`; keys from secondary `+0x164/+0x168` |
| Invite vs Kick branch | **Confirmed** | targetClan null → invite; else rank-field compare → kick |
| Button ids `0x11173` / `0x11174` | **Confirmed** | immediates + `read_memory` path |
| Labels Invite/Kick Clan strings | **Confirmed** | `read_memory` @ `0xa72174` / `0xa72164` |
| XML plate generic | **Confirmed** | `read_memory` @ `0xa721ac` |
| Slots `+0x548` / `+0x54C` | **Confirmed** | `MOV [EBX+0x548],EAX` / `[EBX+0x54C]` |
| Callers = parent pack ×2 sites | **Confirmed** | xrefs UNCONDITIONAL_CALL |
| Live decompile ≡ frozen raw CF | **Confirmed** | MEGA-076 re-verify |
| Product menu class name | **Inferred** | no RTTI on VA |
| `+0x6B4` / clan`+0x24` English | **Open** | numeric only |
| Same-clan requirement on kick | **Open** | CF is rank-field compare only |

---

## 4. Control flow

```
if not (target+0x6B4 < 1 || local+0x6B4 > 0): return
if DAT_00d1da30 == 0: return
localClan  = ClanTable_Lookup(DAT_00d1da30, local keys @ secondary+0x164/168)
targetClan = ClanTable_Lookup(DAT_00d1da30, target keys @ secondary+0x164/168)
if localClan == 0: return
if targetClan == 0:
  if localClan+0x24 >= 2:
    btn = CreateLabelBtn(host, "Invite To Clan", xml, 0x11173)
    host+0x548 = btn; return
else if targetClan+0x24 < localClan+0x24:
  btn = CreateLabelBtn(host, "Kick From Clan", xml, 0x11174)
  host+0x54C = btn
return
```

---

## 5. Gaps (acceptable)

1. Product class / MSVC name for menu host and clan table.
2. English for `+0x6B4`, key pair `+0x164/+0x168`, entry `+0x24`.
3. Dual of `FUN_004c22a0` / `FUN_0082f7d0` (not OWN).
4. Whether kick path is product-intended only for same clan (no explicit compare).
5. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

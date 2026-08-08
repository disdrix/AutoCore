# Review A (reconstruction fidelity): `aa_0082fd50` UI_InteractionMenu_AddNameplateLabel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fd50` |
| **VA** | `0x0082fd50`–`0x0082fe20` exclusive |
| **Body size** | **208 B** (`0xD0`) |
| **Canonical name** | `UI_InteractionMenu_AddNameplateLabel_Inferred` |
| **Ghidra name** | `FUN_0082fd50` |
| **Prior alias** | `UI_int_btn_generic_0082fd50` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md` |
| **System** | interaction menu / social UI (partition: skills-abilities) |
| **Agent** | MEGA-084 OWN-ONLY dual |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `get_function_by_address`, callers/xrefs, `disassemble_function`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/id/slot/colors/call sites sealed; product host class + `+0x6B4`/color English open |

---

## 1. Purpose

**Interaction-menu nameplate label pack.** For a menu host (EDI) and owner/target object (EBX), create a non-interactive generic button labeled with the object's display name (`vtbl+0x160`), store it at host `+0x53C`, disable interaction, and tint via one of two ARGB constants selected by `target+0x6B4`.

```c
// EDI = menu host; EBX = owner/target; ret 0
void UI_InteractionMenu_AddNameplateLabel_Inferred(MenuHost* menu, Object* target);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x0082fd50` |
| Body span | `get_function_by_address` `0082fd50`–`0082fe1f` + next fn @ `0082fe20` |
| Entry / body bytes | `read_memory` 220 B @ `0x0082fd50` |
| Full asm | `disassemble_function` (operands sealed) |
| Callers / xrefs | `FUN_0082fe20` @ `0x0082FEC0`, `0x0082FF22` (UNCONDITIONAL_CALL ×2) |
| Parent CF | `disassemble_function` `FUN_0082fe20` — `mov edi,esi`; `mov ebx,ebp` before calls |
| Plate string | `read_memory` @ `0x00A721AC` → `i_m_int_2d_btn_generic.xml` |
| Peer packs | dualed convoy `aa_0082fb30`; parent dual `aa_0082fe20` |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 208 B / tight next-fn | **Confirmed** | meta + memory + `C3` then `56 8B F1` |
| EDI = menu host; EBX = owner/target | **Confirmed** | parent call-site setup |
| `ret 0` (`C3`) | **Confirmed** | epilogue |
| Button id `0x1117F` | **Confirmed** | `PUSH 0x1117F` |
| Plate XML generic | **Confirmed** | string @ `0x00A721AC` |
| Slot host `+0x53C` | **Confirmed** | `MOV [EDI+0x53C],ESI` |
| Label from `vtbl+0x160` name | **Confirmed** | first CALL; peer packs same getter |
| Always `vtbl+0xD4(0)` | **Confirmed** | no branch around disable |
| Colors `0xFF1EA0B4` / `0xFFA01EB4` by `+0x6B4` | **Confirmed** | byte stores + CMP/JL |
| `btn+0x170 = -2` | **Confirmed** | immediate store |
| Leaf (no direct FUN callees) | **Confirmed** | analyze + xrefs |
| Product menu class name | **Inferred** | no RTTI on VA |
| `+0x6B4` / color English | **Open** | numeric + ARGB only |

---

## 4. Control flow

```
name = ObjectAdj(EBX).vtbl+0x160()
btn  = menu.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x1117F, -1)
if btn: btn.vtbl+0x1D8(name, 1, 1)
menu+0x53C = btn
if btn == 0: return
btn.vtbl+0xD4(0)                          // always disable
if target+0x6B4 < 1: color = 0xFF1EA0B4
else:                color = 0xFFA01EB4
btn.vtbl+0x15C(1, &color)
btn+0x170 = 0xFFFFFFFE
btn.vtbl+0x1E4(1)
return
```

---

## 5. Gaps (acceptable)

1. Product class / MSVC name for menu host.
2. English for `+0x6B4` and the two ARGB colors.
3. English for `vtbl+0x15C` / `+0x1E4` / `btn+0x170`.
4. Dual of sibling action packs / shell clear `FUN_0082F850` (not OWN).
5. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

# Review A (reconstruction fidelity): `aa_0082d2b0` UI_InteractionMenu_RebuildPopupShell_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082d2b0` |
| **VA** | `0x0082d2b0`–`0x0082d3ce` exclusive |
| **Body size** | **286 B** (`0x11E`) |
| **Canonical name** | `UI_InteractionMenu_RebuildPopupShell_Inferred` |
| **Ghidra name** | `FUN_0082d2b0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md` |
| **System** | skills-abilities / interaction-menu UI shell |
| **Agent** | MEGA-072 OWN-ONLY dual |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `analyze_control_flow`, `get_function_callers`, `get_function_xrefs`, `get_assembly_context`, `read_memory`, `search_strings` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/offsets/string/call graph sealed; product host class + vtbl English open |

---

## 1. Purpose

**Popup-shell rebuild for active menu hosts.** When `host+0x4C0` is non-zero, clear prior content, replace owned CNDHash @ `+0x534`, destroy prior dialog @ `+0x538`, construct a 0x488 NDUI dialog, load `i_d_pop_2d_wnd_blocker.xml` at layer 70000, reattach, update depth counters, notify via `vtbl+0x3f4(1)`.

```c
// __thiscall; ECX = menu host*; ret 0
void UI_InteractionMenu_RebuildPopupShell_Inferred(MenuHost* host);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x0082d2b0` ≡ raw 2026-07-23 body |
| Complete analysis | `analyze_function_complete` — callers/callees/xrefs/locals |
| Body span | `analyze_control_flow` size 286; RET `C3` @ `0x0082d3cd`; pad `CC` via `read_memory` |
| Entry / ABI | `disassemble_function`: SEH + `MOV ESI,ECX` + bare `RET` |
| String | `search_strings` → `0x00a4c5ec` `"i_d_pop_2d_wnd_blocker.xml"` |
| DATA vtbl | `read_memory` @ `0x00a733b8` → LE `b0 d2 82 00` |
| Call sites | `get_assembly_context` on 7 CALL xrefs — all `+0x4C0` gated |
| Parent dual | `UI_InteractionMenu_PopulateTargetButtons_Inferred` first-calls this |
| Peer dual | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` owns `+0x534` teardown |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 286 B / pad `CC` | **Confirmed** | CF metrics + memory |
| ECX = host; `ret 0` | **Confirmed** | `MOV ESI,ECX`; epilogue `C3` |
| Gate `+0x4C0` | **Confirmed** | entry `CMP [ESI+0x4c0]` |
| CNDHash rebuild @ `+0x534` | **Confirmed** (role) / **Inferred** (product type name) | `new(0x34)` + ctor; peer dual tags CNDHash |
| Ctor flag `CL=2` | **Confirmed** | `MOV CL,2` before `CALL 00416920` |
| Prior dialog destroy `vtbl+0xbc` | **Confirmed** | asm + decompile |
| Dialog `new(0x488)` + `FUN_007b5dd0` | **Confirmed** | size + call |
| XML load + layer 70000 | **Confirmed** | string + `PUSH 0x11170` |
| Depth float `-(float)count` @ `+0x74` | **Confirmed** | `NEG; CVTSI2SS; MOVSS` |
| DATA vtbl @ `0x00a733b8` | **Confirmed** | memory |
| Multi-caller shared shell | **Confirmed** | 7 CALL + 1 DATA |
| Product MSVC host class | **Inferred** | no RTTI on VA; `_Inferred` |
| `vtbl+0x450/0xa8/0xbc/0x3f4` English | **Open** | structural only |

---

## 4. Control flow

```
if host+0x4C0 == 0: return
host.vtbl+0x450()
hash = new(0x34) ? FUN_00416920(CL=2, mem) : null
host+0x534 = hash
host+0x68 = 0; host+0x74 = 0.0f; clamp host+0x70 >= 0; host+0x4A4 = 0
if host+0x538 != 0: host.vtbl+0xbc(old)
dialog = new(0x488) ? FUN_007b5dd0(mem, 0) : null
host.vtbl+0xa8(dialog)
dialog.vtbl+0x28("i_d_pop_2d_wnd_blocker.xml")
dialog.vtbl+0x74(70000)
host+0x68++; host+0x538 = dialog; host+0x74 = -(float)count; max(host+0x70, count)
host.vtbl+0x3f4(1)
```

---

## 5. Gaps (acceptable)

1. Product class / MSVC name for menu host (shared base vs CVOGMenu vs InteractionMenu).
2. English for host/dialog vtbl slots.
3. Dual of `FUN_007b5dd0` / `FUN_00416920` (not OWN).
4. Runtime / bit-exact (Terminal false).
5. Decompiler presents float store as `(int)(float)` — asm sealed; not a CF reject.

**Verdict:** **accept-with-gaps** under `_Inferred` name.

# Review A (reconstruction fidelity): `aa_0090d400` UI_CloseRelatedChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090d400` |
| **VA** | `0x0090d400`–`0x0090d465` inclusive |
| **Body size** | **102 B** (`0x66`) |
| **Canonical name** | `UI_CloseRelatedChrome_Inferred` |
| **Ghidra name** | `FUN_0090d400` |
| **Prior names** | `Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_0090d400` (retired) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0090d400_UI_CloseRelatedChrome_Inferred.md` |
| **System** | skills-abilities / interaction-menu UI chrome |
| **Agent** | OWN-ONLY dual **MEGA-086** |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_xrefs_to` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/register contract/vtbl offsets/call-site families sealed; product class + vtbl English open |

---

## 1. Purpose

**Dual-object UI close helper** used heavily by the interaction-menu social path and by chrome table flush. Closes the **primary** object in **ESI** (visibility gate → hide → close/flush), then notifies/resets the **secondary** object in **EDI** (detach/notify, optional re-bind of `DAT_00d1b978`, select/reset `-1`).

```c
// register contract; bare RET
void UI_CloseRelatedChrome_Inferred(void /* ESI=primary, EDI=secondary */);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x0090d400` |
| Live analyze | `analyze_function_complete` (leaf; 25 xrefs; 9 named callers) |
| Body span | `get_function_by_address` `0090d400`–`0090d465` + `read_memory` + pad `CC` |
| Listing | `disassemble_function` full body |
| Parent dual (evidence) | `UI_InteractionMenu_PopulateTargetButtons_Inferred` optional close @ `+0x2B0` |
| Call sites | menu family `MOV EDI,[ESI+0x2B0]`; table family `MOV EDI,EAX` / `MOV ESI,[table]` |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`, dual of other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 102 B / pad `CC` / next `FUN_0090d470` | **Confirmed** | meta + memory |
| ESI = primary closed; EDI = secondary notified | **Confirmed** | listing |
| Bare `RET` (`C3`); no stack formals | **Confirmed** | epilogue |
| Not ECX-thiscall entry | **Confirmed** | entry `TEST ESI,ESI` |
| Vtbl offsets `0x3d8`/`0xcc`/`0x440`/`0xb0`/`0x3bc`/`0x3f4` | **Confirmed** | listing + hex |
| Static callees none | **Confirmed** | analyze + callees empty |
| 25 UNCONDITIONAL_CALL xrefs | **Confirmed** | xrefs |
| Menu family ESI=host EDI=`+0x2B0` | **Confirmed** | parent/call-site listing |
| Table family ESI=chrome EDI=host | **Confirmed** | `0090dab0` listing |
| Product class / vtbl English | **Inferred / Open** | no RTTI on VA |
| `DAT_00d1b978` product identity | **Inferred** | Tell path peer only |
| Runtime Confirmed | **Open** | no Launcher |

---

## 4. Control flow

```
if ESI == 0: return
if !ESI.vtbl+0x3d8(): return
ESI.vtbl+0xcc(0)
ESI.vtbl+0x440()
EDI.vtbl+0xb0(ESI)
if DAT_00d1b978 && DAT_00d1b978.vtbl+0x3d8():
  EDI.vtbl+0x3bc(DAT_00d1b978)
EDI.vtbl+0x3f4(-1)
return
```

Live decompile CF ≡ frozen raw 2026-07-23 ≡ live 2026-08-05.

---

## 5. Gaps (acceptable)

1. Product / MSVC names for host and chrome classes.
2. English for all six vtbl slots.
3. Product name for `DAT_00d1b978`.
4. Whether one product symbol covers both menu-close-host and table-close-chrome assignments.
5. Runtime / bit-exact / differential (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

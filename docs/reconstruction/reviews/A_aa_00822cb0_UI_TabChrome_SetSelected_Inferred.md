# Review A (reconstruction fidelity): `aa_00822cb0` UI_TabChrome_SetSelected_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00822cb0` |
| **VA** | `0x00822cb0` |
| **Canonical name** | `UI_TabChrome_SetSelected_Inferred` |
| **Review date** | `2026-08-05` (R12-002 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` |
| **System** | inventory-transfer (UI tab chrome helper; no inventory wire) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply **selected / unselected chrome** to a client UI tab control:

- **ESI** = tab chrome widget*
- **BL** = desired selected state (`1` = selected, `0` = unselected)
- **stack force** = if `0` and `widget[+0x4FC] == BL`, early-out

When state changes (or force is set): restyle optional child text/label (`+0x818`), toggle optional child visibility (`+0x814`), and if the prior state differed, resize the widget by stored deltas (`+0x80C`/`+0x810`) via vtbl `+0x120` / `+0x110`. Always store `BL` into `widget[+0x4FC]` on the non-early path.

Parent partition residual under dualed `UI_Cs2dTabs_SelectTab_Inferred` (`0x00888b00`) and sibling tab selectors (`00889410`, `00889fb0`, …). Paired after collapse (BL=0) with dualed `UI_Widget_MoveToFrontInParentGroup_Inferred` (`0x00756c90`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x00822cb0)` 2026-08-05 ≡ frozen raw CF |
| Body / epilogue | `disassemble_function` + `read_memory` 512 B; epilogue `MOV [ESI+0x4FC],BL; POP EDI; ADD ESP,0x18; RET 4` |
| ABI | entry `SUB ESP,0x18; CMP [ESP+0x1c],0` (force); uses **ESI** + **BL** (unaff in decomp) |
| Call sites | parent `FUN_00888b00` / `FUN_00889410` / `FUN_00889fb0`: `MOV ESI,tab; MOV/XOR BL; PUSH force; CALL 00822cb0` |
| Callers / xrefs | `analyze_function_complete` → **45** xrefs / **10** named callers |
| Raw / annotated / clean / records | R12-002 trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of child vtbls / other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw CF | **Confirmed** | force gate; BL=0/1 arms; store state |
| ESI = widget formal | **Confirmed** | disasm + all sampled call sites |
| BL = selected desired state | **Confirmed** | parent `MOV BL,1` / `XOR BL,BL` |
| Stack force; `RET 4` | **Confirmed** | `[ESP+0x1c]` after `SUB ESP,0x18`; epilogue `C2 04 00` |
| Not ECX thiscall | **Confirmed** | ECX used for child this / vcall this only |
| selected byte `@+0x4FC` | **Confirmed** | `CMP [ESI+0x4FC],BL` / store |
| scale byte `@+0x4FD` | **Confirmed** | full on select; `SHR 1` on unselect |
| child text/style `@+0x818` | **Confirmed** | vtbl `+0xF0/+0xE8/+0x164/+0x15C/+0x34C` |
| child visibility `@+0x814` | **Confirmed** | vtbl `+0x3C8` args `(1, selected)` |
| size deltas `@+0x80C/+0x810` | **Confirmed** | select: size − delta; unselect: size + delta |
| size get/set vtbl `+0x120` / `+0x110` | **Confirmed** | disasm |
| Multi-caller (not Cs2d-only) | **Confirmed** | 10 named + 45 xrefs |
| Product English class/method name | **Open** | keep `_Inferred` |
| Exact product meaning of child vtbls | **Open** | residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| force==0 && state==BL → return | **Yes** |
| BL==0 unselect arm | **Yes** |
| BL!=0 select arm | **Yes** |
| Optional child@+0x818 style path | **Yes** |
| Optional child@+0x814 show/hide | **Yes** |
| Size adjust only when prior state differs | **Yes** |
| Store BL → +0x4FC | **Yes** |
| No inventory C2S packets | **Yes** |

### Sealed CF sketch

```
UI_TabChrome_SetSelected_Inferred(widget@ESI, selected@BL, force@stack):
  if !force && widget.selected(+0x4FC) == selected: return
  childA = widget[+0x818]
  if selected == 0:  // unselect / collapse
    if childA:
      // restyle at half scale (+0x4FD >> 1) via childA vtbls
      childA.Invalidate(+0x34C)
    if childB = widget[+0x814]:
      childB.SetVisible(1, 0)   // vtbl +0x3C8
    if widget.selected == 0: goto store
    // grow size by deltas
    sz = widget.GetSize(+0x120)
    new_h = sz.h + widget[+0x810]
    new_w = sz.w + widget[+0x80C]
  else:              // select / expand
    if childA:
      // restyle at full scale (+0x4FD) via childA vtbls
      childA.Invalidate(+0x34C)
    if childB = widget[+0x814]:
      childB.SetVisible(1, 1)
    if widget.selected == selected: goto store
    // shrink size by deltas
    sz = widget.GetSize(+0x120)
    new_h = sz.h - widget[+0x810]
    new_w = sz.w - widget[+0x80C]
  widget.SetSize(+0x110, new_w, new_h)
store:
  widget.selected(+0x4FC) = selected
```

---

## 5. Gaps

1. Product / RTTI English name of tab chrome class and method.
2. Exact product semantics of childA vtbls (`+0xF0/+0xE8/+0x164/+0x15C/+0x34C`) and childB `+0x3C8`.
3. Whether `+0x4FD` is font size, alpha, or another scale channel.
4. Why selected chrome is **smaller** by the stored deltas (inset vs chrome policy).
5. Runtime tab-switch capture; bit-exact image.

**Verdict:** **accept-with-gaps** — ABI (ESI+BL+force/`RET 4`), offsets, dual select/unselect CF, multi-caller pattern sealed; product labels + child vtbl English open.

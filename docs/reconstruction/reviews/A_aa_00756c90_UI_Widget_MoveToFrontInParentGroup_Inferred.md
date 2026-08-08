# Review A (reconstruction fidelity): `aa_00756c90` UI_Widget_MoveToFrontInParentGroup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756c90` |
| **VA** | `0x00756c90` |
| **Canonical name** | `UI_Widget_MoveToFrontInParentGroup_Inferred` |
| **Review date** | `2026-08-05` (R12-003 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` |
| **System** | inventory-transfer (UI tab/group chrome helper) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Move a UI widget (tab chrome / control) to the front of its parent group's child-pointer vector. Gate on parent presence (`widget+0x88`) and singleton size; otherwise erase-self-if-present then InsertN(1) of self at vector begin via `FUN_00456960`.

Parent partition residual under dualed `UI_Cs2dTabs_SelectTab_Inferred` (`0x00888b00`) and sibling tab selectors (`00889410`, `00889fb0`, …).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x00756c90)` 2026-08-05 ≡ frozen raw CF |
| Body / epilogue | `disassemble_function` + `read_memory` 256 B; success `XOR EAX,EAX; POP ESI; POP ECX; RET`; fail `OR EAX,-1; … RET` |
| ABI | entry `MOV ESI,[EDI+0x88]`; no stack formals; plain `RET` |
| Call sites | parent `FUN_00888b00` / `FUN_00889410` / `FUN_00889fb0` disasm: `MOV EDI, tabCtrl; CALL` |
| Callee | `FUN_00456960` decompile = StdVector InsertN; IAT memmove |
| Sibling contrast | `FUN_00756be0` true detach (clears `+0x88`) |
| Callers / xrefs | `analyze_function_complete` + `get_function_xrefs` → **28** UNCONDITIONAL_CALL |
| Raw / annotated / clean / records | R12-003 trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of `FUN_00456960` / `FUN_00822cb0` / other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw CF | **Confirmed** | null group / size==1 / erase / InsertN |
| EDI = widget formal | **Confirmed** | disasm + all sampled call sites |
| No stack args; plain `RET` | **Confirmed** | epilogue `C3` not `C2 xx` |
| Return 0 / `-1` in EAX | **Confirmed** | `XOR EAX,EAX` / `OR EAX,0xFFFFFFFF` |
| Not ECX thiscall | **Confirmed** | ECX used as begin / count only |
| `widget+0x88` = parent group | **Confirmed** | load + fail path |
| Vector begin/end `@group+0x94/+0x98` | **Confirmed** | disasm + size SAR 2 |
| size==1 early-out skips erase+insert | **Confirmed** | `CMP EAX,1; JZ success` |
| Erase via memmove + end-=4 | **Confirmed** | |
| `FUN_00456960` = InsertN front | **Confirmed** | ECX=1, EDX=group+0x90, pos=begin, value=widget |
| Does **not** clear `widget+0x88` | **Confirmed** | contrast `FUN_00756be0` |
| Product group/widget English names | **Open** | keep `_Inferred` |
| Product reason inactive tabs move-to-front | **Open** | policy residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load group from `widget+0x88` | **Yes** |
| Null group → `-1` | **Yes** |
| size==1 → `0` (no mutate) | **Yes** |
| Linear scan erase self | **Yes** |
| InsertN(1) at begin | **Yes** (disasm seals decomp arity) |
| Success → `0` | **Yes** |
| No inventory C2S packets | **Yes** |

### Sealed CF sketch

```
UI_Widget_MoveToFrontInParentGroup_Inferred(widget@EDI) -> EAX:
  group = widget.group(+0x88)
  if !group: return -1
  if group.vec size == 1: return 0
  erase widget from group.vec[begin@+0x94, end@+0x98) if present
  InsertN(group.vec@+0x90, pos=begin, count=1, value=widget)
  return 0
```

---

## 5. Gaps

1. Product / RTTI name of widget and parent group classes.
2. Product policy: why collapsed tabs are moved to front (z-order / focus / radio list).
3. Residual dual of `FUN_00456960` InsertN (known family; not owned here).
4. Anonymous xrefs `@0090a4ac` / `@0090b62c`.
5. Runtime tab-switch capture; bit-exact image.

**Verdict:** **accept-with-gaps** — ABI, offsets, erase+InsertN CF, caller pattern sealed; product labels + policy open.

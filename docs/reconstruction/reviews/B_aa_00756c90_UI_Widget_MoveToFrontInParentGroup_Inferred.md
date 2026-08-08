# Review B (skeptical / adversarial): `aa_00756c90` UI_Widget_MoveToFrontInParentGroup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756c90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-003) |
| **Counterpart** | `reviews/A_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ABI/CF/move-to-front; **falsify** pure-remove / thiscall / inventory-wire / stack-arg / Runtime Confirmed claims |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Inventory transfer / grab-drop packet sender | Body is only pointer-vector erase + InsertN; **no** C2S opcodes | **Falsified** as inventory wire |
| 2 | Pure “remove from group” / list-detach | After optional erase, always `FUN_00456960` InsertN(1) at begin when size≠1; **does not** clear `widget+0x88` (true detach is `FUN_00756be0`) | **Falsified** as pure-remove |
| 3 | `__thiscall` ECX = widget | Entry uses **EDI**; ECX loaded from group+0x94 / set to 1 for InsertN | **Falsified** |
| 4 | `unaff_EDI` is decompiler garbage | Call sites `MOV EDI, [host+tabSlot]` immediately before `CALL 00756c90` | **Falsified** — EDI is real formal |
| 5 | Stack formals / stdcall `RET n` | Epilogue `POP ESI; POP ECX; RET` (`C3`); prologue only allocates local | **Falsified** |
| 6 | `FUN_00456960` is erase/destroy | Decompile + family notes = StdVector **InsertN**; live ECX=1, value=widget | **Falsified** as erase |
| 7 | size==1 path still mutates | `CMP EAX,1; JZ` success before scan | **Falsified** |
| 8 | Sole caller is parent `00888b00` | **28** xrefs / **12** named callers incl. `00889410`, `00889fb0`, `00887780`, … | **Falsified** as sole |
| 9 | Product name Confirmed | No RTTI on VA; `_Inferred` required | **Open** |
| 10 | Runtime Confirmed | No Launcher this pass | **Open** — **never** claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI widget + plain RET + EAX status | **High** | Wrong call sites / stack cleanup |
| group `@+0x88`, vec `@+0x94/+0x98` | **High** | Wrong layout port |
| Move-to-front = erase + InsertN | **High** | Mis-port as detach-only |
| size==1 no-op | **High** | Spurious reshuffle |
| Product policy of front-order | **Tentative** | Wrong UI semantics story |
| Host/group class English name | **Open** | Mis-attributed UI |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

- Frozen raw 2026-07-23 CF ≡ live 2026-08-05 decompile + disasm.
- Parent duals R11-031/032 residual notes said “remove widget from group / list-detach” — **incomplete**; sealed body re-inserts at front. Path A name corrects to move-to-front.
- Sibling `FUN_00756be0`: thiscall group, stack widget, erase + **`widget+0x88 = 0`** — true detach; different VA, do not merge names.
- Sibling `FUN_00756d40`: rebind path using `FUN_00756be0` + `FUN_004406e0` — attach family, not this unit.
- `FUN_00456960` used across std::vector InsertN sites (`aa_0040b6d0` family notes) — consistent with front insert.
- Tab hosts pair this unit with collapsed chrome (`FUN_00822cb0` BL=0) — multi-caller, not Cs2d-only.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_Widget_MoveToFrontInParentGroup_Inferred` | **Accept INFERRED** — erase+InsertN front CF + group vector layout |
| `UI_Widget_RemoveFromGroup_Inferred` | **Reject** as canonical — misses re-insert; confuses with `FUN_00756be0` |
| `Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00756c90` | **Reject** as canonical — true ancestry but under-specific |
| `Client_SendInventory*` | **Reject** — no wire |
| `FUN_00756c90` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// custom ABI: EDI=widget*; no stack args; RET; EAX status
group = widget[+0x88]
if !group: return -1
if group.childVec size == 1: return 0
erase widget from childVec if present
InsertN(childVec, front, 1, widget)   // FUN_00456960
return 0
// not inventory transfer; not true detach (does not clear +0x88)
```

**Verdict:** **accept-with-gaps**.

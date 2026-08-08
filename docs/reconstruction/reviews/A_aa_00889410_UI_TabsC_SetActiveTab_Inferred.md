# Review A (reconstruction fidelity): `aa_00889410` UI_TabsC_SetActiveTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00889410` |
| **VA** | `0x00889410` |
| **Body** | `0x00889410`–`0x008896f3` inclusive (**740 B** / `0x2E4`); terminal `C2 08 00`; pad `CC` |
| **Canonical name** | `UI_TabsC_SetActiveTab_Inferred` (**Inferred**); Ghidra `FUN_00889410` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` |
| **System** | inventory-transfer / `i_d_tabs_c_*` dialog tab switch |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `get_assembly_context`, `read_memory`, `batch_decompile` (callees/siblings) — **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** — CF/ABI/tab matrix/XML map/14 xrefs sealed; product English + vtbl names + helper duals open |
| **Dual status** | **Present (R11-032)** |

---

## 1. Purpose

Host-dialog **active-tab setter** for the client inventory `i_d_tabs_c` window:

```text
gate: host visible (vtbl+0x3d8) && (force || tabIndex != dialog+0x530)
dialog+0x530 = tabIndex
switch tabIndex:
  0 char         → show +0x50c; hide +0x510,+0x514; select +0x518; deselect +0x51c,+0x520
  1 achievements → show +0x514; hide +0x50c,+0x510; select +0x520; deselect +0x518,+0x51c; RET
  2 locker       → show +0x510; hide +0x50c,+0x514; select +0x51c; deselect +0x518,+0x520
  else           → store only
```

**ABI:** hybrid `__usercall` — **EAX=tabIndex**, stack **dialog\*** + **force**, **`RET 0x8`**, void.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` `0x00889410` ≡ raw body CF |
| Complete analysis | `analyze_function_complete` — callers/callees/xrefs/locals/phantom `in_EAX` |
| Body bounds | `get_function_by_address` → `00889410`–`008896f3` |
| Machine listing | `disassemble_function` (full body; not `disassemble_bytes`) |
| Entry/exit bytes | `read_memory` @ `0x00889410` / `0x008896f1` |
| Call-site context | `get_assembly_context` on all 14 xrefs |
| Ctor evidence | decompile `FUN_00889960` — XML tab strings + slot assignments |
| Parent evidence | decompile `FUN_0082f510` case 4 → this VA with EAX=0 |
| Sibling pattern | decompile `FUN_00888b00` / `FUN_00889fb0` (2-tab twins; not owned) |
| Scaffold | raw append + annotated/clean/function refresh R11-032 |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits, dual of `FUN_00822cb0` / `FUN_00756c90` / `FUN_00889960`.

---

## 3. Machine seal

| Claim | Evidence | Conf |
|---|---|---|
| Prolog usercall | `55 8B 6C 24 08 56 8B F0` — EBP←stack dialog, ESI←EAX tabIndex | **Confirmed** |
| Force load | `MOV EBX,[ESP+0x14]` after two more pushes = original stack force | **Confirmed** |
| Visible gate | `CALL [vtbl+0x3d8]; TEST AL,AL; JZ epilogue` | **Confirmed** |
| Same-tab skip | `TEST BL,BL; JNZ do; CMP ESI,[EBP+0x530]; JZ epilogue` | **Confirmed** |
| Store active | `MOV [EBP+0x530],ESI` | **Confirmed** |
| 3-way mode | `SUB EAX,0; JZ mode0; SUB EAX,1; JZ mode1; SUB EAX,1; JNZ epilogue` → mode2 | **Confirmed** |
| Mode1 early RET | `RET 8` @ `0x0088960d` before shared tail | **Confirmed** |
| Stack cleanup | all exits `C2 08 00` | **Confirmed** |
| Pane show/hide | vtbl `+0x43c`+`+0x4(1)` / `+0x4(0)`+`+0x440` per matrix | **Confirmed** |
| Tab select refresh | selected path ends `CALL [vtbl+0x94]` | **Confirmed** |
| 00822cb0 reg ABI | `MOV ESI,widget; MOV/XOR BL; PUSH force; CALL 00822cb0` | **Confirmed** |
| 00756c90 reg ABI | `MOV EDI,widget; CALL 00756c90` | **Confirmed** |
| XML tab map | ctor loads char/locker/achievements into `+0x518/+0x51c/+0x520` | **Confirmed** |
| 14 xrefs | `get_function_xrefs` | **Confirmed** |
| Decompile ≡ raw CF | live decompile matches raw panel/tab arms | **Confirmed** |
| Entry/exit bytes | `read_memory` | **Confirmed** |

---

## 4. Gaps

- Product/PDB method English for the dialog class / this setter.
- Official names of vtbl `+0x3d8` / `+0x43c` / `+0x440` / `+0x94` / `+0x4`.
- Full C++ types of dialog / panes / tab buttons.
- Dual seal of register helpers `FUN_00822cb0` / `FUN_00756c90`.
- Ctor `FUN_00889960` residual (not OWN).
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — CF, hybrid ABI (EAX tabIndex + 2 stack + RET 8), 3-tab char/achievements/locker matrix, XML evidence, host global, and 14 callers sealed; residual is product naming + helper duals + runtime only.

# Review B (skeptical / adversarial): `aa_00889410` UI_TabsC_SetActiveTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00889410` |
| **VA** | `0x00889410` |
| **Canonical name** | `UI_TabsC_SetActiveTab_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` |
| **System** | inventory-transfer / `i_d_tabs_c_*` dialog tab switch |
| **Live tools** | Independent decompile + `disassemble_function` + `read_memory` + call-site context + ctor/parent decompile |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/tab matrix/14 xrefs; reject thiscall / void-only-stack / 2-arg complete / scaffold-product / inventory-packet claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra signature `void FUN_*(int*, undefined4)` is complete ABI | **Falsified** — entry `MOV ESI,EAX`; 14 call sites preload EAX with 0/1/2/current; **tabIndex is a third formal in EAX** |
| 2 | thiscall / ECX = dialog | **Falsified** — entry loads dialog from **stack** (`MOV EBP,[ESP+8]` after `PUSH EBP`); no `MOV reg,ECX` of this |
| 3 | `in_EAX` is leftover garbage / return of prior call | **Falsified** — call sites explicitly `XOR EAX,EAX` / `MOV EAX,1` / `MOV EAX,2` / `MOV EAX,[EDI+0x530]` immediately before CALL |
| 4 | `param_2` is the tab index | **Falsified** — `param_2` is force byte (`TEST BL,BL`); tab index is ESI/EAX; force 0/1 both observed with varying EAX |
| 5 | Only 2 tabs (merge with `FUN_00888b00`) | **Falsified** — three mode arms + three tab widgets + three XML names; siblings are 2-tab with different slot maps |
| 6 | Tab 1 is locker (linear pane order) | **Falsified** — mode 1 shows `+0x514` and selects `+0x520` (achievements XML); locker is mode **2** / `+0x510` / `+0x51c` |
| 7 | Scaffold `Named_CalleeOf_Client_Input_PollBoundActions_*` is product | **Rejected** — parent-seed chain name; not plate / not PDB |
| 8 | This is a C2S inventory packet builder | **Falsified** — pure UI show/hide + tab chrome; no opcode / no grid place |
| 9 | `FUN_00822cb0` takes only force (no widget) | **Falsified** — every call site sets **ESI=widget** and **BL=selected** before CALL |
| 10 | Mode 1 falls through shared deselect-ach tail | **Falsified** — early `RET 8` @ `0x0088960d` after selecting achievements |
| 11 | Sole caller is parent `0x0082f510` | **Falsified** — **14** xrefs; parent is one of many (case 4 → tab 0 only) |
| 12 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hybrid ABI EAX+2 stack+RET 8 | **High** | Wrong calling convention on port |
| 3-tab matrix char/ach/locker | **High** | Wrong pane shown |
| Layout +0x50c..+0x530 | **High** | Corrupt dialog object |
| force / same-tab gate | **High** | Spurious / missing switches |
| 00822cb0 / 00756c90 register ABI | **High** | Silent no-op helpers |
| XML string → tab button map | **High** | Wrong English labels only if swapped — matrix matches ctor |
| Product method English | **None** | Overclaim name |
| Official vtbl method names | **Low** | Wrong UI API labels on port |
| Full widget C++ types | **Low** | Adjacent field misuse |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** drop **EAX tabIndex** — decompiler `in_EAX` phantom is load-bearing.
2. Do **not** treat as thiscall — dialog is **stack arg**, not ECX.
3. Do **not** trust decompiler pairing of `FUN_00822cb0` to a single panel — targets are **ESI** widgets (`+0x518/+0x51c/+0x520`).
4. Do **not** trust decompiler `FUN_00756c90()` as nullary pure — **EDI** carries the widget.
5. Do **not** assume pane index == tabIndex (pane for tab 1 is `+0x514`, for tab 2 is `+0x510`).
6. Do **not** “fix” mode-1 early return into shared tail — bytes return after achievements select.
7. Scaffold `Named_CalleeOf_Client_Input_PollBoundActions_*` — **ignore as product symbol**.
8. Sibling 2-tab switchers `FUN_00888b00` / `FUN_00889fb0` — **do not merge**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| `i_d_tabs_c` dialog active-tab setter | Official PDB `SetActiveTab` symbol |
| Tabs 0/1/2 = char/achievements/locker (XML+matrix) | Product enum names beyond XML stems |
| Hybrid usercall + RET 8 + void | thiscall / cdecl-only / non-void |
| 14 callers including input poll + class-8 case 4 | Sole-caller / packet path |
| Host global `DAT_00d1b874` | Product dialog class name |
| `_Inferred` structural name | Confirmed product method English |
| Register ABI of residual helpers | Full dual of those helpers |

---

## 5. CF challenge of Review A

- Body bounds + RET 8 + pad: **agree Confirmed**
- ABI hybrid EAX tabIndex + stack dialog/force: **agree Confirmed**
- Tab matrix + XML map: **agree Confirmed**
- 14 xrefs / multi-caller: **agree Confirmed**
- accept-with-gaps (not bare accept): **agree** — product English + vtbl names + helper duals residual is real

**Verdict:** **accept-with-gaps**

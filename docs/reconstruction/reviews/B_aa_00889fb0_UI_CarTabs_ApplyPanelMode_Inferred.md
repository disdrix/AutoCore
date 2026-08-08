# Review B (skeptical / adversarial): `aa_00889fb0` UI_CarTabs_ApplyPanelMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00889fb0` |
| **VA** | `0x00889fb0` |
| **Canonical name** | `UI_CarTabs_ApplyPanelMode_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00889fb0_UI_CarTabs_ApplyPanelMode_Inferred.md` |
| **System** | inventory-transfer / car-tabs UI panel mode |
| **Live tools** | Independent decompile + `read_memory` + callers + init XML evidence |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/mode arms/tab roles; reject thiscall-only, mode-on-stack, inventory-packet, sole-caller, scaffold-product claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Standard `__thiscall` with mode as stack arg | **Falsified** — entry `MOV ESI,EAX` (mode); host from `[ESP+8]` after `PUSH EBP`; no `MOV reg,ECX` this |
| 2 | `param_2` is the panel mode | **Falsified** — `param_2` is **force** (`MOV EBX,[ESP+0x14]`; `TEST BL`); mode is EAX |
| 3 | cdecl / no stack cleanup | **Falsified** — all exits `RET 8` (`C2 08 00`) |
| 4 | Returns success in AL | **Falsified** — void; epilogues do not set AL |
| 5 | Sole caller `Client_Input_PollBoundActions` | **Falsified** — 13 CALL xrefs incl. `FUN_0082f510`, `FUN_0088a290`, `FUN_0080c240`, tab handlers |
| 6 | Scaffold `Named_CalleeOf_Client_Input_PollBoundActions_00889fb0` is product | **Rejected** — parent-seed name only |
| 7 | Sends inventory C2S packets (`0x2034`/`0x2036`) | **Falsified** — only UI show/hide/layout + list detach; no opcode immediates |
| 8 | Ternary modes like sibling `FUN_00889410` | **Falsified** — only arms for mode **0** and **1**; other modes store and exit |
| 9 | Cargo/mission roles invented | **Falsified attack** — roles sealed by init XML in `FUN_0088a290` (`tab_cargo` / `tab_mission`) loading into `+0x514`/`+0x518` |
| 10 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Binary mode 0/1 CF + store `+0x528` | **High** | Wrong tab switch |
| ABI EAX mode + 2 stack + RET 8 | **High** | Stack smash / wrong mode on port |
| Visible gate `vtbl+0x3d8` | **High** | Apply when hidden |
| Cargo/mission tab slots via init XML | **High** | Swapped panels |
| Multi-caller surface | **High** | Miss bind/menu paths |
| Product class / PDB English | **None** | Overclaim name |
| `FUN_00822cb0` full geometry meaning | **Low–Med** | Wrong expand/collapse port |
| Chrome A/B product labels (`+0x50c/+0x510`) | **Low** | Wrong chrome mapping |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** treat as pure thiscall ECX-this — host is **stack arg0**; mode is **EAX**.
2. Do **not** pass mode as the second stack argument — that is **force**.
3. Do **not** drop ESI/EDI/BL register contract for `FUN_00822cb0` / `FUN_00756c90` — decompiler only surfaces the force stack char.
4. Do **not** invent mode 2+ arms — machine falls through after store.
5. Do **not** treat as inventory wire sender — UI panel only.
6. Scaffold PollBoundActions alias — **ignore as product symbol**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Binary car-tabs panel mode apply | Official PDB `CarTabs::Apply…` symbol |
| Mode 0 cargo / mode 1 mission (XML-backed) | Product chrome A/B English |
| EAX mode + force stack + RET 8 | thiscall-only / cdecl |
| Multi-caller (menu/bind/init/tabs) | Sole-caller |
| `_Inferred` structural name | Confirmed product method English |
| UI show/hide/layout only | Inventory packet emit |

---

## 5. CF challenge of Review A

- Body bounds + RET 8: **agree Confirmed**
- EAX mode + force + host stack: **agree Confirmed**
- Mode 0/1 arms + offsets: **agree Confirmed**
- Cargo/mission via init XML: **agree Confirmed** (roles structural; product chrome labels open)
- accept-with-gaps (not bare accept): **agree** — product class English + helper duals + runtime residual is real

**Verdict:** **accept-with-gaps**

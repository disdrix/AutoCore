# Review A (reconstruction fidelity): `aa_008e2d60` Client_UI_CraftHost_ResetRecipePanel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e2d60` |
| **VA** | `0x008e2d60`–`0x008e2e5e` |
| **Canonical name** | `Client_UI_CraftHost_ResetRecipePanel_Inferred` |
| **Prior names** | `FUN_008e2d60`, `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e2d60` |
| **Review date** | `2026-08-05` (MEGA-085 dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_008e2d60_Client_UI_CraftHost_ResetRecipePanel_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Reset craft/RE host panel recipe chrome: walk a fixed **5×5** cell grid, destroy optional per-cell owned objects, invalidate cell TFID pairs to `0xFFFFFFFF/0xFFFFFFFF`, hide/refresh cell widgets, hide row chrome, then hide/refresh footer widgets at `host+0x748` / optional `+0x768` / `+0x76c`.

Called from bind/rebuild (`FUN_008e5990`) before re-populating slots, and from an orphan float-gate path near `0x008e6390`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008e2d60_FUN_008e2d60.md` (+ 2026-08-05 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_008e2d60_FUN_008e2d60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_ResetRecipePanel_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e2d60.cpp` |
| Live | Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` |
| Not performed | `disassemble_bytes`, Launcher, bit-exact, runtime |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| stdcall `RET 4`, stack host* | **High** | prologue `MOV ESI,[ESP+0x14]`; epilogue `RET 4`; callers `PUSH` host |
| Not thiscall host-in-ECX | **High** | ECX used only for per-widget this |
| 5×5 nested loops | **High** | counters `local_4=5`, `EBX=5` |
| TFID invalidate −1/−1 @ `+0x680` | **High** | dual stores per cell, stride 8 |
| Owned object dtor @ cell+0x64 / host+0x61c | **High** | vtbl[0](1) then clear |
| Indirect vtbl-only callees | **High** | analyze callees empty; disasm CALL [reg+imm] |
| Tail JMP is hide tail-call not jumptable | **High** | `MOV [ESP+4],0; JMP [EAX+4]` after full restore |
| “Reset recipe panel” English | **Inferred** | structure + parent bind path; no product string in body |
| Host product RTTI class name | **Open** | not sealed in this unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Outer×inner 5×5 | Yes |
| Optional owned dtor(1) + clear | Yes |
| TFID −1/−1 | Yes |
| Query 0x2bc → optional 0x58; then 0xcc(0); 0x34c | Yes |
| Row peer+primary hide 0x4(0) | Yes |
| Footer 0x748: 0xd4(0)+0x34c | Yes |
| Optional 0x768 hide | Yes |
| Optional 0x76c tail hide | Yes (clean models as call+return; retail is JMP tail) |

---

## 5. Gaps

1. Product RTTI / English name of craft host class.
2. English names for vtbl slots (0x2bc / 0x58 / 0xcc / 0x34c / 0xd4 / +4).
3. Second caller body undeffed in Ghidra (~`0x008e6390`); full contract open.
4. Parent `FUN_008e5990` residual (MEGA-032 hint `UI_CraftHost_BindResolvedObject`) — not OWN.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

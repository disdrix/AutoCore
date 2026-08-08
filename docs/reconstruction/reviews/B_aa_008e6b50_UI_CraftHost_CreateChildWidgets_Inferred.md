# Review B (adversarial): `aa_008e6b50` UI_CraftHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e6b50` |
| **VA** | `0x008e6b50`–`0x008e811f` inclusive (**5584 B** / `0x15D0`) |
| **Canonical name** | `UI_CraftHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008e6b50` |
| **Review date** | `2026-08-05` (R11-036 dual seal) |
| **Reviewer role** | Adversarial / claim-falsification (OWN-ONLY R11-036) |
| **Counterpart** | `reviews/A_aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer |
| **Evidence pass** | Same live Ghidra set as A; assembly authority on conflicts |
| **Verdict** | **accept-with-gaps** |

---

## Claims tested

| # | Claim | Result | Evidence |
|---|---|---|---|
| 1 | cdecl / stdcall with stack host | **FALSIFIED** | `MOV EBP,ECX`; exit `C3` not `C2 xx` |
| 2 | pure `__fastcall` with unused EDX formal | **FALSIFIED as product ABI** | ECX only; no EDX use as formal; Ghidra `__fastcall` display is incomplete |
| 3 | RET 4 / stack object arg | **FALSIFIED** | no stack args; `RET`/`C3`; object only via `host+0x7cc` at tail |
| 4 | Direct CALL callers | **FALSIFIED** | analyze callers empty; sole xref DATA `0x00a3aca8` |
| 5 | This is BindResolvedObject / TFID bind | **FALSIFIED** | body builds chrome; **calls** dualed `008e5990` once at tail |
| 6 | Only builds tabs | **FALSIFIED** | 38+ XML string pushes; 5-slot component loop; geo buffered pane |
| 7 | Material slots elsewhere than +0x568 | **FALSIFIED for first column** | `ESI=+0x5b8`, store `[ESI-0x50]` => `+0x568`; stride +4 ×5 |
| 8 | Geo pane is plain 0x488 window | **FALSIFIED** | `new(0x4FC)` + `FUN_0078caf0` -> `+0x520` |
| 9 | Decompiler unaff_* are real formals | **FALSIFIED** | assembly shows widgets in stack/regs after new; unaff is decompiler failure |
| 10 | Product class name Confirmed | **OPEN** | no RTTI sealed; name stays `_Inferred` |
| 11 | Runtime Confirmed | **OPEN** | no Launcher; Terminal false |

---

## Odd behavior preserved

1. Store-heavy CreateChildWidgets then **always** rebinds via `008e5990` even if `host+0x7cc` is null/stale.
2. Gate byte `+0x7e2` comes from residual `0052eb90` on global `DAT_00d1b6d8`, not from XML.
3. Multiple z-order bumps (`+0x68/+0x70/+0x74` + `vtbl+0x3f4`) interleaved with construction — not a single final layout pass only.
4. Optional `DAT_00d1b8b4` path can inject title/string via `vtbl+0x114` before rebind.

---

## Name challenge

- Reject inventing unconfirmed `CDlgCraft2d_*` demangle without RTTI.
- Accept role family **CreateChildWidgets** (matches dualed trade/charsheet pattern + virtual DATA dispatch).
- Accept host family **CraftHost** (sealed `i_d_craft_2d_*` + dualed bind callee + shared slots `+0x520/+0x530/+0x54c/+0x568/+0x7cc`).
- Final: `UI_CraftHost_CreateChildWidgets_Inferred`.

---

## Verdict

**accept-with-gaps** — adversarial pass falsifies wrong ABI/role merges; residual English/RTTI/runtime remain open. Agrees with Path A.

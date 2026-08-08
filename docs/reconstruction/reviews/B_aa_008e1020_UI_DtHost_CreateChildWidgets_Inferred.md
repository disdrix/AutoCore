# Review B (adversarial): `aa_008e1020` UI_DtHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e1020` |
| **VA** | `0x008e1020`–`0x008e17be` inclusive (**1951 B** / `0x79F`) |
| **Canonical name** | `UI_DtHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008e1020` |
| **Review date** | `2026-08-05` (R13-014 dual seal) |
| **Reviewer role** | Adversarial / claim-falsification (OWN-ONLY R13-014) |
| **Counterpart** | `reviews/A_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer |
| **Evidence pass** | Same live Ghidra set as A; assembly authority (decompiler failed) |
| **Verdict** | **accept-with-gaps** |

---

## Claims tested

| # | Claim | Result | Evidence |
|---|---|---|---|
| 1 | cdecl / stdcall with stack host | **FALSIFIED** | `MOV EBP,ECX`; exit `C3` not `C2 xx` |
| 2 | pure `__fastcall` with unused EDX formal | **FALSIFIED as product ABI** | ECX only; no EDX formal use |
| 3 | RET 4 / stack object arg | **FALSIFIED** | no stack args; `RET`/`C3` |
| 4 | Direct CALL callers | **FALSIFIED** | analyze callers empty; sole xref DATA `0x00a3c3a0` |
| 5 | This is inventory C2S grab/drop/equip wire | **FALSIFIED** | body is UI chrome new/attach/XML/tabs only; no send-packet leaves |
| 6 | This is craft CreateChildWidgets `008e6b50` | **FALSIFIED** | different VA/vtbl; XML family `i_d_dt_2d_*` not `i_d_craft_2d_*`; no material loop / no bind tail `008e5990` |
| 7 | This is trade CreateChildWidgets `008847f0` | **FALSIFIED** | no dual inventory grids; different XML prefix |
| 8 | Only builds tabs / pure MoveToFront wrapper | **FALSIFIED** | 14+ XML children + close + two tabs + optional global path |
| 9 | Decompiler void/empty means empty function | **FALSIFIED** | decompile fail reason overlapping varnodes; full 1951 B disasm + RET |
| 10 | ECX thiscall is wrong; EDI/ESI register ABI like tab helpers | **FALSIFIED** | entry `MOV EBP,ECX`; ESI/EDI only used for local children/tab temps |
| 11 | Product class name Confirmed | **OPEN** | no RTTI sealed; name stays `_Inferred` |
| 12 | Runtime Confirmed | **OPEN** | no Launcher; Terminal false |

---

## Odd behavior preserved

1. **Decompiler hard-fail** (Overlapping input varnodes) while body is real — reconstruction must stay ASM-structural.
2. **`+0x530` double-store**: title pointer then icon pointer — title is not retained in that slot after the icon write.
3. Crafting tab is built **unselected** then **moved to front** (`00756c90`); disciplines tab is **selected** — asymmetric tab policy.
4. Optional `DAT_00d1b8a8` path can inject a string via `vtbl+0x114` before post-build; not inventory transfer.
5. Multiple z-order bumps interleaved with construction (not a single final layout pass only).

---

## Name challenge

- Reject inventing unconfirmed `CDlgDt2d_*` demangle without RTTI.
- Accept role family **CreateChildWidgets** (matches dualed trade/craft pattern + virtual DATA dispatch).
- Accept host family **DtHost** from sealed `i_d_dt_2d_*` XML prefix (sibling of craft host / trade dialog families).
- Final: `UI_DtHost_CreateChildWidgets_Inferred`.

---

## Verdict

**accept-with-gaps** — adversarial pass falsifies wrong ABI/role merges and inventory-wire claims; residual English/RTTI/runtime remain open. Agrees with Path A.

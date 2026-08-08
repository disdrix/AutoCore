# Review B (adversarial): `aa_008e2d60` Client_UI_CraftHost_ResetRecipePanel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e2d60` |
| **VA** | `0x008e2d60` |
| **Canonical name** | `Client_UI_CraftHost_ResetRecipePanel_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / falsification |
| **Counterpart** | `reviews/A_aa_008e2d60_Client_UI_CraftHost_ResetRecipePanel_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks attempted

| # | Hypothesis | Result |
|---|------------|--------|
| 1 | thiscall ECX=host on entry | **Falsified** — host loaded from `[ESP+0x14]`; callers push host; ECX only set to widgets |
| 2 | cdecl (caller cleans stack) | **Falsified** — `RET 4`; bind site does not `ADD ESP,4` after call |
| 3 | Network / C2S craft submit | **Falsified** — no packet builders; vtbl UI only; no DAT send paths |
| 4 | Mission UI refresh (`Named_CalleeOf_*Client_RefreshOpen*`) | **Reject scaffold** — body is host recipe-cell clear; sole named caller is craft bind `FUN_008e5990` |
| 5 | 5×1 or 1×5 only (not 5×5) | **Falsified** — nested counters both 5; TFID stride 8 × 25 cells |
| 6 | Jumptable multi-branch at `0x008e2e55` | **Falsified** — single `JMP [EAX+4]` tail after rewrite of stack arg to 0 |
| 7 | Mutates bound object at `host+0x7cc` | **Falsified** — never reads/writes `+0x7cc` (parent bind does) |
| 8 | Direct callees / non-leaf | **Falsified** — analyze callees empty; all CALL [reg+disp] |
| 9 | Product class name sealed without RTTI | **Not claimed** — `_Inferred` retained |

---

## Residual risks

- Decompiler “jumptable” warning can mislead ports into inventing multi-way dispatch — bytes show one tail JMP.
- Clean C models tail JMP as ordinary call+return (same observable if hide returns normally); stack-frame equivalence is approximate only on that path.
- Second call site lives in **undefined** Ghidra body between `FUN_008e5e00` end and `FUN_008e6490`; full gate English open.
- Vtbl slot English and host RTTI remain open — do not invent product names.

---

## Confirmations with A

- stdcall RET 4 + 5×5 reset sealed.
- TFID invalidate + owned dtor + footer hide sealed.
- Scaffold `Named_CalleeOf_*` rejected.
- Dual verdict align: **accept-with-gaps**.

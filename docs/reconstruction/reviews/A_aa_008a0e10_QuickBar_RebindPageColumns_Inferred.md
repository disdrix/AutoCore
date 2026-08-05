# Review A (reconstruction fidelity): `aa_008a0e10` QuickBar_RebindPageColumns_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0e10` |
| **VA** | `0x008a0e10` |
| **Canonical name** | `QuickBar_RebindPageColumns_Inferred` |
| **System** | `skills-abilities` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md` |
| Raw | `docs/reconstruction/raw/aa_008a0e10_FUN_008a0e10.md` |
| Annotated | `docs/reconstruction/raw/aa_008a0e10_FUN_008a0e10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_RebindPageColumns_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008a0e10.cpp` |
| Parent dual | `reviews/A_aa_008a0ed0_QuickBar_SelectPage_Inferred.md` |
| Seal tools | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (no `disassemble_bytes`) |

---

## 2. Purpose (from unit)

Rebind the ten QuickBar page-column widgets for `host[+0x50c]` page from `DAT_00d1da60[page*10+col]` (types skill/item/macro/clear). Not page select and not slot activate.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| stdcall host* stack formal (`RET 4`) | **High** | epilogue sealed |
| Gate: vtbl+0x3d8 and `DAT_00d1b6d8` | **High** | |
| Loop count 10; widgets `host+0x63c` | **High** | matches SelectPage |
| Page at `host+0x50c` / `[0x143]` | **High** | |
| Type table stride 0x18 | **High** | index scale sealed |
| Types 1 / 2 / 5 / else | **High** | SUB chain |
| FUN_007fce10(&DAT_00d1a840) prelude | **High** CF | product name open |
| Type-1 skill binder FUN_00826860 | **High** role | full ABI Probable from bytes |
| Type-2 item binder FUN_008283a0 | **High** role | decomp args empty — bytes fill |
| Type-5 macro binder FUN_00827670 | **High** | push id + EAX=5 |
| Else clear QuickBar_ClearActiveSlot_INFERRED | **High** | named in decomp |
| Role name RebindPageColumns | **Inferred** | SelectPage dual agreement |
| Product English symbol | **Tentative** | no string in unit |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Visible/global early-out | **Yes** |
| Context prep FUN_007fce10 | **Yes** |
| 10-iter column loop | **Yes** |
| Type 1/2/5/else dispatch | **Yes** |
| No page write / no select | **Yes** (rebind only) |
| Clean CF ≡ raw decompile | **Yes** |
| Callee arg lists ≡ decompile | **No** — bytes richer for 1/2; documented in clean comments |

---

## 5. Gaps

1. Product names for binders, `FUN_007fce10`, `DAT_00d1b6d8`, `DAT_00d1a840`.
2. Full formal signatures of type-1/2 callees (register pairs sealed; source prototypes open).
3. Slot-row field semantics beyond type/id dwords.
4. Runtime page-switch rebind capture.
5. Callee dual seals for `FUN_00826860` / `FUN_008283a0` / `FUN_00827670` (out of ownership).

**Verdict:** **accept-with-gaps** — rebind CF and layout High; callee product ABI residual.

# Review A (reconstruction fidelity): `aa_009251d0` Client_InteractClickPickDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009251d0` |
| **VA** | `0x009251d0`–`0x009253d6` inclusive (**519 B** / `0x207`) |
| **Canonical name** | `Client_InteractClickPickDispatch_Inferred` |
| **Ghidra name** | `FUN_009251d0` |
| **Prior scaffold** | `FUN_009251d0` (2026-07-23 trio) |
| **Rejected misname** | free `void` / same-as-WorldClickHub / primary UseObject owner / thiscall-RET0 |
| **Review date** | `2026-08-05` (R11-038 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual **click entry / dispatch** on the client controller that:

1. Swallows clicks in mode-6 quiet triple (same polarity as dualed WorldClickHub).
2. Forwards packed mouse coords through client vtbls `+0x3bc` / `+0x42c` on select slot `+0x4b8`.
3. Lets a selected object consume the click via its `vtbl+0x378`.
4. Cancels pending skill target-select when `DAT_00d1d900 != -1` (`Client_PromptSkillTargetSelect` + `FUN_007fb990`).
5. Gates on character null / dead-component / UI modal `vtbl+0x3d8` pair.
6. Writes free-select flag `DAT_00d1a859` from `FUN_00914be0` + `char+0xcd0` + optional UI slots.
7. Calls dualed **`Client_InteractClickPickTarget`** with **soft `0`** or **commit `1`** from `DAT_00d1a860`.
8. Soft path may set `client+0xa35` and **`CVOGHBBase_Start(client+0xc70)`**.

**Not** the 25f UseObject hub itself — that is parent `0x009247b0`. **Not** sibling ItemPickup/soft-cast hub `0x00925820`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_009251d0_FUN_009251d0.md` (+ R11-038 append; body preserved) |
| Annotated | `raw/aa_009251d0_FUN_009251d0.annotated.md` |
| Clean named | `reconstructed-exact/Client_InteractClickPickDispatch_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_009251d0.cpp` |
| Function records | `functions/aa_009251d0_FUN_009251d0.md`, `…_Client_InteractClickPickDispatch_Inferred.md` |
| Live decompile | Ghidra `@ 0x009251d0` ≡ frozen raw CF |
| Asm | `disassemble_function` full body; epilogue bytes `@ 0x009253d0` |
| Xrefs | DATA only `@ 0x00a2f41c` |
| Memory | vtable window `@ 0x00a2f400`; pad `CC` after RET |
| Parent dual | `A|B_aa_009247b0_Client_InteractClickPickTarget` |
| Sibling dual | `A|B_aa_00925820_Client_InteractWorldClickHub` |
| Skill cancel | `A|B_aa_0093bac0_Client_PromptSkillTargetSelect` |

---

## 3. Byte / ABI seal

| Claim | Evidence | Conf |
|---|---|---|
| Body 519 B | `009251d0`–`009253d6`; next `CC` | **Confirmed** |
| thiscall `MOV EBX,ECX` | prologue `@ 0x009251d4` | **Confirmed** |
| `RET 8` | `C2 08 00` `@ 0x009253d4` | **Confirmed** |
| 2 stack formals | `MOV EBP,[ESP+…]` packed; `MOV ESI,[ESP+…]` arg1 | **Confirmed** |
| Packed mouse lo/hi i16 | `MOVSX` + `SHR 0x10` before vtbl `+0x42c` | **Confirmed** |
| Soft `PUSH 0` / commit `PUSH 1` | `@ 0x009253a5` / `@ 0x0092538b` | **Confirmed** |
| Vtable install | dword `@ 0x00a2f41c` = `0x009251d0` | **Confirmed** |
| Sibling next slot | `@ 0x00a2f420` = `0x00925820` | **Confirmed** |
| No direct CALL xrefs | `get_function_xrefs` DATA-only | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-stage click dispatch role | **High** | callees + parent dual + vtable neighbor |
| Live decompile ≡ raw CF | **Confirmed** | R11-038 re-decompile |
| ABI thiscall + RET 8 + packed mouse | **Confirmed** | asm + bytes |
| Soft/commit polarity via `DAT_00d1a860` | **Confirmed** | PUSH imm sites |
| Skill cancel when pending ≠ −1 | **Confirmed** | dualed PromptSkillTargetSelect call |
| Writes `DAT_00d1a859` free flag | **Confirmed** | store 0/1 sites |
| Soft path HB start + `+0xa35` | **Confirmed** | `CVOGHBBase_Start` `@ 0x005081c0` |
| Not UseObject owner / not WorldClickHub | **High** | no SendUseObject/ItemPickup in body |
| Structural name `_Inferred` | **Probable** | product method English Open |
| Stack `arg1` product meaning | **Open** | forwarded residual |
| Vtbl slot English / which UI event | **Open** | |
| Runtime click capture | **Open** | |

---

## 5. Call graph (this unit)

```text
[client vtbl @ 0x00a2f41c]
  └─ Client_InteractClickPickDispatch_Inferred  (0x009251d0)  [OWN R11-038]
       ├─ client vtbl +0x3bc / +0x42c          (mouse UI)
       ├─ select(+0x4b8) vtbl +0x378           (consume click)
       ├─ Client_PromptSkillTargetSelect       (0x0093bac0)  [dualed]
       ├─ FUN_007fb990                         (post-cancel UI)
       ├─ character component vtbl +0x194
       ├─ UI hosts vtbl +0x3d8                 (modals)
       ├─ FUN_00914be0                         (free predicate)
       ├─ Client_InteractClickPickTarget       (0x009247b0)  [dualed parent]
       └─ CVOGHBBase_Start                     (0x005081c0)  [soft only]
```

---

## 6. Gaps

1. Product English for mode `6`, `DAT_00d1a860` / `DAT_00d1a859`, vtbl slots, stack `arg1`.
2. Live UI event that indexes `@ 0x00a2f41c` vs sibling `@ 0x00a2f420`.
3. Full dual of `FUN_00914be0` / `FUN_007fb990` (not OWN).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — OWN stage CF + ABI + soft/commit + skill-cancel + vtable install sealed; residual product English + runtime.

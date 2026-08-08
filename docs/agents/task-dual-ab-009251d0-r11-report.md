# Dual A/B report — R11-038 OWN-ONLY (`0x009251d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-038**  
**Scope:** VA `0x009251d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; parent ledgers; other VAs; `disassemble_bytes` primary; invent product names; wipe raw.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual dual seal — parent dual `0x009247b0` Client_InteractClickPickTarget; body is **click pick dispatch / gate**.  
**System:** `interaction-activation`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009251d0` Client_InteractClickPickDispatch_Inferred | **accept-with-gaps** — CF/ABI/RET8/soft-commit/skill-cancel/vtable install sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): same-as-parent / same-as-WorldClickHub / always-UseObject / inverted mode-6 / inverted soft / RET4 / direct-callers / soft-returns-pick claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x009251d0` — sealed facts

1. **Body:** `0x009251d0`–`0x009253d6` inclusive (**519 B** / `0x207`); pad `CC` after RET.
2. **ABI:** **thiscall** `ECX`=client* (saved `EBX`); stack `(arg1, packedMouse)`; **`RET 8`**; **AL** bool.
3. **packedMouse:** lo16 signed sx, hi16 signed sy (`MOVSX` / `SHR 0x10`).
4. **Install:** DATA only `@ 0x00a2f41c` → this; sibling `@ 0x00a2f420` → dualed `Client_InteractWorldClickHub`.
5. **Stages:**
   - Early-out if `client+0xcc4==6` && `+0x493==0` && `*(DAT_00d1b644+0xf5)==0`.
   - Mouse vtbls `+0x3bc` / `+0x42c` on select `+0x4b8`.
   - Selected consume `vtbl+0x378(arg1, packed)` → return 1.
   - If `DAT_00d1d900 != -1`: `Client_PromptSkillTargetSelect(-1,0)` + `FUN_007fb990` → return 1.
   - Character null / dead `+0x194` / UI modal pair `+0x3d8` → return 0.
   - Write `DAT_00d1a859` from `FUN_00914be0` + `char+0xcd0` + optional UI slots.
   - `DAT_00d1a860 != 0` → `Client_InteractClickPickTarget(..., **0**, filter)`; optional `CVOGHBBase_Start(client+0xc70)` + `+0xa35=1`; **return 0**.
   - else → return `Client_InteractClickPickTarget(..., **1**, filter)`.
6. **Callees (named where dualed):** ClickPickTarget `0x009247b0`; PromptSkillTargetSelect `0x0093bac0`; CVOGHBBase_Start `0x005081c0`; `FUN_007fb990`; `FUN_00914be0`.
7. **Name:** `Client_InteractClickPickDispatch_Inferred` (Ghidra `FUN_009251d0`). Product method English open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/soft polarity sealed via `disassemble_function` + epilogue `read_memory`.
9. **Family:** exclusive CALL producer into dualed parent ClickPickTarget; vtable neighbor of dualed WorldClickHub.

### Gaps

- Product English: mode 6, `DAT_00d1a860`/`DAT_00d1a859`, vtbl slots, stack `arg1`.  
- Which UI/input event indexes `@ 0x00a2f41c` vs sibling.  
- Duals of `FUN_00914be0` / `FUN_007fb990` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_009251d0_FUN_009251d0.md` |
| Annotated | `docs/reconstruction/raw/aa_009251d0_FUN_009251d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_InteractClickPickDispatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009251d0.cpp` |
| Function scaffold | `docs/reconstruction/functions/aa_009251d0_FUN_009251d0.md` |
| Function named | `docs/reconstruction/functions/aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
[client vtbl @ 0x00a2f41c]
  └─ FUN_009251d0  Client_InteractClickPickDispatch_Inferred  [OWN R11-038]
       └─ Client_InteractClickPickTarget  0x009247b0  [dualed parent]
            ├─ Client_SendUseObject_IfInteractable  0x00930d70
            ├─ Client_SendUseObject                 0x00916740  (25f gate)
            └─ type-4 QuestItemPickup 0x205D

[client vtbl @ 0x00a2f420]  (neighbor — not this unit)
  └─ Client_InteractWorldClickHub  0x00925820  [dualed W17-C]
       └─ ItemPickup / soft-cast / destroy modal
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-009251d0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009251d0` | Port as **virtual click dispatch/gate** into ClickPickTarget. **thiscall RET 8**; packed mouse lo/hi i16. Soft when `DAT_00d1a860≠0` (push 0, return 0 + optional HB); commit when flag clear (push 1, return pick). |
| Pair with | dualed parent ClickPickTarget `009247b0`; skill cancel PromptSkillTargetSelect `0093bac0`; sibling WorldClickHub `00925820` (do **not** merge). |
| Not | 25f UseObject owner; ItemPickup owner; product skill cast packet alone. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER` / progress / inventory status → dual-sealed
- system map `interaction-activation.md` row if desired
- mark residual queue R11-038 complete

**Terminal:** false.

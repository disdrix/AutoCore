# Dual A/B report — R10-035 OWN-ONLY (`0x00521f20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-035**  
**Scope:** VA `0x00521f20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + caller disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual partition — inventory-transfer worker under parent `0x00521eb0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00521f20` Character_ComputeTinkerSuccessChance_Inferred | **accept-with-gaps** — CF/ABI/RET8/float-pool/formula/sole caller sealed; product field English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): item-this / percent-return / phantom-DL / multi-caller / Named_CalleeOf product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00521f20` — sealed facts

1. **Body:** `0x00521f20`–`0x00521fe7` inclusive (**200 B** / `0xC8`); jump table data `0x00521fe8`–`0x00521ffb` (5× dword).
2. **ABI:** **ECX** = **character**; stack **item***, **kit***; float **ST0**; **`RET 8`**.
3. **Semantics:**
   - `character[+0x6b4] >= 1` → **1.0**
   - `need = item.vtbl[+0x8c]() + 1`
   - `tier = FUN_00521eb0(character)`; if `tier < need` → **0.0**
   - else `base(need∈1..5) + (character[+0x59b] - 2*need + kit[+0xb0]) * 0.04`
   - bases: **0.4 / 0.35 / 0.3 / 0.25 / 0.2**
4. **Callees:** item vfunc `+0x8c`; `FUN_00521eb0`.
5. **Callers (1):** `FUN_0085f660` @ `0x0085f6c1` — `MOV ECX,[DAT_00d1b6d8]`; `PUSH kit; PUSH item`; result `×100.0` for success-chance UI string.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `Character_ComputeTinkerSuccessChance_Inferred` (Ghidra `FUN_00521f20`). Product field English open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/formula sealed via `disassemble_function` + `read_memory` + caller disasm. Decompiler `extraout_DL` / param roles corrected in annotated notes.
9. **Retired scaffold:** `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00521f20`.

### Gaps

- Product English for `character+0x59b` / `+0x6b4` / item vfunc `+0x8c`.  
- Sibling dual `0x00521eb0` ECX labeling (item vs character) residual — this site passes **character**; not re-dualled.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00521f20_FUN_00521f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00521f20_FUN_00521f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_ComputeTinkerSuccessChance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00521f20.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00521f20.cpp` |
| Function | `docs/reconstruction/functions/aa_00521f20_FUN_00521f20.md` |
| Function named | `docs/reconstruction/functions/aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0085f660  tinker apply / confirm UI
  ├─ FUN_00513c10  Item_ValidateTinkerKitUse  → status 0..4
  └─ if status==4:
        FUN_00521f20  Character_ComputeTinkerSuccessChance_Inferred  [OWN R10-035]
          ├─ item vfunc +0x8c → open slots / need
          ├─ FUN_00521eb0  [parent dual 0x00521eb0]  // ECX=character this
          └─ float chance → ×100 → UI percent string
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00521f20-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00521f20` | Port as **character** thiscall success-chance **fraction** with stack **item** + **kit**. **`RET 8`**. Bases 0.4→0.2 by next-slot need; scale **0.04**; bypass `+0x6b4≥1` → 1.0. |
| Pair with | parent leaf `00521eb0`; validate `00513c10`; UI `0085f660` percent format. |
| Do not merge | validate status codes; item-this naming; treat return as percent without `×100`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- **not** touched by R10-035

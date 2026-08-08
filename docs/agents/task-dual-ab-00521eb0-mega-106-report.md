# Dual A/B report — MEGA-106 OWN-ONLY (`0x00521eb0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-106**  
**Scope:** VA `0x00521eb0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + caller disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual partition — inventory-transfer leaf under parent `0x00513c10` (Item_ValidateTinkerKitUse hint).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00521eb0` Item_GetTinkerSkillOrCap_Inferred | **accept-with-gaps** — CF/ABI/RET/field+0x59b/jump-table/2 callers/item-ECX sealed; product field English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): character-this / unbounded skill / stdcall / non-leaf / Named_CalleeOf product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00521eb0` — sealed facts

1. **Body:** `0x00521eb0`–`0x00521ef6` inclusive (**71 B** / `0x47`); NOP pad `0x00521ef7`; jump table data `0x00521ef8`–`0x00521f1b`.
2. **ABI:** **ECX** = item; no stack args; **EAX** = tier `uint8` 0..5; plain **`RET`**.
3. **Semantics:** map `item[+0x59b]`:
   - `0 → 0`
   - `1,2 → 1` … `7,8 → 4` · `9 → 5`
   - `≥10 → 5` (`SBB`/`AND 5`)
   - equiv. `v==0 ? 0 : min((v+1)/2, 5)`
4. **Callees:** none (leaf).
5. **Callers (2):** `FUN_00513c10` @ `0x00513ca4`; `FUN_00521f20` @ `0x00521f59` — both `MOV ECX,EDI` with EDI = **item**.
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `Item_GetTinkerSkillOrCap_Inferred` (Ghidra `FUN_00521eb0`). Partition hint `Character_*` corrected by call-site ECX. Product field English open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/table sealed via `disassemble_function` + `read_memory` + caller disasm.
9. **Retired scaffold:** `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0`.

### Gaps

- Product English for `item+0x59b`.  
- Character vfunc `+0x8c` product name.  
- Parent duals `00513c10` / `00521f20` residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00521eb0_FUN_00521eb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00521eb0_FUN_00521eb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_GetTinkerSkillOrCap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00521eb0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0.cpp` |
| Function | `docs/reconstruction/functions/aa_00521eb0_FUN_00521eb0.md` |
| Function named | `docs/reconstruction/functions/aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00513c10  Item_ValidateTinkerKitUse (partition hint)  [parent residual]
  ├─ character vfunc +0x8c → skill S
  ├─ FUN_00521eb0  Item_GetTinkerSkillOrCap_Inferred  [OWN MEGA-106]  // ECX=item
  └─ if tier < S+1 && item+0x6b4 < 1 → status 1

FUN_00521f20  tinker float helper  [residual]
  ├─ character vfunc +0x8c → skill S
  ├─ FUN_00521eb0  [OWN MEGA-106]
  └─ if tier >= S+1: float from raw item+0x59b + peer +0xb0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00521eb0-mega-106-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00521eb0` | Port as **item** `+0x59b` → tier **0..5** mapper. **thiscall**, no stack args, plain **RET**. Cap at 5. Do **not** treat ECX as character. |
| Pair with | residual validate `00513c10`; residual float helper `00521f20`; character skill via vfunc `+0x8c` in parents only. |
| Do not merge | character skill getters; raw `+0x59b` passthrough; Named_CalleeOf skill-string plates. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- **not** touched by MEGA-106

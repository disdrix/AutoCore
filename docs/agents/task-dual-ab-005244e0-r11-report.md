# Dual A/B report — R11-001 OWN-ONLY (`0x005244e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-001**  
**Scope:** VA `0x005244e0` (`aa_005244e0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-001**.  
**Work item:** Residual dual seal — inventory-transfer multi-row commodity TFID table cost sum (parent dual `0x00522710`).  
**Hint retired:** scaffold `FUN_005244e0` bare signature (no this / no ret 4).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005244e0` Character_SumCommodityTfidFiveRowCosts_Inferred | **accept-with-gaps** — thiscall RET4 / 5×row@+0x28 / head-null skip / sum+=rowCost sealed; product English + callers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mutate-inventory / pure-cdecl / ret8 / always-call / OR-null / wrong-stride / outer-index-weight / free-score-merge / single-row-merge / sum-starts-1 / runtime-confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005244e0` — sealed facts

1. **Body:** `0x005244e0`–`0x00524518` inclusive (**57 B** / `0x39`); terminal **`C2 04 00`**; pad `CC` before `FUN_00524520` @ `0x00524520`.
2. **ABI:** **`__thiscall`** — **ECX=Character***, stack **table***; **RET 0x4**; EAX = sum. **Not** pure cdecl / pure fastcall.
3. **Semantics:** multi-row commodity cost driver (no mutation):
   - sum=0; for i∈[0,4]: if head TFID non-null (`(lo&hi)!=-1`), `sum += FUN_00522710(i, row)`; stride **+0x28**.
   - Null-head rows contribute **0** (skip callee → avoid base-1).
4. **Callee (1):** dualed `Character_SumCommodityTfidRowCost_Inferred` `FUN_00522710` @ call site `0x005244fe` (rel sealed → `0x00522710`).
5. **Xrefs / callers:** **0** recovered (empty callers + empty `get_xrefs_to` / bulk). Gap.
6. **Family:** dualed row cost `00522710`; dualed free-score sibling `00522780` (one tier float) — **do not merge**.
7. **Name:** `Character_SumCommodityTfidFiveRowCosts_Inferred` (Ghidra `FUN_005244e0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; thiscall + RET 0x4 sealed via `disassemble_function` + `read_memory` (decompiler drops ECX/cleanup, not CF conflict).
9. **Partition parent** `0x00522710` is the **callee** (wave score parent), not a structural caller of this VA.

### Gaps

- Product / MSVC demangle English.  
- Live callers (xrefs empty — dead or indirect).  
- Whether outer 5 rows map to commodity tiers 1..5.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005244e0_Character_SumCommodityTfidFiveRowCosts_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005244e0_Character_SumCommodityTfidFiveRowCosts_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005244e0_FUN_005244e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005244e0_FUN_005244e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SumCommodityTfidFiveRowCosts_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005244e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005244e0_FUN_005244e0.md` |
| Function named | `docs/reconstruction/functions/aa_005244e0_Character_SumCommodityTfidFiveRowCosts_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005244e0  Character_SumCommodityTfidFiveRowCosts_Inferred  [OWN R11-001]
  └─ FUN_00522710  Character_SumCommodityTfidRowCost_Inferred  [dualed WQ-008]
        └─ FUN_00571010  InventoryGrid_FindItemByCoid  [dualed]
              (cargo grid *(*(ch+0x250)+0x2B0); Commodity type 0x1A; cost sub+0x4C8)

Sibling (not this unit):
FUN_00522780  Character_CalcCommodityTierFreeScore_Inferred  [dualed R10-036]
  └─ FUN_00522710  (used) + FUN_00520340 (max) → float free score for ONE tier row
```

Partition host "inventory-transfer" matches commodity cargo cost family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005244e0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005244e0` | Port as **5-row table cost sum** over dualed per-row commodity cost. Thiscall Character*, table*, **RET 4**. Null-head rows skip (contribute 0). |
| Distinct from | single-row cost `00522710`; free-score `00522780`. |
| Pair with | dualed row cost `00522710`; dualed FindByCoid `00571010`; free-score sibling `00522780`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `Character_SumCommodityTfidFiveRowCosts_Inferred` @ `0x005244e0` / `aa_005244e0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x005244e0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + callee context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 4; ECX this; sum starts 0).
- Odd behavior preserved: null-head skip avoids callee base-1; outer rowIndex pushed but dead in callee; AND null test.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

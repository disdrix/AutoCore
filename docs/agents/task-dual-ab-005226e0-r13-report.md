# Dual A/B report — R13-034 OWN-ONLY (`0x005226e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-034**  
**Scope:** VA `0x005226e0` (`aa_005226e0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-034**.  
**Work item:** Residual dual seal — inventory-transfer commodity **sum of tier max capacities** (partition parent dual `0x00520340`).  
**Hint retired:** scaffold `FUN_005226e0` / bare analyze `undefined FUN_005226e0(void)` / Named_CalleeOf plates.  
**Terminal:** **false** (no runtime Confirmed).  
**Dual start:** 2686 (wave).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005226e0` Character_SumCommodityTierMaxCapacities_Inferred | **accept-with-gaps** — thiscall RET / loop tiers 1..5 / Σ max leaf sealed; zero static callers + product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mutate-inventory / pure-cdecl / ret4-on-wrapper / 0..5-merge / free-score-merge / row-cost-merge / five-row-merge / float-product / invented-callers / runtime-confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005226e0` — sealed facts

1. **Body:** `0x005226e0`–`0x00522709` inclusive (**42 B** / `0x2A`); epilog **`C3` RET**; `CC` pad after.
2. **ABI:** **`__thiscall`** — **ECX=Character\*** (`MOV EBX,ECX`); **no stack args** for this unit; **RET** (not ret 4/8). Callee `FUN_00520340` cleans its own tier dword (`ret 4`).
3. **Semantics:** total max commodity capacity across tiers:
   - `sum = 0`
   - for `tier = 1..5`: `sum += Character_CalcCommodityTierMaxCapacity_Inferred(this, tier)`
   - return `sum`
4. **Callee (1):** dualed parent `FUN_00520340` @ site `0x005226f6` (rel `E8 45 DC FF FF` → `0x00520340`).
5. **Xrefs / callers (0):** Ghidra `xref_count=0`; `get_xrefs_to` / `get_function_callers` empty; no data pointer `E0 26 52 00`.
6. **Family:** sibling `FUN_005204f0` sums tiers **0..5** (tier0→0) — **do not merge**. Free-score / row-cost / five-row used sums are distinct.
7. **Name:** `Character_SumCommodityTierMaxCapacities_Inferred` (Ghidra `FUN_005226e0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; thiscall sealed via `disassemble_function` + `read_memory` (decompiler drops this).
9. **Partition parent** `0x00520340` is the structural max-capacity leaf (and sole callee).

### Gaps

- Product / MSVC demangle English.  
- Zero recovered static callers (dead vs indirect open).  
- Dual seal for sibling `FUN_005204f0` (owned elsewhere).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005226e0_FUN_005226e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005226e0_FUN_005226e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SumCommodityTierMaxCapacities_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005226e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005226e0_FUN_005226e0.md` |
| Function named | `docs/reconstruction/functions/aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005226e0  Character_SumCommodityTierMaxCapacities_Inferred  [OWN R13-034]
  └─ FUN_00520340  Character_CalcCommodityTierMaxCapacity_Inferred  [dualed R12-018]
        └─ CRT floor (IAT) only

Sibling (not this VA):
FUN_005204f0  Σ max tiers 0..5 (tier0→0)  [R13-033 partition]

Related family:
FUN_00522780  Character_CalcCommodityTierFreeScore_Inferred  [dualed R10-036]
  └─ uses single-tier max, not this five-tier sum
```

Partition host "inventory-transfer" matches commodity capacity family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005226e0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005226e0` | Port as **Σ max capacity** over tiers 1..5. Thiscall Character*, **RET**, no stack args. |
| Formula | `sum_t=1..5 floor(level × scale[t])` via leaf; do not reimplement scales here. |
| Distinct from | sibling `005204f0` (0..5); free-score `00522780`; row-cost `00522710`; five-row used `005244e0`. |
| Pair with | dualed max leaf `00520340`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers / `systems/inventory-transfer.md` — **not touched** by this agent.
- Name to register: `Character_SumCommodityTierMaxCapacities_Inferred` @ `0x005226e0` / `aa_005226e0`.
- Count **+1** dual unique when parent merges R13-034.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_complete + disassemble_function + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Name uses inventory-domain + `_Inferred` (never Runtime Confirmed).  
- Terminal false.

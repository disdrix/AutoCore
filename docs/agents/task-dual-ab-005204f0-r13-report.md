# Dual A/B report — R13-033 OWN-ONLY (`0x005204f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-033**  
**Scope:** VA `0x005204f0` (`aa_005204f0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `search_byte_patterns` + `get_function_by_address` + `get_function_signature` + `get_function_hash`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-033**.  
**Work item:** Residual dual seal — inventory-transfer commodity tier **max capacity sum** wrapper (partition parent dual `0x00520340`).  
**Hint retired:** scaffold bare `FUN_005204f0` / decompiler `void`/no-this surface.  
**Terminal:** **false** (no runtime Confirmed).  
**Dual start:** 2686 (wave).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005204f0` Character_SumCommodityTierMaxCapacities_Inferred | **accept-with-gaps** — thiscall RET0 / loop tiers 0..5 / Σ parent max / tier0→0 sealed; product English + callers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mutate-inventory / pure-cdecl / ret4 / loop-1..5-only-as-this-VA / free-score-merge / five-row-merge / single-tier-merge / sibling-merge / runtime-confirmed / proven-live-callers claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005204f0` — sealed facts

1. **Body:** `0x005204f0`–`0x00520517` inclusive (**40 B** / `0x28`); exit **`C3`** (`RET`); padding `CC` from `0x00520518`.
2. **ABI:** **`__thiscall`** — **ECX=Character\*** (`MOV EBX,ECX`); **no stack args** on entry; **RET 0**. **Not** pure cdecl / pure fastcall / parent-style `ret 4`.
3. **Semantics:** sum of dualed per-tier max capacities (no mutation):
   - `sum = 0; for (tier = 0; tier < 6; ++tier) sum += FUN_00520340(this, tier); return sum;`
   - Parent returns **0** for tier ∉ {1..5} → tier **0 is dead zero**; effective Σ = tiers **1..5**.
4. **Callees:** `FUN_00520340` only (call site `0x00520503`; rel32 seals target).
5. **Xrefs / callers (0):** no static CALL/data xrefs; LE pointer pattern `F0 04 52 00` — no matches. **Orphan** residual.
6. **Family:** partition parent is the **max leaf**; free-score `00522780` uses parent per-tier; five-row `005244e0` is **used**-cost sum — **do not merge**. Sibling `005226e0` is Σ max over **1..5** only (same effective total, different CF).
7. **Name:** `Character_SumCommodityTierMaxCapacities_Inferred` (Ghidra `FUN_005204f0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; thiscall + RET 0 sealed via `disassemble_function` + `read_memory` (decompiler omits this).
9. **Partition parent** `0x00520340` is the structural **callee** (max capacity leaf dualed R12-018).

### Gaps

- Product / MSVC demangle English.  
- No recovered static callers (dead vs dynamic).  
- Dual of sibling sum `005226e0` / UI hosts open.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005204f0_Character_SumCommodityTierMaxCapacities_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005204f0_Character_SumCommodityTierMaxCapacities_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005204f0_FUN_005204f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005204f0_FUN_005204f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SumCommodityTierMaxCapacities_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005204f0.cpp` |
| Function | `docs/reconstruction/functions/aa_005204f0_FUN_005204f0.md` |
| Function named | `docs/reconstruction/functions/aa_005204f0_Character_SumCommodityTierMaxCapacities_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005204f0  Character_SumCommodityTierMaxCapacities_Inferred  [OWN R13-033]
  └─ FUN_00520340  Character_CalcCommodityTierMaxCapacity_Inferred  [dualed R12-018]
       └─ CRT floor (IAT) only
       └─ level@+0x599 × scale[tier] → floor int max

Sibling (not owned):
FUN_005226e0  Σ max tiers 1..5 only  [R13-034 residual]

Consumers of parent (not of this VA):
FUN_00522780  free-score  [dualed]
FUN_008e41b0  UI "Complexity: %i/%i" max denominator
```

Partition host "inventory-transfer" matches commodity capacity / free-score family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005204f0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005204f0` | Port as **Σ tier max capacity** over loop **0..5**. Thiscall Character*, **no stack args**, **RET 0**. |
| Effective | Same total as looping 1..5 (tier 0 always 0 via parent). Prefer explicit 0..5 to match bytes. |
| Distinct from | parent leaf `00520340`; sibling 1..5 sum `005226e0`; free-score `00522780`; five-row used `005244e0`. |
| Pair with | dualed parent max `00520340`; optional sibling `005226e0` when both dualed. |
| Liveness | No static callers — do not assume hot path without new evidence. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `Character_SumCommodityTierMaxCapacities_Inferred` @ `0x005204f0` / `aa_005204f0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x005204f0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function (+ signature/hash/byte-pattern). **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 0; ECX this; loop 0..5).
- Odd behavior preserved: dead tier-0 call; orphan (no static callers); sibling 1..5 sum not merged.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

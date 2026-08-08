# Dual A/B report — R10-036 OWN `aa_00522780`

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R10-036  
**Scope:** VA `0x00522780` only. Dual A/B + trio artifacts.  
**Role hint:** inventory-transfer residual — commodity tier free-capacity float score (parent cost leaf `0x00522710`).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` (R10-036).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00522780` Character_CalcCommodityTierFreeScore_Inferred | **accept-with-gaps** — thiscall+ret8, used/max/free, tier base/scale table, score formula sealed; product English open |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## Shared context (parent, not owned)

| Link | Notes |
|------|-------|
| Parent dual | `0x00522710` `Character_SumCommodityTfidRowCost_Inferred` — commodity TFID row **used** cost |
| Max helper | `FUN_00520340` — level `@this+0x599` × tier scale → floor max |
| Sole caller | `FUN_00522860` — product of per-tier free scores (5 rows × 40 B stride) |
| Domain | inventory-transfer commodity / TFID row scoring |

---

## VA `0x00522780` — sealed facts

1. **Body:** `0x00522780`–`0x0052283d` exclusive (**189 B** / `0xBD`). Jump table `@0x00522840` (5 entries).
2. **ABI:** **`__thiscall`** ECX = Character*; **two stack dwords** (tier, tfidRow*); **`ret 8`** on both exits.
3. **Semantics:** free-capacity **float score**:
   - `used = Character_SumCommodityTfidRowCost(this, tier, row)`.
   - `max = FUN_00520340(this, tier)`.
   - `free = max - used`; if `free < 0` or `tier ∉ {1..5}` → `0.0f`.
   - `level = *(uint8_t*)(this + 0x599)`.
   - `return (level * scale[tier] + (base[tier] + free * 2)) * 0.01f`.
4. **Tier table (imm + `read_memory`):**

   | Tier | base | scale | scale VA |
   |----:|-----:|------:|---|
   | 1 | 50 | 2.5 | `0x00aaa6c4` |
   | 2 | 40 | 2.0 | `0x00a10e74` |
   | 3 | 30 | 1.5 | `0x00aaa68c` |
   | 4 | 20 | 1.0 | `0x00a0f2a0` |
   | 5 | 10 | 0.5 | `0x00a0f298` |

   Final multiply `DAT_00a0f718` ≈ **0.01** (`0x3c23d70a`). Zero via `g_flZero` @ `0x00a0f518`.

5. **Classification:** pure read score worker (no grid mutation).
6. **Callers (1):** `FUN_00522860` @ site `0x005228c0`.
7. **Callees:** `FUN_00522710`, `FUN_00520340`.
8. **Name:** `Character_CalcCommodityTierFreeScore_Inferred` (Ghidra `FUN_00522780`). **Reject** scaffold `Named_CalleeOf_…_00522780`.
9. **Decompile vs bytes:** CF ≡ raw used/max/switch/score; **bytes win** on `ret 8`, jump-table bounds, and FPU order (`fild` level → `fmul` scale → `fiadd` base+2×free → `fmul` 0.01).

### Gaps

- Product/PDB method English.  
- Product meaning of composite score (UI weight vs craft fitness).  
- Dual seals for `FUN_00520340` / `FUN_00522860`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00522780_FUN_00522780.md` |
| Annotated | `docs/reconstruction/raw/aa_00522780_FUN_00522780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_CalcCommodityTierFreeScore_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522780.cpp` |
| Function | `docs/reconstruction/functions/aa_00522780_FUN_00522780.md` |
| Function named | `docs/reconstruction/functions/aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00522780-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00522780` | Port as **thiscall** float score: `used` from commodity TFID row cost; `max` from level-scaled tier helper; `free=max-used`; score `(level*scale + base + 2*free)*0.01` with fixed tier tables. Early-out 0 on negative free / bad tier. |
| Pairing | Keep with parent `Character_SumCommodityTfidRowCost_Inferred` and max helper `FUN_00520340` when porting free-slot scoring / product fitness (`FUN_00522860`). |

---

## Residual for parent merge (not edited here)

- Count **+1** dual unique when parent merges R10-036 (`00522780`).
- NAMING_REGISTRY: `Character_CalcCommodityTierFreeScore_Inferred`.
- Optional follow-up: dual `FUN_00520340` / `FUN_00522860` capacity-score neighbors.
- VERIFICATION_MATRIX row + `systems/inventory-transfer.md` entry point.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ analyze/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Name uses inventory-domain + `_Inferred` (no invented product plates).  
- Terminal false.

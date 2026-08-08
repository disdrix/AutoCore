# Dual A/B report — R12-018 OWN-ONLY (`0x00520340`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-018**  
**Scope:** VA `0x00520340` (`aa_00520340`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-018**.  
**Work item:** Residual dual seal — inventory-transfer commodity tier **max capacity** leaf (partition parent dual `0x005244e0`).  
**Hint retired:** scaffold `FUN_00520340` / `Named_CalleeOf_*` plates; bare analyze signature.  
**Terminal:** **false** (no runtime Confirmed).  
**Dual start:** 2646 (wave).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00520340` Character_CalcCommodityTierMaxCapacity_Inferred | **accept-with-gaps** — thiscall RET4 / level@+0x599 / tier1..5 scales 3.5→0.7 / floor+chop / default0 sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mutate-inventory / pure-cdecl / ret0 / banker's-ROUND / ceil / tier0-nonzero / wrong-scales / free-score-merge / row-cost-merge / five-row-merge / runtime-confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00520340` — sealed facts

1. **Body:** `0x00520340`–`0x005204cd` inclusive (**398 B** / `0x18E`); all exits **`C2 04 00`**; align `8B FF` @ `0x005204ce`; jump table @ `0x005204d0` (5× case VA).
2. **ABI:** **`__thiscall`** — **ECX=Character\***; stack **tier**; **RET 0x4**; EAX = max capacity. **Not** pure cdecl / pure fastcall.
3. **Semantics:** level-scaled max commodity capacity (no mutation):
   - `level = *(uint8_t*)(this + 0x599)`
   - tier ∈ {1..5}: `(int)floor(level * scale[tier])`; else **0**
   - scales (sealed floats): **3.5 / 2.8 / 2.1 / 1.4 / 0.7** (= `0.7 × (6 − tier)`)
4. **Floor path:** CRT `floor` IAT `[0x009c6598]` then FISTP with RC=chop (`OR AH,0xC`). Decompiler ROUND is chop convert.
5. **Callees:** CRT `floor` only (no inventory FUN_*).
6. **Xrefs / callers (5):** `FUN_005204f0`, `FUN_005226e0`, dualed free-score `FUN_00522780`, UI `FUN_008e41b0` (Complexity max), `FUN_008e55e0`.
7. **Family:** free-score `00522780` uses this as **max**; row-cost `00522710` is **used**; five-row sum `005244e0` is multi-row used driver — **do not merge**.
8. **Name:** `Character_CalcCommodityTierMaxCapacity_Inferred` (Ghidra `FUN_00520340`). Product demangle open → `_Inferred`. UI string "Complexity" is display label only.
9. **Decompile ≡ raw CF**; thiscall + RET 0x4 + scales sealed via `disassemble_function` + `read_memory`.
10. **Partition parent** `0x005244e0` is the wave host (five-row cost sum), **not** a structural caller of this VA.

### Gaps

- Product / MSVC demangle English.  
- Product proof that +0x599 is "character level" (family consensus only).  
- Dual seals for sum wrappers / UI hosts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00520340_Character_CalcCommodityTierMaxCapacity_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00520340_Character_CalcCommodityTierMaxCapacity_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00520340_FUN_00520340.md` |
| Annotated | `docs/reconstruction/raw/aa_00520340_FUN_00520340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_CalcCommodityTierMaxCapacity_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00520340.cpp` |
| Function | `docs/reconstruction/functions/aa_00520340_FUN_00520340.md` |
| Function named | `docs/reconstruction/functions/aa_00520340_Character_CalcCommodityTierMaxCapacity_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00520340  Character_CalcCommodityTierMaxCapacity_Inferred  [OWN R12-018]
  └─ CRT floor (IAT) only

Consumers:
FUN_00522780  Character_CalcCommodityTierFreeScore_Inferred  [dualed R10-036]
  └─ used = FUN_00522710; max = FUN_00520340; free = max − used → float score

FUN_005244e0  Character_SumCommodityTfidFiveRowCosts_Inferred  [dualed R11-001; partition parent]
  └─ multi-row used-cost sum (does NOT call this VA)

UI:
FUN_008e41b0  … formats "Complexity: %i/%i" with this as max denominator
```

Partition host "inventory-transfer" matches commodity capacity / free-score family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00520340-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00520340` | Port as **tier max capacity** = floor(level × scale[tier]). Thiscall Character*, tier, **RET 4**. Tier∉1..5 → 0. |
| Scales | 3.5 / 2.8 / 2.1 / 1.4 / 0.7 for tiers 1..5. |
| Distinct from | free-score `00522780`; row-cost `00522710`; five-row sum `005244e0`. |
| Pair with | dualed free-score `00522780`; dualed row cost `00522710`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `Character_CalcCommodityTierMaxCapacity_Inferred` @ `0x00520340` / `aa_00520340`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00520340`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 4; ECX this; floor+chop not ROUND).
- Odd behavior preserved: tier 0 / out-of-range → 0; scales decrease with tier; UI Complexity label not promoted to method English.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

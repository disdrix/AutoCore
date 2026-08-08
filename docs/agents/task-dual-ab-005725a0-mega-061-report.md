# Dual A/B report — MEGA-061 OWN-ONLY (`0x005725a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-061**  
**Scope:** VA `0x005725a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer complete dtor under dualed scalar `0x00573910`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` (MEGA-061).  
**Partition hint:** `InventoryGrid_CompleteDtor` (confirmed).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005725a0` InventoryGrid_CompleteDtor | **accept** — CF/ABI/174 B body/vtbl/layout reverse-of-ctor/sole scalar caller sealed; product demangle naming-only |

Path A (fidelity): **accept**.  
Path B (adversarial): scalar-merge / free-host / FreeCellArray-only / Ghidra-end-bound / RET4 / cdecl claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005725a0` — sealed facts

1. **Body:** `0x005725a0`–`0x0057264d` inclusive (**174 B** / `0xAE`); pad `CC CC` before ctor `0x00572650`.  
   Ghidra `get_function_by_address` end `0057260b` is **wrong** (false-noreturn on `operator_delete`).
2. **ABI:** **ECX** = `InventoryGrid*`; no stack formals; void; bare **`RET`** (`C3`).
3. **Semantics:** MSVC **complete-object destructor** for InventoryGrid (`PTR_FUN_009d3390`, size **0x68**):
   - Reinstall vtbl `PTR_FUN_009d3390`.
   - `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` (`0x00570f70`).
   - `operator_delete[]` cell array @ `+0x28` (null-safe); zero.
   - Map @ `+0x5c`: `FUN_00573700` erase-all; `operator_delete` sentinel @ `+0x60`; zero head/size.
   - List @ `+0x2c`: vtbl `009d3384` → `FUN_004bc950`; vtbl `009cb334` → `FUN_004bc950`.
   - `DeleteCriticalSection` @ `+0x30` (IAT `[0x009c61f0]`).
   - Does **not** free host (scalar path does).
4. **Caller (1):** dualed `InventoryGrid_ScalarDeletingDtor` `0x00573910` @ `0x00573913` (UNCONDITIONAL_CALL).
5. **Xrefs:** 1 code CALL.
6. **Callees:** `00570f70`, `operator_delete[]` `0048981c`, `00573700`, `operator_delete` `00489822`, `004bc950`×2, DeleteCS.
7. **Name:** `InventoryGrid_CompleteDtor` (Ghidra `FUN_005725a0`). Partition hint confirmed; scaffolds retired.
8. **Decompile ≡ raw through truncated tail**; **full CF ≡ bytes** via `read_memory` + `disassemble_function`.

Full body hex (174 B):

```
6aff68424f9a0064a100000000506489250000000083ec085356578bf9897c240cc70790339d00c744241c01000000e89ce9ffff8b472833db3bc3740950e83972f1ff83c404895f288b47608b088d775c50518d442418508bce885c2428e8fd1000008b4e0451e81672f1ff895e04895e088d772c83c4048bcec70684339d00e82ba3f4ff8bcec70634b39c00e81ea3f4ff83c60456ff15f0619c008b4c24145f5e5b64890d0000000083c414c3
```

### Gaps

- Product/MSVC demangle string (naming-only; family sealed).  
- Tree key English / dual of erase helper `00573700`.  
- Full dual of list helper `004bc950`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005725a0_InventoryGrid_CompleteDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005725a0_InventoryGrid_CompleteDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005725a0_FUN_005725a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005725a0_FUN_005725a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005725a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005725a0_FUN_005725a0.md` |
| Function named | `docs/reconstruction/functions/aa_005725a0_InventoryGrid_CompleteDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
InventoryGrid_ScalarDeletingDtor  0x00573910  [dualed WQ8R-E accept]  vtbl[0]
  └─ InventoryGrid_CompleteDtor   0x005725a0  [OWN MEGA-061]
        ├─ ClearItemsAndReEmptyCells  0x00570f70  [dualed MEGA-090]
        │     ├─ List_TraversalLock / IterateNext / RemoveAll
        │     └─ AllocateCellArray    0x00570720  [dualed]
        ├─ operator_delete[] cells @ +0x28
        ├─ FUN_00573700 map erase @ +0x5c  [residual]
        ├─ operator_delete sentinel @ +0x60
        ├─ FUN_004bc950 list drain ×2      [residual]
        └─ DeleteCriticalSection @ +0x30

InventoryGrid_ctor_Inferred  0x00572650  [related; reverse order]
  installs PTR_FUN_009d3390; InitCS; tree sentinel; Allocate
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005725a0-mega-061-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005725a0` | Port as **InventoryGrid complete dtor** only: clear items → `delete[]` cells → destroy map → destroy list → `DeleteCriticalSection`. **ECX=this**, bare **RET**. **Do not** free host here. **Do not** stop at Ghidra's truncated decompile (must include list + CS tail). |
| Pair with | dualed scalar `00573910` (vtbl[0]: complete then optional delete); dualed clear `00570f70`; ctor `00572650`; residual map erase `00573700`; residual list drain `004bc950`. |
| Layout | Object **0x68**; cells `+0x28`; list `+0x2c`; CS `+0x30`; map `+0x5c`/`+0x60`/`+0x64`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep later for this VA only:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY` / system maps as applicable  
- No parent ledger edits by this agent.

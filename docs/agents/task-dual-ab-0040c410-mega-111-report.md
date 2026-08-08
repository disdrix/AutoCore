# Dual A/B report — MEGA-111 OWN-ONLY (`0x0040c410`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-111**  
**Scope:** VA `0x0040c410` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including sort `0x0048a060` / MEGA-116, sort core `0x00489f20` / MEGA-115, dtor `0x0040c510`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `disassemble_function` + `get_function_by_address` + `get_function_signature` + parent hub call-site context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-111**.  
**Work item:** residual dual seal — **soft-cast hit-list ctor / buffer init** under dualed `Client_InteractWorldClickHub` (`0x00925820`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040c410` SoftCastHitList_CtorInitBuffer_Inferred | **accept-with-gaps** — CF/ABI/RET4/vtbl pair/inline cap-8 header/8×0x30 seeds/sole hub caller sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / heap-alloc ctor / fill-or-sort-in-body / multi-caller / skill-list / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040c410` — sealed facts

1. **Body:** `0x0040c410`–`0x0040c4df` inclusive (**208 B** / `0xD0`); Ghidra range end `0x0040c4e0`; `RET 4` @ `0x0040c4de`.
2. **ABI:** **stdcall** — stack `SoftCastHitList* self` (`MOV EAX,[ESP+0x14]` after SEH); void; **`RET 4`**. **Not** ECX-thiscall.
3. **Semantics:** leaf ctor / buffer init:
   - SEH (`LAB_009bd03d` / FS:[0]); states 0→1→2→`−1`.
   - Temp vtbl `PTR_LAB_00a2f52c` then final `PTR_LAB_00a2f538`.
   - `+0x04 = g_flOne` (`0x00a0f2a0` = `1.0f`).
   - Header: `+0x10 = self+0x20`, `+0x14 count = 0`, `+0x18 = 0x80000008` (cap 8 \| inline high-bit).
   - Seed 8 elements × **0x30**: float `@+0x14 = 1.0f`, dword `@+0x20 = 0`.
   - Reassert count / `+0x04`; no callees.
4. **Layout cross-check:** dtor `FUN_0040c510` frees `(cap&0x7fffffff)*0x30` only if signed cap ≥ 0 (high-bit = skip free). Sort sibling MEGA-116 reads `+0x10`/`+0x14`.
5. **Callees:** none (leaf).
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL — `Client_InteractWorldClickHub` / `FUN_00925820` @ `0x00925c06` (`LEA` stack obj + `PUSH` + `CALL`).
7. **Name:** `SoftCastHitList_CtorInitBuffer_Inferred` (Ghidra `FUN_0040c410`). Product class open → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire.
8. **Decompile ≡ raw scaffold CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site + dtor/sort siblings.

### Gaps

- Product English for hit-list class and float fields (container `+0x04` / key `+0x14`).  
- Full final-vtbl method map (slot0 grow @ `0x00489eb0` pattern; slot1 scalar dtor `0x0040c4f0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040c410_FUN_0040c410.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c410_FUN_0040c410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_CtorInitBuffer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040c410.cpp` |
| Function | `docs/reconstruction/functions/aa_0040c410_FUN_0040c410.md` |
| Function named | `docs/reconstruction/functions/aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ FUN_0040c410     SoftCastHitList_CtorInitBuffer_Inferred  [OWN MEGA-111]
  ├─ FUN_0055e1e0     soft-cast fill wrapper
  │    └─ FUN_006ca890  hit-list core
  ├─ FUN_0048a060     SoftCastHitList_SortIfCountGt1_Inferred  [MEGA-116]
  │    └─ FUN_00489f20  qsort 0x30 / float key +0x14  [MEGA-115 OWN]
  ├─ walk hits
  │    └─ FUN_0040afb0  resolve object* from hit+0x20
  └─ FUN_0040c510     SoftCastHitList dtor
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040c410-mega-111-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040c410` | Port as **soft-cast hit-list ctor / buffer init**. **stdcall stack-self, RET 4** (not thiscall). Inline 8×`0x30` hits; capacity high-bit means **do not free** in dtor. Seed keys to `1.0f`, object slots to null, count 0. |
| Pair with | dualed hub `00925820`; dualed sort `0048a060`; residual sort core `00489f20`; residual dtor `0040c510`; fill `0055e1e0`/`006ca890`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming registry / system map as applicable  
- **not** touched by this agent

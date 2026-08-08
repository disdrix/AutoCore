# Dual A/B report — MEGA-052 OWN-ONLY (`0x004023f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-052**  
**Scope:** VA `0x004023f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — callee of **CVOGReaction_Dispatch** (parent-seed); unit is shared MSVC empty-list default ctor.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` row MEGA-052.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004023f0` StdList_DefaultCtor_Inferred | **accept-with-gaps** — CF/ABI/RET/head@+4/size@+8/callee pair sealed; `list+0` + element-`T` residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): reaction-only / insert-copy / wrong-offset / RET4 / vector-ctor-itself claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004023f0` — sealed facts

1. **Body:** `0x004023f0`–`0x00402405` inclusive (**22 B** / `0x16`); pad `CC` after.
2. **ABI:** **ECX** = list object*; no stack args; **EAX** = this; plain **`RET`** (`C3`).
3. **Semantics:** empty `std::list` default ctor:
   - `CALL FUN_0040fb90` → dualed **StdList_AllocEmptySentinel_Inferred** (`operator_new(0xc)`, next=prev=self).
   - `this+4 = EAX` (`_Myhead`).
   - `this+8 = 0` (`_Mysize`).
   - return `this`.
4. **Object size:** **0xC** (vector-ctor element stride at DATA sites).
5. **Callees:** `FUN_0040fb90` only.
6. **Callers:** **5** UNCONDITIONAL_CALL + **2** DATA:
   - CALL: `CVOGReaction_Dispatch` @ `0057c9c7`; `CVOGVariable_EvaluateComputed` @ `005afe6c`; `FUN_0089bc30` @ `0089bc97`; `FUN_008edc80` @ `008edd63`; `FUN_008a8770` @ `008a8b98`.
   - DATA: `FUN_004e80c0` @ `004e8109`; `FUN_008a5c90` @ `008a5d0a` (`_eh_vector_constructor_iterator_` element ctor, dtor `00403430`).
7. **Pair:** dualed destroy **StdList_Destroy_FreeHead_Inferred** `0x00403430`; clear `0x00404060`; copy sibling `0x00402410`.
8. **Name:** `StdList_DefaultCtor_Inferred` (Ghidra `FUN_004023f0`). Product map open → `_Inferred`.
9. **Retired:** `Named_CalleeOf_CVOGReaction_Dispatch_004023f0` (parent-seed scaffold only).
10. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Unwritten `list+0` (allocator / `_Container_base`).  
- Element type `T` of consuming lists (site-specific).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004023f0_StdList_DefaultCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004023f0_StdList_DefaultCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004023f0_FUN_004023f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004023f0_FUN_004023f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_DefaultCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004023f0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGReaction_Dispatch_004023f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004023f0_FUN_004023f0.md` |
| Function named | `docs/reconstruction/functions/aa_004023f0_StdList_DefaultCtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGReaction_Dispatch  [0x0057c500]  parent seed (partition)
  └─ FUN_004023f0  StdList_DefaultCtor_Inferred  [OWN MEGA-052]
       └─ FUN_0040fb90  StdList_AllocEmptySentinel_Inferred  [dualed]

CVOGVariable_EvaluateComputed  [0x005afd40]
  └─ FUN_004023f0  (stack list for type-1 path)
       … later FUN_00403430 destroy

FUN_004e80c0 / FUN_008a5c90
  └─ _eh_vector_constructor_iterator_(array, 0xC, N, FUN_004023f0, FUN_00403430)

Paired teardown:
  FUN_00403430  StdList_Destroy_FreeHead_Inferred  [dualed]
    └─ FUN_00404060 clear; operator_delete(head@+4)

Sibling:
  FUN_00402410  empty-init then range-insert copy  [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004023f0-mega-052-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004023f0` | Port as **empty `std::list` default ctor**. **ECX=this**, **EAX=this**, plain **RET**. Head@**+4**, size@**+8**=0, object **0xC**. Pair with sentinel alloc `0040fb90` and destroy `00403430`. |
| Do **not** | Treat as reaction/mission domain helper; invent insert/copy; place head at +0. |
| Pair with | dualed `StdList_AllocEmptySentinel_Inferred` `0040fb90`; dualed `StdList_Destroy_FreeHead_Inferred` `00403430`; residual copy `00402410`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.

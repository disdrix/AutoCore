# Dual A/B report — WQ9I-D OWN-ONLY (`0x0040a6e0`, `0x007fe640`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9I-D**  
**Scope:** VAs `0x0040a6e0`, `0x007fe640` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-D**.  
**Work item:** WQ-009 depth-6 residual dual seal (POD placement **0x138** + CNDHash Recreate caller **BL=2**).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040a6e0` PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred | **accept-with-gaps** — null gate / cdecl / leaf 0x138 / parent stride sealed; product POD fields open |
| `aa_007fe640` Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred | **accept-with-gaps** — traverse/teardown/unlock/recreate CF + EAX/BL=2 sealed; host English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): always-construct, thiscall-on-placement, RET4 formals, skill-recreate merge, hard lock abort, VOG scaffold identity, and decompiler-no-formals-on-Recreate all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040a6e0` — sealed facts

1. **Body:** `0x0040a6e0`–`0x0040a729` exclusive (**74 B** / `0x4A`); pad `CC`.
2. **ABI:** **cdecl** formals; **Stack[0x4]=dest\***, **Stack[0x8]=src\***; void; bare **`ret`** (`C3` after `ADD ESP,0x10` SEH teardown). Parent trampoline cleans 8.
3. **Semantics:** MSVC-style **null-checked placement copy-construct** of **0x138** POD:
   - SEH (`LAB_009bdcb1`).
   - If dest ≠ 0: thiscall `PodCopyConstruct_Elem0x138_Inferred` (`0x00408880`, dualed WQ9H-I).
   - Else: no-op.
4. **Stride / width:** **0x138** (via dualed leaf + ConstructN/uninit-copy parents).
5. **Classification:** worker.
6. **Xrefs (1 UNCONDITIONAL_CALL):** `FUN_00409f10` @ `0x00409f1a` (stdcall RET8 trampoline). Upstream: `FUN_00409cc0`, `FUN_0040a4a0`.
7. **Callees:** `FUN_00408880` only.
8. **Name:** `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` (Ghidra `FUN_0040a6e0`). Reject SendLogicUi scaffold plate.
9. **Decompile ≡ raw CF**; thiscall ECX handoff into leaf sealed via **bytes** + dualed leaf ABI.

### Gaps

- Product / English field map for 0x138 Logic-UI event POD.  
- Dual of trampoline `00409f10` / parents `00409cc0` / `0040a4a0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040a6e0_FUN_0040a6e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040a6e0_FUN_0040a6e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040a6e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040a6e0_FUN_0040a6e0.md` |
| Function named | `docs/reconstruction/functions/aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` |

---

## VA `0x007fe640` — sealed facts

1. **Body:** `0x007fe640`–`0x007fe710` exclusive (**209 B** / `0xD1`); pad `CC`.
2. **ABI:** **stdcall**; **Stack[0x4]=owner\***; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** host **CNDHash** at **`owner+0x3084`**:
   - Null hash → return.
   - Soft TraversalLock assert @ `hash+0x1d`; force lock = 1.
   - Ordered walk: head `hash+0x14`, next `node+0x20`, payload `node+0xc`.
   - Per object: `vtbl+0x3d8` → maybe `vtbl+0x440`; if `obj+0x2b0`: secondary `vtbl+0xb0(obj)`.
   - Unlock `@+0x1d`; **`CNDHash_Recreate_00a2c2e4`** with **EAX=hash**, **BL=2**.
4. **Classification:** worker.
5. **Xrefs (2 UNCONDITIONAL_CALL):** `FUN_00934880` @ `0x009348bc`; `FUN_009349b0` @ `0x009349d4`.
6. **Callees:** `FUN_007a4480` (hash error log); `FUN_004195d0` / `CNDHash_Recreate_00a2c2e4` (dualed WQ9H-E).
7. **Name:** `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` (Ghidra `FUN_007fe640`). Reject `Named_VOG_DEBUG_STOP_007fe640`.
8. **Decompile ≡ raw CF**; recreate EAX/BL handoff **not** in decompiler formals — sealed via **bytes**.

### Gaps

- Product / PDB English for host class owning `+0x3084`.  
- Exact English for vtbl methods `+0x3d8` / `+0x440` / secondary `+0xb0`.  
- Dual of callers `00934880` / `009349b0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007fe640_FUN_007fe640.md` |
| Annotated | `docs/reconstruction/raw/aa_007fe640_FUN_007fe640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fe640.cpp` |
| Function | `docs/reconstruction/functions/aa_007fe640_FUN_007fe640.md` |
| Function named | `docs/reconstruction/functions/aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred (0x0040a6e0)  [OWN WQ9I-D]
  └─ PodCopyConstruct_Elem0x138_Inferred (0x00408880)                [dualed WQ9H-I]
  ▲
  FUN_00409f10 trampoline (RET 8)
    ▲
    ├─ FUN_00409cc0 ConstructN-style fill  stride 0x138
    └─ FUN_0040a4a0 uninit-copy range      stride 0x138
  (LogicUiEventQueue_InsertN calls 00408880 directly — not via placement)

Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred (0x007fe640) [OWN WQ9I-D]
  └─ CNDHash_Recreate_00a2c2e4 (0x004195d0)  EAX/BL=2              [dualed WQ9H-E]
        ├─ DestroyBucketTable_00a2c2e4 (0x00406fc0)
        └─ AllocBucketTable_00a2c2e4 (0x00406f20)
  ▲
  ├─ FUN_00934880 host rebuild path
  └─ FUN_009349b0 host teardown path (+0xf40)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040a6e0-007fe640-wq9id-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040a6e0` | Port as **shared null-checked placement construct** for **elem stride 0x138**. cdecl dest/src; bare ret. Leaf = thiscall POD copy `00408880`. Not UI domain logic. |
| `007fe640` | Port as **host hash clear path**: traverse ordered CNDHash @ **+0x3084**, teardown objects via vtbl, unlock, recreate with **log2=2**. stdcall owner / RET 4. Do **not** type-merge with skill recreate `004cbdc0`. |
| Pair with | leaf `00408880`; recreate `004195d0` + stamp helpers `00406f20`/`00406fc0`; host ctor field store +0x3084. |
| Naming caution | **Not** VOG_DEBUG_STOP identity. **Not** skill thiscall recreate. **Not** merge placement with direct InsertN leaf call. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (util/container + host CNDHash — not skill domain merge)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0040a6e0`, `0x007fe640`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decompiler hides thiscall ECX into `00408880`; decompiler hides EAX/BL into recreate; lock asserts are soft-continue.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

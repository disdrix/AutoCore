# Dual A/B report — R12-036 OWN-ONLY (`0x005eb040`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-036**  
**Scope:** VA `0x005eb040` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — 0x40 POD block copy leaf; partition parent `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-036.  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005eb040` PodCopyBlock_0x40_Thiscall_Inferred | **accept-with-gaps** — CF/ABI/RET4/16-dword-0x40/leaf/29-xrefs sealed; product blob English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): scaffold-debug-stop / base-ctor-merge / vector-PodCopy-merge / memcpy-merge / wrong ABI / void-return / wrong size claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005eb040` — sealed facts

1. **Body:** `0x005eb040`–`0x005eb0a6` inclusive (**103 B** / `0x67`); pad `CC` from `0x005eb0a7`.
2. **ABI:** **ECX** = dest*; stack `src*`; **EAX** = dest; **`RET 4`**.
3. **Semantics:** leaf **POD block copy** of exactly **16 dwords / 0x40 bytes**:
   - Prolog: `MOV EAX,ECX`; `MOV ECX,[ESP+4]`.
   - Sixteen dword load/store pairs (`dest[i] = src[i]`, offsets `0..0x3C`).
   - No branches, loops, null checks, or callees.
4. **Parent contract:** dualed `FUN_005eb210` calls this as `dest=self+0x80`, `src=params+0x20` (query-object params tail → object float/matrix blob region).
5. **Callees:** none (leaf).
6. **Callers / xrefs:** **29** UNCONDITIONAL_CALL; **13** named callers including parent `FUN_005eb210`, siblings `FUN_005eb0b0` / `FUN_005eb0e0`, and multi-site consumers (`FUN_005f0210` ×6, `FUN_005f1ec0` ×3, `FUN_00662510` ×2, `FUN_00668d30` ×2, …).
7. **Peers (evidence only):** parent base ctor `005eb210`; nearby wrappers `005eb0b0` / `005eb0e0`; **do not** merge with StdVector PodCopy register-ABI leaves.
8. **Name:** `PodCopyBlock_0x40_Thiscall_Inferred` (Ghidra `FUN_005eb040`). Product blob English open → `_Inferred`. Scaffold `Named_CalleeOf_*VOG_DEBUG_STOP*005eb040` **retired**.
9. **Decompile ≡ raw CF**; ABI/size sealed via `disassemble_function` + `read_memory` + call-site context. Decompiler `void` return is a known display gap (EAX=dest).

### Gaps

- Product/PDB English for the 0x40 blob type.  
- Full per-caller dest/src field map beyond parent `+0x80` / `params+0x20`.  
- Whether any consumer depends on EAX return.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005eb040_FUN_005eb040.md` |
| Annotated | `docs/reconstruction/raw/aa_005eb040_FUN_005eb040.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodCopyBlock_0x40_Thiscall_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005eb040.cpp` |
| Function | `docs/reconstruction/functions/aa_005eb040_FUN_005eb040.md` |
| Function named | `docs/reconstruction/functions/aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005eb210  VOGPhysics_QueryObject_BaseCtor_Inferred  [dualed R11-008]
  └─ FUN_005eb040  PodCopyBlock_0x40_Thiscall_Inferred  [OWN R12-036]
       dest = self+0x80
       src  = params+0x20

FUN_005eb0b0 / FUN_005eb0e0  nearby helpers               [residual]
  └─ FUN_005eb040  [OWN]

FUN_005f0210 / FUN_005f1ec0 / FUN_00662510 / …            [residual]
  └─ FUN_005eb040  multi-site 0x40 block consumers
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005eb040-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005eb040` | Port as **thiscall POD memcpy of 0x40**: ECX=dest, stack=src*, EAX=dest, **RET 4**. Unrolled 16×`uint32` stores or `memcpy(dest,src,0x40)`. |
| Do **not** | Treat as query ctor; merge with vector PodCopy register-ABI leaves; trust decompiler `void`; invent debug-stop / product matrix labels without further duals. |
| Pair with | dualed parent `VOGPhysics_QueryObject_BaseCtor_Inferred` `005eb210`; residual siblings `005eb0b0` / `005eb0e0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable
- system map `interaction-activation.md` entry for `aa_005eb040`
- retire scaffold `Named_CalleeOf_*VOG_DEBUG_STOP*005eb040` inventory aliases

**Terminal:** false.

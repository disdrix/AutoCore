# Dual A/B report — MEGA-039 OWN-ONLY (`0x006c6c50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-039**  
**Scope:** VA `0x006c6c50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `analyze_control_flow`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — area-query filter bit test callee of dualed **CVOGPhysicsUtils_GetObjectsInArea** (`0x004ea350`).  
**Partition:** interaction-activation; hint "area-query filter bit test".  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006c6c50` CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/matrix offsets/sole caller sealed; product this-object English + high-16 rule + per-bit meanings open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG_DEBUG_STOP-scaffold / skill-helper / cdecl / EAX-bool / unmasked indices / matrix@+0 / early-out-pass / mutator / multi-caller claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006c6c50` — sealed facts

1. **Body:** `0x006c6c50`–`0x006c6c98` inclusive (**73 B** / `0x49`); pad `CC` after.
2. **ABI:** **ECX** = this (filter bit-matrix); stack `uint8_t *out`, `uint32_t object_type`, `uint32_t filter_flags`; void; **`RET 0xC`** ×2 exits. EAX left holding `out*` (parent `CMP BYTE PTR [EAX],0`).
3. **Semantics:** area-query **filter bit test**:
   - Early-out: if `((a ^ b) & 0xFFFF0000) == 0` **and** `(a & 0xFFFF0000) != 0` → `*out = 0`.
   - Else: `*out = (*(uint32_t*)(this + 0x1C + (a & 0x1F)*4) & (1u << (b & 0x1F))) != 0`.
   - Leaf: no callees; read-only on matrix.
4. **Callees:** none.
5. **Callers:** **1** UNCONDITIONAL_CALL — dualed `CVOGPhysicsUtils_GetObjectsInArea` `0x004ea350` @ `0x004ea560` (default AABB hit loop).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` (Ghidra `FUN_006c6c50`). Product English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product type/name of filter bit-matrix object (caller EBX / this).  
- High-16 early-out product packing rule (CF sealed as reject).  
- Per-bit meanings of filter flags (`1` / `0x11` / `0x0a` from parent dual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_006c6c50_FUN_006c6c50.md` |
| Annotated | `docs/reconstruction/raw/aa_006c6c50_FUN_006c6c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006c6c50.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50.cpp` |
| Function | `docs/reconstruction/functions/aa_006c6c50_FUN_006c6c50.md` |
| Function named | `docs/reconstruction/functions/aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGPhysicsUtils_GetObjectsInArea  (0x004ea350)  [dualed parent]
  ├─ mode==1 / mode==2 alternate broadphase  (no call to this leaf)
  └─ default AABB path
       profile "CVOGPhysicsUtils::GetObjectsInArea::aabb"
       world broadphase query
       for each hit:
         FUN_006c6c50  CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred  [OWN MEGA-039]
           this = filter bit-matrix (EBX)
           a    = hit object +0x1c (type/category)
           b    = query filterFlags (param_6)
         if *out == 0: skip
         else FUN_0040afb0 resolve + append
```

Gather consumer flag samples (parent dual evidence): default `1`; modes 1/2 → `0x11`; mode 7 → `0x0a`.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006c6c50-mega-039-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006c6c50` | Port as **area-query filter bit-matrix test**. **thiscall RET 0xC**. Result via **out-byte** (not EAX bool). Matrix rows at **`this+0x1C`**, indices **`& 0x1F`**. High-16 early-out **rejects**. Keep distinct from mode-1/mode-2 broadphase paths that do not call this leaf. |
| Pair with | dualed parent GetObjectsInArea `004ea350`; residual gather flag ladder; object resolve `0040afb0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (interaction-activation / physics utils filter)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x006c6c50`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + CF metrics. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; machine twin `FUN_006c6c50.cpp`; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: high-16 same-class early-out forces **false**; EAX is out-pointer not bool; decompiler void + out-param.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

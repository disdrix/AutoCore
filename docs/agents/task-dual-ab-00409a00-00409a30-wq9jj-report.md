# Dual A/B report — WQ9J-J OWN-ONLY (`0x00409a00`, `0x00409a30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-J**  
**Scope:** VAs `0x00409a00`, `0x00409a30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + call-site assembly. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-J**.  
**Work item:** WQ-009 depth-7 residual dual seal — **hkArray elem8 free-if-owned (SEH)** + **gfx param lookup+write** (`gWorldFogCenter` callers).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409a00` HkArray_Elem8_FreeIfOwned_Inferred | **accept-with-gaps** — CF/ABI/mask/*8/tag0x12/SEH callers sealed; product elem type open |
| `aa_00409a30` GfxParam_LookupAndWrite_Inferred | **accept-with-gaps** — CF/EAX·EDX·RET4/vtbl slots/string sealed; host RTTI open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): full-worklist-merge / wrong elem size / thiscall-on-00409a30 / hardcoded-name-in-body / physics-vtbl merge claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409a00` — sealed facts

1. **Body:** `0x00409a00`–`0x00409a28` exclusive (**40 B** / `0x28`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = `{data*, size, capacity}`; plain **RET**; void.
3. **Semantics:** free-if-owned for **elem size 8**:
   - Early-out when `(int)capacity < 0` (high-bit unowned sentinel).
   - Else `nbytes = (capacity & 0x7fffffff) * 8`; `DAT_00b05060` vtbl **`+0x14`**(data, nbytes, tag **`0x12`**).
   - Size field `@+4` unused.
4. **Decompiler gap:** omits `AND 0x7FFFFFFF` (machine present).
5. **Callers (2):** SEH unwind JMPs `Unwind@009a26a5` / `Unwind@009bc140` only.
6. **Xrefs:** 2 (both JMP).
7. **Callees:** indirect free only.
8. **Name:** `HkArray_Elem8_FreeIfOwned_Inferred` (Ghidra `FUN_00409a00`). Free-only sibling of dualed worklist release `0055f4c0`. Product open → `_Inferred`.
9. **Decompile ≡ raw CF**; mask/body sealed via `read_memory` + `disassemble_function`.

### Gaps

- Product allocator English + concrete elem type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409a00_FUN_00409a00.md` |
| Annotated | `docs/reconstruction/raw/aa_00409a00_FUN_00409a00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HkArray_Elem8_FreeIfOwned_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409a00.cpp` |
| Function | `docs/reconstruction/functions/aa_00409a00_FUN_00409a00.md` |
| Function named | `docs/reconstruction/functions/aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md` |

---

## VA `0x00409a30` — sealed facts

1. **Body:** `0x00409a30`–`0x00409a64` exclusive (**52 B** / `0x34`); pad `CC`.
2. **ABI (machine):** **EAX** = host ctx; **EDX** = name C-string; stack = data*; **`RET 0x4`**. Decompiler phantom `in_EAX` + `__fastcall` labels are incomplete.
3. **Semantics:** graphics param service write:
   - `service = *(host+4)+0xc`.
   - If service non-null: `handle = vtbl+0x24(service, 0, name)`.
   - Else `handle = 0`.
   - Reload service; `vtbl+0x50(service, handle, data, 0xFFFFFFFF)` — **no second null guard**.
4. **Call sites:** `FUN_00942840` @ `0x00942c4d` / `0x00942d15` — `EAX=[DAT_00d1f05c]`, `EDX=0xa2cf30` (`"gWorldFogCenter"`), push float3*.
5. **Xrefs:** 2 UNCONDITIONAL_CALL (same caller).
6. **Callees:** indirect vtbl+0x24 / +0x50 only.
7. **Name:** `GfxParam_LookupAndWrite_Inferred` (Ghidra `FUN_00409a30`). Reject physics impulse / EffEffect FindParam / NDSpecialFX SetParamFloat3 merges.
8. **Decompile ≡ raw CF**; ABI/string sealed via disasm + call-site + `read_memory` on string.

### Gaps

- Product RTTI for host/service.  
- Write-flag `-1` English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409a30_GfxParam_LookupAndWrite_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409a30_GfxParam_LookupAndWrite_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409a30_FUN_00409a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00409a30_FUN_00409a30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxParam_LookupAndWrite_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409a30.cpp` |
| Function | `docs/reconstruction/functions/aa_00409a30_FUN_00409a30.md` |
| Function named | `docs/reconstruction/functions/aa_00409a30_GfxParam_LookupAndWrite_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
SEH Unwind tables
  └─ FUN_00409a00  HkArray_Elem8_FreeIfOwned_Inferred   [OWN WQ9J-J]
        └─ DAT_00b05060.vtbl+0x14  tagged free tag 0x12 *8

Compare free half: FUN_0055f4c0  LocalWorklist_Release_Inferred  [dualed W27-N]
Compare stride-16: FUN_0055f590  LocalWorklist16_Release         [dualed W28-R]

FUN_00942840  (client fog/world update; residual)
  ├─ inline: DAT_00d1f05c → service +0x24/+0x50 "gWorldFogCenter"
  └─ FUN_00409a30  GfxParam_LookupAndWrite_Inferred     [OWN WQ9J-J]
        ├─ service.vtbl+0x24  lookup (arg1=0)
        └─ service.vtbl+0x50  write (flag -1)

Compare sibling: FUN_00442d50  same lookup then float4 write helper  [undualed residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409a00-00409a30-wq9jj-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409a00` | Port as **elem-size-8 free-if-owned**. **thiscall** ECX triple; plain RET. Preserve **`(cap & 0x7fffffff) * 8`** + tag **`0x12`** + skip when `cap < 0`. Do **not** use as full worklist release (`0055f4c0`) or stride-16 free (`0055f590`). |
| `00409a30` | Port as **named gfx-param lookup+write**. **EAX host / EDX name / stack data / RET 4**. Preserve null-lookup-only + unsafe second service load. Callers bind `"gWorldFogCenter"` + float3. Do not assume thiscall-ECX. |
| Pair with | dualed `LocalWorklist_Release` `0055f4c0`, fog/env paths using `DAT_00d1f05c`; residual `FUN_00442d50`, caller `FUN_00942840`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (allocator + gfx param residual — not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409a00`, `0x00409a30`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; machine mask on free; ABI correction for EAX host.  
- Odd behavior preserved: decomp mask omit on free; null service write fault path.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

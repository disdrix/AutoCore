# Dual A/B report — MEGA-067 OWN-ONLY (`0x00402280`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-067**  
**Scope:** VA `0x00402280` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent decompile samples. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-067 / missions-progression residual under `createNDUIDialogs` (body is shared stdlist destroy leaf).  
**Hint consumed:** `Mission_createNDUIDialogs nested` → **parent seed only**; not this VA’s identity.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402280` StdList_Destroy_FreeHead_ViaClearEsi_Inferred | **accept-with-gaps** — CF/ABI/RET/ECX-shell/clear-ESI/free-head/null/0xC vector sealed; product `list<T>` English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-identity / noreturn-end / free-shell / RET4 / merge-with-00403430 / Named_CalleeOf claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402280` — sealed facts

1. **Body:** `0x00402280`–`0x0040229c` inclusive (**29 B** / `0x1D`); pad `CC` before sibling `FUN_004022a0` @ `0x004022a0`.
2. **ABI:** **ECX** = list shell* (`+4` head, `+8` size); no stack args; void; bare **`RET`** (`C3`).
3. **Semantics:** list-shell complete dtor:
   - `PUSH ESI; MOV ESI,ECX`
   - `CALL StdList_Clear_ESI` (`0x00415e90`) — free element nodes; re-ring sentinel; size=0
   - `operator_delete(*(list+4))` — free sentinel
   - `*(list+4) = 0` (decomp-hidden; `read_memory` sealed)
   - `POP ESI; RET`
4. **Callees:** `FUN_00415e90` (dualed `StdList_Clear_ESI`); `operator_delete` @ `0x00489822`.
5. **Callers / xrefs:**
   - **10** Unwind JMP: `LEA ECX,[EBP+local]; JMP 00402280`
   - DATA: `FUN_008a5ba0` / `FUN_008a5c90` — `_eh_vector_*_iterator_(this+0x5cc, **0xC**, **4**, FUN_00402280)`
   - DATA table pushes @ `0x009b61fe`, `0x009b625a`
6. **Ctor pair:** `FUN_004023f0` (alloc empty sentinel via `0040fb90`, size=0).
7. **Name:** `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` (Ghidra `FUN_00402280`).  
   Retired: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00402280`.
8. **Twin:** `StdList_Destroy_FreeHead_Inferred` @ `0x00403430` (same outer CF via Clear-ECX `0x00404060`).
9. **Decompile ≡ raw** for clear+delete; full CF via `read_memory` (false noreturn truncates decomp).

### Gaps

- Product demangle `list<T>` / element node payload English.  
- Host class plate for parents `FUN_008a5ba0` / `FUN_008a5c90` (`vtbl 00a4c61c`, `i_d_q.xml`) — out of OWN.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402280_FUN_00402280.md` |
| Annotated | `docs/reconstruction/raw/aa_00402280_FUN_00402280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Destroy_FreeHead_ViaClearEsi_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402280.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00402280.cpp` |
| Function | `docs/reconstruction/functions/aa_00402280_FUN_00402280.md` |
| Function named | `docs/reconstruction/functions/aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008a5c90  (UI/NDUI host ctor; vtbl 00a4c61c; NDUIWindow_ReloadInterface "i_d_q.xml")  [not OWN]
  └─ _eh_vector_constructor_iterator_(this+0x5cc, 0xC, 4, FUN_004023f0, FUN_00402280)
       ├─ FUN_004023f0  shell ctor (alloc sentinel)  [residual]
       └─ FUN_00402280  StdList_Destroy_FreeHead_ViaClearEsi_Inferred  [OWN MEGA-067]

FUN_008a5ba0  (matching dtor path)
  ├─ _eh_vector_destructor_iterator_(this+0x5cc, 0xC, 4, FUN_00402280)  [OWN]
  └─ StdList_Clear_ESI @ this+0x5c0 + free head  [dualed clear; not OWN destroy]

FUN_00402280  [OWN MEGA-067]
  └─ FUN_00415e90  StdList_Clear_ESI  [dualed WQ9L-H]
  └─ operator_delete  (sentinel)

Twin (do not merge VA):
  FUN_00403430  StdList_Destroy_FreeHead_Inferred  → Clear ECX 00404060
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402280-mega-067-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402280` | Port as **std::list shell destroy**: clear nodes + free sentinel + null head. **ECX=list***, bare **RET**. Prefer calling the same clear helper used by `StdList_Clear_ESI` then `delete head`. Do **not** free the shell. Keep distinct from twin `00403430` (Clear-ECX path) and from clear-only `00415e90`. |
| Pair with | dualed `StdList_Clear_ESI` `00415e90`; ctor `004023f0` / alloc `0040fb90`; twin destroy `00403430`; residual host `008a5ba0`/`008a5c90`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (shared stdlist — not mission-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00402280`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context + parent decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (restore null-head after false noreturn).  
- Odd behavior preserved: decompiler drops tail; clear leaf keeps sentinel for this free.  
- `_Inferred` where product demangle unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

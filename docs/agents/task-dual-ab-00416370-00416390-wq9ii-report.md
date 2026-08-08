# Dual A/B report — WQ9I-I OWN-ONLY (`0x00416370`, `0x00416390`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9I-I**  
**Scope:** VAs `0x00416370`, `0x00416390` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-I**.  
**Work item:** WQ-009 depth-6 residual dual seal (`00416xxx` neighborhood — CS pre-zero + SEH InitCS pair).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416370` Mem_ZeroSixDwords_Ecx_Inferred | **accept-with-gaps** — six-dword/0x18 zero leaf CF/ABI/body sealed; sole-caller CS pre-zero; product demangle open |
| `aa_00416390` CriticalSection_Initialize_SehToHresult_Ecx_Inferred | **accept-with-gaps** — SEH InitCS HRESULT CF/ABI/IAT/map sealed; product demangle open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): void-return, stack-formal, bare InitCS thunk, always-0, all-exceptions-OOM, skill-domain, and base-object-zero claims all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00416370` — sealed facts

1. **Body:** `0x00416370`–`0x00416388` exclusive (**24 B** / `0x18`); pad `CC` to twin.
2. **ABI:** **ECX** = `uint32_t*` dest; **EAX** = dest on return (`MOV EAX,ECX`); plain **`ret 0`** (`C3`).
3. **Semantics:** Zero six consecutive dwords (0x18 bytes — Win32 x86 `sizeof(CRITICAL_SECTION)`).
4. **Classification:** leaf.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `0x00489d9b` in `FUN_00489d95` — `MOV ESI,ECX`; `LEA ECX,[ESI+0x18]`; CALL (pre-zero CS field of outer host).
6. **Callees:** none.
7. **Name:** `Mem_ZeroSixDwords_Ecx_Inferred` (Ghidra `FUN_00416370`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; EAX return-dest sealed via **bytes** (decompiler shows void).

### Gaps

- Product / MSVC demangle plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416370_Mem_ZeroSixDwords_Ecx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416370_Mem_ZeroSixDwords_Ecx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416370_FUN_00416370.md` |
| Annotated | `docs/reconstruction/raw/aa_00416370_FUN_00416370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_ZeroSixDwords_Ecx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416370.cpp` |
| Function | `docs/reconstruction/functions/aa_00416370_FUN_00416370.md` |
| Function named | `docs/reconstruction/functions/aa_00416370_Mem_ZeroSixDwords_Ecx_Inferred.md` |

---

## VA `0x00416390` — sealed facts

1. **Body:** `0x00416390`–`0x0041640A` exclusive (**122 B** / `0x7A`); pad `CC` before `0x00416410`.
2. **ABI:** **ECX** = `LPCRITICAL_SECTION`; **EAX** = **HRESULT**; plain **`ret 0`**.
3. **Semantics:** MSVC SEH-wrapped **`InitializeCriticalSection(cs)`**:
   - Success → `0` (`S_OK`).
   - `STATUS_NO_MEMORY` (`0xC0000017`) → `E_OUTOFMEMORY` (`0x8007000E`).
   - Any other SEH → `E_FAIL` (`0x80004005`) via `NEG/SBB/AND 0xFFF93FF7/ADD 0x8007000E`.
   - Scope `DAT_00aaa698` filter `0x004163C4` / handler `0x004163D4`; frame `DAT_00489cb0`.
   - IAT call `dword ptr [0x009c61ec]`.
4. **Classification:** worker.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `0x00489e50` in `FUN_00489dc5` — `LEA ECX,[ESI+0x18]`; `TEST EAX,EAX` / `JGE` else `DAT_00d1f0f0 = 1`.
6. **Callees:** `InitializeCriticalSection` (IAT).
7. **Name:** `CriticalSection_Initialize_SehToHresult_Ecx_Inferred` (Ghidra `FUN_00416390`). Product demangle open → `_Inferred`.
8. **Decompile ≡ success path**; exception arms sealed from **bytes** + SEH table `read_memory`.

### Gaps

- Product / ATL demangle plate.  
- Exact CRT identity of frame handler `DAT_00489cb0`.  
- Runtime / bit-exact under forced InitCS failure.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416390_CriticalSection_Initialize_SehToHresult_Ecx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416390_CriticalSection_Initialize_SehToHresult_Ecx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416390_FUN_00416390.md` |
| Annotated | `docs/reconstruction/raw/aa_00416390_FUN_00416390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CriticalSection_Initialize_SehToHresult_Ecx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416390.cpp` |
| Function | `docs/reconstruction/functions/aa_00416390_FUN_00416390.md` |
| Function named | `docs/reconstruction/functions/aa_00416390_CriticalSection_Initialize_SehToHresult_Ecx_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00489dc5 (host ctor; unowned)
  └─ FUN_00489d95
       └─ Mem_ZeroSixDwords_Ecx_Inferred (0x00416370)  [OWN WQ9I-I]
            zeros CRITICAL_SECTION at host+0x18
  … fill host fields (size 0x3c, flags, GUID ptr, …) …
  └─ CriticalSection_Initialize_SehToHresult_Ecx_Inferred (0x00416390)  [OWN WQ9I-I]
       InitializeCriticalSection(host+0x18); HRESULT → fail flag DAT_00d1f0f0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416370-00416390-wq9ii-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416370` | Port as **leaf zero of 6 dwords (0x18 B)** at **ECX**; **EAX** returns dest; **ret 0**. Sole use pre-zeros CS body. Not skill logic. |
| `00416390` | Port as **SEH InitCS → HRESULT** (0 / E_OUTOFMEMORY / E_FAIL). **ECX**=cs*, **ret 0**. Do **not** strip SEH map to bare InitCS. |
| Pair with | Same host field `+0x18` in `FUN_00489dc5` / `FUN_00489d95` (unowned). DeleteCS neighbor site at `0x00489db6` IAT (unowned). |
| Naming caution | **Not** Enter/Leave. **Not** skill/cast. Prefer `_Inferred` until product demangle. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (util/sync — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00416370`, `0x00416390`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not blank Ghidra paste).  
- Odd behavior preserved: decompiler void vs EAX return-dest on zero leaf; SEH arms under-shown in decompile sealed from bytes.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

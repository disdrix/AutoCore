# Dual A/B report — R10-024 OWN-ONLY (`0x00418790`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-024**  
**Scope:** VA `0x00418790` (`aa_00418790`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` + `get_assembly_context` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — undualed callee of dualed parent `0x004027f0` → sealed as **shared list `_Incsize`** twin of dualed `StdList_Incsize` `0x0043fe60`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` (R10-024).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00418790` StdList_Incsize_00418790 | **accept** — CF/ABI/RET/size+8/max/string/throw/29 xrefs/twin sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): RecvBroadcast-only / thiscall / BuyNode / unlimited-size / stack-arg claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00418790` — sealed facts

1. **Body:** `0x00418790`–`0x004187fe` inclusive (**111 B** / `0x6F`); last insn plain **`RET`** (`C3`).
2. **ABI:** **`__fastcall`** — **ECX** = count, **EDX** = list*; void; no stack args. Not thiscall.
3. **Semantics:** MSVC **`std::list::_Incsize`**:
   - SEH frame (`LAB_009bc919` / FS:[0]).
   - Load `_Mysize` @ `list+8`.
   - If `0x3fffffffU - size < count` → `"list<T> too long"` @ `0x00a1581c` → `FUN_00401a40` → `_CxxThrowException(..., DAT_00acc388)`.
   - Else `_Mysize += count`.
   - Does **not** allocate or relink nodes (callers do).
4. **Callees:** `basic_string` ctor, `FUN_00401a40` (`Std_LengthError_CtorFromString`), `_CxxThrowException` @ `0x006a3d60` (throw path only).
5. **Callers / xrefs:** **29** CALL sites / **21** caller functions (insert/push wrappers). Parent dual `FUN_004027f0` @ `00402805`: `MOV ECX,1` / `MOV EDX,EBX` / `CALL`.
6. **Twin:** dualed `StdList_Incsize` `0x0043fe60` (W23-E **accept**) — same CF/ABI/max/string/throw.
7. **Name:** `StdList_Incsize_00418790` (Ghidra `FUN_00418790`). VA suffix disambiguates from twin. Retire `Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00418790`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Exact C++ exception type English beyond ThrowInfo + length_error ctor.  
- Why two identical image copies (`00418790` vs `0043fe60`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00418790_StdList_Incsize_00418790.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00418790_StdList_Incsize_00418790.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00418790_FUN_00418790.md` |
| Annotated | `docs/reconstruction/raw/aa_00418790_FUN_00418790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Incsize_00418790.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00418790.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00418790.cpp` |
| Function | `docs/reconstruction/functions/aa_00418790_FUN_00418790.md` |
| Function named | `docs/reconstruction/functions/aa_00418790_StdList_Incsize_00418790.md` |

---

## Chain context (not dualled; evidence only)

```text
insert / push wrappers
  e.g. FUN_004027f0  StdList_PushFront_DwordFromEax_Inferred  [dualed MEGA-089]
  e.g. FUN_00403120  insert-before-node
  e.g. FUN_00405e20  related splice
        ├─ FUN_00418700  StdList_BuyNode_Dword_Seh  [dualed MEGA-081]
        └─ FUN_00418790  StdList_Incsize_00418790   [OWN R10-024]
              ├─ FUN_00401a40  Std_LengthError_CtorFromString  [dualed]
              └─ _CxxThrowException(..., DAT_00acc388)

twin leaf (dualed):
  StdList_Incsize @ 0x0043fe60  [W23-E accept]

related (not OWN):
  FUN_00404840  thiscall size path  [R10-006 residual]
  StdList_Incsize_Max1fffffff @ 0x00416010  [dualed; different max]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00418790-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00418790` | Port as **`std::list` `_Incsize`**: **ECX=count**, **EDX=list***, plain **`RET`**. Gate max **`0x3fffffff`**; message **`"list<T> too long"`**. Field **`list+8`**. May **share implementation** with dualed twin `StdList_Incsize` `0043fe60`. Do **not** model as thiscall; keep distinct from `00404840` and `Max1fffffff` variants. |
| Pair with | dualed twin `0043fe60`; BuyNode `00418700`; length_error `00401a40`; parent push_front `004027f0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL list helper — multi-domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00418790`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful VA-disambiguated name; machine ABI sealed (fastcall ECX/EDX; plain RET).  
- Scaffold `Named_CalleeOf_*` retired. Twin relationship to `0043fe60` documented.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

# OWN-ONLY dual agent report — W24-F

**Date:** 2026-07-29  
**Agent:** W24-F OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00421362`, `0x004d8a10`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00421362` OleDb_AllocBindingsBuf_EnterBuild_Inferred | **accept-with-gaps** — **SEH-split gate; null temp → E_OUTOFMEMORY; `new[](colCount)→ctx+0x10`; jmp `FUN_0042139b` sealed; product English open** |
| `aa_004d8a10` CVOGSectorMap_Constructor | **accept-with-gaps** — **thiscall ctor, vtbl `0x009cc770`, return this, product class via `@@new CVOGSectorMap` / `0xE920` sealed; full field English open** |

---

## `aa_00421362` — OleDb_AllocBindingsBuf_EnterBuild_Inferred

### Sealed facts

1. **Body:** `0x00421362`–`0x00421391` (Ghidra). SEH-split worker fragment of OLE DB accessor setup.

2. **ABI:** Shared parent EBP/SEH with `FUN_0042139b` + `FUN_00421677`. Pre-entry `0x0042135f`: `mov ebx,[ebp+8]`. Success **`jmp 0x0042139b`** (not call+ret). Fail path shared epilogue **`ret 4`**, EAX = **`0x8007000E`** (E_OUTOFMEMORY).

3. **Null path:** `[ebp-0x1c] == 0` (parent temp bindings) → SEH=`-1`, optional COM Release on `[ebp-0x18]` (vtbl+8), restore ExceptionList, return E_OUTOFMEMORY.

4. **Success path:** SEH level **4**; `operator_new[]([ebx+0xc])` → store **`[ebx+0x10]`**; jmp into build.

5. **Caller:** `FUN_00421240` only — allocates `colCount * 0x34` temp then enters this fragment.

6. **Name:** `OleDb_AllocBindingsBuf_EnterBuild_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00421362`.

### Gaps

1. Product C++ type for ctx.  
2. Exact English for `ctx+0x10` buffer.  
3. Possible Ghidra merge with siblings — out of sole ownership.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_AllocBindingsBuf_EnterBuild_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00421362.cpp` |
| Raw | `docs/reconstruction/raw/aa_00421362_FUN_00421362.md` |
| Annotated | `docs/reconstruction/raw/aa_00421362_FUN_00421362.annotated.md` |

---

## `aa_004d8a10` — CVOGSectorMap_Constructor

### Sealed facts

1. **Body:** `0x004d8a10`–`0x004d938f` (~0x97F B).

2. **ABI:** **thiscall** (ECX=this → ESI); bare **`ret`**; **EAX=this**.

3. **Vtbl:** `*this = PTR_FUN_009cc770` (`0x009cc770`).

4. **Product class:** Caller `Client_InitInstance` does `FUN_007a4400("@@new CVOGSectorMap")` then `operator_new(0xE920)` then this ctor; stores result at InitInstance+`0xe04`.

5. **Bring-up:** Embedded rb-tree headers (`FUN_004e7450`×4, `FUN_004e7420`×2), many `InitializeCriticalSection` pairs, heap `0x44` lock wrappers, many `0x34` typed nodes, large `0x5118`/`0x40`/`0x70` subsystems, `GetTickCount`, `g_flOne` defaults, **`_DAT_00b03600 = this`**, bump `_DAT_00b037e4`.

6. **Name:** `CVOGSectorMap_Constructor` (product class High). Ghidra: `FUN_004d8a10`.

### Gaps

1. Exhaustive 0xE920 field English.  
2. Product names for subsystem factories.  
3. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004d8a10_CVOGSectorMap_Constructor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004d8a10_CVOGSectorMap_Constructor.md` |
| Function record | `docs/reconstruction/functions/aa_004d8a10_CVOGSectorMap_Constructor.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_Constructor.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004d8a10.cpp` |
| Raw | `docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.md` |
| Annotated | `docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### OleDb alloc gate (`0x00421362`)

- Port as **shared-frame fragment**, not a standalone portable function with success-path ret.
- Keep **null-temp → E_OUTOFMEMORY** and **jmp into binding build**.
- Parent owns `colCount*0x34` temp; this unit allocates **colCount-sized** aux into `ctx+0x10`.

### CVOGSectorMap ctor (`0x004d8a10`)

- Server/client ports must size the object **0xE920** and install equivalent subsystem graph.
- Treat as **client sector-map root** (global `_DAT_00b03600`); StepTo and related duals hang off this type/vtbl family.
- Do not invent HRESULT failure for the ctor body; child `new` failures store null pointers.

# Function record: CVOGSectorMap_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d8a10` |
| **Canonical name** | `CVOGSectorMap_Constructor` |
| **Ghidra name** | `FUN_004d8a10` |
| **Address** | `0x004d8a10` |
| **Body range** | `0x004d8a10`–`0x004d938f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / CVOGSectorMap |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; ABI + vtbl + phases + product class sealed; full field English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004d8a10_CVOGSectorMap_Constructor.md`, `reviews/B_aa_004d8a10_CVOGSectorMap_Constructor.md` |
| **Last reviewed** | `2026-07-29` (W24-F) |

## Alias

- `FUN_004d8a10` (Ghidra)
- `Named_CalleeOf_Named_Client_InitInstance_004d8a10` (auto parent-seed)
- Prior scaffold system `unknown`

## Purpose

**CVOGSectorMap** C++ constructor: install vtbl, zero/default hundreds of members, init embedded rb-tree headers and critical-section lock objects, heap-allocate subsystem helpers (0x34 / 0x44 / 0x40 / 0x70 / 0x5118), stamp `GetTickCount`, publish global `g_pSectorMap`-like `_DAT_00b03600`, bump construction counter, return `this`.

## Signature

```c
// Machine: __thiscall, ECX=this, bare ret; EAX=this
// Ghidra: undefined4 * __fastcall FUN_004d8a10(undefined4 *param_1)
CVOGSectorMap* __thiscall CVOGSectorMap_Constructor(CVOGSectorMap* this);
```

## Object

| Item | Value | Conf |
|---|---|---|
| Alloc size (caller) | `0xE920` | **High** |
| Vtbl | `PTR_FUN_009cc770` @ `0x009cc770` | **High** |
| Product class | `CVOGSectorMap` | **High** (InitInstance string) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.md`
- Annotated: `docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGSectorMap_Constructor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004d8a10.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00421362-004d8a10-w24f-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `Client_InitInstance` / `FUN_0094a6a0` @ xref `0x0094a9d7` (after `@@new CVOGSectorMap`) |
| **Callees** | `FUN_004e7450`×4, `FUN_004e7420`×2, `InitializeCriticalSection`×N, `operator_new`, many subsystem ctors (`FUN_004e28c0`, `FUN_004e59b0`…, `FUN_005abfa0`, `FUN_005b0650`, `FUN_004bff60`, …), `GetTickCount`, `FUN_004e4620`, `FUN_00418e60` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + return this + bare ret | **High** |
| vtbl `0x009cc770` | **High** |
| Product class CVOGSectorMap | **High** |
| Phase structure / callee groups | **High** |
| Per-field English for full 0xE920 | **Partial / Open** |
| Runtime / bit-exact | Open |

## Related

- `aa_004e7450` RbTree_InitEmptyHeader
- `aa_004e7420` RbTree_InitEmptyHeader_Node1c
- `aa_004d6c80` CVOGSectorMap_StepTo
- `aa_0094a6a0` Client_InitInstance

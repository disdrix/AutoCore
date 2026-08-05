# Function record: CNDUIWndBuffered_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078caf0` |
| **Canonical name** | `CNDUIWndBuffered_Ctor_Inferred` |
| **Ghidra name** | `FUN_0078caf0` |
| **Address** | `0x0078caf0` |
| **Body range** | `0x0078caf0`–`0x0078cecb` exclusive (**987 B** / `0x3DB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / ND UI buffered window |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/RTTI/size/callers sealed; field-bank product English residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md`, `reviews/B_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` (2026-07-29 W34-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0078caf0`
- `Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0078caf0` (**reject** — shopveh string is a downstream window XML, not this base class)
- Host class RTTI: **`CNDUIWndBuffered`** (**Confirmed** via ctor vtbl COL)

## Purpose

Complete constructor for **`CNDUIWndBuffered`** (size **0x4FC**):

1. `CNDUIWindow` base ctor `FUN_007b5dd0(this, arg1)`
2. Install vtbl `PTR_FUN_00a99f74` (`.?AVCNDUIWndBuffered@@`)
3. Initialize buffered-window field bank (floats, flags, 1/255-scaled color literals)
4. `new(0x80)` + `HostBase_DefaultCtor` → `+0x2A8`; `HostBase_EnsureAuxPtrs(host, 1)`
5. Return `this`

## Signature

```c
CNDUIWndBuffered *CNDUIWndBuffered_Ctor_Inferred(
    CNDUIWndBuffered *this,  // stack
    uint32_t arg1,           // base formal; observed 0
    uint32_t arg2);          // stored +0x488; observed 0 or 1
// ret 12; returns this
```

## Algorithm

```
CNDUIWindow_Ctor(this, arg1)
*this = CNDUIWndBuffered_vtbl
init field bank; this[+0x488] = arg2
host = new(0x80) ? HostBase_DefaultCtor : null
this[+0x2A8] = host
HostBase_EnsureAuxPtrs(host, 1)
return this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0078caf0_FUN_0078caf0.md`
- Annotated: `docs/reconstruction/raw/aa_0078caf0_FUN_0078caf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_Ctor_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0078caf0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0078caf0_FUN_0078caf0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0078caf0-0048eb10-w34t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x007b5dd0` | `CNDUIWindow` base ctor |
| Callee | `0x00489892` | `operator_new` |
| Callee | `0x007560d0` | `HostBase_DefaultCtor` (W32-O) |
| Callee | `0x00756320` | `HostBase_EnsureAuxPtrs` (W32-Q) |
| Caller | `0x00856490` | `CWndPortrait` subclass ctor |
| Caller | `0x008345c0` | `CWndVehicle` subclass ctor |
| Caller | `0x0097c720` | `CWndParticles` subclass ctor |
| Caller | `0x008ff260` / `0x008a9af0` / `0x008e6b50` | `new(0x4FC)` + this |
| Related | `0x0078ca80` | complete dtor (same vtbl; tears HostBase @ `+0xaa`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + `ret 12` + return this | **Confirmed** |
| Class = `CNDUIWndBuffered` RTTI | **Confirmed** |
| Instance size 0x4FC | **Confirmed** |
| Nested HostBase @ +0x2A8 size 0x80 | **Confirmed** |
| Field-bank product English | **Open** |
| arg1/arg2 product meaning | **Open** (constants sealed) |
| Runtime / differential | **Open** |

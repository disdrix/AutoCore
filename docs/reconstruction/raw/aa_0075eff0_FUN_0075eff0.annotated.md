# Annotated low-level: GfxDevice_Reset

| Field | Value |
|---|---|
| Stable ID | `aa_0075eff0` |
| VA | `0x0075eff0`–`0x0075f55f` exclusive (**1391 B** / `0x56F`) |
| Ghidra | `FUN_0075eff0` |
| Canonical | `GfxDevice_Reset` |
| System | client / Palantir graphics — `gfxDevice.cpp` device Reset |
| Date | 2026-08-04 (W37-N dual) |

## Machine-level notes

- **ABI:** **EAX** = present-param seed (`Palantir+8` from sole caller); stack **(GfxDevice* device, dword arg_b0, byte flag5)**; **`RET 12`**; **EAX out** = `0` / `0xFFFFFFFF`.
- **Entry:** `SUB ESP,0x38`; `MOV EBX,EAX` saves register formal; `EBP` = stack device host.
- **Product identity:** path `...\palantir\graphics\gfxDevice.cpp` + strings `Beginning shutdown for Device Reset()`, factory fail messages, `Device Reset() complete`, D3D9 Reset / TestCooperativeLevel error text.
- **Core API:** `(*device)->vtbl[+0x40](device, &presentLocal)` = **IDirect3DDevice9::Reset**; fail path uses `vtbl[+0x0C]` = **TestCooperativeLevel**.
- **Present local:** 14 dwords copied from `device+0x2B8` (`param_1[0xae]`), then overlay `*EAX`, `EAX[1]`, stack arg2, stack arg3 into the block before Reset.
- **Sole caller:** `Palantir_ResetDevice` (`0x00754480`, W35-K) — passes `[this+0x28]`, `[this+0xB0]`, `byte[this+5]`, EAX=`this+8`.

## High-level CF

```
account_teardown(DAT_00d1f614, device dims)
FUN_0075e710()
build PresentParams local (14 dwords + EAX seed + stack2/3)
log "Beginning shutdown for Device Reset()"
shutdown factories / lists / Release surfaces
hr = IDirect3DDevice9::Reset(device, &present)
if (hr >= 0):
  EvictManagedResources-class (vtbl+0x14)
  reset IB/VB/Texture/BufferedViews/Effect/Stats/GlobalEffect factories
  on any factory hr < 0: log product fail string; return -1
  write-back present; GetDeviceCaps hw (+ optional sw); recreate surfaces
  publish globals; log complete; account_rebuild; device[0x1e9]=0; return 0
else:
  map D3D HRESULT → FUN_0076c130 message
  TestCooperativeLevel diagnostics
  return -1
```

## Factory fail plate (line, string)

| Line | String |
|------|--------|
| 0x236 | Failed to Reset() device on IB Factory |
| 0x239 | Failed to Reset() device on VB Factory |
| 0x23c | Failed to Reset() device on Texture Factory |
| 0x23f | Failed to Reset() device on gfxBufferedViews |
| 0x242 | Failed to Reset() device on Effect Factory |
| 0x245 | Failed to Reset() device on Stats Monitor |
| 0x248 | Failed to Reset() device on Global Effect |

## Decompile vs bytes

| Topic | Winner |
|---|---|
| EAX formal + RET 12 | **bytes** (caller + epilog) |
| Product Reset identity | **strings** |
| Factory order / D3D error map | **decompile ≡ strings** High |
| Success accounting reverse (iVar7/iVar1 zeroed) | decompile residual — treat as best-effort |

## Gaps

- Full GfxDevice / PresentParams product field English beyond sealed offsets.
- Unowned factory Reset helper duals.
- Exact D3D vtbl slot demangle names (Reset / TCL / GetDeviceCaps inferred from HRESULT + usage).
- Runtime / bit-exact / differential.

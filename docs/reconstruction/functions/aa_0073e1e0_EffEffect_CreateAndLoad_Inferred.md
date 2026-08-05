# Function record: EffEffect_CreateAndLoad_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073e1e0` |
| **Canonical name** | `EffEffect_CreateAndLoad_Inferred` |
| **Ghidra name** | `FUN_0073e1e0` |
| **Address** | `0x0073e1e0` |
| **Body range** | `0x0073e1e0`–`0x0073e257` exclusive (**119** B / `0x77`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics effect create + path load + manager register |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + fail destroy sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md`, `reviews/B_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` (2026-08-04 W38-Q) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_0073e1e0`
- Informal: effect loader / CreateEffectFromPath (caller reports)

## Purpose

Factory for effect shells used by slot bind and phase-map loaders: freelist alloc, vtbl install, path load into inner slot, manager registration, null+destroy on fail.

## Signature

```c
void* __stdcall EffEffect_CreateAndLoad_Inferred(
    void* manager,
    void* pathOrToken,
    int32_t* outStatus);
// RET 0x0C
```

## Algorithm

1. `obj = FUN_00457040()` with `EDI=&DAT_00d21970` (block 0x30).
2. If non-null: zero fields, vtbl=`PTR_FUN_00a9f9c4`, `+0x1c/+0x1e=0xFFFF`.
3. `status = FUN_007533e0(path, obj, 0)`; `*outStatus = status`.
4. If `status < 0`: `vtbl[0](obj,1)` if obj; return null.
5. `FUN_0073d830(manager, obj)`; return obj.

## Artifacts

- See `aa_0073e1e0_FUN_0073e1e0.md`.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | freelist, path load, manager register, fail dtor |
| **Callers** | `EffEffectSlot_BindByPath_Inferred`; gfxSubPhaseMap Phase*.fx |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body hex | **High** |
| stdcall 3-arg + null-on-fail | **High** |
| Object layout + vtbl | **High** |
| Product English | **Inferred** |
| Runtime / differential | Open |

## Related

- Param index after load: `aa_00752370` (W38-Q pair)
- Slot bind wrapper: `aa_009701d0` (W37-Q)
- Manager singleton: `DAT_00d1f61c` / ctor `FUN_0073e3a0`

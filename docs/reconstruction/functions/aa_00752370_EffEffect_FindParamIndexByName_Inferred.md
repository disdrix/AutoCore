# Function record: EffEffect_FindParamIndexByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00752370` |
| **Canonical name** | `EffEffect_FindParamIndexByName_Inferred` |
| **Ghidra name** | `FUN_00752370` |
| **Address** | `0x00752370` |
| **Body range** | `0x00752370`–`0x007523cb` exclusive (**91** B / `0x5b`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics effect parameter index lookup |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + table scan sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md`, `reviews/B_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` (2026-08-04 W38-Q) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_00752370`
- Informal: effect GetParameterIndex / FindParam (caller reports)

## Purpose

Map a parameter name/token to its dense table index on a loaded effect shell so callers can set constants/textures (`FUN_0096fff0` family) by index.

## Signature

```c
void __thiscall EffEffect_FindParamIndexByName_Inferred(
    void* effect,              // ECX
    int32_t* outIndex,         // stack
    const void* nameOrToken);  // stack
// RET 0x08
// *outIndex = index >= 0 on hit, else -1
```

## Algorithm

1. `inner = effect[+8]`; default `idx = -1`.
2. If `inner` and `inner[+0xc]` iface: `handle = iface.vtbl[+0x24](iface, 0, name)`.
3. If handle ≠ 0: scan `table=inner[+0x10]` for `count=inner[+0x18]` entries of stride 8; match dword0 → index.
4. Miss / empty / null gates → `*outIndex = -1`; hit → `*outIndex = i`.

## Artifacts

- Raw / annotated / clean / twin / FUN_* record / A/B / report — see `aa_00752370_FUN_00752370.md`.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | indirect `vtbl+0x24` |
| **Callers** | 35 fn — DiffuseTexture / MatDiffuse / MatAmbient / WireColor / unserialize / PalTool hosts |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body hex | **High** |
| thiscall + `ret 8` | **High** |
| Stride-8 handle table | **High** |
| Product English | **Inferred** |
| Runtime / differential | Open |

## Related

- Effect create/load: `aa_0073e1e0` `EffEffect_CreateAndLoad_Inferred` (W38-Q pair)
- Slot bind consumer: `aa_009701d0` `EffEffectSlot_BindByPath_Inferred` (W37-Q)
- Set-param peer: `FUN_0096fff0`

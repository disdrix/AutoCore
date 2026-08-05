# Function record: Env_ApplyFogShaderAndReflect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b36f0` |
| **Canonical name** | `Env_ApplyFogShaderAndReflect_Inferred` |
| **Ghidra name** | `FUN_005b36f0` |
| **Address** | `0x005b36f0`–`0x005b3992` (674 B / `0x2A2`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client environment / fog shader |
| **Wave** | W29-I OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Virtual method that, when context and work flags allow:

1. Binds fog shader constants `gFogEnable`, `gFogStart`, `gFogEnd`, `gFogColor` from `this+0x164`.
2. Packs fog color via `Color_PackFloat4_Scale255_Inferred` (`00973820`).
3. Refreshes environment reflection / vector fields on `*(this+0x158)+8` (dirty counters + optional transform).

Returns **0** if prerequisites present (even if work flag skips body); **-1** if `this+0x15c` / nested `+0xe4f8` missing.

## ABI

| Item | Value |
|---|---|
| ECX | `this` (host with vtbl `PTR_FUN_009d95a0`) |
| Stack | one `uint32_t` arg (forwarded to optional vfunc `+0x3c`) |
| Epilogue | **`ret 4`** (`C2 04 00`) |
| Return | `0` / `0xFFFFFFFF` in EAX |

## Vtbl / ownership

| Item | Value |
|---|---|
| Slot | `PTR_FUN_009d95a0[1]` @ `0x009d95a4` |
| Ctor | `FUN_005b35a0` |
| Body dtor | `FUN_005b3670` |
| Scalar dtor | `FUN_005b3a30` |
| Direct CALL xrefs | **0** (virtual only) |

## Call graph

| | |
|---|---|
| Callers | virtual via vtbl[1] only |
| Callees | `FUN_0074f1b0`, `FUN_00442d50`, `FUN_00973820`, `FUN_0075bf40`, `FUN_0040d340`, `FUN_00442b90`, `FUN_0074dfa0`, `FUN_00416160`, `FUN_004cd220`, `FUN_005b39d0`, `FUN_0099b8a0`, + shader vcalls |

## Gaps

1. Product class English for host / method.
2. Full dual of nested bind/transform helpers (not OWN).
3. Semantic labels for reflect vector fields / `arg0`.
4. Runtime / bit-exact.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b36f0_FUN_005b36f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b36f0_FUN_005b36f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Env_ApplyFogShaderAndReflect_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005b36f0.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_005b36f0_FUN_005b36f0.md` |
| A | `docs/reconstruction/reviews/A_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00973590-005b36f0-w29i-report.md` |

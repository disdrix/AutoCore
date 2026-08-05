# Function record: NDSpecialFX_HostTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8ed0` |
| **Canonical name** | `NDSpecialFX_HostTick_Inferred` |
| **Ghidra name** | `FUN_004b8ed0` |
| **Address** | `0x004b8ed0` |
| **Body span** | `004b8ed0`–`004b9240` (**880 B / `0x370`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Convention** | `__thiscall` + **`ret 4`**; return 0/1 in AL |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff/bit-exact open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Dual A/B** | `reviews/A_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md`, `reviews/B_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` (2026-07-29 W24-C) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

NDSpecialFX **host tick**: rate/type gate, liveness probe, child CVOGObject_Tick / Destroy free path, residual list maintenance, or DeactivateClear + return 1.

## Signature

```c
// thiscall; ret 4
unsigned __thiscall NDSpecialFX_HostTick_Inferred(void *fx_host, void **ctx);
// 0 = still active; 1 = deactivated this call
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b8ed0_FUN_004b8ed0.md`
- Annotated: `docs/reconstruction/raw/aa_004b8ed0_FUN_004b8ed0.annotated.md`
- Clean (mirror): `docs/reconstruction/reconstructed-exact/FUN_004b8ed0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_HostTick_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b8ed0_FUN_004b8ed0.md`
- Review A/B: dual files above

## Callers / callees (sealed-relevant)

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004ba290` | `FUN_004ba290` |
| Caller | `0x004fc400` | `FUN_004fc400` |
| Caller | `0x00516de0` | `FUN_00516de0` (×3 sites) |
| Caller | `0x005a9040` | `FUN_005a9040` (×2) |
| Caller | `0x0097b540` | `FUN_0097b540` |
| Callee | `0x004b7150` | `NDSpecialFX_DeactivateClear_Inferred` |
| Callee | `0x004b75d0` | `NDSpecialFX_UpdateParamMapTransforms_Inferred` |
| Callee | `0x00595230` | `CVOGObject_Tick` |
| Callee | `0x004b7330` | liveness gate (not dualed here) |
| Callee | `0x004b6910` | host notify residual |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile ≡ rate/type gates | **High / Confirmed** |
| ABI ret 4 + 0/1 return | **Confirmed** |
| Role host tick / deactivate | **High** |
| Product C++ name | **Inferred** (`_Inferred`) |
| Runtime / differential | **Open** |

## Prior scaffold alias

`Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_004b8ed0` — too narrow; prefer HostTick.

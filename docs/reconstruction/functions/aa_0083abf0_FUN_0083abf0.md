# Function record: FUN_0083abf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083abf0` |
| **Canonical name** | `FUN_0083abf0` |
| **Named alias** | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` |
| **Address** | `0x0083abf0`–`0x0083ac89` inclusive (**154 B** / `0x9A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shopveh list UI — bind slot from list index if mismatch |
| **Completion status** | **Dual-reviewed** WQ9L-J — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-J** |

## Alias

Human name: `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred`  
Legacy scaffold: `Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083abf0`

## Purpose

Gate + list lookup + conditional bind into residual `FUN_0083ab90` when slot unbound or entity id mismatch. Sole caller is dualed reindex `FUN_0083ac90`. See named function record for full contract.

## Signature (product)

```c
// ECX = slot; EDX = list_i; stack host*; void; RET 4
void __fastcall FUN_0083abf0(int slot, int list_i, void *host);
```

Decompiler `FUN_0083ab90(iVar2)` understates bind ABI — assembly passes ECX=slot_obj, EAX=entity_id, stack host.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.md`
- Annotated: `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0083abf0.cpp`
- Named record: `docs/reconstruction/functions/aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0083ac90` only @ `0083ad5a`, `0083adb7`, `0083add0` |
| Callees | `FUN_00427d20`, `FUN_0083ab90`, entity vtbl `+0x1d4` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from bytes / disasm | **High** |
| ABI ECX/EDX + stack host + RET 4 | **High** |
| Parameter semantic names | **Probable** (`_Inferred`) |
| Types / product demangle | **Open** |
| Runtime | **Open** |

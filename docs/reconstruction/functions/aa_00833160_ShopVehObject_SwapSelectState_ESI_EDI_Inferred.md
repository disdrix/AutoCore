# Function record: ShopVehObject_SwapSelectState_ESI_EDI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00833160` |
| **Canonical name** | `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00833160` |
| **Address** | `0x00833160` |
| **Body** | `0x00833160`–`0x00833383` exclusive (**547 B** / `0x223`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shopveh 2d list / object select-state swap |
| **Completion status** | **Dual-reviewed** WQ9J-D — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Register-pair worker that swaps a curated subset of fields between two objects (**ESI** / **EDI**), including a three-way nested **XformState** exchange at **`+0x510`**:

1. `temp = FieldBlock_CopyFrom_ClearFlags0xBC(stack, ESI+0x510)`
2. `XformState_AssignSelectiveByFlags(ESI+0x510, EDI+0x510)`
3. `XformState_AssignSelectiveByFlags(EDI+0x510, temp)`

Also swaps dwords at `+0x508/+0x50C/+0x5D4/+0x298/+0x5E0..+0x5EC/+0x500/+0x504`, bytes at `+0x4FC/+0x5D0/+0x5DC/+0xBC`, optionally cross-sets nested positions via vtbl `+0x1a0` + `FUN_0040cf90`, then refreshes both via vtbl `+0x3bc`. Returns **0** if EDI null else **1**.

Sole caller: shopveh list reindex `FUN_0083ac90` (host five-slot table at `+0x50c`).

## Signature

```c
// ESI = objA*; EDI = objB*; no stack args; RET
uint8_t ShopVehObject_SwapSelectState_ESI_EDI_Inferred(void);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0083ac90` @ `0x0083ad72` |
| Callees | `FUN_00416240` (WQ9I-H), `FUN_00416160`×2 (WQ9I-G), `FUN_0040cf90`×2, vtbl+0x1a0, vtbl+0x3bc |

## Artifacts

- Raw (+ WQ9J-D append): `docs/reconstruction/raw/aa_00833160_FUN_00833160.md`
- Annotated: `docs/reconstruction/raw/aa_00833160_FUN_00833160.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ShopVehObject_SwapSelectState_ESI_EDI_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00833160.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00833160_FUN_00833160.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ESI/EDI ABI + return 0/1 | **High** |
| Nested +0x510 three-way swap | **High** |
| Major dword offsets | **High** |
| Byte offset set | **High** |
| Byte micro-order | **Med** |
| Product class English | **Open** (caller graph only) |

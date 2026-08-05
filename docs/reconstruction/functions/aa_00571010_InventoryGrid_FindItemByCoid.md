# Function record: InventoryGrid_FindItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571010` |
| **Canonical name** | `InventoryGrid_FindItemByCoid` |
| **Address** | `0x00571010` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B present** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00571010`
- `Named_CalleeOf_Client_RecvInventoryEquip_00571010`

## Purpose

First-fit InventoryGrid list walk: return the first item whose instance COID (`+0x160` / `+0x164`) equals the caller's lo/hi dwords. Sibling of `InventoryGrid_FindItemByCbid` (`0x005710c0`) — **not** a CBID match.

## Signature

```c
// __thiscall; ret 0x08
int* __thiscall InventoryGrid_FindItemByCoid(void* grid, int coidLo, int coidHi);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00571010_FUN_00571010.md`
- Annotated: `docs/reconstruction/raw/aa_00571010_FUN_00571010.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_FindItemByCoid.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00571010.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00571010_InventoryGrid_FindItemByCoid.md`
- Review B: `docs/reconstruction/reviews/B_aa_00571010_InventoryGrid_FindItemByCoid.md`
- Residual: `docs/reconstruction/reviews/a_00571010.md`
- Contrast dual: `docs/reconstruction/reviews/A_aa_005710c0_InventoryGrid_FindItemByCbid.md`

## Callers / callees

**Callees:** `FUN_004294f0` (TraversalLock), `FUN_004022a0` (IterateNext), `LeaveCriticalSection`.

**Callers (sample):** `Client_RecvInventoryAddItem`, `Client_RecvInventoryDropResponse`, `Client_RecvInventoryEquip`, `Client_RecvInventoryUseItemResponse`, `FUN_00571830`, `FUN_00571d80`, `FUN_00571db0`, `FUN_0060d460`, inventory modify/UI paths (`00809c70`, `00809d20`, …).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| COID match at `+0x160/+0x164` | **High / Sealed** |
| List at grid `+0x2C` | **High / Sealed** |
| No capacity/Broken | **High / Sealed** |
| Canonical name | **Probable** (PDB open) |
| Runtime / bit-exact | **Open** |

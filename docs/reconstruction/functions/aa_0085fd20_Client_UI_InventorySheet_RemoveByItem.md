# Function record: Client_UI_InventorySheet_RemoveByItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd20` |
| **Canonical name** | `Client_UI_InventorySheet_RemoveByItem` |
| **Address** | `0x0085fd20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual-sealed** (A/B 2026-07-29) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred; leaf trivial) |
| **Ghidra name** | `FUN_0085fd20` |

## Purpose

Thin wrapper: `EAX=item*` → push COID `+0x164/+0x160` → `Client_UI_InventorySheet_RemoveByCoid` (`FUN_0085fcc0`). **ESI** must already be inventory sheet host*.

## Signature

```c
void Client_UI_InventorySheet_RemoveByItem(void);
// EAX = item*, ESI = sheet*
```

## Callers / callees

- Callers: `FUN_007fee30`, `FUN_00810670`, `FUN_0093d6e0`, `FUN_00944d50`
- Callee: `FUN_0085fcc0` (`Client_UI_InventorySheet_RemoveByCoid`)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0085fd20_FUN_0085fd20.md`
- Annotated: `docs/reconstruction/raw/aa_0085fd20_FUN_0085fd20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0085fd20.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md`
- Review B: `docs/reconstruction/reviews/B_aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md`
- Parent dual: `reviews/A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md`

## Confidence

| Claim | Level |
|---|---|
| 5-instruction wrapper ABI | Confirmed |

# Function record: Client_UseInventoryItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941f50` |
| **Canonical name** | `Client_UseInventoryItemByCoid` |
| **Address** | `0x00941f50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` / `skills-abilities` |
| **Completion status** | **Dual A/B complete** (WQ8R-I 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |

## Alias

- Ghidra: `FUN_00941f50`
- Prior note on Use dual: “COID→use”

## Purpose

Thin client helper: locate cargo-grid item by COID, then activate via `Client_UseInventoryItem_Inferred` (equip or skill-use **C2S 0x2045**).

WQ-008 residual: **UI/skill-adjacent inventory consumer**.

## Signature

```c
// EAX = Client*; ret 0x0C; AL bool
uint8_t Client_UseInventoryItemByCoid(uint32_t coidLo, uint32_t coidHi, uint32_t mode);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00941f50_FUN_00941f50.md`
- Annotated: `docs/reconstruction/raw/aa_00941f50_FUN_00941f50.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_UseInventoryItemByCoid.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00941f50.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00941f50_Client_UseInventoryItemByCoid.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00941f50_Client_UseInventoryItemByCoid.md`
- Function FUN alias: `docs/reconstruction/functions/aa_00941f50_FUN_00941f50.md`

## Callers / callees

| Direction | Addr | Name |
|---|---|---|
| CALL site | `0x0086152C` | orphan UI (skill-bit gated item use) |
| Callee | `0x00571010` | `InventoryGrid_FindItemByCoid` (cargo `host+0x2B0`) |
| Callee | `0x00941d50` | `Client_UseInventoryItem_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| ABI EAX-client + `ret 0x0C` | **High / Sealed** |
| Cargo path `char+0x250+0x2B0` | **High / Sealed** |
| Invalid COID / null host → 0 (not `grid&~0xff`) | **High / Sealed** |
| Tail to UseInventoryItem | **High / Sealed** |
| Name (no PDB) | **Probable** |
| Find-null safety | **Gap** |
| Runtime / bit-exact | **Open** |

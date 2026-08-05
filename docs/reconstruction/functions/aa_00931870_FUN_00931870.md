# Function record: Inventory_WriteSwapDebugLog

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931870` |
| **Canonical name** | `Inventory_WriteSwapDebugLog` |
| **Address** | `0x00931870` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00931870`
- Prior auto-slug names (if any): leave on disk; canonical is `Inventory_WriteSwapDebugLog`

## Purpose

Appends before/after cargo swap dump lines to InventoryLog.txt.

## String evidence

`"InventoryLog.txt" / "-----Before Swap-----"`

## Signature (decompiler-derived)

```c
void Inventory_WriteSwapDebugLog(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ *param_5,uint32_t /* width from decompiler */ param_6,char param_7)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00931870_FUN_00931870.md`
- Annotated: `docs/reconstruction/raw/aa_00931870_FUN_00931870.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Inventory_WriteSwapDebugLog.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00931870.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

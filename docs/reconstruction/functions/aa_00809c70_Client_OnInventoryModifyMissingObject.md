# Function record: Client_OnInventoryModifyMissingObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809c70` |
| **Canonical name** | `Client_OnInventoryModifyMissingObject` |
| **Address** | `0x00809c70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00809c70`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnInventoryModifyMissingObject`

## Purpose

Error path when modifying an object that is not present in inventory.

## String evidence

`"Tried to modify an object that isn't in inventory."`

## Signature (decompiler-derived)

```c
void __fastcall Client_OnInventoryModifyMissingObject(uint32_t /* width from decompiler */ param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00809c70_FUN_00809c70.md`
- Annotated: `docs/reconstruction/raw/aa_00809c70_FUN_00809c70.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnInventoryModifyMissingObject.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00809c70.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

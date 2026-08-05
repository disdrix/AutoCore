# Function record: Inventory_LogMissingItemAfterRandomize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bf60` |
| **Canonical name** | `Inventory_LogMissingItemAfterRandomize` |
| **Address** | `0x0093bf60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0093bf60`
- Prior auto-slug names (if any): leave on disk; canonical is `Inventory_LogMissingItemAfterRandomize`

## Purpose

Debug error when cargo/locker item missing after inventory randomization.

## String evidence

`"not found in inventory after randomization" (cargo/locker)`

## Signature (decompiler-derived)

```c
void Inventory_LogMissingItemAfterRandomize(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ *param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

                 uint32_t /* width from decompiler */ *param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ *param_12)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0093bf60_FUN_0093bf60.md`
- Annotated: `docs/reconstruction/raw/aa_0093bf60_FUN_0093bf60.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Inventory_LogMissingItemAfterRandomize.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0093bf60.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

# Function record: Client_ShowEquipFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931db0` |
| **Canonical name** | `Client_ShowEquipFailureMessage` |
| **Address** | `0x00931db0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00931db0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_ShowEquipFailureMessage`

## Purpose

Maps equip-failure reason codes to localized player messages (space/weight/tech/etc.).

## String evidence

`"There is not enough space in your inventory for this equipment."`

## Signature (decompiler-derived)

```c
void Client_ShowEquipFailureMessage(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00931db0_FUN_00931db0.md`
- Annotated: `docs/reconstruction/raw/aa_00931db0_FUN_00931db0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_ShowEquipFailureMessage.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00931db0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

# Function record: Client_OnVehicleSwitchFailure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810360` |
| **Canonical name** | `Client_OnVehicleSwitchFailure` |
| **Address** | `0x00810360` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00810360`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnVehicleSwitchFailure`

## Purpose

Vehicle chassis switch failures (inventory fit / vehicle not found).

## String evidence

`"vehicle not found in inventory" / chassis inventory fit`

## Signature (decompiler-derived)

```c
void __fastcall Client_OnVehicleSwitchFailure(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00810360_FUN_00810360.md`
- Annotated: `docs/reconstruction/raw/aa_00810360_FUN_00810360.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnVehicleSwitchFailure.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00810360.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

# Function record: Client_OnGlobalForceQuitDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_008096c0` |
| **Canonical name** | `Client_OnGlobalForceQuitDialog` |
| **Address** | `0x008096c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_008096c0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnGlobalForceQuitDialog`

## Purpose

Global disconnect / force-quit dialog: multiple logins, GM kick/ban; Accept → login screen.

## String evidence

`"You have been forced to quit due to multiple logins." / login screen`

## Signature (decompiler-derived)

```c
void __fastcall Client_OnGlobalForceQuitDialog(int param_1,char param_2,int param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008096c0_FUN_008096c0.md`
- Annotated: `docs/reconstruction/raw/aa_008096c0_FUN_008096c0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnGlobalForceQuitDialog.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_008096c0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

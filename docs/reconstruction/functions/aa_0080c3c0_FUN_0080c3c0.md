# Function record: Client_ShowLoginFailureDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080c3c0` |
| **Canonical name** | `Client_ShowLoginFailureDialog` |
| **Address** | `0x0080c3c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0080c3c0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_ShowLoginFailureDialog`

## Purpose

Shows generic login-failure dialog after auth/sector login attempt fails.

## String evidence

`"Failed to login!  Please try again in a moment."`

## Signature (decompiler-derived)

```c
void Client_ShowLoginFailureDialog(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080c3c0_FUN_0080c3c0.md`
- Annotated: `docs/reconstruction/raw/aa_0080c3c0_FUN_0080c3c0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_ShowLoginFailureDialog.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0080c3c0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

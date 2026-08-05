# Function record: Client_OnAuthDisconnected

| Field | Value |
|---|---|
| **Stable ID** | `aa_008221e0` |
| **Canonical name** | `Client_OnAuthDisconnected` |
| **Address** | `0x008221e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_008221e0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnAuthDisconnected`

## Purpose

Auth OnDisconnected path - surfaces login-failure toast/dialog.

## String evidence

`"OnDisconnected" / "Failed to login!"`

## Signature (decompiler-derived)

```c
void __fastcall Client_OnAuthDisconnected(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008221e0_FUN_008221e0.md`
- Annotated: `docs/reconstruction/raw/aa_008221e0_FUN_008221e0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnAuthDisconnected.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_008221e0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

# Function record: AuthClient_OnAccountKicked

| Field | Value |
|---|---|
| **Stable ID** | `aa_007284b0` |
| **Canonical name** | `AuthClient_OnAccountKicked` |
| **Address** | `0x007284b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_007284b0`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnAccountKicked`

## Purpose

Inbound AuthServer AccountKicked handler - account forcibly kicked.

## String evidence

`FUN_00727b70("AccountKicked","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_OnAccountKicked(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007284b0_FUN_007284b0.md`
- Annotated: `docs/reconstruction/raw/aa_007284b0_FUN_007284b0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnAccountKicked.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_007284b0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

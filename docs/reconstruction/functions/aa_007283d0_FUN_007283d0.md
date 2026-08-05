# Function record: AuthClient_OnBlockedAccount

| Field | Value |
|---|---|
| **Stable ID** | `aa_007283d0` |
| **Canonical name** | `AuthClient_OnBlockedAccount` |
| **Address** | `0x007283d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_007283d0`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnBlockedAccount`

## Purpose

Inbound AuthServer BlockedAccount handler - account blocked.

## String evidence

`FUN_00727b70("BlockedAccount","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_OnBlockedAccount(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007283d0_FUN_007283d0.md`
- Annotated: `docs/reconstruction/raw/aa_007283d0_FUN_007283d0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnBlockedAccount.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_007283d0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

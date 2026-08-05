# Function record: AuthClient_OnOpenedTcpConnection

| Field | Value |
|---|---|
| **Stable ID** | `aa_00729200` |
| **Canonical name** | `AuthClient_OnOpenedTcpConnection` |
| **Address** | `0x00729200` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00729200`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnOpenedTcpConnection`

## Purpose

Auth TCP open path - traces '[Opened TCP Connection]'.

## String evidence

`"[Opened TCP Connection]","AuthServer"`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __fastcall AuthClient_OnOpenedTcpConnection(uint32_t /* width from decompiler */ param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00729200_FUN_00729200.md`
- Annotated: `docs/reconstruction/raw/aa_00729200_FUN_00729200.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnOpenedTcpConnection.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00729200.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

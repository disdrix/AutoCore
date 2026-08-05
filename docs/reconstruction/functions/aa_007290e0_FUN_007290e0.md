# Function record: AuthClient_CloseTcpConnection

| Field | Value |
|---|---|
| **Stable ID** | `aa_007290e0` |
| **Canonical name** | `AuthClient_CloseTcpConnection` |
| **Address** | `0x007290e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_007290e0`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_CloseTcpConnection`

## Purpose

Closes Auth TCP connection and traces '[Closing TCP Connection]'.

## String evidence

`"[Closing TCP Connection]","AuthServer"`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_CloseTcpConnection(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007290e0_FUN_007290e0.md`
- Annotated: `docs/reconstruction/raw/aa_007290e0_FUN_007290e0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_CloseTcpConnection.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_007290e0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

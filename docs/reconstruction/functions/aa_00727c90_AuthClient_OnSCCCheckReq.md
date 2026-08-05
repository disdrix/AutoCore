# Function record: AuthClient_OnSCCCheckReq

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727c90` |
| **Canonical name** | `AuthClient_OnSCCCheckReq` |
| **Address** | `0x00727c90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00727c90`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnSCCCheckReq`

## Purpose

Inbound AuthServer SCCCheckReq handler - logs message type and dispatches callback.

## String evidence

`FUN_00727b70("SCCCheckReq","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_OnSCCCheckReq(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00727c90_FUN_00727c90.md`
- Annotated: `docs/reconstruction/raw/aa_00727c90_FUN_00727c90.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnSCCCheckReq.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00727c90.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

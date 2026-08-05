# Function record: AuthClient_SendLoginInsecure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728c20` |
| **Canonical name** | `AuthClient_SendLoginInsecure` |
| **Address** | `0x00728c20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00728c20`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_SendLoginInsecure`

## Purpose

Outbound AuthServer LoginInsecure - username/password login; path cites AuthClientImpl.cpp.

## String evidence

`LoginInsecure / AuthClientImpl.cpp / "username string too long"`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_SendLoginInsecure(int param_1,char *param_2,char *param_3,uint32_t /* width from decompiler */ param_4,int param_5)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00728c20_FUN_00728c20.md`
- Annotated: `docs/reconstruction/raw/aa_00728c20_FUN_00728c20.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_SendLoginInsecure.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00728c20.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

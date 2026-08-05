# Function record: Client_OnServerConnectionTerminated

| Field | Value |
|---|---|
| **Stable ID** | `aa_00812de0` |
| **Canonical name** | `Client_OnServerConnectionTerminated` |
| **Address** | `0x00812de0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00812de0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnServerConnectionTerminated`

## Purpose

Server connection terminated / GM force-quit path; Accept returns to login screen.

## String evidence

`"Connection to server terminated" / "return to the login screen"`

## Signature (decompiler-derived)

```c
void __thiscall Client_OnServerConnectionTerminated(int param_1,int param_2,char param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00812de0_FUN_00812de0.md`
- Annotated: `docs/reconstruction/raw/aa_00812de0_FUN_00812de0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnServerConnectionTerminated.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00812de0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

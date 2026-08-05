# Function record: Client_OnBadCharacterLoginId

| Field | Value |
|---|---|
| **Stable ID** | `aa_009494c0` |
| **Canonical name** | `Client_OnBadCharacterLoginId` |
| **Address** | `0x009494c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_009494c0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnBadCharacterLoginId`

## Purpose

Rejects play/login when character ID is invalid.

## String evidence

`"Bad character ID on attempted login."`

## Signature (decompiler-derived)

```c
void __fastcall Client_OnBadCharacterLoginId(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009494c0_FUN_009494c0.md`
- Annotated: `docs/reconstruction/raw/aa_009494c0_FUN_009494c0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnBadCharacterLoginId.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_009494c0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |

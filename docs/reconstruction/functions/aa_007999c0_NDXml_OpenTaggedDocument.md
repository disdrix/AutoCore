# Function record: NDXml_OpenTaggedDocument

| Field | Value |
|---|---|
| **Stable ID** | `aa_007999c0` |
| **Canonical name** | `NDXml_OpenTaggedDocument` |
| **Address** | `0x007999c0`–`0x00799ae0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NDXml / MSXML open (UI + SpecialFX + related) |
| **Completion status** | **Dual A/B done** — ABI/CF/fields sealed; COM method names gapped |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |
| **Dual A** | `docs/reconstruction/reviews/A_aa_007999c0_NDXml_OpenTaggedDocument.md` |
| **Dual B** | `docs/reconstruction/reviews/B_aa_007999c0_NDXml_OpenTaggedDocument.md` |

## Purpose

Copy `pszPath` into owned storage at `this+0x10`, load the MSXML document via `NDXml_LoadDocumentFromPath` (singleton loader + `this+0x04` doc), convert optional `pszTag` to BSTR, bind via doc vtable `+0xdc` into `this+0x08`, read count via bound iface vtable `+0x20` into `this+0x0c`. Return **0** on success, **1** if load fails or count `< 1`.

## Signature (sealed)

```c
int __thiscall NDXml_OpenTaggedDocument(void *this, char *pszPath, char *pszTag /* nullable */);
// RET 8; EAX = 0 success, 1 failure (or COM hr until empty-count forces 1)
```

## Layout (fields this unit touches)

| Off | Role |
|---|---|
| `+0x04` | MSXML document pointer |
| `+0x08` | Bound node/list interface (out) |
| `+0x0c` | Child/count int (out) |
| `+0x10` | Owned path `char*` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007999c0_NDXml_OpenTaggedDocument.md`
- Annotated: `docs/reconstruction/raw/aa_007999c0_NDXml_OpenTaggedDocument.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDXml_OpenTaggedDocument.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_007999c0_*` / `B_aa_007999c0_*`

## Callers / callees

**Callees:** `FUN_007b6a20`, `NDXml_LoadDocumentFromPath` (`0x007b6c70`), `operator_new[]` / `operator_delete[]`, `FUN_004234e0` (ANSI→BSTR), `FUN_004048e0` (OOM throw), `SysFreeString`.

**Callers (6):** `NDUIWindow_InitFromInterfaceXml`, `NDSpecialFX_LoadFromScriptName`, `FUN_004a6390`, `FUN_004a6670`, `FUN_00547920`, `FUN_005abba0`.

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + path + tag + RET 8 | **High** |
| Control flow / return 0 vs 1 | **High** |
| Field offsets +0x04/+0x08/+0x0c/+0x10 | **High** |
| COM IDL method names at +0xdc / +0x20 | **Tentative** |
| Parameter semantic names path/tag | **High** (literals `"XML"`, `"NDSpecialFX"`) |

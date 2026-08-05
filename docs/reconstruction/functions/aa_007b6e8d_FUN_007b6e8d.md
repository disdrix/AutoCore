# Function record: FUN_007b6e8d (scaffold)

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6e8d` |
| **Canonical name** | `NDXml_FinishLoadResult` (prefer named record) |
| **Ghidra name** | `FUN_007b6e8d` |
| **Address** | `0x007b6e8d` |
| **Body range** | `0x007b6e8d`–`0x007b6f81` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-xml / MSXML load epilogue |
| **Completion status** | **partial** — dual A/B **accept** (W19-S) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Canonical: `NDXml_FinishLoadResult`
- String residual: `Named_Failed_load_XML_file_failed_code`

## Purpose

See named record `aa_007b6e8d_NDXml_FinishLoadResult.md`.

## Signature

```c
bool FUN_007b6e8d(void);  // parent EBP + ESI=HRESULT; ret 8
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_007b6e8d_NDXml_FinishLoadResult.md`
- Raw / annotated / clean / reviews — see named record

## Confidence

| Claim | Level |
|---|---|
| Control flow + fail-log ESI from bytes | **High** |
| Outlined epilogue of LoadDocumentFromPath | **High** |

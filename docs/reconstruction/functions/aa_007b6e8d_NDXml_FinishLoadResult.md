# Function record: NDXml_FinishLoadResult

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6e8d` |
| **Canonical name** | `NDXml_FinishLoadResult` |
| **Ghidra name** | `FUN_007b6e8d` |
| **Address** | `0x007b6e8d` |
| **Body range** | `0x007b6e8d`–`0x007b6f81` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-xml / MSXML load epilogue |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes (incl. HRESULT log arg) sealed; product symbol open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_007b6e8d_NDXml_FinishLoadResult.md`, `reviews/B_aa_007b6e8d_NDXml_FinishLoadResult.md` |
| **Last reviewed** | `2026-07-29` (W19-S) |

## Alias

- `FUN_007b6e8d` (Ghidra)
- plate residual `Named_Failed_load_XML_file_failed_code` (string-derived)

## Purpose

**Outlined epilogue** of `NDXml_LoadDocumentFromPath`: log failed HRESULT loads, dump `IXMLDOMParseError` when `VARIANT_BOOL != VARIANT_TRUE`, free BSTRs, Release error object, restore SEH `ExceptionList`, return success bool, **`ret 8`** to grand-caller.

## Signature

```c
// Uses parent EBP frame; ESI = HRESULT; returns bool in AL; ret 8
bool NDXml_FinishLoadResult(void);
```

## Algorithm

1. SEH state `[ebp-4] = 0`.
2. If `ESI < 0`: log fail with path + **HRESULT (ESI)**.
3. SEH state = `-1`.
4. If `VARIANT_BOOL [ebp-0x28] != -1`: `get_parseError` → dump url/line/linepos/reason → free → Release → restore ExceptionList → **false**.
5. Else restore ExceptionList → **return ESI ≥ 0**.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b6e8d_FUN_007b6e8d.md`
- Annotated: `docs/reconstruction/raw/aa_007b6e8d_FUN_007b6e8d.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDXml_FinishLoadResult.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_007b6e8d.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00439a80-007b6e8d-w19s-report.md`
- Parent: `NDXml_LoadDocumentFromPath` (`aa_007b6c70`)

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_007a4480`, `SysFreeString`×2, COM vcalls |
| **Callers** | sole: `NDXml_LoadDocumentFromPath` @ `0x007b6e6f` |

## Confidence

| Claim | Level |
|---|---|
| Outlined load epilogue / sole caller | **High** |
| Fail log includes ESI as `%d` (bytes) | **High** |
| VARIANT_TRUE gate + parseError dump | **High** |
| Dual-interface parseError slots | **High** |
| `ret 8` grand-caller return | **High** |
| Product/PDB symbol | Open |

## Related

- `aa_007b6c70` NDXml_LoadDocumentFromPath
- `aa_00423ac0` NDResource_LoadByKey
- `aa_007a4480` client log helper

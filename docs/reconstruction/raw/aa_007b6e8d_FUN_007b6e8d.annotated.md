# Annotated low-level: FUN_007b6e8d / NDXml_FinishLoadResult

| Field | Value |
|---|---|
| Stable ID | `aa_007b6e8d` |
| VA | `0x007b6e8d` |
| Body range | `0x007b6e8d`–`0x007b6f81` |
| System | client-xml / MSXML load epilogue |
| Date | 2026-07-23 scaffold; W19-S dual seal 2026-07-29 |
| Canonical name | `NDXml_FinishLoadResult` (structural) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` (W19-S).
- **Outlined epilogue** of `NDXml_LoadDocumentFromPath` (`0x007b6c70`): sole CODE xref CALL from `0x007b6e6f`.
- Uses **caller EBP frame** (no `push ebp` at entry). Entry starts `test esi,esi`.
- **Inputs (register + parent frame):**
  - **ESI** = HRESULT from `IXMLDOMDocument::load` (or prior fail path)
  - **EBP+8** = `IXMLDOMDocument*` (slot reused as url BSTR after get_url)
  - **EBP+0xc** = `char* pszPath`
  - **EBP-0x28** = `VARIANT_BOOL` out from `load` (`-1` = `VARIANT_TRUE`)
  - **EBP-4** = SEH state (0 then `0xffffffff`)
  - **EBP-0xc** = saved `ExceptionList`
- **Epilogue:** restore `ExceptionList`; **`ret 8`** — pops parent thiscall's two stack args (`pXmlDom`, `pszPath`) and returns to **grand-caller**.
- Decompiler **missed** `push ESI` for fail log `%d`; sealed by entry bytes:
  ```
  85 f6                test esi,esi
  c7 45 fc 00 00 00 00 mov dword [ebp-4], 0
  7d 14                jge  +0x14
  8b 55 0c             mov edx, [ebp+0xc]   ; path
  56                   push esi             ; HRESULT  ← not in decomp
  52                   push edx             ; path
  68 f0 5e a9 00       push "Failed to load XML file %s, failed with code %d"
  6a 01                push 1
  e8 …                 call FUN_007a4480
  83 c4 10             add esp, 16
  ```
- MSXML dual-interface `IXMLDOMParseError` (IUnknown+IDispatch):
  - `+0x20` get_url → BSTR
  - `+0x24` get_reason → BSTR
  - `+0x2c` get_line → long
  - `+0x30` get_linepos → long
  - `+8` Release
- Document `vtbl+0xf0` = `get_parseError`.

## Pseudocode (annotated)

```c
// bool NDXml_FinishLoadResult(void)
// ESI = HRESULT; EBP = NDXml_LoadDocumentFromPath frame
// returns AL; ret 8

bool FUN_007b6e8d(void)
{
  *(undefined4 *)(unaff_EBP + -4) = 0;           // SEH state
  if (unaff_ESI < 0) {
    // BYTES: log(1, fmt, path, hr=ESI)  — decomp omitted ESI
    FUN_007a4480(1,
      "Failed to load XML file %s, failed with code %d",
      *(undefined4 *)(unaff_EBP + 0xc) /*, unaff_ESI */);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;

  if (*(short *)(unaff_EBP + -0x28) != -1) {     // VARIANT_BOOL != VARIANT_TRUE
    // get_parseError on document at EBP+8
    iVar1 = **(int **)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    (**(code **)(iVar1 + 0xf0))(*(int **)(unaff_EBP + 8), unaff_EBP + -0x14);
    piVar2 = *(int **)(unaff_EBP + -0x14);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;        // reuse slot for url BSTR
      (**(code **)(*piVar2 + 0x20))(piVar2, unaff_EBP + 8);          // get_url
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      (**(code **)(*piVar2 + 0x24))(piVar2, unaff_EBP + -0x20);      // get_reason
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      (**(code **)(*piVar2 + 0x2c))(piVar2, unaff_EBP + -0x1c);      // get_line
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      (**(code **)(*piVar2 + 0x30))(piVar2, unaff_EBP + -0x18);      // get_linepos
      FUN_007a4480(1, "%S(%i)(%s): pos %i, XML parse error: %S",
                   url, line, path, linepos, reason);
      SysFreeString(*(BSTR *)(unaff_EBP + 8));
      SysFreeString(*(BSTR *)(unaff_EBP + -0x20));
      (**(code **)(*piVar2 + 8))(piVar2);        // Release
    }
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return false;                                // xor al,al; ret 8
  }

  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -1 < unaff_ESI;                         // setge al (esi >= 0); ret 8
}
```

## Open questions

- Product/PDB symbol for the outlined epilogue (may be part of LoadDocumentFromPath in source).
- Whether any other tail-merge sites exist (Ghidra currently shows sole caller).
- Runtime / differential — open.

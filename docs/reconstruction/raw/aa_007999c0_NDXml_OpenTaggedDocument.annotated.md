# Annotated low-level: NDXml_OpenTaggedDocument

| Field | Value |
|---|---|
| Stable ID | `aa_007999c0` |
| VA | `0x007999c0`–`0x00799ae0` |
| System | NDXml / MSXML |
| Date | 2026-07-29 (dual A/B seal; prior scaffold 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_007999c0` + live Ghidra `decompile_function` / `read_memory` (2026-07-29).
- **ABI sealed:** `__thiscall(this, pszPath, pszTag)` — epilogue **`RET 8`**. Decompiler `param_3` is **not** a real third stack arg (SEH frame artifact).
- **this** in ECX → ESI for body; path first stack arg; tag second (nullable).
- Path ownership: `delete[]` old `this+0x10`, `new[]` `strlen+1`, strcpy.
- Load: singleton from `FUN_007b6a20`, then `NDXml_LoadDocumentFromPath(loader, this+4, path)`.
- Tag: optional ANSI→BSTR via `FUN_004234e0(tag, -1)`; OOM → `FUN_004048e0(0x8007000E)` noreturn.
- COM: `(*(doc+0))**+0xdc`(doc, bstr, &this+8); if S_OK, `(*(node))**+0x20`(node, &this+0xc).
- Empty count (`*(int*)(this+0xc) < 1`) forces return **1**.
- Prefer call-site bytes when decompiler drops args (prototype still `void`).

## Pseudocode (annotated)

```c
/* NDXml_OpenTaggedDocument
   Open file into NDXml MSXML document, bind tag, fill child count.
   Callers: NDUIWindow_InitFromInterfaceXml ("XML"),
            NDSpecialFX_* ("NDSpecialFX"), others.
*/

// SEALED ABI — ignore decompiler's unused param_3
int __thiscall NDXml_OpenTaggedDocument(void *this, char *pszPath, char *pszTag)
{
  // SEH frame (LAB_009b1404) omitted in spirit; present in raw

  // Replace owned path @ +0x10
  if (*(void **)((char *)this + 0x10) != NULL)
    operator_delete[](*(void **)((char *)this + 0x10));
  *(void **)((char *)this + 0x10) = NULL;

  // strlen + new[] + strcpy (raw uses classic end-pointer sizing)
  {
    char *p = pszPath;
    while (*p != '\0') p++;
    void *buf = operator_new[]((size_t)(p - pszPath + 1));
    *(void **)((char *)this + 0x10) = buf;
    // byte copy including NUL into buf
    char *src = pszPath;
    char *dst = (char *)buf;
    char c;
    do { c = *src++; *dst++ = c; } while (c != '\0');
  }

  void *loader = (void *)FUN_007b6a20();                 // &DAT_00d20c38 singleton
  void *pDoc   = *(void **)((char *)this + 4);
  char *path   = *(char **)((char *)this + 0x10);
  if (!NDXml_LoadDocumentFromPath(loader, pDoc, path))
    return 1;                                            // load fail

  BSTR bstr = NULL;
  if (pszTag != NULL) {
    bstr = (BSTR)FUN_004234e0(pszTag, 0xffffffff);
    if (bstr == NULL)
      FUN_004048e0(0x8007000e);                          // noreturn E_OUTOFMEMORY
  }

  // Doc method slot 0xDC/4 — bind tag → interface @ +0x08
  int hr = (**(int (***)())(*(int *)pDoc + 0xdc))(
             pDoc, bstr, (void **)((char *)this + 8));
  if (hr == 0) {
    int *pNode = *(int **)((char *)this + 8);
    // Bound iface method slot 0x20/4 — write count @ +0x0c
    hr = (**(int (***)())(*pNode + 0x20))(pNode, (int *)((char *)this + 0xc));
  }
  if (*(int *)((char *)this + 0xc) < 1)
    hr = 1;                                              // empty → fail

  SysFreeString(bstr);
  return hr;                                             // 0 success
}
```

## Open questions

- Product/IDL names for COM slots `+0xdc` / `+0x20`.
- Whether any caller requires HRESULT values other than `{0,1}`.
- Runtime confirmation.

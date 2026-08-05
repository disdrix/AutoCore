// =============================================================================
// NDXml_OpenTaggedDocument
// -----------------------------------------------------------------------------
// Stable ID: aa_007999c0
// Address:   0x007999c0 – 0x00799ae0  (autoassault.exe, image base 0x400000)
// System:    NDXml / MSXML document open (UI interfaces + SpecialFX scripts)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - ABI sealed: __thiscall(this, pszPath, pszTag), RET 8.
 *   Ghidra often prints a phantom third stack arg (param_3) from SEH — do not port it.
 * - this+0x10 owns a char[] path copy (delete[] / new[] / strcpy).
 * - Load via singleton FUN_007b6a20 + NDXml_LoadDocumentFromPath(loader, doc@+4, path).
 * - Optional tag → BSTR (FUN_004234e0); OOM throws FUN_004048e0(E_OUTOFMEMORY).
 * - Doc vtbl+0xdc(doc, bstr, &node@+8); if S_OK, node vtbl+0x20(node, &count@+0xc).
 * - count < 1 forces return 1. Load false returns 1. Success returns 0 (HRESULT S_OK path).
 * - Callers: NDUIWindow_InitFromInterfaceXml ("XML"), NDSpecialFX_* ("NDSpecialFX"), …
 *
 * Readability pass:
 * - Names path/tag preferred over param_2/param_4.
 * - Control flow and call order preserved from authoritative raw.
 */

/* NDXml_OpenTaggedDocument

   Open an XML document by file path with a tag string (e.g. "XML", "NDSpecialFX").
   Copies path into this+0x10, then NDXml_LoadDocumentFromPath.
   On success: bind tag BSTR into COM interface via document vtable+0xdc and
   query count via bound interface vtable+0x20 into this+0x0c.

   Crash chain frame: often immediately above 0x007B6DB0 (inside LoadDocumentFromPath).
   Params dump often show 0x00A9650C = "XML" for UI, or script name for FX. */

int __thiscall NDXml_OpenTaggedDocument(void *this, char *pszPath, char *pszTag)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  char *pcVar4;
  void *pvVar5;
  void *loader;
  BSTR bstrString;
  int iVar6;
  void *unaff_ESI;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b1404;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(void **)((char *)this + 0x10) != (void *)0x0) {
    ExceptionList = &pvStack_c;
    operator_delete__(*(void **)((char *)this + 0x10));
  }
  *(uint32_t *)((char *)this + 0x10) = 0;
  pcVar4 = pszPath;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  /* size = strlen(pszPath) + 1  (raw end-pointer formula preserved) */
  pvVar5 = operator_new__((uint)(pcVar4 + (2 - (int)(pszPath + 1))));
  *(void **)((char *)this + 0x10) = pvVar5;
  iVar6 = (int)pvVar5 - (int)pszPath;
  do {
    cVar1 = *pszPath;
    pszPath[iVar6] = cVar1;
    pszPath = pszPath + 1;
  } while (cVar1 != '\0');
  pcVar4 = *(char **)((char *)this + 0x10);
  pvVar5 = *(void **)((char *)this + 4);
  loader = (void *)FUN_007b6a20();
  bVar3 = NDXml_LoadDocumentFromPath(loader, pvVar5, pcVar4);
  if (bVar3) {
    if (pszTag == (char *)0x0) {
      bstrString = (BSTR)0x0;
    }
    else {
      bstrString = (BSTR)FUN_004234e0(pszTag, 0xffffffff);
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0(0x8007000e);
      }
    }
    iVar6 = (**(code **)(**(int **)((char *)this + 4) + 0xdc))
                      (*(int **)((char *)this + 4), bstrString,
                       (uint32_t *)((char *)this + 8));
    if (iVar6 == 0) {
      piVar2 = *(int **)((char *)this + 8);
      iVar6 = (**(code **)(*piVar2 + 0x20))(piVar2, (char *)this + 0xc);
    }
    if (*(int *)((char *)this + 0xc) < 1) {
      iVar6 = 1;
    }
    SysFreeString(bstrString);
    ExceptionList = unaff_ESI;
    return iVar6;
  }
  ExceptionList = puStack_8;
  return 1;
}

// =============================================================================
// NDXml_FinishLoadResult  (FUN_007b6e8d)
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6e8d
// Address:   0x007b6e8d  (autoassault.exe, image base 0x400000)
// Body:      0x007b6e8d–0x007b6f81
// System:    client-xml / MSXML load epilogue
// Generated: 2026-07-29 W19-S dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seal
//            for fail-log HRESULT arg. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Outlined epilogue of NDXml_LoadDocumentFromPath (0x007b6c70).
//   1) If HRESULT (ESI) < 0: log "Failed to load XML file %s, failed with code %d"
//      with path (EBP+0xc) and ESI (bytes; decompiler omitted second arg).
//   2) If VARIANT_BOOL (EBP-0x28) != VARIANT_TRUE (-1): get_parseError, dump
//      url/line/linepos/reason, free BSTRs, Release error, return false.
//   3) Else return (HRESULT >= 0).
//   Restores ExceptionList from [EBP-0xc]; ret 8 (cleans parent stack args).
//
// ABI: uses caller EBP frame (no local frame). ESI = HRESULT.
//      epilogue ret 8 — returns to grand-caller of LoadDocumentFromPath.
// Sole caller: NDXml_LoadDocumentFromPath @ 0x007b6e6f.
//
// COM (MSXML dual IXMLDOMParseError):
//   doc vtbl+0xf0 get_parseError
//   err +0x20 get_url, +0x24 get_reason, +0x2c get_line, +0x30 get_linepos, +8 Release
//

#include <windows.h>
#include <oleauto.h>

extern void *ExceptionList;
void FUN_007a4480(int level, const char *fmt, ...);

bool NDXml_FinishLoadResult(void)
{
  int iVar1;
  int *piVar2;
  int unaff_EBP; /* parent frame */
  int unaff_ESI; /* HRESULT */

  *(unsigned int *)(unaff_EBP - 4) = 0;
  if (unaff_ESI < 0) {
    /* read_memory seal: push ESI as %d after path */
    FUN_007a4480(1, "Failed to load XML file %s, failed with code %d",
                 *(unsigned int *)(unaff_EBP + 0xc),
                 unaff_ESI);
  }
  *(unsigned int *)(unaff_EBP - 4) = 0xffffffff;

  if (*(short *)(unaff_EBP - 0x28) != -1) {
    iVar1 = **(int **)(unaff_EBP + 8);
    *(unsigned int *)(unaff_EBP - 0x14) = 0;
    (**(int (**)(void *, void *))(iVar1 + 0xf0))(
        *(void **)(unaff_EBP + 8), (void *)(unaff_EBP - 0x14));
    piVar2 = *(int **)(unaff_EBP - 0x14);
    if (piVar2 != (int *)0) {
      *(unsigned int *)(unaff_EBP + 8) = 0;
      (**(int (**)(int *, void *))(*piVar2 + 0x20))(piVar2, (void *)(unaff_EBP + 8));
      *(unsigned int *)(unaff_EBP - 0x20) = 0;
      (**(int (**)(int *, void *))(*piVar2 + 0x24))(piVar2, (void *)(unaff_EBP - 0x20));
      *(unsigned int *)(unaff_EBP - 0x1c) = 0;
      (**(int (**)(int *, void *))(*piVar2 + 0x2c))(piVar2, (void *)(unaff_EBP - 0x1c));
      *(unsigned int *)(unaff_EBP - 0x18) = 0;
      (**(int (**)(int *, void *))(*piVar2 + 0x30))(piVar2, (void *)(unaff_EBP - 0x18));
      FUN_007a4480(1, "%S(%i)(%s): pos %i, XML parse error: %S",
                   *(unsigned int *)(unaff_EBP + 8),
                   *(unsigned int *)(unaff_EBP - 0x1c),
                   *(unsigned int *)(unaff_EBP + 0xc),
                   *(unsigned int *)(unaff_EBP - 0x18),
                   *(unsigned int *)(unaff_EBP - 0x20));
      SysFreeString(*(BSTR *)(unaff_EBP + 8));
      SysFreeString(*(BSTR *)(unaff_EBP - 0x20));
      (**(int (**)(int *))(*piVar2 + 8))(piVar2);
    }
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    return false;
  }

  ExceptionList = *(void **)(unaff_EBP - 0xc);
  return -1 < unaff_ESI;
}

// Ghidra alias
bool FUN_007b6e8d(void)
{
  return NDXml_FinishLoadResult();
}

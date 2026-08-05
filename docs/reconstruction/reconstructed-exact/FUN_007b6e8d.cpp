// =============================================================================
// FUN_007b6e8d  (scaffold alias → NDXml_FinishLoadResult)
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6e8d
// Address:   0x007b6e8d  (autoassault.exe, image base 0x400000)
// Body:      0x007b6e8d–0x007b6f81
// System:    client-xml / MSXML load epilogue
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W19-S)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seal for ESI log arg.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Authoritative named clean: NDXml_FinishLoadResult.cpp
// Strings: "Failed to load XML file %s, failed with code %d"
//          "%S(%i)(%s): pos %i, XML parse error: %S"

#include <windows.h>
#include <oleauto.h>

extern void *ExceptionList;
void FUN_007a4480(int level, const char *fmt, ...);

bool FUN_007b6e8d(void)
{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  int unaff_ESI;

  *(unsigned int *)(unaff_EBP - 4) = 0;
  if (unaff_ESI < 0) {
    /* bytes: push ESI for %d (decompiler residual omitted it) */
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

// =============================================================================
// FUN_00421677
// -----------------------------------------------------------------------------
// Stable ID: aa_00421677
// Address:   0x00421677–0x00421732  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB accessor finalize
// Generated: 2026-07-29 W22-N dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named twin: OleDb_RowBufZeroAndCreateAccessor_Inferred.cpp
// =============================================================================

// PURPOSE:
//   Null-check ctx row buffer; on fail return E_OUTOFMEMORY after cleanup.
//   Else zero-fill row buffer, call FUN_00422830 (CreateAccessor+free binds),
//   free temp bindings, free aux on failed HRESULT, Release COM, return hr.
//
// ABI notes:
//   Ghidra decompiler: int FUN_00421677(void) with unaff_EBX / unaff_EBP.
//   Bytes: ret 4; pre-entry 0x00421674 mov ebx,[ebp+8].
//   E_OUTOFMEMORY = 0x8007000E (decompiler -0x7ff8fff2).

#include <cstdint>

extern "C" int FUN_00422830(uint32_t a0, uint32_t sizeHint);
extern "C" void operator_delete__(void* p);
extern void* ExceptionList;

int FUN_00421677(void)
{
  void *pvVar1;
  int *piVar2;
  uint32_t uVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t *unaff_EBX; // ctx*
  int unaff_EBP;      // parent frame
  uint32_t *puVar6;

  pvVar1 = *(void **)(unaff_EBP + -0x1c);
  if ((uint32_t *)unaff_EBX[2] == (uint32_t *)0x0) {
    operator_delete__(pvVar1);
    operator_delete__((void *)unaff_EBX[4]);
    *(uint32_t *)(unaff_EBP + -4) = 0xffffffff;
    piVar2 = *(int **)(unaff_EBP + -0x18);
    unaff_EBX[4] = 0;
    if (piVar2 != (int *)0x0) {
      (**(void (**)(int *))(*piVar2 + 8))(piVar2);
    }
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return (int)0x8007000E; // E_OUTOFMEMORY (raw: -0x7ff8fff2)
  }
  uVar3 = *(uint32_t *)(unaff_EBP + -0x24);
  puVar6 = (uint32_t *)unaff_EBX[2];
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (uVar5 = uVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(uint8_t *)puVar6 = 0;
    puVar6 = (uint32_t *)((int)puVar6 + 1);
  }
  // Decompiler collapses custom ABI of FUN_00422830; see annotated bytes.
  iVar4 = FUN_00422830(*unaff_EBX, uVar3);
  operator_delete__(pvVar1);
  if (iVar4 < 0) {
    operator_delete__((void *)unaff_EBX[4]);
    unaff_EBX[4] = 0;
  }
  *(uint32_t *)(unaff_EBP + -4) = 0xffffffff;
  piVar2 = *(int **)(unaff_EBP + -0x18);
  if (piVar2 != (int *)0x0) {
    (**(void (**)(int *))(*piVar2 + 8))(piVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

// =============================================================================
// FUN_00414c20  (scaffold twin of GfxVBHolder_ReplaceAndAllocate)
// -----------------------------------------------------------------------------
// Stable ID: aa_00414c20
// Address:   0x00414c20  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxVertexBufferImpl
// Dual A/B:  accept (2026-07-29 W21-L)
// Canonical: GfxVBHolder_ReplaceAndAllocate.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern int __fastcall FUN_00414cd0(void *freelist_head);
extern void *__thiscall FUN_00999960(void *node);
extern int __thiscall FUN_0099a8e0(void *vb_this, uint32_t a, uint32_t b,
                                   uint32_t c, uint32_t d);
extern void *DAT_00d218e0;
extern void *ExceptionList;
extern unsigned char LAB_009bf04b[];

/* Decompiler shows void; sealed return is allocate status in EAX. */
int __thiscall
FUN_00414c20(void *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
             uint32_t param_5)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = LAB_009bf04b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;

  /* Bytes: mov ecx, DAT_00d218e0; call FUN_00414cd0 */
  iVar3 = FUN_00414cd0(&DAT_00d218e0);
  local_4 = 0;
  if (iVar3 == 0) {
    piVar4 = (int *)0x0;
  } else {
    piVar4 = (int *)FUN_00999960((void *)iVar3);
  }
  local_4 = 0xffffffff;
  if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {
    (**(void (__thiscall ***)(int *))(*piVar4 + 4))(piVar4);
  }
  piVar2 = *(int **)((uint8_t *)param_1 + 4);
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void (__thiscall ***)(int *))(*piVar2 + 8))(piVar2);
    }
  }
  *(int **)((uint8_t *)param_1 + 4) = piVar4;
  {
    int status = FUN_0099a8e0(piVar4, param_2, param_3, param_4, param_5);
    ExceptionList = pvStack_c;
    return status;
  }
}

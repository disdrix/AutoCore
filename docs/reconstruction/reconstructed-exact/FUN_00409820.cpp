// =============================================================================
// FUN_00409820  (named: StdTree_Predecessor_Isnil29_Edx_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409820
// Address:   0x00409820–0x00409870 inclusive (81 B / 0x51)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared client::stdtree predecessor (isnil@+0x29, EDX ABI)
// Generated: 2026-08-05 WQ9J-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Prefer: StdTree_Predecessor_Isnil29_Edx_Inferred.cpp

#include <stdint.h>

// EDX = node**; ECX unused; void; bare RET.
void __fastcall FUN_00409820(uint32_t /*ecx unused*/, int* param_2 /*EDX*/)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int* piVar4;

  piVar4 = (int*)*param_2;
  if (*(char*)((int)piVar4 + 0x29) != '\0') {
    *param_2 = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char*)(iVar2 + 0x29) == '\0') {
    cVar1 = *(char*)(*(int*)(iVar2 + 8) + 0x29);
    iVar3 = *(int*)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char*)(*(int*)(iVar3 + 8) + 0x29);
      iVar2 = iVar3;
      iVar3 = *(int*)(iVar3 + 8);
    }
    *param_2 = iVar2;
    return;
  }
  piVar4 = (int*)piVar4[1];
  if (*(char*)((int)piVar4 + 0x29) == '\0') {
    do {
      if (*param_2 != *piVar4) break;
      *param_2 = (int)piVar4;
      piVar4 = (int*)piVar4[1];
    } while (*(char*)((int)piVar4 + 0x29) == '\0');
    if (*(char*)((int)piVar4 + 0x29) == '\0') {
      *param_2 = (int)piVar4;
    }
  }
  return;
}

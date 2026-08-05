// Twin of MatRegistry_FindCompatibleMaterial_Inferred.cpp (aa_0073d940 / FUN_0073d940).
// See MatRegistry_FindCompatibleMaterial_Inferred.cpp for sealed clean body (W37-X).

#include <cstdint>

extern "C" char FUN_00752590(/*EAX*/ void*, /*EDX*/ void*);

extern "C" int __thiscall FUN_0073d940(int param_1, int param_2)
{
  int iVar1;
  char cVar2;
  int* piVar3;
  int* piVar4;

  if ((param_2 != 0) && (*(int*)(param_2 + 8) != 0)) {
    for (piVar3 = *(int**)(param_1 + 4); piVar3 != *(int**)(param_1 + 8); piVar3 = piVar3 + 5) {
      if (*piVar3 == *(int*)(param_2 + 8)) {
        piVar4 = (int*)piVar3[2];
        piVar3 = (int*)piVar3[3];
        if (piVar4 == piVar3) {
          return 0;
        }
        while ((iVar1 = *piVar4, iVar1 == param_2 || (cVar2 = FUN_00752590(), cVar2 == '\0'))) {
          piVar4 = piVar4 + 1;
          if (piVar4 == piVar3) {
            return 0;
          }
        }
        return iVar1;
      }
    }
  }
  return 0;
}

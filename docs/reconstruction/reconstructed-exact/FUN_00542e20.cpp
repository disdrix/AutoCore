// =============================================================================
// FUN_00542e20  (canonical: Host_DrainPendingNfxEventQueue_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00542e20
// Address:   0x00542e20–0x00543050  (autoassault.exe, image base 0x400000)
// System:    host pending NFX / special-FX event queue
// Wave:      W35-F OWN-ONLY dual 2026-07-29
// Exactness: Decompiler CF + sealed ABI from read_memory. Not bit-exact.
// =============================================================================
// ABI: ECX=host; stack arg cleaned by RET 4 (caller pushes session field).
// Named clean: Host_DrainPendingNfxEventQueue_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" char FUN_004ed310(int ring, char* flag, uint32_t* cursor);
extern "C" int FUN_004a16d0(uint32_t skillOrKey, int a, int b);
extern "C" int* Object_ResolveFromTFID(void* tfid16);
extern "C" void FUN_00545500(void);
extern "C" uint32_t FUN_004a6390(char* pathStem);
extern "C" void FUN_0043d650(uint32_t new_size);
extern "C" void FUN_004a04f0(int tree, int a, int b, int c);
extern "C" void FUN_00971820(int ring);
extern "C" void operator_delete(void* p);
extern char* PTR_DAT_00afa2bc;

// Decompiler-faithful body with fixed-width types.
// Bytes: MOV EBX,ECX; RET 4. Stack formal unused in decompile.

void FUN_00542e20(int param_1 /*ECX host*/, void* /*sessionField stack*/) {
  int iVar1;
  char cVar2;
  uint32_t uVar3;
  char* pcVar4;
  int* piVar5;
  void* pvVar6;
  int iVar7;
  char local_104[260];

  if (*reinterpret_cast<int*>(param_1 + 0xf2c) != 0) {
    while (true) {
      iVar1 = **reinterpret_cast<int**>(param_1 + 0xf28);
      cVar2 = FUN_004ed310(iVar1 + 0x44, reinterpret_cast<char*>(iVar1 + 0x40),
                           reinterpret_cast<uint32_t*>(iVar1 + 0x3c));
      if (cVar2 == '\0') break;

      iVar7 = *reinterpret_cast<int*>(
          *reinterpret_cast<int*>(
              *reinterpret_cast<int*>(param_1 + 0xf0c) + 0x10) +
          ((*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(param_1 + 0xf0c) + 8) &
            *reinterpret_cast<uint32_t*>(iVar1 + 0x2c)) *
           4) +
          4);

      if (iVar7 == 0) {
      LAB_00542ea4:
        iVar7 = 0;
      } else {
        do {
          if (*reinterpret_cast<uint32_t*>(iVar1 + 0x2c) ==
              *reinterpret_cast<uint32_t*>(iVar7 + 0x10)) {
            if (iVar7 == 0) goto LAB_00542ea4;
            iVar7 = *reinterpret_cast<int*>(iVar7 + 8);
            goto LAB_00542eab;
          }
          iVar7 = *reinterpret_cast<int*>(iVar7 + 0xc);
        } while (iVar7 != 0);
        iVar7 = 0;
      }
    LAB_00542eab:
      if (iVar7 == 0) {
      LAB_00542f7b:
        piVar5 = *reinterpret_cast<int**>(*reinterpret_cast<int**>(param_1 + 0xf28));
        if (piVar5 != *reinterpret_cast<int**>(param_1 + 0xf28)) {
          *reinterpret_cast<int*>(piVar5[1]) = *piVar5;
          *reinterpret_cast<int*>(*piVar5 + 4) = piVar5[1];
        LAB_00542ffc:
          FUN_00545500();
          operator_delete(piVar5);
        }
      } else if (*reinterpret_cast<char*>(iVar1 + 0x58) == '\0') {
        iVar7 = FUN_004a16d0(*reinterpret_cast<uint32_t*>(iVar1 + 0x28), 1, -1);
        if (iVar7 == 0) goto LAB_00542f7b;
        piVar5 = Object_ResolveFromTFID(reinterpret_cast<void*>(iVar1 + 0x18));
        pvVar6 = Object_ResolveFromTFID(reinterpret_cast<void*>(iVar1 + 8));
        if (piVar5 != nullptr) {
          (**(void(**)(uint32_t, uint32_t, uint32_t, uint32_t, void*, uint32_t, int, int))(
              *piVar5 + 0x238))(
              *reinterpret_cast<uint32_t*>(iVar1 + 0x28),
              *reinterpret_cast<uint32_t*>(iVar1 + 0x2c),
              *reinterpret_cast<uint32_t*>(iVar1 + 0x30),
              *reinterpret_cast<uint32_t*>(iVar1 + 0x34), pvVar6,
              *reinterpret_cast<uint32_t*>(iVar1 + 0x38), 1, iVar7);
        }
        piVar5 = *reinterpret_cast<int**>(*reinterpret_cast<int**>(param_1 + 0xf28));
        if (piVar5 != *reinterpret_cast<int**>(param_1 + 0xf28)) {
          *reinterpret_cast<int*>(piVar5[1]) = *piVar5;
          *reinterpret_cast<int*>(*piVar5 + 4) = piVar5[1];
          goto LAB_00542ffc;
        }
      } else {
        if ((*reinterpret_cast<char*>(iVar7 + 10) == '\0') &&
            (*reinterpret_cast<int*>(iVar1 + 0x54) != 0)) {
          uVar3 = *reinterpret_cast<uint32_t*>(iVar1 + 0x50) >> 2;
          iVar7 = static_cast<int>(uVar3) * -4;
          if (*reinterpret_cast<uint32_t*>(iVar1 + 0x4c) <= uVar3) {
            uVar3 = uVar3 - *reinterpret_cast<uint32_t*>(iVar1 + 0x4c);
          }
          pcVar4 = *reinterpret_cast<char**>(
              *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar1 + 0x48) + uVar3 * 4) +
              (*reinterpret_cast<uint32_t*>(iVar1 + 0x50) + iVar7) * 4);
          if (pcVar4 == nullptr) {
            pcVar4 = PTR_DAT_00afa2bc;
          }
          iVar7 = -static_cast<int>(reinterpret_cast<intptr_t>(pcVar4));
          do {
            cVar2 = *pcVar4;
            pcVar4[reinterpret_cast<int>(local_104) + iVar7] = cVar2;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          pcVar4 = std::strstr(local_104, "_nfx.xml");
          if (pcVar4 != nullptr) {
            *pcVar4 = '\0';
            FUN_004a6390(local_104);
          }
        }
        *reinterpret_cast<uint8_t*>(iVar1 + 0x58) = 0;
        FUN_0043d650(0);
        *reinterpret_cast<uint32_t*>(iVar1 + 0x3c) = 0;
        *reinterpret_cast<uint8_t*>(iVar1 + 0x40) = 0;
        FUN_004a04f0(iVar1 + 0x44, 1, 1, 1);
      }
      if (*reinterpret_cast<int*>(param_1 + 0xf2c) == 0) {
        return;
      }
    }
    if (*reinterpret_cast<char*>(iVar1 + 0x40) == '\0') {
      FUN_00971820(iVar1 + 0x44);
    }
  }
}

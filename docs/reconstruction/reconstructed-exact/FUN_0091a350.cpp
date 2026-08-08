// =============================================================================
// FUN_0091a350  (machine-name twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_0091a350
// Address:   0x0091a350–0x0091a54a inclusive (507 B / 0x1FB)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-033 dual A/B seal
// Canonical: Client_InteractWorldClick_SoftCastAlt_Inferred
// See:       reconstructed-exact/Client_InteractWorldClick_SoftCastAlt_Inferred.cpp
// =============================================================================

#include <cstdint>

extern float DAT_00aaa668;
extern int*  DAT_00d1b6d8;
extern int*  DAT_00d17944;
extern char  DAT_00d1a840;
extern float DAT_00afdfc8, DAT_00afdfcc, DAT_00afdfd0;
extern float DAT_00afdfd4, DAT_00afdfd8, DAT_00afdfdc;
extern float DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8;

extern void __thiscall Ui_ResolveEntityNameColor_Inferred(
    void* entity, void* clientCtx, uint32_t* outArgb, char a, char b);

extern int* __thiscall FUN_007a0120(
    int, int, uint8_t, int, uint32_t, float,
    int, int, int, int, int, int, int,
    int, float, float, float, float, float,
    float, float, float, float, float,
    float, float, int, int, int, uint8_t);

// Retail ESI = client*; decompiler: unaff_ESI / void.
uint8_t FUN_0091a350(int* client /* ESI */)
{
  int iVar1;
  char cVar2;
  uint8_t auStack_14[16];

  cVar2 = ((char(__thiscall*)(void*))(*(int*)(*client + 0x3d8)))(client);
  if (cVar2 != '\0') {
    client[0x156] = *(int*)&DAT_00aaa668; // +0x558 = -1.0f
    *((uint8_t*)client + 0xa32) = 0;
    ((void(__thiscall*)(void*))(*(int*)(*client + 0x478)))(client);

    if (client[0x1d6] != 0) {
      Ui_ResolveEntityNameColor_Inferred(
          (void*)client[0x1d6], &DAT_00d1a840, (uint32_t*)auStack_14, 0, 0);
    }

    if ((DAT_00d1b6d8 != nullptr) &&
        (iVar1 = *(int*)((uint8_t*)DAT_00d1b6d8 + 0x250), iVar1 != 0) &&
        (*(char*)(iVar1 + 0x106) != '\0')) {
      *(uint8_t*)(iVar1 + 0x107) = 0;
      iVar1 = *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 0x250) + 0x284);
      if (iVar1 != 0) {
        (void)DAT_00d17944; // ECX load at call site
        FUN_007a0120(
            0, 2, 8, 0x61, 0,
            *(float*)((uint8_t*)client + 0x548),
            0x3ecccccd, 0x3f800000,
            *(int*)(iVar1 + 0x68), *(int*)(iVar1 + 0x68), 0x40400000,
            (int)0xffffffff, 0,
            *(int*)(iVar1 + 0x30), *(int*)(iVar1 + 0x34), *(int*)(iVar1 + 0x38),
            *(int*)(iVar1 + 0x30), *(int*)(iVar1 + 0x34), *(int*)(iVar1 + 0x38),
            DAT_00afdfc8, DAT_00afdfcc, DAT_00afdfd0,
            DAT_00afdfd4, DAT_00afdfd8, DAT_00afdfdc,
            DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8, 1);
      }
    }
    return 1;
  }
  return 0;
}

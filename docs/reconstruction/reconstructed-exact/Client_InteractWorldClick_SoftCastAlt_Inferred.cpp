// =============================================================================
// Client_InteractWorldClick_SoftCastAlt_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0091a350
// Address:   0x0091a350–0x0091a54a inclusive (507 B / 0x1FB)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-033 dual A/B seal
//            (decompile_function + analyze_function_complete + disassemble_function
//             + read_memory + callers/xrefs + call-site context)
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI fixups.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Alternate arm of dualed Client_InteractWorldClickHub (0x00925820) when
//   DAT_00d1a860 == 0 (non-drop mode). Sole retail caller @ 0x00925958 after
//   dead/UI modal gates.
//
//   1) Gate client vtbl+0x3D8; fail → return 0.
//   2) client+0x558 = -1.0f; client+0xA32 = 0; client vtbl+0x478().
//   3) If select entity at client+0x758: Ui_ResolveEntityNameColor (ECX=entity).
//   4) If global char soft-cast flag entity+0x106 set: clear +0x107; spawn
//      type-2 FX via FUN_007a0120 (ECX=*DAT_00d17944) from body +0x284.
//   5) Return 1.
//
//   Does NOT zero select[+0x758] or call FUN_0093e120(0) — hub ItemPickup arm
//   owns that clear-select path. This unit is the soft-cast / clear-select
//   *alternate* relative to drop + ray/hit-list arms.
//
// ABI (assembly-sealed):
//   ESI = Client* (caller MOV ESI,EDI; not ECX-thiscall on entry)
//   no stack args; bare RET (C3); bool in AL
//   DAT_00aaa668 @ 0x00aaa668 = -1.0f (read_memory 00 00 80 BF)
//
// SEALED: body span, sole caller, gate/stores/FX order, constants, dual RET.
// OPEN:   product English for vtbl slots / flags; FUN_007a0120 full dual; runtime.
// =============================================================================

#include <cstdint>

extern float DAT_00aaa668; // -1.0f @ 0x00aaa668
extern int*  DAT_00d1b6d8; // global character*
extern int*  DAT_00d17944; // FX host object* (ECX = *DAT or load-from global)
extern char  DAT_00d1a840; // UI/client ctx blob for name-color
extern float DAT_00afdfc8, DAT_00afdfcc, DAT_00afdfd0;
extern float DAT_00afdfd4, DAT_00afdfd8, DAT_00afdfdc;
extern float DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8;

// Dualed WQ9D-J: ECX=entity; stack clientCtx, outArgb*, flags; ret 16
extern void __thiscall Ui_ResolveEntityNameColor_Inferred(
    void* entity, void* clientCtx, uint32_t* outArgb, char flagAllowSelf, char flagForce);

// Residual FX spawn. Retail: ECX from [DAT_00d17944]; large stack pack.
// Decompiler lists leading 0 as first arg; assembly seals thiscall host + pack.
extern int* __thiscall FUN_007a0120(
    int a0, int type /*2*/, uint8_t a2, int id /*0x61*/, uint32_t a4, float a5,
    int a6, int a7, int a8, int a9, int a10, int a11, int a12,
    int a13, float a14, float a15, float a16, float a17, float a18,
    float a19, float a20, float a21, float a22, float a23,
    float a24, float a25, int a26, int a27, int a28, uint8_t a29);

// Retail: ESI = client this (caller-established). Explicit param for portable C.
uint8_t Client_InteractWorldClick_SoftCastAlt_Inferred(int* client /* ESI */)
{
  int body;
  int entity;
  char gate;
  uint32_t localArgb[4]; // auStack_14[16]; retail also seeds 0xFF lanes

  gate = ((char(__thiscall*)(void*))(*(int*)(*client + 0x3d8)))(client);
  if (gate == '\0') {
    return 0;
  }

  *(float*)((uint8_t*)client + 0x558) = DAT_00aaa668; // -1.0f
  *((uint8_t*)client + 0xa32) = 0;
  ((void(__thiscall*)(void*))(*(int*)(*client + 0x478)))(client);

  if (client[0x1d6] != 0) {
    // Live: ECX = client[+0x758] before CALL; ret 16
    Ui_ResolveEntityNameColor_Inferred(
        (void*)client[0x1d6], &DAT_00d1a840, localArgb, 0, 0);
  }

  if (DAT_00d1b6d8 != nullptr) {
    entity = *(int*)((uint8_t*)DAT_00d1b6d8 + 0x250);
    if (entity != 0 && *(char*)(entity + 0x106) != '\0') {
      *(uint8_t*)(entity + 0x107) = 0;
      body = *(int*)(entity + 0x284);
      // re-read through global (matches retail double-load)
      body = *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 0x250) + 0x284);
      if (body != 0) {
        // ECX = dword [DAT_00d17944]; type==2 selects beam cross-product path
        FUN_007a0120(
            0, 2, 8, 0x61, 0,
            *(float*)((uint8_t*)client + 0x548), // client[0x152]
            /*0.4f*/ 0x3ecccccd, /*1.0f*/ 0x3f800000,
            *(int*)(body + 0x68), *(int*)(body + 0x68), /*3.0f*/ 0x40400000,
            (int)0xffffffff, 0,
            *(int*)(body + 0x30), *(int*)(body + 0x34), *(int*)(body + 0x38),
            *(int*)(body + 0x30), *(int*)(body + 0x34), *(int*)(body + 0x38),
            DAT_00afdfc8, DAT_00afdfcc, DAT_00afdfd0,
            DAT_00afdfd4, DAT_00afdfd8, DAT_00afdfdc,
            DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8,
            1);
      }
    }
  }

  return 1;
}

// =============================================================================
// Object_PlayPickupSpecialFX
// -----------------------------------------------------------------------------
// Purpose:  Load and attach client pickup SpecialFX scripts for a world object
//           based on clone-base item type and rarity, optionally play audio,
//           and recolor materials for paint-like type-8 items.
//
// Address:  0x0051aed0  (autoassault.exe, image base 0x400000)
// Body:     0x0051aed0 – 0x0051b1b9
// Stable:   aa_0051aed0
// System:   client / special-fx / item-pickup
//
// Convention: MSVC __thiscall
//   this           object* (clonebase ptr at this+0xA8 = dword index 0x2a)
//   bPlayAudio     stack char; gates mission-audio host play
//   bForceQuestFx  stack char; non-zero forces "generic_pickup_quest"
//   return         void; RET 8
//
// Clonebase type dword at clone+0x38 (when !bForceQuestFx and type != 4):
//   default → "generic_pickup" / "generic_pickup_enhanced" (vtbl+0x60)
//   8       → "generic_pickup_gadget"
//   0x1A    → "generic_pickup_commidity"  (product spelling)
//   0x32    → "generic_pickup_tinkering_kit"
//   0x42    → "generic_pickup_money"
//   type==4 or bForceQuestFx → "generic_pickup_quest"
// Def short +0x3F4 == 0x10 overrides base to "generic_pickup_trick_material".
//
// Rarity short at def+0x4B8 (if > 1):
//   default → rare; 3 ultra_rare; 4 artifact; 5 xeno_artifact
//
// Callers:
//   CLoadNode__initSelection  (1, 0)
//   FUN_00585e00              (distNear, flag)
//
// Dual A/B: 2026-07-29 W25-J accept-with-gaps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>

// Externs (Ghidra names kept where product English open)
extern void *NDSpecialFX_LoadFromScriptName(const char *name, int flags, int unused);
extern void FUN_004b8dc0(int newFlag, int arg2); // NDSpecialFX host activate cascade
extern void *Client_GetMissionCompleteAudioTable(void);
extern void FUN_004b7e50(int a, int b, int c, int d, int e, int f);
extern uint32_t FUN_00519d20(int paintId); // VehiclePaintColor_LookupById_Inferred
extern void FUN_009700f0(const char *matKey, float *rgba);
extern void FUN_0096f660(void);
extern float g_flOne;
extern float DAT_00aaa7a8; // ≈1/255

void __thiscall Object_PlayPickupSpecialFX(int *self, char bPlayAudio, char bForceQuestFx)
{
  short rarity;
  int related;
  int enhanced;
  void *fxPrimary;
  uint32_t colorPacked;
  void *fxRare;
  const char *scriptName;
  float rgba[4];

  // vtbl+0x1cc → related object; if present, vtbl+0xfc on its nested iface
  related = (*(int (**)(void))(*self + 0x1cc))();
  if (related != 0) {
    (*(void (**)(void))(
        *(int *)(*(int *)(*(int *)(related + 4) + 4) + 4 + related) + 0xfc))();
  }

  if ((bForceQuestFx == '\0') && (*(int *)(self[0x2a] + 0x38) != 4)) {
    switch (*(int *)(self[0x2a] + 0x38)) {
    default:
      enhanced = (*(int (**)(void))(*self + 0x60))();
      if (enhanced == 0) {
        scriptName = "generic_pickup";
      } else {
        scriptName = "generic_pickup_enhanced";
      }
      break;
    case 8:
      scriptName = "generic_pickup_gadget";
      break;
    case 0x1a:
      scriptName = "generic_pickup_commidity";
      break;
    case 0x32:
      scriptName = "generic_pickup_tinkering_kit";
      break;
    case 0x42:
      scriptName = "generic_pickup_money";
      break;
    }
    fxPrimary = NDSpecialFX_LoadFromScriptName(scriptName, 4, 0);
    if (*(short *)(*(int *)(self[0x2a] + 0x3c) + 0x3f4) != 0x10) {
      goto attach_rarity;
    }
    scriptName = "generic_pickup_trick_material";
  } else {
    scriptName = "generic_pickup_quest";
  }
  fxPrimary = NDSpecialFX_LoadFromScriptName(scriptName, 4, 0);

attach_rarity:
  rarity = *(short *)(*(int *)(self[0x2a] + 0x3c) + 0x4b8);
  fxRare = (void *)0;
  if (1 < rarity) {
    switch (rarity) {
    default:
      scriptName = "generic_pickup_rare";
      break;
    case 3:
      scriptName = "generic_pickup_ultra_rare";
      break;
    case 4:
      scriptName = "generic_pickup_artifact";
      break;
    case 5:
      scriptName = "generic_pickup_xeno_artifact";
      break;
    }
    fxRare = NDSpecialFX_LoadFromScriptName(scriptName, 4, 0);
  }

  if (fxPrimary != (void *)0) {
    if (fxRare != (void *)0) {
      FUN_004b8dc0(1, 0);
      (*(void (**)(void *, int, int))(*self + 0xf8))(fxRare, 1, 0);
    }
    FUN_004b8dc0(1, 0);
    (*(void (**)(void *, int, int))(*self + 0xf8))(fxPrimary, 1, 0);
    {
      int audioHost = (int)Client_GetMissionCompleteAudioTable();
      if ((*(char *)(audioHost + 600) != '\0') && (bPlayAudio != '\0')) {
        FUN_004b7e50(0, 0, 0, 0, 0, 0);
      }
    }
  }

  // Type short +0x3F4 == 8: apply paint color as MatAmbient/Diffuse/Emissive
  if (((*(short *)(*(int *)(self[0x2a] + 0x3c) + 0x3f4) == 8) && (related != 0)) &&
      (*(int *)(related + 8) != 0)) {
    int paintId = self[0x32];
    rgba[0] = 0.0f;
    rgba[1] = 0.0f;
    rgba[2] = 0.0f;
    rgba[3] = g_flOne;
    if (paintId < 0) {
      paintId = 0;
    }
    colorPacked = FUN_00519d20(paintId);
    rgba[0] = (float)((colorPacked >> 0x10) & 0xff) * DAT_00aaa7a8;
    rgba[1] = (float)((colorPacked >> 8) & 0xff) * DAT_00aaa7a8;
    rgba[2] = (float)(colorPacked & 0xff) * DAT_00aaa7a8;
    rgba[3] = g_flOne;
    FUN_009700f0("MatAmbient", rgba);
    FUN_009700f0("MatDiffuse", rgba);
    FUN_009700f0("MatEmissive", rgba);
    FUN_0096f660();
  }
}

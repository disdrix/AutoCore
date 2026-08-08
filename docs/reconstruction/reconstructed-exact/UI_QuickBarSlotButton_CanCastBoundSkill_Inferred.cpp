// =============================================================================
// UI_QuickBarSlotButton_CanCastBoundSkill_Inferred  (FUN_00829190)
// -----------------------------------------------------------------------------
// Purpose:  Predicate for a QuickBar slot-button bound to a skill:
//           return true if the local client considers the skill castable /
//           target-resolvable enough to show as ready (icon enable path).
//
// Address:  0x00829190  (autoassault.exe, image base 0x400000)
// Stable:   aa_00829190
// System:   client UI / quickbar / skills-abilities
// Body:     0x00829190 – 0x00829359 (458 bytes)
//
// Convention: MSVC __thiscall (button in ECX); 0 stack args; RET; bool AL
// Decompiler: bool __fastcall FUN_00829190(int param_1)
//
// Gates (byte + decompile sealed 2026-08-04):
//   1. DAT_00d1b6d8 != 0
//   2. button+0x548 == 1 (skill payloadKind)
//   3. skill = button+0x558 != null
//   4. if !(DAT_00d1b644 && *(DAT_00d1b644+0xf5)):
//        LocalCastValidate(caster, skipBusy=1, skill, 0) in {0, 6}
//        if (skill+0x614 & 0x800)==0:
//          ResolveCastTarget; true iff TFID != DAT_00a1e810 invalid sentinel
//        else true
//      else true  // UI force-ready
//
// Callees: Skill_LocalCastValidate 0x0051a790,
//          Client_Skill_ResolveCastTarget 0x0093b3a0,
//          TFID_EqualsObjectId 0x00404aa0,
//          virtuals vtbl+0x19c / +0x1a0 on local character link.
// Caller:  0x00829883 (slot button ECX=ESI; icon enable near +0x4fe).
// Dual: reviews/A|B_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md
// Exactness: CF + ABI + layout + accept codes sealed; runtime/diff open.
// =============================================================================

#include <cstdint>

struct UI_QuickBarSlotButton;
struct SkillObject;

// Named for documentation; port must match retail globals/links.
extern "C" bool __fastcall UI_QuickBarSlotButton_CanCastBoundSkill_Inferred(
    UI_QuickBarSlotButton* button /*ECX*/);

/*
 * Behavioral outline (not a drop-in compile unit — globals/vtables omitted):
 *
 * bool UI_QuickBarSlotButton_CanCastBoundSkill_Inferred(UI_QuickBarSlotButton* button)
 * {
 *   if (g_worldRoot == nullptr) return false;
 *   if (*(int32_t*)((uint8_t*)button + 0x548) != 1) return false;
 *   SkillObject* skill = *(SkillObject**)((uint8_t*)button + 0x558);
 *   if (skill == nullptr) return false;
 *
 *   if (g_uiOverride && *(uint8_t*)((uint8_t*)g_uiOverride + 0xf5))
 *     return true;
 *
 *   // seed TFID from local character selection/self (+0x160..); aim via vtbl+0x1a0
 *   int code = Skill_LocalCastValidate(localCharacter, 1, skill, 0);
 *   if (code != 0 && code != 6) return false;
 *
 *   if ((*(uint32_t*)((uint8_t*)skill + 0x614) & 0x800u) != 0)
 *     return true;
 *
 *   TFID_16 resolved = Client_Skill_ResolveCastTarget(...);
 *   return TFID_EqualsObjectId(&resolved, &g_tfidInvalid_A1E810) == 0;
 * }
 */

// =============================================================================
// Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c50
// -----------------------------------------------------------------------------
// Legacy auto-seed alias for aa_00508c50.
// Canonical: HandlerTable58_FindById6c (FUN_00508c50 @ 0x00508c50).
// The Skill_GetModifier… parent-seed name is MISLEADING for this leaf table finder.
// W21-D: retained as alias only; do not treat as product English.
// =============================================================================

#include <stdint.h>

extern int32_t DAT_00d02984;

void *__thiscall Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c50(
    void *registry, int32_t id)
{
  int32_t i;
  int32_t *cursor;

  i = 0;
  if ((id != -1) && (DAT_00d02984 > 0)) {
    cursor = *(int32_t **)((char *)registry + 0x58);
    do {
      if (*(int32_t *)((char *)(*cursor) + 0x6c) == id) {
        return (*(void ***)((char *)registry + 0x58))[i];
      }
      i = i + 1;
      cursor = cursor + 1;
    } while (i < DAT_00d02984);
  }
  return 0;
}

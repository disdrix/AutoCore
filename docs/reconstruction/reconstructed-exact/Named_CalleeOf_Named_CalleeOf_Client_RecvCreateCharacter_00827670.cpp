// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00827670
// Legacy auto-seed alias — CreateCharacter is only an indirect caller via rebind.
// Canonical: UI_QuickBarSlotButton_AssignItemOrMacro_Inferred @ 0x00827670
// =============================================================================

#include <cstdint>

struct UI_QuickBarSlotButton;

extern uint32_t UI_QuickBarSlotButton_AssignItemOrMacro_Inferred(
    UI_QuickBarSlotButton* btn, int32_t kind, int32_t id);

uint32_t Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00827670(
    UI_QuickBarSlotButton* btn, int32_t kind, int32_t id)
{
    return UI_QuickBarSlotButton_AssignItemOrMacro_Inferred(btn, kind, id);
}

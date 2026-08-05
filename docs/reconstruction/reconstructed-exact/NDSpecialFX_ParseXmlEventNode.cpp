// =============================================================================
// NDSpecialFX_ParseXmlEventNode  (canonical name for aa_004a4fa0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004a4fa0
// Address:   0x004a4fa0 – 0x004a617f
// See also:  FUN_004a4fa0.cpp (same CF map)
// Exactness: Behavior-preserving string tables + dispatch. Not modernization.
// =============================================================================
//
// This named unit is the documentation face of FUN_004a4fa0.cpp.
// Full structural reconstruction lives in FUN_004a4fa0.cpp to avoid dual drift.
//
// Contract:
//   void *NDSpecialFX_ParseXmlEventNode(IXmlNode *node, int *outEventType,
//                                       uint8_t *customIdCounter);
//   __cdecl; returns FX* (0x240 shell) or NULL.
//
// Sealed tables (High):
//   - Event type wcsicmp chain (Create..Suspension + custom base 100)
//   - Group owner attach ids (front..weaponMelee)
//   - Sound defaults: radius 10.f @ DAT_009c7c28, maxradius 80.f @ DAT_009c7c2c
//   - Sound category defaults by event type at +0x104
//   - Child element dispatch order / fail→FUN_004b99c0+delete
//
// Residual:
//   - IXml vtbl slot names; child-count register recovery; callee bodies
// =============================================================================

// Implementation: see FUN_004a4fa0.cpp
extern void *FUN_004a4fa0(void *node, int *outEventType, unsigned char *customIdCounter);

void *NDSpecialFX_ParseXmlEventNode(void *node, int *outEventType,
                                    unsigned char *customIdCounter)
{
  return FUN_004a4fa0(node, outEventType, customIdCounter);
}

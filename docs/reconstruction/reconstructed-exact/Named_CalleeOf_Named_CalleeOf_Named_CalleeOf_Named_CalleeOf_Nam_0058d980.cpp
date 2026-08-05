// =============================================================================
// Named scaffold alias → CVOGPhysics_ApplyPointImpulse
// -----------------------------------------------------------------------------
// Stable ID: aa_0058d980
// Address:   0x0058d980
// Canonical: reconstructed-exact/CVOGPhysics_ApplyPointImpulse.cpp
// Dual:      reviews/A_aa_0058d980_CVOGPhysics_ApplyPointImpulse.md
//            reviews/B_aa_0058d980_CVOGPhysics_ApplyPointImpulse.md
// Note:      Prior under-name (VOG_DEBUG callee seed). Prefer canonical.
// =============================================================================

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0058d980(
    int phys, uint32_t impulse, uint32_t point)
{
  char *pcVar1;
  uint32_t uStack_4;

  uStack_4 = (uint32_t)phys;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(phys + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(phys + 0x3c) + 0x60))(impulse, point);
  return;
}

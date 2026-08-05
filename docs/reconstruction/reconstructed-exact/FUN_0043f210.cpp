// =============================================================================
// FUN_0043f210  (alias scaffold → Math_Matrix4x4_Set16)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f210
// Address:   0x0043f210  (autoassault.exe, image base 0x400000)
// Canonical: Math_Matrix4x4_Set16
// System:    math / matrix
// Generated: 2026-07-29 dual A/B W18-E (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See Math_Matrix4x4_Set16.cpp for named clean source.

void __thiscall FUN_0043f210(
    unsigned *param_1,
    unsigned param_2, unsigned param_3, unsigned param_4, unsigned param_5,
    unsigned param_6, unsigned param_7, unsigned param_8, unsigned param_9,
    unsigned param_10, unsigned param_11, unsigned param_12, unsigned param_13,
    unsigned param_14, unsigned param_15, unsigned param_16, unsigned param_17)
{
  int iVar1;
  unsigned *puVar2;
  unsigned local_50[4];
  unsigned local_40;
  unsigned local_3c;
  unsigned local_38;
  unsigned local_34;
  unsigned local_30;
  unsigned local_2c;
  unsigned local_28;
  unsigned local_24;
  unsigned local_20;
  unsigned local_1c;
  unsigned local_18;
  unsigned local_14;

  local_50[0] = param_2;
  local_50[1] = param_3;
  local_50[2] = param_4;
  local_50[3] = param_5;
  local_40 = param_6;
  local_3c = param_7;
  local_38 = param_8;
  local_34 = param_9;
  local_30 = param_10;
  local_2c = param_11;
  local_28 = param_12;
  local_24 = param_13;
  local_20 = param_14;
  local_1c = param_15;
  local_18 = param_16;
  local_14 = param_17;
  puVar2 = local_50;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

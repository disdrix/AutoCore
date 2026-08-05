// =============================================================================
// NDAssetImage_LoadTGA
// -----------------------------------------------------------------------------
// Stable ID: aa_004347d0
// Address:   0x004347d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Load TGA into NDAssetImage. Bottom-origin keeps file order; top-origin bit5 + 32bpp calls
   NDAssetImage_FlipVertical so GetPixel y=0 is always image bottom. Used by
   CVOGTerrain_LoadMapImage for map.tga area ids. */

uint32_t /* width from decompiler */ NDAssetImage_LoadTGA(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  uint8_t uVar3;
  int iVar4;
  byte bVar5;
  uint8_t local_378 [796];
  char *local_5c;
  char *local_58;
  int local_54;
  char *local_50;
  uint32_t /* width from decompiler */ local_4c;
  char *local_48;
  int local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  uint32_t /* width from decompiler */ local_30;
  char local_2c;
  char local_2b;
  char local_2a;
  ushort local_27;
  short local_20;
  ushort local_1e;
  char local_1c;
  char local_17;
  char local_16;
  char local_15;
  uint8_t *local_14;
  void *local_10;
  uint8_t *puStack_c;
  uint32_t /* width from decompiler */ local_8;
  
  puStack_c = &LAB_009bd6e0;
  local_10 = ExceptionList;
  local_14 = &stack0xfffffc7c;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  iVar4 = (**(code **)(*param_2 + 8))(&local_2c,0x12,1);
  if (iVar4 == 0) {
    local_50 = "Not a TGA";
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_50,(ThrowInfo *)&DAT_00acc49c);
  }
  switch(local_2a) {
  case '\x01':
  case '\x02':
  case '\x03':
    local_15 = '\0';
    break;
  default:
    local_48 = "Unknown TGA image type";
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_48,(ThrowInfo *)&DAT_00acc49c);
  case '\t':
  case '\n':
  case '\v':
    local_15 = '\x01';
  }
  if ((((local_20 == 0) || (local_1e == 0)) || (local_1c == '\0')) || (0x100 < local_27)) {
    local_40 = "bad TGA header";
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_40,(ThrowInfo *)&DAT_00acc49c);
  }
  if (((local_1c != '\b') && (local_1c != '\x0f')) &&
     ((local_1c != '\x10' && ((local_1c != '\x18' && (local_1c != ' ')))))) {
    local_58 = "bad TGA header";
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_58,(ThrowInfo *)&DAT_00acc49c);
  }
  if (local_2c != '\0') {
    (**(code **)(*param_2 + 0x10))(local_2c,1);
  }
  FUN_004323e0(local_20,local_1c,3);
  if (local_1c == ' ') {
    FUN_00433180();
  }
  if (*(int *)(param_1 + 4) == 0) {
    local_3c = "TGA Create failed";
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_3c,(ThrowInfo *)&DAT_00acc49c);
  }
  if (*(int *)(param_1 + 0x148) != 0) {
    local_5c = "Cancelled";
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_5c,(ThrowInfo *)&DAT_00acc49c);
  }
  if (local_2b != '\0') {
    (**(code **)(*param_2 + 8))(local_378,(uint)local_27 * 3,1);
    for (iVar4 = 0; local_44 = iVar4, iVar4 < (int)(uint)local_27; iVar4 = iVar4 + 1) {
      iVar1 = iVar4 * 3;
      FUN_00433440(CONCAT31((int3)((uint)iVar1 >> 8),local_378[iVar1 + 2]),local_378[iVar1 + 1],
                   local_378[iVar1],0);
    }
  }
  if ((local_2a == '\x03') || (local_2a == '\v')) {
    FUN_00433a00();
  }
  bVar5 = (byte)((ushort)_local_1c >> 8);
  local_17 = (bVar5 & 0x10) == 0x10;
  local_16 = (bVar5 & 0x20) == 0x20;
  FUN_00433d30();
  local_30 = CONCAT31(local_30._1_3_,0xff);
  iVar4 = 0;
  while( true ) {
    local_54 = iVar4;
    if ((int)(uint)local_1e <= iVar4) {
      if (local_17 != '\0') {
        FUN_0098acc0();
      }
      if ((local_16 != '\0') && (local_1c == ' ')) {
        NDAssetImage_FlipVertical();
      }
      ExceptionList = local_10;
      return 1;
    }
    if (*(int *)(param_1 + 0x148) != 0) break;
    if ((param_2 == (int *)0x0) || (cVar2 = (**(code **)(*param_2 + 0x20))(), cVar2 != '\0')) {
      local_38 = "corrupted TGA";
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_38,(ThrowInfo *)&DAT_00acc49c);
    }
    local_4c = FUN_00433d70();
    if (local_15 == '\0') {
      FUN_00434dd0(param_1,&local_2c,local_20,iVar4,0);
      iVar4 = iVar4 + 1;
    }
    else {
      uVar3 = FUN_00434b30(param_1,local_4c,&local_2c,local_20,iVar4,local_30);
      local_30 = CONCAT31(local_30._1_3_,uVar3);
      iVar4 = iVar4 + 1;
    }
  }
  local_34 = "Cancelled";
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_34,(ThrowInfo *)&DAT_00acc49c);
}

// =============================================================================
// NDUIWindow_InitFromInterfaceXml
// -----------------------------------------------------------------------------
// Stable ID: aa_007b3710
// Address:   0x007b3710  (autoassault.exe, image base 0x400000)
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

/* NDUIWindow_InitFromInterfaceXml  (NDUIWindow.cpp)
   
   Initialize a UI window tree from an interface .xml file.
   Calls NDXml_OpenTaggedDocument(this, "XML").
   On failure logs: "Unable to open .xml file for init: %s"
   On success iterates root nodes and NDUIWindow_ApplyXmlNodeAttributes each child.
   
   String anchors: "Empty interface file %s", vog path libND/NDUIWindow.cpp:0x1b9f. */

void NDUIWindow_InitFromInterfaceXml(int *param_1,uint32_t /* width from decompiler */ param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint32_t /* width from decompiler */ uVar5;
  undefined **local_20;
  int *piStack_1c;
  int *local_18;
  int local_14;
  void *pvStack_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b28b1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00799940();
  piVar1 = param_1;
  local_4 = 0;
  iVar3 = NDXml_OpenTaggedDocument(param_1,"XML");
  if (iVar3 != 0) {
    DAT_00d1794c = (undefined ***)0x0;
    FUN_007a4480(1,"Unable to open .xml file for init: %s",piVar1);
    local_4 = 0xffffffff;
    FUN_007989b0();
    ExceptionList = local_c;
    return;
  }
  DAT_00d1794c = &local_20;
  iVar3 = 0;
  if (0 < local_14) {
    do {
      iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,iVar3,&param_1);
      piVar2 = param_1;
      if (iVar4 != 0) {
        FUN_007a4480(0,"VOG_DEBUG_STOP");
LAB_007b3851:
        uVar5 = FUN_0076cec0(&param_1,"Empty interface file %s",piVar1);
        vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUIWindow.cpp",0x1b9f,3,uVar5);
        goto LAB_007b37e9;
      }
      if (param_1 == (int *)0x0) goto LAB_007b3851;
      NDUIWindow_ApplyXmlNodeAttributes(param_1,piVar1,param_2);
      (**(code **)(*piVar2 + 8))(piVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < local_14);
  }
  DAT_00d1794c = (undefined ***)0x0;
LAB_007b37e9:
  local_4 = 0xffffffff;
  local_20 = &PTR_FUN_00a98338;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
    local_18 = (int *)0x0;
  }
  if (piStack_1c != (int *)0x0) {
    (**(code **)(*piStack_1c + 8))(piStack_1c);
    piStack_1c = (int *)0x0;
  }
  operator_delete__(pvStack_10);
  ExceptionList = local_c;
  return;
}

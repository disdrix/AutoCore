// =============================================================================
// NDXml_LoadDocumentFromPath
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6c70
// Address:   0x007b6c70  (autoassault.exe, image base 0x400000)
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

/* NDXml_LoadDocumentFromPath
   
   Load/parse an interface or script XML file via MSXML.
   CRASH SITE for mission turn-in AVs: PC 0x007B6DB0 is CALL [vtable+8] = IUnknown::Release
   on a stale COM interface from NDResource_AcquireInnerObject after a successful load.
   
   Flow:
     1. Null-check IXMLDOMDocument (param2) and path (param3)
     2. PathFileExistsA + search path table DAT_00d1e574
     3. NDResource_LoadByKey → document object
     4. On success: AcquireInnerObject, Release prior COM iface (CRASH if vtable bad)
     5. Feed VARIANT into IXMLDOMDocument load method (vtable+0xe8)
   
   Callers: NDXml_OpenTaggedDocument, legacy path at 0x0049f9a0.
   Related crash stacks: dialog UI (NDUIWindow_*) and interact FX (NDSpecialFX_*). */

bool __thiscall NDXml_LoadDocumentFromPath(void *this,void *pXmlDom,char *pszPath)

{
  int iVar1;
  uint8_t *puVar2;
  char cVar3;
  uint8_t uVar4;
  BOOL BVar5;
  char *pcVar6;
  uint uVar7;
  uint32_t /* width from decompiler */ uVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  int *piVar14;
  char local_154 [260];
  undefined **local_50;
  int *local_4c;
  uint32_t /* width from decompiler */ local_48;
  _union_2683 local_44;
  uint32_t /* width from decompiler */ local_34;
  uint8_t local_30 [4];
  uint32_t /* width from decompiler */ local_2c;
  int local_28;
  BSTR pOStack_24;
  char *local_20;
  void *local_1c;
  int *piStack_18;
  uint8_t *local_14;
  void *pvStack_10;
  uint8_t *puStack_c;
  uint32_t /* width from decompiler */ local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009b0b6a;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xfffffea0;
  if (pXmlDom == (void *)0x0) {
    return false;
  }
  if (pszPath == (char *)0x0) {
    return false;
  }
  ExceptionList = &pvStack_10;
  local_1c = this;
  puVar2 = &stack0xfffffea0;
  if ((*(byte *)((int)this + 4) & 1) != 0) {
    ExceptionList = &pvStack_10;
    BVar5 = PathFileExistsA(pszPath);
    if (BVar5 != 0) goto LAB_007b6d5c;
    local_20 = (char *)FUN_007b6420();
    pcVar13 = (char *)&DAT_00d1e574;
    do {
      pcVar10 = pcVar13;
      if (0xf < *(uint *)(pcVar13 + 0x14)) {
        pcVar10 = *(char **)pcVar13;
      }
      pcVar12 = local_154;
      do {
        cVar3 = *pcVar10;
        *pcVar12 = cVar3;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
        pcVar6 = local_20;
      } while (cVar3 != '\0');
      do {
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
      uVar7 = (int)pcVar6 - (int)local_20;
      pcVar10 = &stack0xfffffeab;
      do {
        pcVar12 = pcVar10 + 1;
        pcVar10 = pcVar10 + 1;
      } while (*pcVar12 != '\0');
      pcVar12 = local_20;
      for (uVar11 = uVar7 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar10 = pcVar10 + 1;
      }
      BVar5 = PathFileExistsA(local_154);
      if (BVar5 != 0) goto LAB_007b6d5c;
      pcVar13 = pcVar13 + 0x1c;
      puVar2 = local_14;
    } while ((int)pcVar13 < 0xd1e7a4);
  }
  local_14 = puVar2;
  cVar3 = FUN_007b66c0(local_1c);
  if (cVar3 == '\0') {
    ExceptionList = pvStack_10;
    return false;
  }
LAB_007b6d5c:
  piVar14 = (int *)0x0;
  local_34 = 0;
  local_2c = 0;
  local_28 = 0;
  uVar8 = FUN_007b6420();
  FUN_00989e00(local_30,uVar8);
  iVar9 = NDResource_LoadByKey(&local_28,local_30,0,0);
  iVar1 = local_28;
  if (iVar9 < 0) {
    if ((short)local_2c == -1) {
      ExceptionList = pvStack_10;
      return true;
    }
    piStack_18 = (int *)0x0;
    (**(code **)(*(int *)pXmlDom + 0xf0))(pXmlDom,&piStack_18);
    if (piStack_18 != (int *)0x0) {
      pXmlDom = (void *)0x0;
      (**(code **)(*piStack_18 + 0x20))(piStack_18,&pXmlDom);
      pOStack_24 = (BSTR)0x0;
      (**(code **)(*piStack_18 + 0x24))(piStack_18,&pOStack_24);
      local_20 = (char *)0x0;
      (**(code **)(*piStack_18 + 0x2c))(piStack_18,&local_20);
      local_1c = (void *)0x0;
      (**(code **)(*piStack_18 + 0x30))(piStack_18,&local_1c);
      FUN_007a4480(1,"%S(%i)(%s): pos %i, XML parse error: %S",pXmlDom,local_20,pszPath,local_1c,
                   pOStack_24);
      SysFreeString(pXmlDom);
      SysFreeString(pOStack_24);
      (**(code **)(*piStack_18 + 8))(piStack_18);
    }
  }
  else {
    iVar9 = NDResource_AcquireInnerObject();
    if (iVar9 != 0) {
      piVar14 = *(int **)(iVar9 + 4);
    }
    if (piVar14 != (int *)0x0) {
                    /* CRASH: Release on stale COM iface from resource+4 after AcquireInnerObject */
      (**(code **)(*piVar14 + 8))();
    }
    if (*(char *)(iVar1 + 0x38) != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x20));
    }
    if (*(int *)(iVar1 + 0x10) != 0) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    }
    if (*(char *)(iVar1 + 0x38) != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x20));
    }
    if ((*(char *)(DAT_00d1f050 + 0x68) != '\0') && (*(int *)(DAT_00d1f050 + 100) != 0)) {
      FUN_00744ea0(local_30,0);
    }
    if (piVar14 != (int *)0x0) {
      local_48 = 1;
      local_50 = &PTR_LAB_00a95b44;
      local_44._8_4_ = &local_50;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      local_44.n2.vt = 0xd;
      local_4c = piVar14;
      (*(code *)PTR_FUN_00a95b48)(local_44._8_4_);
      local_8 = CONCAT31(local_8._1_3_,2);
      uVar8 = local_44._0_4_;
      (**(code **)(*(int *)pXmlDom + 0xe8))
                (pXmlDom,local_44._0_4_,local_44.decVal.Hi32,local_44._8_4_,local_44._12_4_,
                 &local_2c);
      VariantClear((VARIANTARG *)&local_44.n2);
      uVar4 = FUN_007b6e8d(uVar8,local_44.decVal.Hi32);
      return (bool)uVar4;
    }
  }
  ExceptionList = pvStack_10;
  return false;
}

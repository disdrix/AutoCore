// =============================================================================
// FUN_00490070 / Client_Interact_SelectBestPickTarget
// -----------------------------------------------------------------------------
// Stable ID: aa_00490070
// Address:   0x00490070  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-07-23 scaffold; refined dual seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE: Primary pick resolver for Client_InteractClickPickTarget.
//   - Early-out if client+0xC0 or +0xBC (gfx views) null
//   - Unproject screen (FUN_0075c340) into local ray buffers
//   - Two passes of FUN_004bae00 enumerator (flag 0 then 1)
//   - Score candidates: max priority byte, then min distance (DAT_00aaa630=FLT_MAX)
//   - Return best object* or NULL
//
// DAT_00aaa630: read_memory = FF FF 7F 7F = FLT_MAX
// Entry bytes: sub esp,0x78; mov edi,ecx; test [edi+0xC0]; test [edi+0xBC]
// param_3: unused in body
// =============================================================================

#include <cstdint>

extern float DAT_00aaa630;
extern void FUN_0075c340(void* screenXY, void* outNear, void* outDir);
extern int* FUN_004bae00(std::uint32_t flag, void* iter);
extern int FUN_00524520(int* obj);
extern int FUN_005245d0(int* obj);
extern char FUN_0040b1b0(void);
extern int __RTDynamicCast(int* in, int a, void* src, void* dst, int e);
// RTTI symbols as in raw:
// CVOGClonedObjectBase::RTTI_Type_Descriptor, CVOGCreature::RTTI_Type_Descriptor

// thiscall: ECX/param_1 = Client*
int* __thiscall FUN_00490070(int param_1, std::uint32_t param_2, std::uint32_t param_3, char param_4)
{
  bool bVar1;
  std::uint8_t bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  unsigned uVar6;
  int *piVar7;
  std::uint8_t local_75;
  float local_74;
  unsigned local_6c;
  int *local_68;
  float local_64;
  std::uint32_t local_60;
  int local_5c;
  std::uint8_t auStack_58[4];
  std::uint8_t local_54[12];
  std::uint8_t local_48[12];
  float fStack_3c;
  std::uint8_t local_4;
  std::uint8_t local_3;
  std::uint8_t local_2;
  std::uint8_t local_1;

  (void)param_3; // unused in body

  if ((*(int *)(param_1 + 0xc0) == 0) || (*(int *)(param_1 + 0xbc) == 0)) {
    return (int *)0x0;
  }
  local_2 = 0xff;
  local_3 = 0xff;
  local_4 = 0xff;
  local_1 = 0xff;
  FUN_0075c340((void*)(std::uintptr_t)param_2, local_54, local_48);
  local_64 = DAT_00aaa630;
  local_74 = DAT_00aaa630;
  local_68 = (int *)0x0;
  local_6c = local_6c & 0xffffff00;
  local_75 = 0;
  bVar1 = false;
  local_5c = 2;
  do {
    local_60 = 0;
    piVar4 = (int *)FUN_004bae00(local_6c, &local_60);
    bVar2 = local_75;
    while (piVar4 != (int *)0x0) {
      local_75 = 0;
      if (((((unsigned)piVar4[0x5f] >> 6 & 1) == 0) ||
          (iVar5 = (**(int(**)())(*piVar4 + 0x1cc))(), *(int *)(iVar5 + 8) == 0)) ||
         (*(char *)(iVar5 + 0xe) == '\0')) goto switchD_004901c9_caseD_1e;
      fStack_3c = DAT_00aaa630;
      cVar3 = (**(int(**)())(**(int **)(iVar5 + 8) + 0x78))(5, auStack_58);
      if (cVar3 == '\0') goto switchD_004901c9_caseD_1e;
      uVar6 = (unsigned)*(short *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x3f2);
      if ((uVar6 >> 0xe & 1) != 0) {
        local_74 = fStack_3c;
        local_75 = 0x50;
      }
      if (((uVar6 >> 7 & 1) != 0) && (local_74 = fStack_3c, local_75 < 0x47)) {
        local_75 = 0x46;
      }
      switch(*(std::uint32_t *)(piVar4[0x2a] + 0x38)) {
      case 1:
      case 3:
        if (((*(int *)(param_1 + 0xb8) != 0) &&
            (piVar7 = *(int **)(*(int *)(param_1 + 0xb8) + 0xe8a0), piVar7 != (int *)0x0)) &&
           (iVar5 = (**(int(**)())(*piVar7 + 0x1dc))(), iVar5 != 0)) {
          piVar7 = piVar4;
          (**(int(**)())(**(int **)(*(int *)(param_1 + 0xb8) + 0xe8a0) + 0x1dc))(piVar4);
          iVar5 = FUN_00524520(piVar7);
          if (iVar5 == 0) {
            piVar7 = piVar4;
            (**(int(**)())(**(int **)(*(int *)(param_1 + 0xb8) + 0xe8a0) + 0x1dc))(piVar4);
            iVar5 = FUN_005245d0(piVar7);
            if (iVar5 == 0) goto LAB_00490248;
          }
          bVar1 = true;
          if (local_75 < 0x3d) {
            local_75 = 0x3c;
          }
        }
LAB_00490248:
        if ((piVar4[10] & piVar4[0xb]) != 0xffffffff) {
          bVar1 = true;
        }
        if ((piVar4[0xc] & piVar4[0xd]) != 0xffffffff) {
          bVar1 = true;
        }
        if ((piVar4[0xe] & piVar4[0xf]) != 0xffffffff) {
          bVar1 = true;
        }
        if ((((*(unsigned short *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x3f2) & 0x2000) != 0) || (bVar1)) &&
           (local_74 = fStack_3c, local_75 < 0x15)) {
          local_75 = 0x14;
        }
        break;
      case 10:
      case 0xc:
      case 0x10:
      case 0x1c:
        piVar7 = (int *)piVar4[0x2b];
        local_74 = fStack_3c;
        if (piVar7 == (int *)0x0) {
          if (local_75 < 0x47) {
            local_75 = 0x46;
          }
        }
        else {
          piVar4 = piVar7;
          if (local_75 < 0x5b) {
            local_75 = 0x5a;
          }
        }
        break;
      case 0xe:
        if ((param_4 == '\0') && (*(int *)(param_1 + 0xb8) != 0)) {
          iVar5 = (**(int(**)())(*piVar4 + 0x210))(0);
          if (iVar5 != 0) {
            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;
          }
          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break;
        }
        local_74 = fStack_3c;
        if (local_75 < 0x5b) {
          local_75 = 0x5a;
        }
        break;
      case 0x12:
        if ((param_4 == '\0') && (*(int *)(param_1 + 0xb8) != 0)) {
          iVar5 = (**(int(**)())(*piVar4 + 0x210))(0);
          if (iVar5 != 0) {
            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;
          }
          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break;
        }
        iVar5 = __RTDynamicCast(piVar4, 0, (void*)0 /*CVOGClonedObjectBase RTTI*/,
                                (void*)0 /*CVOGCreature RTTI*/, 0);
        cVar3 = (**(int(**)())(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))();
        if (cVar3 == '\0') {
          cVar3 = FUN_0040b1b0();
          local_74 = fStack_3c;
          if (cVar3 == '\0') goto LAB_00490468;
          if (local_75 < 0x33) {
            local_75 = 0x32;
          }
        }
        else {
          local_74 = fStack_3c;
          if (local_75 < 0x3d) {
            local_75 = 0x3c;
          }
        }
        break;
      case 0x14:
        if ((param_4 == '\0') && (*(int *)(param_1 + 0xb8) != 0)) {
          iVar5 = (**(int(**)())(*piVar4 + 0x210))(0);
          if (iVar5 != 0) {
            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;
          }
          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break;
        }
      default:
        local_74 = fStack_3c;
        if (local_75 < 0x29) {
          local_75 = 0x28;
        }
        break;
      case 0x16:
LAB_00490468:
        local_74 = fStack_3c;
        if (local_75 < 0x65) {
          local_75 = 100;
        }
        break;
      case 0x1e:
      case 0x36:
      case 0x38:
        goto switchD_004901c9_caseD_1e;
      }
      if (local_75 == bVar2) {
        if (local_74 < local_64) {
          local_64 = local_74;
          local_75 = bVar2;
LAB_00490477:
          bVar2 = local_75;
          local_68 = piVar4;
        }
      }
      else if (bVar2 < local_75) goto LAB_00490477;
switchD_004901c9_caseD_1e:
      local_75 = bVar2;
      piVar4 = (int *)FUN_004bae00(local_6c, &local_60);
      bVar2 = local_75;
    }
    local_5c = local_5c + -1;
    local_6c = (local_6c & 0xffffff00) | (unsigned)((char)local_6c == '\0');
    local_75 = bVar2;
    if (local_5c == 0) {
      return local_68;
    }
  } while (true);
}

// =============================================================================
// Client_Interact_SelectBestPickTarget  (was FUN_00490070)
// -----------------------------------------------------------------------------
// Address:  0x00490070  (autoassault.exe, image base 0x400000)
// Stable:   aa_00490070
// Systems:  interaction-activation
//
// Purpose: Primary world-object pick resolver for Client_InteractClickPickTarget
//          (0x009247b0). Two FUN_004bae00 enumerator passes (flag 0 then 1);
//          score each candidate (priority byte, then min distance from
//          DAT_00aaa630 = FLT_MAX). Return best object* or NULL.
//
// Exactness: Ghidra decompile line-faithful + read_memory (entry, DAT_00aaa630).
//            Dual A/B 2026-07-29. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// Priority table (higher wins; equal priority -> lower fStack_3c distance):
//   0x50  def flags +0x3F2 bit14
//   0x46  def flags +0x3F2 bit7 (if pri < 0x47); also type 10 family null parent
//   0x5A  type 10/0xC/0x10/0x1C with parent obj[0x2B]; type 0xE
//   0x3C  types 1/3 mission interact/pick hit; type 0x12 creature vtbl+0x198 true
//   0x32  type 0x12 + FUN_0040b1b0 true
//   0x28  default / type 0x14
//   0x14  types 1/3 owner TFID slots or flag 0x2000
//   0x64  type 0x16 (and type 0x12 when 0040b1b0 false)
//   skip  types 0x1E, 0x36, 0x38
// =============================================================================

#include <cstdint>

extern float DAT_00aaa630; // 0x7F7FFFFF FLT_MAX
extern void FUN_0075c340(void* screenXY, void* outNear, void* outDir);
extern int* FUN_004bae00(std::uint32_t flag, void* iter);
extern int FUN_00524520(int* obj); // FindActiveObjectiveIdForInteract (thiscall ECX char residual)
extern int FUN_005245d0(int* obj); // FindActiveObjectiveIdForPick
extern char FUN_0040b1b0(void);
extern int __RTDynamicCast(int* in, int a, void* src, void* dst, int e);

// thiscall: ECX = Client* (param_1)
// stack: screenXY*, (unused param_3), char filterSelfOwned
// returns best object* or NULL
int* __thiscall Client_Interact_SelectBestPickTarget(
    int param_1,
    std::uint32_t param_2,
    std::uint32_t param_3,
    char param_4)
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

  (void)param_3; // unused in body (raw/live)

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
        // Mission boost: client+0xB8 world; +0xE8A0 character; vtbl+0x1DC prep
        // then FindActiveObjectiveIdForInteract / ForPick
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
        // Owner TFID slots non-all-ones → bVar1; flag 0x2000 or bVar1 → pri 0x14
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
          piVar4 = piVar7; // retarget selection to parent/container
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
          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break; // skip self-owned
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
        iVar5 = __RTDynamicCast(piVar4, 0, (void*)0, (void*)0, 0); // ClonedObjectBase->Creature
        cVar3 = (**(int(**)())(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))();
        if (cVar3 == '\0') {
          cVar3 = FUN_0040b1b0();
          local_74 = fStack_3c;
          if (cVar3 == '\0') goto LAB_00490468; // pri 100
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
      // Selection: higher priority wins; same priority -> nearer distance
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
    // toggle enum flag low byte 0<->1
    local_6c = (local_6c & 0xffffff00) | (unsigned)((char)local_6c == '\0');
    local_75 = bVar2;
    if (local_5c == 0) {
      return local_68;
    }
  } while (true);
}

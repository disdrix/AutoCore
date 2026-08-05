// =============================================================================
// FUN_005da0a0  (canonical: Drive_CollisionListener_Contact)
// -----------------------------------------------------------------------------
// Stable ID: aa_005da0a0
// Address:   0x005da0a0 – 0x005dab25  (autoassault.exe, image base 0x400000)
// Named plate: Drive_CollisionListener_Contact.cpp
// System:    drive / collision / vehicle damage
// Generated: 2026-07-29 W22-I dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   CollisionListener::contact — phys contact callback core.
//   Resolve game objects from both contact body chains, gate by material/type,
//   compute impact energy, optional damage + Logic-UI opcode 0x29, then
//   bidirectional Drive_CollisionListener_DoVehicleCollision (FUN_005d9290).
//
// STRING EVIDENCE: FUN_0076cf00("CollisionListener::contact")
// SIBLING: Drive_CollisionListener_DoVehicleCollision @ 0x005d9290
// CALLER: FUN_005dab30 — if AL==0 sets contactEvent+0x20 = 1
//
// ABI (sealed from bytes):
//   __thiscall RET 0x10
//   ECX = CollisionListener* this  (last-contact time @ +0x10)
//   stack0 = uint32_t ctx           (event+0x14)
//   stack1 = float* impact          (event+0x1c)
//   stack2 = int* bodyA             (event+0x08)
//   stack3 = int* bodyB             (event+0x0c)
//   AL = 0 reject/disable; else keep (local_19e default 1, or forced 1)
//
// CONSTANTS (read_memory):
//   af4364=1.0f  af4368=0.5f  aaa994=3.6f  9db4e4~2.5e-7f  aaacd0=350.f  af43b4=500
//
// DECOMPILER RESIDUALS:
//   - this formal omitted in Ghidra sig; prologue mov [esp+0x24],ecx
//   - local_18c unassigned in decompile → saved this (rate host)
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

// Named entry — twin FUN_005da0a0.cpp keeps Ghidra symbol for inventory glue.
uint8_t __thiscall FUN_005da0a0(
    int this_listener,
    uint32_t param_1,
    float *param_2,
    int *param_3,
    int *param_4)
{
  uint32_t uVar1;
  int *piVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint32_t *puVar8;
  float *pfVar9;
  int *piVar10;
  void *pvVar11;
  int *piVar12;
  float10 fVar13;
  uint32_t *puVar14;
  uint8_t local_19e;
  char cStack_19d;
  uint32_t local_19c;
  float fStack_198;
  int iStack_194;
  char cStack_18d;
  int local_18c;   // residual: == this_listener (rate host)
  int *piStack_188;
  int *piStack_184;
  float local_180;
  int local_17c;
  uint32_t uStack_178;
  uint32_t uStack_174;
  int local_16c;
  uint32_t auStack_168[4];
  uint32_t uStack_158;
  uint32_t uStack_154;
  float fStack_14c;
  uint32_t uStack_13c;
  uint32_t uStack_138;
  uint32_t uStack_134;
  uint32_t uStack_130;
  uint32_t uStack_12c;
  uint32_t uStack_128;
  uint32_t uStack_124;
  void *local_1c;
  uint8_t *puStack_18;
  uint32_t local_14;

  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a720f;
  local_1c = ExceptionList;
  local_19c = DAT_00d1f040;
  ExceptionList = &local_1c;
  local_18c = this_listener;   // seal: decompiler residual filled from ECX

  FUN_0076cf00("CollisionListener::contact");
  local_14 = 0;
  piVar12 = (int *)0x0;
  local_19e = 1;
  fVar13 = (float10)FUN_0079a110();
  local_180 = (float)fVar13;

  // --- walk body A parent chain → host local_17c ---
  piVar10 = (int *)param_3[3];
  piVar6 = param_3;
  while (piVar2 = piVar10, piVar2 != (int *)0x0) {
    piVar6 = piVar2;
    piVar10 = (int *)piVar2[3];
  }
  local_17c = piVar6[8];

  // --- walk body B parent chain → host local_16c ---
  piVar10 = (int *)param_4[3];
  piVar6 = param_4;
  while (piVar2 = piVar10, piVar2 != (int *)0x0) {
    piVar6 = piVar2;
    piVar10 = (int *)piVar2[3];
  }
  local_16c = piVar6[8];

  // --- resolve game object A from host pair-list type==1 ---
  iVar5 = 0;
  if (0 < *(int *)(local_17c + 0x34)) {
    piVar6 = *(int **)(local_17c + 0x30);
    do {
      if (*piVar6 == 1) {
        piVar6 = (int *)(*(int **)(local_17c + 0x30))[iVar5 * 2 + 1];
        if ((piVar6 != (int *)0x0) && (((uint)piVar6[0x5f] >> 5 & 1) != 0)) {
          piVar12 = (int *)(**(code **)(*piVar6 + 0x1c8))();
        }
        break;
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 2;
    } while (iVar5 < *(int *)(local_17c + 0x34));
  }

  // --- resolve game object B ---
  piVar6 = (int *)0x0;
  iVar5 = 0;
  if (0 < *(int *)(local_16c + 0x34)) {
    piVar10 = *(int **)(local_16c + 0x30);
    do {
      if (*piVar10 == 1) {
        piVar10 = (int *)(*(int **)(local_16c + 0x30))[iVar5 * 2 + 1];
        if ((piVar10 != (int *)0x0) && (((uint)piVar10[0x5f] >> 5 & 1) != 0)) {
          piVar6 = (int *)(**(code **)(*piVar10 + 0x1c8))();
        }
        break;
      }
      iVar5 = iVar5 + 1;
      piVar10 = piVar10 + 2;
    } while (iVar5 < *(int *)(local_16c + 0x34));
  }

  // --- material type==1 special path (exclusive one side) ---
  if ((*(int *)(*param_3 + 8) == 1) || (*(int *)(*param_4 + 8) == 1)) {
    if ((piVar12 == (int *)0x0) || (piVar6 == (int *)0x0)) goto LAB_005dab08;
    if (*(int *)(*param_3 + 8) == 1) {
      if (*(int *)(*param_4 + 8) == 1) goto LAB_005dab08;
      fStack_198 = (float)(**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d4))();
      piVar10 = (int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6);
    }
    else {
      fStack_198 = (float)(**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d4))();
      piVar10 = (int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12);
    }
    iVar5 = (**(code **)(*piVar10 + 0x1c8))();
    if (((fStack_198 == 0.0) || (iVar5 == 0)) ||
       (iVar7 = *(int *)(*(int *)(iVar5 + 4) + 4),
        (*(uint *)(iVar7 + 0x180 + iVar5) >> 10 & 1) != 0)) goto LAB_005dab08;
    iVar7 = *(int *)(*(int *)(iVar7 + iVar5 + 0xac) + 0x38);
    if (((((iVar7 == 0x12) || (iVar7 == 0xe)) &&
         ((iVar7 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x210))(0),
          iVar7 == 0 ||
          ((iVar7 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x210))(0),
           iVar7 == 0 ||
           (cVar4 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x298))
                              (*(int *)(piVar6[1] + 4) + 4 + (int)piVar6), cVar4 != '\0')))))) &&
        (cVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))(),
        cVar4 != '\0')) &&
       (((iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1d8))(),
         iVar7 != 0 &&
         (iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1d8))(),
         (*(uint *)(iVar7 + 0x200) >> 4 & 1) != 0)) &&
        ((cVar4 = FUN_0040d080(), cVar4 == '\0' ||
         (*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x38) != 0x12))))))
    {
      if (*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x38) == 0x12) {
        (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1d8))();
        cVar4 = FUN_0040b1b0();
        if (cVar4 != '\0') goto LAB_005da392;
      }
      local_19e = 1;
    }
    else {
LAB_005da392:
      local_19e = 0;
    }
    piStack_188 = (int *)GetTickCount();
    iVar7 = *(int *)(*(int *)(iVar5 + 4) + 4);
    uStack_178 = *(uint32_t *)(iVar7 + 0x164 + iVar5);
    uVar1 = *(uint32_t *)(iVar7 + 0x168 + iVar5);
    iStack_194 = (int)fStack_198 + 0x2b8;
    uStack_174 = uVar1;
    auStack_168[0] = uStack_178;
    FUN_005dab60(&piStack_184, &uStack_178);
    if ((piStack_184 != *(int **)((int)fStack_198 + 700)) &&
       ((uint)((int)piStack_188 - piStack_184[6]) < DAT_00af43b4)) goto LAB_005daa60;
    uStack_178 = auStack_168[0];
    uStack_174 = uVar1;
    puVar8 = (uint32_t *)FUN_004055c0(&uStack_178);
    *puVar8 = piStack_188;
  }

  // type 0xe side hooks
  if ((piVar12 != (int *)0x0) &&
     (*(int *)(*(int *)(*(int *)(piVar12[1] + 4) + 0xac + (int)piVar12) + 0x38) == 0xe)) {
    (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d4))();
    FUN_004faf80();
  }
  if ((piVar6 != (int *)0x0) &&
     (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 0xe)) {
    (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d4))();
    FUN_004faf80();
  }

  // rate-limit contact flag via this+0x10 vs 0.5f
  if (local_180 - *(float *)(local_18c + 0x10) <= _DAT_00af4368) {
    iStack_194 = (uint)iStack_194._1_3_ << 8;
  }
  else {
    iStack_194 = CONCAT31(iStack_194._1_3_, 1);
    fVar13 = (float10)FUN_0079a110();
    *(float *)(local_18c + 0x10) = (float)fVar13;
  }
  iVar5 = iStack_194;
  cStack_18d = '\0';
  cStack_19d = '\0';
  FUN_005d9ea0(param_1, param_3, param_2, iStack_194, &cStack_18d);
  FUN_005d9ea0(param_1, param_4, param_2, iVar5, &cStack_19d);

  if ((piVar12 == (int *)0x0) || (piVar6 == (int *)0x0)) {
LAB_005da987:
    local_14 = 0xffffffff;
    FUN_0076cef0();
    ExceptionList = local_1c;
    return 1;
  }

  // affinity / mutual gates
  iVar5 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x210))(0);
  if ((iVar5 != 0) &&
     ((iVar5 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x210))(0),
      iVar5 != 0 &&
      (cVar4 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x298))
                         (*(int *)(piVar6[1] + 4) + 4 + (int)piVar6), cVar4 == '\0'))))
  goto LAB_005dab08;

  // sort lighter / heavier by vtbl+0x28
  fVar13 = (float10)(**(code **)(*piVar12 + 0x28))();
  local_180 = (float)fVar13;
  fVar13 = (float10)(**(code **)(*piVar6 + 0x28))();
  piStack_184 = piVar6;
  piStack_188 = piVar12;
  if (fVar13 < (float10)local_180) {
    piStack_184 = piVar12;
    piStack_188 = piVar6;
  }

  // impact energy
  if (piStack_184[2] == 0) {
    pfVar9 = (float *)&DAT_00bc5660;
  }
  else {
    pfVar9 = (float *)(*(int *)(piStack_184[2] + 0x3c) + 0x40);
  }
  local_180 = *pfVar9 * *pfVar9 + pfVar9[1] * pfVar9[1] + pfVar9[2] * pfVar9[2];
  fStack_198 = SQRT(local_180) * _DAT_00aaa994;   // * 3.6f
  fVar13 = (float10)(**(code **)(*piStack_184 + 0x2c))();
  fVar13 = (float10)fStack_198 * (float10)fStack_198 * fVar13 * (float10)_DAT_009db4e4;
  fStack_198 = (float)fVar13;
  if ((float10)DAT_00aaacd0 <= fVar13) {
    fStack_198 = DAT_00aaacd0;   // clamp 350
  }

  if (*(char *)(*(int *)(piVar12[1] + 4) + 0x26 + (int)piVar12) != '\0') {
    iVar5 = *(int *)(piVar6[1] + 4);
    piVar10 = (int *)FUN_00515170();
    (**(code **)(*piVar10 + 0x54))(iVar5 + 4 + (int)piVar6, fStack_198);
  }
  if (*(char *)(*(int *)(piVar6[1] + 4) + 0x26 + (int)piVar6) != '\0') {
    iVar5 = *(int *)(piVar12[1] + 4);
    piVar10 = (int *)FUN_00515170();
    (**(code **)(*piVar10 + 0x54))(iVar5 + 4 + (int)piVar12, fStack_198);
  }

  // type 0x12 hard gates both sides
  if (*(int *)(*(int *)(*(int *)(piVar12[1] + 4) + 0xac + (int)piVar12) + 0x38) == 0x12) {
    cVar4 = FUN_0040d080();
    if (cVar4 != '\0') goto LAB_005dab08;
    (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d8))();
    cVar4 = FUN_0040b1b0();
    if (cVar4 != '\0') goto LAB_005dab08;
  }
  if (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 0x12) {
    cVar4 = FUN_0040d080();
    if (cVar4 != '\0') goto LAB_005dab08;
    (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d8))();
    cVar4 = FUN_0040b1b0();
    if (cVar4 != '\0') goto LAB_005dab08;
  }
  if (((*(int *)(*(int *)(*(int *)(piVar12[1] + 4) + 0xac + (int)piVar12) + 0x38) == 0x12) &&
      (iVar5 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d8))(),
      (*(uint *)(iVar5 + 0x200) >> 4 & 1) != 0)) ||
     ((*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 0x12 &&
      (iVar5 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d8))(),
      (*(uint *)(iVar5 + 0x200) >> 4 & 1) != 0)))) goto LAB_005dab08;

  // FX + Logic-UI packet 0x29 when impact magnitude > 1.0
  if ((((char)iStack_194 != '\0') &&
      (iVar5 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d4))(),
      iVar5 != 0)) ||
     (iVar5 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d4))(),
     iVar5 != 0)) {
    if ((cStack_18d == '\0') && (cStack_19d == '\0')) {
      iStack_194 = 0;
      iVar5 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d4))();
      if (iVar5 == 0) {
        iVar7 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d4))();
        iVar5 = local_17c;
        if (iVar7 != 0) {
          piVar10 = (int *)FUN_0040afb0(&local_17c, 3);
          iVar5 = *piVar10;
          iStack_194 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d4))();
          if (iStack_194 == 0) {
            iStack_194 = 0;
          }
          else {
            iStack_194 = *(int *)(*(int *)(iStack_194 + 4) + 4) + 4 + iStack_194;
          }
        }
      }
      else {
        iStack_194 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d4))();
        if (iStack_194 == 0) {
          iStack_194 = 0;
        }
        else {
          iStack_194 = *(int *)(*(int *)(iStack_194 + 4) + 4) + 4 + iStack_194;
        }
        piVar10 = (int *)FUN_0040afb0(&local_17c, 3);
        iVar5 = *piVar10;
      }
      FUN_005d9af0(param_1, iVar5, *param_2, iStack_194, 1);
    }
    if (_DAT_00af4364 < ABS(*param_2)) {
      fStack_14c = ABS(*param_2);
      uStack_158 = 0;
      uStack_154 = 0;
      uStack_138 = *(uint32_t *)(*(int *)(piVar12[1] + 4) + 0x164 + (int)piVar12);
      uStack_134 = *(uint32_t *)(*(int *)(piVar12[1] + 4) + 0x168 + (int)piVar12);
      puVar8 = (uint32_t *)(*(int *)(piVar6[1] + 4) + 0x164 + (int)piVar6);
      uStack_12c = puVar8[1];
      uStack_130 = *puVar8;
      uStack_128 = puVar8[2];
      uStack_124 = puVar8[3];
      uStack_13c = 0x29;   // Logic-UI opcode
      Client_SendLogicUiPacket(&uStack_158);
    }
  }

  cVar4 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x298))
                    (*(int *)(piVar6[1] + 4) + 4 + (int)piVar6);
  if (cVar4 == '\0') goto LAB_005daa60;
  iVar5 = *(int *)(*(int *)(*(int *)(piVar12[1] + 4) + 0xac + (int)piVar12) + 0x38);
  if ((iVar5 == 3) && (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 3))
    goto LAB_005da987;
  if ((iVar5 != 0xe) &&
     (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) != 0xe)) {
    cStack_19d = '\x01';
    if (iVar5 == 0x12) {
      puVar14 = &DAT_009db428;
      puVar8 = auStack_168;
      (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d8))(puVar8);
      pvVar11 = (void *)FUN_004ba740(puVar8);
      iVar5 = TFID_NotEquals(pvVar11, puVar14);
      if ((char)iVar5 != '\0') {
        cStack_19d = '\0';
      }
    }
    if (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 0x12) {
      puVar14 = &DAT_009db428;
      puVar8 = auStack_168;
      (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d8))(puVar8);
      pvVar11 = (void *)FUN_004ba740(puVar8);
      iVar5 = TFID_NotEquals(pvVar11, puVar14);
      if ((char)iVar5 != '\0') goto LAB_005daa8f;
    }
    if (cStack_19d != '\0') {
LAB_005daa60:
      local_14 = 0xffffffff;
      FUN_0076cef0();
      ExceptionList = local_1c;
      return local_19e;
    }
  }
LAB_005daa8f:
  // bidirectional vehicle collision
  fVar3 = fStack_198;
  cVar4 = FUN_005d9290(piStack_184, piStack_188, param_2, fStack_198, param_1);
  if (cVar4 != '\0') {
    cVar4 = FUN_005d9290(piStack_188, piStack_184, param_2, fVar3, param_1);
    local_14 = 0xffffffff;
    if (cVar4 != '\0') {
      FUN_0076cef0();
      ExceptionList = local_1c;
      return local_19e;
    }
  }
LAB_005dab08:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return 0;
}

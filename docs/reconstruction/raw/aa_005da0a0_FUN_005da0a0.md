# Raw capture: FUN_005da0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005da0a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005da0a0` |
| **Canonical name** | `FUN_005da0a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_005da0a0(undefined4 param_1,float *param_2,int *param_3,int *param_4)



{

  undefined4 uVar1;

  int *piVar2;

  float fVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  undefined4 *puVar8;

  float *pfVar9;

  int *piVar10;

  void *pvVar11;

  int *piVar12;

  float10 fVar13;

  undefined4 *puVar14;

  undefined1 local_19e;

  char cStack_19d;

  undefined4 local_19c;

  float fStack_198;

  int iStack_194;

  char cStack_18d;

  int local_18c;

  int *piStack_188;

  int *piStack_184;

  float local_180;

  int local_17c;

  undefined4 uStack_178;

  undefined4 uStack_174;

  int local_16c;

  undefined4 auStack_168 [4];

  undefined4 uStack_158;

  undefined4 uStack_154;

  float fStack_14c;

  undefined4 uStack_13c;

  undefined4 uStack_138;

  undefined4 uStack_134;

  undefined4 uStack_130;

  undefined4 uStack_12c;

  undefined4 uStack_128;

  undefined4 uStack_124;

  void *local_1c;

  undefined1 *puStack_18;

  undefined4 local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a720f;

  local_1c = ExceptionList;

  local_19c = DAT_00d1f040;

  ExceptionList = &local_1c;

  FUN_0076cf00("CollisionListener::contact");

  local_14 = 0;

  piVar12 = (int *)0x0;

  local_19e = 1;

  fVar13 = (float10)FUN_0079a110();

  local_180 = (float)fVar13;

  piVar10 = (int *)param_3[3];

  piVar6 = param_3;

  while (piVar2 = piVar10, piVar2 != (int *)0x0) {

    piVar6 = piVar2;

    piVar10 = (int *)piVar2[3];

  }

  local_17c = piVar6[8];

  piVar10 = (int *)param_4[3];

  piVar6 = param_4;

  while (piVar2 = piVar10, piVar2 != (int *)0x0) {

    piVar6 = piVar2;

    piVar10 = (int *)piVar2[3];

  }

  local_16c = piVar6[8];

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

  if ((*(int *)(*param_3 + 8) == 1) || (*(int *)(*param_4 + 8) == 1)) {

    if ((piVar12 == (int *)0x0) || (piVar6 == (int *)0x0)) goto LAB_005dab08;

    if (*(int *)(*param_3 + 8) == 1) {

      if (*(int *)(*param_4 + 8) == 1) goto LAB_005dab08;

      fStack_198 = (float)(**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d4

                                      ))();

      piVar10 = (int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6);

    }

    else {

      fStack_198 = (float)(**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d4))

                                    ();

      piVar10 = (int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12);

    }

    iVar5 = (**(code **)(*piVar10 + 0x1c8))();

    if (((fStack_198 == 0.0) || (iVar5 == 0)) ||

       (iVar7 = *(int *)(*(int *)(iVar5 + 4) + 4), (*(uint *)(iVar7 + 0x180 + iVar5) >> 10 & 1) != 0

       )) goto LAB_005dab08;

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

    uStack_178 = *(undefined4 *)(iVar7 + 0x164 + iVar5);

    uVar1 = *(undefined4 *)(iVar7 + 0x168 + iVar5);

    iStack_194 = (int)fStack_198 + 0x2b8;

    uStack_174 = uVar1;

    auStack_168[0] = uStack_178;

    FUN_005dab60(&piStack_184,&uStack_178);

    if ((piStack_184 != *(int **)((int)fStack_198 + 700)) &&

       ((uint)((int)piStack_188 - piStack_184[6]) < DAT_00af43b4)) goto LAB_005daa60;

    uStack_178 = auStack_168[0];

    uStack_174 = uVar1;

    puVar8 = (undefined4 *)FUN_004055c0(&uStack_178);

    *puVar8 = piStack_188;

  }

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

  if (local_180 - *(float *)(local_18c + 0x10) <= _DAT_00af4368) {

    iStack_194 = (uint)iStack_194._1_3_ << 8;

  }

  else {

    iStack_194 = CONCAT31(iStack_194._1_3_,1);

    fVar13 = (float10)FUN_0079a110();

    *(float *)(local_18c + 0x10) = (float)fVar13;

  }

  iVar5 = iStack_194;

  cStack_18d = '\0';

  cStack_19d = '\0';

  FUN_005d9ea0(param_1,param_3,param_2,iStack_194,&cStack_18d);

  FUN_005d9ea0(param_1,param_4,param_2,iVar5,&cStack_19d);

  if ((piVar12 == (int *)0x0) || (piVar6 == (int *)0x0)) {

LAB_005da987:

    local_14 = 0xffffffff;

    FUN_0076cef0();

    ExceptionList = local_1c;

    return 1;

  }

  iVar5 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x210))(0);

  if ((iVar5 != 0) &&

     ((iVar5 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x210))(0),

      iVar5 != 0 &&

      (cVar4 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x298))

                         (*(int *)(piVar6[1] + 4) + 4 + (int)piVar6), cVar4 == '\0'))))

  goto LAB_005dab08;

  fVar13 = (float10)(**(code **)(*piVar12 + 0x28))();

  local_180 = (float)fVar13;

  fVar13 = (float10)(**(code **)(*piVar6 + 0x28))();

  piStack_184 = piVar6;

  piStack_188 = piVar12;

  if (fVar13 < (float10)local_180) {

    piStack_184 = piVar12;

    piStack_188 = piVar6;

  }

  if (piStack_184[2] == 0) {

    pfVar9 = (float *)&DAT_00bc5660;

  }

  else {

    pfVar9 = (float *)(*(int *)(piStack_184[2] + 0x3c) + 0x40);

  }

  local_180 = *pfVar9 * *pfVar9 + pfVar9[1] * pfVar9[1] + pfVar9[2] * pfVar9[2];

  fStack_198 = SQRT(local_180) * _DAT_00aaa994;

  fVar13 = (float10)(**(code **)(*piStack_184 + 0x2c))();

  fVar13 = (float10)fStack_198 * (float10)fStack_198 * fVar13 * (float10)_DAT_009db4e4;

  fStack_198 = (float)fVar13;

  if ((float10)DAT_00aaacd0 <= fVar13) {

    fStack_198 = DAT_00aaacd0;

  }

  if (*(char *)(*(int *)(piVar12[1] + 4) + 0x26 + (int)piVar12) != '\0') {

    iVar5 = *(int *)(piVar6[1] + 4);

    piVar10 = (int *)FUN_00515170();

    (**(code **)(*piVar10 + 0x54))(iVar5 + 4 + (int)piVar6,fStack_198);

  }

  if (*(char *)(*(int *)(piVar6[1] + 4) + 0x26 + (int)piVar6) != '\0') {

    iVar5 = *(int *)(piVar12[1] + 4);

    piVar10 = (int *)FUN_00515170();

    (**(code **)(*piVar10 + 0x54))(iVar5 + 4 + (int)piVar12,fStack_198);

  }

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

          piVar10 = (int *)FUN_0040afb0(&local_17c,3);

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

        piVar10 = (int *)FUN_0040afb0(&local_17c,3);

        iVar5 = *piVar10;

      }

      FUN_005d9af0(param_1,iVar5,*param_2,iStack_194,1);

    }

    if (_DAT_00af4364 < ABS(*param_2)) {

      fStack_14c = ABS(*param_2);

      uStack_158 = 0;

      uStack_154 = 0;

      uStack_138 = *(undefined4 *)(*(int *)(piVar12[1] + 4) + 0x164 + (int)piVar12);

      uStack_134 = *(undefined4 *)(*(int *)(piVar12[1] + 4) + 0x168 + (int)piVar12);

      puVar8 = (undefined4 *)(*(int *)(piVar6[1] + 4) + 0x164 + (int)piVar6);

      uStack_12c = puVar8[1];

      uStack_130 = *puVar8;

      uStack_128 = puVar8[2];

      uStack_124 = puVar8[3];

      uStack_13c = 0x29;

      Client_SendLogicUiPacket(&uStack_158);

    }

  }

  cVar4 = (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x298))

                    (*(int *)(piVar6[1] + 4) + 4 + (int)piVar6);

  if (cVar4 == '\0') goto LAB_005daa60;

  iVar5 = *(int *)(*(int *)(*(int *)(piVar12[1] + 4) + 0xac + (int)piVar12) + 0x38);

  if ((iVar5 == 3) && (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 3)

     ) goto LAB_005da987;

  if ((iVar5 != 0xe) &&

     (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) != 0xe)) {

    cStack_19d = '\x01';

    if (iVar5 == 0x12) {

      puVar14 = &DAT_009db428;

      puVar8 = auStack_168;

      (**(code **)(*(int *)(*(int *)(piVar12[1] + 4) + 4 + (int)piVar12) + 0x1d8))(puVar8);

      pvVar11 = (void *)FUN_004ba740(puVar8);

      iVar5 = TFID_NotEquals(pvVar11,puVar14);

      if ((char)iVar5 != '\0') {

        cStack_19d = '\0';

      }

    }

    if (*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xac + (int)piVar6) + 0x38) == 0x12) {

      puVar14 = &DAT_009db428;

      puVar8 = auStack_168;

      (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1d8))(puVar8);

      pvVar11 = (void *)FUN_004ba740(puVar8);

      iVar5 = TFID_NotEquals(pvVar11,puVar14);

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

  fVar3 = fStack_198;

  cVar4 = FUN_005d9290(piStack_184,piStack_188,param_2,fStack_198,param_1);

  if (cVar4 != '\0') {

    cVar4 = FUN_005d9290(piStack_188,piStack_184,param_2,fVar3,param_1);

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
```

---

## Live re-decompile (2026-07-29 W22-I)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x005da0a0`–`0x005dab25` (**2693 B** / `0xA85`) |
| **Epilogue** | `C2 10 00` (`RET 0x10`) — 4 stack formals + ECX this |
| **Profiler string** | `"CollisionListener::contact"` via `FUN_0076cf00` |
| **Caller** | sole: `FUN_005dab30` @ `0x005dab30` (site `0x005dab45`) |
| **Integrity** | Live decompile ≡ 2026-07-23 raw body (identical CF) |

### Prologue thiscall evidence

```
55 8B EC 83 E4 F0 6A FF 68 0F 72 9A 00 ... 81 EC 88 01 00 00 53 56 57 89 4C 24 24
```

`mov [esp+0x24], ecx` saves **this** (CollisionListener*). Caller `FUN_005dab30` does not clobber ECX before the call, so outer thiscall chains through.

### Sealed ABI

```
// __thiscall RET 0x10
// ECX = CollisionListener* this  (rate-limit stamp @ this+0x10; decompiler residual local_18c)
// stack0 = context token from contact event +0x14
// stack1 = float* impact (contact event +0x1c)
// stack2 = phys body/shape A*
// stack3 = phys body/shape B*
// AL = result (0 = reject/disable path → caller sets event+0x20=1; non-zero keep)
uint8_t Drive_CollisionListener_Contact(
    CollisionListener* this,
    uint32_t ctx,
    float* impact,
    int* bodyA,
    int* bodyB);
```

### Sealed constants (`read_memory`)

| Symbol | VA | Bytes | Value |
|---|---|---|---|
| `_DAT_00af4364` | `0x00af4364` | `00 00 80 3F` | **1.0f** (UI impact magnitude gate) |
| `_DAT_00af4368` | `0x00af4368` | `00 00 00 3F` | **0.5f** (contact time throttle) |
| `_DAT_00aaa994` | `0x00aaa994` | `66 66 66 40` | **3.6f** (speed scale) |
| `_DAT_009db4e4` | `0x009db4e4` | `BD 37 86 34` | **~2.5e-7f** (energy scale) |
| `DAT_00aaacd0` | `0x00aaacd0` | `00 00 AF 43` | **350.0f** (energy clamp) |
| `DAT_00af43b4` | `0x00af43b4` | `F4 01 00 00` | **500** (tick debounce ms) |
| UI opcode | imm | — | **0x29** (`uStack_13c`) |

### Caller contract (`FUN_005dab30`)

```
// pushes: bodyB, bodyA, &event->f1c, event->ctx
al = Contact(listener, *(ev+0x14), ev+0x1c, *(ev+8), *(ev+0xc))
if al == 0: *(ev+0x20) = 1
```

### High-level CF stages (see annotated / reviews)

1. Profiler enter `"CollisionListener::contact"`; sample time `FUN_0079a110`.
2. Walk body A/B parent chain (`[3]` links) → host at `[8]`.
3. Scan host pair-list (`+0x30`/`+0x34`) type==1; flag bit5 @ `obj+0x17c`; vtbl+0x1c8 → game objects.
4. Material-type==1 special path: resolve vehicle/char via vtbl+0x1d4; type filters 0x12/0xe; debounce map `FUN_005dab60` + `GetTickCount` vs 500 ms.
5. Type 0xe side paths → `FUN_004faf80`.
6. Rate-limit flag via `this+0x10` vs 0.5 s.
7. `FUN_005d9ea0` both bodies (per-body contact prep / flags out).
8. Missing game object → return 1.
9. Affinity gates vtbl+0x210 / +0x298; sort lighter/heavier via vtbl+0x28.
10. Impact energy: `\|v\|*3.6` squared * mass * 2.5e-7, clamp 350; apply via `FUN_00515170` + vtbl+0x54 if flag +0x26.
11. Type 0x12 gates (`FUN_0040d080`, `FUN_0040b1b0`, bit4 @ +0x200).
12. Optional FX `FUN_005d9af0`; if `ABS(*impact)>1.0` → `Client_SendLogicUiPacket` opcode 0x29 with both TFID halves @ +0x164/+0x168.
13. Type pair filters (3/3 early return 1; 0xe skip; 0x12 vs null TFID `DAT_009db428`).
14. Bidirectional `Drive_CollisionListener_DoVehicleCollision` (`FUN_005d9290`).
15. Return `local_19e` (default 1) or 0 on reject paths.

# Raw capture: FUN_004b8ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b8ed0` |
| **Canonical name** | `FUN_004b8ed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004b8ed0(byte *param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint uVar4;

  char cVar5;

  byte bVar6;

  int *piVar7;

  int *piVar8;

  float10 fVar9;

  uint local_10;

  void *local_c;

  undefined1 *puStack_8;

  undefined4 local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a155d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(int *)(DAT_00d17958 + 0x154) = *(int *)(DAT_00d17958 + 0x154) + 1;

  uVar4 = g_dwClientTickMs;

  if (g_dwClientTickMs - *(int *)(param_1 + 0xd0) < 0x1389) {

switchD_004b8f1f_caseD_7:

    *(uint *)(param_1 + 0xd0) = uVar4;

    cVar5 = FUN_004b7330();

    if (cVar5 == '\0') {

      FUN_004b75d0();

      iVar1 = *(int *)(*(int *)(DAT_00b04c70 + 0x2e4) + 8);

      if ((DAT_00b03e64 != '\0') ||

         (DAT_009cb2b0 <=

          *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x90) +

          *(float *)(iVar1 + 0x94) * *(float *)(iVar1 + 0x94) +

          *(float *)(iVar1 + 0x98) * *(float *)(iVar1 + 0x98))) {

        piVar7 = (int *)**(int **)(param_1 + 0x204);

        if (piVar7 != *(int **)(param_1 + 0x204)) {

          do {

            iVar2 = piVar7[2];

            if ((*(byte *)(iVar2 + 0x90e) & 1) == 0) {

              local_10 = CONCAT31(local_10._1_3_,*(byte *)(iVar2 + 0x90e) >> 3) & 0xffffff01;

              fVar9 = (float10)FUN_0079a110();

              FUN_00595230(*param_2,(float)fVar9);

              if ((*param_1 & 2) == 0) {

                bVar6 = FUN_0058e1a0(param_1 + 0xa0,local_10);

                param_1[0xd4] = param_1[0xd4] | bVar6;

              }

              piVar8 = (int *)*piVar7;

            }

            else {

              FUN_0076cf00("Destroy");

              piVar8 = (int *)*piVar7;

              local_4 = 0;

              if (piVar7 != *(int **)(param_1 + 0x204)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

              if (g_flZero < *(float *)(iVar2 + 0x798)) {

                FUN_00590c20(iVar2);

                *(undefined4 *)(iVar2 + 0x914) = 0;

              }

              FUN_005be2f0(iVar2);

              local_4 = 0xffffffff;

              FUN_0076cef0();

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x204));

        }

        piVar7 = (int *)**(int **)(param_1 + 0x1e0);

        if (piVar7 != *(int **)(param_1 + 0x1e0)) {

          do {

            iVar2 = piVar7[2];

            cVar5 = FUN_005bc3c0(param_2,*(undefined4 *)(param_1 + 0x2c),iVar1);

            if (cVar5 == '\0') {

              piVar8 = (int *)*piVar7;

              if (piVar7 != *(int **)(param_1 + 0x1e0)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

              FUN_005be310(iVar2);

            }

            else {

              FUN_005bb5e0(param_2,*(undefined4 *)(param_1 + 0x2c));

              piVar8 = (int *)*piVar7;

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x1e0));

        }

        piVar7 = (int *)**(int **)(param_1 + 0x210);

        if (piVar7 != *(int **)(param_1 + 0x210)) {

          do {

            pvVar3 = (void *)piVar7[2];

            cVar5 = FUN_005ba440(*param_2);

            if (cVar5 == '\0') {

              piVar8 = (int *)*piVar7;

              if (piVar7 != *(int **)(param_1 + 0x210)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

              if (pvVar3 != (void *)0x0) {

                FUN_005b85e0();

                    /* WARNING: Subroutine does not return */

                operator_delete(pvVar3);

              }

            }

            else {

              piVar8 = (int *)*piVar7;

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x210));

        }

        piVar7 = (int *)**(int **)(param_1 + 0x21c);

        if (piVar7 != *(int **)(param_1 + 0x21c)) {

          do {

            cVar5 = FUN_00498a50(*param_2);

            if (cVar5 == '\0') {

              piVar8 = (int *)*piVar7;

            }

            else {

              FUN_00498ab0(0);

              piVar8 = (int *)*piVar7;

              if (piVar7 != *(int **)(param_1 + 0x21c)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x21c));

        }

        FUN_004b6910();

      }

      ExceptionList = local_c;

      return 0;

    }

  }

  else {

    switch(*(undefined4 *)(param_1 + 0x28)) {

    case 4:

      cVar5 = FUN_004b6a80();

      if (cVar5 != '\0') goto switchD_004b8f1f_caseD_7;

    case 2:

    case 3:

    case 5:

    case 6:

    case 0xc:

    case 0xd:

    case 0xe:

    case 0x13:

    case 0x14:

    case 0x15:

    case 0x17:

      break;

    default:

      goto switchD_004b8f1f_caseD_7;

    }

  }

  FUN_004b7150();

  ExceptionList = local_c;

  return 1;

}
```


---

## W24-C re-verify (2026-07-29) — OWN-ONLY dual seal

| Field | Value |
|---|---|
| **Agent** | W24-C OWN-ONLY |
| **Tools** | `decompile_function` + `read_memory` + callers/callees/xrefs + `get_function_by_address` |
| **Forbidden** | `disassemble_bytes`; Launcher; parent ledger edits |
| **Body** | `0x004b8ed0`–`0x004b9240` (**880 B / `0x370`**) |
| **ABI** | `__thiscall` ECX=fx host; 1 stack arg; epilogue **`ret 4`** (`C2 04 00`); return AL 0/1 |
| **Entry** | SEH prolog `64 A1 … 6A FF 68 5D 15 9A 00`; counter `DAT_00d17958+0x154++`; `mov esi,ecx` |
| **Rate gate** | `cmp eax, 0x1388` + `jbe` ≡ delta < `0x1389` (5001 ms) vs stamp `this+0xd0` |
| **Cull float** | `DAT_009cb2b0` = `0x358637bd` ≈ **1e-6** (sq-len threshold) via `read_memory` |
| **Deactivate peer** | `FUN_004b7150` = sealed `NDSpecialFX_DeactivateClear_Inferred` (W23-H) |
| **Child tick** | `FUN_00595230` = sealed `CVOGObject_Tick` (W23-H); sole known child walk site |
| **Live decompile** | Matches scaffold body (CF identical). |

### Entry / exit bytes (`read_memory`)

```
@004b8ed0: 64 a1 00 00 00 00 6a ff 68 5d 15 9a 00 50 a1 58 79 d1 00 64 89 25 00 00 00 00
           83 80 54 01 00 00 01 83 ec 0c 56 57 8b 3d cc 41 b0 00 8b f1 ...
@004b8f00: 2b 86 d0 00 00 00 3d 88 13 00 00 76 40 8b 46 28 83 c0 fe 83 f8 15 ...
@004b9220..: ... 8b ce e8 e6 d6 ff ff (call FUN_004b7150) ... 32 c0 ... c2 04 00
@return-1: b0 01 ... c2 04 00
```

### Live decompile (authoritative for this pass)

```c
undefined4 __thiscall FUN_004b8ed0(byte *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  int *piVar7;
  int *piVar8;
  float10 fVar9;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a155d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)(DAT_00d17958 + 0x154) = *(int *)(DAT_00d17958 + 0x154) + 1;
  uVar4 = g_dwClientTickMs;
  if (g_dwClientTickMs - *(int *)(param_1 + 0xd0) < 0x1389) {
switchD_004b8f1f_caseD_7:
    *(uint *)(param_1 + 0xd0) = uVar4;
    cVar5 = FUN_004b7330();
    if (cVar5 == '\0') {
      FUN_004b75d0();
      iVar1 = *(int *)(*(int *)(DAT_00b04c70 + 0x2e4) + 8);
      if ((DAT_00b03e64 != '\0') ||
         (DAT_009cb2b0 <=
          *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x90) +
          *(float *)(iVar1 + 0x94) * *(float *)(iVar1 + 0x94) +
          *(float *)(iVar1 + 0x98) * *(float *)(iVar1 + 0x98))) {
        piVar7 = (int *)**(int **)(param_1 + 0x204);
        if (piVar7 != *(int **)(param_1 + 0x204)) {
          do {
            iVar2 = piVar7[2];
            if ((*(byte *)(iVar2 + 0x90e) & 1) == 0) {
              local_10 = CONCAT31(local_10._1_3_,*(byte *)(iVar2 + 0x90e) >> 3) & 0xffffff01;
              fVar9 = (float10)FUN_0079a110();
              FUN_00595230(*param_2,(float)fVar9);
              if ((*param_1 & 2) == 0) {
                bVar6 = FUN_0058e1a0(param_1 + 0xa0,local_10);
                param_1[0xd4] = param_1[0xd4] | bVar6;
              }
              piVar8 = (int *)*piVar7;
            }
            else {
              FUN_0076cf00("Destroy");
              piVar8 = (int *)*piVar7;
              local_4 = 0;
              if (piVar7 != *(int **)(param_1 + 0x204)) {
                *(int **)piVar7[1] = piVar8;
                *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
                operator_delete(piVar7);
              }
              if (g_flZero < *(float *)(iVar2 + 0x798)) {
                FUN_00590c20(iVar2);
                *(undefined4 *)(iVar2 + 0x914) = 0;
              }
              FUN_005be2f0(iVar2);
              local_4 = 0xffffffff;
              FUN_0076cef0();
            }
            piVar7 = piVar8;
          } while (piVar8 != *(int **)(param_1 + 0x204));
        }
        piVar7 = (int *)**(int **)(param_1 + 0x1e0);
        if (piVar7 != *(int **)(param_1 + 0x1e0)) {
          do {
            iVar2 = piVar7[2];
            cVar5 = FUN_005bc3c0(param_2,*(undefined4 *)(param_1 + 0x2c),iVar1);
            if (cVar5 == '\0') {
              piVar8 = (int *)*piVar7;
              if (piVar7 != *(int **)(param_1 + 0x1e0)) {
                *(int **)piVar7[1] = piVar8;
                *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
                operator_delete(piVar7);
              }
              FUN_005be310(iVar2);
            }
            else {
              FUN_005bb5e0(param_2,*(undefined4 *)(param_1 + 0x2c));
              piVar8 = (int *)*piVar7;
            }
            piVar7 = piVar8;
          } while (piVar8 != *(int **)(param_1 + 0x1e0));
        }
        piVar7 = (int *)**(int **)(param_1 + 0x210);
        if (piVar7 != *(int **)(param_1 + 0x210)) {
          do {
            pvVar3 = (void *)piVar7[2];
            cVar5 = FUN_005ba440(*param_2);
            if (cVar5 == '\0') {
              piVar8 = (int *)*piVar7;
              if (piVar7 != *(int **)(param_1 + 0x210)) {
                *(int **)piVar7[1] = piVar8;
                *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
                operator_delete(piVar7);
              }
              if (pvVar3 != (void *)0x0) {
                FUN_005b85e0();
                    /* WARNING: Subroutine does not return */
                operator_delete(pvVar3);
              }
            }
            else {
              piVar8 = (int *)*piVar7;
            }
            piVar7 = piVar8;
          } while (piVar8 != *(int **)(param_1 + 0x210));
        }
        piVar7 = (int *)**(int **)(param_1 + 0x21c);
        if (piVar7 != *(int **)(param_1 + 0x21c)) {
          do {
            cVar5 = FUN_00498a50(*param_2);
            if (cVar5 == '\0') {
              piVar8 = (int *)*piVar7;
            }
            else {
              FUN_00498ab0(0);
              piVar8 = (int *)*piVar7;
              if (piVar7 != *(int **)(param_1 + 0x21c)) {
                *(int **)piVar7[1] = piVar8;
                *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
                operator_delete(piVar7);
              }
            }
            piVar7 = piVar8;
          } while (piVar8 != *(int **)(param_1 + 0x21c));
        }
        FUN_004b6910();
      }
      ExceptionList = local_c;
      return 0;
    }
  }
  else {
    switch(*(undefined4 *)(param_1 + 0x28)) {
    case 4:
      cVar5 = FUN_004b6a80();
      if (cVar5 != '\0') goto switchD_004b8f1f_caseD_7;
    case 2:
    case 3:
    case 5:
    case 6:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x17:
      break;
    default:
      goto switchD_004b8f1f_caseD_7;
    }
  }
  FUN_004b7150();
  ExceptionList = local_c;
  return 1;
}
```


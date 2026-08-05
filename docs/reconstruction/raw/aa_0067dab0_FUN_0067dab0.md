# Raw capture: FUN_0067dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067dab0` |
| **Canonical name** | `FUN_0067dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0067dab0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 *_Dst;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(byte *)(param_1 + 6) <= (byte)param_2) {
    return 0;
  }
  bVar2 = *(byte *)(((uint)param_2 & 0xff) + 7 + param_1);
  if (bVar2 == 0) {
    uVar6 = FUN_0067cef0();
    return uVar6;
  }
  if (bVar2 == 0xfe) {
    iVar7 = 0;
    while (((*(int *)(param_1 + 0x2918) != 0 &&
            (param_2 = (undefined4 *)(*(int *)(param_1 + 0x291c) - *(int *)(param_1 + 0x2918) >> 2),
            param_2 != (undefined4 *)0x0)) && (iVar7 < 0x32))) {
      _Dst = *(undefined4 **)(param_1 + 0x2918);
      uVar6 = *_Dst;
      param_2 = operator_new(0x10);
      if (param_2 == (undefined4 *)0x0) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2a00);
        *(int *)(param_1 + 0x2a00) = iVar3 + 1;
        *param_2 = uVar6;
        param_2[1] = iVar3;
        param_2[2] = 0;
        *(undefined1 *)(param_2 + 3) = 0xfe;
        *(undefined1 *)((int)param_2 + 0xd) = 0;
      }
      iVar3 = *(int *)(param_1 + 0x2968);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(param_1 + 0x2970) - iVar3 >> 2) <=
          (uint)(*(int *)(param_1 + 0x296c) - iVar3 >> 2))) {
        FUN_0067f930(*(undefined4 *)(param_1 + 0x296c),1,&param_2);
      }
      else {
        puVar4 = *(undefined4 **)(param_1 + 0x296c);
        *puVar4 = param_2;
        *(undefined4 **)(param_1 + 0x296c) = puVar4 + 1;
      }
      memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x291c) - (int)(_Dst + 1) >> 2) * 4);
      *(int *)(param_1 + 0x291c) = *(int *)(param_1 + 0x291c) + -4;
      iVar7 = iVar7 + 1;
    }
  }
  else {
    if (bVar2 == 0xff) {
      uVar6 = FUN_0076cec0(&param_2,
                           "Session %lu: Packet on out queue is destined for internal channel",
                           *(undefined4 *)(param_1 + 0x2a20));
      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
                     ,0x710,3,uVar6);
      FUN_0067c590(0xff);
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0x124 + (uint)bVar2 * 0x28);
    iVar7 = param_1 + 0x114 + (uint)bVar2 * 0x28;
    if (iVar3 == 0) {
      param_2 = operator_new(0x10);
      if (param_2 == (undefined4 *)0x0) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        iVar3 = *(int *)(iVar7 + 0xc);
        uVar6 = *(undefined4 *)(iVar7 + 8);
        *param_2 = 0;
        param_2[1] = iVar3 + -1;
        param_2[2] = uVar6;
        *(byte *)(param_2 + 3) = bVar2;
        *(undefined1 *)((int)param_2 + 0xd) = 0;
      }
      if (*(int *)(param_1 + 0x2a3c) != 0) {
        piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x68);
        *piVar1 = *piVar1 + 1;
      }
      *(undefined1 *)(iVar7 + 0x21) = 0;
      *(undefined1 *)(iVar7 + 0x22) = 0;
      FUN_0067ffb0(&param_2);
      FUN_0067c590(bVar2);
      return 0;
    }
    if (*(char *)(iVar7 + 0x18) == '\0') {
      *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;
      param_2 = operator_new(0x10);
      if (param_2 == (undefined4 *)0x0) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        uVar6 = *(undefined4 *)(iVar7 + 8);
        uVar5 = *(undefined4 *)(iVar7 + 0xc);
        *param_2 = *(undefined4 *)(iVar7 + 0x10);
        param_2[1] = uVar5;
        param_2[2] = uVar6;
        *(byte *)(param_2 + 3) = bVar2;
        *(undefined1 *)((int)param_2 + 0xd) = 0;
      }
      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
      *(undefined4 *)(iVar7 + 0x14) = param_2[1];
      *(undefined1 *)(iVar7 + 0x18) = 1;
      *(int *)(iVar7 + 0x1c) = (int)*(float *)(param_1 + 0x29bc);
      *(int *)(iVar7 + 0x24) = (int)*(float *)(param_1 + 0x29bc);
      *(undefined1 *)(iVar7 + 0x20) = 1;
      *(undefined1 *)(iVar7 + 0x21) = 0;
      *(undefined1 *)(iVar7 + 0x22) = 0;
    }
    else {
      if ((float)*(double *)(param_1 + 0x29f8) <
          *(float *)(param_1 + 0x29bc) - (float)*(int *)(iVar7 + 0x1c)) {
        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;
        param_2 = operator_new(0x10);
        if (param_2 == (undefined4 *)0x0) {
          param_2 = (undefined4 *)0x0;
        }
        else {
          uVar6 = *(undefined4 *)(iVar7 + 8);
          uVar5 = *(undefined4 *)(iVar7 + 0x14);
          *param_2 = *(undefined4 *)(iVar7 + 0x10);
          param_2[1] = uVar5;
          param_2[2] = uVar6;
          *(byte *)(param_2 + 3) = bVar2;
          *(undefined1 *)((int)param_2 + 0xd) = 0;
        }
        *(int *)(iVar7 + 0x1c) = (int)*(float *)(param_1 + 0x29bc);
        *(undefined1 *)(iVar7 + 0x21) = 0;
        *(undefined1 *)(iVar7 + 0x22) = 0;
        if (*(int *)(param_1 + 0x2a3c) != 0) {
          piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x60);
          *piVar1 = *piVar1 + 1;
        }
        FUN_0067ffb0(&param_2);
        return 1;
      }
      if (*(char *)(iVar7 + 0x21) == '\0') {
        return 1;
      }
      param_2 = operator_new(0x10);
      if (param_2 == (undefined4 *)0x0) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        iVar3 = *(int *)(iVar7 + 0xc);
        uVar6 = *(undefined4 *)(iVar7 + 8);
        *param_2 = 0;
        param_2[1] = iVar3 + -1;
        param_2[2] = uVar6;
        *(byte *)(param_2 + 3) = bVar2;
        *(undefined1 *)((int)param_2 + 0xd) = 0;
      }
      *(undefined1 *)(iVar7 + 0x21) = 0;
      *(undefined1 *)(iVar7 + 0x22) = 0;
      if (*(int *)(param_1 + 0x2a3c) != 0) {
        piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x68);
        *piVar1 = *piVar1 + 1;
      }
    }
    FUN_0067ffb0(&param_2);
  }
  return 1;
}
```

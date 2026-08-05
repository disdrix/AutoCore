# Raw capture: FUN_0049fcd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049fcd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049fcd0` |
| **Canonical name** | `FUN_0049fcd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0049fcd0(int param_1,int *param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_EBX;
  undefined4 *puVar5;
  char cStack_299;
  undefined4 local_298;
  char *pcStack_294;
  char acStack_290 [128];
  wchar_t awStack_210 [2];
  undefined4 auStack_20c [130];
  
  iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_298);
  if ((-1 < iVar3) && (unaff_EBX != (int *)0x0)) {
    awStack_210[0] = L'\0';
    awStack_210[1] = L'\0';
    puVar5 = auStack_20c;
    for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    if (param_3 == '\0') {
      *(byte *)(param_1 + 0x90d) = *(byte *)(param_1 + 0x90d) | 1;
    }
    else {
      *(byte *)(param_1 + 0x90c) = *(byte *)(param_1 + 0x90c) | 0x80;
    }
    *(undefined1 *)(param_1 + 0x911) = 0;
    FUN_00798bb0(unaff_EBX,L"filename",awStack_210);
    pcStack_294 = acStack_290;
    uVar4 = (*(code *)PTR_FUN_00af8c9c)();
    FUN_00403450(awStack_210,uVar4);
    strncpy((char *)(param_1 + 0x2be),pcStack_294,0x7e);
    if (pcStack_294 != acStack_290) {
      free(pcStack_294);
    }
    FUN_00799300(unaff_EBX,L"mass",param_1 + 0x284);
    FUN_00799460(unaff_EBX,L"collisionFilter",param_1 + 0x900,10);
    cVar1 = FUN_007995a0(unaff_EBX,&local_298,L"initialVelocity",param_1 + 0x28c,param_1 + 0x298,
                         &cStack_299,0);
    FUN_005b8370(local_298,0xc,param_1 + 0x28c,param_1);
    *(byte *)(param_1 + 0x90c) =
         *(byte *)(param_1 + 0x90c) ^ (cStack_299 * '\b' ^ *(byte *)(param_1 + 0x90c)) & 8;
    if (cVar1 != '\0') {
      *(byte *)(param_1 + 0x90c) = *(byte *)(param_1 + 0x90c) | 0x20;
    }
    cVar1 = FUN_007994c0(unaff_EBX,L"initialRotation",param_1 + 0x2a4,param_1 + 0x2b0,&cStack_299,0)
    ;
    *(byte *)(param_1 + 0x90c) =
         *(byte *)(param_1 + 0x90c) ^ (cStack_299 * '\x04' ^ *(byte *)(param_1 + 0x90c)) & 4;
    if (cVar1 != '\0') {
      *(byte *)(param_1 + 0x90c) = *(byte *)(param_1 + 0x90c) | 0x40;
    }
    FUN_007996d0(unaff_EBX,L"relativeCoords",&stack0xfffffd5f);
    *(byte *)(param_1 + 0x90c) =
         *(byte *)(param_1 + 0x90c) ^ (cVar1 << 4 ^ *(byte *)(param_1 + 0x90c)) & 0x10;
    cVar2 = FUN_007996d0(unaff_EBX,L"useParentInitialVelocity",&stack0xfffffd5f);
    if (cVar2 != '\0') {
      *(byte *)(param_1 + 0x910) =
           *(byte *)(param_1 + 0x910) ^ (cVar1 * '\x02' ^ *(byte *)(param_1 + 0x910)) & 2;
    }
    cVar2 = FUN_007996d0(unaff_EBX,L"useParentInitialRotation",&stack0xfffffd5f);
    if (cVar2 != '\0') {
      *(byte *)(param_1 + 0x910) =
           *(byte *)(param_1 + 0x910) ^ (cVar1 * '\x04' ^ *(byte *)(param_1 + 0x910)) & 4;
    }
    *(undefined1 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    cVar1 = FUN_00798bb0(unaff_EBX,L"materialType",awStack_210);
    if (cVar1 != '\0') {
      iVar3 = _wcsicmp(L"Metal",awStack_210);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x2c) = 1;
      }
      else {
        iVar3 = _wcsicmp(L"Wood",awStack_210);
        if (iVar3 == 0) {
          *(undefined4 *)(param_1 + 0x2c) = 2;
        }
        else {
          iVar3 = _wcsicmp(L"Glass",awStack_210);
          if (iVar3 == 0) {
            *(undefined4 *)(param_1 + 0x2c) = 3;
          }
          else {
            iVar3 = _wcsicmp(L"Stone",awStack_210);
            if (iVar3 == 0) {
              *(undefined4 *)(param_1 + 0x2c) = 4;
            }
            else {
              iVar3 = _wcsicmp(L"Vehicle",awStack_210);
              if (iVar3 == 0) {
                *(undefined4 *)(param_1 + 0x2c) = 5;
              }
              else {
                iVar3 = _wcsicmp(L"Flesh",awStack_210);
                if (iVar3 == 0) {
                  *(undefined4 *)(param_1 + 0x2c) = 6;
                }
              }
            }
          }
        }
      }
    }
    FUN_00799820(unaff_EBX,L"materialSize",(undefined1 *)(param_1 + 0x30),10);
    cVar1 = FUN_00799300(unaff_EBX,L"constraintLength",param_1 + 0xa8);
    *(byte *)(param_1 + 0x90d) =
         *(byte *)(param_1 + 0x90d) ^ (cVar1 << 4 ^ *(byte *)(param_1 + 0x90d)) & 0x10;
    cVar1 = FUN_00799300(unaff_EBX,L"constraintBreak",(undefined4 *)(param_1 + 0xac));
    if (cVar1 == '\0') {
      *(undefined4 *)(param_1 + 0xac) = DAT_009c7c30;
    }
    FUN_007996d0(unaff_EBX,L"noCollide",param_1 + 0xb0);
    FUN_00799300(unaff_EBX,L"scaleX",param_1 + 0xb4);
    FUN_00799300(unaff_EBX,L"scaleY",param_1 + 0xb8);
    (**(code **)(*unaff_EBX + 8))(unaff_EBX);
    return 1;
  }
  return 0;
}
```

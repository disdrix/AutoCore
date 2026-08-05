# Raw capture: FUN_0073bad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073bad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073bad0` |
| **Canonical name** | `FUN_0073bad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x0073bb97) */

void __fastcall FUN_0073bad0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  int unaff_EBX;
  int *piVar7;
  undefined4 local_4;
  
  piVar7 = (int *)**(int **)(unaff_EBX + 8);
  local_4 = param_1;
  if (piVar7 != *(int **)(unaff_EBX + 8)) {
    do {
      piVar1 = (int *)piVar7[0xb];
      if (1 < piVar1[1]) {
        if ((uint)piVar1[0xc] < 0x10) {
          piVar6 = piVar1 + 7;
        }
        else {
          piVar6 = (int *)piVar1[7];
        }
        uVar5 = FUN_0076cec0(&local_4,"%i references to font %s not released",piVar1[1] + -1,piVar6)
        ;
        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontFactory.cpp",0x2c,3,
                       uVar5);
        iVar2 = piVar1[1];
        while (1 < iVar2) {
          piVar6 = piVar1 + 1;
          *piVar6 = *piVar6 + -1;
          if (*piVar6 == 0) {
            (**(code **)(*piVar1 + 8))();
          }
          iVar2 = piVar1[1];
        }
      }
      piVar6 = piVar1 + 1;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        (**(code **)(*piVar1 + 8))();
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)*(int *)(unaff_EBX + 8));
  }
  puVar3 = *(undefined4 **)(unaff_EBX + 8);
  pvVar4 = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(*(int *)(unaff_EBX + 8) + 4) = *(int *)(unaff_EBX + 8);
  *(undefined4 *)(unaff_EBX + 0xc) = 0;
  if (pvVar4 != *(void **)(unaff_EBX + 8)) {
    FUN_00464120();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar4);
  }
  local_4 = *(undefined4 *)(unaff_EBX + 8);
  if (*(int *)(unaff_EBX + 0x14) != *(int *)(unaff_EBX + 0x18)) {
    *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x14);
  }
  FUN_00463e30(*(undefined4 *)(unaff_EBX + 0x14),9,&local_4);
  *(undefined4 *)(unaff_EBX + 0x20) = 1;
  *(undefined4 *)(unaff_EBX + 0x24) = 1;
  return;
}
```

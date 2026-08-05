# Annotated low-level: FUN_007add10

| Field | Value |
|---|---|
| Stable ID | `aa_007add10` |
| VA | `0x007add10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007add10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007adf2e) */
/* WARNING: Removing unreachable block (ram,0x007adf4b) */
/* WARNING: Removing unreachable block (ram,0x007adf53) */
/* WARNING: Removing unreachable block (ram,0x007adf69) */
/* WARNING: Removing unreachable block (ram,0x007adf6e) */
/* WARNING: Removing unreachable block (ram,0x007adf58) */
/* WARNING: Removing unreachable block (ram,0x007adf72) */
/* WARNING: Removing unreachable block (ram,0x007adf94) */
/* WARNING: Removing unreachable block (ram,0x007ae01d) */
/* WARNING: Removing unreachable block (ram,0x007ae051) */
/* WARNING: Removing unreachable block (ram,0x007ae038) */
/* WARNING: Removing unreachable block (ram,0x007adfb5) */
/* WARNING: Removing unreachable block (ram,0x007adfc9) */
/* WARNING: Removing unreachable block (ram,0x007adfcb) */
/* WARNING: Removing unreachable block (ram,0x007adfd0) */
/* WARNING: Removing unreachable block (ram,0x007adfdf) */
/* WARNING: Removing unreachable block (ram,0x007adfff) */
/* WARNING: Removing unreachable block (ram,0x007ae007) */
/* WARNING: Removing unreachable block (ram,0x007ae058) */
/* WARNING: Removing unreachable block (ram,0x007ae05a) */
/* WARNING: Removing unreachable block (ram,0x007ae00c) */
/* WARNING: Removing unreachable block (ram,0x007ae05e) */
/* WARNING: Removing unreachable block (ram,0x007ae075) */
/* WARNING: Removing unreachable block (ram,0x007ae07f) */
/* WARNING: Removing unreachable block (ram,0x007ae086) */
/* WARNING: Removing unreachable block (ram,0x007ae090) */
/* WARNING: Removing unreachable block (ram,0x007ae097) */
/* WARNING: Removing unreachable block (ram,0x007ae0a1) */

void FUN_007add10(int *param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  BSTR unaff_ESI;
  int *piVar7;
  int **ppiVar8;
  wchar_t *_Str1;
  wchar_t *pwVar9;
  BSTR pOStack_8d4;
  int *local_8c4 [2];
  int local_8bc;
  int *piStack_8b8;
  int **ppiStack_8b4;
  int *piStack_8b0;
  wchar_t awStack_8ac [2];
  OLECHAR local_8a8 [60];
  undefined4 uStack_830;
  undefined4 auStack_82c [514];
  undefined1 uStack_24;
  void *pvStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009aced2;
  pvStack_14 = ExceptionList;
  local_8c4[0] = (int *)0x0;
  pOStack_8d4 = local_8a8;
  local_c = 0;
  ExceptionList = &pvStack_14;
  (**(code **)(*param_1 + 0x30))();
  if (piStack_8b0 != (int *)0x0) {
    _Str1 = awStack_8ac;
    (**(code **)(*piStack_8b0 + 0x20))(piStack_8b0);
    piStack_8b0 = (int *)0x0;
    if (0 < (int)ppiStack_8b4) {
      do {
        piVar7 = piStack_8b0;
        iVar2 = (**(code **)(*piStack_8b8 + 0x1c))(piStack_8b8,piStack_8b0,local_8c4);
        if (iVar2 == 0) {
          SysFreeString(pOStack_8d4);
          pOStack_8d4 = (OLECHAR *)0x0;
          (**(code **)(*local_8c4[0] + 0x1c))(local_8c4[0],&pOStack_8d4);
          iVar2 = wcscmp(_Str1,L"#text");
          if (iVar2 == 0) {
            SysFreeString(_Str1);
            _Str1 = (wchar_t *)0x0;
            (**(code **)(*(int *)unaff_ESI + 0x68))(unaff_ESI,&stack0xfffff724);
            if (_Str1 != (wchar_t *)0x0) {
              ppiStack_8b4 = &piStack_8b0;
              pwVar9 = _Str1;
              uVar3 = (*(code *)PTR_FUN_00af8c9c)();
              FUN_00403450(_Str1,uVar3);
              uStack_24 = 1;
              uVar3 = 0xffffffff;
              ppiVar8 = ppiStack_8b4;
              FUN_007a69d0(ppiStack_8b4,0xffffffff);
              pcVar4 = (char *)FUN_007a6de0(ppiVar8,uVar3);
              uStack_24 = 0;
              _Str1 = pwVar9;
              if (ppiStack_8b4 != &piStack_8b0) {
                free(ppiStack_8b4);
                _Str1 = pwVar9;
              }
              if ((param_3 == '\x01') && (local_8bc == 1)) {
                (**(code **)(*(int *)pOStack_8d4 + 0x1d8))(pcVar4,1,1);
              }
              else {
                puVar5 = operator_new(8);
                if (puVar5 == (undefined4 *)0x0) {
                  puVar5 = (undefined4 *)0x0;
                }
                else {
                  *puVar5 = 0;
                  puVar5[1] = 0;
                }
                *puVar5 = 1;
                pcVar6 = pcVar4;
                do {
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                pcVar6 = operator_new__((uint)(pcVar6 + (1 - (int)(pcVar4 + 1))));
                puVar5[1] = pcVar6;
                do {
                  cVar1 = *pcVar4;
                  *pcVar6 = cVar1;
                  pcVar4 = pcVar4 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                FUN_0041c7e0(pOStack_8d4 + 0xf4,puVar5);
              }
            }
          }
          else {
            iVar2 = wcscmp(_Str1,L"FONT");
            if (iVar2 == 0) {
              uStack_830 = 0;
              puVar5 = auStack_82c;
              for (iVar2 = 0x1ff; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar5 = 0;
                puVar5 = puVar5 + 1;
              }
              local_8c4[0] = (int *)0x0;
              (**(code **)(*(int *)unaff_ESI + 0x44))(unaff_ESI,&stack0xfffff738);
            }
          }
          (**(code **)(*(int *)unaff_ESI + 8))(unaff_ESI);
          piVar7 = piStack_8b0;
        }
        piStack_8b0 = (int *)((int)piVar7 + 1);
      } while ((int)piStack_8b0 < (int)ppiStack_8b4);
    }
    (**(code **)(*piStack_8b8 + 8))(piStack_8b8);
  }
  SysFreeString(unaff_ESI);
  ExceptionList = pvStack_1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

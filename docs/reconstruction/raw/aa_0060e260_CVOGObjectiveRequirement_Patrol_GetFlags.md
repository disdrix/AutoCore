# Raw capture: CVOGObjectiveRequirement_Patrol_GetFlags

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e260` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060e260` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetFlags` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGObjectiveRequirement_Patrol_GetFlags(int param_1,FILE *param_2)

{
  FILE *_File;
  undefined4 *puVar1;
  
  _File = param_2;
  fprintf(param_2,"\t\t<Requirement type=\"patrol\" slot=\"%d\">\r\n");
  fprintf(param_2,"\t\t\t<AutoComplete>%d</AutoComplete>\r\n",
          (uint)(*(char *)(param_1 + 0x10) != '\0'));
  fprintf(param_2,"\t\t\t<AutoCompleteDistance>%f</AutoCompleteDistance>\r\n",
          (double)*(float *)(param_1 + 0x14));
  fprintf(param_2,"\t\t\t<AutoFail>%d</AutoFail>\r\n",(uint)(*(char *)(param_1 + 0x18) != '\0'));
  fprintf(param_2,"\t\t\t<AutoFailDistance>%f</AutoFailDistance>\r\n",
          (double)*(float *)(param_1 + 0x1c));
  fprintf(param_2,"\t\t\t<ContinentCBID>%d</ContinentCBID>\r\n",*(undefined4 *)(param_1 + 0x28));
  param_2 = (FILE *)0x0;
  if (0 < *(int *)(param_1 + 0xd0)) {
    puVar1 = (undefined4 *)(param_1 + 0x30);
    do {
      fprintf(_File,"\t\t\t<GenericTargetCOID>%i</GenericTargetCOID>\r\n",*puVar1,puVar1[1]);
      param_2 = (FILE *)((int)param_2 + 1);
      puVar1 = puVar1 + 2;
    } while ((int)param_2 < *(int *)(param_1 + 0xd0));
  }
  fprintf(_File,"\t\t\t<Laps>%i</Laps>\r\n");
  fprintf(_File,"\t\t</Requirement>\r\n");
  return;
}
```

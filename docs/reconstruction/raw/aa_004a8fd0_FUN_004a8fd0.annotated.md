# Annotated low-level: FUN_004a8fd0

| Field | Value |
|---|---|
| Stable ID | `aa_004a8fd0` |
| VA | `0x004a8fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a8fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004a8fd0(byte param_1,char *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  puVar1 = &DAT_00aefb88;
  do {
    if (*puVar1 == (uint)param_1) {
      iVar3 = iVar2;
      if (iVar2 != 0) goto LAB_004a9012;
      break;
    }
    puVar1 = puVar1 + 0x15;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0xaf06b0);
  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp",0x857,3,
                 "Invalid tileset type! defaulting to Universal");
  iVar2 = iVar3;
LAB_004a9012:
  sprintf(param_2,"..\\editors\\textures\\%s",(&PTR_s_tile_mnt_ground_01_dds_00aefb90)[iVar2 * 0x15]
         );
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

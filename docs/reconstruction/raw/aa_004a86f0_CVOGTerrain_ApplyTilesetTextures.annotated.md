# Annotated low-level: CVOGTerrain_ApplyTilesetTextures

| Field | Value |
|---|---|
| Stable ID | `aa_004a86f0` |
| VA | `0x004a86f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a86f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGTerrain::ApplyTilesetTextures [VOGTerrain.cpp]. Maps m_ucTileSet (this+0x1c) -> 8 terrain
   texture layer indices (this+0x344..+0x360) via per-tileset table at DAT_00aefb60/DAT_00aefb88
   (stride 0x15 dwords). Terrain is rendered with 8 blended texture layers chosen by tileset type.
   Defaults to Universal on invalid tileset. */

void __fastcall CVOGTerrain_ApplyTilesetTextures(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  puVar1 = &DAT_00aefb88;
  do {
    if (*puVar1 == (uint)*(byte *)(param_1 + 0x1c)) {
      iVar3 = iVar2;
      if (iVar2 != 0) goto LAB_004a8733;
      break;
    }
    puVar1 = puVar1 + 0x15;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0xaf06b0);
  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp",0x288,3,
                 "Invalid tileset type! defaulting to Universal");
  iVar2 = iVar3;
LAB_004a8733:
  iVar3 = (&DAT_00aefb9c)[iVar2 * 0x15];
  *(int *)(param_1 + 0x364) = iVar3;
  *(undefined4 *)(param_1 + 0x344) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefba0)[iVar2 * 0x15];
  *(int *)(param_1 + 0x368) = iVar3;
  *(undefined4 *)(param_1 + 0x348) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefba4)[iVar2 * 0x15];
  *(int *)(param_1 + 0x36c) = iVar3;
  *(undefined4 *)(param_1 + 0x34c) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefba8)[iVar2 * 0x15];
  *(int *)(param_1 + 0x370) = iVar3;
  *(undefined4 *)(param_1 + 0x350) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefbac)[iVar2 * 0x15];
  *(int *)(param_1 + 0x374) = iVar3;
  *(undefined4 *)(param_1 + 0x354) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefbb0)[iVar2 * 0x15];
  *(int *)(param_1 + 0x378) = iVar3;
  *(undefined4 *)(param_1 + 0x358) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefbb4)[iVar2 * 0x15];
  *(int *)(param_1 + 0x37c) = iVar3;
  *(undefined4 *)(param_1 + 0x35c) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  iVar3 = (&DAT_00aefbb8)[iVar2 * 0x15];
  *(int *)(param_1 + 0x380) = iVar3;
  *(undefined4 *)(param_1 + 0x360) = *(undefined4 *)(&DAT_00aefb60 + iVar3 * 4);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

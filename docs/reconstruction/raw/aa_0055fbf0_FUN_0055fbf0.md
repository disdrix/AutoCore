# Raw capture: FUN_0055fbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fbf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0055fbf0` |
| **Canonical name** | `FUN_0055fbf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x0055fcee) */

void __thiscall FUN_0055fbf0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_38;
  int iStack_34;
  undefined **ppuStack_24;
  int iStack_20;
  undefined1 *puStack_1c;
  int iStack_18;
  int iStack_14;
  undefined1 auStack_10 [16];
  
  FUN_0062d960(*(undefined4 *)(param_1 + 0x234));
  if ((*(int *)(param_2 + 0xc) != 0) &&
     ((**(code **)(**(int **)(param_1 + 0xc4) + 0xc))(param_2 + 0x1c,&local_38), 0 < iStack_34)) {
    if (*(char *)(param_2 + 0x40) == '\0') {
      FUN_006297e0(0,0,local_38,iStack_34);
    }
    else {
      puStack_1c = auStack_10;
      ppuStack_24 = &PTR_FUN_009d2820;
      iStack_18 = 0;
      iStack_14 = -0x7ffffffc;
      *(undefined ****)(*(int *)(param_1 + 0x138) + 0x24) = &ppuStack_24;
      if (*(int *)(param_1 + 0xd0) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 0xd0) + 8;
      }
      iStack_20 = param_2 + 0xc;
      FUN_006caaa0(0,0,local_38,iStack_34,iVar2);
      iVar2 = 0;
      *(int *)(*(int *)(param_1 + 0x138) + 0x24) = *(int *)(param_1 + 0x138) + 0x100;
      if (0 < iStack_18) {
        do {
          iVar1 = *(int *)(puStack_1c + iVar2 * 4);
          FUN_006297e0(0,0,*(undefined4 *)(iVar1 + 0x8c),*(undefined4 *)(iVar1 + 0x90));
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar1 + 0x90) = 0;
        } while (iVar2 < iStack_18);
      }
      if (-1 < iStack_14) {
        (**(code **)(*DAT_00b05060 + 0x14))(puStack_1c,iStack_14 * 4,0x12);
        FUN_0055f4c0();
        return;
      }
    }
  }
  FUN_0055f4c0();
  return;
}
```


---

## Re-verify append — W26-D 2026-07-29

| Field | Value |
|---|---|
| **Tool** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Disasm** | **Not used** |
| **Live decompile** | **Identical** to raw 2026-07-23 body above (unreachable-block warning retained) |
| **Body** | `0x0055fbf0`–`0x0055fd72` (**386 B** exclusive end); pad `CC` after final `C2 04 00` |
| **ABI** | **thiscall**; ECX = manager; stack `Object* obj`; **`ret 4`**; void |
| **CF** | `FUN_0062d960(*(mgr+0x234))` ? gate `*(obj+0xc)!=0` + vcall `*(**(mgr+0xc4)+0xc)(obj+0x1c,&out)` with count>0 ? branch `*(obj+0x40)` simple `FUN_006297e0` vs complex `FUN_006caaa0`+loop clears ? always `FUN_0055f4c0` |
| **Callees** | `FUN_0062d960`, `FUN_006297e0`, `FUN_006caaa0`, `FUN_0055f4c0`, vcall on `*(mgr+0xc4)`, optional free via `*DAT_00b05060+0x14`; analyze also lists `FUN_005b3300` (growth helper; decompiler marked related block unreachable) |
| **Callers (4)** | `FUN_00560e90` (RebindActivate), `FUN_00561450` (RemoveOrDefer), `FUN_005614f0`, `FUN_00561370` — 5 xrefs |
| **Role** | Manager **unbind / remove spatial-query links** for world object (pair of bind `FUN_0055fa40`) |
| **Name (inferred)** | `WorldObj_UnbindLinks_Inferred` |
| **Decompile = bytes** | **Yes** for sealed CF/ABI (`ret 4` both epilogues) |

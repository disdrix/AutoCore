# Raw capture: FUN_008ab8f0

> **REDIRECT (2026-07-29):** Canonical name is now **`Client_MissionDialog_FlushPreparedResponse`**.
> Prefer: [`aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md`](aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md)
> Function record: `docs/reconstruction/functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md`
> This legacy scaffold is retained so older links do not break. Do not edit the original body below; new captures append only under the promoted filename.

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ab8f0` |
| **Canonical name** | `FUN_008ab8f0` → **`Client_MissionDialog_FlushPreparedResponse`** |
| **System** | missions-progression (was unknown) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008ab8f0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1[0x194] != 0) && (g_pSectorNetConnection_INFERRED != (void *)0x0)) {
    (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,param_1 + 0x194,0x20,0)
    ;
  }
  if ((((DAT_00d1d8dc != (int *)0x0) &&
       (cVar1 = (**(code **)(*DAT_00d1d8dc + 0x3d8))(), cVar1 != '\0')) &&
      (cVar1 = (**(code **)(*DAT_00d1d8dc + 0xd0))(), cVar1 != '\0')) && (DAT_00d1d8dc[0x146] != 0))
  {
    iVar3 = 0;
    piVar2 = param_1 + 0x156;
    do {
      if ((*piVar2 == DAT_00d1d8dc[0x148]) && (piVar2[1] == DAT_00d1d8dc[0x149])) {
        DAT_00d1d8f4 = 1;
        DAT_00d1d8f5 = 0;
        (**(code **)(*DAT_00d1d8dc + 4))(0);
        break;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar3 < 4);
  }
  FUN_008aa320();
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```

---

## Versioned note (2026-07-29) — promotion, body unchanged

Promoted to `Client_MissionDialog_FlushPreparedResponse`. Re-verify decompile (identical control flow) + assembly:

- `param_1[0x194]` ≡ `dialog+0x650` (`0x194*4`); `LEA [ESI+0x650]`, `PUSH 0x20`, `CALL [EDX+0x18]` with connection `DAT_00d1b4b8`
- This is the **C2S 0x206E send site** (opcode already in buffer from `Client_NpcDialog_PrepareResponseOpcode`)
- Full unit: `aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` (+ annotated / clean / function record)

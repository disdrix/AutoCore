# Raw capture: Client_MissionDialog_FlushPreparedResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ab8f0` |
| **Canonical name** | `Client_MissionDialog_FlushPreparedResponse` |
| **Prior name** | `FUN_008ab8f0` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-29` (re-verify; original scaffold 2026-07-23) |
| **Tool** | Ghidra MCP `decompile_function` + `get_assembly_context` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_MissionDialog_FlushPreparedResponse (FUN_008ab8f0)
   
   If prepared response opcode at dialog+0x650 (param_1[0x194]) is non-zero,
   send 0x20 bytes from that address via sector connection DAT_00d1b4b8 vtbl+0x18.
   Opcode 0x206E is written by Client_NpcDialog_PrepareResponseOpcode. */

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

## Assembly notes (send site, 2026-07-29)

```
008ab8f0  PUSH ESI
008ab8f1  MOV ESI, ECX
008ab8f3  CMP dword ptr [ESI + 0x650], 0
008ab8fa  LEA EAX, [ESI + 0x650]
008ab900  JZ  skip_send
008ab902  MOV ECX, dword ptr [0x00d1b4b8]
008ab908  TEST ECX, ECX
008ab90a  JZ  skip_send
008ab90c  MOV EDX, dword ptr [ECX]
008ab90e  PUSH 0
008ab910  PUSH 0x20
008ab912  PUSH EAX
008ab913  PUSH -1
008ab915  CALL dword ptr [EDX + 0x18]
```

DATA xref (vtable): `0x00a4a95c` → `0x008ab8f0`

---

## Residual re-verify (2026-07-29) — UF-010 invoker

Live `decompile_function(0x008ab8f0)` ≡ body above (param_1[0x194]/0x20/DAT_00d1b4b8).

| Item | Evidence |
|---|---|
| Vtable base | Ctor `FUN_008ac3f0`: `*param_1 = &PTR_FUN_00a4a51c` (`0x00a4a51c`) |
| Slot math | `0x00a4a51c + 0x440 = 0x00a4a95c`; `read_memory` dword = `0x008ab8f0` |
| Host | UI init `FUN_0093e7e0`: `*(client+0x1058) = FUN_008ac3f0()`; Show uses `+0x1058` |
| Index | `(0x1058-0x1030)/4 = 10` |
| Invoker | `FUN_007fca10`: if `vtbl+0x3d8` visible → `CALL vtbl+0x440` |
| Event paths | `FUN_008aec40`: HandleButton success / close `0x9c40` → `FUN_007fca10`; `FUN_008af020` same |
| Non-invoker | `Client_HideMissionDialogIfOpen` @ `0x0092ce50` uses `+0x107c` only |

Open residual: UF-011 (no clear of `+0x650` after send; close without fill still flushes).

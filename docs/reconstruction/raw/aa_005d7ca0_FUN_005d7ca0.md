# Raw capture: FUN_005d7ca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7ca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d7ca0` |
| **Canonical name** | `FUN_005d7ca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005d7ca0(int *param_1)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  undefined4 *puVar5;

  undefined4 local_8;

  int local_4;

  

  puVar5 = &local_8;

  local_8 = *(undefined4 *)

             (*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac + param_1[0x19]) +

                      0x3c) + 0x4dc);

  piVar4 = &local_4;

  FUN_00540890(0);

  FUN_004cbd50(piVar4,puVar5);

  iVar2 = FUN_00540890(0);

  if (local_4 == *(int *)(iVar2 + 4)) {

    return;

  }

  FUN_004c3c80(0);

  if (*(char *)(param_1[0x19] + 0x26c) == '\0') {

    NPC_TryCastSkillFromSet(param_1,0);

    FUN_005cedf0();

    if ((char)param_1[0x18] == '\0') {

      cVar1 = FUN_005cc980();

      if (cVar1 != '\0') {

        return;

      }

      (**(code **)(*param_1 + 0x1c))();

      if (*(int *)(param_1[6] + 0xa0) != 0) {

        (**(code **)(*param_1 + 0x2c))(2);

      }

      cVar1 = FUN_005cebd0(0);

      if (cVar1 != '\0') {

        return;

      }

      iVar2 = *param_1;

      uVar3 = (**(code **)(*(int *)param_1[6] + 0x1a0))(0);

      (**(code **)(iVar2 + 0x4c))(uVar3);

      return;

    }

  }

  else {

    NPC_TryCastSkillFromSet(param_1,2);

    FUN_005cedf0();

    if ((char)param_1[0x18] == '\0') {

      cVar1 = FUN_005cc980();

      if (cVar1 != '\0') {

        return;

      }

      if (*(int *)(param_1[6] + 0xa0) != 0) {

        FUN_005cf560();

      }

      if (*(int *)(param_1[6] + 0xa0) != 0) {

        return;

      }

      (**(code **)(*param_1 + 0x2c))(0);

      return;

    }

  }

  FUN_005cc450();

  return;

}
```

---

## W27-I live re-verify (2026-07-29)

| Field | Value |
|---|---|
| **Tooling** | `decompile_function` + `analyze_function_complete` + `read_memory` + callees/xrefs. **No** `disassemble_bytes`. |
| **Live decompile** | ≡ raw 2026-07-23 control flow (profile lower_bound; clear owner flag via `FUN_004c3c80(0)`; binary branch on owner+0x26c; skill sets 0/2; aim; busy/path/vtbl tails). |
| **Body** | `0x005d7ca0`–`0x005d7dd0` (**305 B** inclusive last `RET`). Pad `CC` after. |
| **Prolog/epilog** | `SUB ESP,8; PUSH ESI; MOV ESI,ECX` … `POP EDI; POP ESI; ADD ESP,8; RET` (`C3`). |
| **Vtbl** | Sole DATA xref `0x009db0dc` inside `PTR_FUN_009db08c` (installed by factory case-4 ctor `FUN_005d7de0`). Slot `+0x50` from vtbl base. |
| **Host global** | `MOV ECX,[DAT_00b041fc]` before each `FUN_00540890`. |
| **Owner** | `this+0x64` (`param_1[0x19]`) — same owner slot as Driver/CreatureBase DoLogic. |
| **Classification** | worker |
| **Named** | `CVOGHBAI_ProfileType4_DoLogic_Inferred` (structural twin of sealed DoLogic family; no in-body plate string). |

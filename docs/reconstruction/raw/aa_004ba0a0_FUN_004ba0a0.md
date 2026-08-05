# Raw capture: FUN_004ba0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba0a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ba0a0` |
| **Canonical name** | `FUN_004ba0a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
char __fastcall FUN_004ba0a0(int param_1)



{

  int iVar1;

  char cVar2;

  char cVar3;

  undefined4 uVar4;

  int *piVar5;

  int iVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  char local_8;

  uint local_4;

  

  local_8 = '\x01';

  cVar2 = '\x01';

  if (*(char *)(param_1 + 8) != '\0') {

    return '\x01';

  }

  piVar5 = *(int **)(param_1 + 0x10);

  if (piVar5 != (int *)0x0) {

    switch(*(undefined4 *)(param_1 + 0x28)) {

    case 4:

      cVar3 = FUN_004b6a80();

      if (cVar3 != '\0') break;

    case 5:

    case 6:

    case 0xc:

    case 0xd:

    case 0xe:

    case 0x14:

    case 0x15:

      if (*(char *)(param_1 + 0xb) != '\0') {

        cVar2 = '\0';

        uVar4 = (**(code **)(*piVar5 + 0x1cc))();

        FUN_004b9af0(uVar4);

        FUN_004b9270(param_1);

        local_8 = '\0';

      }

    }

  }

  *(undefined1 *)(param_1 + 8) = 1;

  piVar5 = (int *)**(int **)(param_1 + 0x1e0);

  if (piVar5 != *(int **)(param_1 + 0x1e0)) {

    do {

      iVar1 = piVar5[2];

      if (cVar2 != '\0') {

        *(undefined1 *)(iVar1 + 0x7f9) = 1;

      }

      FUN_005b8340();

      iVar6 = iVar1 + 0x14;

      do {

        FUN_005b8340();

        iVar6 = *(int *)(iVar6 + 0x2f4);

      } while (iVar6 != iVar1 + 0x14);

      *(undefined4 *)(iVar1 + 4) = 0;

      piVar5 = (int *)*piVar5;

      local_8 = cVar2;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x1e0));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x1ec);

  if (piVar5 != *(int **)(param_1 + 0x1ec)) {

    do {

      if ((*(char *)(piVar5[2] + 0x10b) != '\0') && (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 0))

      {

        uVar9 = 0;

        local_4 = (uint)*(byte *)(iVar1 + 0x168);

        uVar4 = *(undefined4 *)(iVar1 + 0x160);

        uVar7 = *(undefined4 *)(iVar1 + 0x164);

        uVar8 = 0;

        Client_GetMissionCompleteAudioTable(uVar4,uVar7,local_4,0,0);

        FUN_00723b20(uVar4,uVar7,local_4,uVar8,uVar9);

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x1ec));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x204);

  if (piVar5 != *(int **)(param_1 + 0x204)) {

    do {

      FUN_00593e10(*(undefined4 *)(param_1 + 0x2c),cVar2);

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x204));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x210);

  if (piVar5 != *(int **)(param_1 + 0x210)) {

    do {

      if (local_8 != '\0') {

        *(uint *)(piVar5[2] + 0x178) = *(uint *)(piVar5[2] + 0x178) | 0x100;

      }

      FUN_005b8340();

      *(undefined4 *)piVar5[2] = 0;

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x210));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x21c);

  if (piVar5 != *(int **)(param_1 + 0x21c)) {

    do {

      FUN_00498a90();

      FUN_00498ab0(0);

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x21c));

  }

  *(undefined4 *)(param_1 + 0x10) = 0;

  return local_8;

}
```

---

## Re-verify append — 2026-07-29 W27-D

| Field | Value |
|---|---|
| **Tool** | Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes` |
| **Live decompile ≡ raw body** | **Yes** (2026-07-29 ≡ 2026-07-23 scaffold) |
| **Body** | `0x004ba0a0`–`0x004ba26d` (**461 B / `0x1CD`**) |
| **Classification** | **worker** |
| **Callers (2)** | `FUN_005179e0` @ `0x00517a1d`; `FUN_00514d80` @ `0x00514d9a` |
| **Callees** | `FUN_004b6a80` (`NDSpecialFX_List1e0_AnyFlag10`), `FUN_004b9af0`, `FUN_004b9270`, `FUN_005b8340` (× sites), `Client_GetMissionCompleteAudioTable`, `FUN_00723b20` (`CSoundManager_StopMatchingSounds_Inferred`), `FUN_00593e10`, `FUN_00498a90`, `FUN_00498ab0` |
| **ABI** | ECX = fx host (`__fastcall`/`__thiscall` single-arg); frame `SUB ESP,8`; plain **`RET`** (`C3`); **AL** 0\|1 |
| **Entry bytes** | `83 EC 08 53 56 8B F1 80 7E 08 00 B3 01 88 5C 24 08 74 08 …` early ret `8A C3 5B 83 C4 08 C3` |
| **Exit bytes** | `C7 46 10 00 00 00 00 5E 8A C3 5B 83 C4 08 C3` then `8B FF` |
| **Role name** | `NDSpecialFX_StopFinalize_Inferred` (structural; product/PDB open). **Reject** keyword alias `Mission_Uses_Client_GetMissionCompleteAudioTable_004ba0a0`. |

### Control-flow (sealed)

1. **Re-entry:** if host`+8` ≠ 0 → return **1**.
2. **Type-gated early clear** when host`+0x10` non-null:
   - `switch(host+0x28)` case **4**: `FUN_004b6a80()`; non-zero → **break** (skip clear).
   - Fall-through **5,6,0xC,0xD,0xE,0x14,0x15**: if host`+0xB` ≠ 0 → keep=`0`, vcall host`vtable+0x1CC`, `FUN_004b9af0`, `FUN_004b9270(host)`, `local_8=0`.
3. host`+8 = 1` (finalized sticky).
4. **List `+0x1E0`:** optional payload`+0x7F9=1` if keep; `FUN_005b8340`; ring payload`+0x14` via `+0x2F4` + `FUN_005b8340`; payload`+4=0`; `local_8=keep`.
5. **List `+0x1EC`:** if payload`+0x10B` and host`+0x10`: args host`+0x160/+164/+168` → audio table + `FUN_00723b20` stop-matching.
6. **List `+0x204`:** `FUN_00593e10(host+0x2C, keep)` per node.
7. **List `+0x210`:** if `local_8` OR payload`+0x178 \|= 0x100`; `FUN_005b8340`; `*payload=0`.
8. **List `+0x21C`:** `FUN_00498a90`; `FUN_00498ab0(0)`.
9. host`+0x10 = 0`; return `local_8`.

### Notes

- Layout family matches dualed HostTick / DeactivateClear / LivenessDone.
- Distinct from DeactivateClear (`FUN_004b7150`): no staged multi-hit flush / destroy-pending bit0 walk.
- `FUN_005179e0`: free fx only if host`+9==0` and return non-zero.

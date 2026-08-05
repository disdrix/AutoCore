# Raw capture: Skill_CategoryCooldownMap_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d2f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051d2f0` |
| **Canonical name** | `Skill_CategoryCooldownMap_Insert` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_CategoryCooldownMap_Insert / Map_InsertOrFind style insert
   
   Inserts category cooldown node {key, startTick, duration}.
   Shared pattern with Map_InsertOrFind_IntKey. */

void __thiscall Skill_CategoryCooldownMap_Insert(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  piVar3 = param_3;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar2 = true;
  if (*(char *)((int)puVar5[1] + 0x19) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *param_3 < (int)puVar5[3];
      if (bVar2) {
        puVar4 = (undefined4 *)*puVar5;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x19) == '\0');
  }
  param_3 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_0051c1c0(&param_3,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    FUN_005ae050();
  }
  if (param_3[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_0051c1c0(&param_3,bVar2,puVar5,piVar3);
    *param_2 = *puVar5;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_2 + 1) = 0;
  *param_2 = param_3;
  return;
}
```

---

## Residual re-verify (2026-07-29) — append only

| Source | Result |
|---|---|
| Live `decompile_function` `0x0051d2f0` | Body **identical** to raw above |
| `read_memory` `0x0051d2f0`–`0x0051d3a8` | Three exits `C2 08 00` (`RET 0x8`) @ `0x0051d35e`, `0x0051d395`, `0x0051d3a6` |
| Out-pair stores | `mov byte ptr [eax+4], 0/1` + `mov [eax], node` — inserted is **+4** |
| `FUN_005ae220` | `push 0x1c`; color `@+0x18`; isnil `@+0x19=0`; `RET 0x14` |
| `get_xrefs_to` | Only `Skill_InsertCategoryCooldown` @ `0x00518e23`, `CVOGHBOKToCastAgain_ctor` @ `0x0051e361` |

Dual residual: `reviews/a_0051d2f0.md` + A/B strengthen. Do not rewrite raw body above.

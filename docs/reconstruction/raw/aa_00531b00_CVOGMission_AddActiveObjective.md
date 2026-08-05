# Raw capture: CVOGMission_AddActiveObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00531b00` |
| **Canonical name** | `CVOGMission_AddActiveObjective` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Add active objective node to character mission hash (+0x548). Called from GiveMission and
   CompleteObjective when advancing sequence. Sets dirty flag char+0x634 |= 0x10. */

void __thiscall CVOGMission_AddActiveObjective(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_0053c460(*(undefined4 *)(param_2 + 0x10),param_2,0);
  if ((*(int *)(param_2 + 0x158) != 0) &&
     (*(int *)(param_2 + 0x15c) - *(int *)(param_2 + 0x158) >> 2 != 0)) {
    piVar1 = operator_new(0x14);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = 0;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
    }
    *piVar1 = param_2;
    iVar2 = FUN_0053c760(*(undefined4 *)(param_2 + 0x10),piVar1,0);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(piVar1);
    }
    for (uVar3 = 0;
        (iVar2 = *(int *)(param_2 + 0x158), iVar2 != 0 &&
        (uVar3 < (uint)(*(int *)(param_2 + 0x15c) - iVar2 >> 2))); uVar3 = uVar3 + 1) {
      (**(code **)(**(int **)(iVar2 + uVar3 * 4) + 0x28))(param_1,piVar1);
    }
    *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x10;
  }
  return;
}
```

---

## Versioned note — 2026-07-29 dual tighten (asm; do not rewrite raw body)

Ghidra re-decompile @ `0x00531b00` matches the pseudocode above (CF unchanged). Machine-code facts the decompiler drops:

| Fact | Asm | Implication |
|------|-----|-------------|
| Def-insert hash this | `0x00531b0d` MOV ECX,[EBP+0x548] before CALL FUN_0053c460 | Active objectives hash = **char+0x548** |
| State-insert hash this | `0x00531b6f` MOV ECX,[EBP+0x55c] before CALL FUN_0053c760 | Pending hash = **char+0x55c** |
| Call arity | GiveMission `0x005328b2` / CompleteObjective `0x005348a2`: PUSH obj; MOV ECX,char; CALL | **thiscall(char, objDef)** — not single-arg |
| Delete path | `0x00531b7c`-`0x00531b8f` fall through after operator_delete | Noreturn WARNING is false |

See annotated layer + dual A/B + scratch `reviews/a_00531b00.md` for full seal tables. Raw body above remains the frozen decompile capture.

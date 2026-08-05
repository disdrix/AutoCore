# Raw capture: CVOGHBOKToCastAgain_OnStart

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e390` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051e390` |
| **Canonical name** | `CVOGHBOKToCastAgain_OnStart` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBOKToCastAgain_OnStart (vtable activate)
   If owner skill attached: Skill_SetIsCastingFlag(skill, 1), CVOGHBBase_ResetStartTick. */

void __fastcall CVOGHBOKToCastAgain_OnStart(void *pHeartbeat)

{
  char unaff_SI;
  
  if (*(int *)((int)pHeartbeat + 0x18) != 0) {
    Skill_SetIsCastingFlag(*(void **)((int)pHeartbeat + 0x24),(void *)0x1,unaff_SI);
  }
  CVOGHBBase_StampLastFireTime(pHeartbeat);
  return;
}
```

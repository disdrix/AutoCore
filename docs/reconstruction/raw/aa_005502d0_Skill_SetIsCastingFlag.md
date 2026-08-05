# Raw capture: Skill_SetIsCastingFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_005502d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005502d0` |
| **Canonical name** | `Skill_SetIsCastingFlag` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_SetIsCastingFlag(pSkill, bIsCasting)
   
   Parameters:
     pSkill      - skill runtime
     bIsCasting  - sets skill+0x628; if true stamps skill+0x178 = g_dwClientTickMs
   
   VERIFIED offsets from assembly. */

void __thiscall Skill_SetIsCastingFlag(void *this,void *pSkill,char bIsCasting)

{
  *(char *)((int)this + 0x628) = (char)pSkill;
  if ((char)pSkill != '\0') {
    *(undefined4 *)((int)this + 0x170) = 0;
    *(uint *)((int)this + 0x178) = g_dwClientTickMs;
  }
  return;
}
```

---

## Append 2026-07-29 — dual residual seal (`read_memory` + xrefs)

**Do not alter the raw decompile above.** Live machine CF (authoritative for ABI/types):

```
8A442404 84C0 888128060000 7416
0F57C0 F30F118170010000
A1CC41B000 898178010000
C20400
```

| Item | Sealed value |
|---|---|
| ABI | `__thiscall` ECX=skill; **1** stack `char`; **`RET 4`** |
| `+0x628` | **byte** is-casting flag (always written) |
| true | `+0x170` **float** 0 via `movss`; `+0x178` = `g_dwClientTickMs` @ `0x00b041cc` |
| false | **no** clear of `+0x170`/`+0x178` |
| CODE callers | OnStart `push 1`; OnEnd `push 0`; FUN_0052c780 `push 0` walk |

Decomp names `pSkill`/`bIsCasting` as two formals for one stack arg — plate noise; flag is `(char)[esp+4]`.

# Raw capture: CVOGHBOKToCastAgain_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051e3b0` |
| **Canonical name** | `CVOGHBOKToCastAgain_OnEnd` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBOKToCastAgain_OnEnd (HB complete/abort)
   If owner skill attached: Skill_SetIsCastingFlag(skill, 0). */

void __fastcall CVOGHBOKToCastAgain_OnEnd(void *pHeartbeat)

{
  char unaff_SI;
  
  if (*(int *)((int)pHeartbeat + 0x18) != 0) {
    Skill_SetIsCastingFlag(*(void **)((int)pHeartbeat + 0x24),(void *)0x0,unaff_SI);
  }
  FUN_005081f0();
  return;
}
```

---

## Append: machine seal (2026-07-29)

Tool: Ghidra MCP `read_memory` + `decompile_function` + `get_function_xrefs` / callees.
Do not treat decompiler `unaff_SI` or "cleanup" wording as authoritative -- see residual `reviews/a_0051e3b0.md`.

### Body bytes `0x0051e3b0`-`0x0051e3ca`

```
56 8B F1 83 7E 18 00 74 0A 8B 4E 24 6A 00 E8 0D1F0300
8B CE 5E E9 259EFEFF
```

- `call` target: `0x005502d0` (`Skill_SetIsCastingFlag`)
- `jmp` target: `0x005081f0` (`FUN_005081f0`)

### `FUN_005081f0` @ `0x005081f0`

```
C3   ; RET only
```

### Vtbl `0x009ce1c4` slot +0x14

DATA at `0x009ce1d8` -> `0x0051e3b0` (sole xref to this function).

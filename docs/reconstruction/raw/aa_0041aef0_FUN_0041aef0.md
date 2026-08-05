# Raw capture: FUN_0041aef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041aef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0041aef0` |
| **Canonical name** | `FUN_0041aef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0041aef0(int param_1)



{

  int iVar1;

  undefined4 in_EAX;

  int local_4;

  

  iVar1 = *(int *)(param_1 + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x934) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x934))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_004220c0(param_1);

    *(int *)(param_1 + 8) = iVar1 + 0x934;

    return;

  }

  FUN_0041c920(&local_4,*(undefined4 *)(param_1 + 8),in_EAX);

  return;

}
```


---

## Live dual refresh (2026-07-29)

- Ghidra program: `autoassault.exe` (HTTP `127.0.0.1:8089`).
- Tools: `batch_decompile`, `read_memory`, callers/callees/xrefs.
- Live decompile **≡** this raw body. Dual A/B: `reviews/A_aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md` / `B_aa_*`.
- Parent ensure: `Skill_DbLoadSkillsCharacters` `0x007e34b0`.

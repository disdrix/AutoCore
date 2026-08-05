# Raw capture: Client_SendUseObject_IfInteractable

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930d70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00930d70` |
| **Canonical name** | `Client_SendUseObject_IfInteractable` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Alt UseObject path: C2S 0x2072 size 0x20; TFID from obj+0x160; only if interactable

   (FUN_00524520) or type==4. */



undefined4 Client_SendUseObject_IfInteractable(void)



{

  int in_EAX;

  int unaff_ESI;

  undefined4 local_20 [2];

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  int local_8;

  

  if (*(char *)(*(int *)(unaff_ESI + 0xe04) + 0xf6) == '\0') {

    local_8 = FUN_00524520(in_EAX);

    if ((local_8 != 0) || (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 4)) {

      local_18 = *(undefined4 *)(in_EAX + 0x160);

      local_14 = *(undefined4 *)(in_EAX + 0x164);

      local_10 = *(undefined4 *)(in_EAX + 0x168);

      local_c = *(undefined4 *)(in_EAX + 0x16c);

      local_20[0] = 0x2072;

      if (*(int *)(unaff_ESI + 0xc78) != 0) {

        (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_20,0x20,0);

      }

      return 1;

    }

  }

  return 0;

}
```

---

## Version: 2026-07-29 re-decompile check + objective overlay

| Field | Value |
|---|---|
| Tool | Ghidra MCP `batch_decompile` `0x00930d70` program `autoassault.exe` |
| Result | Body **byte-identical** to 2026-07-23 raw pseudocode above |
| Callers | `Client_Input_PollBoundActions` `0x00925d60`; `Client_InteractClickPickTarget` `0x009247b0`; `FUN_008be900`; `FUN_00925820` |
| Callees | `FUN_00524520` `0x00524520` |
| System assignment | `interaction-activation` (was unknown) |

**Stack overlay note (analysis, not body change):** `local_8` is assigned from `FUN_00524520` and occupies packet offset `+0x18` (IDObjective). No second write before send. Type-4 path with match-fail therefore transmits objective **0**, not -1. Callee `FUN_00524520` returns objective id (`def+0x10`) after walking `char+0x548` via `FUN_0059d9c0` (eval vtable `+0x40`).

---

## Version: 2026-07-29 dual residual strengthen (read_memory)

| Field | Value |
|---|---|
| Tool | Ghidra MCP `read_memory` `0x00930d70` length 160 + decompile recheck |
| Body vs raw | Pseudocode body **unchanged** |
| **Sealed** | Character thiscall: `MOV ECX,[ESI+0xe98]` before `CALL 0x00524520` |
| **Sealed** | Objective fill: `MOV [ESP+0x1c],EAX` → packet `+0x18` (explicit, not decompiler-name overlay only) |
| **Sealed** | Type-4 with EAX=0 stores **0**; no `−1` write in unit |
| **Sealed** | Return 1 after pack even if `*(ESI+0xc78)==0` |
| Dual A/B | Strengthened; function record updated |

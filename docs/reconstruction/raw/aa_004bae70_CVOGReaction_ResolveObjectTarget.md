# Raw capture: CVOGReaction_ResolveObjectTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bae70` |
| **Canonical name** | `CVOGReaction_ResolveObjectTarget` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
CVOGReaction_ResolveObjectTarget(int param_1,char param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_3 & param_4) != 0xffffffff) {
    if (param_2 == '\0') {
      if (*(char *)(param_1 + 0xd) != '\0') {
        uVar1 = FUN_004e3260(param_3,param_4);
        return uVar1;
      }
    }
    else if (*(char *)(param_1 + 0xc) != '\0') {
      uVar1 = FUN_004e3260(param_3,param_4);
      return uVar1;
    }
  }
  return 0;
}
```

---

## Versioned note — 2026-07-29 image seal (append only)

**Do not replace the 2026-07-23 decompile body above.** That decompile remains the historical raw capture.

Live `read_memory` of `0x004bae70` (2026-07-29) confirms the decompiler **omitted** table selection:

* After `bGlobal != 0` + flag `ctx+0xc`: `mov ecx, [ecx+0x4]` then `call FUN_004e3260`
* After `bGlobal == 0` + flag `ctx+0xd`: `mov ecx, [ecx+0x8]` then `call FUN_004e3260`
* Epilogue: `ret 0x0c` (three stack args)
* Invalid path: `(coidLo & coidHi) == 0xFFFFFFFF` → `xor eax,eax; ret 0x0c`

Authoritative corrected CF lives in annotated + clean + dual A/B (strengthen pass). Hex body prefix:

`8b442408 8b54240c 56 8bf0 23f2 83feff 5e 742d 807c240400 7413 80790c00 7420 8b4904 52 50 e8c6830200 c20c00 80790d00 740d 8b4908 52 50 e8b3830200 c20c00 33c0 c20c00`

# Raw capture: vog_LogMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996dc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00996dc0` |
| **Body** | `0x00996dc0`–`0x00996e32` |
| **Canonical name** | `vog_LogMessage` |
| **System** | `diagnostics` |
| **Capture timestamp** | `2026-07-23` (initial); **machine re-seal `2026-07-29`** |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* vog_LogMessage(const char* sourceFile, int line, int severity, const char* fmt, ...)
   Engine-wide logging/assert sink; every call site carries the original C:\vog\1_code\... source
   path - the primary source for recovering original class/file names in this stripped retail
   binary. */

void vog_LogMessage(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  FILE *_File;
  
  iVar1 = FUN_0076d1b0(param_1,param_2,param_4);
  if (iVar1 == 3) {
    _File = fopen("c:\\VOGCRASH.txt","w");
    if (_File != (FILE *)0x0) {
      fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",param_1,param_2,
              param_3,param_4);
      fclose(_File);
    }
    raise(0x16);
                    /* WARNING: Subroutine does not return */
    ExitProcess(3);
  }
  return;
}
```

---

## Machine bytes (2026-07-29 `read_memory`)

Address `00996dc0`, length 128 (body ends `c3` at `00996e32`; trailing `cc` pad):

```
8b 44 24 04 53 8b 5c 24 14 55 8b 6c 24 10 57 8b 7c 24 18
53 55 50 e8 d5 63 dd ff 83 c4 0c 83 f8 03 75 4c
56 68 78 4b a1 00 68 98 d0 a9 00 ff 15 90 66 9c 00
8b f0 83 c4 08 85 f6 74 1e
8b 4c 24 14 53 57 55 51 68 5c d0 a9 00 56 ff 15 68 66 9c 00
56 ff 15 6c 66 9c 00 83 c4 1c
6a 16 ff 15 24 64 9c 00 83 c4 04
6a 03 ff 15 c4 60 9c 00
5e 5f 5d 5b c3
```

**Machine notes (append-only):**

- cdecl; plain `ret` (`C3`).
- Decompiler omits that **param_3 (severity) is loaded into EDI** before `call FUN_0076d1b0` (callee indexes severity table via EDI).
- `FUN_0076d1b0` stack args are `(param_1, param_2, param_4)` only — matches decompile.

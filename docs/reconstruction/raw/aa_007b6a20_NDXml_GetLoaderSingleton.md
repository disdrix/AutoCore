# Raw capture: NDXml_GetLoaderSingleton

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6a20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b6a20`–`0x007b6a82` |
| **Canonical name** | `NDXml_GetLoaderSingleton` |
| **Ghidra name** | `FUN_007b6a20` |
| **System** | `client-xml` / NDXml path-loader singleton |
| **Capture timestamp** | `2026-07-29` (W17-I dual A/B) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Authoritative body matches scaffold capture `aa_007b6a20_FUN_007b6a20.md` (2026-07-23); this file is the named plate |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007b6a20(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b00cb;
  local_c = ExceptionList;
  if ((DAT_00d20c48 & 1) == 0) {
    DAT_00d20c48 = DAT_00d20c48 | 1;
    _DAT_00d20c3c = 1;
    _DAT_00d20c38 = &PTR_FUN_00a95b88;
    _DAT_00d20c40 = 0;
    _DAT_00d20c44 = 0;
    ExceptionList = &local_c;
    _atexit((_func_4879 *)&LAB_009c3040);
  }
  ExceptionList = local_c;
  return &DAT_00d20c38;
}
```

## Entry / exit bytes (`read_memory`)

| Addr | Hex (selected) | Meaning |
|---|---|---|
| `0x007b6a20` | `64 A1 00 00 00 00 6A FF 68 CB 00 9B 00 50` | FS:[0] SEH frame |
| `0x007b6a2e` | `B8 01 00 00 00 84 05 48 0C D2 00` | once-test `DAT_00d20c48` bit0 |
| `0x007b6a73` | `B8 38 0C D2 00` | `mov eax, &DAT_00d20c38` |
| `0x007b6a7e` | `83 C4 0C C3` | tear SEH / `ret` |

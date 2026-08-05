# Raw capture: FUN_004bcca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcca0` |
| **Canonical name** | `FUN_004bcca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bcca0(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_004e2bd0();
  if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
    free((void *)**(undefined4 **)(param_1 + 0x10));
    operator_delete__(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}
```

---

## Re-verify (2026-07-29 W31-M)

| Field | Value |
|---|---|
| **Tools** | `decompile_function` + `read_memory` + callers/callees/xrefs; **no** `disassemble_bytes` |
| **Live decompile** | ≡ 2026-07-23 raw CF (count zero → reclaim `FUN_004e2bd0` → free `*buckets` + `delete[]` table + null) |
| **Body** | `0x004bcca0`–`0x004bccd4` exclusive (**52 B / `0x34`**); pad `CC` after `ret` |
| **Bytes** | `56 8B F1 C7 46 0C 00 00 00 00 E8 21 5F 02 00 8B 46 10 85 C0 74 1C 8B 00 50 FF 15 24 65 9C 00 8B 4E 10 51 E8 54 CB FC FF 83 C4 08 C7 46 10 00 00 00 00 5E C3` |
| **ABI** | MSVC `__thiscall` (decompiler `__fastcall` ECX); plain `ret` (`C3`); no stack args |
| **Callers** | `FUN_004bcd40` @ `0x004bcd66` (Recreate_009cb45c); `FUN_004bd140` @ `0x004bd18e` (Dtor vtbl `009cb45c`); `FUN_004e4990` @ `0x004e49b6` (parallel Recreate); `FUN_004e66a0` @ `0x004e66ee` (Dtor vtbl `009cc6c0`) |
| **Callees** | reclaim `FUN_004e2bd0` (`0x004e2bd0`); `free` IAT `0x009c6524`; `operator_delete[]` `0x0048981c` |
| **Named role** | `CNDHash_FreeBuckets_009cb45c` (primary family; shared reclaim path also used by `009cc6c0` dtor / parallel Recreate) |

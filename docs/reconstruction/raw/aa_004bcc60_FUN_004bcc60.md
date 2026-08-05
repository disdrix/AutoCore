# Raw capture: FUN_004bcc60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcc60` |
| **Canonical name** | `FUN_004bcc60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bcc60(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_004bcae0();
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
| **Live decompile** | ≡ 2026-07-23 raw CF (count zero → reclaim `FUN_004bcae0` → free `*buckets` + `delete[]` table + null) |
| **Body** | `0x004bcc60`–`0x004bcc94` exclusive (**52 B / `0x34`**); pad `CC` after `ret` |
| **Bytes** | `56 8B F1 C7 46 0C 00 00 00 00 E8 71 FE FF FF 8B 46 10 85 C0 74 1C 8B 00 50 FF 15 24 65 9C 00 8B 4E 10 51 E8 94 CB FC FF 83 C4 08 C7 46 10 00 00 00 00 5E C3` |
| **ABI** | MSVC `__thiscall` (decompiler `__fastcall` ECX); plain `ret` (`C3`); no stack args |
| **Callers** | `FUN_004bcce0` @ `0x004bcd06` (Recreate_009cb450); `FUN_004bd0b0` @ `0x004bd0fe` (Dtor vtbl `009cb450`) |
| **Callees** | reclaim `FUN_004bcae0` (`0x004bcae0`); `free` IAT `0x009c6524`; `operator_delete[]` `0x0048981c` |
| **Twin vs `004bcca0`** | identical opcode skeleton; only reclaim near-call reloc + `operator_delete[]` reloc (same absolute targets differ by PC) |
| **Named role** | `CNDHash_FreeBuckets_009cb450` |

# Raw capture: FUN_004a7aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004a7aa0` |
| **Canonical name** | `FUN_004a7aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004a7aa0(basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                  *param_1,
                 basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
    ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(param_1);
  }
  return;
}
```

---

## W36-S re-verify (2026-07-29) — OWN-ONLY dual

**Tools:** `batch_decompile` / `decompile_function` + `get_function_by_address` + `get_function_xrefs` + `get_function_callees` + `read_memory`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger.

### Live decompile

Live 2026-07-29 ≡ scaffold raw CF (destroy-range loop, stride 0x1c, `~basic_string<wchar_t>`).

### Function extent

| Field | Value |
|---|---|
| Entry | `0x004a7aa0` |
| Body | `0x004a7aa0`–`0x004a7ac4` exclusive (**36 B** / `0x24`) |
| Pad | `CC` ×12 then unrelated / parent cluster |

### Full body hex (36 B, `read_memory`)

```
568b742408578b7c24103bf774118bff8bceff15ac629c0083c61c3bf775f15f5ec20800
```

### Byte-sealed facts

| Claim | Evidence |
|---|---|
| Stack first* → ESI | `56; 8B 74 24 08` |
| Stack last* → EDI | `57; 8B 7C 24 10` |
| Early-out first==last | `3B F7; 74 11` |
| thiscall dtor ECX=elem | `8B CE; FF 15 AC 62 9C 00` |
| IAT dtor slot | `[0x009c62ac]` → `0x006eb03a` |
| Stride 0x1c | `83 C6 1C` |
| RET 0x08 | `C2 08 00` |

### Xrefs / callees

| Kind | Targets |
|---|---|
| Callers | `FUN_004a7ad0` / `StdVector_InsertN_BasicStringW` @ `0x004a7c82`; Catch@`0x004a7cbd`; Catch@`0x004a7d90` |
| Callees | IAT `~basic_string<wchar_t>` via `0x009c62ac` |

### Name

`StdVector_DestroyRange_BasicStringW` — wchar twin of `StdVector_DestroyRange_BasicString` (`0x00431aa0`, W33-H). **Reject** scaffold `Named_CalleeOf_*_004a7aa0`.

### Verdict

**accept-with-gaps** — destroy-range ABI/CF/stride/IAT sealed; product demangle residual.

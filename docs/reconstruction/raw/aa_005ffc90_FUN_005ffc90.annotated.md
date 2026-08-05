# Annotated low-level: hkAnalogDI_CopyStringByKey

| Field | Value |
|---|---|
| Stable ID | `aa_005ffc90` |
| VA | `0x005ffc90`–`0x005ffce5` |
| Ghidra | `FUN_005ffc90` |
| Canonical | `hkAnalogDI_CopyStringByKey` |
| System | Havok / DI analog string table (client) |
| Date | 2026-07-29 (W25-M seal) |
| Tools | decompile + analyze_function_complete + read_memory; no disassemble_bytes |

---

## Machine-level notes

- **thiscall** is **required**: `lea esi,[ecx+8]` binds the open-address table at **this+8**. Decompiler free-function surface is incomplete.
- Stack cleanup **`ret 0xc`** matches 3 dword stack args after ECX.
- Fail path never touches `dst`; success uses `strncpy` then returns **source** strlen (not clamped copy length).
- Parent `hkAnalogDI_vtbl1` only enters when `*(byte*)(this+5) & 0x80` — this unit is the real work.

## Annotated control flow

```
// ECX = hkAnalogDI* this
// [esp+4]=key, [esp+8]=dst, [esp+0xc]=maxlen

table = this + 8
index = HashOpenAddressLookup(table, key)          // FUN_00650290
found = (index <= table->capacity)                 // FUN_0065ad10 → bool
if (!found) return 0

src = HashValueAt(table, index)                    // FUN_0065acb0 → char*
strncpy(dst, src, maxlen)                          // FUN_00638040
return strlen(src)                                 // FUN_00638060
```

## Callee contracts (supporting)

| Callee | Role (this seal) |
|---|---|
| `FUN_00650290` | Open-address: `slot = (key>>4)*GOLDEN & mask`; probe; return index or `mask+1` |
| `FUN_0065ad10` | `*outBool = (index <= *(table+8))` |
| `FUN_0065acb0` | Value pointer from parallel slot array |
| `FUN_00638040` | `strncpy` if n!=0 |
| `FUN_00638060` | `strlen` |

## Signature (sealed)

```c
// thiscall; ret 0xc
int __thiscall hkAnalogDI_CopyStringByKey(
    hkAnalogDI* this,
    unsigned key,
    char* dst,
    size_t maxlen);
```

## Open / residual

- Product English for key domain (axis id vs control id).
- Full hash table layout beyond `*base / capacity@+8` used here.
- Whether `strncpy` zero-fills remainder (CRT) — deferred to callee dual.
- Runtime / bit-exact / differential: open.

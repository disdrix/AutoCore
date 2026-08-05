# Raw capture: FUN_005ffc90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffc90` |
| **Canonical name** | `FUN_005ffc90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_005ffc90(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  

  uVar1 = FUN_00650290(param_1);

  FUN_0065ad10(&param_1,uVar1);

  if ((char)param_1 != '\0') {

    uVar1 = FUN_0065acb0(uVar1);

    FUN_00638040(param_2,uVar1,param_3);

    uVar1 = FUN_00638060(uVar1);

    return uVar1;

  }

  return 0;

}
```


---

## W25-M live seal append (2026-07-29)

**Tools:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callee decompiles). **No** `disassemble_bytes`.
**Program:** `autoassault.exe` base `0x400000`.

### Function bounds

| Item | Value |
|---|---|
| Entry | `0x005ffc90` |
| Body end | `0x005ffce5` (exclusive; next is `cc` pad) |
| Size | 0x55 (85 B) |
| Ghidra name | `FUN_005ffc90` |
| Canonical (sealed) | `hkAnalogDI_CopyStringByKey` |

### Live decompile (re-verify)

```c
undefined4 FUN_005ffc90(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  uVar1 = FUN_00650290(param_1);
  FUN_0065ad10(&param_1,uVar1);
  if ((char)param_1 != '\0') {
    uVar1 = FUN_0065acb0(uVar1);
    FUN_00638040(param_2,uVar1,param_3);
    uVar1 = FUN_00638060(uVar1);
    return uVar1;
  }
  return 0;
}
```

**Decompile gap:** Ghidra surfaces as free function with 3 stack args and hides **thiscall ECX**. Bytes prove `lea esi,[ecx+8]` then all table ops use `this+8`.

### Entry / body bytes (`read_memory` full body)

```
005ffc90: 8b 44 24 04 56 57 8d 71 08 50 8b ce e8 ef 05 05
005ffca0: 00 8b f8 57 8d 4c 24 10 51 8b ce e8 60 b0 05 00
005ffcb0: 80 7c 24 0c 00 74 28 57 8b ce e8 f1 af 05 00 8b
005ffcc0: 54 24 14 8b f0 8b 44 24 10 52 56 50 e8 6f 83 03
005ffcd0: 00 56 e8 89 83 03 00 83 c4 10 5f 5e c2 0c 00 5f
005ffce0: 33 c0 5e c2 0c 00
```

| Addr | Bytes | Decode |
|---|---|---|
| `005ffc90` | `8B 44 24 04` | `mov eax,[esp+4]` key |
| `005ffc94` | `56 57` | `push esi; push edi` |
| `005ffc96` | `8D 71 08` | `lea esi,[ecx+8]` **hash table = this+8** |
| `005ffc99` | `50 8B CE` | push key; `mov ecx,esi` |
| `005ffc9c` | `E8 EF050500` | `call FUN_00650290` open-address key lookup |
| `005ffca1` | `8B F8` | `mov edi,eax` index |
| `005ffca3`–`ab` | … | push index; lea out-bool over key slot; `call FUN_0065ad10` |
| `005ffcb0` | `80 7C 24 0C 00` | `cmp byte [esp+0xc],0` found? |
| `005ffcb5` | `74 28` | `jz` fail → xor eax,eax; ret 0xc |
| `005ffcb7`–`ba` | … | `call FUN_0065acb0(index)` → string* |
| `005ffcbf`–`cc` | … | push maxlen, src, dst; `call FUN_00638040` (`strncpy`) |
| `005ffcd1`–`d7` | … | `call FUN_00638060` (`strlen` src); `add esp,0x10` |
| `005ffcda`–`dc` | `5F 5E C2 0C 00` | pop; **`ret 0xc`** success (EAX=strlen) |
| `005ffcdf`–`e3` | `5F 33 C0 5E C2 0C 00` | fail: **EAX=0**, **`ret 0xc`** |

### ABI (bytes)

- **thiscall**: ECX = `hkAnalogDI* this` (family sealed via sole caller `hkAnalogDI_vtbl1` @ `0x005ffd80`).
- Stack: `uint key`, `char* dst`, `size_t maxlen` → **`ret 0xc`**.
- Return: `int` string length on hit; **0** on miss / not-found.

### Semantics (sealed)

1. `table = this + 8`.
2. `index = FUN_00650290(table, key)` — open-address hash; miss returns `capacity+1`.
3. `found = (index <= table->capacity)` via `FUN_0065ad10` writing bool into key stack slot.
4. On found: `src = FUN_0065acb0(table, index)` value-side string*; `strncpy(dst, src, maxlen)`; return `strlen(src)`.
5. On miss: return 0 (no write to dst in this unit).

### Call graph

| Role | VA / name |
|---|---|
| Sole caller | `hkAnalogDI_vtbl1` `0x005ffd80` (gate `*(byte*)(this+5) & 0x80`) |
| Hash lookup | `FUN_00650290` `0x00650290` |
| Found test | `FUN_0065ad10` `0x0065ad10` |
| Value fetch | `FUN_0065acb0` `0x0065acb0` |
| Copy | `FUN_00638040` `0x00638040` (`strncpy` wrapper) |
| Length | `FUN_00638060` `0x00638060` (strlen) |

### Xrefs

- From: `0x005ffd97` only (`xref_count=1`).

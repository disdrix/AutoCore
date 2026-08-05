# Raw capture: FUN_0040ead0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ead0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ead0` |
| **Canonical name** | `FUN_0040ead0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0040ead0(undefined4 param_1)

{
  switch(param_1) {
  case 0x14:
    return 0x18;
  case 0x15:
  case 0x16:
  case 0x23:
  case 0x70:
  case 0x72:
    return 0x20;
  case 0x17:
  case 0x19:
  case 0x1a:
  case 0x33:
  case 0x6f:
    return 0x10;
  default:
    return 0;
  case 0x1c:
  case 0x32:
    return 8;
  case 0x24:
  case 0x71:
  case 0x73:
    return 0x40;
  case 0x74:
    return 0x80;
  }
}
```

---

## W38-T re-verify (2026-08-04) — append only

| Field | Value |
|---|---|
| **Tools** | `batch_decompile` / `analyze_function_complete` + `read_memory` + xrefs + `get_assembly_context`. **No** `disassemble_bytes` |
| **Body extent** | Code `0x0040ead0`–`0x0040eb13` + jump table `0x0040eb14`–`0x0040eb2f` (7 dwords) + index table `0x0040eb30`–`0x0040eb90` (**0x61** bytes); total **193 B** / `0xC1` to last index; pad `CC` @ `0x0040eb91` |
| **ABI** | Free function; stack `(format)`; returns **bits-per-pixel** in EAX; epilogues plain **`C3` (`ret`)**; callers **`add esp,4`** → **`__cdecl`** |
| **Classification** | leaf |
| **Xrefs** | 19 CODE; 17 caller funcs; **0 callees** |

### Prologue + return stubs hex (code)

```
8b44240483c0ec83f86077320fb68030eb4000ff248514eb4000
b880000000c3   ; ret 0x80
b840000000c3   ; ret 0x40
b820000000c3   ; ret 0x20
b818000000c3   ; ret 0x18
b810000000c3   ; ret 0x10
b808000000c3   ; ret 0x08
33c0c3         ; ret 0
8d4900         ; align
```

### Machine CF

```
eax = format - 0x14;
if (eax > 0x60) return 0;
idx = byte_table[eax];          // @ 0x0040eb30
jmp dword_table[idx];           // @ 0x0040eb14 → {24,32,16,8,64,128,0}
```

### D3DFORMAT → bpp map (sealed)

| Format | Value | bpp | D3D9 note |
|---|---|---|---|
| R8G8B8 | `0x14` | 24 | D3DFMT_R8G8B8 |
| A8R8G8B8 / X8R8G8B8 / A2B10G10R10 | `0x15`/`0x16`/`0x23` | 32 | |
| R5G6B5 / A1R5G5B5 / A4R4G4B4 / A8L8 | `0x17`/`0x19`/`0x1a`/`0x33` | 16 | |
| A8 / L8 | `0x1c`/`0x32` | 8 | |
| A16B16G16R16 | `0x24` | 64 | |
| (extended) `0x6f` | 16 | |
| (extended) `0x70`/`0x72` | 32 | |
| (extended) `0x71`/`0x73` | 64 | |
| (extended) `0x74` | 128 | |
| other / out of range | 0 | unknown |

### Caller evidence (bytes)

| Site | After call | Role |
|---|---|---|
| `0x00583209` (`FUN_00583170` veh_paint) | `add esp,4; shr eax,3` | bpp→bytes/pixel |
| `0x0075f01d` / `0x0075f4fc` (`FUN_0075eff0` GfxDevice_Reset) | `imul` w/h/levels; `shr eax,3` | texture memory bytes |
| `0x0096c483` | `add esp,4; test eax,eax` | reject bpp==0 |

### Name

`D3dFormat_GetBitsPerPixel_Inferred` — **Inferred** from D3DFMT constants + `shr 3` byte conversion at callers. **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_0040ead0`.

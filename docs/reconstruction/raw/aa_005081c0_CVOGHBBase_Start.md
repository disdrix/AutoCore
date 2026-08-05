# Raw capture: CVOGHBBase_Start

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005081c0` |
| **Canonical name** | `CVOGHBBase_Start` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBBase_Start — begin receiving TryFire ticks.
   
   Parameters:
     this (ECX): CVOGHBBase*
   
   Algorithm: if fDormant, clear fDormant and call vtable[1] OnStart.
   Ctor sets fDormant=true; Start arms the HB for TryFire.
   
   Returns: void */

void __fastcall CVOGHBBase_Start(CVOGHBBase *this)

{
  if (this->fDormant != false) {
    this->fDormant = false;
                    /* WARNING: Could not recover jumptable at 0x005081cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((int)this->pVTable + 4))();
    return;
  }
  return;
}
```

---

## Re-verify 2026-07-29 (append only)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Address** | `0x005081c0` |
| **Length** | 16 body bytes (`005081c0`–`005081cf`) |

### Live decompile (matches original raw CF)

```c
void __fastcall CVOGHBBase_Start(CVOGHBBase *this)
{
  if (this->fDormant != false) {
    this->fDormant = false;
    /* WARNING: Could not recover jumptable at 0x005081cc. Too many branches */
    /* WARNING: Treating indirect jump as call */
    (**(code **)((int)this->pVTable + 4))();
    return;
  }
  return;
}
```

### `read_memory` hex

```
80 79 21 00 74 09 8B 01 C6 41 21 00 FF 60 04 C3
```

### Decode

| Bytes | Instruction | Note |
|---|---|---|
| `80 79 21 00` | `cmp byte [ecx+0x21], 0` | fDormant @ +0x21 |
| `74 09` | `jz +9` | already armed → ret |
| `8B 01` | `mov eax, [ecx]` | vtbl |
| `C6 41 21 00` | `mov byte [ecx+0x21], 0` | clear dormant |
| `FF 60 04` | `jmp [eax+4]` | tail-call OnStart (not call) |
| `C3` | `ret` | idle path |

Jumptable warning is decompiler noise on a single vtbl tail-jmp.

### Sibling peek (context, not owned)

- `0x005081d0` Stop: `80 79 21 00 75 09 8B 01 C6 41 21 01 FF 60 10 C3` — set dormant + `jmp [eax+0x10]`.
- `0x00508200` ctor: stores `*(this+0x21)=1` among other zeros + lastFire stamp.

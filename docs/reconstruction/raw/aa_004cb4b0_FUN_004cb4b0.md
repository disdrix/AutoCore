# Raw capture: FUN_004cb4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cb4b0` |
| **Canonical name** | `FUN_004cb4b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_004cb4b0(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar2[1] + 0x29) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((int)param_2[1] < (int)puVar2[5]) ||
         (((int)param_2[1] <= (int)puVar2[5] && (*param_2 <= (uint)puVar2[4])))) {
        puVar3 = (undefined4 *)*puVar2;
      }
      else {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x29) == '\0');
  }
  return puVar2;
}
```

---

## W31-N re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Tools** | `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw 2026-07-23 CF (leaf lower_bound walk) |
| **Body** | `0x004cb4b0`–`0x004cb4eb` exclusive (**59 B** / `0x3B`); pad `CC`; next func |
| **ABI** | ECX=`map/tree host`; stack `const KeyU32I32*`; epilogue **`RET 4`** (`C2 04 00`); returns node* in EAX |
| **Callees** | none (leaf) |
| **Callers** | `FUN_004c8970`, `FUN_004ca760`, `FUN_004cba00`, `FUN_004cc400`, `FUN_005a0470` |
| **Classification** | leaf |

### Full body hex (59 B)

```
8b41048b480480792900752c8b542404568b328b5204578b79143bfa7f0e7c078b79103bfe73058b4908eb048bc18b098079290074e15f5ec20400
```

### Byte-sealed algorithm

```
// MSVC _Tree::_Lbound for 8-byte key (u32 lo, i32 hi) — TFID-shaped
head = *(this+4)                 // _Myhead
if head->parent.isnil: return head
cand = head
node = head->parent              // root
while !node.isnil:
  // go left when !(node.key < search) i.e. search <= node
  // node.key: lo@+0x10 ([4]), hi@+0x14 ([5] signed)
  // search:   lo=*key, hi=key[1] signed
  if (search.hi < node.hi) || (search.hi <= node.hi && search.lo <= node.lo):
    cand = node; node = node.left   // [0]
  else:
    node = node.right               // [2]
return cand   // first not-less-than; may be head (end)
```

### Key / node layout (sealed)

| Offset | Field |
|---|---|
| node+0x00 | left |
| node+0x04 | parent |
| node+0x08 | right |
| node+0x10 | key.lo (uint32) |
| node+0x14 | key.hi (int32) |
| node+0x29 | isnil |
| node+0x20 | value payload (consumers; not used here) |

Host: `head` at `this+4` (standard MSVC map/set). Object-map consumers place host at `object+0x154` → head `object+0x158` (W30-T).

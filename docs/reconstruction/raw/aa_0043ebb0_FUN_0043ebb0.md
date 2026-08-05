# Raw capture: FUN_0043ebb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ebb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043ebb0` |
| **Canonical name** | `FUN_0043ebb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0043ebb0(int *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                 uint param_7)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  while ((param_2 != param_4 || (param_3 != param_5))) {
    param_5 = param_5 - 1;
    uVar6 = param_5 >> 2;
    iVar3 = uVar6 * -4;
    if (*(uint *)(param_4 + 8) <= uVar6) {
      uVar6 = uVar6 - *(uint *)(param_4 + 8);
    }
    param_7 = param_7 - 1;
    uVar5 = param_7 >> 2;
    iVar4 = uVar5 * -4;
    if (*(uint *)(param_6 + 8) <= uVar5) {
      uVar5 = uVar5 - *(uint *)(param_6 + 8);
    }
    puVar1 = (undefined4 *)(*(int *)(*(int *)(param_4 + 4) + uVar6 * 4) + (param_5 + iVar3) * 4);
    puVar2 = (undefined4 *)(*(int *)(*(int *)(param_6 + 4) + uVar5 * 4) + (param_7 + iVar4) * 4);
    if (puVar2 != puVar1) {
      *puVar2 = *puVar1;
    }
  }
  *param_1 = param_6;
  param_1[1] = param_7;
  return;
}
```

---

## Live re-verify — 2026-07-29 (OWN-ONLY W33-K)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Program** | `autoassault.exe` base `0x400000` |
| **Live ≡ raw scaffold** | **Yes** (CF/pseudocode match 2026-07-23 body) |
| **Body span** | `0x0043ebb0`–`0x0043ec43` (**148 B** / `0x94`; pad `CC`; next `FUN_0043ec50`) |
| **Classification** | leaf worker (0 callees) |
| **Xrefs (4)** | `0x0043dfee` (`FUN_0043df90`), `0x0043e352` (`FUN_0043e080`), `0x0044e4bd` (`FUN_0044e1c0`), `0x0054454d` (`FUN_005441d0`) |
| **Callers** | `FUN_0043e080`, `FUN_0043df90`, `FUN_0044e1c0`, `FUN_005441d0` |
| **Callees** | none |

### ABI (bytes)

| Slot | Role |
|---|---|
| **Stack[+0x04]** | `param_1` out pair `int*` → writes `{dst_container, final_dst_index}` |
| **Stack[+0x08]** | `param_2` stop container (src-side exclusive end container) |
| **Stack[+0x0c]** | `param_3` stop index |
| **Stack[+0x10]** | `param_4` source container (cursor) |
| **Stack[+0x14]** | `param_5` source index (starts high; decremented) |
| **Stack[+0x18]** | `param_6` dest container |
| **Stack[+0x1c]** | `param_7` dest index (starts high; decremented) |
| Frame | push EBX/EBP/ESI/EDI; `LEA ESP,[ESP+0]` no-op; plain **`RET`** (caller cleans **7×4**) |
| Return | **out pair in EAX** (bytes: `MOV EAX,[ESP+0x14]` before store; decompiler void is incomplete — **bytes win**) |

### Field layout (ring header — same family)

| Offset | Role |
|---|---|
| `+0x04` | slot / block pointer array |
| `+0x08` | capacity (block-index wrap unit) |
| (indices) | logical absolute; block = `idx>>2`; lane via `idx + block*-4` |

### Control flow (sealed)

```
// Reverse ring dword assign with self-alias skip (copy_backward style).
while (stop_c != src_c || stop_i != src_i) {
  src_i--; map block+wrap on src_c;
  dst_i--; map block+wrap on dst_c;
  if (dst_elem != src_elem) *dst_elem = *src_elem;
}
*out = {dst_c, dst_i};  // EAX = out
// plain RET
```

### Full body hex (`read_memory`, 148 B)

```
53 8b 5c 24 18 55 8b 6c 24 18 56 57 8d 64 24 00 39 6c 24 18
75 06 39 5c 24 1c 74 62 83 eb 01 8b cb c1 e9 02 8d 04 8d 00
00 00 00 8b f3 2b f0 8b 45 08 3b c1 77 02 2b c8 8b 54 24 2c
83 ea 01 8b c2 c1 e8 02 8d 3c 85 00 00 00 00 89 54 24 2c 2b
d7 8b 7c 24 28 8b 7f 08 3b f8 77 02 2b c7 8b 7d 04 8b 0c 8f
8d 0c b1 8b 74 24 28 8b 76 04 8b 04 86 8d 04 90 3b c1 74 98
8b 09 89 08 eb 92 8b 44 24 14 8b 54 24 28 8b 4c 24 2c 5f 5e
5d 89 10 89 48 04 5b c3
```

Entry loads src_i → EBX, stop_i → EBP; loop decrements both cursors.  
Epilogue: `MOV EAX,out; MOV EDX,dst_c; MOV ECX,dst_i; … MOV [EAX],EDX; MOV [EAX+4],ECX; POP EBX; RET`.

### Contrast vs sealed `GuardedVector_RingAssignBackward` (`0x0043d300`)

| Unit | Self-guard | Out write order | Return |
|------|------------|-----------------|--------|
| `0043d300` | no | `[1]=idx` then `[0]=c` | out in EAX |
| `0043ebb0` | **yes** (`dst != src`) | `[0]=c` then `[1]=idx` | out in EAX (bytes) |

Same reverse walk + capacity wrap + dword element width.

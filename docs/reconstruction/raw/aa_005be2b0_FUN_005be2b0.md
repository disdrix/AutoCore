# Raw capture: FUN_005be2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005be2b0` |
| **Canonical name** | `FUN_005be2b0` / preferred `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| **System** | client object motion / reaction slot freelist |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005be2b0(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2[2] != 0) {
    FUN_004b0bd0();
    piVar1 = (int *)param_2[2];
    if (piVar1 != (int *)0x0) {
      *piVar1 = *param_1;
      *param_1 = (int)piVar1;
    }
    param_2[2] = 0;
  }
  FUN_004b0bd0();
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  return;
}
```

---

## W28-I dual seal append (2026-07-29)

| Field | Value |
|---|---|
| **Body** | `0x005be2b0`–`0x005be2e9` exclusive (**57** B / `0x39`) |
| **Epilogue** | `5F 5E C2 04 00` → pop edi; pop esi; **ret 4** |
| **Pad** | `CC` from `0x005be2e9` |
| **Prologue** | `56 8B 74 24 08 57 8B F9` — ESI=stack node, EDI=ECX freelist head |
| **Global freelist** | Callers load `ECX = 0x00B036C0` (`DAT_00b036c0`) before call |
| **Callee** | `FUN_004b0bd0` @ `0x004b0bd0` — empty body (thiscall dtor stub); called with ECX=child then ECX=node |
| **Callers** | `FUN_005bb5e0` @ `0x005bb624` (SlotListTick remove); `FUN_005bbc50` @ `0x005bbd0e` (list teardown walk) |
| **Name** | `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| **Tools** | `decompile_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw 2026-07-23 body |

### Byte body (57 B)

```
56 8B 74 24 08 57 8B F9 8B 4E 08 85 C9 74 19 E8 0C 29 EF FF
8B 46 08 85 C0 74 06 8B 0F 89 08 89 07 C7 46 08 00 00 00 00
8B CE E8 F1 28 EF FF 8B 17 89 16 89 37 5F 5E C2 04 00
```

### Algorithm (sealed)

```
// ECX = freelist head* (call sites: &DAT_00b036c0)
// stack: Slot* node; ret 4
if (node->child@+0x8 != 0) {
  FUN_004b0bd0(this=child);          // empty
  if (node->child) { push child onto *freelist via dword0 next }
  node->child = 0;
}
FUN_004b0bd0(this=node);             // empty
push node onto *freelist via dword0 next
```

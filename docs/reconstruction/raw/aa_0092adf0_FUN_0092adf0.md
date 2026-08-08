# Raw capture: FUN_0092adf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092adf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092adf0` |
| **Canonical name** | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` |
| **System** | skills-abilities / inventory-transfer (adjacent) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0092adf0(float *param_1,undefined4 *param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  int *unaff_EDI;
  float fVar3;
  int *local_1c;
  int *local_18;
  undefined4 local_14 [4];
  
  local_18 = (int *)0x0;
  local_14[0] = 0;
  FUN_004294f0();
  iVar2 = FUN_004022a0(local_14,&local_18);
  piVar1 = local_18;
  while (local_18 = piVar1, iVar2 == 0) {
    if (piVar1 != (int *)0x0) {
      iVar2 = *(int *)(*(int *)(*unaff_EDI + 0xe98) + 0x250);
      if (iVar2 != 0) {
        iVar2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;
      }
      if (((piVar1[0x2b] != iVar2) && (iVar2 = FUN_00571010(piVar1[0x58],piVar1[0x59]), iVar2 == 0))
         && (iVar2 = 0, 0 < unaff_EDI[10])) {
        local_1c = unaff_EDI + 0xb;
        do {
          if (*local_1c == *(int *)(piVar1[0x2a] + 0x34)) {
            (**(code **)(*piVar1 + 0x144))();
            fVar3 = ((float)piVar1[0x22] - param_1[2]) * ((float)piVar1[0x22] - param_1[2]) +
                    ((float)piVar1[0x21] - param_1[1]) * ((float)piVar1[0x21] - param_1[1]) +
                    ((float)piVar1[0x20] - *param_1) * ((float)piVar1[0x20] - *param_1);
            if (fVar3 < *param_3) {
              *param_3 = fVar3;
              *param_2 = piVar1;
            }
          }
          local_1c = local_1c + 1;
          iVar2 = iVar2 + 1;
        } while (iVar2 < unaff_EDI[10]);
      }
    }
    iVar2 = FUN_004022a0(local_14,&local_18);
    piVar1 = local_18;
  }
  iVar2 = *(int *)(*(int *)(*unaff_EDI + 0xd34) + 0x20);
  if (*(char *)(iVar2 + 0x28) != '\0') {
    *(undefined1 *)(iVar2 + 0x28) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));
  }
  return 1;
}
```

---

## WQ8R-I append (2026-08-04) — live re-decompile + image seal

**Tools:** `batch_decompile` / `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address`, `get_function_callers`. **No** `disassemble_bytes`.

### Body / ABI (image)

| Fact | Value |
|---|---|
| Body | `0x0092adf0`–`0x0092af7a` (end exclusive per Ghidra body; pad `CC` after) |
| Epilogue | `mov al,1` / restore / **`ret 0x0C`** (`C2 0C 00` @ end) |
| Entry | `push ebp; mov ebp,esp; and esp,-16; sub esp,0x18` |
| Context | **EDI** = filter ctx (`*EDI` = client*); not ECX-this |
| Stack | `float* origin` (+4), `void** bestOut` (+8), `float* bestDistSq` (+0xC) |
| Return | **1** always after unlock |

### Entry bytes (64B @ `0x0092adf0`)

```
55 8B EC 83 E4 F0 83 EC 18 33 C0 89 44 24 10 89 44 24 14
8B 07 8B 88 34 0D 00 00 8B 49 20 53 56 E8 DB E6 AF FF ...
```

### FindItemByCoid thiscall (bytes mid-loop — decompiler hides ECX)

After self-exclude compare:

1. `ECX = *(*EDI + 0xE98)` → local **character**
2. Self-id: `*(character+0x250)` then C++ this-adjust `(vtbl[+4]+4)+obj` compared to `object+0xAC` (`piVar1[0x2b]`)
3. `ECX = *(character + 0xCBC)` → **InventoryGrid*** (type-3 **locker** path; same plate as DropResponse type 3)
4. push `object+0x164`, `object+0x160` (COID hi/lo = `[0x59]`/`[0x58]`)
5. `CALL InventoryGrid_FindItemByCoid` (`0x00571010`)
6. Continue object only if return **NULL** (COID not present in that grid)

### CBID whitelist

- Count: `*(EDI + 0x28)` (`unaff_EDI[10]`)
- Array: `EDI + 0x2C` (`unaff_EDI + 0xb`)
- Match: `*(object->clonebase + 0x34)` where `clonebase = object[0x2a]` (`+0xA8`)

### Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller (1) | `0x0092af80` | multi-list target dispatcher (calls this when `ctx+0x28 > 0`) |
| Grandcaller | `0x0092bf60` | uses char pos vtbl+0x1A0 then `FUN_0092af80` |
| Callee | `0x004294f0` | TraversalLock |
| Callee | `0x004022a0` | IterateNext |
| Callee | `0x00571010` | `InventoryGrid_FindItemByCoid` |
| Callee | — | object vtbl `+0x144` (refresh/world-pos helper before dist) |
| Callee | `LeaveCriticalSection` | unlock list lock @ `*(client+0xD34)+0x20` |

### Sibling arms on same ctx (not owned)

| Offset count | Helper | Role (sketch) |
|---|---|---|
| `+0x20/+0x24` COID pair | `CVOGReaction_ResolveObjectTarget` | direct id |
| `+0x28` | **this VA** | CBID list + locker absence |
| `+0x80` | `FUN_0092abc0` | type/list walk |
| `+0x54` | `FUN_0092a980` | another CBID/hash arm |
| `+0xAC` | `FUN_0092a760` / `FUN_00929cd0` | further filter |

Live decompile body matches 2026-07-23 raw CF; **bytes win** on ECX grid path and `ret 0x0C`.

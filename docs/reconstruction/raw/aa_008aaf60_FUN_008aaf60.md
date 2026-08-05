# Raw capture: FUN_008aaf60

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aaf60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008aaf60` |
| **Body** | `0x008aaf60`–`0x008ab098` (312 B / `0x138`) |
| **Canonical name** | `FUN_008aaf60` |
| **Inferred name** | `Client_MissionDialog_SetHeaderCaption_Inferred` |
| **System** | `missions-progression` |
| **Capture timestamp** | `2026-07-23` (scaffold); live seal append `2026-08-04` WQ7R-A |
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs |
| **Integrity** | Do not overwrite the original raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile — 2026-07-23; reconfirmed live 2026-08-04)

```c
void __fastcall FUN_008aaf60(int param_1)

{
  char *pcVar1;
  int unaff_EDI;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [24];
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009abcb7;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x6e0) != 0) {
    if (unaff_EDI == 0) {
      ExceptionList = &local_c;
      (**(code **)(**(int **)(param_1 + 0x6e0) + 0x1d8))(0);
      (**(code **)(**(int **)(param_1 + 0x6e0) + 0x34c))();
    }
    else {
      ExceptionList = &local_c;
      FUN_007a69d0();
      pcVar1 = (char *)FUN_007a6de0();
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,pcVar1);
      local_4 = 0;
      if (DAT_00d1b6d8 != 0) {
        FUN_005465c0();
      }
      (**(code **)(**(int **)(param_1 + 0x6e0) + 0x1d8))(0);
      FUN_008aab00(*(undefined4 *)(param_1 + 0x6e0));
      (**(code **)(**(int **)(param_1 + 0x6e0) + 0x1f0))();
      (**(code **)(**(int **)(param_1 + 0x6e0) + 0x34c))();
      if (((DAT_00d1b21c == '\0') || (*(int *)(param_1 + 0x648) == 2)) ||
         (*(int *)(param_1 + 0x648) == 3)) {
        (**(code **)(**(int **)(param_1 + 0x6e0) + 0x1fc))();
      }
      uStack_10 = 0xffffffff;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xffffffcc);
    }
    (**(code **)(**(int **)(param_1 + 0x6e0) + 0x214))(0);
    FUN_008aa610();
  }
  ExceptionList = local_c;
  return;
}
```

---

## Live seal append — 2026-08-04 (WQ7R-A)

### Tools
- `decompile_function` @ `0x008aaf60` — body **≡** 2026-07-23 raw CF
- `analyze_function_complete` — callers `Client_UpdateMissionJournal`, `Client_ShowNpcMissionDialogUI`; callees listed
- `get_function_by_address` — body `008aaf60`–`008ab098`
- `get_function_xrefs` — 6 call sites (incl. `FUN_0093e450` / choice-dialog path @ `0x0093e661`)
- `read_memory` 320 B @ entry
- **No** `disassemble_bytes`; **no** Launcher

### ABI (bytes — decompiler lag notes)
- **ECX** = dialog context (`mov esi, ecx`) — decompiler `__fastcall param_1`
- **EDI** = caption key / string id (`test edi,edi`; non-zero path `push edi` into `FUN_007a6de0`) — decompiler `unaff_EDI`
- SEH frame `LAB_009abcb7`; stack locals; plain **`C3`** after `add esp, 0x28`
- Return: void

### Decompiler lag on vtable `+0x1d8`
Decompile shows `(vtbl+0x1d8)(0)`. Entry bytes for both branches push **three** args:

```
push 1
push 1
push 0
call [vtable+0x1d8]
```

Preserve **(0, 1, 1)** order (right-to-left: arg0=0, arg1=1, arg2=1). Clean must not collapse to a single formal.

### Non-zero EDI path order (bytes ≡ CF)
1. `FUN_007a69d0()` then `FUN_007a6de0(EDI, -1)` → `std::string` from result
2. If `DAT_00d1b6d8`: `FUN_005465c0(character, &string)` (cdecl, `add esp,8`)
3. Widget `dialog+0x6e0`: vtbl `+0x1d8(0,1,1)`
4. `FUN_008aab00(widget)` — text/chrome apply (owned residual WQ7R-C)
5. vtbl `+0x1f0()`, `+0x34c()`
6. If `DAT_00d1b21c==0` **OR** dialog state `+0x648` ∈ {2,3}: vtbl `+0x1fc()`
7. Destroy `std::string`
8. Common: vtbl `+0x214(0)` then `FUN_008aa610()` (owned residual WQ7R-B)

### Zero EDI path
- vtbl `+0x1d8(0,1,1)` + `+0x34c()` only, then common tail (`+0x214(0)`, `FUN_008aa610`)

### Entry hex (`read_memory` 320 B @ `0x008aaf60`)
```
64a1000000006aff68b7bc9a00506489250000000083ec1c568bf183bee0060000000f840101000085ff0f84c2000000e83bbaefff6aff578bc8e841beefff508d4c2408ff15f8629c00c744242800000000a1d8b6d10085c0740e8d4c24045150e8fab5c9ff83c4088b8ee00600008b116a016a016a00ff92d8010000837c241c108b4c240873048d4c24088b86e006000050e808fbffff8b8ee00600008b1183c404ff92f00100008b8ee00600008b01ff904c030000803d1cb2d1000074108b864806000083f802740583f803750e8b8ee00600008b11ff92fc010000c7442428ffffffff8d4c2404ff15f4629c00eb228b8ee00600008b016a016a016a00ff90d80100008b8ee00600008b11ff924c0300008b8ee00600008b016a00ff9014020000e887f5ffff8b4c24205e64890d0000000083c428c3
```

### Callers (6 xrefs)
| Site | Parent |
|------|--------|
| `0x00943a9d`, `0x00943af1`, `0x00943b27` | `Client_ShowNpcMissionDialogUI` |
| `0x008ae1ec`, `0x008ae21b` | `Client_UpdateMissionJournal` |
| `0x0093e661` | `FUN_0093e450` (choice / non-mission dialog case 0 header clear path) |

### Terminal
`terminal_coverage = false` (no Launcher / runtime Confirmed).

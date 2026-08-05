# Raw capture: FUN_004bce90

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bce90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bce90` |
| **Canonical name** | `FUN_004bce90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_004bce90(undefined4 *param_1,byte param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a16eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009cb450;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1 << (param_2 & 0x1f);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(byte *)(param_1 + 7) = param_2;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  local_4 = 0;
  FUN_004bc7a0();
  ExceptionList = local_c;
  return param_1;
}
```

---

## W28-J re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W28-J |
| **Tools** | `decompile_function` + `read_memory` + function meta / callers / callees / xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw body above (identical CF) |
| **Body** | `0x004bce90`–`0x004bcf01` (**114 B / `0x72`**); pad `CC` from `0x004bcf02` |
| **Exit** | `83 C4 10 C2 04 00` — **`ret 4`**, EAX = this |
| **ABI** | `__thiscall`; ECX=this; stack **byte log2** (4-byte slot) |
| **Vtbl** | `C7 06 50 B4 9C 00` → `*this = PTR_FUN_009cb450` |
| **Callee** | `E8 B1 F8 FF FF` @ `0x004bcee6` → `FUN_004bc7a0` (AllocBucketTable twin; not OWN) |
| **Callers** | sole code xref: `FUN_004bbfb0` COList_Constructor ×1 (`0x004bc0b0`) with fixed arg **5** |
| **sizeof host** | **`0x34`** (`operator_new(0x34)` at COList site) |
| **Name** | `CNDHash_Ctor_009cb450` (stamp-qualified; twin of `CNDHash_Ctor_009cb45c`) |

### Full-body hex (`read_memory` @ `0x004bce90`, 114 B)

```
6A FF 68 EB 16 9A 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 51 33 C0 56 8B F1
8A 4C 24 18 BA 01 00 00 00 D3 E2 C7 06 50 B4 9C 00 89 46 04 89 46 0C 89 56 08
89 46 10 89 46 14 89 46 18 88 4E 1C 88 46 1D 89 46 20 89 74 24 04 89 46 28
89 46 2C 89 46 30 8B CE 89 44 24 10 E8 B1 F8 FF FF 8B 4C 24 08 8B C6 5E
64 89 0D 00 00 00 00 83 C4 10 C2 04 00
```

### Diff vs `aa_004bcf90` (only two imm diffs)

| Site | `004bce90` | `004bcf90` |
|---|---|---|
| vtbl imm | `50 B4 9C 00` (`009cb450`) | `5C B4 9C 00` (`009cb45c`) |
| call rel32 | `E8 B1 F8 FF FF` → `004bc7a0` | `E8 51 F8 FF FF` → `004bc840` |

Field init order/offsets identical (including unwritten `+0x24`).

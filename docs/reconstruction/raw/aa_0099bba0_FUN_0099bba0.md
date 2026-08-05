# Raw capture: FUN_0099bba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099bba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099bba0` |
| **Canonical name** | `FUN_0099bba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x0099bd7c) */
/* WARNING: Removing unreachable block (ram,0x0099bd80) */
/* WARNING: Removing unreachable block (ram,0x0099bdd5) */
/* WARNING: Removing unreachable block (ram,0x0099bdd0) */
/* WARNING: Removing unreachable block (ram,0x0099bdd8) */
/* WARNING: Removing unreachable block (ram,0x0099bddc) */
/* WARNING: Removing unreachable block (ram,0x0099be37) */
/* WARNING: Removing unreachable block (ram,0x0099bde1) */
/* WARNING: Removing unreachable block (ram,0x0099be1a) */
/* WARNING: Removing unreachable block (ram,0x0099be2f) */
/* WARNING: Removing unreachable block (ram,0x0099be2b) */
/* WARNING: Removing unreachable block (ram,0x0099be3c) */
/* WARNING: Removing unreachable block (ram,0x0099bd34) */
/* WARNING: Removing unreachable block (ram,0x0099bd3a) */
/* WARNING: Removing unreachable block (ram,0x0099bd40) */
/* WARNING: Removing unreachable block (ram,0x0099be54) */

undefined4 FUN_0099bba0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;
  uint uVar1;
  uint unaff_EBP;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  uint uStack_50;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_44;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_40;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_3c;
  undefined4 local_30;
  undefined4 local_2c;
  void *pvStack_1c;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1372;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_007a4480();
  local_30 = 0;
  local_2c = 0;
  local_4 = 0;
  (**(code **)(*param_3 + 0x14))();
  FUN_007a4480();
  uVar1 = 0;
  pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0;
  if (unaff_EBP != 0) {
    do {
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &local_30);
      pvStack_c._0_1_ = 1;
      FUN_00766fb0();
      FUN_00989e00();
      FUN_004301f0();
      pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &local_30);
      uVar1 = uVar1 + 1;
      pbVar2 = pbStack_3c;
    } while (uVar1 < unaff_EBP);
  }
  (**(code **)(*param_3 + 0x14))();
  FUN_007a4480();
  FUN_00430540(local_4);
  uStack_50 = 0;
  if (local_4 != 0) {
    do {
      (**(code **)(*param_3 + 0x14))();
      FUN_00430600(0);
      uStack_50 = uStack_50 + 1;
      pbVar2 = pbStack_44;
    } while (uStack_50 < local_4);
  }
  uStack_14 = 0xffffffff;
  this = pbVar2;
  if (pbVar2 == (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0)
  {
    ExceptionList = pvStack_1c;
    return 1;
  }
  for (; this != pbStack_40; this = this + 0x1c) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pbVar2);
}
```

---

## W34-J re-verify (2026-07-29)

**Tools:** `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + string/callee decompiles for role. **No** `disassemble_bytes`. **No** Launcher.

### Product plate (read_memory)

| VA | ASCII |
|----|-------|
| `0x00a9b728` | `CNDAssetStringTable::Unserialize` |
| `0x00a9b75c` | `string table size =%u` |
| `0x00a9b718` | `pyramids = %u` (space form) / nearby `pyramids =%u` |

Matches serialize twin plate at `0x0099b8e0` (`CNDAssetStringTable_Serialize` in NAMING_REGISTRY).

### Body / ABI (bytes)

| Item | Value |
|------|-------|
| Range | `0x0099bba0`–`0x0099BED5` exclusive |
| Size | **821 B** / `0x335` |
| Pad | `CC…` then next unit |
| SEH | `LAB_009b1372` (`68 72 13 9B 00`) |
| Frame | `83 EC 54` + saved EBX/EBP/ESI/EDI |
| Stream this | **EBP** = reader (`8B 6C 24 74` early; vcall `FF 50 14` = vtbl[+0x14] read) |
| Epilogue | `B0 01` … `83 C4 60 C2 0C 00` → **AL=1**, **RET 12** (3 stack formals) |
| Ghidra trap | false-noreturn on `operator_delete` — epilogue **present** after string-vec dtor loop |

### Full body hex (821 B)

```
6aff6872139b0064a100000000506489250000000083ec5453558b6c247456576828b7a9006affe8b488e0ff33f633ff83c408897c243c89742440897424446a048d4c2414897424708b4500518bcd89742418ff50148b54241052685cb7a9006affe87988e0ff83c40c33db3974241076728b44247483c004894424308d49008d4c2448ff1588629c008d7c24488bf5c644246c01e876b3dcff837c2460108b44244c73048d44244c508d4c2438518b4c2438e8a8e1feff8d542448528d4c243ce88a45a9ff8d4c2448c644246c00ff15f4629c0083c3013b5c241072a28b7c243c33f68b45006a048d8c2480000000518bcd89b42484000000ff50148b54247c526818b7a9006affe8d287e0ff8b8c24880000008b9c2484000000518bc489642444518bcb89700489700889700ce86c48a9ff3974247c897424300f86ae01000033ff897c24208b43048b550003c78944242c6a048d442420508bcd89742424ff52148b4c241c83ec108bc48964244489700489700889700c8b74243c51e8dc48a9ff33c9394c241c894c242c0f863a010000894c2418eb0633c98d6424008b43048b4407048b542418894c24146a048d4c24188d34028b4500518bcdff50148b4c241433c050508bd6e80005abff33f6397424140f86d80000008d6424008b43048b4407048b5424188b7c02048b45006a048d4c2428518bcdc744242c00000000ff50148b55006a048d44f704508bcdff52148b4424248b54243c8d0cc5000000002bc8837c8a18108d048a72058b5804eb038d580485db745b803b0074568b4c24748b410c8b490868e05a43008d5424385250518d44243850895c2448e83b41abff8b8c24880000008b410c8b4c243c83c4143bc874118b095351ff1578669c0083c40885c0740433c0eb0d8b5424288b02eb05a1c0ead1008b5c24788904f78b7c242083c6013b7424140f822cffffff8b44242c834424181083c0013b44241c8944242c0f82ccfeffff8b44243083c00183c71033f63b44247c89442430897c24200f825cfeffff8b7c243c3bfec744246cffffffff74228b5c24403bfb8bf7740f8bceff15f4629c0083c61c3bf375f157e867d9aeff83c4048b4c24645f5e5db00164890d000000005b83c460c20c00
```

### Staged semantics (outer sealed; pyramid nested with decompiler noise)

1. Log plate `CNDAssetStringTable::Unserialize` via `FUN_007a4480`.
2. Zero local `vector<basic_string>` shell (begin/end/cap @ stack).
3. Stream **read u32** size via reader vtbl[+0x14] size=4; log `string table size =%u`.
4. For i in [0, size): default-ctor local string; `FUN_00766fb0` (read C-string into it from stream); `FUN_00989e00` (string intern/lookup into table host); `FUN_004301f0` / `StringVec_PushBack` onto local path vector; dtor local.
5. Stream read **pyramids** count; log `pyramids =%u`; `FUN_00430540` resize host pyramid vector (elem stride **0x10**).
6. Nested loops: per-pyramid / per-row stream reads; `FUN_00430600` reshape; lower_bound-style `FUN_0044ff40` + IAT `_stricmp` resolve string indices into host table; fill row slots.
7. Destroy local string vector (dtor each 0x1c + `operator_delete`); **return 1** in AL.

### Callers / callees

| Direction | Value |
|-----------|-------|
| Callers | `FUN_0099c1c0` @ `0x0099c23a` only |
| Callees (principal) | `FUN_007a4480`, IAT `basic_string` ctor/dtor, `FUN_00766fb0`, `FUN_00989e00`, `FUN_004301f0`, `FUN_00430540`, `FUN_00430600`, `FUN_0044ff40`, IAT `_stricmp`, `operator_delete` |

### Name

`CNDAssetStringTable_Unserialize` (product string plate; Ghidra `FUN_0099bba0`).

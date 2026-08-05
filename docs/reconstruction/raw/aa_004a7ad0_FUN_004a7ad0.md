# Raw capture: FUN_004a7ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004a7ad0` |
| **Canonical name** | `FUN_004a7ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall

FUN_004a7ad0(int param_1,int param_2,uint param_3,

            basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            *param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  undefined4 uVar4;

  uint uVar5;

  uint extraout_ECX;

  int iVar6;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_34 [28];

  int local_18;

  undefined1 *local_14;

  void *local_10;

  undefined1 *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a11e9;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc0;

  ExceptionList = &local_10;

  local_18 = param_1;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            (local_34,param_4);

  iVar2 = *(int *)(param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (0x9249249U - iVar2 < param_3) {

      FUN_004a6820();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (uVar5 < iVar2 + param_3) {

      if (0x9249249 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00469c50();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x1c);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_004a6b50(*(undefined4 *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_004a74f0(iVar2,param_3,local_34,param_1,param_2);

      FUN_004a6b50(param_2,*(undefined4 *)(param_1 + 8),iVar2 + param_3 * 0x1c,param_1,param_2);

      local_8 = 0;

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_004a7aa0(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x1c + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x1c);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      iVar1 = param_3 * 0x1c;

      if ((uint)((iVar2 - param_2) / 0x1c) < param_3) {

        FUN_004a6b50(param_2,iVar2,iVar1 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_004a7a70(*(undefined4 *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x1c

                     ,local_34);

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

        local_8 = 0;

        FUN_004a68a0(param_2,*(int *)(param_1 + 8) + param_3 * -0x1c,local_34);

      }

      else {

        iVar6 = iVar2 + param_3 * -0x1c;

        uVar4 = FUN_004a6b50(iVar6,iVar2,iVar2,param_1,param_2);

        *(undefined4 *)(param_1 + 8) = uVar4;

        FUN_004a68d0(param_2,iVar6,iVar2,param_2);

        FUN_004a68a0(param_2,iVar1 + param_2,local_34);

      }

    }

  }

  local_8 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(local_34);

  ExceptionList = local_10;

  return;

}
```

---

## W34-R append (2026-07-29) — decompile + read_memory seal

| Field | Value |
|---|---|
| **Tools** | `batch_decompile`, `get_function_by_address`, `get_function_xrefs`, `read_memory`. **No** `disassemble_bytes`. |
| **Body** | `0x004a7ad0`–`0x004a7df7` exclusive (**807 B** / `0x327`); pad `CC` |
| **ABI** | **ECX=`vector*`**; stack **where*, count, value***; **`RET 0x0C`** (`C2 0C 00`); void |
| **SEH** | `LAB_009a11e9` |
| **Elem stride** | **`0x1c`** (MSVC `basic_string<wchar_t>`) |
| **Max elems** | **`0x9249249`** (`~0u/0x1c`) |
| **Growth** | **1.5x** (`cap + (cap>>1)`), floor to `size+count` |
| **Callers** | `FUN_004a7ff0` @ `0x004a8043` (insert-one rebind: count=`1`) |
| **Callees** | wstring copy/dtor IAT; `FUN_004a6820`; `FUN_00469c50`; `operator_new`/`operator_delete`; `FUN_004a6b50`; `FUN_004a74f0`; `FUN_004a7aa0`; `FUN_004a7a70`; `FUN_004a68a0`; `FUN_004a68d0` |
| **Name** | `StdVector_InsertN_BasicStringW` (**Inferred**) |
| **Layout** | begin@`+4`, end@`+8`, capEnd@`+0xC` |
| **Twin** | char `StdVector_InsertN_BasicString` @ `0x004306b0` (W32-B); POD wave-mate `StdVector_InsertN_Elem28` @ `0x0055be00` |

### Semantics (decompile ≡ bytes for CF)

1. Copy `*value` into local `basic_string<wchar_t>` (SEH-owned).
2. If `count==0`: dtor local; return.
3. Capacity / size in element units (`/ 0x1c`).
4. If `size + count` exceeds max → `FUN_004a6820`.
5. **Grow path** (`cap < size+count`): 1.5x (or exact floor); `operator_new(newCap*0x1c)`; relocate prefix + fill-n + suffix; destroy+delete old; rebind triad.
6. **In-place** hole/mid arms via helpers.
7. Destroy local wstring; restore SEH; **`RET 0x0C`**.

### Epilogue / constants (read_memory)

- Entry: `55 8B EC 6A FF 68 E9 11 9A 00`.
- This: `8B F1`.
- Magic `/0x1c`: `B8 93 24 49 92` (`0x92492493`).
- Max: `BA 49 92 24 09` (`0x09249249`).
- Exit: `5B 8B E5 5D C2 0C 00`.

### Full body hex (807 B)

```
558bec6aff68e9119a0064a100000000506489250000000083ec248b45105356578bf18965f0508d4dd08975ecff15b4629c008b5e0433c93bd9894dfc74188b4e0c2bcbb893244992f7e903d1c1fa048bcac1e91f03ca8b7d0c85ff0f84a202000085db750433c0eb198b5e082b5e04b893244992f7eb03d3c1fa048bc2c1e81f03c2ba499224092bd03bd773078bcee8bbecffff837e0400750433c0eb198b5e082b5e04b893244992f7eb03d3c1fa048bc2c1e81f03c203c73bc80f83420100008bc1d1e8ba499224092bd03bd1730433c9eb0203c8837e0400750433c0eb198b5e082b5e04b893244992f7eb03d3c1fa048bc2c1e81f03c203c73bc8730b8bcee87920fcff8bc803cf8d1ccd000000002bd903db03db53e8a41cfeff8b55088b4e0452565089451089450c8b45085051c645fc01e845efffff8b4d0883c41851568d55d052575089450ce8cff8ffff8b55088b4d0c83c414528d04fd000000002bc78d04818b4e08565089450c8b45085150e807efffff8b460483c41485c0c745fc0000000074188b4e082bc8b893244992f7e903d1c1fa048bc2c1e81f03c203f88b460485c074188b4e0851508bcee819feffff8b460450e8921bfeff83c4048b451003d88d14fd000000002bd78d0c90895e0c894e08894604e9220100008b550c8b75108b4dec5256e8defdffff56e85a1bfeff83c4046a006a00e88cc01f008b4e088bd92b5d08b893244992f7eb03d3c1fa048d1cfd000000002bdf8bc2c1e81f03db03c203db3bc7894d100f83970000008b55088d04138b55085256508b45085150e833eeffff8b4e082b4d0883c4148d55d052b893244992f7e903d1c1fa048bc2c1e81f03c22bf88b460857508bcec645fc03e821fdffff015e088b76088b55088d4dd0512bf35652c745fc00000000e834ebffff83c40ceb638b4d0c8d04cd000000002bc18b4dec8b510803c003c003d0528b550803c250e80bfdffff6a006a00e8c2bf1f008b45085056518bf9512bfb57e8a1edffff8b4d088b551051528946088b75085756e80cebffff8d45d05003de5356e8cfeaffff83c4308d4dd0c745fcffffffffff15ac629c008b4df45f5e64890d000000005b8be55dc20c00
```

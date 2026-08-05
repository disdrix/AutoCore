# Raw capture: FUN_0075eff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075eff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0075eff0` |
| **Canonical name** | `FUN_0075eff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0075eff0(undefined4 *param_1,undefined4 param_2,byte param_3)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 local_38 [7];
  undefined4 local_1c;
  uint local_18;
  undefined1 auStack_8 [8];
  
  iVar3 = DAT_00d1f614;
  if (DAT_00d1f614 != 0) {
    *(int *)(DAT_00d1f614 + 0x364) = *(int *)(DAT_00d1f614 + 0x364) + (-1 - param_1[0xb1]);
    iVar1 = FUN_0040ead0(param_1[0xb0]);
    *(int *)(iVar3 + 0x3ac) =
         *(int *)(iVar3 + 0x3ac) -
         ((uint)(iVar1 * param_1[0xaf] * param_1[0xae] * (param_1[0xb1] + 1)) >> 3);
  }
  if ((param_1[0xb7] != 0) && (iVar3 != 0)) {
    *(int *)(iVar3 + 0x368) = *(int *)(iVar3 + 0x368) + -1;
    iVar1 = FUN_0043b800();
    *(int *)(iVar3 + 0x3b0) =
         *(int *)(iVar3 + 0x3b0) - ((uint)(iVar1 * param_1[0xaf] * param_1[0xae]) >> 3);
  }
  FUN_0075e710();
  local_38[1] = in_EAX[1];
  puVar5 = param_1 + 0xae;
  puVar6 = local_38;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  local_38[0] = *in_EAX;
  local_1c = param_2;
  local_18 = (uint)param_3;
  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x1fe,1,
                 "Beginning shutdown for Device Reset()");
  FUN_00985f40();
  FUN_00985580();
  FUN_009864e0();
  FUN_009686e0();
  FUN_0073d8d0();
  iVar3 = param_1[0x1d5];
  piVar9 = *(int **)(iVar3 + 8);
  piVar4 = (int *)*piVar9;
  if (piVar4 != piVar9) {
    do {
      if (*(int *)(piVar4[2] + 0x30) == 0) {
        FUN_0096c8e0();
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(iVar3 + 8));
  }
  iVar3 = param_1[0x1e7];
  piVar9 = *(int **)(iVar3 + 0x3d4);
  if (piVar9 != (int *)0x0) {
    (**(code **)(*piVar9 + 8))(piVar9);
  }
  *(undefined4 *)(iVar3 + 0x3d4) = 0;
  FUN_0073e980();
  FUN_0074f0c0();
  piVar9 = (int *)param_1[2];
  if (piVar9 != (int *)0x0) {
    (**(code **)(*piVar9 + 8))(piVar9);
  }
  param_1[2] = 0;
  piVar9 = (int *)param_1[3];
  if (piVar9 != (int *)0x0) {
    (**(code **)(*piVar9 + 8))(piVar9);
  }
  param_1[3] = 0;
  iVar3 = (**(code **)(*(int *)*param_1 + 0x40))((int *)*param_1,local_38);
  if (-1 < iVar3) {
    (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);
    iVar3 = FUN_00985610();
    if (iVar3 < 0) {
      pcVar10 = "Failed to Reset() device on IB Factory";
      uVar8 = 0x236;
    }
    else {
      iVar3 = FUN_00986570();
      if (iVar3 < 0) {
        pcVar10 = "Failed to Reset() device on VB Factory";
        uVar8 = 0x239;
      }
      else {
        iVar3 = FUN_0096e8e0(param_1[0x1d5]);
        if (iVar3 < 0) {
          pcVar10 = "Failed to Reset() device on Texture Factory";
          uVar8 = 0x23c;
        }
        else {
          iVar3 = FUN_00968720();
          if (iVar3 < 0) {
            pcVar10 = "Failed to Reset() device on gfxBufferedViews";
            uVar8 = 0x23f;
          }
          else {
            iVar3 = FUN_0073d870();
            if (iVar3 < 0) {
              pcVar10 = "Failed to Reset() device on Effect Factory";
              uVar8 = 0x242;
            }
            else {
              iVar3 = FUN_00966760();
              if (iVar3 < 0) {
                pcVar10 = "Failed to Reset() device on Stats Monitor";
                uVar8 = 0x245;
              }
              else {
                iVar3 = FUN_0074f090();
                if (-1 < iVar3) {
                  FUN_00968680();
                  FUN_0073be50();
                  puVar5 = (undefined4 *)&stack0xffffffbc;
                  puVar6 = param_1 + 0xae;
                  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *puVar6 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar6 = puVar6 + 1;
                  }
                  FUN_0075e710();
                  piVar9 = (int *)*param_1;
                  iVar3 = (**(code **)(*piVar9 + 0x1c))(piVar9,param_1 + 5);
                  if (iVar3 < 0) {
                    uVar8 = FUN_006b7a5a(iVar3,"Failed GetDeviceCaps for hardware.");
                    uVar8 = FUN_006a5dac(iVar3,uVar8);
                    uVar8 = FUN_0076cec0(auStack_8,"%s - %s\r\n%s",uVar8);
                    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",
                                   0x256,3,uVar8);
                  }
                  if (param_1[0x1df] == 0) {
                    puVar5 = param_1 + 5;
                    puVar6 = param_1 + 0x51;
                    for (iVar3 = 0x4c; iVar3 != 0; iVar3 = iVar3 + -1) {
                      *puVar6 = *puVar5;
                      puVar5 = puVar5 + 1;
                      puVar6 = puVar6 + 1;
                    }
                  }
                  else {
                    (**(code **)(*(int *)*param_1 + 0x134))((int *)*param_1,1);
                    iVar3 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,param_1 + 0x51);
                    if (iVar3 < 0) {
                      uVar8 = FUN_006b7a5a(iVar3,"Failed GetDeviceCaps for software.");
                      uVar8 = FUN_006a5dac(iVar3,uVar8);
                      uVar8 = FUN_0076cec0(auStack_8,"%s - %s\r\n%s",uVar8);
                      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",
                                     0x25d,3,uVar8);
                    }
                    if (param_1[0x1df] == 1) {
                      (**(code **)(*(int *)*param_1 + 0x134))((int *)*param_1,0);
                    }
                  }
                  iVar7 = 0;
                  iVar1 = 0;
                  (**(code **)(*(int *)*param_1 + 0x48))((int *)*param_1,0,0,0,param_1 + 2);
                  (**(code **)(*(int *)*param_1 + 0xa0))((int *)*param_1,param_1 + 3);
                  param_1[4] = param_1[0xb8];
                  FUN_00966630();
                  *DAT_00d1f048 = param_1[2];
                  DAT_00d1f048[1] = param_1[3];
                  DAT_00d1f048[2] = param_1[4];
                  iVar3 = DAT_00d1f610;
                  *(undefined4 *)(DAT_00d1f610 + 0xc) = 0;
                  *(undefined4 *)(iVar3 + 0x10) = 0xffffffff;
                  *(undefined4 *)(iVar3 + 0x14) = 0xffffffff;
                  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",
                                 0x270,1,"Device Reset() complete");
                  iVar3 = DAT_00d1f614;
                  if (DAT_00d1f614 != 0) {
                    *(int *)(DAT_00d1f614 + 0x364) =
                         (int)piVar9 + *(int *)(DAT_00d1f614 + 0x364) + 1;
                    iVar2 = FUN_0040ead0(param_1[0xb0]);
                    *(int *)(iVar3 + 0x3ac) =
                         *(int *)(iVar3 + 0x3ac) +
                         ((uint)(iVar2 * ((int)piVar9 + 1) * iVar7 * iVar1) >> 3);
                  }
                  if ((unaff_ESI != 0) && (iVar3 != 0)) {
                    *(int *)(iVar3 + 0x368) = *(int *)(iVar3 + 0x368) + 1;
                    iVar2 = FUN_0043b800();
                    *(int *)(iVar3 + 0x3b0) =
                         *(int *)(iVar3 + 0x3b0) + ((uint)(iVar2 * iVar7 * iVar1) >> 3);
                  }
                  param_1[0x1e9] = 0;
                  return 0;
                }
                pcVar10 = "Failed to Reset() device on Global Effect";
                uVar8 = 0x248;
              }
            }
          }
        }
      }
    }
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",uVar8,3,pcVar10);
    return 0xffffffff;
  }
  if (iVar3 < -0x7789f7d8) {
    if (iVar3 == -0x7789f7d9) {
      pcVar10 = 
      "ERROR: Internal driver error. Applications should generally shut down when receiving this error. For more information, see Driver Internal Errors."
      ;
      goto LAB_0075f1db;
    }
    if (iVar3 == -0x7ff8fff2) {
      pcVar10 = "ERROR: Direct3D could not allocate sufficient memory to complete the call.";
      goto LAB_0075f1db;
    }
    if (iVar3 == -0x7789fe84) {
      pcVar10 = "ERROR: Direct3D does not have enough display memory to perform the operation. \n";
      goto LAB_0075f1db;
    }
  }
  else {
    if (iVar3 == -0x7789f798) {
      pcVar10 = 
      "ERROR: The device has been lost but cannot be reset at this time. Therefore, rendering is not possible. \n"
      ;
      goto LAB_0075f1db;
    }
    if (iVar3 == -0x7789f794) {
      pcVar10 = 
      "ERROR: The method call pd3dDevice->Reset() is invalid. For example, a method\'s parameter may have an invalid value. \n"
      ;
      goto LAB_0075f1db;
    }
  }
  pcVar10 = "ERROR: <UNKNOWN> from IDirect3DDevice9::Reset()\n";
LAB_0075f1db:
  FUN_0076c130(pcVar10);
  iVar3 = (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1);
  if (-1 < iVar3) {
    return 0xffffffff;
  }
  if (iVar3 == -0x7789f7d9) {
    FUN_0076c130(
                "Internal driver error. Applications should generally shut down when receiving this error. For more information, see Driver Internal Errors.\n"
                );
    return 0xffffffff;
  }
  if (iVar3 == -0x7789f798) {
    FUN_0076c130(
                "The device has been lost but cannot be reset at this time. Therefore, rendering is not possible\n"
                );
    return 0xffffffff;
  }
  if (iVar3 != -0x7789f797) {
    FUN_0076c130("<UNKNOWN> from IDirect3DDevice9::TestCooperativeLevel()\n");
    return 0xffffffff;
  }
  FUN_0076c130("The device has been lost but can be reset at this time.\n");
  return 0xffffffff;
}
```

---

## W37-N re-verify append (2026-08-04)

**Tools:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + `get_assembly_context` (sole caller `0x00754498`). **No** `disassemble_bytes`.

### Body / ABI (bytes)

| Field | Value |
|---|---|
| Range | `0x0075eff0`–`0x0075f55f` exclusive |
| Size | **1391 B** / `0x56F` |
| Exit | **`RET 12`** (`C2 0C 00`) after `ADD ESP,0x38` — **stdcall** 3 stack formals |
| Entry | `SUB ESP,0x38`; saves EBX/EBP/ESI/EDI; `MOV EBX,EAX` (EAX register formal) |

Success-path exit bytes @ `0x0075f550`:

```
899da4070000  ; mov [ebp+0x7a4], ebx   ; param_1[0x1e9] = 0 path uses XOR EAX later
5d            ; pop ebp
33c0          ; xor eax, eax          ; return 0
5b            ; pop ebx
83c438        ; add esp, 0x38
c20c00        ; ret 12
```

### Sole caller ABI (`Palantir_ResetDevice` @ `0x00754480`, W35-K)

Bytes @ call site (`0x00754486`–`0x00754498`):

```
MOV AL,[ESI+5]
MOV ECX,[ESI+0xB0]
MOV EDX,[ESI+0x28]
PUSH EDI                 ; save
LEA EDI,[ESI+8]
PUSH EAX                 ; stack arg3 = byte[Palantir+5]
PUSH ECX                 ; stack arg2 = [Palantir+0xB0]
PUSH EDX                 ; stack arg1 = [Palantir+0x28]  → gfxDevice*
MOV EAX,EDI              ; EAX formal = Palantir+8
CALL FUN_0075eff0
```

Sealed formals:

| Formal | Source | Role |
|---|---|---|
| EAX | `Palantir+8` | present-param seed (`*EAX`, `EAX[1]` → local PresentParams[0..1]) |
| stack1 | `*[Palantir+0x28]` | **gfxDevice*** host (`param_1` / EBP) |
| stack2 | `[Palantir+0xB0]` | written into present-param block (`local_1c`) |
| stack3 | `byte[Palantir+5]` | written into present-param block (`local_18`) |
| return | EAX | **0** success / **0xFFFFFFFF** fail |

### Semantics (product `gfxDevice.cpp`)

Path strings seal unit as **device Reset** implementation:

1. Optional `DAT_00d1f614` memory accounting tear-down using `param_1[+0xae..]` dims / mip / format helpers `FUN_0040ead0` / `FUN_0043b800`.
2. `FUN_0075e710`; build **14-dword** present-param local: copy `param_1+0x2B8` (14 dwords), overlay `*EAX` / `EAX[1]` / stack2 / stack3.
3. Log `\"Beginning shutdown for Device Reset()\"` (line `0x1FE`).
4. Shutdown cascade: `FUN_00985f40`, `FUN_00985580`, `FUN_009864e0`, `FUN_009686e0`, `FUN_0073d8d0`; texture list walk + conditional `FUN_0096c8e0`; Release COM @ `param_1[0x1e7]+0x3d4`; `FUN_0073e980`; `FUN_0074f0c0`; Release `param_1[2]` and `param_1[3]` (default surfaces).
5. **IDirect3DDevice9::Reset** via `(*param_1)->vtbl[+0x40](device, &local_present)`.
6. **Success path (hr ≥ 0):** `vtbl[+0x14]` (EvictManagedResources-class); then sequential factory Reset helpers with product fail strings:
   - IB Factory `0x236` / VB Factory `0x239` / Texture Factory `0x23c` / gfxBufferedViews `0x23f` / Effect Factory `0x242` / Stats Monitor `0x245` / Global Effect `0x248` → log + return **−1**.
   - On full success: `FUN_00968680`, `FUN_0073be50`; write-back 14 dwords to `param_1+0x2B8`; `FUN_0075e710`; GetDeviceCaps hardware (`vtbl+0x1c` → `param_1+5`); optional software caps path when `param_1[0x1df]≠0` (`vtbl+0x134` mode switch); recreate surfaces `vtbl+0x48` / `vtbl+0xa0`; `FUN_00966630`; publish `DAT_00d1f048[0..2]`; clear `DAT_00d1f610` slots; log `\"Device Reset() complete\"` (`0x270`); reverse memory accounting; `param_1[0x1e9]=0`; return **0**.
7. **Reset fail (hr < 0):** map D3D HRESULTs (`D3DERR_DRIVERINTERNALERROR`, `E_OUTOFMEMORY`, `D3DERR_OUTOFVIDEOMEMORY`, `D3DERR_DEVICELOST`, `D3DERR_INVALIDCALL`, unknown) via `FUN_0076c130`; `TestCooperativeLevel` `vtbl[+0xc]` with DEVICELOST / DEVICENOTRESET / DRIVERINTERNAL messages; always return **−1**.

### Call graph

- **Callers (1):** `FUN_00754480` `Palantir_ResetDevice` @ `0x00754498`.
- **Callees (high-signal):** `FUN_0075e710`, factory Reset helpers, `vog_LogMessage`, `FUN_0076c130`, `FUN_0040ead0`, `FUN_0043b800`, D3D vcalls on `*param_1`.

### Decompile vs bytes

| Topic | Decompile | Bytes / sealed |
|---|---|---|
| EAX formal | `in_EAX` phantom | **EAX live-in = Palantir+8** (caller + `MOV EBX,EAX`) |
| Stack arity / cleanup | 3 params implied | **RET 12** seals 3×4 |
| Return | `undefined4` 0 / −1 | **High** (`XOR EAX,EAX` / `return 0xffffffff`) |
| Product identity | path + Reset strings | **High** — `GfxDevice_Reset` |

### Name (W37-N)

`GfxDevice_Reset` — product plate from `gfxDevice.cpp` + `Device Reset()` log strings. Ghidra residual `FUN_0075eff0`.

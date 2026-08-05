# Raw capture: FUN_005cedf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cedf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cedf0` |
| **Canonical name** | `FUN_005cedf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005cf409) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_005cedf0(int param_1)



{

  ushort uVar1;

  ushort uVar2;

  int *piVar3;

  int iVar4;

  float *pfVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined4 *puVar8;

  float fVar9;

  undefined1 uStack_65;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined4 uStack_38;

  undefined4 uStack_34;

  float fStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  

  iVar4 = *(int *)(param_1 + 100);

  if (((iVar4 == 0) ||

      (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x19c))(),

      iVar4 == 0)) ||

     (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                                   *(int *)(param_1 + 100)) + 0x19c))(), *(int *)(iVar4 + 8) == 0))

  {

    *(undefined1 *)(param_1 + 0x60) = 0;

    *(undefined4 *)(param_1 + 0x3c) = 0;

    return;

  }

  fStack_64 = (float)(int)g_dwClientTickMs;

  if ((int)g_dwClientTickMs < 0) {

    fStack_64 = fStack_64 + _DAT_00aaa5dc;

  }

  fStack_64 = fStack_64 * g_flMsToSeconds_Inferred;

  if (*(char *)(param_1 + 0x60) != '\0') {

    if (fStack_64 - *(float *)(param_1 + 0x3c) <= DAT_00aaa8dc) {

      pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) +

                                              4 + *(int *)(param_1 + 100)) + 0x1a0))();

      fStack_60 = ABS(*pfVar5 - *(float *)(param_1 + 0x40));

      fStack_5c = ABS(pfVar5[1] - *(float *)(param_1 + 0x44));

      fStack_58 = ABS(pfVar5[2] - *(float *)(param_1 + 0x48));

      fStack_54 = ABS(pfVar5[3] - *(float *)(param_1 + 0x4c));

      if ((DAT_00a0f708 < fStack_58 || DAT_00a0f708 < fStack_5c) || DAT_00a0f708 < fStack_60)

      goto LAB_005cef56;

      *(undefined1 *)(param_1 + 0x60) = 0;

    }

    else {

      *(undefined1 *)(param_1 + 0x60) = 0;

    }

    *(undefined4 *)(param_1 + 0x3c) = 0;

  }

LAB_005cef56:

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                               *(int *)(param_1 + 100)) + 0x19c))();

  if ((((*(char *)(*(int *)(iVar4 + 8) + 0x40) == '\0') || (*(int *)(*(int *)(iVar4 + 8) + 8) == 0))

      && (iVar4 = *(int *)(param_1 + 100), *(float *)(iVar4 + 0x120) == 0.0)) &&

     ((*(char *)(iVar4 + 0x304) != '\0' ||

      ((*(int *)(iVar4 + 0x250) != 0 && (*(float *)(*(int *)(iVar4 + 0x250) + 0x614) != 0.0)))))) {

    pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))

                                ();

    fStack_60 = ABS(*(float *)(param_1 + 0x50) - *pfVar5);

    fStack_5c = ABS(*(float *)(param_1 + 0x54) - pfVar5[1]);

    fStack_58 = ABS(*(float *)(param_1 + 0x58) - pfVar5[2]);

    fStack_54 = ABS(*(float *)(param_1 + 0x5c) - pfVar5[3]);

    if ((fStack_58 <= DAT_00a10e78 && fStack_5c <= DAT_00a10e78) && fStack_60 <= DAT_00a10e78) {

      pfVar5 = (float *)FUN_004c3ac0();

      fStack_60 = ABS(*(float *)(param_1 + 0x50) - *pfVar5);

      fStack_5c = ABS(*(float *)(param_1 + 0x54) - pfVar5[1]);

      fStack_58 = ABS(*(float *)(param_1 + 0x58) - pfVar5[2]);

      fStack_54 = ABS(*(float *)(param_1 + 0x5c) - pfVar5[3]);

      if ((g_flOne < fStack_58 || g_flOne < fStack_5c) || g_flOne < fStack_60) {

        if (*(float *)(param_1 + 0x3c) == g_flZero) {

          *(float *)(param_1 + 0x3c) = fStack_64;

          return;

        }

        if (*(char *)(param_1 + 0x60) != '\0') {

          return;

        }

        if (fStack_64 - *(float *)(param_1 + 0x3c) <= DAT_00aaa68c) {

          return;

        }

        *(undefined1 *)(param_1 + 0x60) = 1;

        pfVar5 = (float *)FUN_004c3ac0();

        fStack_60 = *pfVar5;

        fStack_5c = pfVar5[1];

        fStack_58 = pfVar5[2];

        fStack_54 = pfVar5[3];

        piVar3 = *(int **)(*(int *)(param_1 + 100) + 0x250);

        if (piVar3 != (int *)0x0) {

          pfVar5 = (float *)(**(code **)(*piVar3 + 0x54))();

          fStack_60 = *pfVar5;

          fStack_5c = pfVar5[1];

          fStack_58 = pfVar5[2];

          fStack_54 = pfVar5[3];

        }

        pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4)

                                                + 4 + *(int *)(param_1 + 100)) + 0x1a0))();

        fStack_60 = fStack_60 - *pfVar5;

        fStack_5c = fStack_5c - pfVar5[1];

        fStack_58 = fStack_58 - pfVar5[2];

        fStack_54 = fStack_54 - pfVar5[3];

        pcVar6 = (char *)FUN_005d6870(&uStack_65);

        if (*pcVar6 != '\0') {

          fStack_64 = fStack_60 * fStack_60 + fStack_58 * fStack_58 + fStack_5c * fStack_5c;

          if (fStack_64 == 0.0) {

            fVar9 = 0.0;

          }

          else {

            fVar9 = g_flOne / SQRT(fStack_64);

            fStack_64 = fVar9;

          }

          fStack_58 = fStack_58 * fVar9;

          fStack_60 = fVar9 * fStack_60;

          fStack_5c = fStack_5c * fVar9;

          fStack_54 = fStack_54 * fVar9;

          uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                                       *(int *)(param_1 + 100)) + 0x1a4))();

          FUN_005d1d20(&fStack_20,uVar7);

          fStack_64 = fStack_20 * fStack_60 + fStack_18 * fStack_58 + fStack_1c * fStack_5c;

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(undefined4 *)(iVar4 + 0xc) = 0;

          }

          uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(undefined4 *)(iVar4 + 0xc) = 0;

          }

          uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          pfVar5 = (float *)(param_1 + 0x40);

          fVar9 = (float)uVar1 * _DAT_009da8cc + DAT_00aaa688;

          *pfVar5 = (float)uVar2 * _DAT_009da8d0 + DAT_00aaa690;

          *(undefined4 *)(param_1 + 0x44) = 0;

          *(float *)(param_1 + 0x48) = fVar9;

          *(undefined4 *)(param_1 + 0x4c) = 0;

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(undefined4 *)(iVar4 + 0xc) = 0;

          }

          uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          fVar9 = DAT_00aaa668;

          if ((uVar1 & 1) != 0) {

            *pfVar5 = *pfVar5 * DAT_00aaa668;

          }

          if (g_flZero < fStack_64) {

            *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * fVar9;

          }

          puVar8 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x18) + 0x1a0))();

          uStack_40 = *puVar8;

          uStack_3c = puVar8[1];

          uStack_38 = puVar8[2];

          uStack_34 = puVar8[3];

          puVar8 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x18) + 0x1a4))();

          uStack_50 = *puVar8;

          uStack_4c = puVar8[1];

          uStack_48 = puVar8[2];

          uStack_44 = puVar8[3];

          FUN_004e8bf0(&uStack_40,&uStack_50,pfVar5,&fStack_30);

          *pfVar5 = fStack_30;

          *(undefined4 *)(param_1 + 0x44) = uStack_2c;

          *(undefined4 *)(param_1 + 0x48) = uStack_28;

          *(undefined4 *)(param_1 + 0x4c) = uStack_24;

          return;

        }

        *(undefined4 *)(param_1 + 0x40) = g_abInferredDefaultAimPos._0_4_;

        *(undefined4 *)(param_1 + 0x44) = g_abInferredDefaultAimPos._4_4_;

        *(undefined4 *)(param_1 + 0x48) = g_abInferredDefaultAimPos._8_4_;

        *(undefined4 *)(param_1 + 0x4c) = g_abInferredDefaultAimPos._12_4_;

        return;

      }

    }

  }

  if (*(char *)(param_1 + 0x60) != '\0') {

    return;

  }

  *(undefined4 *)(param_1 + 0x3c) = 0;

  return;

}
```

---

## Live re-decompile (2026-07-29 W26-O)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x005cedf0`–`0x005cf558` (**1897 B** inclusive last RET; pad `CC` after) |
| **Prologue** | `55 8B EC 83 E4 F0 83 EC 64` — frame; `SUB ESP,0x64`; align 16 |
| **Epilogue** | `POP EDI/ESI/EBX; MOV ESP,EBP; POP EBP; RET` — **fastcall/thiscall ECX=this**; no stack formals |
| **Classification** | **worker** |
| **Callers (4 / 9 xrefs)** | `CVOGHBAIDriver_DoLogic`, `FUN_005d7f70` (`CVOGHBAICreatureBase_DoLogic`), `CVOGHBAICreatureBase_OnHeartBeat`, `FUN_005d7ca0` |
| **Callees** | `FUN_004c3ac0` (`CVOGObject_GetActivePositionPtr_Inferred`)×2, `FUN_005d6870`, `FUN_005d1d20`, `FUN_004e8bf0` (`Math_QuatTransformPoint_Inferred`), `CVOGReaction_RandomUnitScalar`×3; owner vtbl `+0x19c/+0x1a0/+0x1a4`; optional vehicle vtbl `+0x54`; object@`this+0x18` vtbl `+0x1a0/+0x1a4` |
| **Integrity** | Live decompile ≡ 2026-07-23 raw body (identical CF; unreachable-block warning retained) |
| **Canonical name** | `CVOGHBAI_UpdateAimOffset_Inferred` (Ghidra `FUN_005cedf0`) |

### Sealed ABI

```
// __fastcall / thiscall: ECX = AI helper object; void
// void CVOGHBAI_UpdateAimOffset_Inferred(AIAimState *this)
```

### this layout (fields touched)

| Off | Type | Role |
|---|---|---|
| `+0x18` | obj* | pose/transform source (vtbl +0x1a0 pos, +0x1a4 orient) |
| `+0x3c` | float | stage timestamp (seconds) |
| `+0x40..+0x4c` | float×4 | aim offset / aim position vec4 |
| `+0x50..+0x5c` | float×4 | last sampled reference pos |
| `+0x60` | char | aim-offset-active flag |
| `+0x64` | obj* | owner `CVOGObject` |

### Constants (`read_memory` sealed)

| Symbol | VA | Bits | Value | Role |
|---|---|---|---|---|
| `_DAT_00aaa5dc` | `0x00aaa5dc` | `4F800000` | **4294967296.0** | uint→float bias when tick ms signed-neg |
| `g_flMsToSeconds_Inferred` | `0x00a0f72c` | | **0.001** | ms→seconds |
| `DAT_00aaa8dc` | `0x00aaa8dc` | `40C00000` | **6.0** | active-offset TTL (s) |
| `DAT_00a0f708` | `0x00a0f708` | `3F400000` | **0.75** | clear if owner pos near stored offset |
| `DAT_00a10e78` | `0x00a10e78` | `3D4CCCCD` | **0.05** | still vs last sample |
| `g_flOne` | `0x00a0f2a0` | | **1.0** | active-pose drift gate |
| `g_flZero` | `0x00a0f518` | | **0.0** | timestamp empty / facing-dot test |
| `DAT_00aaa68c` | `0x00aaa68c` | `3FC00000` | **1.5** | wait before new offset (s) |
| `DAT_00aaa688` | `0x00aaa688` | `40A00000` | **5.0** | random Z base |
| `DAT_00aaa690` | `0x00aaa690` | `40800000` | **4.0** | random X base |
| `_DAT_009da8cc` | `0x009da8cc` | `38A000A0` | **≈5/65535** | ushort→float scale (Z) |
| `_DAT_009da8d0` | `0x009da8d0` | `38C000C0` | **≈6/65535** | ushort→float scale (X) |
| `DAT_00aaa668` | `0x00aaa668` | `BF800000` | **−1.0** | random sign flip |
| `g_abInferredDefaultAimPos` | (named global) | | 16 B | fallback aim vec4 |

### Control-flow stages (sealed)

1. **Owner/phys gate:** owner@`+0x64` null, or vtbl+0x19c host null, or host+8 phys null → clear flag@+0x60 + ts@+0x3c; return.
2. **Time:** `now = (float)(int)g_dwClientTickMs [+ 2^32 if neg] * 0.001`.
3. **Active clear:** if flag:
   - if `now - ts <= 6.0`: compare owner vtbl+0x1a0 pos to stored +0x40..; if all abs ≤ 0.75 on XYZ components that gate → clear flag; else keep (goto main).
   - else (TTL expired): clear flag.
   - on clear: `ts = 0`.
4. **Candidate gate:** phys body inactive path + owner `+0x120==0` + (char@+0x304 or vehicle@+0x250 with float@+0x614≠0).
5. **Still vs last:** abs(this+0x50.. − owner pos) all ≤ **0.05**.
6. **Active-pose drift:** abs(this+0x50.. − `FUN_004c3ac0` pos) any > **1.0**:
   - ts==0 → stamp `ts=now`; return (arm wait).
   - flag set → return.
   - `now-ts <= 1.5` → return (hold).
   - else set flag=1; build new aim offset:
     - base = GetActivePosition; override with vehicle vtbl+0x54 if vehicle present.
     - delta = base − owner pos; finite-check `FUN_005d6870`.
     - normalize XYZ (len² of x/z/y); facing basis via vtbl+0x1a4 + `FUN_005d1d20`; facing·delta.
     - 3× `CVOGReaction_RandomUnitScalar` ushort draws → local offset (X∈[4,10], Y=0, Z∈[5,10], W=0) with optional X and (if facing·delta>0) Z sign flip via −1.
     - transform local offset by object@+0x18 pos/orient via `FUN_004e8bf0`; store to +0x40..
     - non-finite → copy `g_abInferredDefaultAimPos`.
7. **Else:** if flag clear → `ts=0`; if flag set → keep.

### Live decompile (identical CF to raw)

```c

/* WARNING: Removing unreachable block (ram,0x005cf409) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005cedf0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  float fVar9;
  undefined1 uStack_65;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;

  iVar4 = *(int *)(param_1 + 100);
  if (((iVar4 == 0) ||
      (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x19c))(),
      iVar4 == 0)) ||
     (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                   *(int *)(param_1 + 100)) + 0x19c))(), *(int *)(iVar4 + 8) == 0))
  {
    *(undefined1 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return;
  }
  fStack_64 = (float)(int)g_dwClientTickMs;
  if ((int)g_dwClientTickMs < 0) {
    fStack_64 = fStack_64 + _DAT_00aaa5dc;
  }
  fStack_64 = fStack_64 * g_flMsToSeconds_Inferred;
  if (*(char *)(param_1 + 0x60) != '\0') {
    if (fStack_64 - *(float *)(param_1 + 0x3c) <= DAT_00aaa8dc) {
      pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) +
                                              4 + *(int *)(param_1 + 100)) + 0x1a0))();
      fStack_60 = ABS(*pfVar5 - *(float *)(param_1 + 0x40));
      fStack_5c = ABS(pfVar5[1] - *(float *)(param_1 + 0x44));
      fStack_58 = ABS(pfVar5[2] - *(float *)(param_1 + 0x48));
      fStack_54 = ABS(pfVar5[3] - *(float *)(param_1 + 0x4c));
      if ((DAT_00a0f708 < fStack_58 || DAT_00a0f708 < fStack_5c) || DAT_00a0f708 < fStack_60)
      goto LAB_005cef56;
      *(undefined1 *)(param_1 + 0x60) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x60) = 0;
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
LAB_005cef56:
  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                               *(int *)(param_1 + 100)) + 0x19c))();
  if ((((*(char *)(*(int *)(iVar4 + 8) + 0x40) == '\0') || (*(int *)(*(int *)(iVar4 + 8) + 8) == 0))
      && (iVar4 = *(int *)(param_1 + 100), *(float *)(iVar4 + 0x120) == 0.0)) &&
     ((*(char *)(iVar4 + 0x304) != '\0' ||
      ((*(int *)(iVar4 + 0x250) != 0 && (*(float *)(*(int *)(iVar4 + 0x250) + 0x614) != 0.0)))))) {
    pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))
                                ();
    fStack_60 = ABS(*(float *)(param_1 + 0x50) - *pfVar5);
    fStack_5c = ABS(*(float *)(param_1 + 0x54) - pfVar5[1]);
    fStack_58 = ABS(*(float *)(param_1 + 0x58) - pfVar5[2]);
    fStack_54 = ABS(*(float *)(param_1 + 0x5c) - pfVar5[3]);
    if ((fStack_58 <= DAT_00a10e78 && fStack_5c <= DAT_00a10e78) && fStack_60 <= DAT_00a10e78) {
      pfVar5 = (float *)FUN_004c3ac0();
      fStack_60 = ABS(*(float *)(param_1 + 0x50) - *pfVar5);
      fStack_5c = ABS(*(float *)(param_1 + 0x54) - pfVar5[1]);
      fStack_58 = ABS(*(float *)(param_1 + 0x58) - pfVar5[2]);
      fStack_54 = ABS(*(float *)(param_1 + 0x5c) - pfVar5[3]);
      if ((g_flOne < fStack_58 || g_flOne < fStack_5c) || g_flOne < fStack_60) {
        if (*(float *)(param_1 + 0x3c) == g_flZero) {
          *(float *)(param_1 + 0x3c) = fStack_64;
          return;
        }
        if (*(char *)(param_1 + 0x60) != '\0') {
          return;
        }
        if (fStack_64 - *(float *)(param_1 + 0x3c) <= DAT_00aaa68c) {
          return;
        }
        *(undefined1 *)(param_1 + 0x60) = 1;
        pfVar5 = (float *)FUN_004c3ac0();
        fStack_60 = *pfVar5;
        fStack_5c = pfVar5[1];
        fStack_58 = pfVar5[2];
        fStack_54 = pfVar5[3];
        piVar3 = *(int **)(*(int *)(param_1 + 100) + 0x250);
        if (piVar3 != (int *)0x0) {
          pfVar5 = (float *)(**(code **)(*piVar3 + 0x54))();
          fStack_60 = *pfVar5;
          fStack_5c = pfVar5[1];
          fStack_58 = pfVar5[2];
          fStack_54 = pfVar5[3];
        }
        pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4)
                                                + 4 + *(int *)(param_1 + 100)) + 0x1a0))();
        fStack_60 = fStack_60 - *pfVar5;
        fStack_5c = fStack_5c - pfVar5[1];
        fStack_58 = fStack_58 - pfVar5[2];
        fStack_54 = fStack_54 - pfVar5[3];
        pcVar6 = (char *)FUN_005d6870(&uStack_65);
        if (*pcVar6 != '\0') {
          fStack_64 = fStack_60 * fStack_60 + fStack_58 * fStack_58 + fStack_5c * fStack_5c;
          if (fStack_64 == 0.0) {
            fVar9 = 0.0;
          }
          else {
            fVar9 = g_flOne / SQRT(fStack_64);
            fStack_64 = fVar9;
          }
          fStack_58 = fStack_58 * fVar9;
          fStack_60 = fVar9 * fStack_60;
          fStack_5c = fStack_5c * fVar9;
          fStack_54 = fStack_54 * fVar9;
          uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                       *(int *)(param_1 + 100)) + 0x1a4))();
          FUN_005d1d20(&fStack_20,uVar7);
          fStack_64 = fStack_20 * fStack_60 + fStack_18 * fStack_58 + fStack_1c * fStack_5c;
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(undefined4 *)(iVar4 + 0xc) = 0;
          }
          uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(undefined4 *)(iVar4 + 0xc) = 0;
          }
          uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          pfVar5 = (float *)(param_1 + 0x40);
          fVar9 = (float)uVar1 * _DAT_009da8cc + DAT_00aaa688;
          *pfVar5 = (float)uVar2 * _DAT_009da8d0 + DAT_00aaa690;
          *(undefined4 *)(param_1 + 0x44) = 0;
          *(float *)(param_1 + 0x48) = fVar9;
          *(undefined4 *)(param_1 + 0x4c) = 0;
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(undefined4 *)(iVar4 + 0xc) = 0;
          }
          uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          fVar9 = DAT_00aaa668;
          if ((uVar1 & 1) != 0) {
            *pfVar5 = *pfVar5 * DAT_00aaa668;
          }
          if (g_flZero < fStack_64) {
            *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * fVar9;
          }
          puVar8 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x18) + 0x1a0))();
          uStack_40 = *puVar8;
          uStack_3c = puVar8[1];
          uStack_38 = puVar8[2];
          uStack_34 = puVar8[3];
          puVar8 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x18) + 0x1a4))();
          uStack_50 = *puVar8;
          uStack_4c = puVar8[1];
          uStack_48 = puVar8[2];
          uStack_44 = puVar8[3];
          FUN_004e8bf0(&uStack_40,&uStack_50,pfVar5,&fStack_30);
          *pfVar5 = fStack_30;
          *(undefined4 *)(param_1 + 0x44) = uStack_2c;
          *(undefined4 *)(param_1 + 0x48) = uStack_28;
          *(undefined4 *)(param_1 + 0x4c) = uStack_24;
          return;
        }
        *(undefined4 *)(param_1 + 0x40) = g_abInferredDefaultAimPos._0_4_;
        *(undefined4 *)(param_1 + 0x44) = g_abInferredDefaultAimPos._4_4_;
        *(undefined4 *)(param_1 + 0x48) = g_abInferredDefaultAimPos._8_4_;
        *(undefined4 *)(param_1 + 0x4c) = g_abInferredDefaultAimPos._12_4_;
        return;
      }
    }
  }
  if (*(char *)(param_1 + 0x60) != '\0') {
    return;
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}

```

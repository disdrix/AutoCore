# Raw capture: FUN_005d9ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d9ea0` |
| **Canonical name** | `FUN_005d9ea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall

FUN_005d9ea0(int param_1,undefined4 param_2,int *param_3,float *param_4,float param_5,

            undefined1 *param_6)



{

  undefined4 uVar1;

  bool bVar2;

  int *piVar3;

  char cVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  undefined4 *puVar8;

  int *piVar9;

  int iVar10;

  int iVar11;

  int local_4;

  

  local_4 = 0;

  piVar5 = (int *)param_3[3];

  piVar9 = param_3;

  while (piVar3 = piVar5, piVar3 != (int *)0x0) {

    piVar9 = piVar3;

    piVar5 = (int *)piVar3[3];

  }

  iVar11 = piVar9[8];

  iVar6 = 0;

  if (0 < *(int *)(iVar11 + 0x34)) {

    piVar9 = *(int **)(iVar11 + 0x30);

    do {

      if (*piVar9 == 1) {

        piVar9 = (int *)(*(int **)(iVar11 + 0x30))[iVar6 * 2 + 1];

        if ((piVar9 != (int *)0x0) && (((uint)piVar9[0x5f] >> 5 & 1) != 0)) {

          local_4 = (**(code **)(*piVar9 + 0x1c8))();

        }

        break;

      }

      iVar6 = iVar6 + 1;

      piVar9 = piVar9 + 2;

    } while (iVar6 < *(int *)(iVar11 + 0x34));

  }

  iVar6 = *(int *)(iVar11 + 0x34);

  iVar7 = 0;

  if (0 < iVar6) {

    piVar9 = *(int **)(iVar11 + 0x30);

    do {

      if (*piVar9 == 3) {

        iVar7 = (*(int **)(iVar11 + 0x30))[iVar7 * 2 + 1];

        goto LAB_005d9f38;

      }

      iVar7 = iVar7 + 1;

      piVar9 = piVar9 + 2;

    } while (iVar7 < iVar6);

  }

  iVar7 = 0;

LAB_005d9f38:

  iVar10 = 0;

  if (0 < iVar6) {

    piVar9 = *(int **)(iVar11 + 0x30);

    do {

      if (*piVar9 == 4) {

        iVar11 = (*(int **)(iVar11 + 0x30))[iVar10 * 2 + 1];

        goto LAB_005d9f58;

      }

      iVar10 = iVar10 + 1;

      piVar9 = piVar9 + 2;

    } while (iVar10 < iVar6);

  }

  iVar11 = 0;

LAB_005d9f58:

  cVar4 = param_5._0_1_;

  bVar2 = false;

  if (*(int *)(param_1 + 0xc) != *param_3) {

    if (param_5._0_1_ != '\0') {

      param_5 = ABS(*param_4);

      if (_DAT_00af4364 < param_5) {

        FUN_005d90a0(param_2,&param_5,iVar7,iVar11);

      }

      bVar2 = true;

    }

    *(int *)(param_1 + 0xc) = *param_3;

  }

  if ((local_4 != 0) &&

     (*(int *)(*(int *)(*(int *)(*(int *)(local_4 + 4) + 4) + 0xac + local_4) + 0x38) == 3)) {

    puVar8 = (undefined4 *)FUN_0040afb0(&param_5,3);

    uVar1 = *puVar8;

    puVar8 = (undefined4 *)FUN_0040afb0(&param_5,4);

    if (cVar4 != '\0') {

      param_5 = ABS(*param_4);

      if (_DAT_00af4364 < param_5) {

        if (!bVar2) {

          FUN_005d90a0(param_2,&param_5,uVar1,*puVar8);

        }

        FUN_005d9af0(param_2,uVar1,*param_4,*(int *)(*(int *)(local_4 + 4) + 4) + 4 + local_4,0);

        *param_6 = 1;

      }

      *(int *)(param_1 + 0xc) = *param_3;

    }

  }

  return;

}
```


---

## Live re-seal append — 2026-07-29 W25-K dual A/B

| Field | Value |
|---|---|
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` |
| **Excluded** | `disassemble_bytes`; Launcher; parent ledgers |
| **Live decompile** | Matches raw 2026-07-23 CF (no drift); ABI refined from epilogue + Contact call sites |
| **Body** | `0x005d9ea0`–`0x005da093` (**500** bytes exclusive end `0x005da094`) |
| **Epilog** | `POP EDI/ESI/EBP/EBX; ADD ESP,0xC; RET 0x14` (`5F 5E 5D 5B 83 C4 0C C2 14 00`) |
| **ABI** | **ECX** = CollisionListener* `this` (`+0xc` last-body cache); **5 stack formals**; void; **RET 0x14** |
| **Stack formals** | (0) ctx, (1) body*, (2) impact float*, (3) enable byte, (4) outPlayed* |
| **Caller (1)** | `Drive_CollisionListener_Contact` / `FUN_005da0a0` — **two** sites `0x005da4d8` / `0x005da4f3` (body A then body B) |
| **Callees** | `FUN_005d90a0` (`PlayCollisionSound`), `FUN_0040afb0` ×2 (material lookup keys 3/4), `FUN_005d9af0` (`PlayCollisionEffect`, **allowCreate=0**) |
| **Threshold** | `_DAT_00af4364` @ `0x00af4364` = **1.0f** — sound/FX only if `ABS(*impact) > 1.0` |
| **Role** | Per-body contact prep: walk body parent chain → host pair-list materials → optional sound + type-3 GO collision FX; set out flag |
| **Canonical name** | `Drive_CollisionListener_PrepBodyContact` (**Inferred**; no product string on this VA; sibling strings on Contact / PlayCollisionSound / PlayCollisionEffect) |
| **Decompile residual** | Meta shows `undefined FUN_005d9ea0(void)`; Contact call display may drop one formal — **bytes seal RET 0x14** (5 stack args) |

### Body hex (`read_memory` 500 B)

```
83ec0c538b5c241855894c240c8b4b0c85c95657c7442418000000008bc374098bc18b480c85c975f78b68208b4d3433c085c97e408b75308bd68d9b00000000833a01740c83c00183c2083bc17cf1eb248b44c60485c0741c8b887c010000c1e905f6c101740e8b108bc8ff92c8010000894424188b4d3433c085c97e188b75308bd6833a030f845701000083c00183c2083bc17ced33c033d285c97e188b7d308bf7833e040f844001000083c20183c6083bd17ced33d28b4c24148b490c3b0b8a5c242c8b7c2420c644241300744f84db743e8b4c2428d901d9e1d95c242cd9056443af00d944242cdff1ddd8761df30f1044242c8b4c241452508d5424345257f30f1144243ce8f3f0ffffc6442413018b4424248b088b542414894a0c8b44241885c00f84ae0000008b48048b51048b8402ac000000837838030f85970000006a038d4c2430518bcde8c00fe3ff8b306a048d542430528bcde8b00fe3ff84db8b0074738b5c2428d903d9e1d95c242cd9056443af00d944242cdff1ddd8764a807c241300751df30f1044242c8b4c241450568d4424345057f30f1144243ce85af0ffff8b4424188b48048b51048b4c24146a008d440204508b03505657e88bfaffff8b4c2430c601018b5424248b028b4c241489410c5f5e5d5b83c40cc214008b44c604e9acfeffff8b54d704e9c3feff
```

### Control-flow stages (sealed)

1. Walk `body` parent chain via `[3]` links → root; host = root`[8]`.
2. Scan host pair-list (`host+0x30` / count `+0x34`) for **type==1**: if object non-null and bit5 of `obj+0x17c` (`obj[0x5f]>>5&1`), call **vtbl+0x1C8** → `local_go`.
3. Scan same list for **type==3** → material id A (`iVar7`); **type==4** → material id B (`iVar11`); miss → 0.
4. Snapshot enable byte; clear local “sound-done” flag.
5. If `this+0xc != *body` (new body vs cache):
   - if enable: `abs = ABS(*impact)`; if `abs > 1.0f` → `PlayCollisionSound(ctx, &abs, mat3, mat4)`.
   - set sound-done; **always** write `this+0xc = *body`.
6. If `local_go != 0` and nested type at `go` chain `+0xac` slot `+0x38 == 3`:
   - `FUN_0040afb0(&scratch, 3)` / `(…, 4)` material pack.
   - if enable and `ABS(*impact) > 1.0f`:
     - if !sound-done → sound with packed materials.
     - `PlayCollisionEffect(listener=this implied, ctx, matA, *impact, go, allowCreate=0)`.
     - `*outPlayed = 1`.
   - if enable path entered: refresh `this+0xc = *body`.

### Contact call-site contract (bytes)

Both sites push **5** stack args then `CALL` with **ECX=listener**:

```
PrepBodyContact(listener, ctx, bodySide, impact, enable, &outFlag)
// body A then body B; out flags start 0 (cStack_18d / cStack_19d)
```

`enable` comes from Contact rate/material gate (`iStack_194` low byte / sibling).  
`PlayCollisionEffect` allowCreate polarity from this unit: **0** (no lazy FxMaster); Contact later may call with **1**.

### Globals

| VA | Bytes | Role |
|---|---|---|
| `0x00af4364` | `00 00 80 3F` | **1.0f** impact magnitude gate |

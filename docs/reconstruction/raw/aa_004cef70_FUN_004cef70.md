# Raw capture: FUN_004cef70

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cef70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cef70` |
| **Canonical name** | `FUN_004cef70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 FUN_004cef70(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uStack_8;
  
  piVar1 = param_1;
  iVar2 = (**(code **)(*param_1 + 0x27c))();
  uStack_8 = 0;
  if (param_2 != (int *)0x0) {
    iVar3 = (**(code **)(*param_2 + 0x1d4))();
    if (iVar3 != 0) {
      uStack_8 = 1;
    }
  }
  (**(code **)(*param_1 + 0x1d4))();
  iVar3 = (**(code **)(*param_1 + 0x214))();
  if (iVar3 == 0) {
    param_1 = (int *)((float)iVar2 * g_flMsToSeconds_Inferred * DAT_00a0f704 +
                     g_flKillSpreeBonusPerStack);
  }
  else {
    (**(code **)(*param_1 + 0x214))();
    fVar4 = (float10)FUN_004c4dd0();
    param_1 = (int *)(float)fVar4;
  }
  iVar2 = (**(code **)(*piVar1 + 0x214))();
  if (iVar2 != 0) {
    uVar5 = 1;
    (**(code **)(*piVar1 + 0x214))(1);
    fVar4 = (float10)FUN_004c3140(uVar5);
    param_1 = (int *)(float)(fVar4 + (float10)(float)param_1);
  }
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x214))();
    if (iVar2 != 0) {
      (**(code **)(*param_2 + 0x214))(uStack_8);
      fVar4 = (float10)FUN_004c3120(uStack_8);
      param_1 = (int *)(float)((float10)(float)param_1 - fVar4);
    }
  }
  if ((float)param_1 < 0.0) {
    param_1 = (int *)g_flKillSpreeBonusPerStack;
  }
  return (float10)(float)param_1;
}
```

---

## Live re-seal (W22-A dual, 2026-07-29)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `read_memory` |
| **Body range** | `0x004cef70`–`0x004cf07c` (268 B) |
| **Classification** | worker |
| **Xrefs (2)** | `0x004cf0bf` (`FUN_004cf080` / Combat_RollCritMultiplier), `0x00839a01` (`FUN_00838e20` UI path) |
| **Callees** | `FUN_004c4dd0`, `FUN_004c3140`, `FUN_004c3120` (+ vtbl) |
| **Live decompile** | ≡ 2026-07-23 raw body |

### Machine ABI (bytes)

Prologue: `83 ec 08` (sub esp,8); args `Stack[0x4]`/`Stack[0x8]` → ESI/EDI; epilogue `83 c4 08` / `c3` (plain **RET**, **cdecl**).

Return: **ST0** float (`fld` of stack slot before RET).

### Sealed constants (`read_memory`)

| Symbol | VA | LE bytes | float |
|---|---|---|---|
| `g_flMsToSeconds_Inferred` | `0x00a0f72c` | `6f 12 83 3a` | **0.001** |
| `DAT_00a0f704` | `0x00a0f704` | `00 00 80 3e` | **0.25** |
| `g_flKillSpreeBonusPerStack` | `0x009cbf80` | `cd cc 4c 3d` | **0.05** (name is XP-domain; reused float) |

Fallback formula path (no skill binding at `vtbl+0x214`):

```
chance = (float)level * 0.001 * 0.25 + 0.05
       = level * 0.00025 + 0.05
```

Bytes: `mulss [0xa0f72c]; mulss [0xa0f704]; addss [0x9cbf80]`.

### Control-flow contract (sealed)

```
level = attacker->vtbl[+0x27c]()                    // int (same slot as crit mult level)
flagT = 0
if target != null:
  if target->vtbl[+0x1d4]() != 0: flagT = 1
attacker->vtbl[+0x1d4]()                            // call; result unused in decompile
bindA = attacker->vtbl[+0x214]()
if bindA == 0:
  chance = level * 0.001 * 0.25 + 0.05
else:
  chance = FUN_004c4dd0(attacker->vtbl[+0x214]())   // skill-table chance
if attacker->vtbl[+0x214]() != 0:
  chance += FUN_004c3140(bindA_or_obj, 1)           // attacker bonus: +0x1dc (flag) / +0x1d8
if target != null && target->vtbl[+0x214]() != 0:
  chance -= FUN_004c3120(bindT, flagT)              // target resist: +0x1e4 / +0x1e0
if chance < 0.0: chance = 0.05
return chance   // ST0; used as 0..1-ish by 004cf080 *100 vs roll%100
```

Callee helpers (context only, not owned):
- `FUN_004c3140(this, char)` → float at `this+0x1dc` if char else `this+0x1d8`
- `FUN_004c3120(this, char)` → float at `this+0x1e4` if char else `this+0x1e0`
- `FUN_004c4dd0(bind)` → skill-derived chance when binding present

### Body hex (full 268 B)

```
83ec08568b7424108b06578bceff907c02000089442414db442414d95c240c8b7c241885ffc64424080074138b178bcfff92d401000085c07405c6442408018b068bceff90d40100008b168bceff921402000085c074178b068bceff90140200008bc8e8f85dffffd95c2414eb24f30f1044240cf30f59052cf7a000f30f590504f7a000f30f580580bf9c00f30f114424148b168bceff921402000085c0741b8b066a018bceff90140200008bc8e81d41ffffd8442414d95c241485ff742c8b178bcfff921402000085c0741e8b4424088b17508bcfff92140200008bc8e8cd40ffffd86c2414d95c24140f57c00f2f4424145f5e760ef30f100580bf9c00f30f1144240cd944240c83c408c3
```

Canonical structural name: **`Combat_ComputeCritChance_Inferred`**.

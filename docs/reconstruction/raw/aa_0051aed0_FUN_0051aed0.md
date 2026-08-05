# Raw capture: FUN_0051aed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051aed0` |
| **Canonical name** | `FUN_0051aed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0051aed0(int *param_1,char param_2,char param_3)



{

  short sVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint uVar5;

  void *pvVar6;

  char *pcVar7;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  iVar2 = (**(code **)(*param_1 + 0x1cc))();

  if (iVar2 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0xfc))();

  }

  if ((param_3 == '\0') && (*(int *)(param_1[0x2a] + 0x38) != 4)) {

    switch(*(int *)(param_1[0x2a] + 0x38)) {

    default:

      iVar3 = (**(code **)(*param_1 + 0x60))();

      if (iVar3 == 0) {

        pcVar7 = "generic_pickup";

      }

      else {

        pcVar7 = "generic_pickup_enhanced";

      }

      break;

    case 8:

      pcVar7 = "generic_pickup_gadget";

      break;

    case 0x1a:

      pcVar7 = "generic_pickup_commidity";

      break;

    case 0x32:

      pcVar7 = "generic_pickup_tinkering_kit";

      break;

    case 0x42:

      pcVar7 = "generic_pickup_money";

    }

    pvVar4 = NDSpecialFX_LoadFromScriptName(pcVar7,4,0);

    if (*(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4) != 0x10) goto LAB_0051afbb;

    pcVar7 = "generic_pickup_trick_material";

  }

  else {

    pcVar7 = "generic_pickup_quest";

  }

  pvVar4 = NDSpecialFX_LoadFromScriptName(pcVar7,4,0);

LAB_0051afbb:

  sVar1 = *(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4b8);

  pvVar6 = (void *)0x0;

  if (1 < sVar1) {

    switch(sVar1) {

    default:

      pcVar7 = "generic_pickup_rare";

      break;

    case 3:

      pcVar7 = "generic_pickup_ultra_rare";

      break;

    case 4:

      pcVar7 = "generic_pickup_artifact";

      break;

    case 5:

      pcVar7 = "generic_pickup_xeno_artifact";

    }

    pvVar6 = NDSpecialFX_LoadFromScriptName(pcVar7,4,0);

  }

  if (pvVar4 != (void *)0x0) {

    if (pvVar6 != (void *)0x0) {

      FUN_004b8dc0(1,0);

      (**(code **)(*param_1 + 0xf8))(pvVar6,1,0);

    }

    FUN_004b8dc0(1,0);

    (**(code **)(*param_1 + 0xf8))(pvVar4,1,0);

    iVar3 = Client_GetMissionCompleteAudioTable();

    if ((*(char *)(iVar3 + 600) != '\0') && (param_2 != '\0')) {

      FUN_004b7e50(0,0,0,0,0,0);

    }

  }

  if (((*(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4) == 8) && (iVar2 != 0)) &&

     (*(int *)(iVar2 + 8) != 0)) {

    iVar2 = param_1[0x32];

    fStack_10 = 0.0;

    fStack_c = 0.0;

    fStack_8 = 0.0;

    fStack_4 = g_flOne;

    if (iVar2 < 0) {

      iVar2 = 0;

    }

    uVar5 = FUN_00519d20(iVar2);

    fStack_10 = (float)(uVar5 >> 0x10 & 0xff) * DAT_00aaa7a8;

    fStack_c = (float)(uVar5 >> 8 & 0xff) * DAT_00aaa7a8;

    fStack_8 = (float)(uVar5 & 0xff) * DAT_00aaa7a8;

    fStack_4 = g_flOne;

    FUN_009700f0("MatAmbient",&fStack_10);

    FUN_009700f0("MatDiffuse",&fStack_10);

    FUN_009700f0("MatEmissive",&fStack_10);

    FUN_0096f660();

  }

  return;

}
```

---

## v2026-07-29 W25-J re-decompile + bytes (append)

**Agent:** OWN-ONLY dual W25-J  
**Tools:** Ghidra MCP `decompile_function` `0x0051aed0`; `get_function_by_address`; `get_function_xrefs`; `read_memory` entry/tail + float `0x00aaa7a8`. No `disassemble_bytes`.

**Body range:** `0x0051aed0`–`0x0051b1b9`  
**ABI:** `__thiscall` (ECX=this → EBX); stack `char bPlayAudio`, `char bForceQuestFx`; **`ret 8`** (`C2 08 00`).

**Live decompile CF:** identical to authoritative raw body above (pickup script name switch → rarity overlay → activate/attach FX → optional audio → optional paint material recolor).

**Entry bytes (64):**
```
83ec105355568bd98b0357ff90cc0100008be885ed74148b4d048b51048b442a048d4c2a04ff90fc000000807c2428000f85a20000008b8ba80000008b413883
```

**Tail bytes:**
```
5f5e5d5b83c410c20800
```
Decode: pop edi/esi/ebp/ebx; `add esp,0x10`; **`ret 8`**.

**Float `DAT_00aaa7a8` @ `0x00aaa7a8`:** `81 80 80 3b` → **≈1/255** (byte→unit RGB scale). **High**.

**Xrefs (call):**
| Site | Function |
|------|----------|
| `0x005c69aa` | `CLoadNode__initSelection` / `FUN_005c6960` — `(1, 0)` |
| `0x00585fe1` | `FUN_00585e00` — `(distNear, flagFrom_00516c40)` |

**Canonical rename (W25-J):** `Object_PlayPickupSpecialFX` (script-name domain **High**; product C++ method English **Open**).

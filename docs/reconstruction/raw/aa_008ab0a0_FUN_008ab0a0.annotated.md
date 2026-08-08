# Annotated low-level: FUN_008ab0a0 → Client_NpcMissionDialog_InitRuntimeFields_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008ab0a0` |
| VA | `0x008ab0a0`–`0x008ab33d` (670 B / `0x29E`) |
| System | `missions-progression` |
| Date | 2026-08-05 (R11-035 dual) |
| Canonical (inferred) | `Client_NpcMissionDialog_InitRuntimeFields_Inferred` |
| Ghidra | `FUN_008ab0a0` |
| Parent | `Client_NpcMissionDialogHost_Ctor_Inferred` (`0x008ac3f0`) |
| Classification | leaf |
| Terminal | false |

---

## Machine-level notes

- **ABI:** ECX = `NpcMissionDialogHost*`; no stack formals; plain `RET`.
- **Leaf:** no CALL; only stores + SSE loads of float constants.
- **Role:** mid-ctor field pack — zeros widget/chrome pointers, writes `−1` into TFID/id slots (response bank + reward bank), installs three default float4s, clears turn-in byte `+0x64c`.
- **Call order in parent ctor:** base `FUN_0087b890` → vtbl install / early fields → **this** → `NDUIWindow_ReloadInterface("i_d_npc.xml")` → `UI_MissionDialog_BuildResponseButtons_Inferred` → vtbl+0x34C.
- **Also published** at mission-dialog vtbl `0x00a4a51c` + **0x3AC** (`DAT` @ `0x00a4a8c8`).
- Prefer assembly when decompiler shows `void` return / empty prototype — body is pure stores.

## Pseudocode (annotated)

```c
// thiscall: ECX = NpcMissionDialogHost* host
void Client_NpcMissionDialog_InitRuntimeFields_Inferred(NpcMissionDialogHost *host)
{
  // --- zero scalar / chrome / list widget pointers ---
  host->field_4b4 = 0;   // +0x4b4
  host->field_4b8 = 0;   // +0x4b8
  host->field_4bc = 0;   // +0x4bc
  host->field_504 = 0;   // +0x504
  host->field_508 = 0;   // +0x508
  // +0x680..+0x700: title/list/chrome widget ptrs (zero pack)
  host->w_680 = host->w_684 = host->w_688 = host->w_68c = 0;
  host->w_690 = host->w_694 = 0;
  host->w_6d8 = host->w_6dc = host->w_6e0 = 0;
  host->w_6e4 = host->w_6e8 = host->w_6ec = 0;
  host->w_6f0 = host->w_6f4 = host->w_6f8 = host->w_6fc = 0;
  host->w_700 = 0;
  host->field_644 = 0;   // +0x644
  host->chromeMode_510 = 0; // +0x510 (panel chrome mode; later ApplyPanelMode)

  // --- 4× reward/chrome id banks: TFID pairs = -1; related ptrs = 0 ---
  // slots i=0..3 at +0x558+i*8 / +0x698+i*4 / +0x6a8+i*4 / +0x6b8+i*4 / +0x6c8+i*4
  for (int i = 0; i < 4; ++i) {
    *(int *)((char *)host + 0x558 + i * 8) = -1;
    *(int *)((char *)host + 0x55c + i * 8) = -1;
    *(int *)((char *)host + 0x698 + i * 4) = 0; // chrome grid column (ApplyPanelMode hide bank)
    *(int *)((char *)host + 0x6a8 + i * 4) = 0;
    *(int *)((char *)host + 0x6b8 + i * 4) = 0;
    *(int *)((char *)host + 0x6c8 + i * 4) = 0;
  }

  // --- 8× response button TFID pairs + widget slots (pre-BuildResponseButtons) ---
  // same banks as MissionDialog_ClearResponseButtonSlots_Inferred (+0x518 / +0x708)
  for (int i = 0; i < 8; ++i) {
    *(int *)((char *)host + 0x518 + i * 8) = -1;
    *(int *)((char *)host + 0x51c + i * 8) = -1;
    *(int *)((char *)host + 0x708 + i * 4) = 0;
  }
  *(int *)((char *)host + 0x578) = -1;
  *(int *)((char *)host + 0x57c) = -1;

  // --- three float4 defaults (SSE; constants from image) ---
  // +0x594 = (0, 0, 0, 0.6f)     DAT_00a0f71c
  // +0x584 = (0, 1.0f, 0, 0.157f) g_flOne + DAT_00aaa7e8
  // +0x5a4 = (0, 1.0f, 0, 0.549f) g_flOne + DAT_00aaa7e4
  float *q594 = (float *)((char *)host + 0x594);
  q594[0] = 0.f; q594[1] = 0.f; q594[2] = 0.f; q594[3] = 0.6f;
  float *q584 = (float *)((char *)host + 0x584);
  q584[0] = 0.f; q584[1] = 1.f; q584[2] = 0.f; q584[3] = 0.157f;
  float *q5a4 = (float *)((char *)host + 0x5a4);
  q5a4[0] = 0.f; q5a4[1] = 1.f; q5a4[2] = 0.f; q5a4[3] = 0.549f;

  // turn-in / deliver mode flag (NAMING_REGISTRY dialogTurnInMode)
  *(unsigned char *)((char *)host + 0x64c) = 0;
}
```

## Cross-links

| Related unit | VA | Relation |
|---|---|---|
| `Client_NpcMissionDialogHost_Ctor_Inferred` | `0x008ac3f0` | sole CALL site |
| `MissionDialog_ClearResponseButtonSlots_Inferred` | `0x008aa560` | same +0x518/+0x708 banks (destroy path) |
| `UI_MissionDialog_BuildResponseButtons_Inferred` | `0x008ac110` | runs after this in ctor |
| `Client_NpcMissionDialog_ApplyPanelMode_Inferred` | `0x008ab550` | uses +0x510/+0x648/+0x698.. chrome |

## Open questions

- Product name for vtbl+0x3AC method.
- Float4 bank English (color channels vs layout scales).
- Runtime confirmation of turn-in clear interaction with `FUN_008aa760`.

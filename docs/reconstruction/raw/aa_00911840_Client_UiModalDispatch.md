# Raw capture: Client_UiModalDispatch (abandon modal slice)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911840` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00911840` |
| **Canonical name** | `Client_UiModalDispatch` |
| **Ghidra / prior name** | `FUN_00911840` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-29` (abandon slice extract; full-function body previously `2026-07-23`) |
| **Tool** | Ghidra MCP `batch_decompile` / prior full raw |
| **Integrity** | Full-function raw also at `aa_00911840_FUN_00911840.md`. This file is the **abandon-focused** raw section (cases `0x4e46` / `0x4e47`). Do not invent case bodies; append versioned sections only. |

---

## Function identity

Large UI modal / dialog-result switch (`switch(param_3)`). Modal type codes in the `0x4e2x–0x4e5x` range; action discriminator `param_2 == 8` is the common “confirm / primary” gate for many cases.

**Abandon chain ownership (this unit):** cases **`0x4e46`** (Yes → C2S FailMission `0x20B2`) and **`0x4e47`** (No / dismiss → close only).

Upstream: `Client_MissionDialogHandleButton` (`0x008ae7c0`) state **2** stashes mission id in `DAT_00d1b4b4` and posts the abandon confirm modal via `Client_ShowModalPrompt` with **EAX=`0x4e46` (Yes)** + stack secondary **`0x4e47` (No)** (UF-009). Decompiler often shows only `FUN_007fdfb0(..., 0x4e47, 1, 0)`.

---

## Upstream abandon arm (HandleButton, for context — not this function)

From `aa_008ae7c0` raw (state 2):

```c
if (iVar5 == 2) {
  /* State 2: Show abandon mission confirmation dialog */
  if (pDialogContext == (int *)0x1) {
    if (*(undefined4 **)(in_EAX + 0x670) == (undefined4 *)0x0) {
      DAT_00d1b4b4 = 0xffffffff;
    }
    else {
      DAT_00d1b4b4 = **(undefined4 **)(in_EAX + 0x670);
    }
    /* ... format "Are you sure you wish to abandon \"%s\"?" ... */
    FUN_007fdfb0(&DAT_00d1a840,acStack_200,0x4e47,1,0);
    return '\0';
  }
}
```

---

## Raw pseudocode — abandon cases only (authoritative excerpt)

Captured from full decompile of `FUN_00911840` / `0x00911840`. Local names match the full-function decompile.

```c
/* Function prologue relevant to abandon path: mission id key snapshotted at entry */
key = DAT_00d1b4b4;
/* ... SEH / ExceptionList setup ... */
switch(param_3) {
  /* ... many unrelated modal cases ... */

  case 0x4e45:
  case 0x4e47:          /* abandon modal No / cancel (also shared with other modal codes) */
  case 0x4e4b:
  case 0x4e4d:
  case 0x4e4f:
  case 0x4e52:
  case 0x4e53:
  case 0x4e55:
  case 0x4e57:
  case 0x4e59:
  case 0x4e5b:
    ppvVar1 = &pvStack_c;
    if (param_2 == 8) {
      ExceptionList = &pvStack_c;
      FUN_007fc360();          /* close modal only — no sector packet */
      goto LAB_00911a99;
    }
    break;

  case 0x4e46:                 /* abandon modal Yes / confirm */
    ppvVar1 = &pvStack_c;
    if (param_2 == 8) {
      ExceptionList = &pvStack_c;
      if ((DAT_00d1b4b4 != 0xffffffff) && (ExceptionList = &pvStack_c, DAT_00d1b6d8 != 0)) {
        ExceptionList = &pvStack_c;
        puVar7 = (undefined4 *)FUN_0053fff0();   /* mission definition table root */
        if (((void *)*puVar7 != (void *)0x0) &&
           (piVar8 = CNDHash_LookupByKey((void *)*puVar7,key), piVar8 != (int *)0x0)) {
          apiStack_460[0] = (int *)0x20b2;       /* OPCODE FailMission C2S */
          iVar9 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);
          uStack_458 = *(undefined4 *)(iVar9 + 0x164 + DAT_00d1b6d8);  /* CharacterCoid lo */
          uStack_454 = *(undefined4 *)(iVar9 + 0x168 + DAT_00d1b6d8);  /* CharacterCoid hi */
          uStack_450 = *piVar8;                  /* MissionId from def node */
          Client_SendSectorPacket(&DAT_00d1a840,0x18,apiStack_460);
          if ((DAT_00d1b898 != (int *)0x0) &&
             (cVar2 = (**(code **)(*DAT_00d1b898 + 0x3d8))(), cVar2 != '\0')) {
            FUN_007fca10();
            FUN_007fef20(0x13,1,0);             /* optional mission UI refresh */
            param_1 = local_468;
          }
        }
      }
      FUN_007fc360();                            /* always close modal after confirm arm */
      goto LAB_00911a99;
    }
    break;

  /* ... remaining modal cases ... */
}
```

---

## Packet layout built at case `0x4e46` (size `0x18`)

| Buffer offset | Source | Field |
|---:|---|---|
| `+0x00` | literal `0x20B2` | Opcode FailMission |
| `+0x04` | stack pad (`apiStack_460[1]`) | pad4 |
| `+0x08` | char base `+0x164` via `DAT_00d1b6d8` dual-base | CharacterCoid lo |
| `+0x0C` | char base `+0x168` | CharacterCoid hi |
| `+0x10` | `*piVar8` (mission def hash payload) | MissionId |
| `+0x14` | stack pad | pad4 |

Matches AutoCore `FailMissionPacket` (`src/AutoCore.Game/Packets/Sector/FailMissionPacket.cs`).

---

## Modal code pairing — residual **SEALED High** (UF-009 + dual A/B)

| Code | Role (abandon chain) | Confidence |
|---:|---|---|
| `0x4e46` | **Yes** — open EAX → host `+0x498`; case body = **send `0x20B2` then close** | **High** |
| `0x4e47` | **No** — open stack secondary → host `+0x49c`; case body = **close only** (shared dismiss family) | **High** |

**Supersedes earlier “Probable Yes/No residual” wording.** Pairing sealed via open-site `MOV EAX,0x4e46` + `PUSH 0x4e47` + dual-id store in `FUN_007fdfb0` + these dispatch cases. Do not treat decompiler-only third arg `0x4e47` as the Yes id.

---

## Downstream after C2S `0x20B2`

Server processes abandon / fail → S2C same opcode `0x20B2` → `Client_PacketDispatch` case `0x20b2` → `Client_RecvFailMission` (`0x0080b100`) → `CVOGReaction_FailMission` (`0x0052da30`).

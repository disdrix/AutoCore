# Annotated low-level: Client_Skill_ResolveCastTarget

| Field | Value |
|---|---|
| Stable ID | `aa_0093b3a0` |
| VA | `0x0093b3a0` |
| System | skills-abilities |
| Date | 2026-07-23 |
| Residual close | **2026-07-29** (dual residual + hardpoint plate; scratch `reviews/a_0093b3a0.md`) |

## Machine-level notes

- Source: raw capture for `aa_0093b3a0`.
- Prefer assembly when decompiler conflicts.
- **2026-07-29 dual residual:**
  - `FUN_004f8b80` → `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` (sole caller this unit; live decompile renamed).
  - outFlags bits **4 / 8 / 0x10** written only by `Skill_FilterTargetForResolveList_Inferred` (`0x0054ff00`) inside ResolveTargetList.
  - decomp `pA` / clean `unaffReg` = **`local_750` / `activeBindScratch`** (Lookup out). Asm: `LEA [ESP+0x34]` → push → Lookup → `PUSH EAX` → `TFID_NotEquals`. Sibling `Client_RecvSkillStatusEffect` recovers the same pattern as `&local_220`.
  - Sticky success path does **not** copy binding TFID into out: `JNZ write_seed` uses EDI/EBP/EBX set from **listOut** after ResolveTargetList (invalid at this gate). Silent invalid out; suppresses "Can't find a target!".
  - **Hardpoint plate (Confirmed):** on bit4 + `skill+0x614&8` (after related `&2` failed): `ECX = *(char+0x250)` @ `0x0093b576`; `CALL 0x004f8b80`; reload EDI/EBP/EBX from `*EAX`; `TFID_EqualsObjectId` vs `0x00a15870` @ `0x00404aa0`; `JZ write_seed` when not-equal. Empty helper returns `&DAT_009cd0f8` — content ≡ invalid (`read_memory` both 16B `ff…ff 00…00`). Fail UX `"No enemies found."` @ `0x00a2e04c`.

## write_seed register plate (asm Confirmed)

| Out dword | Register / slot after list / related / hardpoint load |
|---|---|
| +0x0 | EDI |
| +0x4 | EBP |
| +0x8 | EBX |
| +0xc | `[ESP+0x24]` |

After `Skill_ResolveTargetList` @ `0x0093b483`: EDI/EBP/EBX/`[ESP+0x24]` ← listOut; also mirrored to `[ESP+0x18..0x20]` for equals checks.

Hardpoint reload @ `0x0093b581`–`0x0093b589` overwrites the same plate from the returned TFID pointer.

## outFlags consume map

| Bit | Producer | This unit |
|----:|---|---|
| 1 | ResolveTargetList no-target | clear → valid list / bind / toast; set → related or "Nothing is targeted." |
| 2 | range helper via ResolveTargetList | code **0xd** toast |
| 4 | FilterTargetForResolveList | related (`+0x614&2`) / hardpoint (`&8`) / code **0xe** |
| 8 | FilterTargetForResolveList | related / code **3** |
| 0x10 | FilterTargetForResolveList | not tested here |

## Pseudocode (annotated copy of raw)

```c
void Client_Skill_ResolveCastTarget
               (byte *param_1,int param_2,undefined4 *param_3,undefined4 param_4,char param_5)

{
  int in_EAX;
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pA;              /* = local_750 after Lookup; decomp unaffiliated */
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte *pB;
  void *local_76c;
  undefined4 local_764;
  undefined4 local_760;
  undefined4 local_75c;
  undefined4 local_758;
  uint local_754;
  undefined1 local_750 [16];  /* activeBindScratch — TFID_NotEquals first arg */
  char local_740 [256];
  undefined4 local_640;
  undefined4 local_63c;
  undefined4 local_638;
  undefined4 local_634;
  
  if (*(int *)(in_EAX + 0xe98) == 0) goto LAB_0093b7b6;
  FUN_007a69d0();
  local_758 = param_3[3];
  uVar4 = param_3[2];
  uVar5 = param_3[1];
  uVar6 = *param_3;
  if (*(int *)(param_2 + 0x614) == 1) goto LAB_0093b547;
  local_754 = 0;
  if (*(int *)(in_EAX + 0xe98) == 0) {
    local_76c = (void *)0x0;
  }
  else {
    local_76c = (void *)(*(int *)(in_EAX + 0xe98) + 4 +
                        *(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4));
  }
  if ((*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0') &&
     (iVar2 = *(int *)(in_EAX + 0xe98),
     *(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa4 + iVar2) != 0)) {
    local_76c = *(void **)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa4 + iVar2);
  }
  Skill_ResolveTargetList
            (&local_640,*(undefined4 *)(in_EAX + 0xe04),local_76c,*param_3,param_3[1],param_3[2],
             param_3[3],param_4,&local_754);
  local_758 = local_634;
  local_764 = local_640;
  local_760 = local_63c;
  local_75c = local_638;
  if ((local_754 & 2) == 0) {
    if ((local_754 & 4) != 0) {
      if ((*(uint *)(param_2 + 0x614) & 2) != 0) {
LAB_0093b511:
        iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                                     *(int *)(in_EAX + 0xe98)) + 0x19c))();
LAB_0093b52b:
        puVar3 = (undefined4 *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);
        local_758 = puVar3[3];
        uVar4 = puVar3[2];
        uVar5 = puVar3[1];
        uVar6 = *puVar3;
LAB_0093b547:
        *(undefined4 *)param_1 = uVar6;
        *(undefined4 *)(param_1 + 4) = uVar5;
        *(undefined4 *)(param_1 + 8) = uVar4;
        *(undefined4 *)(param_1 + 0xc) = local_758;
        return;
      }
      if ((*(uint *)(param_2 + 0x614) & 8) == 0) {
        if (param_5 != '\0') {
          pcVar1 = Skill_FormatFailureMessage(0xe,local_740,local_76c);
          if (DAT_00d1b8dc != 0) {
            FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,pcVar1,0);
          }
        }
        *(undefined4 *)param_1 = g_abTfidInvalid_A15870._0_4_;
        *(undefined4 *)(param_1 + 4) = g_abTfidInvalid_A15870._4_4_;
        *(undefined4 *)(param_1 + 8) = g_abTfidInvalid_A15870._8_4_;
        *(undefined4 *)(param_1 + 0xc) = g_abTfidInvalid_A15870._12_4_;
        return;
      }
      /* was FUN_004f8b80 */
      puVar3 = (undefined4 *)Vehicle_ResolveFirstHardpointOccupantTfid_Inferred();
      uVar6 = *puVar3;
      uVar5 = puVar3[1];
      uVar4 = puVar3[2];
      local_758 = puVar3[3];
      local_764 = uVar6;
      local_760 = uVar5;
      local_75c = uVar4;
      iVar2 = TFID_EqualsObjectId(&local_764,g_abTfidInvalid_A15870);
      if ((char)iVar2 == '\0') goto LAB_0093b547;
      if ((param_5 == '\0') || (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0'))
      goto LAB_0093b7b6;
      pcVar1 = "No enemies found.";
LAB_0093b793:
      pcVar1 = (char *)FUN_007a6de0(pcVar1,0xffffffff);
      goto LAB_0093b79c;
    }
    if ((local_754 & 8) != 0) {
      if ((*(byte *)(param_2 + 0x614) & 2) != 0) {
        iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                                     *(int *)(in_EAX + 0xe98)) + 0x19c))();
        goto LAB_0093b52b;
      }
      if (param_5 == '\0') goto LAB_0093b7b6;
      pcVar1 = Skill_FormatFailureMessage(3,local_740,local_76c);
      goto LAB_0093b79c;
    }
    if ((local_754 & 1) == 0) {
      iVar2 = TFID_EqualsObjectId(&local_764,g_abTfidInvalid_A15870);
      uVar4 = local_638;
      uVar5 = local_63c;
      uVar6 = local_640;
      if ((char)iVar2 == '\0') goto LAB_0093b547;
      if ((*(byte *)(param_2 + 0x615) & 2) != 0) {
        pB = g_abTfidInvalid_A15870;
        Skill_LookupActiveCastBinding(local_750,*(int *)(param_2 + 0x5fc));
        /* pA := local_750 (asm Confirmed) */
        iVar2 = TFID_NotEquals(local_750 /*pA*/,pB);
        /* binding present → write_seed with invalid listOut (silent) */
        if ((char)iVar2 != '\0') goto LAB_0093b547;
      }
      if (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0') goto LAB_0093b547;
      if (param_5 == '\0') goto LAB_0093b7b6;
      pcVar1 = "Can\'t find a target!";
      goto LAB_0093b793;
    }
    if ((*(byte *)(param_2 + 0x614) & 2) != 0) goto LAB_0093b511;
    if ((param_5 == '\0') || (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0'))
    goto LAB_0093b7b6;
    pcVar1 = (char *)FUN_007a6de0("Nothing is targeted.",0xffffffff);
    if (DAT_00d1b8dc == 0) goto LAB_0093b7b6;
    uVar6 = 6;
  }
  else {
    if ((param_5 == '\0') || (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0'))
    goto LAB_0093b7b6;
    pcVar1 = Skill_FormatFailureMessage(0xd,local_740,local_76c);
LAB_0093b79c:
    if (DAT_00d1b8dc == 0) goto LAB_0093b7b6;
    uVar6 = 0x18;
  }
  FUN_008f8200(DAT_00d1b8dc,uVar6,&DAT_00a156cc,pcVar1,0);
LAB_0093b7b6:
  *(undefined4 *)param_1 = g_abTfidInvalid_A15870._0_4_;
  *(undefined4 *)(param_1 + 4) = g_abTfidInvalid_A15870._4_4_;
  *(undefined4 *)(param_1 + 8) = g_abTfidInvalid_A15870._8_4_;
  *(undefined4 *)(param_1 + 0xc) = g_abTfidInvalid_A15870._12_4_;
  return;
}
```

## Open questions

- Runtime cast trace / binary diff (deferred).
- Secondary callers `FUN_00829190` / `FUN_00941d50`.
- Product English for every `skill+0x614/+0x615` bit (partially owned by filter dual).

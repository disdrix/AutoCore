# Annotated low-level: phyBone_unserialize

| Field | Value |
|---|---|
| Stable ID | `aa_0096e280` |
| VA | `0x0096e280` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096e280`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* phyBone::unserialize  (PBON / file tag NOBP = 0x50424f4e, chunk version 1)
   Source: C:\vog\1_code\palantir\palantir\physics\phyBone.cpp
   
   Reads the phyBone record (fields at ESI+0x148/+0x14c/+0x150/+0x154), then delegates to
   phyBoneSharedData_unserialize (FUN_00997540) for the NESTED TADB chunk that carries the
   model root transform (an hkQsTransform: rotation quaternion + translation [+ scale in v2]).
   
   That transform maps a model's raw .geo (TREV) vertices into its true (body-XOBB) frame.
   Web/tools parsers that ignore it render vehicle props on their side and tunnel doors sunk
   into the ground. See AutoCore-SCAR/docs/geo-format.md section "PBON". */

uint __fastcall phyBone_unserialize(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_ESI;
  uint local_24 [3];
  char local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b244e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope(param_1);
  local_4 = 0;
  if (local_14 == 0x50424f4e) {
    if (local_10 == 1) {
      if (*(int *)(param_1 + 0x4044) == 0) {
        uVar2 = FUN_00437050(unaff_ESI + 0x148);
      }
      else {
        uVar2 = FUN_00768760(unaff_ESI + 0x148);
      }
      if (*(int *)(param_1 + 0x4044) == 0) {
        uVar3 = FUN_00437050(unaff_ESI + 0x14c);
      }
      else {
        uVar3 = FUN_00768760(unaff_ESI + 0x14c);
      }
      if (*(int *)(param_1 + 0x4044) == 0) {
        uVar4 = FUN_00437050(unaff_ESI + 0x150);
      }
      else {
        uVar4 = FUN_00768760(unaff_ESI + 0x150);
      }
      if (*(int *)(param_1 + 0x4044) == 0) {
        local_24[0] = FUN_00435fe0(unaff_ESI + 0x154);
      }
      else {
        local_24[0] = FUN_00767fd0(unaff_ESI + 0x154);
      }
      FUN_00449dc0();
      uVar5 = phyBoneSharedData_unserialize(*(undefined4 *)(unaff_ESI + 0xf4));
      uVar5 = uVar5 | local_24[0];
      FUN_0096de80();
      local_4 = 0xffffffff;
      if (local_18 != '\0') {
        FUN_00769e40();
      }
      ExceptionList = local_c;
      return uVar2 | uVar3 | uVar4 | uVar5;
    }
    uVar1 = FUN_0076cec0(local_24,"Invalid chunk version (%i) unserializing phyBone",local_10);
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBone.cpp",0x57,3,uVar1);
  }
  else {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBone.cpp",0x43,3,
                   "Invalid TAG unserializing phyBone");
  }
  local_4 = 0xffffffff;
  if (local_18 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

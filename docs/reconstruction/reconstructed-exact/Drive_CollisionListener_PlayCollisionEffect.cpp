// =============================================================================
// Drive_CollisionListener_PlayCollisionEffect
// -----------------------------------------------------------------------------
// Stable ID: aa_005d9af0
// Address:   0x005d9af0 – 0x005d9e94  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005d9af0
// System:    drive / collision / client FX
// Generated: 2026-07-29 W23-G dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   CollisionListener::PlayCollisionEffect — spawn/apply collision FX for a
//   contacted game object. Resolves clonebase FX binding, optionally lazy-creates
//   an FxMaster on the listener (+4), loads event variant, samples GO frames
//   (vtbl+0x1C8 ×2), writes three float3 FX params (keys 1..3), then plays.
//
// STRING EVIDENCE: FUN_0076cf00("CollisionListener::PlayCollisionEffect") @ 0x009db524
// CALLERS: Drive_CollisionListener_Contact (0x005da0a0), FUN_005d9ea0
// SIBLINGS: Drive_CollisionListener_Contact, DoVehicleCollision, PlayCollisionSound
//
// ABI (sealed from bytes):
//   __thiscall RET 0x14
//   ECX = CollisionListener* this     (FxMaster* @ +4)
//   stack0 = float* vec3             ([ebp+8], three movss)
//   stack1 = uint32_t                ([ebp+c])
//   stack2 = uint32_t / float slot   ([ebp+10])
//   stack3 = int* gameObject         ([ebp+14], null → early return)
//   stack4 = int8_t allowCreate      ([ebp+18])
//
// CONSTANTS (read_memory):
//   a10e74=2.0f  a0f2a0=1.0f  new(8) FxMaster  SetParam keys 1,2,3
// =============================================================================

void __thiscall Drive_CollisionListener_PlayCollisionEffect(
    int this_listener,
    float *vec3_a,
    uint32_t arg1,
    uint32_t arg2,
    int *gameObject,
    int8_t allowCreate)
{
  int iVar1;
  void *pvVar2;
  uint32_t uVar3;
  void *local_1c;
  uint8_t *puStack_18;
  int local_14;

  (void)vec3_a;
  (void)arg1;
  (void)arg2;

  local_14 = 0xffffffff;
  puStack_18 = (uint8_t *)&LAB_009a71fa;
  local_1c = ExceptionList;

  if (gameObject == (int *)0x0) {
    return;
  }

  ExceptionList = &local_1c;
  FUN_0076cf00("CollisionListener::PlayCollisionEffect");

  // go+0xA8 == decompiler go[0x2a] as int*
  iVar1 = gameObject[0x2a];
  local_14 = 0;
  FUN_004eb3b0();

  if (*(int *)(iVar1 + 0x88) == 0) {
LAB_005d9b75:
    if (allowCreate == 0) goto LAB_005d9e70;
    if (*(int *)(this_listener + 4) == 0) {
      pvVar2 = operator_new(8);
      local_14 = (local_14 & ~0xff) | 1;
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
      } else {
        uVar3 = FUN_004a1620(); // FxMasterCatalog_Ctor
      }
      local_14 = (int)((uint32_t)local_14 & 0xffffff00);
      *(uint32_t *)(this_listener + 4) = uVar3;
      FUN_004a6390(); // FxMaster_LoadMasterFromXML
    }
    if ((*(int *)(this_listener + 4) == 0) || (iVar1 = FUN_004a16d0(), iVar1 == 0)) {
      goto LAB_005d9e70;
    }
  } else {
    FUN_004eb3b0();
    iVar1 = FUN_004a16d0();
    if (iVar1 == 0) goto LAB_005d9b75;
  }

  // Frame/world queries then FX param write + play (float body residual in raw)
  (**(code **)(*gameObject + 0x1c8))();
  (**(code **)(*gameObject + 0x1c8))();
  // uses vec3_a[0..2], DAT 2.0f / 1.0f, builds three float3 params
  FUN_004b7550(); // key 1
  FUN_004b7550(); // key 2
  FUN_004b7550(); // key 3
  (**(code **)(*gameObject + 0xf8))();
  FUN_004b7e50(0, 0, 0);

LAB_005d9e70:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return;
}

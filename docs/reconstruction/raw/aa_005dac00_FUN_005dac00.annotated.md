# Annotated low-level: CVOGHBRecreateObject_RecreateOwner_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005dac00` |
| VA | `0x005dac00`–`0x005dae45` |
| Ghidra name | `FUN_005dac00` |
| Canonical name | `CVOGHBRecreateObject_RecreateOwner_Inferred` |
| System | combat / world-object lifecycle |
| Date | 2026-07-29 (W22-J dual seal) |
| Former scaffold | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_005dac00` — **misleading** |

## Machine-level notes

- **ABI:** ECX = `CVOGHBRecreateObject*` / `CVOGHBBase*`; plain `RET`; void.
- **Gate:** `owner = *(this+0x18)` non-null; RTTI cast to `CVOGPhysicsBase` non-null; phys body `phys+0x8` non-null.
- **Role:** Full owner re-bind after recreate HB — physics + graphics refresh, clear soft flag, zero impulse, optional body-type request, tail `FUN_004cd540`.
- Prefer decompile CF; seal bytes for prologue/epilogue and RTTI descriptors only (no `disassemble_bytes`).

## Control flow

```
if *(this+0x18) == 0: return
phys = dynamic_cast<CVOGPhysicsBase*>(owner)
if phys == 0 || phys[2] == 0: return   // phys body host null
FUN_004bcda0(owner+0x160, owner+0x164, 0)
vcall(owner, +0x2a4)(owner[0x29]+0xe4e8)
gfx = dynamic_cast<CVOGGraphicsBase*>(owner)
vcall(gfx layout, +0xfc)()
copy pos (FUN_004e88e0 @ gfx+0x84) + orient (FUN_004e87d0 @ gfx+0x94)
vcall(*gfx)(1, pos3, orient4?, gfx+0xd)
vcall(+0xb8)(*( +0xbc ))
vcall(+0x100)()
vcall(phys, +0x10)()
FUN_00560e90(phys[2], 1)
*(phys_layout + 0x181) &= ~1
if FUN_00418d10()==0: Object_SetPhysBodyTypeIfNotReady(0)
CVOGPhysics_ApplyImpulseVector(&DAT_00bc5670)  // zero
FUN_0040d040(&DAT_00bc5670)
tmp = vcall(+0x244)(); vcall(+0x240)(tmp)
type = *(linked + 0x38)
if type != 0x12 && type != 0x14: FUN_00516a00(1)
FUN_004cd540(phys_layout+4 base, 1)
```

## Pseudocode (annotated)

```c
// __thiscall; ECX = CVOGHBRecreateObject* / CVOGHBBase*
// Canonical: CVOGHBRecreateObject_RecreateOwner_Inferred
void __thiscall CVOGHBRecreateObject_RecreateOwner_Inferred(int pHB)
{
  byte *pbFlag;
  int typeId;
  char softReady;
  int *pPhys;       // CVOGPhysicsBase*
  undefined4 *pGfx; // CVOGGraphicsBase*
  undefined4 v244;
  undefined4 pos[3];
  undefined4 orient[4];

  if (*(int *)(pHB + 0x18) == 0) {
    return;
  }
  pPhys = (int *)__RTDynamicCast(*(int *)(pHB + 0x18), 0,
                                 &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                 &CVOGPhysicsBase::RTTI_Type_Descriptor, 0);
  if ((pPhys == (int *)0x0) || (pPhys[2] == 0)) {
    return;
  }
  /* refresh / rebind owner resources */
  FUN_004bcda0(*(undefined4 *)(*(int *)(pHB + 0x18) + 0x160),
               *(undefined4 *)(*(int *)(pHB + 0x18) + 0x164), 0);
  (**(code **)(**(int **)(pHB + 0x18) + 0x2a4))
            (*(undefined4 *)((*(int **)(pHB + 0x18))[0x29] + 0xe4e8));
  pGfx = (undefined4 *)
         __RTDynamicCast(*(undefined4 *)(pHB + 0x18), 0,
                         &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                         &CVOGGraphicsBase::RTTI_Type_Descriptor, 0);
  (**(code **)(*(int *)(*(int *)(pGfx[1] + 4) + 4 + (int)pGfx) + 0xfc))();
  FUN_004e88e0(&pos, *(int *)(pGfx[1] + 4) + 0x84 + (int)pGfx);
  FUN_004e87d0(&orient, *(int *)(pGfx[1] + 4) + 0x94 + (int)pGfx);
  (**(code **)*pGfx)
            (1, pos[0], pos[1], pos[2], orient[0], orient[1], orient[2], orient[3],
             *(undefined1 *)((int)pGfx + 0xd));
  (**(code **)(*(int *)((int)pGfx + *(int *)(pGfx[1] + 4) + 4) + 0xb8))
            (*(undefined4 *)((int)pGfx + *(int *)(pGfx[1] + 4) + 0xbc));
  (**(code **)(*(int *)(*(int *)(pGfx[1] + 4) + 4 + (int)pGfx) + 0x100))();
  (**(code **)(*pPhys + 0x10))();
  FUN_00560e90(pPhys[2], 1);
  pbFlag = (byte *)(*(int *)(pPhys[1] + 4) + 0x181 + (int)pPhys);
  *pbFlag = *pbFlag & 0xfe;                 /* clear bit0 */
  softReady = FUN_00418d10();
  if (softReady == '\0') {
    FUN_0053d970(0);                        /* Object_SetPhysBodyTypeIfNotReady(flag=0 → type 1) */
  }
  CVOGPhysics_ApplyImpulseVector(&DAT_00bc5670); /* zero impulse */
  FUN_0040d040(&DAT_00bc5670);
  typeId = *(int *)(*(int *)(pPhys[1] + 4) + 4 + (int)pPhys);
  v244 = (**(code **)(*(int *)(*(int *)(pPhys[1] + 4) + 4 + (int)pPhys) + 0x244))();
  (**(code **)(typeId + 0x240))(v244);
  typeId = *(int *)(*(int *)(*(int *)(pPhys[1] + 4) + 0xac + (int)pPhys) + 0x38);
  if ((typeId != 0x12) && (typeId != 0x14)) {
    FUN_00516a00(1);
  }
  FUN_004cd540((int)pPhys + *(int *)(pPhys[1] + 4) + 4, 1);
  return;
}
```

## Confidence

| Claim | Level |
|---|---|
| thiscall ECX=HB; `+0x18` owner | **High** |
| Dual RTTI Physics + Graphics | **High** |
| Recreate-owner role (not spawn factory) | **High** |
| Clear flag bit0 @ layout+0x181 | **High** |
| Zero impulse via `DAT_00bc5670` | **High** |
| Soft body-type via `0053d970(0)` | **High** |
| Product English for each vfunc | Open |
| `FUN_004cd540` / `FUN_00516a00` English | Open |

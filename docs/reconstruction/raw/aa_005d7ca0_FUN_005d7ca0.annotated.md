# Annotated low-level: CVOGHBAI_ProfileType4_DoLogic_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005d7ca0` |
| VA | `0x005d7ca0`–`0x005d7dd0` (**305 B**) |
| Ghidra | `FUN_005d7ca0` |
| Canonical | `CVOGHBAI_ProfileType4_DoLogic_Inferred` |
| System | npc-ai / HBAI / profile-type-4 |
| Date | 2026-07-29 (W27-I seal; scaffold 2026-07-23) |

## Machine-level notes

- **ABI:** `__thiscall`/`__fastcall` ECX=`this` (HBAI); **void**; bare `RET` after `ADD ESP,8`.
- **Vtbl home:** `0x009db0dc` in `PTR_FUN_009db08c` (ctor `FUN_005d7de0`, factory case **4** of `Object_EnsurePrimaryHBAI_FromAIProfile`).
- **Owner:** `this+0x64` (`[0x19]`) — identical owner slot to Driver/CreatureBase DoLogic.
- **Profile:** key from owner MI → def `+0x4dc`; `Host_AIProfileMap_GetOrReset` + `Map_LowerBoundFindByIntKey_Isnil65`; **return if end**.
- **Owner flag clear:** `FUN_004c3c80(owner, 0)` → writes `owner+0x278 = 0` (TFID target path only when arg==1).
- **State:** binary on `owner+0x26c` (0 vs non-0) — not the full ternary idle/engage/combat of CreatureBase.
  - **0:** cast set 0 → aim → if path byte clear: busy? ret; vtbl+0x1c; target? vtbl+0x2c(2); `FUN_005cebd0(0)`? ret; owner/vehicle vtbl+0x1a0 → this vtbl+0x4c.
  - **non-0:** cast set 2 → aim → if path clear: busy? ret; target? `FUN_005cf560`; if target still present return; else vtbl+0x2c(0).
- **Fallthrough:** `FUN_005cc450()` when path-mode byte `this+0x60` non-zero after cast/aim.

## Pseudocode (annotated)

```c
void CVOGHBAI_ProfileType4_DoLogic_Inferred(int *self)
{
  uint32_t key = /* owner MI -> def +0x4dc */;
  int *it;
  Host_AIProfileMap_GetOrReset(host, 0);
  Map_LowerBoundFindByIntKey_Isnil65(&it, &key);
  if (it == map_end) return;

  FUN_004c3c80(self[0x19], 0);  // clear owner+0x278

  if (*(char *)(self[0x19] + 0x26c) == 0) {
    NPC_TryCastSkillFromSet(self, 0);
    CVOGHBAI_UpdateAimOffset_Inferred();
    if ((char)self[0x18] == 0) {
      if (FUN_005cc980()) return;
      self->vtbl[+0x1c]();
      if (*(int *)(self[6] + 0xa0)) self->vtbl[+0x2c](2);
      if (FUN_005cebd0(0)) return;
      u = (*(self[6])->vtbl[+0x1a0])(0);
      self->vtbl[+0x4c](u);
      return;
    }
  } else {
    NPC_TryCastSkillFromSet(self, 2);
    CVOGHBAI_UpdateAimOffset_Inferred();
    if ((char)self[0x18] == 0) {
      if (FUN_005cc980()) return;
      if (*(int *)(self[6] + 0xa0)) FUN_005cf560();
      if (*(int *)(self[6] + 0xa0)) return;
      self->vtbl[+0x2c](0);
      return;
    }
  }
  FUN_005cc450();
}
```

## Residuals

- Product class name for vtbl `009db08c` / profile type 4.
- Product method name (DoLogic is structural inference from Driver plate + CreatureBase dual).
- Nested helpers `FUN_005cc980` / `FUN_005cebd0` / `FUN_005cc450` dual ownership elsewhere.
- Runtime / bit-exact open.

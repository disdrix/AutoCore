# Annotated low-level: FUN_008c4fc0 → Client_CastFirstHardpointSkillFlag200_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008c4fc0` |
| VA | `0x008c4fc0` |
| System | skills-abilities / host hardpoint cast |
| Date | 2026-07-23 scaffold; **WQ8R-F 2026-08-04** |

---

## Machine-level notes

- **Role:** When local player has host-mode flag `+0x6b8`, walk the hardpoint / HB list (`MI+0xb4` on player or active vehicle), take the **first** `CVOGHBSkillBase` with enable byte `+0x140`, and if skill runtime flags `+0x614 & 0x200` cast via `Client_CastSkillFromQuickBarSlot(skillId@+0x5fc)`.
- **ABI:** no stack formals; `SUB ESP,8` / `ADD ESP,8` / `RET`. Client for cast loaded as `ESI=&DAT_00d1a840` (stdcall skillId on stack) — matches dual residual of `Client_CastSkillFromQuickBarSlot`.
- **List helpers (registry):** `FUN_004294f0` = `List_TraversalLock` (EnterCS @list+4, set +0x28); `FUN_004022a0` = `List_IterateNext` (cursor in locals; ret 0 = continue).
- **Unlock:** if traversal flag `list+0x28` still set after walk, clear + LeaveCS.
- **Filter:** HB node `+0x1c == 1` (skill type tag, same as `CVOGHBSkillBase_ctor`); RTTI cast Base→SkillBase; skillBase `+0x140 ≠ 0`; skill object = skillBase `+0x24`.
- **Flag mask 0x200:** sealed by `TEST [skill+0x614],0x200` + `JLE` skip; distinct from CastSkillFromQuickBarSlot aim bits `0x800`/`0x20`.
- **Host selection:** if `player+0x30c==0` **or** `player+0x250==0` → list on **player**; else list on **vehicle** at `+0x250`.
- **Single caller:** UI path `FUN_008c50f4` when `+0x6b8 && !+0x6b9` (enhanced-state bit `+0x6b9` diverts to mod-chip instead).
- Prefer this annotation + `read_memory` over decompiler stack noise for ESI client recovery.

## Pseudocode (annotated)

```c
// Client_CastFirstHardpointSkillFlag200_Inferred  @ 0x008c4fc0
// INFERRED — no product string/RTTI on this VA; role from CF + RTTI cast + dualed callee.
void Client_CastFirstHardpointSkillFlag200_Inferred(void)
{
  Character* player = DAT_00d1b6d8;          // local character
  if (!player || !player->flag_0x6b8) return;

  // Resolve HB/hardpoint list host: vehicle if present & host-link (+0x30c) set, else player
  List* listHost;
  if (player->byte_0x30c == 0 || player->vehicle_0x250 == 0)
    listHost = *(List**)( MI_adjust(player) + 0xb4 );
  else
    listHost = *(List**)( MI_adjust(player->vehicle_0x250) + 0xb4 );

  if (!listHost) return;

  SkillRuntime* chosen = nullptr;
  ListCursor cur = {0, 0};
  List_TraversalLock(listHost);              // FUN_004294f0 — ECX=listHost
  int done = List_IterateNext(listHost, &cur.node, &cur.payload);
  while (done == 0) {
    CVOGHBBase* hb = (CVOGHBBase*)cur.node; // decomp: local_8
    if (hb && hb->typeTag_0x1c == 1) {
      CVOGHBSkillBase* skillHb =
        dynamic_cast<CVOGHBSkillBase*>(hb); // __RTDynamicCast Base→SkillBase
      if (skillHb && skillHb->enable_0x140) {
        chosen = (SkillRuntime*)((char*)skillHb + 0x24);
        break;
      }
    }
    done = List_IterateNext(listHost, &cur.node, &cur.payload);
  }
  if (listHost->traversalHeld_0x28) {
    listHost->traversalHeld_0x28 = 0;
    LeaveCriticalSection(&listHost->cs_0x4);
  }

  if (chosen && (chosen->flags_0x614 & 0x200)) {
    // ESI = &DAT_00d1a840 (global client); push skillId @ +0x5fc
    Client_CastSkillFromQuickBarSlot(/*client via ESI*/, chosen->skillId_0x5fc);
  }
}
```

## Open questions

1. Product English for `player+0x6b8` / `+0x30c` / list at `MI+0xb4` (host HB list).
2. Product name of skill flag bit **0x200** on `+0x614`.
3. Why only the **first** matching skill HB (no multi-cast).
4. PDB / retail symbol for this VA.
5. Runtime capture of case-8 / `0x9c40` UI path invoking parent → this unit.

# Annotated low-level: Skill_InsertCategoryCooldown

| Field | Value |
|---|---|
| Stable ID | `aa_00518df0` |
| VA | `0x00518df0` |
| System | skills-abilities |
| Date | 2026-07-23; residual seal 2026-07-29 |

## Machine-level notes

- Source: raw capture + live re-decompile/`read_memory` 2026-07-29.
- **ABI:** `RET 0x8` — `__stdcall` two stack formals (`nCategoryId`, `nDurationMs`).
- **Implicit ECX:** not a formal param; passed through to `Skill_GetCategoryCooldownMap` as **map owner** (host with map slot `+0x6c`). Ghidra marks `in_ECX` phantom.
- **Early out:** `categoryId == -1` → no GetMap / no Insert.
- **Entry pack (12 bytes):** `{ int key; uint startTick; int durationMs }` with `startTick = g_dwClientTickMs` (`0x00b041cc`).
- **Call sequence:** push Map_Insert stack args → `GetMap(ECX=owner)` → `mov ecx, eax` → `Map_Insert(this=map, outPair, entry)` (Map_Insert `RET 8` cleans both pushes).
- **Map_Insert semantics (callee sealed):** insert-**or-find** — equal key does **not** rewrite start/duration. Plate wording “inserts/**updates**” is **overstated** for equal-key hits.
- **Sole static caller:** `Skill_ApplyStatusEffectLocal` @ `0x0051ac77` (item-skill arm: `packet+0x38 != 0`). Cast-again ctor arms category CD via **direct** `Map_Insert`, not this wrapper.
- Call-site duration (caller context, not this unit’s math): `*(int*)(pPacket+0x10) + skill->nPeriodCounter`; category from skill field block used as int key.

## Pseudocode (annotated)

```c
/* Skill_InsertCategoryCooldown — high-level category CD arm
   ABI: __stdcall RET 8; ECX = map owner (cast-side host, map @ +0x6c)
   Entry: {key=categoryId, start=g_dwClientTickMs, duration=durationMs}
   Map_Insert = insert-or-find (no refresh on live key). */

void __stdcall Skill_InsertCategoryCooldown(int nCategoryId, int nDurationMs)
{
  void *pMapOwner = /* ECX at entry */;
  InsertPair outPair;           // local_14[8]: {node* it, u8 inserted}
  CategoryCooldownEntry entry;  // nKey, nStartTick, nDuration

  if (nCategoryId == -1)
    return;

  entry.key = nCategoryId;
  entry.startTick = g_dwClientTickMs;   // DAT_00b041cc / 0x00b041cc
  entry.durationMs = nDurationMs;

  {
    void *map = Skill_GetCategoryCooldownMap(pMapOwner); // __fastcall ECX
    // thiscall:
    Skill_CategoryCooldownMap_Insert(map, &outPair, &entry);
    // outPair ignored
  }
}
```

## Open questions

- Product class name of map owner (`+0x6c` host) — High as cast-owner, not skill runtime (sibling GetMap dual).
- Whether any dynamic/call-through path exists beyond the single static xref (unlikely; xref scan complete).
- Runtime proof of equal-key no-refresh (owned by Map_Insert dual; inherited here).

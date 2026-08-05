# Dual A/B â€” `aa_00512440` Object_GetRootRaceId

**Date:** 2026-07-29  
**Owned VA:** `0x00512440` only  
**Tools:** Ghidra `decompile_function` / `read_memory` / high pcode / callers / `get_enum_values` (no Launcher; no WORK_QUEUE/RESUME/ACTIVE_WORK/CHANGE_LOG)  
**Verdict:** **accept-with-gaps**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| Leaf unary getter of **root** race/faction id | Decompile + 32-byte body; `callees: []` |
| Walks **owner chain** `object+0xAC` until null | Bytes `mov eax,[ecx+0xAC]` / loop; pcode `INT_ADD 0xac` |
| Returns **DWORD** at **root `+0x10`** | `mov eax,[ecx+0x10]` / pcode `INT_ADD 0x10` + LOAD â†’ EAX |
| ABI: `__fastcall`, arg in **ECX**, ret **EAX** | Signature + pcode register 4 / 0 |
| Body **`00512440`â€“`0051245f`** | Function bounds |
| **No** null-check on input; **no** cycle guard | Entry load; unbounded while |
| Plate documents regen period use (0/1/2 â†’ 3000 ms) | Plate comment on function |

### Signature

```c
RACE_ID_INFERRED __fastcall Object_GetRootRaceId(void *pObject);
// pObject: cloned-object base (not necessarily "this" of a C++ method)
// return: *(s32*)(root + 0x10) where root is end of +0xAC owner chain
```

### Algorithm (authoritative)

```
owner = *(pObject + 0xAC)
while owner != NULL:
    pObject = owner
    owner = *(pObject + 0xAC)
return *(pObject + 0x10)   // RACE_ID_INFERRED / s32
```

If the starting object has **null** owner, returns **that objectâ€™s** `+0x10` (self is root).

### Constants / related domain (caller-sealed; not body magic numbers)

| Value | Meaning (caller domain) | Example consumer |
|---|---|---|
| `0` | `RACE_HUMAN_INFERRED` | Ghidra enum; regen 3000 |
| `1` | `RACE_BIOMEK_INFERRED` | enum; regen 3000 |
| `2` | `RACE_TRIBE_INFERRED` | enum; regen 3000 |
| other / non-{0,1,2} | non-player race path | regen **5000** in `CVOGHBRegeneration_ctor` |
| `0xFFFFFF9C` (âˆ’100) | Neutral â€” skip proactive aggro | `CVOGHBAIBase_FindTargetToAttack` |
| `~0` (âˆ’1) | Special vs Human; â€œNPCâ€ faction skip path | `FUN_005c9450` hostility |

Ghidra enum `RACE_ID_INFERRED` size **4**, members **only** Human/Biomek/Tribe as above.

### Companion (not owned)

| VA | Role |
|---|---|
| `0x00512460` `FUN_00512460` | **Writer**: set `+0x10` on self and walk owners writing same id (spawn faction dirty apply) |

### Call surface

| Metric | Value |
|---|---|
| Xrefs | **38** |
| Named callers (sample) | `CVOGHBAIBase_FindTargetToAttack`, `CVOGHBRegeneration_ctor`, `CVOGSpawnPoint_CreateCreature`, `CVOGSpawnPoint_CreateTemplateVehicle`, `CVOGVariable_EvaluateComputed`, `FUN_005c9450` / `FUN_005c8e00` (hostility), `FUN_00509010`, `FUN_0050aa80`, `FUN_004d5110`, â€¦ |

### Port implication

Resolve faction/race for AI, hostility, regen, and spawn by **owner-chain root**, not leaf-only `+0x10`. Keep writer sibling when applying spawnpoint faction overrides.

---

## Gaps

1. Product field names for `+0xAC` / `+0x10`.
2. Full faction/race id table beyond 0/1/2 and known sentinels (âˆ’1, âˆ’100).
3. Whether race vs faction are always the same DWORD domain (usage is unified in callers).
4. Owner-chain cycle / corruption policy.
5. Runtime capture / bit-exact image diff.
6. Per-caller argument adjustment (`*(**+4)+4+obj` MI bases) is caller-owned, not this unit.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00512440_Object_GetRootRaceId.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00512440_Object_GetRootRaceId.md` | accept-with-gaps |

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00512440_Object_GetRootRaceId.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00512440_Object_GetRootRaceId.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00512440_Object_GetRootRaceId.md` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00512440_Object_GetRootRaceId.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00512440_Object_GetRootRaceId.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Object_GetRootRaceId.cpp` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-00512440-object-getrootraceid-report.md` |

Duplicate scaffolds (legacy name `FUN_00512440`):  
`docs/reconstruction/functions/aa_00512440_FUN_00512440.md`,  
`docs/reconstruction/raw/aa_00512440_FUN_00512440*.md`,  
`docs/reconstruction/reconstructed-exact/FUN_00512440.cpp` â€” prefer **Object_GetRootRaceId** paths.

---

## AutoCore port sketch

```csharp
/// <summary>Retail aa_00512440: walk owner (+0xAC) to root, return root race/faction (+0x10).</summary>
public static int GetRootRaceId(ObjectBase obj)
{
    // Retail does not null-check obj
    while (obj.Owner != null)
        obj = obj.Owner;
    return obj.RaceOrFactionId;
}
```

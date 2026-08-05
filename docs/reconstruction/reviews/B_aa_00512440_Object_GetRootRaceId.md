# Review B (skeptical / adversarial): `aa_00512440` Object_GetRootRaceId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512440_Object_GetRootRaceId.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | “Get race of *this* object only” | Body follows `+0xAC` owners; leaf object’s own `+0x10` is **ignored** if any owner exists | **Over-narrow if misread** — returns **root** id |
| 2 | Returns relation *between* two objects | Single ECX arg; no second object | **Falsified** — unary root load |
| 3 | Thiscall with hidden `this` class method only | `__fastcall` with ECX object pointer; callers pass adjusted bases (`*(**+4)+4+obj`) | **Naming ok**; not virtual |
| 4 | Null `pObject` safe | Immediate `[ecx+0xAC]` | **Unsafe** — crash on null |
| 5 | Stops at “root vehicle” specifically | Stops at **null owner**; root may be creature, spawn template, map object, etc. | **Semantic gap** — chain topology is caller’s |
| 6 | Enum complete: only 0/1/2 | Ghidra enum has 3 members; callers also use **−100**, **−1**, and “else” paths | **Incomplete enum in type** — raw s32 domain |
| 7 | `+0x10` is display race only | Hostility (`005c9450`), AI neutral, spawn apply, regen period all use same load | **Faction/race dual use** — opaque DWORD |
| 8 | Must call companion writer to stay consistent | Getter does not write; spawn paths call `FUN_00512460` to push id down chain | **Pairing is caller duty** |
| 9 | Clean invented control flow | 32-byte leaf; decompile ≡ bytes ≡ clean | **No invention** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Algorithm (walk `+0xAC`, load root `+0x10`) | **High** | Wrong faction resolution on owned items/vehicles |
| Offsets `0xAC` / `0x10` | **High** | Broken AI / hostility / spawn |
| `__fastcall` ECX in / EAX out | **High** | Wrong ABI on port |
| No null / cycle guards | **High** | Server crash or hang if bad graph |
| Product name of return as “race id” | **High** usage / **Medium** product string | Mislabel faction vs race tables |
| −100 Neutral meaning | **High** (caller seal) | Proactive aggro always/never |
| −1 NPC special case | **Probable** (caller) | Hostility skip wrong |
| Full race id table | **Tentative** | Wrong regen period / faction map |

---

## 3. Cross-check against raw / pcode / memory

```
raw decompile:
  owner = *(p+0xAC)
  while owner: p = owner; owner = *(p+0xAC)
  return *(p+0x10)

high pcode:
  INT_ADD ECX, 0xac → LOAD  (owner)
  INT_NOTEQUAL owner, 0 → CBRANCH loop / exit
  loop: INT_ADD cur, 0xac → LOAD
  exit: INT_ADD root, 0x10 → LOAD → EAX → RETURN

read_memory 00512440..5f:
  matches above; ret at 0051245f
  next function 00512460 = chain writer of +0x10
```

Clean does **not** invent bounds checks, vtable calls, or multi-object compare.

---

## 4. Surviving contract for AutoCore

```csharp
// Unary: root race/faction id after owner-chain walk.
// pObject must be non-null cloned-object base with +0xAC owner ptr and +0x10 id.
int Object_GetRootRaceId(ClonedObjectBase p)
{
    // No retail null check
    while (p.Owner != null)   // field +0xAC
        p = p.Owner;
    return p.RaceOrFactionId; // field +0x10 (s32)
}

// Call-site constants (not this body):
//   0,1,2 = Human, Biomek, Tribe (regen 3000 ms)
//   -100  = Neutral (skip proactive aggro)
//   -1    = ~Human special ("NPC" faction path in hostility)
// Writer sibling: FUN_00512460 sets +0x10 on self and all owners up chain.
```

---

## 5. Residual gaps (do not over-seal)

1. Exact C++ member names / class owning layout.
2. Whether every object type stores meaningful id at `+0x10` without walk.
3. Full faction table from `tFactions` / clonebase.
4. Cycle policy (undefined in retail).
5. Runtime confirmation on live objects.

**Verdict:** **accept-with-gaps**

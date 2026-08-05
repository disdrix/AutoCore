# Review B (skeptical / adversarial): `aa_00512460` Object_SetRaceIdOwnerChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Writes **only** leaf `+0x10` | Body loops owners at `+0xAC` | **Falsified** — chain write |
| 2 | Writes **only** root (like inverse of getter) | Always writes self first; then owners including root | **Over-narrow if misread** — self+chain |
| 3 | `__fastcall` two-register args | Bytes: id from `[esp+4]`, `ret 4` | **Falsified** — thiscall + stack |
| 4 | Stops before writing root | Loop writes `cur` then checks `cur+0xAC` | **Falsified** — root written |
| 5 | Null `pObject` safe | Immediate `[ecx+0xAC]` / `[ecx+0x10]` | **Unsafe** |
| 6 | Cycle-safe | Unbounded while on owner links | **No guard** |
| 7 | Same as getter walk | Getter returns root load; this **mutates** every node | **Different role** — pair, not dual of same op |
| 8 | Long Named_CalleeOf_… primary name | Role sealed as race/faction chain writer | **Reject** legacy scaffold alias as primary |
| 9 | Clean invents control flow | 39-byte leaf; decompile ≡ bytes | **No invention** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Algorithm (self + owner chain write `+0x10`) | **High** | Wrong spawn faction / vehicle-driver sync |
| Offsets `0xAC` / `0x10` | **High** | Broken AI / hostility / regen consumers of chain |
| `__thiscall` + `ret 4` | **High** | Wrong ABI on port |
| Root-inclusive | **High** | Partial chain leaves root stale vs getter |
| Product “race” vs “faction” label | **Medium** product string / **High** usage | Docs mislabel tables |
| Full id table | **Tentative** | Wrong authored overrides |

---

## 3. Cross-check against raw / memory

```
raw decompile:
  *(p+0x10) = id
  while owner: cur = owner; *(cur+0x10)=id; advance +0xAC

read_memory 00512460..86:
  cmp [ecx+0xac],0
  mov edx,[esp+4]
  lea eax,[ecx+0xac]
  mov [ecx+0x10],edx
  jz done
loop:
  mov eax,[eax]
  mov [eax+0x10],edx
  add eax,0xac
  cmp [eax],0
  jnz loop
  ret 4
```

Clean does **not** invent bounds checks, vtable calls, or write-only-root semantics.

Decompiler’s initial `iVar1 = *(p+0xac)` is redundant with the loop’s first `*piVar2` but **semantically equivalent** to the early-out byte path.

---

## 4. Surviving contract for AutoCore

```csharp
// thiscall: set race/faction on object and every owner including root.
// pObject must be non-null cloned-object base with +0xAC owner ptr and +0x10 id.
void Object_SetRaceIdOwnerChain(ClonedObjectBase p, int raceId)
{
    p.RaceOrFactionId = raceId;          // +0x10
    var slot = p;                        // walk via +0xAC
    while (slot.Owner != null)
    {
        slot = slot.Owner;
        slot.RaceOrFactionId = raceId;
    }
}

// Pairing (caller duty):
//   id = Object_GetRootRaceId(spawnpoint);  // 0x00512440
//   Object_SetRaceIdOwnerChain(spawned, id);
//   // optional: same on driver for template vehicles
```

Port already present as `SpawnPoint.ApplySpawnFactionOverride` (2026-07-13) for dirty spawn faction — keep **chain** semantics if owner links exist server-side.

---

## 5. Residual gaps (do not over-seal)

1. Exact C++ member names / owning class layout.
2. Full faction table from data.
3. Cycle policy (undefined in retail).
4. Runtime confirmation on live objects (driver + vehicle both updated).
5. Whether any caller expects leaf-only write (body never does leaf-only).

**Verdict:** **accept-with-gaps**

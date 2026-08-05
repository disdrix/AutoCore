# Review B (skeptical / adversarial): `aa_005b0920` CNDHash_LookupByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0920` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b0920_CNDHash_LookupByKey.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is `__stdcall` / multi-arg | Bytes: ECX-relative loads then `[ESP+4]` key; **`RET 4`** thrice | **Falsified** — **`__thiscall(this, key)`** |
| 2 | Returns node pointer | Final success path `MOV EAX,[EAX+8]` only | **Falsified** — returns **value** |
| 3 | Fancy hash (multiply / rotate) | Only `AND` of mask & key | **Falsified** — **mask & key** |
| 4 | Takes traversal lock / asserts | No load of `+0x1d`; no callees | **Falsified** — **unlocked read** |
| 5 | Decompiler invented `*(bucket+4)` indirection | Bytes: `mov eax,[ecx+eax*4]; mov eax,[eax+4]` | **Confirmed** — real double load |
| 6 | Clean scaffold is “unknown system” only | Ubiquitous xrefs (missions, unlock, skills, UI) | **Partially** — system is **shared container**, not mission-only |
| 7 | Plate comment “USContinentUnlocked only” | Plate mentions one use; 200+ sites | **Falsify exclusive use** — continent unlock is **one consumer** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + key + RET 4 | **High** | Wrong call wrappers crash / corrupt stack |
| mask@+8, buckets@+10 | **High** | All hash lookups mis-index |
| node key@+10, next@+c, value@+8 | **High** | Wrong returns / infinite walk |
| bucket head @ bucketHdr+4 | **High** | Always-null or wrong chain |
| No callees / no lock | **High** | Spurious lock ports |
| mask is always power-of-two−1 | **Medium** | Assumed from & pattern; ctor not owned |
| First-match on duplicates | **High for this unit** | Depends on Insert prepend (sibling sealed for layout) |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  iVar1 = *(*(this+0x10 + (mask&key)*4) + 4);
  while key != *(iVar1+0x10): iVar1 = *(iVar1+0xc); if !iVar1 return 0
  return *(iVar1+8)

bytes @ 005b0920 (read_memory):
  8B4108 8B542404 8B4910 23C2 8B0481 8B4004 85C0 7413
  3B5010 740A 8B400C 85C0 75F4 C20400
  85C0 7505 33C0 C20400 8B4008 C20400
  CC...

≡ same CF. Insert 0053c560 writes value@+8 key@+10 next@+c head@bucket+4 → consistent.
```

---

## 4. Surviving contract for AutoCore

```csharp
// Port of client CNDHash lookup (leaf). Do not confuse with VOG hash / std::map.
object? CndHashLookupByKey(CndHash table, uint key)
{
    uint index = table.Mask & key;                 // +0x08
    var bucket = table.Buckets[index];             // +0x10 → T*
    var node = bucket.Head;                        // bucket +0x04
    while (node != null)
    {
        if (node.Key == key)                       // +0x10
            return node.Value;                     // +0x08
        node = node.Next;                          // +0x0c
    }
    return null;
}
```

- Server ports of mission/skill/unlock tables may use .NET `Dictionary` — **must preserve key==value identity** and null miss semantics, not bucket layout, unless bit-identical client sim is required.
- Callers that treat non-null as “has entry” are correct; do not return sentinel objects.

---

## 5. Open questions

1. Ctor / resize: is mask always `capacity-1` with power-of-two capacity?
2. Full bucket-header and node object sizes (only chain fields sealed here).
3. Whether any writer inserts without going through `CNDHash_Insert` (would still need same node layout for Lookup to work).
4. Runtime confirmation on live `autoassault.exe` process (static only this session).
5. Full caller product map (out of OWN ONLY scope beyond listing).

**Verdict:** **accept**

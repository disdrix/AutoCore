# Review B (skeptical / adversarial): `aa_004bc530` CNDHash_TraverseToNext_ListNext20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-029) |
| **Counterpart** | `reviews/A_aa_004bc530_CNDHash_TraverseToNext_ListNext20.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Product id is `VOG_DEBUG_STOP` / Named_VOG_* | **Falsified** — shared assert plate; real op string is **TraverseToNext** |
| 2 | Same body as dualed `CNDHash_TraverseToNext` `0x00411900` | **Falsified** — twin next@**+0x14** / payload@**+8**; this next@**+0x20** / payload@**+0xc** |
| 3 | Unlocked traverse aborts / returns | **Falsified** — dual log only; fall-through continues |
| 4 | Returns the **node** pointer | **Falsified** — returns `*(node+0xc)` payload |
| 5 | Sets or clears traversal lock | **Falsified** — read-only check; parent `FUN_004bae00` / `FUN_00402c40` own lock |
| 6 | `__cdecl` / no stack cleanup | **Falsified** — `MOV ESI,ECX`; dual **`RET 4`** |
| 7 | Many direct callers / skill-map exclusive | **Falsified** — sole caller `FUN_004bae00` (2 sites); not skill-hash twin |
| 8 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 9 | Interaction-activation product system owns this leaf | **Clarify** — partition tags consumer path; body is **generic CNDHash** iterator |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Iterate step under lock (log if not) | **Confirmed** | Skip / infinite if next offset wrong |
| Payload at `node+0xc` (this family) | **Confirmed** | Wrong object handle |
| Next at `node+0x20` (this family) | **Confirmed** | Corrupt walk |
| No membership mutation | **Confirmed** | Accidental remove ports |
| Merge with skill twin `00411900` | **None — forbidden** | Crash / wrong payload |
| Product English "CNDHash" class brand | **High** (HashError family) | Doc only |
| Exact stamp / table instance English | **Low** | Naming residual only |
| Runtime / bit-exact | **Open** | — |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean CNDHash_TraverseToNext_ListNext20.cpp

56 8B F1                 PUSH ESI; MOV ESI,ECX
80 7E 1D 00              CMP byte [ESI+0x1d],0
75 1B                    JNZ skip_log
68 9C 7C A2 00           PUSH "HashError:TraverseToNext, not locked for traversal"
6A 00 / E8 …            CALL FUN_007a4480
68 44 58 A1 00           PUSH "VOG_DEBUG_STOP"
6A 00 / E8 … / 83 C4 10 CALL + ADD ESP,0x10
8B 4C 24 08              MOV ECX,[ESP+8]   ; cursor*
…
8B 40 20                 MOV EAX,[EAX+0x20]  ; next (non-null cursor path)
…
8B 40 0C                 MOV EAX,[EAX+0x0c]  ; payload
5E C2 04 00              POP ESI; RET 4
33 C0 5E C2 04 00        XOR EAX,EAX; POP ESI; RET 4
```

Reject ports that:

- Name this `Named_VOG_DEBUG_STOP_*` or treat assert as product API.
- Use next@+0x14 / payload@+8 (skill twin layout).
- Treat unlock log as fatal abort.
- Return node* instead of payload.
- Implement lock set/clear inside this leaf.
- Use cdecl without `RET 4`.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: CNDHash::TraverseToNext under TraversalLock
// Node family: listNext @ +0x20, payload @ +0x0c (not the +0x14/+8 skill family)

uint TraverseToNext_ListNext20(CndHash hash, ref uint cursorNode)
{
    if (hash.LockedForTraversal /* +0x1d */ == 0)
    {
        Log("HashError:TraverseToNext, not locked for traversal");
        Log("VOG_DEBUG_STOP");
        // continue — non-fatal
    }

    if (cursorNode == 0)
        cursorNode = hash.ListHead; // +0x14
    else
        cursorNode = ReadU32(cursorNode + 0x20); // list next

    return cursorNode != 0 ? ReadU32(cursorNode + 0x0c) : 0; // payload
}

// Parent pattern (FUN_004bae00):
//   TraversalLock(hash);  // FUN_00402c40
//   payload = TraverseToNext_ListNext20(hash, ref cursor);
//   hash.LockedForTraversal = 0;
```

Keep distinct from:

| Twin / peer | VA | Layout |
|---|---|---|
| `CNDHash_TraverseToNext` | `0x00411900` | next+0x14 / payload+8 |
| `FUN_00402c40` TraversalLock | `0x00402c40` | sets +0x1d |
| Parent shell | `0x004bae00` | lock/traverse/unlock dual hash |

---

## 5. Verdict

Adversarial pass confirms A's CF/ABI/layout split; VOG_DEBUG_STOP and twin-merge claims falsified. Residual stamp + runtime only → **accept-with-gaps**.

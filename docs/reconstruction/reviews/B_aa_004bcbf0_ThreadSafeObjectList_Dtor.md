# Review B (skeptical / adversarial): `aa_004bcbf0` ThreadSafeObjectList_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcbf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bcbf0_ThreadSafeObjectList_Dtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Deletes list **nodes** in the while-loop | Loop operand is PopFront **return** = payload; nodes free inside PopFront | **Falsified** — payload delete only |
| 2 | Single critical section | Two DeleteCS: `+0x10` and `esi+0x28` | **Falsified** — dual CS |
| 3 | `__cdecl` / stack this | `mov esi,ecx`; `ret` no imm | **Falsified** — thiscall/fastcall |
| 4 | Leaves count dirty | `mov [esi+0xC],0` after drain | **Confirmed** zero |
| 5 | Different layout than PopFront | Offsets match sealed twin | **Confirmed** shared layout |
| 6 | Name is PDB product symbol | Structural inference only | **Accept as Inferred** |
| 7 | Decompiler void wrong | No EAX use; pure teardown | **void OK** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Drain order + dual DeleteCS | **High** | CS leak / double-free |
| Payload delete flag 1 | **High** | Object leak |
| Vtbl reinstall before drain | **High** | Wrong virtuals mid-dtor |
| Product English | **Medium** | Doc naming only |

---

## 3. Cross-check against raw / bytes

```
raw:  vtbl=PTR; while PopFront: dtor(1); count=0; DeleteCS×2
bytes: C7 06 68B39C00; E8→0040b020; FF 12 with push 1; C7 46 0C 0; DeleteCS +10/+28
twin:  PopFront returns payload*, frees node
```

Clean must not free nodes again; must not skip payload delete; must hit both CS offsets.

---

## 4. Surviving contract for AutoCore

```csharp
void ThreadSafeObjectList_Dtor(ThreadSafeObjectList list)
{
    // optional: list.Vtbl = knownListVtbl;
    while (true) {
        var payload = ThreadSafeObjectList_PopFront(list);
        if (payload == null) break;
        // payload.Dispose()/delete — virtual dtor(1)
        DestroyOwnedObject(payload);
    }
    list.Count = 0;
    // DeleteCriticalSection(inner); DeleteCriticalSection(outer);
}
```

**Port traps to reject:**

- Treating PopFront return as node\* and double-freeing.
- Only deleting one CS.
- Assuming empty list skips CS teardown (still DeleteCS both).

---

## 5. Residual gaps (do not block seal)

1. Product name.
2. Payload type polymorphism.
3. Runtime / image diff.

---

## Verdict

**accept** — adversarial review cannot break the drain + dual-CS dtor contract. Main trap is payload vs node ownership; PopFront twin seals that split.

# Review B (skeptical / adversarial): `aa_004bbc70` COList_Destructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbc70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bbc70_COList_Destructor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | ICS locals are standalone CS, not ThreadSafeObjectList | Bytes store `PTR_FUN_009cb368` + zero head/tail/count then ICS at +0x10/+0x28; PopFront/Dtor ECX = that stack object | **Falsified** — stack list construct |
| 2 | `FUN_004bcbf0` destroys a **member** list | `lea ecx,[esp+…]` immediately before call | **Falsified** — stack temp only |
| 3 | PopFront returns nodes to free here | Sealed PopFront returns **payload**; nodes freed inside pop | **Confirmed** — payload to TakeByCoid |
| 4 | Append (`004024d0`) targets `this` | Append ECX = stack list | **Falsified** |
| 5 | Class is generic “VOG_DEBUG_STOP” helper | Vtbl rdata `COList::Insert`; ctor twin; scalar dtor | **Falsified** — COList dtor |
| 6 | `__cdecl` | `8B F1`; `ret` no imm on body | **Falsified** — thiscall |
| 7 | Hash next link is +0x14 like SectorMap dtor | COList walk uses **node+0x20** next (bytes `8B 7F 20`) | **Confirmed** difference vs SectorMap hash walk |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack list + dual CS layout | **High** | CS leak / wrong dtor |
| Hash collect + 0xac filter | **High** | Miss detach / crash |
| TakeByCoid drain | **High** | Object list corruption |
| Owned vdel set {6,7,8,9,1,2} | **High** | Leak children |
| Product COList name | **High** | Doc only if wrong |

---

## 3. Cross-check against raw / bytes

```
raw:  vtbl 009cb448; ICS×2; hash walks; Append; PopFront+TakeByCoid; vdel slots; bcbf0; free triples
bytes: C7 06 48B49C00; stack C7 … 68B39C00; E8→004024d0 / 0040b020 / 004bb970 / 004bcbf0; 83C444 C3
twins: list layout ≡ PopFront/Dtor/Append seals; TakeByCoid dual present
```

---

## 4. Surviving contract for AutoCore

```csharp
void COList_Destructor(COList list)
{
    // list.Vtbl = COListVtbl;
    var scratch = new ThreadSafeObjectList(); // dual CS
    CollectHashObjectsWithFlagAc(list.HashA, scratch);
    CollectHashObjectsWithFlagAc(list.HashB, scratch);
    while (true) {
        var obj = ThreadSafeObjectList_PopFront(scratch);
        if (obj == null) break;
        ClonedObjectList_TakeByCoid(list, obj.ModeByte, obj.CoidLo, obj.CoidHi);
    }
    // virtual-delete owned children at sealed slots
    ThreadSafeObjectList_Dtor(scratch);
    // free three vector buffers
}
```

**Port traps to reject:**

- Treating stack list as a COList member field.
- Freeing PopFront payloads as list nodes.
- Using SectorMap hash next-link (+0x14) on COList nodes (+0x20).
- Skipping TakeByCoid before child vdel (order sealed).

---

## 5. Residual gaps (do not block seal)

1. Hash/vector product field names.
2. Runtime / image diff.
3. Exact host sizeof.

---

## Verdict

**accept** — adversarial review cannot break COList dtor CF/ABI/stack-list/drain contract. Residual is English depth only.

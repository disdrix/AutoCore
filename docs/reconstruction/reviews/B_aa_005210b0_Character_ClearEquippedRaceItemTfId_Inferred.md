# Review B (skeptical / adversarial): `aa_005210b0` Character_ClearEquippedRaceItemTfId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005210b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-E) |
| **Counterpart** | `reviews/A_aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This sets/creates the race-item object | **Falsified** — only resolve + deferred enqueue + TFID wipe |
| 2 | This clears CBID at `+0x514` | **Falsified** — no store to `+0x514` in body |
| 3 | `FUN_004d0e90` immediately destroys the object | **Falsified** — sealed as `Object_EnqueueDeferredOnce` (flag + list append) |
| 4 | Null template is all zeros | **Falsified** — `read_memory` shows `ffffffff ffffffff 00000000 00000000` |
| 5 | Always runs clear even when TFID already null | **Falsified** — early return when `(lo&hi)==-1` and byte `+0x520==0` |
| 6 | Clean invents free/dtor calls | **Falsified** — only resolve + enqueue + stores |
| 7 | Stack args present | **Falsified** — ECX this only; plain `ret` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID wipe contract | **High** | Stale ghost binding after unequip/resync |
| Deferred enqueue vs free | **High** | Double-free / use-after-free if ported as free-now |
| Host gate required | **High** | Spurious clear without world context |
| Product name “race item” | Medium | Naming only; CF still holds for TFID slot |
| Resolve intermediate `+0xe4e8` | Medium | Wrong if port assumes free-function-only ABI |

---

## 3. Cross-check against raw + bytes

```
if present(TFID@+0x518) && host(+0xa8) != null:
    obj = Resolve(TFID)           // via *(host+0xe4e8)
    if obj: EnqueueDeferredOnce(host, obj)
    this+0x518 = DAT_009cee98     // 16-byte null template
return
```

Clean must **not**: clear CBID, call object dtor, spawn items, or skip the present/host gates.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of Character_ClearEquippedRaceItemTfId_Inferred
void ClearEquippedRaceItemTfId(Character self)
{
    // if TFID cache looks live and host available:
    //   resolve object; if non-null enqueue deferred teardown once
    //   write null TFID template { -1, -1, 0, 0 } to self+0x518
    // does NOT clear CBID at +0x514
}
```

When porting `Character_SyncEquippedRaceItemFromCbid`: call this on mismatch **before** optional re-give; preserve deferred semantics for the prior world object.

---

## 5. Open questions

1. Product English / PDB name.
2. Whether server should use immediate despawn vs deferred queue (product choice; client CF is deferred).
3. Full identity of `FUN_0052f260` second caller path.

**Verdict:** **accept**

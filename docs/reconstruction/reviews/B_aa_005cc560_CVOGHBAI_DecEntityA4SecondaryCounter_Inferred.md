# Review B (skeptical / adversarial): `aa_005cc560` CVOGHBAI_DecEntityA4SecondaryCounter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc560` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-093) |
| **Counterpart** | `reviews/A_aa_005cc560_CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / stack `this` | **Falsified** — `MOV EDI,ECX`; no stack this load |
| 2 | `RET 4` / stack formals | **Falsified** — exits via `JMP 0x005081e0` → bare `C3`; 0 stack args |
| 3 | Decrements entity fields directly (not A4 block) | **Falsified** — loads `[entity+0xA4]` into ESI base; mutates through that pointer |
| 4 | Counters at `+0x10/+0x14` only (sibling primary pair) | **Falsified** — this unit only touches **`+0x18`/`+0x1c`** secondary pair |
| 5 | Branch on HBAI `this+0x21` / mask `owner+0x210` (sibling 005cc5b0 logic) | **Falsified** — sole branch is **`related+0x250`** after `vtbl+0x214` |
| 6 | Direct CALL to a FUN_* (not virtual) | **Falsified** — `CALL [EAX+0x214]`; callees list empty |
| 7 | Only reachable from park; not a virtual | **Falsified** — 5 DATA vtbl xrefs; park is Driver **override** that tails here |
| 8 | Same body as `FUN_005cc5b0` | **Falsified** — sibling has owner/mask/flags and more counter lanes; different VA/size |
| 9 | `piVar1[0x29]` is index 0x29 objects not +0xA4 | **Falsified** — asm `CMP [EAX+0xA4]`; `0x29*4=0xA4` |
| 10 | ESI+8 means counters+8 (decomp wrong) | **Falsified** — `ADD ESI,0x10` then `+8` ≡ **+0x18**; decomp algebra holds |
| 11 | Product plate “DecEntityA4SecondaryCounter” is official NetDevil name | **Fails** — structural `_Inferred`; no plate string for this VA |
| 12 | Runtime Confirmed | **Fails** — open (no Launcher; Terminal false) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + plain ret | **Confirmed** (bytes) | Stack imbalance |
| entity `+0x18`, counters `+0xA4` | **Confirmed** | Wrong object graph |
| Virtual `+0x214` + branch `+0x250` | **Confirmed** | Wrong related resolve |
| Dec `+0x18`/`+0x1c` only | **Confirmed** | Port wrong counter lane |
| Driver park tail link | **High** | Miss post-park release |
| Counter product English | **Low** | Doc naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw / bytes

```text
raw scaffold 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean
CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.cpp

57 8B F9                PUSH EDI; MOV EDI,ECX
8B 47 18                MOV EAX,[EDI+0x18]
85 C0 74 3C             TEST/JZ
83 B8 A4 00 00 00 00    CMP [EAX+0xA4],0
… FF 90 14 02 00 00     CALL [EAX+0x214]
83 B8 50 02 00 00 00    CMP [EAX+0x250],0
83 46 0C FF / 83 46 08 FF   dec [ESI+0xC] / [ESI+0x8]
E9 … → 005081e0 = C3
```

Reject ports that:

- Treat this as full sibling `005cc5b0` multi-lane release.
- Use cdecl or `RET 4`.
- Decrement primary lanes `+0x10/+0x14` only.
- Skip the `vtbl+0x214` resolve and always hit one lane.
- Claim product plate without `_Inferred`.
- Claim Runtime Confirmed without live proof.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail HBAI virtual (CreatureBase family) + Driver park tail:
// After optional axis park (Driver override):
void DecEntityA4SecondaryCounter(Hbai self)
{
    var entity = self.EntityAt18;
    if (entity == null) return;
    var counters = entity.CounterBlockAtA4;
    if (counters == null) return;
    var related = entity.Vtbl214_GetRelated(); // product name open
    if (related == null) return;
    if (related.FlagOrFieldAt250 == 0)
        counters.SecondaryA_At18--;
    else
        counters.SecondaryB_At1C--;
}
// Do not merge with FUN_005cc5b0 (mask/flag multi-lane release).
// Preserve thiscall, 0 stack formals, plain ret.
```

---

## 5. Verdict

Adversarial pass **confirms** A’s CF/ABI/offset seal and falsifies park-only / sibling-merge / wrong-lane / wrong-ABI claims. Product English residual remains → **accept-with-gaps**.

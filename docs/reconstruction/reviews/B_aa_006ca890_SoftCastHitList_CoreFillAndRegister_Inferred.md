# Review B (skeptical / adversarial): `aa_006ca890` SoftCastHitList_CoreFillAndRegister_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ca890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-062) |
| **Counterpart** | `reviews/A_aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Free function / first arg is this on stack | **Falsified** — body saves `MOV EAX,ECX` then stores via `[EAX+…]`; sole caller `LEA ECX,[local]; CALL` |
| 2 | `RET` bare / `RET 4` / wrong cleanup | **Falsified** — epilog `C2 14 00` (`RET 0x14`); 5 stack formals |
| 3 | Multiple callers / shared generic util | **Falsified** — **1** xref only (`0055e215` in `FUN_0055e1e0`) |
| 4 | Direct callees / leaves without dispatch | **Falsified** — static callees empty, but **indirect** `CALL [EDX+0x30]` always executed |
| 5 | Same unit as sort gate `0048a060` or qsort `00489f20` | **Falsified** — distinct body; no compare/sort; hub orders fill → sort |
| 6 | Always writes entry `+0x40` | **Falsified** — when flag@+0x20 is 0, only `+0x44=0`; `+0x40` untouched |
| 7 | Related object always required | **Falsified** — wrapper passes `*(controller+0xD0)` which may be null; null arms zero links |
| 8 | Parent decompile is full truth for args | **Falsified** — `FUN_0055e1e0` decompile drops local entry + shows wrong free-call shape; assembly seals 6-arg thiscall |
| 9 | Product name without `_Inferred` | **Fails gate** — no PDB/string for class/method English |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 11 | Inventory / skill hit, not soft-cast interact | **Falsified** — only chain is InteractWorldClickHub soft-cast list path |
| 12 | ECX at wrapper is controller passed through | **Falsified** — wrapper overwrites ECX with local entry; controller fields only supply manager/related |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX entry + RET 0x14 | **Confirmed** | Stack imbalance / wrong this |
| Sole wrapper caller | **Confirmed** | Over-generalize system tag |
| soft_desc flag@+0x20 / field@+0x24 | **Confirmed** | Wrong attach geometry |
| related +0x14 / +0x10 links | **Confirmed** | Broken optional attach |
| manager vtbl+0x30 register | **High** | Wrong iface if slot reused |
| Soft-cast hit-list role | **High** | Mis-tag if hub path misread |
| Query `{1, 0x10}` product meaning | **Low** | Do not invent packet English |
| Entry vtbl `0x009d27a8` method map | **Low** | Partial layout only |
| Product English name | **Inferred** | Doc only until string/PDB |

---

## 3. Cross-check against raw / bytes

```text
raw scaffold 2026-07-23  ≡  live decompile 2026-08-05  ≡  clean named/twin CF

006ca890  PUSH EBP / MOV EBP,ESP / AND ESP,0xFFFFFFF0 / SUB ESP,0x2C
006ca899  MOV EDX,[EBP+0x18]          ; param_6 backref
006ca89c  MOV EAX,ECX                 ; this → EAX
006ca89e  MOV ECX,[EBP+0x0C]          ; soft_desc
006ca8a2  MOV ESI,[EBP+0x10]          ; related
006ca8a7  MOV [EAX+4],ECX             ; entry+4
006ca8aa  MOV [EAX+0xC],EDX           ; entry+0xC
006ca8ad  MOV [EAX+0x10],0
          … related / flag branches …
006ca933  CALL [EDX+0x30]             ; manager vcall
006ca93a  RET 0x14                    ; C2 14 00
pad       CC CC CC

Body: 0x006ca890–0x006ca93b (172 B / 0xAC)
Caller: FUN_0055e1e0 @ 0055e215 only
Hub:    Client_InteractWorldClickHub @ 00925c32 → wrapper; then sort 0048a060
```

Reject ports that:

- Treat this as a free function taking the entry as the first stack argument without ECX thiscall.
- Use bare `RET` / `RET 4` / `RET 8` (must be **`RET 0x14`**).
- Zero or always write entry `+0x40` when soft-desc flag is clear.
- Inline sort/compare (belongs at `0048a060` / `00489f20`).
- Claim runtime Confirmed without Launcher evidence.
- Drop the 16-byte stack alignment if bit-exact native interop is required.
- Trust parent decompile alone for the call shape (must keep local entry + vtbl install).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail soft-cast hit-list core under InteractWorldClickHub list path.
// Port: fill entry from SoftCastDesc + optional related, then manager.Register(query, entry).

sealed class SoftCastHitEntry
{
    public SoftCastDesc Desc;          // retail +0x04
    public IntPtr RelatedPlus14;       // retail +0x08 (0 or related+0x14)
    public SoftCastHitList HitList;    // retail +0x0C backref
    // +0x10 = 0
    public uint DescField24;           // retail +0x40 when flag set
    public IntPtr RelatedPlus10;       // retail +0x44
}

void SoftCastHitList_CoreFillAndRegister(
    SoftCastHitEntry entry,
    SoftCastManager manager,
    SoftCastDesc desc,
    object relatedOrNull,
    uint queryPayload,
    SoftCastHitList hitListBackref)
{
    entry.Desc = desc;
    entry.HitList = hitListBackref;
    entry.Field10 = 0;
    entry.RelatedPlus14 = relatedOrNull == null ? 0 : relatedOrNull.Base + 0x14;

    if (!desc.Flag20)
        entry.RelatedPlus10 = 0;
    else if (relatedOrNull == null) {
        entry.RelatedPlus10 = 0;
        entry.DescField24 = desc.Field24;
    } else {
        entry.RelatedPlus10 = relatedOrNull.Base + 0x10;
        entry.DescField24 = desc.Field24;
    }

    var query = SoftCastQuery.FromDesc(desc, payload: queryPayload, flag: 1, size: 0x10);
    manager.Register(query, entry, zero: 0); // retail vtbl+0x30
}
```

Pair with:

- Wrapper: `FUN_0055e1e0` (local entry vtbl `0x009d27a8`, payload always 0).
- Sort gate: dualed `SoftCastHitList_SortIfCountGt1_Inferred` (`0x0048a060`).
- Resolve: residual `FUN_0040afb0` on post-sort hits.
- Hub: dualed `Client_InteractWorldClickHub` (`0x00925820`).

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/sole-caller/register dispatch. Remaining gaps are product English for vcall/fields + wrapper residual + runtime → **accept-with-gaps**.

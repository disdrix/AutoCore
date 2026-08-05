# Review B (skeptical / adversarial): `aa_00606ff0` Outpost_PreRecastBankWalk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606ff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-C OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__fastcall` / no stack args | Epilogue **`ret 4`**; stack load faction; callers `push [esi+0x234]` | **Falsified** — **thiscall + 1 stack arg** |
| 2 | Is BeaconShare cast itself | No ResolveSkillTargets, no CastSkillOnTarget, no ratio | **Falsified** — side-effect walk only |
| 3 | Processes flag≠0 (Faction polarity) | `cmp byte [entry+0xC],0` / process on **equal** | **Falsified** — flag **==0** only |
| 4 | Applies ratio gate `+0x24c` | No load of `this+0x24c` or entry+8 | **Falsified** — **no ratio** |
| 5 | ResolveObjectTarget mode 1 | `push 0` before call | **Falsified** — mode **0** |
| 6 | vfunc 0x220 second arg 0 (remove) | `push 1` before call | **Falsified** — arg **1** |
| 7 | Many callees | analyze callees = ResolveObjectTarget only | **Confirmed** leaf-of-direct-calls |
| 8 | Only called from ratio update | Second xref CaptureOutpost `00608543` | **Confirmed** two callers |
| 9 | Scaffold “unknown system” | Outpost skill bank offsets + W19-O context | **System = outpost skills** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX + faction + ret 4 | **High** | Wrong port crashes / skips |
| Bank/TFID offsets | **High** | Walks wrong vectors |
| flag==0 polarity | **High** | Opposite bank half |
| No ratio in this VA | **High** | Over-constrain port |
| 0x220(skillId,1) exact product meaning | **Medium** | Wrong side-effect if invent name |
| Order relative to BeaconShare | **High** | Recast without prep |

---

## 3. Cross-check against raw + bytes + callers

```
raw/live decompile:
  faction 0..3; base + faction*0x48
  bank +0xd4; TFID +0xb4; flag==0; Resolve(0); vfunc 0x1ec; vfunc 0x220(id,1)

bytes:
  c2 04 00 epilogue
  80 7d 0c 00 flag test
  e8 → 004bae70 ResolveObjectTarget
  ff 92 ec 01 00 00 / ff 90 20 02 00 00

caller 006078e0 @ 0060799a:
  push faction; call 00606ff0; push faction; call BeaconShare 006070e0

caller 006082e0 CaptureOutpost @ 00608543:
  00606ff0(old faction) among teardown before faction store / FUN_006078e0
```

≡ consistent pre-recast/teardown bank walk, not the cast body.

---

## 4. Surviving contract for AutoCore

```csharp
// When beacon-share ratio changes (or capture teardown):
OutpostPreRecastBankWalk(outpost, factionIndex);
// then Outpost_CastSkillsForBeaconShare / faction cast as retail orders

void OutpostPreRecastBankWalk(Outpost op, int faction)
{
    if (faction < 0 || faction >= 4) return;
    var slot = op.FactionSlot(faction); // + faction*0x48
    foreach (var e in slot.SkillBank)    // +0xd4, stride 0x10
    {
        if (e.Flag != 0) continue;      // +0x0C
        foreach (var tfid in slot.Tfids) // +0xb4, stride 8
        {
            var obj = ResolveObjectTarget(mode: 0, tfid);
            var host = obj?.VFunc_1ec();
            host?.VFunc_220(e.SkillId, 1);
        }
    }
}
```

- Do **not** fold ratio gate or CastSkillOnTarget into this unit.
- Preserve call **before** BeaconShare on ratio change.
- Do not invent free/delete of bank entries here.

---

## 5. Gaps surviving review

1. Product/PDB name.
2. vfunc `+0x220` English (start vs notify vs clear with flag=1).
3. Full CaptureOutpost ordering dual (parent not owned).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF, ABI, bank/TFID layout, flag polarity, mode 0, vfunc chain **sealed**; product English residual.

# Review B (skeptical / adversarial): `aa_006082e0` Outpost_CaptureOutpost

| Field | Value |
|---|---|
| **Stable ID** | `aa_006082e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-D) |
| **Counterpart** | `reviews/A_aa_006082e0_Outpost_CaptureOutpost.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ xrefs/assembly_context). No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function always stores new faction | **Falsified** — requires `new != old`, non-null timer, valid faction range, **and** world `+0x7e` |
| 2 | Missing capturer aborts always | **Falsified** — capturer null still allows path; nearby loop skipped; `00606a70(new, 0)` |
| 3 | Default race 3 is "invalid" | **Falsified as always-invalid** — only logged when `<0` or `>3`; seed 3 is in-range; used when no capturer resolve |
| 4 | This unit **is** CastSkillsForFaction | **Falsified** — calls dualed `0x00606d70`; does not own cast bank walk |
| 5 | Beacon ratio update is optional/debug | **Falsified** — always after successful store (`call 0x006078e0`) |
| 6 | ABI is cdecl / no this | **Falsified** — `mov esi,ecx`; `ret 4` |
| 7 | `"CaptureOutpost"` is only a log tag, not role | **Weakened** — string + sole owner of dualed cast/ratio call sites at capture xrefs seals role |
| 8 | Nearby credit uses outpost faction not capturer race | **Falsified** — filter is `GetRootRaceId == newFaction` (capturer race) |
| 9 | Radius compare is unsquared | **Falsified** — multiplies `+0x218` by itself before distSq compare |
| 10 | Schedule count always from one DAT pair | **Falsified** — `+0x220` selects `d029f4/f8` vs `d029e4/e8` |
| 11 | Parent alias `Named_CalleeOf_CVOGReaction_Dispatch` is product | **Falsified as product name** — superseded |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate order (faction change + timer + world flag) | **High** | false captures / stuck outposts |
| Success callee order | **High** | skill/bank desync |
| thiscall + one stack arg | **High** | ABI crash in ports |
| Product CaptureOutpost role | **High** | wrong domain placement |
| Unresolved helper semantics | **Medium** | missing side effects in rehost |
| capturerCtx concrete type | **Medium** | wrong resolve path |
| Default race=3 product meaning | **Medium** | wrong null-capturer behavior |

---

## 3. Cross-check against raw + bytes

```
seed new=3
resolve capturer race if ctx
maybe clear-old helpers
if new==old OR no timer: return
if new not in [0,3]: log; return
credit nearby same-race in radius
if !world.flag_7e: return
old-bank teardown → new-bank arm → CastSkillsForFaction
store faction → UpdateBeaconShareRatio
arm schedule + timer → post helper
```

Any clean that:

- stores faction without world `+0x7e`, or
- skips `UpdateBeaconShareRatio` after store, or
- treats ECX as non-this, or
- folds CastSkillsForFaction body into this unit,

is **wrong**.

---

## 4. Surviving contract for AutoCore

```c
// Port sketch — outpost capture
void Outpost_CaptureOutpost(Outpost* self, CapturerCtx* ctx) {
  int capturer = 0;
  int newFaction = 3;
  if (ctx) {
    capturer = ctx->ResolveRootObject(/*vtbl+0x210*/);
    if (capturer) newFaction = Object_GetRootRaceId(BaseOf(capturer));
  }
  int old = self->faction; // +0x234
  if (old >= 0 && old < 3) ClearOldFactionSide(old);       // FUN_004cd5f0
  // optional capturer race-byte path...

  if (newFaction == old || self->timerBlob == nullptr) return;
  if (newFaction < 0 || newFaction > 3) {
    Log("Invalid faction in CaptureOutpost = %d", newFaction);
    return;
  }
  Notify(/*FUN_005743e0*/);
  if (capturer) CreditNearbySameRace(self, capturer, newFaction, self->radius);
  if (!WorldFlag7e(self)) return;

  TeardownOldBanks(old);
  ArmNewBanks(newFaction);
  Outpost_CastSkillsForFaction(self, newFaction);
  AttachCapturer(newFaction, capturer ? BaseOf(capturer) : 0);
  self->faction = newFaction;
  Outpost_UpdateBeaconShareRatio(self);
  self->scheduleCount = CountScheduleBank(self->useAltBank);
  self->scheduleCursor = 0;
  self->timerBlob->value = NextCaptureTimer(); // FUN_00607550
  self->timerBlob->tick  = GetTickCount();
  PostCaptureNotify(capturer);                 // FUN_006081b0
}
```

---

## 5. Open questions

1. Exact product names for `FUN_00606820`…`00606a70` bank helpers.
2. What `FUN_00418d70` records (contribution / mission credit / threat?).
3. Whether null-capturer captures with seed race 3 are intentional live paths.
4. Runtime packet/log correlation for a real outpost flip.

**Verdict:** **accept-with-gaps** — CF, ABI, product string, gates, and dualed success callees sealed; helper semantics and runtime remain open.

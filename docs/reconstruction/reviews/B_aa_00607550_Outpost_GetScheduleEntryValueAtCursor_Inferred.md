# Review B (skeptical / adversarial): `aa_00607550` Outpost_GetScheduleEntryValueAtCursor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00607550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ8R-E) |
| **Counterpart** | `reviews/A_aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always throws on OOB | **Falsified** — signed `<0` and `index >= size` return **0**; throw only after in-range gate fails recheck |
| 2 | Mutates outpost / advances cursor | **Falsified** — no stores to self; pure load |
| 3 | Stack formals / RET 4 | **Falsified** — plain `C3`; only ECX this |
| 4 | Returns float (same as twin) | **Falsified** — dword load `8B 44 16 04`; twin at `0x006075b0` is float @+8 |
| 5 | Single global table | **Falsified** — `+0x220` selects `DAT_00d029e0` vs `DAT_00d029f0` |
| 6 | Stride 4 / dword vector | **Falsified** — `SAR …,4` / `SHL ESI,4` → stride **16** |
| 7 | Named_CalleeOf CVOGReaction chain | **Falsified** — sole code xref is CaptureOutpost @ `006085cc` |
| 8 | Name "NextCaptureTimer" product-sealed | **Resisted** — timer arm use is High; English "duration/timer" is **Inferred** only → keep structural name |
| 9 | FUN_00608620 always reachable in normal play | **Resisted** — present for operator[] shape; normal CF soft-returns 0 before recheck when size consistent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Soft OOB → 0 vs throw | **High** | Wrong exception policy / false hard-fail |
| Bank select + cursor | **High** | Wrong schedule bank / wrong slot |
| Field +4 dword | **High** | Wrong timer arm value |
| CaptureOutpost sole caller | **High** | Miss other schedule consumers |
| Product English of +4 | **Medium** | Label only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against twin + parent

- Twin `Outpost_GetPulseXpPercent` (`0x006075b0`): identical prologue (bank/`+0x220`/cursor/`+0x23c`/stride); differs only at load offset (**+8 float** vs **+4 dword**) and zero constant (`g_flZero` vs `0`).
- Parent CaptureOutpost dual already documented `timer[+8] = FUN_00607550()` after `+0x23c = 0` — live assembly context reconfirms.
- Throw helper decompile plate `"invalid vector<T> subscript"` seals pathological path identity without owning that VA.

---

## 4. Surviving contract for AutoCore

```
// Port as pure schedule lookup:
uint32_t Outpost_GetScheduleEntryValueAtCursor(Outpost* self) {
  auto& bank = self->scheduleBankSelect /*+0x220*/
      ? g_ScheduleBankA /*DAT_00d029e0*/ : g_ScheduleBankB /*DAT_00d029f0*/;
  int idx = self->scheduleCursor; /*+0x23c*/
  if (idx < 0) return 0;
  size_t n = bank.size(); // (end-begin)/16
  if ((uint32_t)idx >= n) return 0;
  return bank[idx].field4; // dword at +4; do not advance cursor
}
// Capture path: after cursor=0, timerBlob.field8 = this(); timerBlob.tick = GetTickCount();
// Do NOT treat OOB as throw. Do NOT merge with GetPulseXpPercent (float +8).
// Do NOT invent stack args / RET 4.
```

---

## 5. Verdict

Adversarial CF/ABI attacks fail. Residual is product English of the dword field and bank population — **accept-with-gaps**.

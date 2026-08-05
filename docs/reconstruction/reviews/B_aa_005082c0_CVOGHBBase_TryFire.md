# Review B (skeptical / adversarial): `aa_005082c0` CVOGHBBase_TryFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_005082c0` |
| **VA** | `0x005082c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (machine seal; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_005082c0_CVOGHBBase_TryFire.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + pcode + sibling duals (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** on CF; **High** on **16≠regen**, **period@+0x08**, **−1000@+0x08 = no-fire Continue** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | **16ms is combat regen period** | **Falsified** — static dword at `0x00af19e8` = **16** written as **Remove**; List_Tick tests **`status & 0x10`**; Regeneration writes **3000/5000** at **`+0x08`** |
| 2 | TryFire period field is **`+0x0C`** (SetPeriodAndCounter target) | **Falsified** — machine loads **`[esi+0x08]`** only; never touches `+0x0C` |
| 3 | **`nPeriodMs == -1000` means always ready / always fire** | **Falsified** — `jz` to **Continue** path; **no** OnHeartBeat |
| 4 | Combat pool relies on TryFire −1000 sentinel | **Falsified as TryFire path** — Regeneration: `SetPeriodAndCounter(-1000,true)` → **`+0x0C/+0x10`**, then **`*(+0x08)=3000/5000`**. Interval is elapsed vs **`+0x08`**; −1000 is **RescheduleAfterFire** (`cmp [ecx+0x0C],-1000`) |
| 5 | Dormant still fires OnHeartBeat | **Falsified** — `fDormant` → Inactive(2) only |
| 6 | Due when `elapsed >= period` | **Falsified** — **`ja`** after `elapsed - period` style cmp → **strict `>`** (`nPeriodMs < elapsed`) |
| 7 | Finished portable ABI / no stack out | **Overstated** — **`ret 4`**, stack `pOutStatus`; decomp `unaff_retaddr` is noise |
| 8 | Direct CALL sites to `0x005082c0` | **Falsified as code xrefs** — **DATA-only** vtable slots; List_Tick uses **indirect** `[*obj+8]` |
| 9 | Calls `StampLastFireTime` helper | **Falsified as call** — inlines `mov [esi+0x14], g_dwClientTickMs` |
| 10 | Prior dual “always ready” plate for AutoCore combat pool | **Reject / replace** — pool fires on **elapsed vs real period @ +0x08** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Remove vs period constant collision (16) | **High** | Wrong list remove / fake 16ms regen |
| Period bind **`+0x08`** | **High** | Wire schedule from SetPeriod field (`+0x0C`) |
| **`+0x08==-1000` → suppress fire (Continue)** | **High** | Invent “always fire” combat path |
| Dual-field: Reschedule/sentinel **`+0x0C`**, pulse **`+0x08`** | **High** | Pool never arms / wrong delay token |
| fDormant / cStopped gates | **High** | Stuck inactive or never remove |
| OnHeartBeat return pointer shape | **Probable** | Status corruption if port assumes EAX status dword |
| Who sets `+0x08=-1000` in live types | **Open** | Rare schedule class |

---

## 3. Cross-check against raw / machine

```
if cStopped(+0x20): *out = Remove(16@af19e8); ret4
if nPeriodMs(+0x08) == -1000: *out = Continue(0@b041d0); ret4   // NOT fire
if elapsed > period OR wrap:
  if fDormant(+0x21): *out = Inactive(2@af19e4); ret4
  else OnHeartBeat(vtbl+0x0C); stamp +0x14; *out = *status; ret4
else: *out = Continue; ret4
```

Clean (post-seal) ≡ machine CF. Prior raw plate “always ready” wording for combat pool is **semantic debt** — body still matches “fall through to Continue” for `+0x08==-1000`, but that is **no-fire**, not pool schedule.

---

## 4. Surviving contract for AutoCore

```
TryFire(hb, &status):  // thiscall; ret 4
  if hb.cStopped: status = Remove(0x10 / 16); return
  // pulse period is hb+0x08 (NOT +0x0C sentinel)
  if hb.nPeriodMs == -1000: status = Continue(0); return   // suppress period fire
  elapsed = g_dwClientTickMs - hb.dwLastFireTickMs
  if elapsed > nPeriodMs OR tick wrapped below lastFire:
    if hb.fDormant: status = Inactive(2); return
    status = *OnHeartBeat()
    hb.dwLastFireTickMs = g_dwClientTickMs
    return
  status = Continue(0)

Combat pool (Regeneration):
  +0x0C/+0x10 = -1000 via SetPeriodAndCounter  // Reschedule path
  +0x08 = 3000 or 5000                         // TryFire elapsed gate
  NEVER treat 16 as regen interval
```

---

## 5. Open questions

1. OnHeartBeat return storage (pointer semantics) across HB subclasses.
2. Inventory of types with `+0x08 == -1000`.
3. Whether any status bits besides 0 / 2 / 0x10 are produced by base OnHeartBeat defaults.

**Verdict:** **accept-with-gaps** on CF; **High** on 16≠regen, period@+0x08, −1000@+0x08=no-fire

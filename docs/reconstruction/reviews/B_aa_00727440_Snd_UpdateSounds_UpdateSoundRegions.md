# Review B (skeptical / adversarial): `aa_00727440` Snd_UpdateSounds_UpdateSoundRegions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-Q) |
| **Counterpart** | `reviews/A_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md` |
| **Verdict** | **accept-with-gaps** on sealed CF/ABI; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | cdecl / bare `ret` | Epilogue is `c2 0c 00` | **Falsified** — **stdcall ret 12** |
| 2 | ECX-thiscall only | Body uses stack `param_1` as mgr; callee of 00938380 pushes 3 args | **Falsified** as pure thiscall |
| 3 | Always runs every frame | Gate enable + accum must exceed **0.0005** | **Falsified** as unconditional |
| 4 | This body *is* the hard-kill walker | Hard-kill/regions is nested `FUN_007252d0` | **Falsified as same unit** |
| 5 | Threshold is 0.05 or 1/30 | double @ `aaab78` decodes to **0.0005** | **Falsified** |
| 6 | No critical section | `EnterCriticalSection` / `LeaveCriticalSection` on `+0x3f8` | **Falsified** |
| 7 | Slot table size dynamic only | Fixed walk count **0x30** plus separate count walk | **Nuanced** — both |
| 8 | Plate string is decoration only | Passed to `FUN_00786a00` profiler enter | **Overstated** — real zone name |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |
| 10 | Server-side audio | Sole caller is client tick `00938380` | **Falsified as server** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall ret 0xC ABI | **High** | Wrong wrapper |
| Gate + 0.0005 accum | **High** | Tick rate bugs |
| CS @ +0x3f8 | **High** | Deadlock / races if omitted |
| Nest 007252d0 for regions | **High** | Missing hard-kill |
| Slot 0x30 table @ +0x31c | **High** | Buffer OOB if size wrong |
| Deep volume helper semantics | **Med** | Port approximation |
| Exact product class/method name | **Med** | Naming only |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex entry SEH + enable | **Yes** |
| Epilogue `c2 0c 00` | **Yes** |
| String @ `0x00aa91ac` | **Yes** full UpdateSounds::updateSoundRegions() |
| Double threshold 0.0005 | **Yes** |
| Sole caller 00938380 | **Yes** |
| Nested dual 007252d0 | **Yes** (W18-F sealed) |

**Attack on "this is just a profiler stub":** **Fails** — large 1797 B body with CS + slots.

**Attack on "regions logic is inline here only":** **Fails** — primary regions/hard-kill is nested `007252d0`.

---

## 4. Surviving contract for AutoCore

```
// stdcall ret 0xC
Snd_UpdateSounds_UpdateSoundRegions(mgr, flag, dt):
  if !mgr.enable@+0x258: return
  mgr.accum@+0x6c += dt
  if mgr.accum <= 0.0005: return
  pre(mgr); EnterCS(mgr+0x3f8)
  stamp GetTickCount → +0x3dc
  FUN_00724d70(dt)
  maybe push listener pos/orient via device vtable
  profile "UpdateSounds::updateSoundRegions()"
  FUN_007252d0(flag, accum)   // hard-kill + regions nest
  profile leave
  walk slots [+0x31c) for count@+0x210 and fixed 0x30:
    age, volume/spatialize, fade/restart flags
  FUN_00723290(mgr); device vcall +0x44
  optional re-arm up to 2 channels if +0x30c==0
  mgr.accum = 0; LeaveCS
```

**Falsified port mistakes:**

- Calling as cdecl or thiscall without stack args / wrong cleanup.
- Running every frame without 0.0005 gate.
- Omitting CS around the body.
- Inlining 007252d0 offsets as if they were this function's fields.
- Treating as server/network audio.

---

## 5. Open questions

1. Product class: `UpdateSounds` method vs `CSoundManager::updateSoundRegions`.
2. Full contracts for `004bb5b0` / `004bb3a0` / `0071fc20` (not owned).
3. Runtime timing under real client load.

**Verdict:** **accept-with-gaps** — outer contract safe for client audio map; nested helpers remain residual.

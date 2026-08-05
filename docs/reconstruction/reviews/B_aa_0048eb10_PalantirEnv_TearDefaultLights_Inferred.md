# Review B (skeptical / adversarial): `aa_0048eb10` PalantirEnv_TearDefaultLights_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048eb10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W34-T) |
| **Counterpart** | `reviews/A_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory_bytes` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is login-callback leaf / RecvLogin method | **Falsified** — callers are RebuildDefaultLights + Sector dtor + env reload; no login packet parse |
| 2 | Is light **create** / same as RebuildDefaultLights | **Falsified** — only destroy path; rebuild is `0048f370` which **calls this first** |
| 3 | cdecl / no this | **Falsified** — `mov esi,ecx`; bare `ret` |
| 4 | Tears textures / effect-texture slots `+0xDC/+0xE0` | **Falsified** — only `+0x104/+0x108` (+ optional `+0xC4`) |
| 5 | Symmetric hemi/dir teardown | **Falsified** — dir path only runs `FUN_0074e0d0(0)` first |
| 6 | `FUN_005b3580` called with env this | **Falsified** — bytes set ECX=`[env+0xC4]` before tail-jmp |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tear not create | **Confirmed** | Double-free / skip rebuild prelude |
| Slot identity vs W32-R | **Confirmed** | Wrong light host lifetime |
| Manager at env+4 | **High** | Wrong effect registry this |
| Full product plate of 0074e* | **Medium** residual | Incomplete port of unregister |

---

## 3. Cross-check

```
raw 2026-07-23: if +104: 74e260; dtor1; null; if +108: 74e0d0(0); 74e260; dtor1; null; if +c4: 5b3580
live 2026-07-29: identical CF
bytes: 56 8B F1 ... 8B 4E 04 (mgr) ... E9 → 005b3580; C3
Rebuild 0048f370: first instruction path calls this @ 0048f38d
Sector dtor 00492be0: vtbl → .?AVCVOGEnvironmentSector@@; calls this
Reflect residual 005b3580: if reflect+0x150: 74e260(that)
```

---

## 4. Surviving contract for AutoCore

```
PalantirEnv_TearDefaultLights(env):
  mgr = env->auxAt4
  destroy light pair at +0x104 / +0x108 (dir clears mgr attach first)
  if env->reflectAt_C4: Reflect_TearSlot150(reflect)
```

Port as **env method** paired with `PalantirEnv_RebuildDefaultLights_Inferred`. Do **not** merge into rebuild body. Reject login-callback naming.

---

## 5. Open questions

- Exact product semantics of `FUN_0074e260` list removal vs refcount.
- Whether Reflect notify is always required when `+0xC4` is non-null during light rebuild (cold on first InitPhases before phase alloc — W32-R note).

**Verdict:** **accept-with-gaps**

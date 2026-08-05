# Review B (skeptical / adversarial): `aa_0074e910` AnimSlot_SetTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-J) |
| **Counterpart** | `reviews/A_aa_0074e910_AnimSlot_SetTime.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Bare `ret` / no stack cleanup | Epilogue is `c2 08 00` | **Falsified** if claimed bare ret |
| 2 | Always clamps | Mode `+0x4c != 0` takes `_CIfmod` | **Falsified** |
| 3 | Always wraps | Mode 0 is clamp path | **Falsified** |
| 4 | Physics / vehicle / drive math | Call graph is visual anim load/select | **Falsified** |
| 5 | Mission CompleteCount helper | Different subsystem entirely | **Falsified** |
| 6 | Mutates only `+0x44` | Also `+0x40`, `+0x34`, `+0x50`, `+0x68`, `+0x6c` | **Falsified** |
| 7 | `+0x34 = time` | Formula is `param_3 - time/rate` | **Falsified** |
| 8 | Ctor flag always clamp | Ctor sets `+0x4c = 1` (wrap default) | **Falsified** if claimed clamp default |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |
| 10 | Product name sealed as SetTime | Structural only | **Overstated** if claimed PDB-sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body bytes / `ret 8` | **High** | Wrong ABI wrappers |
| Clamp vs wrap split | **High** | Looping anim bugs |
| Rate division at `+0x3c` | **High** | Wrong remaining |
| Zeroing `+0x50`/`+0x68` | **High** | Stale-cache ports miss clears |
| Product identifier spelling | **Low–Med** | Naming only |
| Must-port for sector combat sim | **High reject** as mandatory combat math | Client visual |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex length 179 | **Yes** via `read_memory` |
| `g_flZero` @ `0x00a0f518` is `0.0f` | **Yes** |
| Load dual calls with `(0, dur)` | **Yes** (`Object_LoadOrReplaceAnimSlot`) |
| Ctor size `0x78` + default wrap | **Yes** (`FUN_0074ed90`) |
| 16 xrefs | **Yes** |

**Attack on “fmod path is dead”:** **Fails** — ctor defaults `+0x4c=1`; wrap path is hot for default slots.

**Attack on “param_3 unused after store”:** **Fails** — feeds `+0x34` formula.

**Attack on “clean invents std::fmod vs _CIfmod”:** **Accept residual** — clean uses library fmod as behavioral stand-in; retail is MSVC `_CIfmod` FPU helper. CF algebra sealed; bit-identical float path not claimed.

---

## 4. Surviving contract for AutoCore

```
// thiscall slot; two floats; ret 8
// if mode==0: time = clamp(time, 0, length)
// else: time = wrap_fmod(time, length)  // negative → +length
// remaining = endOrDuration - time/rate
// clear +0x50, +0x68; +0x6c = time
```

**Falsified port mistakes:**

- Using bare `ret` or `ret 4`.
- Ignoring mode byte / always clamp.
- Skipping zero of `+0x50`/`+0x68`.
- Treating as mission or physics core.
- Conflating with getter/setter at `0x0059d890`.

---

## 5. Open questions

1. Product name / PDB.
2. English labels for `+0x34` / `+0x40` / cache fields.
3. Whether any caller relies on pre-flag wrap when load sets `+0x4c` after call.
4. Runtime / bit-exact.

**Verdict:** **accept** — time worker CF sealed; spelling + float-helper residual non-blocking.

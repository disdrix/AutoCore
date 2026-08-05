# Review B (skeptical / adversarial): `aa_00724870` CSoundManager_ProbeSoundFileExists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00724870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-M) |
| **Counterpart** | `reviews/A_aa_00724870_CSoundManager_ProbeSoundFileExists_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function opens/plays the sound | **Falsified** — existence only; no play call |
| 2 | Pure stdcall with path on stack | **Falsified as sole ABI** — path is **EAX**; 3 stack args + `RET 0xC` |
| 3 | `outPath` receives rooted full path on search hit | **Falsified** — success copies **`local_208`** (input+ext), not `local_104` |
| 4 | Always hits disk | **Falsified** — gated by cfg bit0; fallback path may skip FS |
| 5 | Root table is static strings in image | **Falsified for content** — BSS zeros at `DAT_00d1e574` in static read; runtime-filled |
| 6 | `param_1` unused (decompiler phantom feel) | **Falsified** — this → `FUN_00722790` ECX |
| 7 | Product name / kind=2 meaning proven | **Sustained as gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX path + RET 0xC | **Confirmed** | Wrong ABI → crash / silent fail |
| Extension append | **High** | Wrong file suffix in probes |
| Root stride 0x1c / end | **Confirmed** | OOB or missed roots |
| outPath = local_208 only | **Confirmed** | Wrong if automation expects absolute rooted path |
| Fallback semantics | **Medium** | Dual of `007b66c0` still open |
| Kind enum | **Open** | Mis-map wire/UI state |

---

## 3. Cross-check against raw + bytes

```
strcpy(buf, EAX_path)
AppendOgg(this, buf)
if cfg.bit0:
  if PathFileExists(buf) goto ok
  for root in roots[0x1c]:
    if PathFileExists(root+basename(buf)) goto ok
if !Fallback(cfg): return 0
ok:
  if outPath: strcpy(outPath, buf)
  if outKind: *outKind = 2
  return 1
```

Clean must **not** invent play, network fetch, or rewriting outPath to rooted trial path.

---

## 4. Surviving contract for AutoCore

```c
// Client-only path probe. Server need not port unless simulating client FS layout.
bool ProbeSoundFileExists(SoundHost* self, char* outPathOpt, int* outKindOpt, const char* path);
// success ⇒ outKindOpt ? *outKindOpt = 2 : void
```

Use for DevTool / automation only if mirroring client search roots + ogg suffix rules.

---

## 5. Open questions

1. Product symbol and kind-`2` English.
2. Root table population site.
3. Exact fallback object behind `cfg+0xc` / `vtbl+0x14`.
4. Interaction when `self+0x308` selects `_lxx.ogg`.

**Verdict:** **accept-with-gaps**

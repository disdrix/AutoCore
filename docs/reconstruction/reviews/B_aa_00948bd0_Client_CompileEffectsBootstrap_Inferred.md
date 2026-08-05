# Review B (skeptical / adversarial): `aa_00948bd0` Client_CompileEffectsBootstrap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00948bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-H) |
| **Counterpart** | `reviews/A_aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md` |
| **Scratch** | `tmp/a_00948bd0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is normal game client init | **Falsified** — only called for `-compileeffects`; main init is `FUN_0094a6a0` |
| 2 | Name should be Drive_NDRiver_fx | **Falsified** — single FX string plate; purpose is full bootstrap + 36 FX |
| 3 | ECX/thiscall self | **Falsified** — ESI host; bare C3; no stack formals |
| 4 | Shows main game window | **Falsified** — `ShowWindow(hwnd, 0)` hides; 32×32 stub size |
| 5 | Skips AssManager | **Falsified** — calls sealed `FUN_007b75b0` mode=1 |
| 6 | Multiple callers | **Falsified** — xref_count=1 |
| 7 | Unreachable blocks are main CF | **Falsified** — SEH string-dtor cleanup only |
| 8 | Product PDB name sealed | **Careful** — `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| -compileeffects sole path | **High** | Wrong lifecycle port |
| Stage order | **High** | Missing init deps |
| ESI offsets +0xde8/+0x3180/+0x3188 | **High** | Corrupt host |
| Nested render/FX English | **Med** | Partial port |
| Product name | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0094ba40:
if strstr(cmd, "-developer") == null: return 0
...
if strstr(cmd, "-compileeffects"):
  FUN_00948bd0()   // this unit
  CloseHandle(mutex)
  _exit(0)
// else: normal Client_InitInstance path
```

Live decompile ≡ raw scaffold for CF. Entry `new(0x2ec)` and epilogue `C3` sealed.

---

## 4. Surviving contract for AutoCore

```
// Port as offline compile-effects bootstrap ONLY:
//   not Client_InitInstance
//   AssManager_Init(mode=1) → tiny hidden AA window → RenderEngine → load fixed 36 FX list
//   process exits after (caller)
// Do not rename from a single .fx string.
// Pair with W30-D AssManager dual for resolver/precompile side effects (pack opens).
```

---

## 5. Verdict

Adversarial pass confirms A on caller context, ABI, stages. Nested product residual → **accept-with-gaps**.

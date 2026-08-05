# Review B (skeptical / adversarial): `aa_00948530` Client_InitRenderEngine

| Field | Value |
|---|---|
| **Stable ID** | `aa_00948530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-Q) |
| **Counterpart** | `reviews/A_aa_00948530_Client_InitRenderEngine.md` |
| **Scratch** | `tmp/a_00948530.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Only "Could not get Palantir desktop window" setup | **Falsified** — full window/class/RenderEngine path; Palantir is late stage |
| 2 | stdcall / stack `this` | **Falsified** — ECX app; bare RET; InitInstance calls as thiscall |
| 3 | Success returns 1 | **Falsified** — success `xor eax,eax` → **0**; fail **`0x80004005`** |
| 4 | Table-only / asset loader | **Falsified** — CreateWindow + RenderEngine + Palantir factory |
| 5 | Multi static callers | **Falsified** — sole CODE xref from `Client_InitInstance` |
| 6 | `FUN_007a3e90` return 0 = success | **Falsified** — 0 → fail string; non-zero continues; 2 → SetWindowPos path |
| 7 | Decompiler noreturn kills function at first `operator_delete` | **Falsified** — bytes continue to `FUN_0040d9c0` and tails (same class of Ghidra bug as W30-P) |
| 8 | Scaffold Named_Could_not_get_Palantir_* is product demangle | **Reject as sole plate** — string is one fail path; product banners name InitRenderEngine |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Window/class/render stage order | **High** | Wrong boot port |
| Returns 0 / E_FAIL | **High** | Inverted success check vs InitInstance |
| Sole caller hard-exit contract | **High** | Soft-fail misport |
| Palantir + `FUN_004cda90` wiring | **High** | Broken desktop bundle |
| Flag English `+0x9c1` etc. | **Low** | Naming only |
| Nested helper bodies | **Med** | Residual on other OWN VAs |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Client_InitInstance:
FUN_007a4400("@@InitRenderEngine");
FUN_007a4480(-1, "InitRenderEngine");
if (FUN_00948530(app) != 0) {
  FUN_007a4480(1, "Failed to initialize your graphics card, exiting...");
  _exit(1);
}
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Entry/epilogue hex seals frame ABI. Xrefs: 1 caller.

---

## 4. Surviving contract for AutoCore

```
// Port as InitRenderEngine orchestrator (not Palantir-only):
HRESULT Client_InitRenderEngine(ClientApp* app) {
  // monitors → RegisterClass("XutoAssault") → CreateWindow("Auto Assault")
  // → RenderEngine(aa.bmp) → optional table rewrite → Palantir bundle
  // → subsystem hooks
  // return S_OK (0) or E_FAIL (0x80004005)
}
// Caller MUST treat nonzero as fatal graphics init failure.
// Do not invent product names for nested helpers without their duals.
```

---

## 5. Verdict

Adversarial pass confirms A on stages/ABI/returns/caller. Nested product residual → **accept-with-gaps**.

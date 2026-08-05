# Review A (reconstruction fidelity): `aa_00948530` Client_InitRenderEngine

| Field | Value |
|---|---|
| **Stable ID** | `aa_00948530` |
| **VA** | `0x00948530`–`0x00948ba7` (**1656 B**) |
| **Canonical name** | `Client_InitRenderEngine` |
| **Ghidra name** | `FUN_00948530` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-Q) |
| **Counterpart** | `reviews/B_aa_00948530_Client_InitRenderEngine.md` |
| **System** | client boot / window + render + Palantir |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry+epilogue) + xrefs + InitInstance caller context. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Orchestrate main window creation, RenderEngine init, optional table rewrite, Palantir view bundle, and success-path subsystem hooks for the client app.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-Q append) | `docs/reconstruction/raw/aa_00948530_FUN_00948530.md` |
| Annotated | `docs/reconstruction/raw/aa_00948530_FUN_00948530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InitRenderEngine.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00948530.cpp` |
| Function record | `docs/reconstruction/functions/aa_00948530_Client_InitRenderEngine.md` |
| Caller | `Client_InitInstance` banners + hard-fail on nonzero |
| Nested | `Client_InitPalantirViewBundle` W30-F dual sealed |

---

## 3. Signature (sealed)

```c
// ECX = client app; bare RET; 0 success / 0x80004005 E_FAIL
uint32_t __fastcall Client_InitRenderEngine(void* app);
```

| Formal | Source | Conf |
|---|---|---|
| app | ECX (`8B F9` after prologue) | **High** |
| return | EAX 0 / `0x80004005` | **High** |
| cleanup | bare `C3` (frame leave) | **High** |

---

## 4. Control flow (sealed stages)

| # | Stage | Evidence | Conf |
|---|---|---|---|
| 1 | Monitor enum → table stride 0xC | `EnumDisplayMonitors` + `(end-begin)/0xC` | **High** |
| 2 | Clamp index `+0xa14`; build rect `+0x3190` | decompile | **High** |
| 3 | `RegisterClassA` / `CreateWindowExA` strings | product strings | **High** |
| 4 | Style WS_POPUP vs `DAT_00ca0000` by `+0x9c1/+0x9c2` | decompile | **High** |
| 5 | `FUN_007a3e90` codes 0 fail / 2 repos | string + `SetWindowPos` | **High** |
| 6 | Optional `DAT_00d1f050` rewrite | decompile; ignore false-noreturn | **High** |
| 7 | Palantir stamp + `FUN_004cda90` | W30-F + decompile | **High** |
| 8 | Success if desktop `+0x2c`; else fail string | decompile | **High** |
| 9 | Fail log `FUN_007a4480(1,msg)` → E_FAIL | decompile | **High** |

---

## 5. Gaps

- Product C++ class for app host / flags English.
- Nested `FUN_007a3e90` / success-path helper full plates (other waves).
- WndProc `LAB_009484d0` (not owned).
- Full 1656 B hex dump not re-emitted (entry+epilogue sealed; body large — CF from live decompile ≡ raw).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Stage map, ABI, returns, strings, sole-caller hard-fail contract sealed. Nested product English open → **accept-with-gaps**.

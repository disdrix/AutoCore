# Review A (reconstruction fidelity): `aa_00948bd0` Client_CompileEffectsBootstrap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00948bd0` |
| **VA** | `0x00948bd0`–`0x009492c7` (**1784 B**) |
| **Canonical name** | `Client_CompileEffectsBootstrap_Inferred` |
| **Ghidra name** | `FUN_00948bd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-H) |
| **Counterpart** | `reviews/B_aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md` |
| **System** | client / -compileeffects |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry/epilogue) + sole-caller decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Offline `-compileeffects` bootstrap: helper alloc, AssManager init (mode=1), create/hide AA window, render engine init, preload 36 `.fx` shaders.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-H append) | `docs/reconstruction/raw/aa_00948bd0_FUN_00948bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00948bd0_FUN_00948bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CompileEffectsBootstrap_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md` |
| Related | W30-D AssManager init; W31-H AssPackManager open (nested via AssManager) |
| Live | decompile ≡ CF; entry/epilogue hex; caller `FUN_0094ba40` |

---

## 3. Signature (sealed)

```c
// ESI = client host; bare C3; void
void Client_CompileEffectsBootstrap_Inferred(void* self /*ESI*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | ESI (`89 86 E8 0D 00 00` store +0xde8) | **High** |
| cleanup | bare `C3` @ `0x009492c7` | **High** |

---

## 4. Control flow (bytes + decompile authority)

```
SEH LAB_009bbb53
helper = new(0x2ec)+ctor → self+0xde8
mgr = AssManager_get; mgr.flags(+4)=3
AssManager_InitPrecompileAndResolvers(mgr, mode=1)
RegisterClassA("XutoAssault"); CreateWindowExA(... "Auto Assault" ...) → self+0x3188
if !hwnd: log CreateWindowEx fail; return
UpdateWindow; RenderEngine_init(hwnd, 24x32-ish)
if fail: log RenderEngine fail; return
ShowWindow(hwnd, 0)
for 36 fx: FUN_00989e00(slot, name); FUN_009701d0(slot)
return
```

| Stage | Match | Conf |
|---|---|---|
| Helper @ +0xde8 | decompile ≡ entry bytes | **High** |
| AssManager mode=1 | decompile ≡ W30-D dual | **High** |
| Window strings/style | decompile ≡ bytes | **High** |
| 36 FX pairs | decompile count | **High** |
| Sole -compileeffects caller | `FUN_0094ba40` decompile | **High** |

---

## 5. Machine bytes

- Entry @ `0x00948bd0`: `55 8B EC 83 E4 F8 6A FF 68 53 BB 9B 00` … `68 EC 02 00 00` (new 0x2ec).
- Epilogue @ `0x009492c7`: `C3`; pad `CC`.
- Full 1784 B hex omitted (large); entry/epilogue + decompile seal stages.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (tool bootstrap) |
| Callers | `FUN_0094ba40` ×1 under `-compileeffects` |

---

## 7. Gaps

- Product English for `FUN_007a26c0` (0x2ec), `FUN_007a3e90`, FX loaders.
- Exact dim argument layout for render init (local_cc/local_d0 order).
- Runtime / bit-exact.

---

## 8. Verdict

Caller context + multi-stage CF sealed. Nested render/FX product residual → **accept-with-gaps**.

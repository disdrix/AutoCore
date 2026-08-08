# Review B (skeptical / adversarial): `aa_00759de0` gfxUIWindow_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00759de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-F) |
| **Counterpart** | `reviews/A_aa_00759de0_gfxUIWindow_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a scalar-deleting dtor | **Falsified** — no flags arg; installs vtbl; large free chain; no free of `this` |
| 2 | This is a vector-deleting dtor | **Falsified** — no array count / no host `operator_delete[]` |
| 3 | cdecl / stack this | **Falsified** — entry `MOV ESI,ECX` |
| 4 | Frees host heap | **Falsified** — bare `RET` (`C3`); host free is scalar peer `0x004401b0` only |
| 5 | `operator_delete` is noreturn / body ends at first delete | **Falsified** — disasm + epilogue continue through children assert, residual EH, `RET` |
| 6 | Product name is CNDUIWindow | **Falsified** — RTTI `.?AVgfxUIWindow@@`; CNDUIWindow *calls* this as super-base |
| 7 | Same unit as `FUN_00797d70` | **Falsified** — different ABI/shape; layout helper is owned block free |
| 8 | Children vector free always skips assert | **Falsified** — non-empty path always calls `FUN_0076d1b0` per child |
| 9 | Scaffold `Named_gfxUIWindow` is wrong class | **Falsified as class** — string+RTTI agree on **gfxUIWindow**; scaffold *address suffix* retired in favor of `*_CompleteDtor` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar/vector | **High** | Double-free / miss free |
| Vtbl + RTTI product name | **High** | Naming residual closed |
| False-noreturn correction | **High** | Truncated port |
| Slot product English | **Open** | Residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_00759de0 (gfxUIWindow complete):
// SEH; ESI = ECX
mov  dword ptr [ESI], 00a9f304h
; clear multiple tree shells + vectors + refcount
; children vector assert path (gfxUIWindow.cpp:0x73)
; EH residual member teardown + nested vtbl 00a9db18 @ +0x30
; SEH restore; add esp,20h; ret
```

Live decompile 2026-08-05 truncates at early `operator_delete` warnings; **disasm + `read_memory` epilogue** seal full body.  
`read_memory` COL `@0x00a9f300` → `0x00ab96a4` → type_info `0x00afe190` → `.?AVgfxUIWindow@@`.  
`vtbl[0]` dword `@0x00a9f304` = `0x004401b0` (scalar peer).

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor only (not scalar):
void gfxUIWindow_CompleteDtor(void* self) {
  *(void**)self = &PTR_FUN_00a9f304;
  // tear shells/vectors/refcount
  // assert+clear children @ +0x94
  // nested mid-dtor @ +0x30
}
// Do NOT operator_delete(self) here.
// Scalar peer: 0x004401b0
// Derived chains: CNDUIWindow_CompleteDtor → this
```

---

## 5. Verdict

**accept-with-gaps** — adversarial claims against complete-dtor role, ABI, RTTI name, and false-noreturn truncation are falsified. Residual: helper English, runtime.

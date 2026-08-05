# Review A (reconstruction fidelity): `aa_00968720` GfxBufferedViews_RecreateRenderTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968720` |
| **VA** | `0x00968720`–`0x00968831` exclusive (**273 B** / `0x111`) |
| **Canonical name** | `GfxBufferedViews_RecreateRenderTargets_Inferred` (was `FUN_00968720`) |
| **Review date** | `2026-08-04` (W38-AA) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00968720_GfxBufferedViews_RecreateRenderTargets_Inferred.md` |
| **System** | palantir/graphics — gfxBufferedView list / Device Reset rebuild |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + function/xref helpers + `get_assembly_context` sole call site. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: `GfxDevice_Reset` (W37-N), release twin `0x009686e0`, unowned ReCreate `FUN_0096cad0`.

---

## 1. Purpose

**List-level render-target ReCreate** for all registered **gfxBufferedView** instances during **Device Reset rebuild**:

1. SEH frame; walk `DAT_00d1ee30`.
2. For each view with `*(tex+0x30)==0` (`tex=*(view+0x44)`):
   - If `!(*(tex+0x2c) & 0x3000)`: `FUN_0096cad0` ReCreate; on `<0` log product failure string at `gfxBufferedView.cpp:0xCA`.
   - Else: COM-style `Release` on `*(tex+0x4c)` (`vtbl[+8]`).
3. Always return **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-AA append) | `docs/reconstruction/raw/aa_00968720_FUN_00968720.md` |
| Annotated | `docs/reconstruction/raw/aa_00968720_FUN_00968720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBufferedViews_RecreateRenderTargets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00968720.cpp` |
| Live | decompile ≡ CF; full 273 B hex; strings @ `00aa22c8` / `00aa2318`; call site `0075f2d9` |
| Parent plate | `"Failed to Reset() device on gfxBufferedViews"` @ `00a9e120` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
int32_t GfxBufferedViews_RecreateRenderTargets_Inferred(void); // always 0
// SEH LAB_009b11e5; plain RET after ADD ESP,0x2C
```

| Item | Evidence |
|---|---|
| Return | `XOR EAX,EAX` before epilogue — **always 0** |
| Formals | none |
| Body range | entry `00968720`, last `C3` @ `00968830` |
| Xrefs | **1** call site |

---

## 4. Control flow (sealed)

```
SEH + head/node = DAT_00d1ee30 list
for each payload view:
  tex = *(view+0x44)
  if *(tex+0x30) != 0: continue
  if (*(tex+0x2c) & 0x3000) == 0:
    hr = FUN_0096cad0(tex, fields +0x24/+0x1c/+0x20/+0x34/+0x30/+0xc)
    if hr < 0:
      name = FUN_0096a630(tex+0x4c or DAT_00d1ed24)
      sprintf Failure on ReCreate... %s ...
      vog_LogMessage(gfxBufferedView.cpp, 0xCA, 5, msg)
      ~string
      // continue — no return -1
  else:
    (*(IUnknown**)(tex+0x4c))->Release()
return 0
```

---

## 5. Gaps (explicit)

- Product English for flags `0x3000` and full texture field map.
- Nested `FUN_0096cad0` / `FUN_0096a630` duals open.
- Parent `<0` fail plate is **unreachable** from always-0 return (design/history residual).
- Runtime / bit-exact / differential.

---

## 6. Verdict rationale

**accept-with-gaps:** List role, rebuild placement, ReCreate vs special Release branch, product log plates, and always-0 return are sealed. Residuals are nested helper English and dead parent fail path — not blocking the sealed contract.

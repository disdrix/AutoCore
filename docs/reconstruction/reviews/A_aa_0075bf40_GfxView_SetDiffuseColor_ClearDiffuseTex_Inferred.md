# Review A (reconstruction fidelity): `aa_0075bf40` GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075bf40` |
| **VA** | `0x0075bf40`–`0x0075bf95` (**85 B**) |
| **Canonical name** | `GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred` (was `FUN_0075bf40`) |
| **Review date** | `2026-08-04` (W37-L) |
| **Reviewer role** | Reconstruction fidelity (GfxView color set + DiffuseTexture clear) |
| **Counterpart** | `reviews/B_aa_0075bf40_GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.md` |
| **System** | GfxView / material color worker |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers + string `read_memory` @ `0x00a9ede4`. **No** `disassemble_bytes`. Context-only: `FUN_00752370`, `FUN_00970060`, caller `FUN_004c0a90` / `FUN_004c1960`.

---

## 1. Purpose

Set a packed color on a GfxView-like object (`+0x148`), mark dirty (`+0x129=1`), and if an effect exists at `+0x134`, clear the bind for the parameter named **`DiffuseTexture`**. Always returns 0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075bf40_FUN_0075bf40.md` |
| Annotated | `docs/reconstruction/raw/aa_0075bf40_FUN_0075bf40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075bf40.cpp` |
| Function records | `functions/aa_0075bf40_*.md` |
| Live Ghidra | decompile + full 85 B hex; string `"DiffuseTexture\0"` |
| Callers | `0x808080` init path; `0` clear path |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// __thiscall — ECX = GfxView*; one stack arg; ret 4; always 0
int GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred(void *self, uint32_t color);
```

| Item | Evidence |
|---|---|
| Convention | `XOR EAX,EAX; POP EDI; POP ESI; POP ECX; RET 4` |
| Effect field | `MOV ECX,[EDI+0x134]`; null → index -1 |
| String | `PUSH 0x00a9ede4` → `"DiffuseTexture"` |
| Color store | `MOV [EDI+0x148], color` |
| Dirty | `MOV byte [EDI+0x129], 1` |
| Xrefs | **11** sites / **8** caller functions |

---

## 4. Control flow (sealed)

```
EDI = this
if *(this+0x134) == 0:
  index = -1
else:
  ESI = this+0x134
  FUN_00752370(effect, &index, "DiffuseTexture")
if index >= 0:
  FUN_00970060(index, 0)
*(this+0x148) = color
*(u8*)(this+0x129) = 1
return 0
```

---

## 5. Confirmations

1. Always writes color + dirty even when effect is null / index miss.  
2. Clear only when index ≥ 0.  
3. Call-site colors are packed RGB-like immediates (`0x808080`, `0`).  
4. Decompiler's `local_4 = param_1` on non-null path is **false** (bytes).

---

## 6. Residual gaps

1. Packed color format (ARGB/RGB order).  
2. Exact clear semantics of `FUN_00970060(index,0)`.  
3. Product method English beyond string-backed inference.  
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — short body fully sealed by bytes + string; residual gaps are product format / unowned clear helper.

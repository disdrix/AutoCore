# Review A (reconstruction fidelity): `aa_004941b0` Host_RebuildElem0x28ArrayFromMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004941b0` |
| **VA** | `0x004941b0`–`0x00494304` exclusive (**341 B** / `0x155`) |
| **Canonical name** | `Host_RebuildElem0x28ArrayFromMap_Inferred` |
| **Ghidra name** | `FUN_004941b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-Q) |
| **Counterpart** | `reviews/B_aa_004941b0_Host_RebuildElem0x28ArrayFromMap_Inferred.md` |
| **System** | host / cookie-vector rebuild from map dims |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (body + float globals + string + caller `0x004ac100`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Free existing 0x28-stride cookie-vector at `host+0x28`, then rebuild sized from map extents at `*(mapCtx+0xe4f8)` with scale 64.0f or 32.0f selected by `mapCtx+0xf5`. Element ctor/dtor pair `FUN_005b7db0` / `FUN_005b8000`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-Q) | `docs/reconstruction/raw/aa_004941b0_FUN_004941b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004941b0_FUN_004941b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Host_RebuildElem0x28ArrayFromMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004941b0.cpp` |
| Function records | `functions/aa_004941b0_FUN_004941b0.md`, `functions/aa_004941b0_Host_RebuildElem0x28ArrayFromMap_Inferred.md` |
| Element dtor | `Elem0x28_CompleteDtor` (W29-F) |
| Element ctor | `FUN_005b7db0` (zeros element fields) |
| Live | decompile ≡ raw; body 341 B; `RET 4`; floats 64/32; caller bytes seal ECX/stack |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=host; stack mapCtx; RET 4; void
void __thiscall Host_RebuildElem0x28ArrayFromMap_Inferred(void* host, void* mapCtx);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX | **High** |
| mapCtx | stack (cleaned by RET 4) | **High** |
| return | void | **High** |

### Caller ABI (`FUN_004ac100` @ `0x004ac12e`)

```
eax = *[caller_this + 0x340]   // mapCtx
ecx = *[eax + 0xe898]          // host pointer
push eax
call FUN_004941b0
```

---

## 4. Control flow (clean ≡ raw)

```
SEH LAB_009a0bbb
free cookie-vec @ host+0x28 (stride 0x28, dtor FUN_005b8000); host+0x28=0
if *(mapCtx+0xe4f8)==0:
  FUN_007a4480(0, "VOG_DEBUG_STOP"); RET 4
scale = 64.0f; if *(char*)(mapCtx+0xf5)==0: scale = 32.0f
  (via DAT_00aefa50 ← DAT_00a11088 / DAT_00aaa8a4)
map = *(mapCtx+0xe4f8)
host+4 = ROUND((float)map[+0x10]/scale * map[+0x18]) + 1
host+8 = ROUND((float)map[+0x14]/scale * map[+0x18]) + 1
count = (host+8)*(host+4)
raw = new[](count*0x28+4); cookie=*raw=count; storage=raw+1
eh_vector_ctor_iter(storage, 0x28, count, FUN_005b7db0, FUN_005b8000)
host+0x28 = storage
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Free arm | **Yes** | **High** |
| Null-map assert | **Yes** (string @ `0x00a15844`) | **High** |
| Scale 64/32 | **Yes** (`read_memory`) | **High** |
| ROUND dims +1 | **Yes** (decompile) | **High** |
| Cookie new + ctor | **Yes** | **High** |
| Body size / RET 4 | **Yes** (004941b0–00494304) | **High** |
| Caller host/mapCtx | **Yes** (call-site bytes) | **High** |

---

## 5. Gaps

- Product English for host / mapCtx / map row (`+0xe4f8` object).
- Semantic of `mapCtx+0xf5` beyond scale branch.
- Meaning of map ints `+0x10/+0x14` and float `+0x18`.
- Early-exit does not zero `host+4/+8` after free (stale dims possible).
- Runtime / bit-exact / differential.

---

## 6. Verdict

CF/ABI/formula/constants/caller sealed. Residual product types and flag English → **accept-with-gaps**.

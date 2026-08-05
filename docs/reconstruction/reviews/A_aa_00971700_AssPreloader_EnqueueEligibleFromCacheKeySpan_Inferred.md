# Review A (reconstruction fidelity): `aa_00971700` AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971700` |
| **VA** | `0x00971700`–`0x00971795` (**150 B**) |
| **Canonical name** | `AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred` |
| **Ghidra name** | `FUN_00971700` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-M) |
| **Counterpart** | `reviews/B_aa_00971700_AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 150 B) + `get_function_by_address` + `analyze_function_complete` + `disassemble_function` listing; 0 xrefs; callees W31-K / W32-G sealed |
| **Verdict** | **accept** |

**Tools:** decompile + `read_memory` + function helpers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

AssPreloader host method: snapshot a linear dword key span from the resource-cache context (`*(*(host+0x110)+0x64)` → `+0x50`/`+0x54`) into a local GuardedVector, enqueue eligible keys via sealed `AssPreloader_EnqueueEligibleFromRing_Inferred`, destroy local, return 0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971700_FUN_00971700.md` (+ W33-M append) |
| Annotated | `docs/reconstruction/raw/aa_00971700_FUN_00971700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971700.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971700_FUN_00971700.md` |
| Named record | `docs/reconstruction/functions/aa_00971700_AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.md` |
| Live | decompile ≡ CF tree; full 150 B hex; listing; sole known InsertRange caller |

---

## 3. Signature (sealed)

```c
// ECX = AssPreloader* host; bare RET; returns 0
uint32_t AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred(void* host /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV ESI,ECX`) | **High** |
| cleanup | bare **`RET`** | **High** |
| return | **EAX = 0** (`XOR EAX,EAX`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH install (LAB_009afe03)
local GuardedVector zeroed
ctx   = *(*(host+0x110)+0x64)
first = *(ctx+0x50); last = *(ctx+0x54)
FUN_0043df90(...)                              // erase/init local
GuardedVector_InsertRange(local, …, first, last, …)  // 6 stack formals
AssPreloader_EnqueueEligibleFromRing(host, local)    // ESI=local
FUN_005b2ba0(local)
return 0
```

| Stage | Match | Conf |
|---|---|---|
| ECX host + ESI preserve | **Yes** | **High** |
| Cache ctx path +0x110/+0x64 | **Yes** | **High** |
| Span +0x50/+0x54 as pointers | **Yes** (pushed as InsertRange first/last) | **High** |
| InsertRange sole-caller link | **Yes** (W32-G) | **High** |
| EnqueueEligible ESI/stack ABI | **Yes** (W31-K) | **High** |
| No dep-expand call | **Yes** (no `00744360`) | **High** |
| Product English | inferred | **Inferred** |
| Static callers | **none** | **Open** (orphan) |

---

## 5. Machine bytes (`read_memory`)

Full 150 B hex: see raw W33-M append.

Key sites:

| Site | Meaning |
|---|---|
| `8B F1` | host ← ECX |
| `8B 86 10 01 00 00` / `8B 40 64` | cache → ctx |
| `8B 78 54` / `8B 58 50` | last / first |
| `E8` → `0043df90` / `0044e1c0` / `00971640` / `005b2ba0` | callees |
| `33 C0` … `C3` | return 0; bare RET |

---

## 6. Gaps

- Product/PDB English for cache-ctx object and span fields.
- Zero static xrefs — dead, dynamic, or unlinked residual.
- Nested `FUN_0043df90` / `FUN_005b2ba0` dual ownership elsewhere.
- Runtime / bit-exact.

---

## 7. Verdict

Host ABI, span snapshot, InsertRange→EnqueueEligible→destroy pipeline, and full 150 B body sealed from live decompile + `read_memory` + family callee seals → **accept** (orphan-xref residual documented, not blocking).

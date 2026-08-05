# Review A (reconstruction fidelity): `aa_004c17b0` ParticleFluidLiquidChild_HostLink_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c17b0` |
| **VA** | `0x004c17b0` |
| **Body** | `0x004c17b0`–`0x004c17fe` inclusive (**79 B**) |
| **Canonical name** | `ParticleFluidLiquidChild_HostLink_Ctor_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004c17b0` |
| **Prior / alias** | `Named_CalleeOf_*Drive_NDRiver_fx_004c17b0` (**reject** product) |
| **Review date** | `2026-08-04` (W38-L OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004c17b0_ParticleFluidLiquidChild_HostLink_Ctor_Inferred.md` |
| **System** | particle fluid liquid-child host-link |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ctor for the 8-byte host-link subobject installed at liquid-child `+0x18`: publish vtbl `009cb7a4` and host back-pointer; if host non-null, push_back `this` onto host list (sentinel @ host+8, size @ host+0xC).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c17b0_FUN_004c17b0.md` (+ W38-L append) |
| Annotated | `docs/reconstruction/raw/aa_004c17b0_FUN_004c17b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidLiquidChild_HostLink_Ctor_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004c17b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c17b0_ParticleFluidLiquidChild_HostLink_Ctor_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | full 79 B hex in raw append |
| Parent context | W37-G `aa_004c1800` liquid-child ctor |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `8B 44 24 04 85 C0 55 8B E9` — host from stack; ECX→EBP this |
| Vtbl | `C7 45 00 A4 B7 9C 00` — `009cb7a4` |
| Host field | `89 45 04` |
| Null skip | `74 34` |
| Head load | `8B 78 08` — host+8 |
| IncSize base | `8D 70 04` — host+4 |
| Epilogue | `8B C5 5D C2 04 00` — return this; **RET 4** |
| Body end | inclusive `0x004c17fe` then `CC` |

Full hex: see raw W38-L append.

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size 79 B / RET 4 | **pass** |
| thiscall ECX=subobject | **pass** (caller LEA +0x18) |
| Optional list push_back | **pass** |
| Clean has no bare `undefined4` | **pass** (`uint32_t` / structs) |
| Product English / vtbl demangle | **gap** |
| Nested list helper duals | **gap** (unOWN) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 4 sealed |
| 8 B host-link layout | **High** | stores only +0/+4 |
| Sole caller liquid-child | **High** | 1 xref |
| Name structural `_Inferred` | **Inferred** | no product plate |
| Runtime / differential | Open | |

---

## 6. Gaps (acceptable)

1. Product/PDB English for host-link / `009cb7a4`.  
2. Full dual of `FUN_006759b0`, `FUN_004c20b0`, vtbl method `0x004c09c0`.  
3. Runtime / bit-exact / differential.

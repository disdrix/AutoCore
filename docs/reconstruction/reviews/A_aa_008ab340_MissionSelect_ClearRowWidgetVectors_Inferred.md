# Review A (reconstruction fidelity): `aa_008ab340` MissionSelect_ClearRowWidgetVectors_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab340` |
| **VA** | `0x008ab340` |
| **Canonical name** | `MissionSelect_ClearRowWidgetVectors_Inferred` (Ghidra `FUN_008ab340`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Destroy-and-clear** Select-a-Mission list-row widget pointer vectors on the host:

1. For each non-null entry in vector A (`+0x72c`…`+0x730`) and vector B (`+0x73c`…`+0x740`):
   - widget **vtbl+0x3d8** → optional **vtbl+0x440**
   - if `widget+0x2b0 ≠ 0`: host **vtbl+0xB0**(widget)
   - scalar deleting dtor **vtbl[0](1)**; zero slot
2. Set each vector **end = begin** (used-range clear; capacity retained).

Callers: panel mode switch `FUN_008ab550` (×2) and host dtor `FUN_008ac340` (before `operator_delete`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra | `decompile_function` + `analyze_function_complete` @ `0x008ab340` |
| Body bounds | `get_function_by_address` → `008ab340`–`008ab548` (RET); exclusive end `008ab549` |
| Full bytes | `read_memory` length **521** |
| Disasm | `disassemble_function` (ABI/offsets; not `disassemble_bytes`) |
| Callers | `get_function_callers` / `get_xrefs_to` (3 UNCONDITIONAL_CALL) |
| Parent framing | decompile + disasm `FUN_008ab550`, `FUN_008ac340` |
| Raw | `docs/reconstruction/raw/aa_008ab340_FUN_008ab340.md` (+ MEGA-105 append) |
| Annotated | `docs/reconstruction/raw/aa_008ab340_FUN_008ab340.annotated.md` |
| Clean | `reconstructed-exact/MissionSelect_ClearRowWidgetVectors_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_008ab340.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 521 B / `0x209` | **High** | bounds + full hex + `CC` pad after RET |
| ESI = mission-select host | **High** | parent `MOV ESI,ECX`; dtor `MOV ESI,ECX`; all loads `[ESI+…]` |
| No stack args / plain RET | **High** | ends `5F 5D 5B 59 C3`; no `RET n` |
| Offsets +0x72c/+0x730/+0x73c/+0x740 | **High** | `8B 86 2C/30/3C/40 07 00 00` |
| Dual destroy loops | **High** | mirrored blocks in disasm + decompile |
| vtbl +0x3d8 / +0x440 / +0xB0 / dtor | **High** role | `FF 92 D8 03` / `40 04` / `B0 00` / `6A 01 FF 12` |
| end = begin clear via memmove | **High** | size computed as `end-end=0`; stores begin into end field |
| 3 call sites | **High** | xrefs sealed |
| Product virtual English | **Tentative** | ordinals only |
| Product function name | **Open** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live | Clean |
|---|---|---|---|
| Count vector A; loop destroy | Yes | Yes | Yes |
| Clear A used range | Yes | Yes | Yes |
| Count vector B; loop destroy | Yes | Yes | Yes |
| Clear B used range | Yes | Yes | Yes |
| Invented branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra. Decompiler `unaff_ESI` corrected to ESI ABI in clean/annotated.

---

## 5. Assembly seals (no disassemble_bytes)

| Bytes | Meaning |
|---|---|
| `51 8B 86 2C 07 00 00` | push ecx; mov eax,[esi+0x72c] |
| `8B AE 30 07 00 00` / `2B E8` / `C1 FD 02` | end−begin >> 2 → count |
| `FF 92 D8 03 00 00` | call [edx+0x3d8] |
| `FF 92 40 04 00 00` | call [edx+0x440] |
| `83 B9 B0 02 00 00 00` | cmp [ecx+0x2b0],0 |
| `FF 92 B0 00 00 00` | call [edx+0xb0] host |
| `6A 01` / `FF 12` | push 1; call [edx] dtor |
| `FF 15 2C 65 9C 00` | call memmove IAT |
| `89 86 30 07 00 00` / `89 86 40 07 00 00` | store end field |
| `5F 5D 5B 59 C3` | restore + ret |

### Caller seals

```
008ab555  MOV ESI, ECX          ; FUN_008ab550 host this
…
008ab6c4  CALL 0x008ab340       ; show-path early exit
…
008ab791  CALL 0x008ab340       ; hide-path fallthrough

008ac358  MOV ESI, ECX          ; dtor this
008ac36c  CALL 0x008ab340
; then operator_delete on +0x73c and +0x72c buffers
```

---

## 6. Gaps

1. Product/PDB name.
2. Product names for vtbl +0x3d8 / +0x440 / host +0xB0.
3. Semantic split vector A vs B (two banks).
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — ESI ABI, 521 B body, dual vector destroy/clear, ordinals, and three call sites sealed; product English open. No runtime Confirmed.

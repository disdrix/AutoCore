# Review A (reconstruction fidelity): `aa_0073cb70` HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073cb70` |
| **VA** | `0x0073cb70`–`0x0073cd69` (**506 B**) |
| **Canonical name** | `HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred` |
| **Ghidra name** | `FUN_0073cb70` |
| **Review date** | `2026-07-29` (W36-G dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-G) |
| **Counterpart** | `reviews/B_aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md` |
| **System** | EDI host vector get-or-create / PalDiffMap |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 506 B) + `analyze_function_complete` + xrefs + callee decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Get-or-create next **0x14c** host from EDI-owned pointer vector (cursor **+0x44**). Miss path builds host + **0xC4** material with **PalDiffMap.fx** / **DiffuseMap**, wires via `FUN_007647c0`, grows vector, stores, returns host.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0073cb70_FUN_0073cb70.md` (+ W36-G append) |
| Annotated | `docs/reconstruction/raw/aa_0073cb70_FUN_0073cb70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073cb70.cpp` |
| Function | `docs/reconstruction/functions/aa_0073cb70_FUN_0073cb70.md` |
| Named | `docs/reconstruction/functions/aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md` |
| Live | decompile ≡ raw CF; full 506 B hex; 2 callers |
| Context | W35-E HostPtrTable12 0x14c/0xC4 pair; string `PalDiffMap.fx` @ `0x00a2ddcc` |

---

## 3. Signature (sealed)

```c
void *HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred(void /* EDI host */);
```

| Slot | Source | Conf |
|---|---|---|
| EDI host | all `EDI+disp`; no EDI save | **High** |
| return | EAX = 0x14c\* (hit or new) | **High** |
| stack formals | none | **High** |
| early exit | `ADD ESP,0x64; RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
count = vec empty ? 0 : (end-begin)>>2
if (cursor < count) return vec[cursor++]
host = new(0x14c)+FUN_00764030
mat  = new(0xC4)+FUN_00748960
load PalDiffMap.fx; resolve DiffuseMap; optional 0x10x0x10/fmt 0x16
material local + mat[+0x5c]; FUN_007647c0(host, mat)
FUN_004367f0(edi+0x48, cursor+1, 0)
vec[cursor] = host; cursor++; dtor local; return host
```

| Stage | Match | Conf |
|---|---|---|
| Fast path cursor/vector | **Yes** | **High** |
| 0x14c / 0xC4 sizes | **Yes** | **High** |
| PalDiffMap.fx / DiffuseMap | **Yes** | **High** |
| Grow + store | **Yes** | **High** |
| Product host class English | open | **Low** |
| Full material helper contracts | open | **Low** |

---

## 5. Gaps / open

1. Product C++ names for EDI host / 0x14c / 0xC4 classes.
2. Unowned callees (`FUN_00748960`, FX helpers, `FUN_007647c0` detail — W36-H/L).
3. Twin at `0x0073cd70` (different offsets) not owned.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — EDI vector get-or-create + PalDiffMap construction sealed; product English + unowned pipeline open.

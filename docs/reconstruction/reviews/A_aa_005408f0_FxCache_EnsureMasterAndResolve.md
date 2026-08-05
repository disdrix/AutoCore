# Review A (reconstruction fidelity): `aa_005408f0` `FxCache_EnsureMasterAndResolve`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005408f0` |
| **VA** | `0x005408f0` |
| **Body span** | `005408f0`–`005409b1` (**193 B** through `ret 0x0c`) |
| **Canonical name** | `FxCache_EnsureMasterAndResolve` (structural **INFERRED**) |
| **Ghidra name** | `FUN_005408f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W20-I) |
| **Counterpart** | `reviews/B_aa_005408f0_FxCache_EnsureMasterAndResolve.md` |
| **System** | `client-fx` / skills-abilities |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Ensure FX master loaded for a cache key, then resolve FX:**

1. Inline CNDHash find on `*(host+0xf0c)` by `key`.
2. Miss → return **0**.
3. If `value[+0x0a]==0`: SkillDefMap exact-find → materialize name (`FUN_00540090`) → `FxMaster_LoadMasterFromXML`.
4. `FUN_004a16d0` with **ECX = value+4** (bytes); return result.

Sibling heavier path: `FxCache_ApplyWithNfxEnsure` (`0x00542790`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005408f0_FUN_005408f0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_005408f0_FUN_005408f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FxCache_EnsureMasterAndResolve.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_005408f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005408f0_FxCache_EnsureMasterAndResolve.md` |
| Live decompile | Ghidra @ `0x005408f0` |
| Bytes | `read_memory` entry 128 B + exit @ `0x005409a0` |
| Xrefs | callers `FUN_00512d10`, `FUN_00578b30` |
| Related duals | `SkillDefMap_GetGlobal`, `SkillDefMap_ExactFindByIntKey`, `FxMaster_LoadMasterFromXML` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed claims (`read_memory`)

### Entry / hash

```text
005408f0  8B 81 0C 0F 00 00   mov  eax, [ecx+0xf0c]
005408f6  8B 50 08            mov  edx, [eax+8]
005408f9  8B 4C 24 04         mov  ecx, [esp+4]     ; key
005408fd  8B 40 10            mov  eax, [eax+0x10]
00540900  23 D1               and  edx, ecx
00540902  8B 14 90            mov  edx, [eax+edx*4]
00540905  8B 42 04            mov  eax, [edx+4]
```

### Early miss ret

```text
... 33 C0 ... 81 C4 04 04 00 00  C2 0C 00   ; return 0, ret 0x0c
```

### Exit → FUN_004a16d0

```text
005409a0  8D 4E 04            lea  ecx, [esi+4]
005409a3  E8 .. .. .. ..      call FUN_004a16d0
005409a8  5E                  pop  esi
005409a9  81 C4 04 04 00 00   add  esp, 0x404
005409af  C2 0C 00            ret  0x0c
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **193 B** through final ret | `get_function_by_address` + `CC` pad | **Confirmed** |
| **`ret 0x0c`** (3 stack args) | `C2 0C 00` | **Confirmed** |
| Host hash @ **`+0xf0c`** | `8B 81 0C 0F 00 00` | **Confirmed** |
| Inline bucket walk (mask/table/chain) | entry bytes + decompile | **Confirmed** |
| FUN_004a16d0 this = **value+4** | `lea ecx,[esi+4]` | **Confirmed** |
| Live decompile ≡ raw CF | side-by-side | **Confirmed** |
| Clean ≡ raw CF | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = ensure master + resolve FX | **High** | SkillDefMap + LoadMaster + 004a16d0 |
| Master gate `value+0x0a` | **Confirmed** | decompile + sibling 00542790 |
| GetGlobal leaf / ExactFind consumer | **Confirmed** | dualed callees |
| Product English name | **Open** | structural only |
| Full FUN_004a16d0 semantics | **Open** | not OWN |
| Runtime | **Open** | |

---

## 5. Call graph (this unit)

**Callees:** `SkillDefMap_GetGlobal`, `SkillDefMap_ExactFindByIntKey`, `FUN_00540090`, `FxMaster_LoadMasterFromXML`, `FUN_004a16d0`.

**Callers:**

| Symbol | VA |
|---|---|
| `FUN_00512d10` | `0x00512d10` |
| `FUN_00578b30` | `0x00578b30` |

---

## 6. Gaps

1. Product/PDB English symbol.
2. Exact type of host (`DAT_00b041fc` client vs skill manager) — layout only sealed at `+0xf0c`.
3. Dual of `FUN_004a16d0` / `FUN_00540090` (not OWN this wave).
4. Runtime cold/warm golden.

**Verdict:** **accept-with-gaps** — CF/ABI/hash/master path sealed; naming + runtime residual.

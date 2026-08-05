# Review A (reconstruction fidelity): `aa_0058e370` CVOGObject_SetGfxBodyLink_Mode1AndTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e370` |
| **VA** | `0x0058e370` |
| **Body** | `0x0058e370`–`0x0058e398` (**40** B) |
| **Canonical name** | `CVOGObject_SetGfxBodyLink_Mode1AndTarget` (**Inferred**) |
| **Prior / alias** | `FUN_0058e370`; long `Named_CalleeOf_…_Cli_0058e370` (**parent-seed noise**) |
| **Review date** | `2026-07-29` (W20-M OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md` |
| **System** | client CVOG object / gfxBody link packet |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_xrefs_to` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Arm the CVOG object's gfxBody link packet** toward an external target:

1. Load `gfxBody = *(this + 0x914)`; bail if null.
2. Load `packet = *(gfxBody + 0x78)`; bail if null.
3. `*packet = 1` (mode byte).
4. `*(packet + 4) = target` (stack arg).

No callees. Sole xref from `FUN_004b73c0` list broadcast.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058e370_FUN_0058e370.md` (+ W20-M live append) |
| Annotated | `docs/reconstruction/raw/aa_0058e370_FUN_0058e370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_SetGfxBodyLink_Mode1AndTarget.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0058e370.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md` |
| Live decompile | `decompile_function` @ `0x0058e370` |
| Live bytes | `read_memory` length 40 |
| Bounds | `get_function_by_address` → `0058e370`–`0058e398` |
| Context | decompile `0x0058f780` (gfxBody create + packet init mode 9) |
| Caller | decompile `0x004b73c0` (single xref) |

---

## 3. Byte seal (`read_memory` @ `0x0058e370`)

```
8b 81 14 09 00 00    mov  eax, [ecx+0x914]
85 c0                test eax, eax
74 1c                jz   done
83 78 78 00          cmp  dword [eax+0x78], 0
74 16                jz   done
8b 50 78             mov  edx, [eax+0x78]
c6 02 01             mov  byte [edx], 1
8b 81 14 09 00 00    mov  eax, [ecx+0x914]
8b 48 78             mov  ecx, [eax+0x78]
8b 54 24 04          mov  edx, [esp+4]
89 51 04             mov  [ecx+4], edx
c2 04 00             ret  4
```

| Claim | Evidence | Conf |
|---|---|---|
| Offset **0x914** gfxBody load | `mov eax,[ecx+0x914]` | **High** |
| Offset **0x78** packet check | `cmp [eax+0x78],0` | **High** |
| Mode write **1** | `c6 02 01` | **High** |
| Target store at **packet+4** | `mov [ecx+4], edx` from `[esp+4]` | **High** |
| `__thiscall` + `ret 4` | ECX this; `c2 04 00` | **High** |
| Decompile ≡ raw ≡ bytes | match | **High** |
| `+0x914` is gfxBody | string in `0058f780` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `+0x914` | **Yes** |
| Dual null gates | **Yes** |
| Mode byte = 1 | **Yes** |
| `*(packet+4) = arg` | **Yes** |
| No callees / no invent | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf store helper | **High** | 40 B body |
| gfxBody / packet offsets | **High** | creator + this unit |
| Mode 1 vs sibling mode 9 | **High** as bytes; product enum **Open** |
| Single caller broadcast role | **High** | one xref |
| Target type product name | **Medium** | pointer-sized entity from caller |
| Runtime | **Open** | deferred |

---

## 6. Gaps / open

1. Product name of link packet / mode enum.
2. Consumer of mode=1 (gfx tick path) — not this dual's ownership.
3. Full type of `FUN_004b73c0` manager (only used for role).

**Verdict:** **accept**

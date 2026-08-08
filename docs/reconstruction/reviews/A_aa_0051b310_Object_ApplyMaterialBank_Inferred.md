# Review A (reconstruction fidelity): `aa_0051b310` Object_ApplyMaterialBank_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b310` |
| **VA** | `0x0051b310` |
| **Body** | `0x0051b310`–`0x0051b34f` (**64 bytes** / `0x40`) |
| **Canonical name** | `Object_ApplyMaterialBank_Inferred` |
| **Prior scaffold** | `FUN_0051b310` |
| **Review date** | `2026-08-04` (WQ9R-I dual seal) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0051b310_Object_ApplyMaterialBank_Inferred.md` |
| **System** | object / gfx material bank |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Object virtual method:** if the object's material-parameter bank is non-empty, resolve the gfx/material component via `vtbl+0x1CC` and commit bank entries into shader parameters through `FUN_005194f0` (MatDiffuse / MatAmbient / MatEmissive path in that callee).

Complement of empty-bank fill sibling `FUN_0051b2a0` (same vector + vcall; fill via `FUN_00519280`) — adjacent vtable slots (`…b2a0` then `…b310`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x0051b310` |
| Bytes | `read_memory` 80 B @ entry → end `C3`; pad into next fn |
| Bounds | `get_function_by_address` body `0051b310`–`0051b34f` |
| Callee | `decompile_function` `FUN_005194f0` @ `0x005194f0` (Mat* commit) |
| Sibling | `decompile_function` `FUN_0051b2a0` @ `0x0051b2a0` (empty fill) |
| Caller | `FUN_004c5510` @ `0x004c5510` (also direct bank path with mid-object ECX) |
| Vtable DATA xrefs | 23 slots (e.g. `0x009ce3c8` holds `0x0051b310`) |
| Code xrefs | `0x004c5524` (`FUN_004c5510`), `0x004f3760` |
| Raw / clean | `aa_0051b310_*`, `Object_ApplyMaterialBank_Inferred.cpp` |

**Not performed:** Launcher, runtime material capture, parent ledgers, dual of `005194f0` / `0051b2a0`.

---

## 3. Sealed facts

### 3.1 ABI / body

| Claim | Evidence | Confidence |
|---|---|---|
| Body **64 B** exclusive end `0x0051b34f` | `get_function_by_address` + bytes `…5E 59 C3` | **Confirmed** |
| **`__thiscall`/`__fastcall`** ECX=`object*` | `MOV EAX,[ECX+0x148]`; `LEA ESI,[ECX+0x144]` | **Confirmed** |
| No stack formals; bare **`C3` RET** | epilogue `ADD ESP,8` only for callee | **Confirmed** |
| ECX preserved | entry `PUSH ECX` / exit `POP ECX` | **Confirmed** |

### 3.2 Material bank layout

| Offset | Role | Evidence |
|---|---|---|
| `this+0x144` | Bank header base (passed as 2nd arg) | `LEA ESI,[ECX+0x144]`; `PUSH ESI` |
| `this+0x148` | Begin pointer (`param_1[0x52]`) | `MOV EAX,[ECX+0x148]`; null test |
| `this+0x14C` | End pointer (`[ESI+8]`) | `MOV EDX,[ESI+8]`; `SUB EDX,EAX`; `SAR EDX,4` |
| Stride **0x10** | Element size | `SAR …,4` count |

Callee `FUN_005194f0` reads `param_2+4` / `param_2+8` as begin/end and expects `gfxCount*3 == bankCount` (debug stop otherwise) — seals that header is **not** a classic `{begin,end,cap}` at +0 but a structure whose **active range is at +4/+8**.

### 3.3 Control flow

```
if begin==null || (end-begin)>>4==0: return
component = vtbl[0x1CC](this)
if component==null || *(component+8)==null: return
FUN_005194f0(*(component+8), this+0x144)   // cdecl; ADD ESP,8
return
```

### 3.4 Classification / xrefs

| Claim | Confidence |
|---|---|
| Worker virtual method on object hierarchy | **High** (23 DATA vtable xrefs) |
| Applies **existing** bank → gfx (not fill) | **High** (vs sibling empty-path `0051b2a0`) |
| Not a skill-bank cast helper | **High** — Mat* path; residual WQ-009 region neighbor only |
| Name `Object_ApplyMaterialBank_Inferred` | **Inferred** structural; product demangle open |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Non-empty bank gate | Yes |
| vtbl+0x1CC component | Yes |
| component+8 host gate | Yes |
| `FUN_005194f0(host, this+0x144)` arg order | Yes |
| No invented writes | Yes |

---

## 5. Gaps / open

1. Product / MSVC demangle for method and bank type.
2. Exact English for `vtbl+0x1CC` return type (gfx component).
3. Full layout of bank element (0x10 B) — owned by `005194f0` dual, not this unit.
4. Identity of code site `0x004f3760` (no function bound at that VA in Ghidra).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**

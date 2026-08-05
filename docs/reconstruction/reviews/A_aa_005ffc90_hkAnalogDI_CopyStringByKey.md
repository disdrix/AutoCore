# Review A (reconstruction fidelity): `aa_005ffc90` hkAnalogDI_CopyStringByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc90` |
| **VA** | `0x005ffc90`–`0x005ffce5` |
| **Canonical name** | `hkAnalogDI_CopyStringByKey` |
| **Ghidra name** | `FUN_005ffc90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-M) |
| **Counterpart** | `reviews/B_aa_005ffc90_hkAnalogDI_CopyStringByKey.md` |
| **System** | Havok / DI analog string table |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` full body; callee decompiles; sole caller `hkAnalogDI_vtbl1` |
| **Verdict** | **accept** |

---

## 1. Purpose

Copy the C-string mapped from a uint key in the open-address table at **this+8** into a caller buffer, returning source length; return 0 if the key is absent.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ffc90_FUN_005ffc90.md` (+ W25-M append) |
| Annotated | `docs/reconstruction/raw/aa_005ffc90_FUN_005ffc90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/hkAnalogDI_CopyStringByKey.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_005ffc90.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ffc90_hkAnalogDI_CopyStringByKey.md` |
| Live | decompile `0x005ffc90`; `read_memory` 85 B; callees `00650290`/`0065ad10`/`0065acb0`/`00638040`/`00638060`; caller `005ffd80` |

---

## 3. Signature

```c
int __thiscall hkAnalogDI_CopyStringByKey(void* this, unsigned key, char* dst, unsigned maxlen);
// Bytes: ret 0xc; EAX = strlen(src) or 0
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8D 71 08` lea esi,[ecx+8] | **High** |
| 3 stack args / ret 0xc | terminal `C2 0C 00` ×2 | **High** |
| Fail EAX=0 | `33 C0` on miss path | **High** |
| Success EAX=strlen(src) | call `FUN_00638060` then ret | **High** |

---

## 4. Control flow (sealed)

```
table = this+8
index = FUN_00650290(table, key)
found = (index <= capacity) via FUN_0065ad10
if !found: return 0
src = FUN_0065acb0(table, index)
FUN_00638040(dst, src, maxlen)  // strncpy
return FUN_00638060(src)        // strlen
```

| Stage | Match | Conf |
|---|---|---|
| Table base +8 | **Yes** | **High** |
| Lookup then found gate | **Yes** | **High** |
| Copy + strlen only on hit | **Yes** | **High** |
| Miss returns 0 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (85 B) captured in raw W25-M append. Spot checks:

| Pattern | Bytes | Role |
|---|---|---|
| this+8 | `8D 71 08` | table bind |
| miss jz | `74 28` | skip copy |
| ret 0xc | `C2 0C 00` | ABI |

Decompile CF ≡ bytes for branch structure; thiscall recovered from prologue only.

---

## 6. Gaps

1. Product English for key namespace.  
2. Full table object layout (only +0 base / +8 capacity used here).  
3. Runtime / bit-exact / differential open.

**None of these block role/ABI/CF seal.**

---

## 7. Verdict

**accept** — ABI, bounds, CF, and role sealed from bytes + callees + sole caller family name.

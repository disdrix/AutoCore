# Review A (reconstruction fidelity): `aa_004e2e80` `Mem_MoveDwordRange_ReturnEnd`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2e80` |
| **VA** | `0x004e2e80` |
| **Body span** | `004e2e80`–`004e2eaa` (42 B through `ret 0xC`) |
| **Canonical name** | `Mem_MoveDwordRange_ReturnEnd` (structural) |
| **Ghidra name** | `FUN_004e2e80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W19-C) |
| **Counterpart** | `reviews/B_aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md` |
| **System** | `stl-helpers` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Move a dword-aligned half-open pointer range into a destination buffer and return the write end:**

```c
size = ((srcEnd - srcBegin) >> 2) * 4;
memmove(dest, srcBegin, size);
return dest + size;
```

Generic POD relocate used by many vector/list grow paths (including sector-map character add callees).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e2e80_FUN_004e2e80.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_004e2e80_FUN_004e2e80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ReturnEnd.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_004e2e80.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md` |
| Live decompile | Ghidra @ `0x004e2e80` |
| Bytes | `read_memory` 48 B @ `0x004e2e80` |
| Xrefs | 30+ unconditional calls (vector relocate family) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x004e2e80`)

```text
004e2e80  8B 4C 24 04        mov  ecx, [esp+4]     ; srcBegin
004e2e84  8B 44 24 08        mov  eax, [esp+8]     ; srcEnd
004e2e88  2B C1              sub  eax, ecx
004e2e8a  56                 push esi
004e2e8b  C1 F8 02           sar  eax, 2
004e2e8e  8D 34 85 00 00 00 00  lea esi, [eax*4] ; size
004e2e95  8B 44 24 10        mov  eax, [esp+10h]   ; dest
004e2e99  56 51 50           push size, src, dest
004e2e9c  FF 15 2C 65 9C 00  call [memmove IAT]
004e2ea2  83 C4 0C           add  esp, 0Ch
004e2ea5  03 C6              add  eax, esi
004e2ea7  5E                 pop  esi
004e2ea8  C2 0C 00           ret  0Ch
```

Hex (body through `ret 0xC`):

```
8b4c24048b4424082bc156c1f8028d3485000000008b442410565150ff152c659c0083c40c03c65ec20c00
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **42 bytes** through `ret 0xC` | `read_memory` + `CC` pad | **Confirmed** |
| `__stdcall` three args | `C2 0C 00` | **Confirmed** |
| Size `((end-begin)>>2)*4` | `sar 2` + `lea [eax*4]` | **Confirmed** |
| Sole callee memmove | IAT call `0x009c652c` | **Confirmed** |
| Return dest+size | `add eax,esi` after memmove | **Confirmed** |
| Live decompile ≡ raw | side-by-side | **Confirmed** |
| Clean ≡ raw CF | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = dword-range move + return end | **Confirmed** | bytes + CF |
| Not byte-exact span when span % 4 ≠ 0 | **Confirmed** | floor via `>>2`*`4` |
| Overlap-safe (memmove not memcpy) | **Confirmed** | IAT target |
| Product STL symbol | **Open** | structural name only |
| Per-caller element type | **Open** | always 4-byte POD for this helper |

---

## 5. Call graph (this unit)

**Callees:** `memmove`

**Callers:** 30+ including `FUN_004e39d0`, `FUN_004073a0`, `FUN_00429970`, `FUN_004507a0`, `FUN_004bf830`, `FUN_00596770`, `FUN_0068c060`, …

---

## 6. Gaps

1. Product / MSVC STL English name.
2. Runtime / bit-exact golden.
3. Full per-caller element-type recovery (out of OWN scope).

**Verdict:** **accept** — leaf fully sealed; naming residual only.

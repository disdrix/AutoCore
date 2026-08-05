# Review A (reconstruction fidelity): `aa_00410490` StdVector_EraseRange_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00410490` |
| **VA** | `0x00410490` |
| **Canonical name** | `StdVector_EraseRange_Dword_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00410490` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-S) |
| **Counterpart** | `reviews/B_aa_00410490_StdVector_EraseRange_Dword_Inferred.md` |
| **System** | STL / container utility (multi-domain dword vectors) |
| **Verdict** | **accept** on CF / dword width / thiscall+`ret 0xC` / end rebind; product symbol **open** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

MSVC-style **vector range erase** for **dword (4-byte) POD** elements:

```
// __thiscall this; stack (outIt*, first, last); ret 0xC
if (first != last) {
  size = ((end - last) >> 2) * 4;     // bytes of tail [last, end)
  memmove(first, last, size);         // close hole
  end = memmove_dst + size;           // *(this+8)
}
*outIt = first;
```

- **Does not** call element destructors.
- **Does not** free or shrink capacity of the buffer.
- **Does not** touch begin (`this+4`) itself — callers compute `first`/`last` from begin/end.

Primary documented consumer: `StdVector_DwordResize` (`0x004367f0`) shrink arm:

```
FUN_00410490(&tmp, begin + newCount*4, end);
```

Also: `FUN_00410420` (similar resize), `FUN_004365e0` (bit-length trim of dword words), `FUN_00449000`.

Scaffold alias `Named_CalleeOf_…_gfxFontImpl_*` is **parent-seed residue**, not exclusive ownership.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00410490_FUN_00410490.md` |
| Raw | `docs/reconstruction/raw/aa_00410490_FUN_00410490.md` |
| Annotated | `docs/reconstruction/raw/aa_00410490_FUN_00410490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00410490.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00410490` (2026-07-29) — **≡ raw** |
| Live body bytes | Ghidra `read_memory` `0x00410490` length 80 |
| IAT slot | `read_memory` `0x009c652c` → `0x006ea9d0` (`memmove` thunk) |
| Callers | `get_function_callers`: `00410420`, `004365e0`, `004367f0`, `00449000` |
| Parent dual | `A_aa_004367f0_StdVector_DwordResize.md` (shrink callee) |

**Not performed:** Launcher, runtime golden, bit-exact image diff, dual of every caller body, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; `ECX` saved as this (`mov ebx,ecx`) | **Confirmed** | bytes |
| Three stack args; **`ret 0xC`** (`c2 0c 00`) | **Confirmed** | epilogue |
| Empty range (`first == last`) skips memmove, still writes outIt | **Confirmed** | `je` + fallthrough store |
| Tail size `((end-last)>>2)*4` | **Confirmed** | `sar 2` + `lea [eax*4]` |
| `memmove(first, last, size)` via IAT | **Confirmed** | `call [0x009c652c]` + `add esp,0xC` (cdecl) |
| Rebind `*(this+8) = first + size` | **Confirmed** | `add eax,esi; mov [ebx+8],eax` |
| `*outIt = first` always | **Confirmed** | final stores |
| Element width = **dword** (not 0x98 toast) | **Confirmed** | `>>2` / parent `*4` index math |
| No free / no dtor / no capacity write | **Confirmed** | leaf body |
| Role = erase-range helper | **High** | multi-caller shrink pattern |
| Product / PDB name | **Open** | structural `Inferred` |
| Clean ≡ raw ≡ live CF | **Confirmed** | identity |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Save this from ECX | **Yes** |
| Load first/last from stack | **Yes** |
| `first == last` → skip move | **Yes** |
| Compute tail byte size from end@+8 | **Yes** |
| memmove + rebind end | **Yes** |
| `*outIt = first` | **Yes** |
| `ret 0xC` | **Yes** |

### Recovered CF

```c
void __thiscall StdVector_EraseRange_Dword(
    DwordVec *this, void **outIt, void *first, void *last)
{
  if (first != last) {
    size_t size = ((char *)this->end - (char *)last); // via ((end-last)>>2)*4
    void *p = memmove(first, last, size);
    this->end = (char *)p + size;
  }
  *outIt = first;
}
```

### Parent shrink wiring (`0x004367f0`)

```
size = (end - begin) >> 2
if (begin && newCount < size)
  EraseRange(&tmp, begin + newCount*4, end)
```

---

## 5. Assembly contract (from `read_memory`, no `disassemble_bytes`)

```
00410490  53                 push ebx
00410491  57                 push edi
00410492  8b 7c 24 10        mov  edi, [esp+0x10]   ; first
00410496  8b d9              mov  ebx, ecx          ; this
00410498  8b 4c 24 14        mov  ecx, [esp+0x14]   ; last
0041049c  3b f9              cmp  edi, ecx
0041049e  74 22              je   skip_move
004104a0  8b 43 08           mov  eax, [ebx+8]      ; end
004104a3  2b c1              sub  eax, ecx          ; end - last
004104a5  56                 push esi
004104a6  c1 f8 02           sar  eax, 2
004104a9  8d 34 85 00 00 00 00  lea esi, [eax*4]    ; size
004104b0  56                 push esi
004104b1  51                 push ecx               ; src = last
004104b2  57                 push edi               ; dst = first
004104b3  ff 15 2c 65 9c 00  call dword ptr [0x009c652c]  ; memmove
004104b9  83 c4 0c           add  esp, 0xC
004104bc  03 c6              add  eax, esi          ; new end
004104be  89 43 08           mov  [ebx+8], eax
004104c1  5e                 pop  esi
skip_move:
004104c2  8b 44 24 0c        mov  eax, [esp+0xC]    ; outIt
004104c6  89 38              mov  [eax], edi        ; *outIt = first
004104c8  5f                 pop  edi
004104c9  5b                 pop  ebx
004104ca  c2 0c 00           ret  0xC
```

Hex: `53578b7c24108bd98b4c24143bf974228b43082bc156c1f8028d348500000000565157ff152c659c0083c40c03c68943085e8b44240c89385f5bc20c00`

---

## 6. Gaps

1. Retail / PDB symbol (`std::vector<unsigned>::_Erase` vs local helper).
2. Per-caller domain duals for `00410420` / `004365e0` / `00449000` (roles partially known; not OWN here beyond shrink evidence).
3. Capacity pointer `@+0xC` unused here (owned by grow/insert helpers).

**Verdict:** **accept** — sealed erase-range CF, dword element width, thiscall/`ret 0xC`, end@+8 rebind, and multi-caller shrink helper role.

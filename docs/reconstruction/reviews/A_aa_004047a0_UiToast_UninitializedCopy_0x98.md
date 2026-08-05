# Review A (reconstruction fidelity): `aa_004047a0` UiToast_UninitializedCopy_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_004047a0` |
| **VA** | `0x004047a0`–`0x0040480b` (108 B) |
| **Canonical name** | `UiToast_UninitializedCopy_0x98` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004047a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W22-H) |
| **Counterpart** | `reviews/B_aa_004047a0_UiToast_UninitializedCopy_0x98.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Verdict** | **accept** on CF / stride / ABI / callee link; product symbol **open** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Range POD copy** of UI toast elements (`0x98` bytes each) from half-open iterator range `[src_begin, src_end)` into `dst`, returning the advanced destination end. Implements MSVC-style `uninitialized_copy` over the sealed leaf `UiToast_PodCopyElement_0x98`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_004047a0_FUN_004047a0.md` |
| Named record | `docs/reconstruction/functions/aa_004047a0_UiToast_UninitializedCopy_0x98.md` |
| Raw | `docs/reconstruction/raw/aa_004047a0_FUN_004047a0.md` (+ W22-H live seal) |
| Annotated | `docs/reconstruction/raw/aa_004047a0_FUN_004047a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiToast_UninitializedCopy_0x98.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004047a0.cpp` |
| Live decompile | Ghidra `decompile_function` `0x004047a0` |
| Live body | `read_memory` 128 B @ entry; `get_function_by_address` body end `0040480b` |
| Callers | `FUN_00404510` only |
| Leaf dual | `A_aa_00404710_UiToast_PodCopyElement_0x98` |
| Sibling | `UiToast_UninitializedFillN_0x98` @ `0x00404130` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of wrapper (OWN-ONLY).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loop: while `src != end`, PodCopy, step both `0x98` | **Confirmed** | decomp ≡ bytes (`add …, 0x98`) |
| Body **108 B** / end `0040480b` | **Confirmed** | `get_function_by_address` |
| ABI **cdecl** plain `ret` (`C3`) | **Confirmed** | epilogue bytes |
| Return EAX = advanced **dst** | **Confirmed** | `mov eax, edi` |
| Callee = `FUN_00404710` PodCopy | **Confirmed** | rel32 target + dual |
| Formals (src_begin, src_end, dst) | **Confirmed** | `[ebp+8/c/10]` |
| 4th stack dword unused by leaf | **Confirmed** | EBX→ECX only; PodCopy ignores ECX |
| Toast family / stride 0x98 | **High** | sealed leaf + fill-n siblings |
| Product / PDB name | **Open** | structural |
| Clean ≡ raw ≡ live CF | **Confirmed** | identity |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH register | Yes |
| cmp src, end; jz done | Yes |
| push src; push dst; call PodCopy | Yes |
| add dst/src, 0x98; loop | Yes |
| mov eax, dst; restore; ret | Yes |
| No grow / no free / no deep fields | Yes |

### Recovered CF

```c
void *UiToast_UninitializedCopy_0x98(void *src_begin, void *src_end, void *dst, void *unused)
{
    for (; src_begin != src_end; src_begin = (char*)src_begin + 0x98) {
        UiToast_PodCopyElement_0x98(dst, src_begin);
        dst = (char*)dst + 0x98;
    }
    return dst;
}
```

---

## 5. Assembly contract (from `read_memory`)

Key path:

```
mov ebx, [ebp+14]   ; unused-by-leaf formal
mov edi, [ebp+10]   ; dst
mov esi, [ebp+08]   ; src begin
cmp esi, [ebp+0C]   ; src end
jz  done
push esi / push edi / mov ecx, ebx / call FUN_00404710
add edi, 0x98 / add esi, 0x98 / jmp cmp
done: mov eax, edi / leave / ret
```

Hex (108 B through `C3`): see raw W22-H section.

---

## 6. Callers (OWN context)

| Caller | VA | Role |
|---|---|---|
| `FUN_00404510` | `0x00404510` | thiscall thunk: `FUN_004047a0(first, last, result, this, result)` |

---

## 7. Gaps

1. Retail symbol.
2. Product meaning of 4th formal (allocator vs vector this) — body-dead.
3. Full toast vector grow path ownership (parent dual residual).

**Verdict:** **accept** — sealed range-copy CF, stride, cdecl ABI, and PodCopy linkage in the toast helper family.

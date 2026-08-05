# Review A (reconstruction fidelity): `aa_00404710` UiToast_PodCopyElement_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404710` |
| **VA** | `0x00404710`–`0x00404728` |
| **Canonical name** | `UiToast_PodCopyElement_0x98` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00404710` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00404710_UiToast_PodCopyElement_0x98.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Verdict** | **accept** on CF / stride / ABI / leaf purity; product symbol **open** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**POD dword-copy** of one **UI toast element** (`0x26` dwords = **`0x98` bytes**) from `src` → `dst`, gated on `dst != NULL`.

No heap, no vtable stamp, no string deep-copy. Used by toast vector fill/copy helpers (`FUN_00404670` multi-element fill; sibling `FUN_004047a0`). Parent push path `Client_UiToastQueue_Push` @ `0x0040c5c0` documents this as the in-place element copy on the fast capacity path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00404710_FUN_00404710.md` |
| Raw | `docs/reconstruction/raw/aa_00404710_FUN_00404710.md` |
| Annotated | `docs/reconstruction/raw/aa_00404710_FUN_00404710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00404710.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x00404710` (2026-07-29) |
| Live body bytes | Ghidra `read_memory` `0x00404710` length 48 |
| Callers | `get_function_callers` / xrefs: `FUN_00404670`, `FUN_004047a0` |
| Parent dual (context) | `reviews/A_aa_0040c5c0_Client_UiToastQueue_Push.md` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of callers (OWN-ONLY).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf: no callees / no heap | **Confirmed** | decompile + bytes (`rep movsd` only) |
| Copy width **`0x26` dwords** (= **`0x98` bytes**) | **Confirmed** | `mov ecx, 0x26` + `f3 a5` |
| Null-check is on **dst** only (`param_1`) | **Confirmed** | `test edi,edi` / `jz` skip; src unchecked |
| ABI: **`__stdcall`**, 2 stack args, **`ret 8`** | **Confirmed** | epilogue `c2 08 00` |
| Formals: `(void *dst, void *src)` order | **Confirmed** | `edi=[esp+arg1]`, `esi=[esp+arg2]` after saves |
| Role = toast-element POD copy (not mission grant) | **High** | parent toast dual + stride chain |
| Product / PDB name | **Open** | structural name only |
| Clean ≡ raw ≡ live CF | **Confirmed** | identity (scaffold types only) |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load dst; if null → ret | **Yes** |
| Load src; `ecx = 0x26` | **Yes** |
| `rep movsd` dword copy | **Yes** |
| `ret 8` | **Yes** |
| No side effects beyond dst write | **Yes** |

### Recovered CF (byte-aligned)

```c
// __stdcall: (dst, src) on stack; ret 8
void __stdcall UiToast_PodCopyElement_0x98(uint32_t *dst, uint32_t *src)
{
    if (dst != NULL) {
        // 0x26 dwords = 0x98 bytes
        for (int i = 0x26; i != 0; --i) {
            *dst++ = *src++;
        }
    }
}
```

---

## 5. Assembly contract (from `read_memory`)

```
00404710  57              push edi
00404711  8b7c2408        mov  edi, [esp+8]     ; dst
00404715  85ff            test edi, edi
00404717  740d            jz   short skip       ; → 00404726
00404719  56              push esi
0040471a  8b742410        mov  esi, [esp+0x10]  ; src
0040471e  b926000000      mov  ecx, 0x26
00404723  f3a5            rep  movsd
00404725  5e              pop  esi
00404726  5f              pop  edi
00404727  c20800          ret  8
```

Hex (body through final `ret`, 25 bytes):  
`578b7c240885ff740d568b742410b926000000f3a55e5fc20800`

Trailing `cc` padding at `00404729+` not executed.

---

## 6. Callers (OWN context only)

| Caller | VA | Role (caller-owned) |
|---|---|---|
| `FUN_00404670` | `0x00404670` | Fill `count` slots of stride `0x98` via this copy |
| `FUN_004047a0` | `0x004047a0` | Sibling element-path helper |

Scaffold alias `Named_CalleeOf_…_Client_RecvCraftFr_00404710` is a **parent-seed**, not exclusive ownership.

---

## 7. Gaps

1. Retail / PDB symbol.
2. Full `ToastElement` field map (owned by packers, not this leaf).
3. Whether any non-toast client reuses the same POD width (this VA is toast-chain dedicated via callers).

**Verdict:** **accept** — sealed leaf CF, stride, stdcall ABI, and POD-copy role in the toast vector family.

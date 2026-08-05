# Review A (reconstruction fidelity): `aa_0051db60` CNDHash_Ctor_009ce1a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051db60` |
| **VA** | `0x0051db60`–`0x0051dbd2` (**115 B** / `0x73`) |
| **Canonical name** | `CNDHash_Ctor_009ce1a0` (Ghidra `FUN_0051db60`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W26-P Path A) |
| **Counterpart** | `reviews/B_aa_0051db60_CNDHash_Ctor_009ce1a0.md` |
| **System** | container / CNDHash (medal family; object vtbl `009ce1a0`) |
| **Live tools** | `decompile_function`, `read_memory`, `analyze_function_complete` (xrefs/callees) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — seals AllocBucketTable caller residual “ctor FUN_0051db60” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

Medal-family CNDHash constructor:

```text
// thiscall; stack log2; returns this; ret 4
*this = &PTR_FUN_009ce1a0
zero fields; +0x08 = 1 << log2; +0x1C = log2; +0x1D = 0
// +0x24 not written
FUN_0051ba40(this)  // AllocBucketTable → mask + table + sentinels 009ce090
return this
```

**Caller:** static init `@ 0x009c0b57` with `log2=2`, `this=0x00b042e0`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | full body through `C2 04 00` |
| Alloc twin dual | W25-F `aa_0051ba40` (caller site `@ 0051dbba` listed) |
| Free / reclaim family | `aa_0051d150`, `aa_0051bfb0` |
| Static site | `read_memory` `@ 0x009c0b50` |
| Raw / clean | `raw/aa_0051db60_*`, `reconstructed-exact/CNDHash_Ctor_009ce1a0.cpp`, `FUN_0051db60.cpp` |

---

## 3. Authoritative body (sealed CF)

```c
void *__thiscall CNDHash_Ctor_009ce1a0(void *thisHash, uint8_t log2)
{
  uint32_t *p = (uint32_t *)thisHash;
  // SEH LAB_009a371b
  p[0] = (uint32_t)&PTR_FUN_009ce1a0;
  p[1] = 0; p[3] = 0;
  p[2] = 1u << (log2 & 0x1f);
  p[4] = p[5] = p[6] = 0;
  *(uint8_t *)(p + 7) = log2;
  *((uint8_t *)p + 0x1d) = 0;
  p[8] = 0;                 // freelist
  // +0x24 skipped
  p[10] = p[11] = p[12] = 0;
  FUN_0051ba40(thisHash);   // thiscall
  return thisHash;
}
```

---

## 4. Machine seal (`read_memory` @ `0x0051db60`)

| Claim | Evidence | Conf |
|---|---|---|
| SEH prolog | `6A FF 68 1B 37 9A 00` | **High** |
| thiscall ECX→ESI | `56 8B F1` | **High** |
| log2 stack load | `8A 4C 24 18` | **High** |
| N=1≪CL | `BA 01.. D3 E2` | **High** |
| vtbl imm `009ce1a0` | `C7 06 A0 E1 9C 00` | **High** |
| +0x08 ← EDX (N) | `89 56 08` | **High** |
| +0x1C ← CL | `88 4E 1C` | **High** |
| +0x24 not stored | no ESI+0x24 write | **High** |
| call Alloc | `8B CE; E8 …` → `0051ba40` | **High** |
| return this; ret 4 | `8B C6 … C2 04 00` | **High** |
| static log2=2 | `6A 02 B9 E0 42 B0 00 E8` @ `009c0b50` | **High** |

---

## 5. Gaps

- Product / PDB Ctor English / exact class name.
- Full vtbl method matrix at `009ce1a0`.
- Semantic of unwritten `+0x24`.
- Runtime / bit-exact / differential.

## 6. Verdict

**accept-with-gaps** — ABI, field init, Alloc handoff, static caller sealed High. Name stamp-qualified inferred.

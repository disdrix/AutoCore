# Review A (reconstruction fidelity): `aa_00442b00` SkillSet_UninitializedCopy_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442b00` |
| **VA** | `0x00442b00`–`0x00442b3e` |
| **Canonical name** | `SkillSet_UninitializedCopy_0x18` |
| **Ghidra name** | `FUN_00442b00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-S) |
| **Counterpart** | `reviews/B_aa_00442b00_SkillSet_UninitializedCopy_0x18.md` |
| **System** | skills-skillset |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; parents `FUN_00440f80` / `FUN_00442760` |
| **Verdict** | **accept** |

---

## 1. Purpose

Copy a half-open range of **0x18-byte POD** skill-vector elements into a destination buffer; return the advanced dest end pointer. Leaf helper for SkillSet insert/reallocate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00442b00_FUN_00442b00.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00442b00_FUN_00442b00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_UninitializedCopy_0x18.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00442b00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00442b00_FUN_00442b00.md` |
| Parents | `FUN_00440f80` @ `0x00440f80`, `FUN_00442760` @ `0x00442760` |
| Live | decompile ≡ raw; `read_memory` 63 B body; 8 xrefs |

---

## 3. Signature (sealed)

```c
// EAX = dest, ECX = begin, EDX = end (exclusive)
// returns EAX = dest + n*0x18
void *SkillSet_UninitializedCopy_0x18(void *dest, void *begin, void *end);
```

| Formal | Source | Conf |
|---|---|---|
| dest | **EAX** | **High** |
| begin | **ECX** | **High** |
| end | **EDX** | **High** |
| return dest end | **EAX** after `add eax,0x18` loop; parents store into vector `+8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if begin == end: ret (EAX unchanged)
loop:
  if dest != null: copy 6 dwords
  begin += 0x18; dest += 0x18
  until begin == end
ret dest_end
```

| Stage | Match | Conf |
|---|---|---|
| Empty early `jz` → `ret` | **Yes** | **High** |
| Stride `0x18` / 6 dwords | **Yes** | **High** |
| Null dest skip-write | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Parent elem size `0x18` + max `0xaaaaaaa` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (63 B):
```
3bca743a53565785c074268bf18b1e8bf8891f8b5e04895f048b5e08895f088b5e0c895f0c8b5e10895f108b761489771483c11883c0183bca75cc5f5e5bc3
```

Decompile ≡ bytes for CF. Phantom `in_EAX` filled as dest; return value is advanced EAX (decompiler shows void — residual).

---

## 6. Gaps

1. Product field layout of the 0x18-byte entry.  
2. Runtime / bit-exact.  
3. Sibling stack-arg clone at `0x00442b40` not owned.

---

## Verdict

**accept** — range-copy kernel, ABI, and SkillSet vector role sealed from bytes + parents.

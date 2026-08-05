# OWN-ONLY dual agent report — W25-F

| Field | Value |
|---|---|
| Agent | W25-F |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0051bfb0`, `0x0051ba40` |
| Tools | Ghidra `decompile_function` + `read_memory` (+ function meta / xrefs / callees). **No** `disassemble_bytes` |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdicts

| Unit | Proposed name | Verdict |
|------|---------------|---------|
| `aa_0051bfb0` @ `0x0051bfb0` | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` | **accept-with-gaps** |
| `aa_0051ba40` @ `0x0051ba40` | `CNDHash_AllocBucketTable_009ce090` | **accept-with-gaps** |

Both A and B reviews agree per VA.

---

## VA1 — `0x0051bfb0` CNDHash_ReclaimAll_ValueOwning_009ce0a8

### Sealed facts

1. **Body:** `0051bfb0`–`0051c021` (**0x72** B). Frame with ECX→EBP; plain `ret`.
2. **ABI:** MSVC **`__thiscall`** (Ghidra `__fastcall`), no stack args.
3. **Contract:** For `i = 0..mask(+0x08)` inclusive: walk `table[i]->head(+4)`; stamp node **`009ce0a8`**; if value `+0x08` ≠ 0 → **`FUN_00604e30(value)`** then **`operator_delete(value)`** (both return); clear value; push freelist `+0x20`; clear heads.
4. **Not** FreeBuckets: does not zero count or free table/slab.
5. **Decompiler noise:** false noreturn on `operator_delete`; missing thiscall arg on `FUN_00604e30`.
6. **Caller:** sole site `CNDHash_FreeBuckets` @ `0x0051d15a`.
7. **Name:** stamp-qualified ReclaimAll; reject Named_CalleeOf VOG chain. Closes FreeBuckets residual “full value matrix of FUN_0051bfb0”.

### Gaps

- Product / PDB Reclaim English  
- Exact medal value type beyond nested residual fields  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051bfb0_FUN_0051bfb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bfb0_FUN_0051bfb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0051bfb0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009ce0a8.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_0051bfb0_FUN_0051bfb0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` |

---

## VA2 — `0x0051ba40` CNDHash_AllocBucketTable_009ce090

### Sealed facts

1. **Body:** `0051ba40`–`0051bad0` (Ghidra). Success `pop edi/esi/ecx; ret`; fail throw path.
2. **ABI:** MSVC **`__thiscall`**, no stack args.
3. **Contract:** Gate log2 `+0x1C` ∈ **[1,16]**; `N=*+0x08`; `new[](N*4)` → `+0x10`; `malloc(N*0xC)` slab; each sentinel stamp **`009ce090`**, head/fields 0; **`+0x08 = N-1` (mask)**.
4. **Fail:** `VOG_DEBUG_STOP` + throw **`0x80004003`** / ThrowInfo `0xacc430`.
5. **Callers:** `CNDHash_Recreate` @ `0x0051d27c`; ctor `FUN_0051db60` @ `0x0051dbba`.
6. **Name:** stamp-qualified AllocBucketTable; reject Named_VOG identity. Explains FreeBuckets `free(*buckets)`.

### Gaps

- Product / PDB Alloc English  
- Full sentinel vtbl method matrix at `009ce090`  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051ba40_FUN_0051ba40.md` |
| Annotated | `docs/reconstruction/raw/aa_0051ba40_FUN_0051ba40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0051ba40.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009ce090.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_0051ba40_FUN_0051ba40.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` |

---

## AutoCore impact

- **`0051bfb0`:** medal (and same-family) CNDHash reclaim used by FreeBuckets/Recreate/dtor. Port as: walk all buckets by mask inclusive; destroy values with nested field teardown then free value; freelist push; clear heads. Do **not** free table here.
- **`0051ba40`:** alloc twin for Recreate/ctor. Port as: validate log2 1..16; allocate pointer table + contiguous 0xC sentinels; convert count→mask. Free path must free slab via first table entry then `delete[]` table.
- No server Launcher / live runtime work performed this pass.

---

## Compliance

| Rule | Status |
|---|---|
| OWN VAs only | **Yes** (`0051bfb0`, `0051ba40`) |
| decompile_function + read_memory | **Yes** |
| No disassemble_bytes | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| raw / annotated / reconstructed-exact / functions / reviews A+B | **Yes** (both VAs) |

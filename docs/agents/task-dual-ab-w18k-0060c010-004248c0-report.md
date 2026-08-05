# Dual A/B report — W18-K OWN-ONLY (`0x0060c010`, `0x004248c0`)

**Date:** 2026-07-29  
**Agent:** W18-K  
**Scope:** OWN VAs only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_by_address`). No `disassemble_bytes`.  
**Program:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | VA | Canonical | Verdict |
|------|-----|-----------|---------|
| `aa_0060c010` | `0x0060c010` | `CNDHash_InsertAlways` | **accept-with-gaps** — always-insert CF/ABI/layouts sealed |
| `aa_004248c0` | `0x004248c0` | `Rng_Mt19937_Twist` | **accept-with-gaps** — MT19937 twist CF/constants/ESI ABI sealed |

---

## `0x0060c010` — CNDHash_InsertAlways

### Sealed facts

1. **`__thiscall(this, uint key, void* value)`**, epilogue **`RET 8`**.  
2. Null value → **`0x80004003`** (`E_POINTER`); success → **0**.  
3. **No** lock check (`+0x1d`), **no** `CNDHash_LookupByKey`, **no** soft/hard duplicate policy — **always inserts** (multi-key chains allowed).  
4. Node via `FUN_0053ada0` with freelist **`this+0x20`**; node size **0x1c**; vtbl **`PTR_LAB_009cf024`**.  
5. Hash: mask `+0x08`, count `+0x0c`, buckets `+0x10`, listHead `+0x14`, listTail `+0x18`.  
6. Node: value `+0x08`, bucketNext `+0x0c`, key `+0x10`, listNext `+0x14`, listPrev `+0x18`, touch `+0x04`.  
7. Bucket head-insert at `bucketHdr+4`; `FUN_00537d30(ECX=bucketHdr)` integrity.  
8. **Sole static caller:** `CVOGRegionMissions_ctor` `0x0060b870` (×2 secondary indexes `this[2]`/`this[3]`).  
9. Sibling `CNDHash_Insert` `0x0053c560` / twin `0x0053c360` share link core; twin shares this vtbl but keeps full dup policy.

### Gaps

- Product / PDB name (canonical is behavior-inferred).  
- Whether multi-key is intentional for `def+0x88` / `+0x86` indexes.  
- Full freelist shell / node RTTI.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0060c010_CNDHash_InsertAlways.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0060c010_CNDHash_InsertAlways.md` |
| Function record | `docs/reconstruction/functions/aa_0060c010_CNDHash_InsertAlways.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_InsertAlways.cpp` |
| Raw | `docs/reconstruction/raw/aa_0060c010_FUN_0060c010.md` |
| Annotated | `docs/reconstruction/raw/aa_0060c010_CNDHash_InsertAlways.annotated.md` |

---

## `0x004248c0` — Rng_Mt19937_Twist

### Sealed facts

1. **Leaf MT19937 twist**; state base in **ESI**; **no stack args**; near **`RET`**.  
2. Constants: **N=624**, **M=397**, loops **227** + **396** + wrap, **MATRIX_A=`0x9908b0df`**.  
3. After twist: **`[esi+0x9c4]=0x270`** (remaining), **`[esi+0x9c0]=esi`** (cursor=`&mt[0]`).  
4. State object size **0x9c8** at alloc sites (`mt[624]` + cursor + remaining).  
5. **0 callees**; **22 xrefs** (extract `FUN_00424830`, table fill `FUN_007a4200`, ctor `FUN_007a42d0`, others).  
6. Not seed (`0x6c078965` is sibling `FUN_00424890`); not temper (extract sibling).

### Gaps

- Product / PDB name.  
- Full dual of extract/seed siblings (context only).  
- Extract temper masks (non-owned).  
- Runtime vector / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004248c0_Rng_Mt19937_Twist.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004248c0_Rng_Mt19937_Twist.md` |
| Function record | `docs/reconstruction/functions/aa_004248c0_Rng_Mt19937_Twist.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_Mt19937_Twist.cpp` |
| Raw | `docs/reconstruction/raw/aa_004248c0_FUN_004248c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004248c0_Rng_Mt19937_Twist.annotated.md` |

---

## AutoCore impact

- **CNDHash_InsertAlways:** region-mission secondary indexes may contain **duplicate keys**; do not port with `CNDHash_Insert` uniqueness/soft-skip. Server multi-map OK if keys collide. Freelist is per-hash at `+0x20`.  
- **Rng_Mt19937_Twist:** client PRNG buffer refill; skill/dice streams that must match client need this twist + extract temper. Cursor/remaining model (countdown + pointer walk), not classic `mti` index alone.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`0060c010`, `004248c0`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` only (no `disassemble_bytes`) | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
